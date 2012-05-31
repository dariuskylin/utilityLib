/*
 * =====================================================================================
 *
 *       Filename:  reactor_client_test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 02:28:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef REACTOR_CLIENT_TEST_H_
#define REACTOR_CLIENT_TEST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include"test_common.h"

NDSL::Reactor g_reactor;

const size_t kBufferSize = 1024;
char g_read_buffer[kBufferSize];
char g_write_buffer[kBufferSize];
///////////////////////////////////////////////////////
class TimeClient : public NDSL::EventHandler
{
    public:
        TimeClient() :
            EventHandler()
        {
            m_handle = socket(AF_INET,SOCK_STREAM,0);
            assert(IsValidHandle(m_handle));
        }
        ~TimeClient()
        {
            close(m_handle);
        }
        bool ConnectServer(const char *ip,unsigned short port)
        {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip);
            if(connect(m_handle,(struct sockaddr *)&addr,sizeof(addr))<0)
            {
                ReportSocketError("connect");
                return false;
            }
            return false;
        }
        virtual NDSL::handle_t GetHandle() const
        {
            return m_handle;
        }
        virtual void HandleRead()
        {
            memset(g_read_buffer,0,kBufferSize);
            int len = read(m_handle,g_read_buffer,sizeof(g_read_buffer));
            if(len > 0)
            {
                fprintf(stderr,"%s\n",g_read_buffer);
                g_reactor.RegisterHandler(this,NDSL::kWriteEvent);
            }
            else
            {
                ReportSocketError("read");
            }
        }
        virtual void HandleWrite()
        {
            memset(g_write_buffer,0,sizeof(g_write_buffer));
            int len = sprintf(g_write_buffer,"time\r\n");
            len = write(m_handle,g_write_buffer,sizeof(g_write_buffer));
            if(len >0)
            {
                fprintf(stderr,"%s",g_write_buffer);
                g_reactor.RegisterHandler(this,NDSL::kReadEvent);
            }
            else
            {
                ReportSocketError("write");
            }
        }
        virtual void HandleError()
        {
            fprintf(stderr,"server closed\n");
            close(m_handle);
            exit(0);
        }
    private:
        NDSL::handle_t m_handle;
};
int main(int argc,char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"usage: %s ip port\n",argv[0]);
        return -1;
    }
    TimeClient client;
    if(!client.ConnectServer(argv[1],atoi(argv[2])))
    {
        fprintf(stderr,"connect remote server failed\n");
        return -1;
    }
    g_reactor.RegisterHandler(&client,NDSL::kWriteEvent);
    while(1)
    {
        g_reactor.HandleEvents(100);
    }
    return 0;
}
#endif
