/*
 * =====================================================================================
 *
 *       Filename:  TcpSockets.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 11:41:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_TCPSOCKETS_H
#define _NDSL_TCPSOCKETS_H
#include"Sockets.h"
#include"InetAddr.h"

class TcpSockets : public Socket
{
    public:
        TcpSockets();
        ~TcpSockets();
        int create();
        int read(char *buf,size_t size);
        int write(const char *buf,size_t size);
        //Bind the sockaddr_in struct
        int bindAddress(const InetAddress &addr);
        //Set socket to be blocked or non-blocked
        void setNonblock();
        //Enable/disable Nagle's algorithm
        void setTcpNoDelay(bool on);
        //Enable/disable SO_REUSEADDR
        void setReuseAddr(bool on);
        //Enable/disable SO_KEEPALIVE
        void setKeepAlive(bool on);
};
#endif
