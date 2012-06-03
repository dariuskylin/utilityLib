/*
 * =====================================================================================
 *
 *       Filename:  timeofday.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/02/2012 11:33:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<sys/time.h>
#include<iostream>
using std::cout;
using std::endl;
int main()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    cout<<"time  "<<tv.tv_sec<<":"<<tv.tv_usec<<endl;
    return 0;
}
