/**
 * @file Thread.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_THREAD_H_
#define _XCOM_THREAD_H_

#include <pthread.h>
#include <list>
#include <boost/typeof/typeof.hpp>
#include <boost/utility.hpp>
#include <signal.h>
#include <setjmp.h>
#include "Exception.h"

#include <boost/ref.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>

#define CALLBACK_PARAMS(w) &w.run, &w

namespace xcom
{

typedef void* (*CallbackFunc)(void *);

/**
 * @class Thread
 * @comment
 *
 */
class Thread
{
public:
	enum Attribute { StackSize = 0, Affinity, Priority };

protected:
	pthread_t tid_;
	pthread_attr_t attr_;

	void exit()
	{ pthread_exit(NULL); }
	void exit(void *value)
	{ pthread_exit(value); }

public:
	Thread()
	{ pthread_attr_init(&attr_); }
	~Thread()
	{
		if (isRunning()) throw EXCEPTION();
		pthread_attr_destroy(&attr_);
	}

	// @TODO
	void setAttribute(Attribute &a, void *value)
	{ /*switch case*/ }
	void getAttribute(Attribute &a, void *value)
	{ }

	bool isRunning()
	{ return pthread_kill(tid_, 0) == 0 ? true : false; }

	void detach()
	{ if (pthread_detach(tid_) != 0) throw EXCEPTION(); }
	void detach(pthread_t tid)
	{ if (pthread_detach(tid) != 0) throw EXCEPTION(); }

	void cancel()
	{
		if (!isRunning()) {
			tid_ = 0;
			return;
		}
		pthread_cancel(tid_);
		join();		// force the thread to be canceled.
	}
	void kill(int sig)
	{ if (pthread_kill(tid_, sig) != 0) throw EXCEPTION(); }

	void join()
	{ pthread_join(tid_, NULL); }

	pthread_t run(CallbackFunc f, void *p)
	{
		if (pthread_create(&tid_, &attr_, f, p) == 0)
			return tid_;
		else
			throw EXCEPTION();	// EAGAIN means no memory
	}
};

template <typename T, bool>
struct CallbackWrapperImp
{
	static void* run(void *p)
	{
		T *self = (T*)p;
		return (void*)self->func_();
	}
};

template <typename T>
struct CallbackWrapperImp<T, true>
{
	static void* run(void *p)
	{
		T *self = (T*)p;
		self->func_();
		return NULL;
	}
};

template <typename R>
struct CallbackWrapper
	: CallbackWrapperImp<CallbackWrapper<R>, boost::is_void<R>::value>
{
	boost::function<R ()> func_;

	CallbackWrapper()
	{ }
	CallbackWrapper(boost::function<R ()> f) : func_(f)
	{ }

	template <typename T>
	void set(T t)
	{ func_ = t; }

	bool enabled()
	{ return func_; }
};

struct PThreadMutex
{
	pthread_mutex_t mutex_;

	PThreadMutex()
	{ pthread_mutex_init(&mutex_, NULL); }
	~PThreadMutex()
	{ pthread_mutex_destroy(&mutex_); }

	void lock()
	{ if (pthread_mutex_lock(&mutex_) != 0) throw EXCEPTION(); }

	void unlock()
	{ if (pthread_mutex_unlock(&mutex_) != 0) throw EXCEPTION(); }

	bool trylock()
	{
		int ret;
		if ((ret = pthread_mutex_trylock(&mutex_)) != 0)
		{
			if (ret == EBUSY)
				return false;
			else
				throw EXCEPTION();
		}
		return true;
	}
};

struct PThreadCond
{
	pthread_cond_t cond_;
	timespec time_;

	PThreadCond()
	{
		time_.tv_sec = -1;
		time_.tv_nsec = -1;
		pthread_cond_init(&cond_, NULL);
	}
	~PThreadCond()
	{ pthread_cond_destroy(&cond_); }

	void setTimeout(long sec, long nsec)
	{
		time_.tv_sec = sec;
		time_.tv_nsec = nsec;
	}

	void wait(PThreadMutex &m)
	{ if (pthread_cond_wait(&cond_, &m.mutex_) != 0) throw EXCEPTION(); }

	void signal()
	{ if (pthread_cond_signal(&cond_) != 0) throw EXCEPTION(); }

	bool timedWait(PThreadMutex &m)
	{
		int ret;
		if ((ret = pthread_cond_timedwait(&cond_, &m.mutex_, &time_)) != 0)
		{
			if (ret == ETIMEDOUT)
				return false;
			else
				throw EXCEPTION();
		}
		return true;
	}
};

class ThreadPool : private boost::noncopyable
{
public:
	struct Task
	{
		CallbackFunc func;
		void *param;
		PThreadCond &cond;
		PThreadMutex &mutex;
		int &status;

		Task(CallbackFunc f, void *p,
				PThreadCond &c, PThreadMutex &m, int &s)
			: func(f), param(p), cond(c), mutex(m), status(s)
		{ }

		void wait()
		{
			mutex.lock();
			while (status == 0)
				cond.wait(mutex);
			--status;
			mutex.unlock();
		}
	};

protected:
	enum { IDLE = 0, BUSY };
	class Item : public Thread
	{
	protected:
		std::list<Task*> &handlers_;
		PThreadMutex &mutex_;
		PThreadCond &cond_;
		Task *handler_;

		// pthread_cond_wait will lock the mutex, so release it
		static void cleanup_(void *p)
		{ ((Item*)p)->mutex_.unlock(); }
		static void* run_(void *self)
		{
			pthread_cleanup_push(cleanup_, self);
			while (true)
			{
				Item *This = (Item*)self;
				This->mutex_.lock();
				This->status_ = IDLE;
				pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
				while (This->handlers_.size() == 0)
					This->cond_.wait(This->mutex_);		// <--cancel point

				pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
				This->handler_ = This->handlers_.front();
				This->handlers_.pop_front();

				This->status_ = BUSY;
				This->mutex_.unlock();

				This->handler_->param =
						This->handler_->func(This->handler_->param);

				This->handler_->mutex.lock();
				++This->handler_->status;
				This->handler_->cond.signal();
				This->handler_->mutex.unlock();
				This->handler_ = NULL;
			}
			pthread_cleanup_pop(0);
			return NULL;
		}

	public:
		Item(std::list<Task*> &h, PThreadMutex &m, PThreadCond &c)
			: handlers_(h), mutex_(m), cond_(c), handler_(NULL), status_(IDLE)
		{ }

		~Item()
		{ cancel(); }

		int status_;	// 0 idle; 1 busy

		pthread_t run()
		{
			if (pthread_create(&tid_, &attr_, &Item::run_, this) == 0)
				return tid_;
			else
				throw EXCEPTION();	// EAGAIN means no memory
		}
	};

	PThreadMutex mutex_;
	PThreadCond cond_;
	std::list<Task*> handlers_;
	std::list<Item*> threads_;

public:
	explicit ThreadPool(size_t size)
	{ add(size); }
	~ThreadPool()
	{ close(); }

	void add(size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			Item *p = new Item(handlers_, mutex_, cond_);
			threads_.push_back(p);
			p->run();
		}
	}

	size_t remove(size_t size)
	{
		size_t i = 0;
		for (std::list<Item*>::iterator it = threads_.begin();
				it != threads_.end() && i < size;)
		{
			std::list<Item*>::iterator it1 = it;
			++it;
			if ((*it1)->status_ == IDLE) {
				delete *it1;
				threads_.erase(it1);
				 ++i;
			}
		}
		return i;
	}

	void close()
	{
		while (!threads_.empty())
		{
			delete threads_.front();
			threads_.pop_front();
		}
	}

	size_t size()
	{ return threads_.size(); }

	void addTask(Task &handler)
	{
		mutex_.lock();
		cond_.signal();
		handlers_.push_back(&handler);
		mutex_.unlock();
	}
};

}; // namespace xcom
#endif /* _XCOM_THREAD_H_ */
