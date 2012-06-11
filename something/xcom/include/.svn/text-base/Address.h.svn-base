/**
 * @file Address.h
 * @comment
 * wrap of struct sockaddr_in
 *
 * @author niexw
 */

#ifndef _XCOM_ADDRESS_H_
#define _XCOM_ADDRESS_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string>
#include <assert.h>
#include <ostream>
#include <stdio.h>
#include <sys/un.h>

namespace xcom
{
/**
 * @class Address4
 * @comment
 * Address4 is wrap of sockaddr_in
 */
struct Address4 : public sockaddr_in
{
	typedef int value_type;
	static int const value = AF_INET;

	Address4()
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
	}

	explicit Address4(sockaddr_in &sa)
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
		if (sa.sin_family != AF_INET)
			return;
		sin_port = sa.sin_port;
		sin_addr.s_addr = sa.sin_addr.s_addr;
	}

	Address4(const Address4 &addr)
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
		sin_port = addr.sin_port;
		sin_addr.s_addr = addr.sin_addr.s_addr;
	}

	Address4(const unsigned int addr, const unsigned short port)
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
		sin_port = htons(port);
		sin_addr.s_addr = htonl(addr);
	}

	Address4(const unsigned short port)
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
		sin_port = htons(port);
		sin_addr.s_addr = INADDR_ANY;
	}

	Address4(const char *p, unsigned short port)
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
		inet_pton(p);
		sin_port = htons(port);
	}

	Address4(const std::string &addr, unsigned short port)
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
		inet_pton(addr.c_str());
		sin_port = htons(port);
	}

	~Address4() { }

	inline size_t size() const
	{ return sizeof(Address4); }

	//
	// presentation to number and so on
	//
	bool inet_pton(const char *p)
	{ return ::inet_pton(AF_INET, p, (void *)&sin_addr.s_addr); }
	bool inet_pton(std::string &s)
	{ return ::inet_pton(AF_INET, s.c_str(), (void *)&sin_addr.s_addr); }
	bool inet_ntop(char *buf, size_t size)
	{
		return buf == NULL || ::inet_ntop(AF_INET,
			(const void *)&sin_addr.s_addr,	buf, size) == NULL ?
					false : true;
	}
	bool inet_ntop(std::string &s)
	{
		s.resize(16);
		const char* ret = ::inet_ntop(AF_INET, (const void *)&sin_addr.s_addr,
				(char *)s.c_str(), 16);
		if (ret == NULL)
			return false;
		s.resize(strlen(s.c_str()));
		return true;
	}

	void setAnyAddress() { sin_addr.s_addr = INADDR_ANY; }

	void hostPort(unsigned short p) { sin_port = htons(p); }
	unsigned short hostPort() { return ntohs(sin_port); }

	void clear()
	{
		bzero(this, sizeof(Address4));
		sin_family = AF_INET;
	}

	//
	// operators
	//
	bool operator==(const Address4 &rhs)
	{
		return sin_port == rhs.sin_port
				&& sin_addr.s_addr == rhs.sin_addr.s_addr;
	}
	bool operator==(const sockaddr_in &rhs)
	{
		return sin_family == rhs.sin_family && sin_port == rhs.sin_port
				&& sin_addr.s_addr == rhs.sin_addr.s_addr;
	}
	Address4& operator=(const sockaddr_in &addr)
	{
		assert(addr.sin_family == AF_INET);
		sin_port = addr.sin_port;
		sin_addr.s_addr = addr.sin_addr.s_addr;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream &os, Address4 &addr)
	{
		char p[16];
		::inet_ntop(AF_INET, (const void *)&addr.sin_addr.s_addr, p, 16);
		os << p << ":" << ntohs(addr.sin_port);
		return os;
	}
};

struct AddressUn : public sockaddr_un
{
	typedef int value_type;
	static int const value = AF_LOCAL;

	AddressUn()
	{
		bzero(this, sizeof(AddressUn));
		sun_family = AF_LOCAL;
	}

	AddressUn(AddressUn &addr)
	{
		assert(addr.sun_family == AF_LOCAL);
		bzero(this, sizeof(AddressUn));
		sun_family = AF_LOCAL;
		bcopy(addr.sun_path, sun_path, strlen(addr.sun_path));
	}

	AddressUn(char const *p)
	{
		bzero(this, sizeof(AddressUn));
		sun_family = AF_LOCAL;
		bcopy(p, sun_path, strlen(p));
	}

	AddressUn(std::string const &str)
	{
		bzero(this, sizeof(AddressUn));
		sun_family = AF_LOCAL;
		bcopy(str.c_str(), sun_path, str.size());
	}

	size_t size() const
	{ return (long)&sun_path - (long)this + strlen(sun_path); }

	void unlink() const
	{ ::unlink(sun_path); }

	bool operator==(const AddressUn &rhs)
	{ return bcmp(this, &rhs, sizeof(AddressUn)) == 0; }
	bool operator==(const sockaddr_un &rhs)
	{ return bcmp(this, &rhs, sizeof(AddressUn)) == 0; }
	AddressUn& operator=(const sockaddr_un &addr)
	{
		assert(addr.sun_family == AF_LOCAL);
		bzero(this, sizeof(AddressUn));
		sun_family = AF_LOCAL;
		bcopy(addr.sun_path, sun_path, strlen(addr.sun_path));
		return *this;
	}
	friend std::ostream& operator<<(std::ostream &os, AddressUn &addr)
	{
		os << addr.sun_path;
		return os;
	}
};


}; // namespace xcom

#endif // _XCOM_ADDRESS_H_
