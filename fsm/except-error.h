/*
 * =====================================================================================
 *
 *       Filename:  except-error.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/17/2012 11:08:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _EXCEPT_ERROR_HEAD_H
#define _EXCEPT_ERROR_HEAD_H
#include<stdexcept>
#include<string>
class RunError : public std::runtime_error
{
    public:
        RunError(const std::string &what)
            :std::runtime_error(what.c_str())
        {
        }
        RunError(const char* const what)
            :std::runtime_error(what)
        {
        }
};

#endif
