/**
 * @file AddressTest.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_ADDRESSTEST_H_
#define _XCOM_ADDRESSTEST_H_

#include <iostream>
#include "Address.h"

using std::cout;
using std::endl;
using std::cerr;
using std::string;

using xcom::Address4;
using xcom::AddressUn;

class Address4TestCases
{
  public:
	void testConstructor()
	{
		Address4 addr;
		BOOST_CHECK(addr.sin_family == AF_INET);

		sockaddr_in sa;
		bzero(&sa, sizeof(sa));
		Address4 addr1(sa);
		BOOST_CHECK(!(addr1 == sa));

		sa.sin_family = AF_INET;
		Address4 addr2(sa);
		BOOST_CHECK(addr2 == sa);

		Address4 addr3(1234);
		BOOST_CHECK(addr3.sin_port == htons(1234));

		Address4 addr4("127.0.0.1", 1234);
		BOOST_CHECK(addr4.sin_port == htons(1234));
		BOOST_CHECK(addr4.sin_addr.s_addr == htonl(0x7f000001));

		string str = "127.0.0.1";
		Address4 addr5(str, 1234);
		BOOST_CHECK(addr5.sin_port == htons(1234));
		BOOST_CHECK(addr5.sin_addr.s_addr == htonl(0x7f000001));

		BOOST_CHECK(Address4::value == AF_INET);
		//cout << addr5 << endl;
	}

	void testP2n()
	{
		Address4 addr;
		BOOST_CHECK(addr.inet_pton("127.0.0.1"));
		BOOST_CHECK(addr.sin_addr.s_addr == htonl(0x7f000001));

		addr.setAnyAddress();
		BOOST_CHECK(addr.sin_addr.s_addr == INADDR_ANY);

		string str = "127.0.0.1";
		BOOST_CHECK(addr.inet_pton(str));
		BOOST_CHECK(addr.sin_addr.s_addr == htonl(0x7f000001));
	}

	void testN2p()
	{
		Address4 addr;
		BOOST_CHECK(addr.inet_pton("127.0.0.1"));

		char ca[20];
		string str = "127.0.0.1";
		BOOST_CHECK(addr.inet_ntop(ca, 20));
		BOOST_CHECK(str == ca);

		str.clear();
		BOOST_CHECK(addr.inet_ntop(str));
		BOOST_CHECK(str == "127.0.0.1");
	}

	void testHostPort()
	{
		Address4 addr(1234);
		BOOST_CHECK(addr.hostPort() == 1234);

		addr.clear();
		BOOST_CHECK(addr.sin_addr.s_addr == INADDR_ANY);
		BOOST_CHECK(addr.sin_port == 0);

		addr.hostPort(1234);
		BOOST_CHECK(addr.sin_port == htons(1234));
	}
};

class Address4TestSuite : public test_suite
{
  public:
	Address4TestSuite() : test_suite("Address4TestSuite")
	{
		boost::shared_ptr<Address4TestCases> instance(new Address4TestCases());
		add(BOOST_CLASS_TEST_CASE(&Address4TestCases::testConstructor, instance));
		add(BOOST_CLASS_TEST_CASE(&Address4TestCases::testP2n, instance));
		add(BOOST_CLASS_TEST_CASE(&Address4TestCases::testN2p, instance));
		add(BOOST_CLASS_TEST_CASE(&Address4TestCases::testHostPort, instance));
	}
};

class AddressUnTestCases
{
  public:
	void testConstructor()
	{
		AddressUn addr;
		BOOST_CHECK(addr.sun_family == AF_LOCAL);
		BOOST_CHECK(AddressUn::value == AF_LOCAL);
		BOOST_CHECK(addr.size() == sizeof(addr.sun_family));

		AddressUn addr1("/tmp/xcom.sock");
		BOOST_CHECK(addr1.sun_family == AF_LOCAL);
		BOOST_CHECK(addr1.size()
				== sizeof(addr1.sun_family) + strlen(addr1.sun_path));
		string str("/tmp/xcom.sock");
		BOOST_CHECK(addr1.sun_path == str);

		AddressUn addr2(str);
		BOOST_CHECK(addr2.sun_family == AF_LOCAL);
		BOOST_CHECK(addr2.sun_path == str);

		AddressUn addr3(addr2);
		BOOST_CHECK(addr3.sun_family == AF_LOCAL);
		BOOST_CHECK(addr3.sun_path == str);
		BOOST_CHECK(addr3 == addr2);

		AddressUn addr4 = addr3;
		BOOST_CHECK(addr4.sun_family == AF_LOCAL);
		BOOST_CHECK(addr4.sun_path == str);
		BOOST_CHECK(addr3 == addr4);

		//cout << addr4 << endl;
	}

};

class AddressUnTestSuite : public test_suite
{
  public:
	AddressUnTestSuite() : test_suite("AddressUnTestSuite")
	{
		boost::shared_ptr<AddressUnTestCases> instance(new AddressUnTestCases());
		add(BOOST_CLASS_TEST_CASE(&AddressUnTestCases::testConstructor, instance));
	}
};

#endif /* _XCOM_ADDRESSTEST_H_ */
