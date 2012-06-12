/*
 * =====================================================================================
 *
 *       Filename:  ThreadPool.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 08:40:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"ThreadPool.h"
using namespace std;

ThreadPool::ThreadPool()
{}
ThreadPool::~ThreadPool()
{}
void ThreadPool::add(Thread *t)
{
   MutexGuard threadsGuard(threadsMutex_);
   threads.push_back(t);
}
void ThreadPool::remove(Thread *t)
{
    MutexGuard threadsGuard(threadsMutex_);
    //threads.erase(t);
    list<Thread *>::iterator it;
    for( it = threads.begin();it != threads.end();it++)
    {
        if(pthread_equal((*it)->getTid() , (*t).getTid()))
        { 
            threads.erase(it);
            break;
        }
    }
}
size_t ThreadPool::size_threads() const
{
    MutexGuard threadsGuard(threadsMutex_);
    return threads.size();
}
size_t ThreadPool::size_messages() const
{
    MutexGuard messageGuard(messageMutex_);
    return messages.size();
}
list<string> ThreadPool::getMessageQueue() const
{
    MutexGuard messageGuard(messageMutex_);
    return messages;
}
void ThreadPool::addMessage(const string message)
{
    MutexGuard messageGuard(messageMutex_);
    messages.push_back(message);
}
string ThreadPool::getMessage() 
{
    MutexGuard messageGuard(messageMutex_);
    string message = messages.front();
    messages.pop_front();
    return message;
}
void ThreadPool::run()
{
    MutexGuard threadsGuard(threadsMutex_);
    list<Thread *>::iterator it;
    for(it = threads.begin();it!=threads.end();it++)
    {
        (*it)->run();
    }
}
