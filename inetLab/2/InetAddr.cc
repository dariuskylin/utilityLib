/*
 * =====================================================================================
 *
 *       Filename:  InetAddr.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 10:08:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"InetAddr.h"
#include<assert.h>
#include<stdio.h>
#include<string.h>

InetAddress::InetAddress(uint16_t port)
{
    memset(&addr_,0,sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_.sin_port = htons(port);
}
InetAddress::InetAddress(const string &ip,uint16_t port)
{
    memset(&addr_,0,sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    ::inet_pton(AF_INET,ip.c_str(),&addr_.sin_addr);
}
string InetAddress::toIpPort() const
{
    char buf[64];
    char host[40];
    memset(buf,0,sizeof(buf));
    memset(host,0,sizeof(host));
    ::inet_ntop(AF_INET,&addr_.sin_addr,host,sizeof(host));
    int16_t port = ntohs(addr_.sin_port);
    snprintf(buf,sizeof(buf),"%s:%u",host,port);
    return buf;
}
bool InetAddress::operator==(const struct sockaddr_in &rhs)
{
    if((addr_.sin_family == rhs.sin_family)
            &&(addr_.sin_port == rhs.sin_port)
            &&(addr_.sin_addr.s_addr == rhs.sin_addr.s_addr))
        return true;
    else
        return false;
}
bool InetAddress::operator==(const InetAddress &rhs)
{
    return (*this)==rhs.getSockAddrInet();
}
