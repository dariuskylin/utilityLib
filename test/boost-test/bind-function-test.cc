/*
 * =====================================================================================
 *
 *       Filename:  bind-function-test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/2012 11:47:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<iostream>
using std::cout;
using std::endl;
class Penguin
{
    public:
        void run()
        {
            cout<<"I can run..."<<endl;
        }
        void swim()
        {
            cout<<"I can swim..."<<endl;
        }
};
class Sparrow
{
    public:
        void fly()
        {
            cout<<"I can fly..."<<endl;
        }
        void run()
        {
            cout<<"I can run(sparrow)..."<<endl;
        }
};
typedef boost::function<void ()> FlyCallback;
typedef boost::function<void ()> RunCallback;
typedef boost::function<void ()> SwimCallback;

class Foo
{
    public:
        Foo(FlyCallback flyCb,RunCallback runCb) : flyCb_(flyCb),runCb_(runCb_)
        {}
    public:
        FlyCallback flyCb_;
        RunCallback runCb_;
};
class Bar
{
    public:
        Bar(SwimCallback swimCb,RunCallback runCb) : swimCb_(swimCb),runCb_(runCb)
        {}
    private:
        SwimCallback swimCb_;
        RunCallback runCb_;
};
int main()
{
    Sparrow s;
    Penguin p;
    Foo foo(boost::bind(&Sparrow::fly,&s),boost::bind(&Sparrow::run,&s));
    foo.flyCb_;
    Bar bar(boost::bind(&Penguin::swim,&p),boost::bind(&Penguin::run,&p));
    return 0;
}
