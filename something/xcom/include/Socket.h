/**
 * @file Socket.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_SOCKET_H_
#define _XCOM_SOCKET_H_

#include <sys/socket.h>
#include "Address.h"
#include "File.h"

namespace xcom
{
static const int BackLog = 20;

/**
 * @class Socket
 * @comment
 * wrap of socket
 * @tempalte parameter
 * A  Address4 or AddressUn
 * T  SOCK_STREAM, SOCK_DGRAM
 * P  PROTOCOL type
 */
template <typename A, int T, int P>
class Socket : public BasicFile
{
protected:
	A addr_;

public:
	Socket() { }
	~Socket() { }

	void getSockAddress(A &addr) { addr = addr_; }

	void create()
	{
		if (descriptor_ != -1) ::close(descriptor_);
		descriptor_ = ::socket(A::value, T, P);
		if (descriptor_ == -1) throw EXCEPTION();
	}

	void bind(A const &addr)
	{
		if (::bind(descriptor_, (struct sockaddr *)&addr, addr.size()) == 0)
			addr_ = addr;
		else
			throw EXCEPTION();
	}

	void setOption(int level, int name, void *opt, size_t length)
	{
		if (setsockopt(descriptor_, level, name, opt, length) == -1)
			throw EXCEPTION();
	}

	void getOption(int level, int name, void *opt, size_t &length)
	{
		if (getsockopt(descriptor_, level, name, opt, &length) == -1)
			throw EXCEPTION();
	}
};

class TcpSocket : public Socket<Address4, SOCK_STREAM, 0>
{
  protected:
	Address4 peer_;

	//
	// do not use TcpSocket directly
	//
	TcpSocket()
	{ }
	~TcpSocket()
	{ }

  public:
	void getPeerAddress(Address4 &peer)
	{ peer = peer_; }

	void shutdown(int how)
	{ if (::shutdown(descriptor_, how) != 0) throw EXCEPTION(); }
	void shutdown()
	{ if (::shutdown(descriptor_, SHUT_WR) != 0) throw EXCEPTION(); }
};

class TcpClientSocket : public TcpSocket
{
  public:
	TcpClientSocket()
	{ }
	~TcpClientSocket()
	{ }

	void connect(sockaddr_in &addr)
	{
		int ret;
	  RETRY:
		ret = ::connect(descriptor_, (struct sockaddr *)&addr, sizeof(addr));
		if (ret == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			if (errno == EINPROGRESS)
				return;
			else {
				close();	// if failed to connect, the socket is unuseful
				throw EXCEPTION();
			}
		}
		peer_ = addr;
		socklen_t length = sizeof(addr_);
		getsockname(descriptor_, (struct sockaddr*)&addr_, &length);
	}

	void connect(Address4 &addr)
	{ connect((sockaddr_in &)addr); }

	void create()
	{ Socket<Address4, SOCK_STREAM, 0>::create(); }
	void create(Address4 &addr)
	{ create(); connect(addr); }
};

class TcpServerSocket : public TcpSocket
{
  public:
	TcpServerSocket()
	{ }
	~TcpServerSocket()
	{ }

	void listen()
	{ if (::listen(descriptor_, BackLog) == -1) throw EXCEPTION(); }

	void create(const Address4 &addr)
	{ Socket<Address4, SOCK_STREAM, 0>::create(); bind(addr); listen(); }

	void accept(TcpServerSocket &sock)
	{
	  RETRY:
		size_t length = sizeof(sockaddr_in);
		if ((sock.descriptor_ = ::accept(descriptor_,
							(struct sockaddr *)&sock.peer_, &length))
				== -1 && errno == EINTR)
			goto RETRY;
		if (sock.descriptor_ == -1) throw EXCEPTION();
		length = sizeof(addr_);
		getsockname(descriptor_, (struct sockaddr*)&addr_, &length);
	}
};

template <int T>
class UnixSocket : public Socket<AddressUn, T, 0>
{
  protected:
	UnixSocket()
	{ }
	~UnixSocket()
	{ }

  public:
	void create(AddressUn const &addr)
	{
		Socket<AddressUn, T, 0>::create();
		addr.unlink();
		Socket<AddressUn, T, 0>::bind(addr);
	}
};

class UnixStreamClientSocket : public UnixSocket<SOCK_STREAM>
{
  public:
	void connect(sockaddr_un &addr)
	{
		int ret;
	  RETRY:
		ret = ::connect(descriptor_, (struct sockaddr *)&addr, sizeof(addr));
		if (ret == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			if (errno == EINPROGRESS)
				return;
			else {
				close();	// if failed to connect, the socket is unuseful
				throw EXCEPTION();
			}
		}
		addr_ = addr;
	}

	void connect(AddressUn &addr)
	{ connect((sockaddr_un &)addr); }

	void create(AddressUn &addr)
	{
		Socket<AddressUn, SOCK_STREAM, 0>::create();
		connect(addr);
	}

	void create(const char *path)
	{
		AddressUn addr(path);
		create(addr);
	}
};

class UnixStreamServerSocket : public UnixSocket<SOCK_STREAM>
{
  public:
	UnixStreamServerSocket() {}
	~UnixStreamServerSocket() {}

	void listen()
	{ if (::listen(descriptor_, BackLog) == -1) throw EXCEPTION(); }

	void create(const AddressUn &addr)
	{
		UnixSocket<SOCK_STREAM>::create(addr);
		listen();
	}

	void create(const char *path)
	{
		AddressUn addr(path);
		create(addr);
	}

	void accept(UnixStreamServerSocket &sock)
	{
	  RETRY:
		size_t length = sizeof(AddressUn);
		if ((sock.descriptor_ = ::accept(descriptor_,
							(struct sockaddr *)&sock.addr_, &length))
				== -1 && errno == EINTR)
			goto RETRY;
		if (sock.descriptor_ == -1) throw EXCEPTION();
	}
};

class UdpSocket : public Socket<Address4, SOCK_DGRAM, 0>
{
  protected:
	UdpSocket()
	{ }
	~UdpSocket()
	{ }

  public:
	size_t sentto(void *buf, size_t length, int flags, Address4 &addr)
	{
		return ::sendto(descriptor_, buf, length, flags,
				(const struct sockaddr*)&addr, sizeof(addr));
	}

	size_t sendto(std::string &str, int flags, Address4 &addr)
	{
		return ::sendto(descriptor_, str.c_str(), str.size(), flags,
						(const struct sockaddr*)&addr, sizeof(addr));
	}

	size_t recvfrom(void *buf, size_t length, int flags, Address4 &addr)
	{
		size_t size = sizeof(addr);
		return ::recvfrom(descriptor_, buf, length, flags,
				(struct sockaddr*)&addr, &size);
	}

	void setBroadcast(bool set)
	{ setOption(SOL_SOCKET, SO_BROADCAST, &set, sizeof(set)); }
};

class UdpClientSocket : public UdpSocket
{
  protected:
	Address4 peer_;

  public:
	void connect(sockaddr_in &addr)
	{
		int ret;
	  RETRY:
		ret = ::connect(descriptor_, (struct sockaddr *)&addr, sizeof(addr));
		if (ret == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			if (errno == EINPROGRESS)
				return;
			else {
				close();	// if failed to connect, the socket is unuseful
				throw EXCEPTION();
			}
		}
		peer_ = addr;
		socklen_t length = sizeof(addr_);
		getsockname(descriptor_, (struct sockaddr*)&addr_, &length);
	}

	void connect(Address4 &addr)
	{ connect((sockaddr_in &)addr); }

	void disconnect()
	{
		Address4 addr;
		addr.sin_family = AF_UNSPEC;
		::connect(descriptor_, (struct sockaddr *)&addr, sizeof(addr));
		peer_.clear();
	}

	void create(Address4 &addr)
	{
		Socket<Address4, SOCK_DGRAM, 0>::create();
		connect(addr);
	}

	void getPeerAddress(Address4 &peer)
	{ peer = peer_; }
};

class UdpServerSocket : public UdpSocket
{
  public:
	UdpServerSocket()
	{ }
	~UdpServerSocket()
	{ }

	void create(Address4 &addr)
	{
		Socket<Address4, SOCK_DGRAM, 0>::create();
		Socket<Address4, SOCK_DGRAM, 0>::bind(addr);
	}
};


}; // namespace unp
#endif /* _XCOM_SOCKET_H_ */
