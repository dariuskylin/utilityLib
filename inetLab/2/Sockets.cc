/*
 * =====================================================================================
 *
 *       Filename:  Sockets.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 08:51:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"Sockets.h"
Socket::Socket():fd_(0)
{}
Socket::Socket(int fd):fd_(fd)
{}
Socket::~Socket()
{
    if(fd_>0)
    { 
      ::close(fd_);
      fd_ = 0;
    }
}
void Socket::attach(int fd)
{
    if(fd_==0)
    {
        fd_ = fd;
    }
}
void Socket::detach()
{
    if(fd_!=0)
    {
        ::close(fd_);
        fd_ = 0;
    }
}
void Socket::close()
{
    if(fd_ >0)
    {
        ::close(fd_);
        fd_ = 0;
    }
}

