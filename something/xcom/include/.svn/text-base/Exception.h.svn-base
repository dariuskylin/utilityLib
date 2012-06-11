/*
 * @file exception.h
 * @comment
 * c++ exception
 * 
 * @author: niexw
 */

#ifndef _XCOM_EXCEPTION_H_
#define _XCOM_EXCEPTION_H_

#include <exception>
#include <string.h>
#include <errno.h>
#include <ostream>

#define EXCEPTION()	xcom::Exception(errno, __FILE__, __LINE__)

namespace xcom
{

/**
 * @class Exception
 * @comment
 * Exception extend std::exception
 */
class Exception : public std::exception
{
protected:
	int errno_;
	const char *position_;
	int line_;

public:
	Exception() : errno_(0), position_(NULL), line_(0)
	{ }
	explicit Exception(int e) : errno_(e), position_(NULL), line_(0)
	{ }
	Exception(int e, const char *f, int l) : errno_(e), position_(f), line_(l)
	{ }
	~Exception() throw()
	{ }

	int line() { return line_; }
	const char* file() { return position_; }
	const char* what() { return strerror(errno_); }

	friend std::ostream& operator<<(std::ostream &os, Exception &e)
	{
		os << e.what() << " [" << e.position_ << ":" << e.line_ << "]";
		return os;
	}
};

}; // namespace xcom

#endif /* _XCOM_EXCEPTION_H_ */
