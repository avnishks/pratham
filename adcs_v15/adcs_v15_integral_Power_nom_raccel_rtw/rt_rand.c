#include "rt_rand.h"

real_T rt_Urand(uint32_T *seed)
{
  uint32_T hi = *seed / 127773U;
  uint32_T lo = *seed % 127773U;
  int32_T test = (16807 * lo) - (2836 * hi);
  *seed = ((test < 0) ? (uint32_T)(test + 2147483647) : (uint32_T)test);
  return ((real_T) (*seed * 4.656612875245797e-10));
}

real_T rt_NormalRand(uint32_T *seed)
{
  real_T sr, si, t;
  do {
    sr = (2.0 * rt_Urand(seed)) - 1.0;
    si = (2.0 * rt_Urand(seed)) - 1.0;
    t = (sr * sr) + (si * si);
  } while (t > 1.0);

  return(sr * sqrt((-2.0 * log(t)) / t));
}
