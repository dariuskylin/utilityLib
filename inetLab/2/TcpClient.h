/*
 * =====================================================================================
 *
 *       Filename:  TcpClient.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 01:01:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_TCPCLIENT_H
#define _NDSL_TCPCLIENT_H
#include"TcpSockets.h"
#include"InetAddr.h"
class TcpClient : public TcpSockets
{
    public:
        TcpClient();
        ~TcpClient();
        int connect(InetAddress &addr);
};
#endif
