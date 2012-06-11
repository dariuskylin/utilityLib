/**
 * @file ThreadTest.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_THREADTEST_H_
#define _XCOM_THREADTEST_H_

#include "Thread.h"

using xcom::Thread;
using xcom::PThreadMutex;
using xcom::PThreadCond;
using xcom::ThreadPool;
using xcom::CallbackWrapper;

using boost::ref;
using boost::bind;
using boost::function;
using boost::lambda::constant;
using boost::lambda::var;

static int x1 = 0;

void* setX1(void *p)
{ x1 = (int)p; return NULL; }

class ThreadTestCases
{
  public:
	void testRun()
	{
		Thread t;
		t.run(&setX1, (void*)2);
		t.join();
		BOOST_CHECK(x1 == 2);
		BOOST_CHECK(!t.isRunning());
	}
};

void* lock1(void *p)
{
	PThreadMutex *m = (PThreadMutex*)p;
	m->lock();
	//while (true) {}
	return NULL;
}

void* access1(void *p)
{
	PThreadMutex *m = (PThreadMutex*)p;
	m->lock();
	x1 = 3;
	m->unlock();
	return NULL;
}

void* trylock1(void *p)
{
	PThreadMutex *m = (PThreadMutex*)p;
	bool ret = m->trylock();
	x1 = ret ? 1 : 4;
	if (ret) m->unlock();
	return NULL;
}

class PThreadMutexTestCases
{
  public:
	void testLock()
	{
		PThreadMutex mutex;

		Thread t1, t2;
		x1 = 0;
		t1.run(&lock1, (void*)&mutex);
		t1.join();
		t2.run(&access1, (void*)&mutex);
		BOOST_CHECK(x1 == 0);

		Thread t3;
		t3.run(&trylock1, (void*)&mutex);
		t3.join();
		BOOST_CHECK(x1 == 4);

		mutex.unlock();
		t3.run(&trylock1, (void*)&mutex);
		t3.join();
		BOOST_CHECK(x1 == 1);
	}
};

// Note: if we want to use bood::bind, the bound parameters may be used with
// pointer or reference. But boost::bind will transform the parameter with
// value. To use with reference, we must explicitly declare with boost::ref.
void consume(PThreadMutex &m, PThreadCond &c)
{
	m.lock();
	while (x1 == 0)
		c.wait(m);
	--x1;
	m.unlock();
}

void produce(PThreadMutex &m, PThreadCond &c)
{
	m.lock();
	++x1;
	c.signal();
	m.unlock();
}

class PThreadCondTestCases
{
  public:
	void testWait()
	{
		PThreadMutex mutex;
		PThreadCond cond;

		x1 = 0;
		Thread t1, t2;
		CallbackWrapper<void> w1(bind(&produce, ref(mutex), ref(cond)));
		CallbackWrapper<void> w2(bind(&consume, ref(mutex), ref(cond)));
		t2.run(CALLBACK_PARAMS(w2));
		t1.run(CALLBACK_PARAMS(w1));
		t2.join();
		t1.join();
		BOOST_CHECK(x1 == 0);
	}
};

int addX1()
{ return ++x1+2; }

class ThreadPoolTestCases
{
public:
	void testAddHandler()
	{
		x1 = 0;
		ThreadPool pool(5);
		CallbackWrapper<int> w1(&addX1);
		PThreadCond cond;
		PThreadMutex mutex;
		int status = 0;

		ThreadPool::Task handler(CALLBACK_PARAMS(w1),
				cond, mutex, status);
		pool.addTask(handler);
		handler.wait();
		BOOST_CHECK((int)handler.param == 3);
		BOOST_CHECK(x1 == 1);

		size_t ret = pool.remove(3);
		BOOST_CHECK(ret == 3);
		BOOST_CHECK(3 == ret);
		BOOST_CHECK(pool.size() == 2);

		x1 = 0;
		handler.param = &w1;
		pool.addTask(handler);
		handler.wait();
		BOOST_CHECK((int)handler.param == 3);
		BOOST_CHECK(x1 == 1);
	}
};

class ThreadTestSuite : public test_suite
{
  public:
	ThreadTestSuite() : test_suite("ThreadTestSuite")
	{
		boost::shared_ptr<ThreadTestCases> instance(new ThreadTestCases());
		add(BOOST_CLASS_TEST_CASE(&ThreadTestCases::testRun, instance));

		boost::shared_ptr<PThreadMutexTestCases> instance1(new PThreadMutexTestCases());
		add(BOOST_CLASS_TEST_CASE(&PThreadMutexTestCases::testLock, instance1));

		boost::shared_ptr<PThreadCondTestCases> instance2(new PThreadCondTestCases());
		add(BOOST_CLASS_TEST_CASE(&PThreadCondTestCases::testWait, instance2));

		boost::shared_ptr<ThreadPoolTestCases> instance4(new ThreadPoolTestCases());
		add(BOOST_CLASS_TEST_CASE(&ThreadPoolTestCases::testAddHandler, instance4));
	}
};

#endif /* _XCOM_THREADTEST_H_ */
