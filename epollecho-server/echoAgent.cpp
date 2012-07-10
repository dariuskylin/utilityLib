/*
 * =====================================================================================
 *
 *       Filename:  echoAgent.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 06:59:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"agent.h"
#include"epoll.h"
#include"echoAgent.h"
#include"common.h"
using namespace std;
extern Epoll *epollhandle;
EchoAgent::EchoAgent(int sockfd){
    fd = sockfd;
    bufread = NULL;
    bufwrite = NULL;
    ptrread = NULL;
    ptrwrite = NULL;
    sockfd1 = -1;
    n = BUFFERSIZE;
}
EchoAgent::~EchoAgent(){
    delete []bufread;
    delete []bufwrite;
}
int EchoAgent::Init(){
    bufread = new char[n];
    bufwrite = new char[n];
    memset(bufread,0,sizeof(char)*n);
    memset(bufwrite,0,sizeof(char)*n);
    ptrread = bufread;
    ptrwrite = bufwrite;
}
int EchoAgent::Read(){
    ssize_t nread;
    memset(ptrread,0,n);
    nread = read(fd,ptrread,n);
    ptrwrite=ptrread;
    cout<<"\nEchoAgent::Read:"<<ptrread<<endl;
    epollhandle->Epoll_Change(fd,this,EPOLLOUT);
}
int EchoAgent::Write(){
    ssize_t nwrite;
    nwrite = write(fd,ptrwrite,n);
    cout<<"\nEchoAgent::Write:"<<ptrwrite<<endl;
    epollhandle->Epoll_Change(fd,this,EPOLLIN);
}
