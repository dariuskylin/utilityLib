/*
 * =====================================================================================
 *
 *       Filename:  localtime.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/2012 12:39:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<time.h>
#include<iostream>
using std::cout;
using std::endl;
int main()
{
    struct tm *a_tm;
    time_t a_time;
    a_time =time(NULL);
    a_tm = localtime(&a_time);
    //year month day
    cout<<a_tm->tm_year+1900<<"  "<<a_tm->tm_mon+1<<"  "<<a_tm->tm_mday<<endl;
    //hour:min:sec
    cout<<a_tm->tm_hour<<":"<<a_tm->tm_min<<":"<<a_tm->tm_sec<<endl;
    return 0;
}
