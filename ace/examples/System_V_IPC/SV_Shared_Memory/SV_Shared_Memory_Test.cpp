// SV_Shared_Memory_Test.cpp,v 4.2 1998/07/31 22:55:20 gonzo Exp

#include "ace/SV_Shared_Memory.h"
#include "SV_Shared_Memory_Test.h"

ACE_RCSID(SV_Shared_Memory, SV_Shared_Memory_Test, "SV_Shared_Memory_Test.cpp,v 4.2 1998/07/31 22:55:20 gonzo Exp")

static void
client (void)
{
  ACE_SV_Shared_Memory shm_client;

  if (shm_client.open_and_attach (SHM_KEY, SHMSZ) == -1)
    ACE_OS::perror ("open"), ACE_OS::exit (1);

  for (char *s = (char *) shm_client.get_segment_ptr (); *s != '\0'; s++)
    putchar (*s);

  putchar ('\n');
  *(char *) shm_client.get_segment_ptr () = '*';
  ACE_OS::exit (0);
}

static void
server (void)
{
  ACE_SV_Shared_Memory shm_server;

  if (shm_server.open_and_attach (SHM_KEY, SHMSZ, ACE_SV_Shared_Memory::ACE_CREATE) == -1)
    ACE_OS::perror ("open"), ACE_OS::exit (1);

  char *s = (char *) shm_server.get_segment_ptr ();

  for (char c = 'a'; c <= 'z'; c++)
    *s++ = c;

  *s = '\0';

  for (s = (char *) shm_server.get_segment_ptr (); *s != '*'; )
    ACE_OS::sleep (1);

  if (shm_server.remove () < 0)
    ACE_OS::perror ("remove"), ACE_OS::exit (1);
  ACE_OS::exit (0);
}

int
main (int, char *argv[])
{
  switch (ACE_OS::fork ())
    {
    case -1:
      ACE_OS::perror (argv[0]), ACE_OS::exit (1);
    case 0: 
      ACE_OS::sleep (1); 
      client ();
    default:
      server ();
    }
  return 0;
}

