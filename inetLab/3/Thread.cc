/*
 * =====================================================================================
 *
 *       Filename:  Thread.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 02:57:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"Thread.h"
#include"ThreadPool.h"
#include<assert.h>
extern ThreadPool pool;
Thread::Thread(Callback f):func(f)
{
}
Thread::~Thread()
{
}
void Thread::join()
{
   int retval = pthread_join(tid_,0);
   assert(retval == 0);
}
void Thread::detach()
{
    int retval = pthread_detach(tid_);
    assert(retval == 0);
}
void Thread::run()
{
    int retval = pthread_create(&tid_,NULL,func,&pool);
    assert(retval == 0 );
}
