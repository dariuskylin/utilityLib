/*
 * =====================================================================================
 *
 *       Filename:  listenAgent.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 06:21:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"common.h"
#include"echoAgent.h"
#include"listenAgent.h"

using namespace std;

extern Epoll *epollhandle;

ListenAgent::ListenAgent(){
    listenfd = -1;
}
ListenAgent::~ListenAgent(){
    if(listenfd != -1)
        close(listenfd);
}
int ListenAgent::setNonblock(int fd){
    int opt;
    if((opt = fcntl(fd,F_GETFL,0)) <0 ){
        cout<<"fcntl error!"<<endl;
        return -1;
    }
    opt |= O_NONBLOCK;
    if(fcntl(fd,F_SETFL,opt) < 0){
        cout<<"fcntl error!"<<endl;
        return -1;
    }
    return 0;
}
int ListenAgent::init(){
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if((listenfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        cout<<"ListenAgent::socket error"<<endl;
        return -1;
    }
    if(bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0){
        cout<<"ListenAgent::bind error!"<<endl;
        return -1;
    }
    listen(listenfd,LISTENQ);
    if((epollhandle->Epoll_Register(listenfd,this,EPOLLIN))<0){
        cout<<"Epoll_Register error"<<endl;
        return -1;
    }
    return 0;
}
int ListenAgent::Read(){
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t len =sizeof(cliaddr);
    if((connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&len)) <0){
        cout<<"accept error!"<<endl;
        return -1;
    }
    setNonblock(connfd);
    EchoAgent *echohandle = new EchoAgent(connfd);
    if(echohandle->Init() < 0){
        cout<<"EchoAgent Init error"<<endl;
    }
    if((epollhandle->Epoll_Register(connfd,echohandle,EPOLLIN)) < 0){
        cout<<"Epoll_Register EchoAgent error"<<endl;
        return -1;
    }
    return 0;
}
