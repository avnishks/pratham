#ifndef __c16_adcs_v15_integral_Power_h__
#define __c16_adcs_v15_integral_Power_h__

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
} c16_ResolvedFunctionInfo;

typedef struct {
  real_T c16_Cd;
  real_T c16_side;
  real_T c16_v_COM_to_COP_b[3];
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc16_adcs_v15_integral_PowerInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c16_adcs_v15_integral_Power_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[]);
extern void c16_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
