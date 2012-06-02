/*
 * =====================================================================================
 *
 *       Filename:  noncopyable-test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 08:52:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<boost/noncopyable.hpp>
class demo_noncopyable : boost::noncopyable
{};
int main()
{
    demo_noncopyable d1;
    return 0;
}
