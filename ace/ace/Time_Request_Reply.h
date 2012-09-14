/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Time_Request_Reply.h
 *
 *  Time_Request_Reply.h,v 4.11 2000/11/12 20:30:31 brunsch Exp
 *
 *  Define the format used to exchange messages between the
 *  ACE_Time_Server and clerks.
 *
 *  @author  Prashant Jain
 */
//=============================================================================


#ifndef ACE_TIME_REQUEST_REPLY_H
#define ACE_TIME_REQUEST_REPLY_H
#include "ace/pre.h"

#include "ace/Time_Value.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"

/**
 * @class ACE_Time_Request
 *
 * @brief Message format for delivering requests to the ACE_Time Server.
 *
 * This class is implemented to minimize data copying.
 * In particular, all marshaling is done in situ...
 */
class ACE_Export ACE_Time_Request
{
public:
  enum Constants
  {
    /// Request message types.
    TIME_UPDATE = 01,

    /// Class-specific constant values.
    MAX_TIME_LEN = MAXPATHLEN + 1
  };

  /// Default constructor.
  ACE_Time_Request (void);

  /// Create a <ACE_Time_Request> message.
  ACE_Time_Request (ACE_INT32 msg_type, // Type of request.
                    const ACE_UINT32 time,
                    ACE_Time_Value *timeout = 0); // Max time waiting for request.

  /// Initialize length_ in order to ensure correct byte ordering
  /// before a request is sent.
  void init (void);

  // Get the fixed size of message
  ssize_t size (void) const;

  // = Set/get the type of the message.
  ACE_INT32 msg_type (void) const;
  void msg_type (ACE_INT32);

  // = Set/get the time
  ACE_UINT32 time (void) const;
  void time (ACE_UINT32 t);

  // = Set/get the blocking semantics.
  ACE_UINT32 block_forever (void) const;
  void block_forever (ACE_UINT32);

  // = Set/get the timeout.
  ACE_Time_Value timeout (void) const;
  void timeout (const ACE_Time_Value timeout);

  /// Encode the message before transmission.
  int encode (void *&);

  /// Decode message after reception.
  int decode (void);

  /// Print out the values of the message for debugging purposes.
  void dump (void) const;

private:
  // = The 5 fields in the <Transfer> struct are transmitted to the server.
  // The remaining 2 fields are not tranferred -- they are used only on
  // the server-side to simplify lookups.

  struct Transfer
  {
    ACE_INT32 msg_type_;
    // Type of the request (i.e., <TIME_UPDATE>)

    ACE_UINT32 block_forever_;
    // Indicates if we should block forever.  If 0, then <secTimeout_>
    // and <usecTimeout_> indicates how long we should wait.

    ACE_UINT32 sec_timeout_;
    // Max seconds willing to wait for name if not blocking forever.

    ACE_UINT32 usec_timeout_;
    // Max micro seconds to wait for name if not blocking forever.

    ACE_UINT32 time_;
    // The data portion contains <time_>
  };

  /// Transfer buffer.
  Transfer transfer_;

  /// Time
  ACE_UINT32 time_;
};


#include "ace/post.h"
#endif /* ACE_TIME_REQUEST_REPLY_H */
