/*
 * =====================================================================================
 *
 *       Filename:  test_common.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 01:04:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _TEST_COMMON_H_
#define _TEST_COMMON_H_
#include"reactor.h"
#include<stdio.h>
#include<errno.h>
#include<string.h>

extern bool IsValidHandle(NDSL::handle_t handle)
{
    return handle>=0;
}
extern void ReportSocketError(const char *msg)
{
    fprintf(stderr,"%s error: %s\n",msg,strerror(errno));
}
#endif
