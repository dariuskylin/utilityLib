/*
 * =====================================================================================
 *
 *       Filename:  ThreadPool.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 08:27:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_THREADPOOL_H
#define _NDSL_THREADPOOL_H
#include"Mutex.h"
#include"Thread.h"
#include<list>
#include<string>
using namespace std;
class ThreadPool
{
    private:
        mutable Mutex messageMutex_;
        mutable Mutex threadsMutex_;
        list<Thread *> threads;
        list<string> messages;
    public:
        ThreadPool();
        ~ThreadPool();
        void add(Thread *t);
        void remove(Thread *t);
        size_t size_threads() const;
        size_t size_messages() const;
        list<string> getMessageQueue() const;
        void addMessage(const string message);
        string getMessage();
        void run();
};
#endif

