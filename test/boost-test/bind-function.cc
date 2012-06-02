/*
 * =====================================================================================
 *
 *       Filename:  bind-function.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/2012 12:14:27 AM
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
void CallFun(boost::function<void (void)> f)
{
    f();
}
void Fun1(int i)
{
    cout<<i<<endl;
}
void FunWeNeed()
{
    Fun1(1);
}
int main()
{
    CallFun(boost::bind(Fun1,1));
    CallFun(FunWeNeed);
    return 0;
}
