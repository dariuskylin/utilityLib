/*
 * =====================================================================================
 *
 *       Filename:  InetAddr.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 09:57:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_INETADDR_H
#define _NDSL_INETADDR_H
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<sys/types.h>
using namespace std;
class InetAddress
{
    public:
        explicit InetAddress(uint16_t port);
        InetAddress(const string &ip,uint16_t port);
        InetAddress(const struct sockaddr_in &addr)
            :addr_(addr)
        {}
        string toIpPort() const;
        string toHostPort() const { return toIpPort(); }
        const struct sockaddr_in& getSockAddrInet() const { return addr_; }
        void setSockAddrInet(const struct sockaddr_in& addr)
        {
            addr_= addr;
        }
        uint32_t ipNetEndian() const
        {
            return addr_.sin_addr.s_addr;
        }
        uint16_t portNetEndian() const
        {
            return addr_.sin_port;
        }
        size_t size() const
        {
            return sizeof(struct sockaddr_in);
        }
        bool operator==(const InetAddress& rhs);
        bool operator==(const struct sockaddr_in &rhs);
    private:
        struct sockaddr_in addr_;
};
#endif
