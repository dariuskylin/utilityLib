/**
 * @file SocketTest.h
 * @comment
 * 
 * @author niexw
 */

#ifndef SOCKETTEST_H_
#define SOCKETTEST_H_

#include "Socket.h"

using xcom::Socket;
using xcom::TcpServerSocket;
using xcom::TcpClientSocket;
using xcom::UnixStreamClientSocket;
using xcom::UnixStreamServerSocket;
using xcom::UdpServerSocket;
using xcom::UdpClientSocket;

class SocketTestCases
{
  public:
	void testConstructor()
	{
		Socket<Address4, SOCK_STREAM, 0> socket;
		BOOST_CHECK(socket.descriptor() == -1);

		socket.create();
		BOOST_CHECK(socket.descriptor() > 2);
	}

	void testBind()
	{
		Address4 addr(1234);
		Socket<Address4, SOCK_STREAM, 0> sock;
		sock.create();
		sock.bind(addr);
		Address4 addr1;
		sock.getSockAddress(addr1);
		BOOST_CHECK(addr1 == addr);
	}

	void testCreate()
	{
		Address4 addr("127.0.0.1", 1234);
		Socket<Address4, SOCK_STREAM, 0> sock;
		sock.create();
		sock.bind(addr);
		Address4 addr1;
		sock.getSockAddress(addr1);
		BOOST_CHECK(addr1 == addr);
	}

	void testTcpServer()
	{
		TcpServerSocket server;
		Address4 addr(1234);
		server.create(addr);
		int ret = system("netstat -ant | grep 1234 > /dev/null &");
		BOOST_CHECK(ret >= 0);

		TcpClientSocket client;
		Address4 addr1("127.0.0.1", 1234);
		client.create(addr1);
		Address4 addr2;
		client.getPeerAddress(addr2);
		BOOST_CHECK(addr2 == addr1);

		//server.setNonblock();
		TcpServerSocket as;
		server.accept(as);
		Address4 addr3, addr4;
		client.getSockAddress(addr3);
		as.getPeerAddress(addr4);
		BOOST_CHECK(addr3 == addr4);

		client.close();
	}

	void testUnixSocket()
	{
		UnixStreamServerSocket server, sa;
		server.create("/tmp/xcom.sock");

		UnixStreamClientSocket client;
		client.create("/tmp/xcom.sock");

		server.accept(sa);
		string str("Hello, world");
		client.write(str);
		char buf[20];
		bzero(buf, 20);
		sa.read(buf, 20);
		BOOST_CHECK(str == buf);

		client.close();
	}

	void testUdpSocket()
	{
		UdpServerSocket server;
		UdpClientSocket client;

		Address4 addr("127.0.0.1", 1234);
		server.create(addr);
		client.create(addr);

		string str = "Hello, world";
		client.write(str);
		char buf[20];
		bzero(buf, 20);
		addr.clear();
		server.recvfrom(buf, 20, 0, addr);
		BOOST_CHECK(str == buf);

		Address4 addr1;
		client.getSockAddress(addr1);
		BOOST_CHECK(addr == addr1);

		server.getSockAddress(addr);
		client.getPeerAddress(addr1);
		BOOST_CHECK(addr == addr1);

		client.disconnect();
		client.getPeerAddress(addr1);
		BOOST_CHECK(addr1.hostPort() == 0);
	}
};

class SocketTestSuite : public test_suite
{
  public:
	SocketTestSuite() : test_suite("SocketTestSuite")
	{
		boost::shared_ptr<SocketTestCases> instance(new SocketTestCases());
		add(BOOST_CLASS_TEST_CASE(&SocketTestCases::testConstructor, instance));
		add(BOOST_CLASS_TEST_CASE(&SocketTestCases::testBind, instance));
		add(BOOST_CLASS_TEST_CASE(&SocketTestCases::testCreate, instance));
		add(BOOST_CLASS_TEST_CASE(&SocketTestCases::testTcpServer, instance));
		add(BOOST_CLASS_TEST_CASE(&SocketTestCases::testUnixSocket, instance));
		add(BOOST_CLASS_TEST_CASE(&SocketTestCases::testUdpSocket, instance));
	}
};

#endif /* SOCKETTEST_H_ */
