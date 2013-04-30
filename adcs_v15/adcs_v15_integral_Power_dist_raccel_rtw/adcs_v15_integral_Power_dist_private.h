#ifndef RTW_HEADER_adcs_v15_integral_Power_dist_private_h_
#define RTW_HEADER_adcs_v15_integral_Power_dist_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef RTW_COMMON_DEFINES_
# define RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
 }
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

#ifdef rt_VALIDATE_MEMORY
#undef rt_VALIDATE_MEMORY
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#include "dsp_rt.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif
#endif
#endif

int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
extern void adcs_v15_integral_Power_dist_QuEST_Init(void);
extern void adcs_v15_integral_Power_dist_QuEST(void);

#if !defined(MULTITASKING) && !defined(NRT)
#  error Model (adcs_v15_integral_Power_dist) was built \
in MultiTasking solver mode, however the MULTITASKING define \
is not present. Please verify that your template makefile is \
configured correctly.
#endif
#endif
