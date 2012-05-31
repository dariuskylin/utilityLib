/*
 * =====================================================================================
 *
 *       Filename:  event_demultiplexer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2012 10:25:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _EVENT_DEMULTIPLEXER_H_
#define _EVENT_DEMULTIPLEXER_H_
#include<set>
#include<map>
#include"reactor.h"
namespace NDSL
{
    class EventDemultiplexer
    {
        public:
            virtual ~EventDemultiplexer() {}
            virtual int WaitEvents(std::map<handle_t,EventHandler *> *handlers,
                    int timeout = 0) = 0;
            virtual int RequestEvent(handle_t handle,event_t evt) = 0;
            virtual int UnrequestEvent(handle_t handle) = 0;
    };    
    //////////////////////////////////////////////////////
    class SelectDemultiplexer : public EventDemultiplexer
    {
        public:
            SelectDemultiplexer();
            virtual int WaitEvents(std::map<handle_t,EventHandler *> *handlers,
                    int timeout = 0);
            virtual int RequestEvent(handle_t handle,event_t evt);
            virtual int UnrequestEvent(handle_t handle);
        private:
            void Clear();
        private:
            fd_set m_read_set;
            fd_set m_write_set;
            fd_set m_except_set;
            timeval m_timeout;
    };
    /////////////////////////////////////////////////////////
    class EpollDemultiplexer : public EventDemultiplexer
    {
        public:
            EpollDemultiplexer();
            virtual ~EpollDemultiplexer();
            virtual int WaitEvents(std::map<handle_t,EventHandler *> *handlers,
                    int timeout = 0);
            virtual int RequestEvent(handle_t handle,event_t evt);
            virtual int UnrequestEvent(handle_t handle);
        private:
            int m_epoll_fd;
            int m_fd_num;
    };
}
#endif
