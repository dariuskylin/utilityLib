/*
 * =====================================================================================
 *
 *       Filename:  TcpClient.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 01:09:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"TcpClient.h"
TcpClient::TcpClient():TcpSockets()
{}
TcpClient::~TcpClient()
{}
int TcpClient::connect(InetAddress &addr)
{
     return ::connect(fd_,(struct sockaddr *)(&(addr.getSockAddrInet())),sizeof(addr));
}
