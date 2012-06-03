/*
 * =====================================================================================
 *
 *       Filename:  anonymous_namespace.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/02/2012 09:10:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"anonymous_namespace.hpp"
int main()
{
    print_function();
    NAME::print_function();
    NAME::print_name();
    return 0;
}
