/*
 * =====================================================================================
 *
 *       Filename:  test1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 01:08:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<errno.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    fprintf(stderr,"ssssss :%s\n",strerror(errno));
    return 0;
}
