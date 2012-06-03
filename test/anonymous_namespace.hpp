/*
 * =====================================================================================
 *
 *       Filename:  anonymous_namespace.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/02/2012 09:09:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
using std::cout;
using std::endl;
namespace 
{
    void print_function()
    {
        cout<<"print_function...."<<endl;
    }
}
namespace NAME
{
    void print_function()
    {
        cout<<"NAME::print_function..."<<endl;
    }
    void print_name()
    {
        cout<<"NAME::print..."<<endl;
    }
}
