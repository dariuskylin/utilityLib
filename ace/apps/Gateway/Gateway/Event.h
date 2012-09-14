/* -*- C++ -*- */
// Event.h,v 4.10 1999/06/16 19:04:26 shuston Exp

// ============================================================================
//
// = LIBRARY
//    gateway
//
// = FILENAME
//    Event.h
//
// = AUTHOR
//    Doug Schmidt
//
// ============================================================================

#ifndef EVENT_H
#define EVENT_H

#include "ace/OS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// = The following #defines should really be in a separate include
// file that is shared with the ../Peer/ directory.  For now, we'll
// keep them here to simplify the sharing between the two directories.
// BTW, this is also the reason why all the methods are inlined...

// Used by Peers to create Consumers in a Gateway.
#if !defined (DEFAULT_GATEWAY_CONSUMER_PORT)
#define DEFAULT_GATEWAY_CONSUMER_PORT 10009
#endif /* DEFAULT_GATEWAY_CONSUMER_PORT */

// Used by Peers create Suppliers in a Gateway.
#if !defined (DEFAULT_GATEWAY_SUPPLIER_PORT)
#define DEFAULT_GATEWAY_SUPPLIER_PORT 10010
#endif /* DEFAULT_GATEWAY_SUPPLIER_PORT */

// Used by a Gateway to create Consumers in a Peer.
#if !defined (DEFAULT_PEER_CONSUMER_PORT)
#define DEFAULT_PEER_CONSUMER_PORT 10011
#endif /* DEFAULT_PEER_CONSUMER_PORT */

// Used by a Gateway to create Suppliers in a Peer.
#if !defined (DEFAULT_PEER_SUPPLIER_PORT)
#define DEFAULT_PEER_SUPPLIER_PORT 10012
#endif /* DEFAULT_PEER_SUPPLIER_PORT */

#if !defined (MAX_CONSUMERS)
#define MAX_CONSUMERS 1000
#endif /* MAX_CONSUMERS */

// This is the unique supplier identifier that denotes a particular
// <Connection_Handler> in the Gateway.
typedef ACE_INT32 CONNECTION_ID;

enum
{
  // = These are the types of events generated by the <Suppliers> and
  // handled by the <Event_Channel>.

  ROUTING_EVENT = 0,
  // A normal event, which is forwarded to the <Consumers>.

  SUBSCRIPTION_EVENT = 1
  // A subscription to <Suppliers> managed by the <Event_Channel>.
};

class Event_Key
{
  // = TITLE
  //     Address used to identify the source/destination of an event.
  //
  // = DESCRIPTION
  //     This is really a "processing descriptor" that is used to
  //     decouple the processing, filtering, and forwarding logic of
  //     the Event Channel from the format of the data.  The
  //     <connection_id_> and <type_> fields are copied from the
  //     <Event_Header> class below.
public:
  Event_Key (CONNECTION_ID cid = -1,
             ACE_INT32 type = 0,
             ACE_INT32 priority = 0)
    : connection_id_ (cid),
      type_ (type),
      priority_ (priority)
  {
  }

  int operator== (const Event_Key &event_addr) const
  {
    return this->connection_id_ == event_addr.connection_id_
      && this->type_ == event_addr.type_;
  }

  CONNECTION_ID connection_id_;
  // Unique connection identifier that denotes a particular
  // Connection_Handler.

  ACE_INT32 type_;
  // Event type, e.g., <ROUTING_EVENT> or <SUBSCRIPTION_EVENT>.

  ACE_INT32 priority_;
  // Event priority.
};

class Event_Header
{
  // = TITLE
  //     Fixed sized header.
  //
  // = DESCRIPTION
  //     This is designed to have a sizeof (16) to avoid alignment
  //     problems on most platforms.
public:
  enum
  {
    INVALID_ID = -1 // No peer can validly use this number.
  };

  Event_Header (ACE_INT32 len,
                CONNECTION_ID connection_id,
                ACE_INT32 type,
                ACE_INT32 priority)
    : len_ (len),
      connection_id_ (connection_id),
      type_ (type),
      priority_ (priority)
  {
  }

  void decode (void)
  {
    this->len_ = ntohl (this->len_);
    this->connection_id_ = ntohl (this->connection_id_);
    this->type_ = ntohl (this->type_);
    this->priority_ = ntohl (this->priority_);
  }
  // Decode from network byte order to host byte order.

  void encode (void)
  {
    this->len_ = htonl (this->len_);
    this->connection_id_ = htonl (this->connection_id_);
    this->type_ = htonl (this->type_);
    this->priority_ = htonl (this->priority_);
  }
  // Encode from host byte order to network byte order.

  ACE_INT32 len_;
  // Length of the data_ payload, in bytes.

  CONNECTION_ID connection_id_;
  // Unique connection identifier that denotes a particular
  // Connection_Handler.

  ACE_INT32 type_;
  // Event type, e.g., <ROUTING_EVENT> or <SUBSCRIPTION_EVENT>.

  ACE_INT32 priority_;
  // Event priority.
};

class Event
{
  // = TITLE
  //    Variable-sized event (data_ may be variable-sized between
  //    0 and MAX_PAYLOAD_SIZE).
public:
  enum { MAX_PAYLOAD_SIZE = 1024 };
  // The maximum size of an Event.

  Event () : header_ (0, -1, 0, 0) {};

  Event_Header header_;
  // Event header.

  char data_[MAX_PAYLOAD_SIZE];
  // Event data.
};

class Subscription
{
  // = TITLE
  //     Allows Consumers to subscribe to be routed information
  //     arriving from a particular Supplier connection id.
public:
  void decode (void)
    {
      this->connection_id_ = ntohl (this->connection_id_);

      for (ACE_INT32 i = 0; i < this->total_consumers_; i++)
        this->consumers_[i] = ntohl (this->consumers_[i]);

      this->total_consumers_ = ntohl (this->total_consumers_);
    }
  // Decode from network byte order to host byte order.

  void encode (void)
    {
      this->connection_id_ = htonl (this->connection_id_);

      for (ACE_INT32 i = 0; i < this->total_consumers_; i++)
        this->consumers_[i] = htonl (this->consumers_[i]);

      this->total_consumers_ = htonl (this->total_consumers_);
    }
  // Encode from host byte order to network byte order.

  ACE_INT32 connection_id_;
  // Connection id.

  ACE_INT32 consumers_[MAX_CONSUMERS];
  // Connection ids for consumers that will be routed information
  // containing this <connection_id_>

  ACE_INT32 total_consumers_;
  // Total number of these consumers.
};

#endif /* EVENT_H */
