/**
 * @file EpollTest.h
 * @comment
 * 
 * @author niexw
 */

#ifndef EPOLLTEST_H_
#define EPOLLTEST_H_

#include "Epoll.h"

using xcom::Epoll;
using xcom::IoReactor;
using xcom::BasicFile;

class EpollTestCases
{
  public:
	void testEpoll()
	{
		Epoll epoll;
		int ret = epoll.create();
		BOOST_CHECK(ret > 2);

		TcpServerSocket server;
		Address4 addr(1235);
		server.create(addr);
		Epoll::Event event(EPOLLIN, (void*)server.descriptor());
		epoll.registerEvent(server.descriptor(), event);

		TcpClientSocket client;
		Address4 addr1("127.0.0.1", 1235);
		client.create();
		client.setNonblock();
		event.events = EPOLLOUT;
		event.data.ptr = (void*)client.descriptor();
		epoll.registerEvent(client.descriptor(), event);
		client.connect(addr1);

		Epoll::Event events[3];
		ret = epoll.waitEvent(events, 3, -1);
		BOOST_CHECK(ret == 2);
		BOOST_CHECK(events[1].data.ptr == (void*)server.descriptor());
		BOOST_CHECK(events[0].data.ptr == (void*)client.descriptor());

		epoll.unregisterEvent(client.descriptor());
		client.close();
		event.events = EPOLLIN;
		event.data.ptr = (void*)server.descriptor();
		epoll.modifyEvent(server.descriptor(), event);
		ret = epoll.waitEvent(events, 3, -1);
		BOOST_CHECK(ret == 1);
		BOOST_CHECK(events[0].data.ptr == (void*)server.descriptor());
		BOOST_CHECK(events[0].events == EPOLLIN);
	}

	IoReactor::Handle ph;
	int onAccept(IoReactor &r,
			UnixStreamServerSocket &s, UnixStreamServerSocket &s1)
	{
		s.accept(s1);
		r.remove(ph);
		return 5;
	}

	void testReactor()
	{
		UnixStreamServerSocket server, sa;
		server.create("/tmp/xcom.sock");

		UnixStreamClientSocket client;
		client.create("/tmp/xcom.sock");

		IoReactor reactor;

		CallbackWrapper<int>
			w1(bind(&EpollTestCases::onAccept, ref(*this),
					ref(reactor), ref(server), ref(sa)));
		IoReactor::Task handler(server, &w1.run, &w1);
		ph = reactor.insert(handler,
				IoReactor::READ | IoReactor::TRIGGER);
		BOOST_CHECK(reactor.size() == 1);

		reactor.run();
		BOOST_CHECK((int)handler.result == 5);
		BOOST_CHECK(reactor.size() == 0);

		client.close();
	}
};

class EpollTestSuite : public test_suite
{
  public:
	EpollTestSuite() : test_suite("EpollTestSuite")
	{
		boost::shared_ptr<EpollTestCases> instance(new EpollTestCases());
		add(BOOST_CLASS_TEST_CASE(&EpollTestCases::testEpoll, instance));
		add(BOOST_CLASS_TEST_CASE(&EpollTestCases::testReactor, instance));
	}
};


#endif /* EPOLLTEST_H_ */
