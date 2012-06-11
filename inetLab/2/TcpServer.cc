/*
 * =====================================================================================
 *
 *       Filename:  TcpServer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 01:21:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"TcpServer.h"
#include<sys/types.h>
TcpServer::TcpServer():TcpSockets()
{}
TcpServer::~TcpServer()
{}
int TcpServer::bind(InetAddress &addr)
{
    return bindAddress(addr);
}
int TcpServer::listen(int listenQ)
{
   int retval = ::listen(fd_,listenQ);
   return retval; 
}
int TcpServer::accept(InetAddress &peer)
{
    socklen_t addrlen = sizeof(struct sockaddr_in);
    int connfd = ::accept(fd_,(struct sockaddr *)(&(peer.getSockAddrInet())),&addrlen);
    return connfd;
}
