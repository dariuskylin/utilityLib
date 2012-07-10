/*
 * =====================================================================================
 *
 *       Filename:  echoAgent.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 06:55:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _ECHOAGENT_H_
#define _ECHOAGENT_H_
#include"agent.h"
#include"common.h"
#include"epoll.h"
class EchoAgent:public Agent{
    private:
        int sockfd1;
        int n,count;
        char *bufread;
        char *bufwrite;
        char *ptrread;
        char *ptrwrite;
    public:
        EchoAgent();
        int Init();
        EchoAgent(int sockfd);
        virtual ~EchoAgent();
        int setNonblock(int fd);
        int Read();
        int Write();
};
#endif
