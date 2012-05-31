/*
 * =====================================================================================
 *
 *       Filename:  event_demultiplexer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2012 11:45:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<errno.h>
#include<assert.h>
#include<vector>
#include"event_demultiplexer.h"
namespace NDSL
{
    SelectDemultiplexer::SelectDemultiplexer()
    {
        this->Clear();
    }
    int SelectDemultiplexer::WaitEvents(std::map<handle_t,EventHandler *> *handlers,
            int timeout)
    {
        m_timeout.tv_sec = timeout/1000;
        m_timeout.tv_usec = timeout % 1000 * 1000;
        int max_fd = handlers->rbegin()->first;
        int ret = select(max_fd + 1,&m_read_set,&m_write_set,
                &m_except_set,&m_timeout);
        if(ret < 0)
        {
            return ret;
        }
        std::map<handle_t,EventHandler *>::iterator it = handlers->begin();
        while(it != handlers->end())
        {
            if(FD_ISSET(it->first,&m_except_set))
            {
               it->second->HandleError();
               FD_CLR(it->first,&m_read_set);
               FD_CLR(it->first,&m_write_set); 
            }
            else
            {
                if(FD_ISSET(it->first,&m_read_set))
                {
                    it->second->HandleRead();
                    FD_CLR(it->first,&m_read_set);
                }
                if(FD_ISSET(it->first,&m_write_set))
                {
                    it->second->HandleWrite();
                    FD_CLR(it->first,&m_write_set);
                }
            }
            FD_CLR(it->first,&m_except_set);
            it++;
        }
        return ret;
    }
    int SelectDemultiplexer::RequestEvent(handle_t handle,event_t evt)
    {
        if(evt & kReadEvent)
        {
            FD_SET(handle,&m_read_set);
        }
        if(evt & kWriteEvent)
        {
            FD_SET(handle,&m_wrtie_set);
        }
        FD_SET(handle,&m_except_set);
        return 0;
    }
    int SelectDemultplexer::UnrequestEvent(handle_t handle)
    {
        FD_CLR(handle,&m_read_set);
        FD_CLR(handle,&m_write_set);
        FD_CLR(handle,&m_except_set);
        return 0;
    }
    void SelectDemultplexer::Clear()
    {
        FD_ZERO(&m_read_set);
        FD_ZERO(&m_write_set);
        FD_ZERO(&m_except_set);
    }
    EpollDemultiplexer::EpollDemultiplexer()
    {
        m_epoll_fd = ::epoll_create(FD_SETSIZE);
        assert(m_epoll_fd != -1);
        m_fd_num = 0;
    }
    EpollDemultiplexer::~EpollDemultiplexer()
    {
        ::close(m_epoll_fd);
    }
    int EpollDemultiplexer::WaitEvents(
            std::map<handle_t,EventHandler *> *handlers,
            int timeout)
    {
        std::vector<epoll_event> ep_evts(m_fd_num);//length of vector is m_fd_num
        int num = epoll_wait(m_epoll_fd,&ep_evts[0],ep_evts.size(),
                timeout);
        if(num > 0 )
        {
            for(int idx = 0;idx<num;idx++)
            {
                handle_t handle = ep_evts[idx].data.fd;
                assert(handlers->find(handle) != handlers->end());
                if( (ep_evts[idx].events & EPOLLERR) ||
                        (ep_evts[idx].events & EPOLLHUP) )
                {
                    (*handlers)[handle]->HandleError();
                }
                else
                {
                    if(ep_evts[idx].events & EPOLLIN)
                    {
                        (*handlers)[handle]->HandleRead();
                    }
                    if(ep_evts[idx].events & EPOLLOUT)
                    {
                        (*handlers)[handle]->HandleWrite();
                    }
                }
            }
        }
        return num;
    }
    int EpollDemultiplexer::RequestEvent(handle_t handle,event_t evt)
    {
        epoll_event ev;
        ev.data.fd = handle;
        ev.events=0;
        if(evt & kReadEvent)
            ev.events |= EPOLLIN;
        if(evt & kWriteEvent)
            ev.events |= EPOLLOUT;
        ev.events |= EPOLLONESHOT;
        if(epoll_ctl(m_epoll_fd,EPOLL_CTL_MOD,handle,&ev) != 0)
        {
            if( errno == ENOENT)
            {
                if(epoll_ctl(m_epoll_fd,EPOLL_CTL_ADD,handle,&ev) != 0)
                {
                    return -errno;
                }
                m_fd_num++;
            }
        }
        return 0;
    }
    int EpollDemultiplexer::UnrequestEvent(handle_t handle)
    {
        epoll_event ev;
        ev.data.fd = handle;
        ev.events = 0;
        if(epoll_ctl(m_epoll_fd,EPOLL_CTL_DEL,handle,&ev) != 0)
        {
            return -errno;
        }
        m_fd_num--;
        return 0;
    }
}
