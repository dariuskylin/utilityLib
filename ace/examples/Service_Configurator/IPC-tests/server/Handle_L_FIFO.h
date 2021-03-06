/* -*- C++ -*- */
// Handle_L_FIFO.h,v 4.5 2000/10/17 05:31:36 schmidt Exp

/* Handle connections from local UNIX ACE_FIFO */
/* Read from a well known ACE_FIFO and write to stdout. */

#ifndef _HANDLE_L_FIFO_H
#define _HANDLE_L_FIFO_H

#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Types.h"
#include "ace/FIFO_Recv_Msg.h"
#include "ace/Log_Msg.h"

class Handle_L_FIFO : public ACE_Service_Object, public ACE_FIFO_Recv_Msg
{
public:
  Handle_L_FIFO (void);
  virtual int init (int argc, char *argv[]);
  virtual int info (char **, size_t) const;
  virtual int fini (void);

private:
  int open (const char *rendezvous_fifo);
  virtual ACE_HANDLE get_handle (void) const;
  virtual int handle_input (ACE_HANDLE fd);
  virtual int handle_close (ACE_HANDLE fd, ACE_Reactor_Mask);

  static const char *DEFAULT_RENDEZVOUS;
};

extern ACE_Service_Object_Type lf;

#if defined (__ACE_INLINE__)
#define ACE_INLINE inline
#include "Handle_L_FIFO.i"
#else
#define ACE_INLINE
#endif /* __ACE_INLINE__ */

#endif /* _HANDLE_L_FIFO_H */


