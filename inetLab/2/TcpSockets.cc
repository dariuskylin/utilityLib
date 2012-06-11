/*
 * =====================================================================================
 *
 *       Filename:  TcpSockets.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 11:52:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"TcpSockets.h"
#include<iostream>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/tcp.h>

using namespace std;

TcpSockets::TcpSockets():Socket()
{
}
TcpSockets::~TcpSockets()
{
}
int TcpSockets::create()
{
   fd_ = socket(AF_INET,SOCK_STREAM,0);
   if(fd_ < 0)
   {
      cout<<"socket() error!"<<endl;
   } 
}

int TcpSockets::read(char* buf,size_t size)
{
    int retval = ::read(fd_,buf,size);
    return retval;
}

int TcpSockets::write(const char* buf,size_t size)
{
    int retval = ::write(fd_,buf,size);
    return retval;
}
int TcpSockets::bindAddress(const InetAddress &addr)
{
    int retval = ::bind(fd_,(struct sockaddr *)(&(addr.getSockAddrInet())),
            sizeof(addr));
    if(retval < 0)
    {
        cout<<"bind() error!"<<endl;
    }
    return retval;
}

void TcpSockets::setNonblock()
{
    int optval;
    if( (optval = fcntl(fd_,F_GETFL,0)) < 0)
    {
        cout<<"fcntl error!"<<endl;
    }
    optval |= O_NONBLOCK;
    if( fcntl(fd_,F_SETFL,optval) , 0)
    {
        cout<<"fcntl error!"<<endl;
    }
}
void TcpSockets::setTcpNoDelay(bool on)
{
    int optval = on ? 1:0;
    ::setsockopt(fd_,IPPROTO_TCP,TCP_NODELAY,&optval,sizeof(optval));
}
void TcpSockets::setReuseAddr(bool on)
{
    int optval = on ? 1:0;
    ::setsockopt(fd_,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval));
}
void TcpSockets::setKeepAlive(bool on)
{
    int optval = on ? 1:0;
    ::setsockopt(fd_,SOL_SOCKET,SO_KEEPALIVE,&optval,sizeof(optval));
}
