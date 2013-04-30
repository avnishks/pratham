#ifndef __c29_adcs_v15_integral_Power_nom_h__
#define __c29_adcs_v15_integral_Power_nom_h__

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
} c29_ResolvedFunctionInfo;

typedef struct {
  real_T c29_s_W_SAT;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc29_adcs_v15_integral_Power_nomInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c29_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c29_adcs_v15_integral_Power_nom_get_check_sum(mxArray *plhs[]);
extern void c29_adcs_v15_integral_Power_nom_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
