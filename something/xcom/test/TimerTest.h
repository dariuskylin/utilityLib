/**
 * @file TimerTest.h
 * @comment
 * 
 * @author niexw
 */
#ifndef _XCOM_TIMERTEST_H_
#define _XCOM_TIMERTEST_H_

#include "Timer.h"

using xcom::Timer;
using xcom::CallbackFunc;

class TimerTestCases
{
  public:
	void testQueue()
	{
		Timer timer;
		BOOST_CHECK(timer.size() == 0);

		timespec tv = {2, 0};
		timespec tv1;
		clock_gettime(CLOCK_MONOTONIC, &tv1);
		Timer::Handle handle = timer.add(tv, NULL, NULL);
		BOOST_CHECK(timer.size() == 1);
		CallbackFunc f = (CallbackFunc)0x8;
		void *p = (void*)0x8;
		bool ret = timer.first(tv, f, p);
		BOOST_CHECK(ret);
		BOOST_CHECK(tv.tv_sec == tv1.tv_sec + 2);
		BOOST_CHECK(f == NULL);
		BOOST_CHECK(p == NULL);
		timer.remove(handle);
		BOOST_CHECK(timer.size() == 0);

		tv = {1, 0};
		clock_gettime(CLOCK_MONOTONIC, &tv1);
		timer.add(tv, NULL, NULL);
		tv = {2, 0};
		handle = timer.add(tv, NULL, NULL);
		Timer::Handle handle1 = timer.add(tv, NULL, NULL);
		tv = {4, 0};
		timer.add(tv, NULL, NULL);
		BOOST_CHECK(timer.size() == 4);
		ret = timer.first(tv, f, p);
		BOOST_CHECK(ret);
		BOOST_CHECK(tv.tv_sec == tv1.tv_sec + 1);
		BOOST_CHECK(handle != handle1);
	}

	Timer timer1;
	IoReactor reactor;
	void *ph;

	int onTime()
	{
		reactor.remove(ph);
		return 6;
	}

	void testTimer()
	{
		IoReactor::Task handler(timer1, &timer1.callback, &timer1);
		ph = reactor.insert(handler,
				IoReactor::TIMER | IoReactor::TRIGGER);
		BOOST_CHECK(reactor.size() == 1);

		CallbackWrapper<int> w1(bind(&TimerTestCases::onTime, ref(*this)));
		timespec tv = {1, 0};
		timespec tv1;
		clock_gettime(CLOCK_MONOTONIC, &tv1);
		timer1.add(tv, &w1.run, &w1);

		reactor.run();
		BOOST_CHECK((int)handler.result == 6);
		BOOST_CHECK(reactor.size() == 0);
	}
};

class TimerTestSuite : public test_suite
{
  public:
	TimerTestSuite() : test_suite("TimerTestSuite")
	{
		boost::shared_ptr<TimerTestCases> instance(new TimerTestCases());
		add(BOOST_CLASS_TEST_CASE(&TimerTestCases::testQueue, instance));
		add(BOOST_CLASS_TEST_CASE(&TimerTestCases::testTimer, instance));
	}
};

#endif /* _XCOM_TIMERTEST_H_ */
