/*
 * =====================================================================================
 *
 *       Filename:  clock_gettime.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/02/2012 11:47:50 PM
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
using std::endl;
using std::cout;
//note:when compile this program ,we should add the lib support using"g++ *.cc -lrt"
int main()
{
    struct timespec ts = {0,0};
    clock_gettime(CLOCK_REALTIME,&ts);
    //EX:
    /*CLOCK_REALTIME :系统实时时间,随系统实时时间改变而改变,即从UTC1970-1-1 0:0:0开始计时,
     *中间时刻如果系统时间被用户该成其他,则对应的时间相应改变
     *CLOCK_MONOTONIC:从系统启动这一刻起开始计时,不受系统时间被用户改变的影响
     *CLOCK_PROCESS_CPUTIME_ID:本进程到当前代码系统CPU花费的时间
     *CLOCK_THREAD_CPUTIME_ID:本线程到当前代码系统CPU花费的时间
     */
    cout<<"sec:nsec   "<<ts.tv_sec<<":"<<ts.tv_nsec<<endl;
    return 0;
}
