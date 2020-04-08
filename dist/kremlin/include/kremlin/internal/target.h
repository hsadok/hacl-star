/* Copyright (c) INRIA and Microsoft Corporation. All rights reserved.
   Licensed under the Apache 2.0 License. */

#ifndef __KREMLIN_TARGET_H
#define __KREMLIN_TARGET_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <limits.h>

#include "kremlin/internal/callconv.h"

/******************************************************************************/
/* Macros that KreMLin will generate.                                         */
/******************************************************************************/

/* For "bare" targets that do not have a C stdlib, the user might want to use
 * [-add-early-include '"mydefinitions.h"'] and override these. */
// #ifndef KRML_HOST_PRINTF
// #  define KRML_HOST_PRINTF printf
// #endif

#if (                                                                          \
    (defined __STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) &&             \
    (!(defined KRML_HOST_EPRINTF)))
#  define KRML_HOST_EPRINTF(...) fprintf(stderr, __VA_ARGS__)
#endif


extern void* (*ec_malloc)(size_t);
extern void (*ec_free)(void*);

inline void* ec_calloc(size_t nmemb, size_t size)
{
  size_t buffer_sz = nmemb * size;
  uint8_t* ptr = ec_malloc(buffer_sz);
  for (size_t i = 0; i < buffer_sz; ++i) {
    ptr[i] = (uint8_t) 0;
  }
  return (void*) ptr;
}

#ifndef KRML_HOST_PRINTF
inline int dummy_printf(__attribute__ ((unused)) const char* a, ...) {
  return 0;
}
#  define KRML_HOST_PRINTF dummy_printf
#endif

inline void dummy_exit() {
  __builtin_trap();
  __builtin_unreachable ();
}

inline void* dummy_malloc(__attribute__ ((unused)) size_t a) {
  return NULL;
}

inline void* dummy_calloc(__attribute__ ((unused)) size_t a, __attribute__ ((unused)) size_t b) {
  return NULL;
}

inline void dummy_free(__attribute__ ((unused)) void* a) {
}

#ifndef KRML_HOST_EXIT
#  define KRML_HOST_EXIT(X) dummy_exit();\
 __builtin_unreachable();
#endif

#ifndef KRML_HOST_MALLOC
#  define KRML_HOST_MALLOC ec_malloc
#endif

#ifndef KRML_HOST_CALLOC
#  define KRML_HOST_CALLOC ec_calloc
#endif

#ifndef KRML_HOST_FREE
#  define KRML_HOST_FREE ec_free
#endif

#ifndef KRML_HOST_TIME

#  include <time.h>

/* Prims_nat not yet in scope */
inline static int32_t krml_time() {
  return (int32_t)time(NULL);
}

#  define KRML_HOST_TIME krml_time
#endif

/* In statement position, exiting is easy. */
#define KRML_EXIT                                                              \
  do {                                                                         \
    KRML_HOST_EXIT(254);                                                       \
  } while (0)

/* In expression position, use the comma-operator and a malloc to return an
 * expression of the right size. KreMLin passes t as the parameter to the macro.
 */
#define KRML_EABORT(t, msg)                                                    \
  (dummy_exit(), *((t *)dummy_malloc(sizeof(t))))

/* In FStar.Buffer.fst, the size of arrays is uint32_t, but it's a number of
 * *elements*. Do an ugly, run-time check (some of which KreMLin can eliminate).
 */

#ifdef __GNUC__
#  define _KRML_CHECK_SIZE_PRAGMA                                              \
    _Pragma("GCC diagnostic ignored \"-Wtype-limits\"")
#else
#  define _KRML_CHECK_SIZE_PRAGMA
#endif

#define KRML_CHECK_SIZE(size_elt, sz)                                          \
  do {                                                                         \
    _KRML_CHECK_SIZE_PRAGMA                                                    \
    if (((size_t)(sz)) > ((size_t)(SIZE_MAX / (size_elt)))) {                  \
      KRML_HOST_PRINTF(                                                        \
          "Maximum allocatable size exceeded, aborting before overflow at "    \
          "%s:%d\n",                                                           \
          __FILE__, __LINE__);                                                 \
      KRML_HOST_EXIT(253);                                                     \
    }                                                                          \
  } while (0)

#if defined(_MSC_VER) && _MSC_VER < 1900
#  define KRML_HOST_SNPRINTF(buf, sz, fmt, arg) _snprintf_s(buf, sz, _TRUNCATE, fmt, arg)
#else
#  define KRML_HOST_SNPRINTF(buf, sz, fmt, arg) snprintf(buf, sz, fmt, arg)
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ > 4
#  define KRML_DEPRECATED(x) __attribute__((deprecated(x)))
#elif  defined(__GNUC__)
/* deprecated attribute is not defined in GCC < 4.5. */
#  define KRML_DEPRECATED(x)
#elif defined(_MSC_VER)
#  define KRML_DEPRECATED(x) __declspec(deprecated(x))
#endif

#endif
