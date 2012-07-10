/*
 * =====================================================================================
 *
 *       Filename:  agent.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 07:03:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _AGENT_H_
#define _AGENT_H_
#include"common.h"
class Agent{
    protected:
        int fd;
    public:
        Agent(){};
        virtual ~Agent(){}
        virtual int Read() = 0;
        virtual int Write() = 0;
};
#endif
