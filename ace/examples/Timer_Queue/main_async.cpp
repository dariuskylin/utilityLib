// main_async.cpp,v 4.2 1998/07/31 22:55:22 gonzo Exp

// ============================================================================
//
// = LIBRARY
//    examples
// 
// = FILENAME
//    main_async.cpp             
//
// = DESCRIPTION
//      Implements an asynchronous timer queue.
//      This code exercises the Timer_Queue_Test_Driver class using
//      signals as an asynchronous mechanism to dispatch events.
//
// = AUTHORS
//    Douglas Schmidt      <schmidt@cs.wustl.edu> &&
//    Sergio Flores-Gaitan <sergio@cs.wustl.edu>  
// 
// ============================================================================

#include "ace/Auto_Ptr.h"
#include "Driver.h"
#include "Async_Timer_Queue_Test.h"

ACE_RCSID(Timer_Queue, main_async, "main_async.cpp,v 4.2 1998/07/31 22:55:22 gonzo Exp")

typedef Timer_Queue_Test_Driver<Async_Timer_Queue *,
                                Async_Timer_Queue,
                                Async_Timer_Queue::ACTION>
        ASYNC_TIMER_QUEUE_TEST_DRIVER;

int
main (int, char *[])
{
  ASYNC_TIMER_QUEUE_TEST_DRIVER *tqtd;
  ACE_NEW_RETURN (tqtd, Async_Timer_Queue_Test_Driver, -1);
  // Auto ptr ensures that the driver memory is released
  // automatically.
  auto_ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER> driver (tqtd);
  
  return driver->run_test ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class auto_ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>;
template class ACE_Auto_Basic_Ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate auto_ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>
#pragma instantiate ACE_Auto_Basic_Ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


