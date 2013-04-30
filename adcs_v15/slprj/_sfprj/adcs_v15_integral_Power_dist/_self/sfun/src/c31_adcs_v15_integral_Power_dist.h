#ifndef __c31_adcs_v15_integral_Power_dist_h__
#define __c31_adcs_v15_integral_Power_dist_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c31_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc31_adcs_v15_integral_Power_distInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c31_adcs_v15_integral_Power_dist_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_adcs_v15_integral_Power_dist_get_check_sum(mxArray *plhs[]);
extern void c31_adcs_v15_integral_Power_dist_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
