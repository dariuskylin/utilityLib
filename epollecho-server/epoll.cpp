/*
 * =====================================================================================
 *
 *       Filename:  epoll.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 01:34:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"epoll.h"
#include"common.h"

using namespace std;

Epoll::Epoll(){
    epfd = -1;
    max_events = 0;
    events = NULL;
    memset(&ev,0,sizeof(struct epoll_event));
}
Epoll::~Epoll(){
    
}
int Epoll::Epoll_Initial(int size){
   max_events = size; 
   epfd = epoll_create(size);
   if(epfd < 0){
       cout<<"epoll_create error"<<endl;
       return -1;
   }
   events = new epoll_event[max_events];
   memset(events,0,sizeof(epoll_event)*max_events);
   return 0;
}
int Epoll::Epoll_Register(int fd,Agent *agent,int event){
    ev.data.ptr = agent;
    ev.events = event;
    if(epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev) < 0){
        cout<<"epoll_ctl error!"<<endl;
        return -1;
    }
    return 0;
}
int Epoll::Epoll_Change(int fd,Agent *agent,int event){
    ev.data.ptr = agent;
    ev.events = event;
    if(epoll_ctl(epfd,EPOLL_CTL_MOD,fd,&ev) < 0){
        cout<<"epoll_ctl_mod error"<<endl;
        return -1;
    }
    return 0;
}
int Epoll::Epoll_Del(int fd){
    if(epoll_ctl(epfd,EPOLL_CTL_DEL,fd,&ev) < 0){
        cout<<"epoll_ctl_del error!"<<endl;
        return -1;
    }
    return 0;
}
int Epoll::Epoll_Wait(int timeout){
    int nfds;
    while(1){
        nfds = epoll_wait(epfd,events,max_events,timeout);
        if(nfds < 0){
            cout<<"epoll_wait error"<<endl;
            return -1;
        }
        for(int i = 0;i<nfds;i++){
            if(events[i].events & EPOLLIN){
                Agent *agent = static_cast<Agent *>(events[i].data.ptr);
                int n = agent->Read();
                if( -1 == n){
                    delete agent;
                    agent = NULL;
                    break;
                }
            }else if(events[i].events & EPOLLOUT){
                Agent *agent = static_cast<Agent *>(events[i].data.ptr);
                int n = agent->Write();
                if(-1 == n){
                    delete agent;
                    agent = NULL;
                    break;
                }
            }
        }
    }
}
