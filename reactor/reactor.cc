/*
 * =====================================================================================
 *
 *       Filename:  reactor.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2012 08:29:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<assert.h>
#include<map>
#include"reactor.h"
#include"event_demultiplexer.h"
namespace NDSL
{
    class ReactorImplementation
    {
        public:
            ReactorImplementation();
            virtual ~ReactorImplementation();
            int RegisterHandler(EventHandler *handler,event_t evt);
            int RemoveHandler(EventHandler *handler);
            void HandleEvents(int timeout);
        private:
            EventDemultiplexer *m_demultiplexer;
            std::map<handle_t, EventHandler *> m_handlers;
    };
    Reactor::Reactor()
    {
        m_reactor_impl = new ReactorImplementation();
    }
    Reactor::~Reactor()
    {
        delete m_reactor_impl;
    }
    int Reactor::RegisterHandler(EventHandler *handler,event_t evt)
    {
        return m_reactor_impl->RegisterHandler(handler,evt);
    }
    int Reactor::RemoveHandler(EventHandler *handler)
    {
        return m_reactor_impl->RemoveHandler(handler);
    }
    void Reactor::HandleEvents(int timeout)
    {
        m_reactor_impl->HandleEvents(timeout);
    }
    /////////////////////////////////////////////////////////////
    ReactorImplementation::ReactorImplementation()
    {
        m_demultiplexer = new EpollDemultiplexer();
    }
    ReactorImplementation::~ReactorImplementation()
    {
        delete m_demultiplexer;
    }
    int ReactorImplementation::RegisterHandler(EventHandler *handler,event_t evt)
    {
        handle_t handle = handler->GetHandle();
        std::map<handle_t, EventHandler *>::iterator it = m_handlers.find(handle);
        if(it == m_handlers.end())
        {
            m_handlers[handle] = handler;
        }
        return m_demultiplexer->RequestEvent(handle,evt);
    }
    int ReactorImplementation::RemoveHandler(EventHandler *handler)
    {
        handle_t handle = handler->GetHandle();
        m_handlers.erase(handle);
        return m_demultiplexer->UnrequestEvent(handle);
    }
    void ReactorImplementation::HandleEvents(int timeout)
    {
        m_demultiplexer->WaitEvents(&m_handlers);
    }
}
