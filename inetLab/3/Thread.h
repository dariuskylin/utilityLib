/*
 * =====================================================================================
 *
 *       Filename:  Thread.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 02:52:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_THREAD_H
#define _NDSL_THREAD_H
#include<pthread.h>
class Thread
{
    public:
    typedef void* (*Callback)(void *);
        Thread(Callback f);
        ~Thread();

        //bool isRunning();
        void join();
        void detach();
        void run();
        pthread_t getTid() const
        {
            return tid_;
        }
    protected:
        pthread_t tid_;
        Callback func;
};
#endif
