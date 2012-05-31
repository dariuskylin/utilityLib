/*
 * =====================================================================================
 *
 *       Filename:  reactor.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2012 08:16:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _REACTOR_H_
#define _REACTOR_H_
#include<stdint.h>
#include<sys/epoll.h>
#include<unistd.h>
namespace NDSL
{
    typedef unsigned int event_t;
    enum
    {
        kReadEvent = 0x01,//for read event
        kWriteEvent = 0x02,//for write event
        kErrorEvent = 0x04,//for error event
        kEventMask = 0xFF //event mask
    };   
    typedef int handle_t;//handle type : socket
    class EventHandler
    {
        public:
            virtual handle_t GetHandle() const = 0;
            virtual void HandleRead() {}
            virtual void HandleWrite() {}
            virtual void HandleError() {}
        protected:
            EventHandler() {}
            virtual ~EventHandler() {}
    };
    class ReactorImplementation;
    class Reactor
    {
        public:
            Reactor();
            virtual ~Reactor();
            int RegisterHandler(EventHandler *handler,event_t evt);
            int RemoveHandler(EventHandler *handler);
            void HandleEvents(int timeout = 0);
        private:
            Reactor(const Reactor&);
            Reactor& operator=(const Reactor&);
        private:
            ReactorImplementation *m_reactor_impl;
    };
}
#endif//_REACTOR_H_
