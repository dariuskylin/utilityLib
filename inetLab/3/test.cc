/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 11:48:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"Mutex.h"
#include"Thread.h"
#include"ThreadPool.h"
#include<iostream>
#include<string>
using namespace std;

void* task(void * args)
{
    ThreadPool* apool = static_cast<ThreadPool *> (args);
    while(apool->size_messages())
    {
        string message = apool->getMessage();
        cout<<"work thread "<<pthread_self()<<":"<<message<<endl;
        sleep(1);
    }
    
}
ThreadPool pool;
int main()
{
    //add message queue
    pool.addMessage("job01 is done...");
    pool.addMessage("job02 is done...");
    pool.addMessage("job03 is done...");
    pool.addMessage("job04 is done...");
    pool.addMessage("job05 is done...");
    pool.addMessage("job06 is done...");
    pool.addMessage("job07 is done...");
    pool.addMessage("job08 is done...");
    pool.addMessage("job09 is done...");
    pool.addMessage("job10 is done...");
    // initialize threads
    Thread* thread1 = new Thread(task);
    Thread* thread2 = new Thread(task);
    Thread* thread3 = new Thread(task);
    //add threads to threadPool
    pool.add(thread1);
    pool.add(thread2);
    pool.add(thread3);
    //enable threadPool run
    pool.run();

    sleep(5);
    return 0;
}
