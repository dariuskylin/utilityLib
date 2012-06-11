/**
 * @file Defines.h
 * @comments
 * defines some basic types and macros.
 *
 * @author niexw
 */

#ifndef _XCOM_DEFINES_H_
#define _XCOM_DEFINES_H_

#if defined(_MSC_VER) && _MSC_VER >= 1100
#define _CRT_SECURE_NO_DEPRECATE
#define _SCL_SECURE_NO_DEPRECATE
#pragma warning(disable:4161)
#define XCOM_NO_VTABLE __declspec(novtable)
#else
#define XCOM_NO_VTABLE
#endif

#include <cstddef>
#include <boost/cstdint.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid_serialize.hpp>
#include <boost/uuid/uuid_io.hpp>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_VECTOR_SIZE 50
#define XCOM_MAX_INTERFACES_NUM BOOST_MPL_LIMIT_VECTOR_SIZE
#include <boost/mpl/vector.hpp>

namespace xcom
{

typedef boost::int8_t int8;
typedef boost::uint8_t uint8;
typedef boost::int16_t int16;
typedef boost::uint16_t uint16;
typedef boost::int32_t int32;
typedef boost::uint32_t uint32;

typedef boost::int64_t int64;
typedef boost::uint64_t uint64;

typedef unsigned long ulong;

typedef boost::uuids::uuid IID;
typedef boost::uuids::uuid ClsID;
typedef boost::uuids::string_generator Str2Uuid;

static const long SUCCESS = 0L;
static const long ERROR = -1L;

}; // namespace xcom

#endif // _XCOM_DEFINES_H_
