/**
 * @file file.h
 * @comment
 * wrap of file descriptor
 *
 * @author niexw
 */

#ifndef _XCOM_FILE_H_
#define _XCOM_FILE_H_

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <string>
#include "boost/utility.hpp"
#include "Exception.h"

namespace xcom
{

class BasicFile : private boost::noncopyable
{
protected:
	int descriptor_;

	BasicFile() : descriptor_(-1)
	{ }
	~BasicFile()
	{ close(); }

public:
	int descriptor() { return descriptor_; }
	void sync() { ::sync(); }
	int dup() { return ::dup(descriptor_); }

	void attach(int fd)
	{ descriptor_ = fd; }
	void attach(FILE *s)
	{ descriptor_ = fileno(s); }
	void detach()
	{ descriptor_ = -1; }

	size_t read(char *buf, size_t count)
	{
		int ret;
	  RETRY:
		if ((ret = ::read(descriptor_, buf, count)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		return ret;
	}

	size_t write(char const *buf, size_t count)
	{
		int ret;
	  RETRY:
		if ((ret = ::write(descriptor_, buf, count)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		return ret;
	}

	size_t write(const std::string &str)
	{ return write(str.c_str(), str.size()); }

	void close()
	{
		if (descriptor_ != -1)
		{
			::close(descriptor_);
			descriptor_ = -1;
		}
	}

	size_t readv(const struct iovec *iov, int cnt)
	{
		int ret;
	  RETRY:
		if ((ret = ::readv(descriptor_, iov, cnt)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		return ret;
	}

	size_t writev(const struct iovec *iov, int cnt)
	{
		int ret;
	  RETRY:
		if ((ret = ::writev(descriptor_, iov, cnt)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		return ret;
	}

	void setControlOption(int option)
	{
		int flags;
	  RETRY:
		flags = fcntl(descriptor_, F_GETFL);
		if (flags == -1) {
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		flags |= option;
	  RETRY1:
		int ret = fcntl(descriptor_, F_SETFL, flags);
		if (ret == -1) {
			if (errno == EINTR)
				goto RETRY1;
			else
				throw EXCEPTION();
		}
	}

	void clearControlOption(int option)
	{
		int flags;
	  RETRY:
		flags = fcntl(descriptor_, F_GETFL);
		if (flags == -1) {
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		flags &= ~option;
	  RETRY1:
		int ret = fcntl(descriptor_, F_SETFL, flags);
		if (ret == -1) {
			if (errno == EINTR)
				goto RETRY1;
			else
				throw EXCEPTION();
		}
	}

	void setNonblock()
	{
		int flags = fcntl(descriptor_, F_GETFL);
		if (flags == -1)
			throw EXCEPTION();
		flags |= O_NONBLOCK;
		flags = fcntl(descriptor_, F_SETFL, flags);
		if (flags == -1)
			throw EXCEPTION();
	}

	void clrNonblock()
	{
		int flags = fcntl(descriptor_, F_GETFL);
		if (flags == -1)
			throw EXCEPTION();
		flags &= ~O_NONBLOCK;
		flags = fcntl(descriptor_, F_SETFL, flags);
		if (flags == -1)
			throw EXCEPTION();
	}
};

/**
 * @class File
 * @comment
 * wrap of file descriptor
 */
class File : public BasicFile
{
public:
	File()
	{ }
	~File()
	{ }

	int open(const char *pathname, int flags)
	{
		int ret;
		if (descriptor_ != -1) return -1;
	  RETRY:
		if ((ret = ::open(pathname, flags)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		descriptor_ = ret;
		return ret;
	}

	int open(const char *pathname, int flags, mode_t mode)
	{
		int ret;
		if (descriptor_ != -1) return -1;
	  RETRY:
		if ((ret = ::open(pathname, flags, mode)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		descriptor_ = ret;
		return ret;
	}

	int open(const std::string &pathname, int flags)
	{
		int ret;
		if (descriptor_ != -1) return -1;
	  RETRY:
		if ((ret = ::open(pathname.c_str(), flags)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		descriptor_ = ret;
		return ret;
	}

	int open(const std::string &pathname, int flags, mode_t mode)
	{
		int ret;
		if (descriptor_ != -1) return -1;
	  RETRY:
		if ((ret = ::open(pathname.c_str(), flags, mode)) == -1)
		{
			if (errno == EINTR)
				goto RETRY;
			else
				throw EXCEPTION();
		}
		descriptor_ = ret;
		return ret;
	}

	off_t lseek(off_t offset, int where)
	{
		off_t o = ::lseek(descriptor_, offset, where);
		if (o == -1)
			throw EXCEPTION();
		return o;
	}
};

}; // namespace xcom
#endif // _XCOM_FILE_H_
