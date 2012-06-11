/*
 * =====================================================================================
 *
 *       Filename:  TcpServer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/2012 01:06:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_TCPSERVER_H
#define _NDSL_TCPSERVER_H
#include"TcpSockets.h"
#include"InetAddr.h"
class TcpServer : public TcpSockets
{
    public:
        TcpServer();
        ~TcpServer();
        int bind(InetAddress &addr);
        int listen(int listenQ = 20);
        int accept(InetAddress &peer);
};

#endif
