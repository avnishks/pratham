#ifndef RTW_HEADER_rt_rand_h_
#define RTW_HEADER_rt_rand_h_
#include <math.h>
#include "rtwtypes.h"
# define MAXSEED                       2147483646
# define SEED0                         1144108930
# define RT_BIT16                      32768

extern real_T rt_Urand(uint32_T *seed);
extern real_T rt_NormalRand(uint32_T *seed);

#endif
