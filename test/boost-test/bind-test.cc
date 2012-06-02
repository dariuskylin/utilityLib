/*
 * =====================================================================================
 *
 *       Filename:  bind-test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 11:33:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<boost/bind.hpp>
using namespace std;
void f(int a,int b)
{
    cout<<a+b<<endl;
}
void g(int a,int b,int c)
{
    cout<<a+b+c<<endl;
}

int main()
{
    int x(10),y(20),z(30);
    //boost::bind(f,1,5);    
    boost::bind(f,10,20);    
    boost::bind(g,_1,_2,_3)(x,y,z);
    return 0;
}
