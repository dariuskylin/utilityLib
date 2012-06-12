/*
 * =====================================================================================
 *
 *       Filename:  Mutex.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 01:54:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_MUTEX_H
#define _NDSL_MUTEX_H
#include<pthread.h>
class Mutex
{
    public:
        Mutex()
        {
            pthread_mutex_init(&mutex_,NULL);
        }
        ~Mutex()
        {
            pthread_mutex_destroy(&mutex_);
        }
        void lock()
        {
            pthread_mutex_lock(&mutex_);
        }
        void unlock()
        {
            pthread_mutex_unlock(&mutex_);
        }
        pthread_mutex_t* getPthreadMutex()
        {
            return &mutex_;
        }
    private:
        pthread_mutex_t mutex_;
};
class MutexGuard 
{
    public:
        explicit MutexGuard(Mutex &mutex) : mutex_(mutex)
        {
            mutex_.lock();
        }
        ~MutexGuard()
        {
            mutex_.unlock();
        }
    private:
        Mutex &mutex_;
};
#endif
