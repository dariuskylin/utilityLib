/*
 * =====================================================================================
 *
 *       Filename:  Counter.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2012 05:51:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<pthread.h>
#include<boost/noncopyable.h>
#include<stdint.h>
class Counter : boost::noncopyable
{
    public:
        Counter():value_(0)
        {}
        int64_t value() const;
        int64_t increase();
        int64_t decrease();
    private:
        int64_t value_;
        mutable Mutex mutex_;
};
int64_t Counter::value() const
{
    MutexLock lock(mutex_);
    return value_;
}
int64_t Counter::increase()
{
    MutexLock lock(mutex_);
    int64_t ret = ++value_;
    return ret;
}
int64_t Counter::decrease()
{
    MutexLock lock(mutex_);
    int64_t ret = --value_;
    return ret;
}
