/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 01:26:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"common.h"
#include"agent.h"
#include"epoll.h"
#include"listenAgent.h"
#include"echoAgent.h"
using namespace std;
Epoll *epollhandle = new Epoll;
ListenAgent *listenhandle = new ListenAgent;

int main()
{
    if(epollhandle->Epoll_Initial(20)<0){
        cout<<"Epoll_Initial error"<<endl;
        return -1;
    }
    if(listenhandle->init() < 0){
        cout<<"listen init error"<<endl;
    }
    while(1){
        epollhandle->Epoll_Wait(50);
    }
    return 0;
}
