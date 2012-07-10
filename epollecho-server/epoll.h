/*
 * =====================================================================================
 *
 *       Filename:  epoll.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 01:28:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _EPOLL_H_
#define _EPOLL_H_
#include"common.h"
#include"agent.h"
class Epoll{
    private:
        int epfd;
        int max_events;
        struct epoll_event ev,*events;
    public:
        Epoll();
        ~Epoll();
        int Epoll_Initial(int size);
        int Epoll_Register(int fd, Agent *agent,int event);
        int Epoll_Change(int fd, Agent *agent, int event);
        int Epoll_Del(int fd);
        int Epoll_Wait(int timeout);
};

#endif
