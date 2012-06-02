/*
 * =====================================================================================
 *
 *       Filename:  test-noncopyable.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 07:34:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"noncopyable.h"
class demo_noncopyable : NDSL::noncopyable  
{
};
int main()
{
    demo_noncopyable d1;
    demo_noncopyable d2;
    return 0;  
}
