/*
 * =====================================================================================
 *
 *       Filename:  Sockets.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 08:46:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_SOCKETS_H
#define _NDSL_SOCKETS_H
#include<sys/socket.h>
#include"InetAddr.h"
class Socket
{
    public:
        Socket();
        Socket(int fd);
        ~Socket();
        void attach(int fd);
        void detach();
        void close();
        int getFd() const  { return fd_;  }
    protected:
        int fd_;
};
#endif

