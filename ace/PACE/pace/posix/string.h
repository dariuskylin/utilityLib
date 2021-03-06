/* string.h,v 1.7 2000/07/10 18:55:19 jwh1 Exp

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/posix/string.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */

#ifndef PACE_STRING_H_POSIX
#define PACE_STRING_H_POSIX

#if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
#endif /* PACE_HAS_CPLUSPLUS */

#if !defined (PACE_NULL)
# define PACE_NULL NULL
#endif /* NULL */

#ifndef PACE_SIZE_T
#define PACE_SIZE_T
  typedef size_t pace_size_t;
#endif /* PACE_SIZE_T */

#if defined (PACE_HAS_CPLUSPLUS)
}
#endif /* PACE_HAS_CPLUSPLUS */

#endif /* PACE_STRING_H_POSIX */
