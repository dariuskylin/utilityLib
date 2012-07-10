/*
 * =====================================================================================
 *
 *       Filename:  listenAgent.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 06:18:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _LISTENAGENT_H_
#define _LISTENAGENT_H_
#include"common.h"
#include"agent.h"
class ListenAgent : public Agent{
    private:
        int listenfd;
    public:
        ListenAgent();
        ~ListenAgent();
        int setNonblock(int fd);
        int init();
        int Read();
        int Write() { return 0; }
};
#endif
