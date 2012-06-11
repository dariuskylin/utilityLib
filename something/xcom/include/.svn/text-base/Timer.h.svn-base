/**
 * @file Timer.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_TIMER_H_
#define _XCOM_TIMER_H_

#include <sys/timerfd.h>
#include <sys/time.h>
#include <set>
#include "File.h"
#include "Thread.h"

namespace xcom
{

class Timer : public BasicFile
{
protected:
	struct Item
	{
		timespec time;
		CallbackFunc func;
		void *param;

		Item(timespec &t, CallbackFunc f, void *p) : func(f), param(p)
		{ time.tv_sec = t.tv_sec; time.tv_nsec = t.tv_nsec;	}
	};

	struct Comp
	{
		bool operator()(Item const &i1, Item const &i2)
		{
			return i1.time.tv_sec == i2.time.tv_sec ?
					i1.time.tv_nsec < i2.time.tv_nsec :
					i1.time.tv_sec < i2.time.tv_sec;
		}
	};

	std::multiset<Item, Comp> queue_;

public:
	typedef std::multiset<Item, Comp>::iterator Handle;

	Timer()
	{ create(); }
	~Timer()
	{ close(); }

	size_t size()
	{ return queue_.size(); }

	Handle add(timespec &tv, CallbackFunc f, void *p)
	{
		timespec tvc;
		clock_gettime(CLOCK_MONOTONIC, &tvc);
		tvc.tv_sec += tv.tv_sec;
		tvc.tv_nsec += tv.tv_nsec;

		Item item(tvc, f, p);
		Handle h = queue_.insert(item);
		if (h == queue_.begin())
		{
			itimerspec t1;
			t1.it_interval = {0, 0};
			t1.it_value = {h->time.tv_sec, h->time.tv_nsec};
			if (timerfd_settime(descriptor_,
					TFD_TIMER_ABSTIME, &t1, NULL) != 0)
				throw EXCEPTION();
		}
		return h;
	}

	void remove(Handle h)
	{
		itimerspec t1;
		if (h == queue_.begin())
		{
			if (queue_.size() == 1) {
				queue_.erase(h);
				t1.it_interval = {0, 0};
				t1.it_value = {0, 0};
				timerfd_settime(descriptor_, TFD_TIMER_ABSTIME, &t1, NULL);
			} else {
				queue_.erase(h);
				h = queue_.begin();
				t1.it_interval = {0, 0};
				t1.it_value = {h->time.tv_sec, h->time.tv_nsec};
				timerfd_settime(descriptor_, TFD_TIMER_ABSTIME, &t1, NULL);
			}
			return;
		}
		else
			queue_.erase(h);
	}

	bool first(timespec &tv, CallbackFunc &f, void *&p)
	{
		if (queue_.size() > 0) {
			Handle h = queue_.begin();
			tv.tv_sec = h->time.tv_sec;
			tv.tv_nsec = h->time.tv_nsec;
			f = h->func;
			p = h->param;
			return true;
		} else
			return false;
	}

	void create()
	{
		descriptor_ = timerfd_create(CLOCK_MONOTONIC, 0);
		if (descriptor_ == -1)
			throw EXCEPTION();
	}

	static void* callback(void *p)
	{
		Timer *This = (Timer*)p;
		Handle h = This->queue_.begin();
		CallbackFunc f = h->func;
		void *param = h->param;
		This->queue_.erase(h);
		return f(param);
	}
};

}; // namespace xcom
#endif /* _XCOM_TIMER_H_ */
