/**
 * @file Epoll.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_EPOLL_H_
#define _XCOM_EPOLL_H_

#include <sys/epoll.h>
#include "File.h"
#include "Thread.h"

namespace xcom
{

/**
 * @class Epoll
 * @comment
 * wrap of epoll
 */
class Epoll : public BasicFile
{
public:
	Epoll() {}
	~Epoll() {}

	struct Event : public epoll_event
	{
		Event() { events = EPOLLERR; data.u64 = 0; }
		Event(unsigned int type, void *magic)
		{ data.u64 = 0; events = type; data.ptr = magic; }
	};

	int create()
	{
		if ((descriptor_ = epoll_create(1)) == -1)
			throw EXCEPTION();
		return descriptor_;
	}

	void registerEvent(int fd, Event &event)
	{
		if (epoll_ctl(descriptor_, EPOLL_CTL_ADD, fd,
				(epoll_event*)&event) == -1)
			throw EXCEPTION();
	}

	void modifyEvent(int fd, Event &event)
	{
		if (epoll_ctl(descriptor_, EPOLL_CTL_ADD, fd,
				(epoll_event*)&event) == -1)
		{
			if (errno == EEXIST)
				errno = 0;
			else
				throw EXCEPTION();
		}
	}

	void unregisterEvent(int fd)
	{
		if (epoll_ctl(descriptor_, EPOLL_CTL_DEL, fd, NULL) == -1)
			throw EXCEPTION();
	}

	int waitEvent(Event *events, int size, int msec)
	{
		int ret;
		RETRY:
		if ((ret = epoll_wait(descriptor_, events, size,
				msec == -1 ? NULL : msec)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		return ret;
	}
};

class IoReactor
{
public:
	static const ulong READ = 0x01UL;
	static const ulong WRITE = 0x02UL;
	static const ulong ERR = 0x04UL;
	static const ulong TIMER = 0x08UL;
	static const ulong SIGNAL = 0x10UL;
	static const ulong CUSTOM = 0x20UL;
	static const ulong TRIGGER = 0x40UL;
	static const ulong ONESHOT = 0x80UL;

	struct Task
	{
		BasicFile &file;		// file
		CallbackFunc func;		// callback function
		void *param;			// the parameter of callback
		void *result;			// the result

		Task(BasicFile &f, CallbackFunc fu, void *p)
			: file(f), func(fu), param(p), result(NULL)
		{ }
	};

	typedef void * Handle;

protected:
	std::list<Task*> tasks_;
	Epoll epoll_;

	inline ulong epollOp(ulong option)
	{
		// @TODO
		return (option & READ ? EPOLLIN : 0)
				| (option & WRITE ? EPOLLOUT : 0)
				| (option & ERR ? EPOLLERR : 0)
				| (option & TIMER ? EPOLLIN : 0)
				| (option & SIGNAL ? EPOLLERR : 0)
				| (option & CUSTOM ? EPOLLERR : 0)
				| (option & TRIGGER ? EPOLLET : 0)
				| (option & ONESHOT ? EPOLLONESHOT : 0);
	}

public:
	IoReactor()
	{ epoll_.create(); }
	~IoReactor()
	{ }

	size_t size()
	{ return tasks_.size(); }

	Handle insert(Task &task, ulong option)
	{
		tasks_.push_front(&task);

		std::list<Task*>::iterator it = tasks_.begin();
		BOOST_STATIC_ASSERT(sizeof(it) == sizeof(void*));
		void *p;
		bcopy(&it, &p, sizeof(void*));
		Epoll::Event event(epollOp(option), p);

		if (epoll_ctl(epoll_.descriptor(), EPOLL_CTL_ADD,
				task.file.descriptor(), (epoll_event*)&event) == -1)
		{
			if (errno == EEXIST) {
				tasks_.pop_front();
				return NULL;
			}
			else
				throw EXCEPTION();
		}

		return p;
	}

	bool remove(Handle p)
	{
		std::list<Task*>::iterator it;
		BOOST_STATIC_ASSERT(sizeof(it) == sizeof(void*));
		bcopy(&p, &it, sizeof(void *));
		int d = (*it)->file.descriptor();

		if (epoll_ctl(epoll_.descriptor(), EPOLL_CTL_DEL, d, NULL) == -1)
		{
			if (errno == ENOENT)
				return false;
			else
				throw EXCEPTION();
		}

		tasks_.erase(it);
		return true;
	}

	bool option(Handle p, ulong option)
	{
		assert(p != NULL);
		std::list<Task*>::iterator it;
		BOOST_STATIC_ASSERT(sizeof(it) == sizeof(void*));
		bcopy(&p, &it, sizeof(void *));
		int d = (*it)->file.descriptor();

		Epoll::Event event(epollOp(option), p);

		if (epoll_ctl(epoll_.descriptor(), EPOLL_CTL_ADD, d,
				(epoll_event*)&event) == -1)
		{
			if (errno == EEXIST)
				errno = 0;
			else
				throw EXCEPTION();
		}
		return true;
	}

	void run()
	{
		int ret;
		Epoll::Event happens[10];

		while (!tasks_.empty())
		{
			ret = epoll_.waitEvent(happens, 10, -1);
			for (int i = 0; i < ret; ++i)
			{
				std::list<Task*>::iterator it;
				BOOST_STATIC_ASSERT(sizeof(it) == sizeof(void*));
				bcopy(&(happens[i].data.ptr), &it, sizeof(void *));

				if (happens[i].events & EPOLLERR)
					throw EXCEPTION();

				if ((*it)->func != NULL)
					(*it)->result = (void*)(*it)->func((*it)->param);
			}
		}
	}
};

class IoProactor
{

};

}; // namespace xcom
#endif /* _XCOM_EPOLL_H_ */
