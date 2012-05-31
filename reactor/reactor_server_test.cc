/*
 * =====================================================================================
 *
 *       Filename:  reactor_server_test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 01:20:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef REACTOR_SERVER_TEST_H_
#define REACTOR_SERVER_TEST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string>
#include<unistd.h>
#include"test_common.h"

NDSL::Reactor g_reactor;

const size_t kBufferSize = 1024;
char g_read_buffer[kBufferSize];
char g_write_buffer[kBufferSize];

class RequestHandler : public NDSL::EventHandler
{
    public:
        RequestHanler(NDSL::handle_t handle) :
            EventHanler(),
            m_handler(handle)
        {}
        virtual NDSL::handle_t GetHandle() const
        {
            return m_handle;
        }
        virtual void HandleWrite()
        {
            memset(g_write_buff,0,sizeof(g_write_buffer));
            int len = sprintf(g_write_buffer,"current time: %d\r\n",(int)time(NULL));
            len = write(m_handle,g_write_buffer,sizeof(g_write_buffer));
            if(len > 0)
            {
                fprintf(stderr,"send response to client,fd = %d\n",m_handle);
                g_reactor.RegisterHandler(this,NDSL::kReadEvent);
            }
            else
            {
                ReportSocketError("read");
            }
        }
        virtual void HandleRead()
        {
            memset(g_read_buffer,0,sizeof(g_read_buffer));
            int len = read(m_handle,g_read_buffer,sizeof(g_read_buffer));
            if(len > 0)
            {
                if(strncasecmp("time",g_read_buffer,4) == 0)
                {
                    g_reactor.RegisterHandler(this,NDSL::kWriteEvent);
                }
                else if(strncasecmp("exit",g_read_buffer,4) == 0)
                {
                    close(m_handle);
                    g_reactor.RemoveHandler(this);
                    delete this;
                }
            }
            else
            {
                ReportSocketError("read");
            }
        }
        virtual void HandleError()
        {
            fprintf(stderr,"client %d closed\n",m_handle);
            close(m_handle);
            g_reactor.RemoveHandler(this);
            delete this;
        }
    private:
        NDSL::handle_t m_handle;
};
///////////////////////////////////////////////////////////////
class TimeServer : public NDSL::EventHanler
{
    public:
        TimeServer(const char *ip,unsigned int port) :
            EventHanler(),
            m_ip(ip),
            m_port(port)
        {}
        bool Start()
        {
            m_handle = socket(AF_INET,SOCK_STREAM,0);
            if( !IsValidHandle(m_handle))
            {
                ReportSocketError("socket");
                return false;
            }

            struct sockaddr_in addr;
            memset(addr,0,sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_port = htons(m_port);
            addr.sin_addr.s_addr = inet_addr(m_ip.c_str());
            
            if(bind(m_handle,(sockaddr *)&addr,sizeof(addr)) != 0)
            {
                ReportSocketError("bind");
                return false;
            }
            //listen
            if(listen(m_handle,10) < 0)
            {
                ReportSocketError("listen");
                return false;
            }
            return true;
        }
        virtual NDSL::handle_t GetHandle() const
        {
            return m_handle;
        }
        virtual void HandleRead()
        {
            struct sockaddr addr;
            socklen_t addrlen = sizeof(addr);
            NDSL::handle_t handle = accept(m_handle,&addr,&addrlen);
            if(!IsValidHandle(handle))
            {
                ReportSocketError("accept");
            }
            else
            {
                RequestHandler *handler = new RequestHandler(handle);
                if(g_reactor.RegisterHandler(handler,NDSL::kReadEvent)!= 0)
                {
                    fprintf(stderr,"error:register handler failed\n");
                    delete handler;
                }
            }
        }
    private:
        NDSL::handle_t m_handle;
        std::string m_ip;
        unsigned short m_port;
};
int main(int argc ,char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"usage: %s ip port\n",argv[0]);
        return -1;
    }
    TimeServer server(argv[1],atoi(argv[2]));
    if(!server.Start())
    {
        fprintf(stderr,"start server failed\n");
        return -1;
    }
    fprintf(stderr,"server started!\n");
    while(1)
    {
        g_reactor.RegisterHandler(&server,NDSL::kReadEvent);
        g_reactor.HandleEvents(100);
    }
    return 0;
}
#endif
