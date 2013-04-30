#ifndef __c26_adcs_v15_integral_Power_nom_no_charge_in_detumb_h__
#define __c26_adcs_v15_integral_Power_nom_no_charge_in_detumb_h__

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
} c26_ResolvedFunctionInfo;

typedef struct {
  real_T c26_s_SIM_STEP_SIZE;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc26_adcs_v15_integral_Power_nom_no_charge_in_detumbInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c26_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c26_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
  (mxArray *plhs[]);
extern void
  c26_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
