/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c10_adcs_v15_integral_Power.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c10_IN_NO_ACTIVE_CHILD         (0)
#define c10_b_s_FRAME_SIZE             (2.0)

/* Variable Declarations */

/* Variable Definitions */
static SFc10_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c10_adcs_v15_integral_Power(void);
static void initialize_params_c10_adcs_v15_integral_Power(void);
static void enable_c10_adcs_v15_integral_Power(void);
static void disable_c10_adcs_v15_integral_Power(void);
static void c10_update_debugger_state_c10_adcs_v15_integral_Power(void);
static void ext_mode_exec_c10_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c10_adcs_v15_integral_Power(void);
static void set_sim_state_c10_adcs_v15_integral_Power(const mxArray *c10_st);
static void finalize_c10_adcs_v15_integral_Power(void);
static void sf_c10_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshall(void *c10_chartInstance, void *c10_u);
static const mxArray *c10_b_sf_marshall(void *c10_chartInstance, void *c10_u);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[17]);
static const mxArray *c10_c_sf_marshall(void *c10_chartInstance, void *c10_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c10_adcs_v15_integral_Power(void)
{
  uint8_T *c10_is_active_c10_adcs_v15_integral_Power;
  c10_is_active_c10_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c10_is_active_c10_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c10_adcs_v15_integral_Power(void)
{
  real_T c10_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_FRAME_SIZE' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c10_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c10_s_FRAME_SIZE = c10_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c10_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c10_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c10_update_debugger_state_c10_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c10_adcs_v15_integral_Power(void)
{
  c10_update_debugger_state_c10_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c10_adcs_v15_integral_Power(void)
{
  const mxArray *c10_st = NULL;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_u[3];
  const mxArray *c10_b_y = NULL;
  int32_T c10_i1;
  real_T c10_b_u[3];
  const mxArray *c10_c_y = NULL;
  uint8_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  uint8_T *c10_is_active_c10_adcs_v15_integral_Power;
  real_T (*c10_dB)[3];
  real_T (*c10_B)[3];
  c10_dB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c10_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c10_is_active_c10_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(3));
  for (c10_i0 = 0; c10_i0 < 3; c10_i0 = c10_i0 + 1) {
    c10_u[c10_i0] = (*c10_B)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  for (c10_i1 = 0; c10_i1 < 3; c10_i1 = c10_i1 + 1) {
    c10_b_u[c10_i1] = (*c10_dB)[c10_i1];
  }

  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_u = *c10_is_active_c10_adcs_v15_integral_Power;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 2, c10_d_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_adcs_v15_integral_Power(const mxArray *c10_st)
{
  const mxArray *c10_u;
  const mxArray *c10_B;
  real_T c10_dv0[3];
  int32_T c10_i2;
  real_T c10_y[3];
  int32_T c10_i3;
  const mxArray *c10_b_B;
  real_T c10_dv1[3];
  int32_T c10_i4;
  real_T c10_b_y[3];
  int32_T c10_i5;
  const mxArray *c10_is_active_c10_adcs_v15_integral_Power;
  uint8_T c10_u0;
  uint8_T c10_c_y;
  boolean_T *c10_doneDoubleBufferReInit;
  uint8_T *c10_b_is_active_c10_adcs_v15_integral_Power;
  real_T (*c10_c_B)[3];
  real_T (*c10_dB)[3];
  c10_dB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c10_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c10_c_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c10_b_is_active_c10_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_B = sf_mex_dup(sf_mex_getcell(c10_u, 0));
  sf_mex_import("B", sf_mex_dup(c10_B), &c10_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i2 = 0; c10_i2 < 3; c10_i2 = c10_i2 + 1) {
    c10_y[c10_i2] = c10_dv0[c10_i2];
  }

  sf_mex_destroy(&c10_B);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3 = c10_i3 + 1) {
    (*c10_c_B)[c10_i3] = c10_y[c10_i3];
  }

  c10_b_B = sf_mex_dup(sf_mex_getcell(c10_u, 1));
  sf_mex_import("dB", sf_mex_dup(c10_b_B), &c10_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i4 = 0; c10_i4 < 3; c10_i4 = c10_i4 + 1) {
    c10_b_y[c10_i4] = c10_dv1[c10_i4];
  }

  sf_mex_destroy(&c10_b_B);
  for (c10_i5 = 0; c10_i5 < 3; c10_i5 = c10_i5 + 1) {
    (*c10_dB)[c10_i5] = c10_b_y[c10_i5];
  }

  c10_is_active_c10_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c10_u, 2));
  sf_mex_import("is_active_c10_adcs_v15_integral_Power", sf_mex_dup
                (c10_is_active_c10_adcs_v15_integral_Power), &c10_u0, 1, 3, 0U,
                0,
                0U, 0);
  c10_c_y = c10_u0;
  sf_mex_destroy(&c10_is_active_c10_adcs_v15_integral_Power);
  *c10_b_is_active_c10_adcs_v15_integral_Power = c10_c_y;
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_adcs_v15_integral_Power();
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_adcs_v15_integral_Power(void)
{
}

static void sf_c10_adcs_v15_integral_Power(void)
{
  int32_T c10_i6;
  int32_T c10_i7;
  int32_T c10_i8;
  int32_T c10_i9;
  int32_T c10_previousEvent;
  int32_T c10_i10;
  real_T c10_B_l[3];
  int32_T c10_i11;
  real_T c10_B_k[3];
  real_T c10_nargout = 2.0;
  real_T c10_nargin = 3.0;
  real_T c10_c_s_FRAME_SIZE = c10_b_s_FRAME_SIZE;
  real_T c10_dB[3];
  real_T c10_B[3];
  int32_T c10_i12;
  real_T c10_A[3];
  int32_T c10_i13;
  real_T c10_x[3];
  int32_T c10_i14;
  real_T c10_b_x[3];
  int32_T c10_i15;
  real_T c10_c_x[3];
  int32_T c10_i16;
  int32_T c10_i17;
  real_T c10_b_A[3];
  int32_T c10_i18;
  real_T c10_d_x[3];
  int32_T c10_i19;
  real_T c10_e_x[3];
  int32_T c10_i20;
  real_T c10_f_x[3];
  int32_T c10_i21;
  int32_T c10_i22;
  int32_T c10_i23;
  real_T (*c10_b_B)[3];
  real_T (*c10_b_dB)[3];
  real_T (*c10_b_B_k)[3];
  real_T (*c10_b_B_l)[3];
  c10_b_dB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c10_b_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c10_b_B_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c10_b_B_l = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,8);
  for (c10_i6 = 0; c10_i6 < 3; c10_i6 = c10_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_b_B)[c10_i6], 0U);
  }

  for (c10_i7 = 0; c10_i7 < 3; c10_i7 = c10_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_b_B_l)[c10_i7], 1U);
  }

  for (c10_i8 = 0; c10_i8 < 3; c10_i8 = c10_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_b_B_k)[c10_i8], 2U);
  }

  for (c10_i9 = 0; c10_i9 < 3; c10_i9 = c10_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_b_dB)[c10_i9], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c10_s_FRAME_SIZE, 4U);
  c10_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,8);
  for (c10_i10 = 0; c10_i10 < 3; c10_i10 = c10_i10 + 1) {
    c10_B_l[c10_i10] = (*c10_b_B_l)[c10_i10];
  }

  for (c10_i11 = 0; c10_i11 < 3; c10_i11 = c10_i11 + 1) {
    c10_B_k[c10_i11] = (*c10_b_B_k)[c10_i11];
  }

  sf_debug_symbol_scope_push(7U, 0U);
  sf_debug_symbol_scope_add("nargout", &c10_nargout, c10_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c10_nargin, c10_b_sf_marshall);
  sf_debug_symbol_scope_add("s_FRAME_SIZE", &c10_c_s_FRAME_SIZE,
    c10_b_sf_marshall);
  sf_debug_symbol_scope_add("dB", &c10_dB, c10_sf_marshall);
  sf_debug_symbol_scope_add("B", &c10_B, c10_sf_marshall);
  sf_debug_symbol_scope_add("B_k", &c10_B_k, c10_sf_marshall);
  sf_debug_symbol_scope_add("B_l", &c10_B_l, c10_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c10_i12 = 0; c10_i12 < 3; c10_i12 = c10_i12 + 1) {
    c10_A[c10_i12] = c10_B_l[c10_i12] - c10_B_k[c10_i12];
  }

  for (c10_i13 = 0; c10_i13 < 3; c10_i13 = c10_i13 + 1) {
    c10_x[c10_i13] = c10_A[c10_i13];
  }

  for (c10_i14 = 0; c10_i14 < 3; c10_i14 = c10_i14 + 1) {
    c10_b_x[c10_i14] = c10_x[c10_i14];
  }

  for (c10_i15 = 0; c10_i15 < 3; c10_i15 = c10_i15 + 1) {
    c10_c_x[c10_i15] = c10_b_x[c10_i15];
  }

  for (c10_i16 = 0; c10_i16 < 3; c10_i16 = c10_i16 + 1) {
    c10_dB[c10_i16] = c10_c_x[c10_i16] / c10_b_s_FRAME_SIZE;
  }

  _SFD_EML_CALL(0,6);
  for (c10_i17 = 0; c10_i17 < 3; c10_i17 = c10_i17 + 1) {
    c10_b_A[c10_i17] = c10_B_l[c10_i17] + c10_B_k[c10_i17];
  }

  for (c10_i18 = 0; c10_i18 < 3; c10_i18 = c10_i18 + 1) {
    c10_d_x[c10_i18] = c10_b_A[c10_i18];
  }

  for (c10_i19 = 0; c10_i19 < 3; c10_i19 = c10_i19 + 1) {
    c10_e_x[c10_i19] = c10_d_x[c10_i19];
  }

  for (c10_i20 = 0; c10_i20 < 3; c10_i20 = c10_i20 + 1) {
    c10_f_x[c10_i20] = c10_e_x[c10_i20];
  }

  for (c10_i21 = 0; c10_i21 < 3; c10_i21 = c10_i21 + 1) {
    c10_B[c10_i21] = c10_f_x[c10_i21] / 2.0;
  }

  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  for (c10_i22 = 0; c10_i22 < 3; c10_i22 = c10_i22 + 1) {
    (*c10_b_B)[c10_i22] = c10_B[c10_i22];
  }

  for (c10_i23 = 0; c10_i23 < 3; c10_i23 = c10_i23 + 1) {
    (*c10_b_dB)[c10_i23] = c10_dB[c10_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
  _sfEvent_ = c10_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i24;
  real_T c10_b_u[3];
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  for (c10_i24 = 0; c10_i24 < 3; c10_i24 = c10_i24 + 1) {
    c10_b_u[c10_i24] = (*((real_T (*)[3])c10_u))[c10_i24];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_b_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  c10_b_u = *((real_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

const mxArray *sf_c10_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_ResolvedFunctionInfo c10_info[17];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i25;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17));
  for (c10_i25 = 0; c10_i25 < 17; c10_i25 = c10_i25 + 1) {
    c10_r0 = &c10_info[c10_i25];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context"
                    , "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name",
                    "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)),
                    "resolved", "nameCaptureInfo", c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c10_i25);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c10_i25);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[17])
{
  c10_info[0].context = "";
  c10_info[0].name = "minus";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved = "[B]minus";
  c10_info[0].fileLength = 0U;
  c10_info[0].fileTime1 = 0U;
  c10_info[0].fileTime2 = 0U;
  c10_info[1].context = "";
  c10_info[1].name = "mrdivide";
  c10_info[1].dominantType = "double";
  c10_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[1].fileLength = 800U;
  c10_info[1].fileTime1 = 1238421692U;
  c10_info[1].fileTime2 = 0U;
  c10_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[2].name = "nargin";
  c10_info[2].dominantType = "";
  c10_info[2].resolved = "[B]nargin";
  c10_info[2].fileLength = 0U;
  c10_info[2].fileTime1 = 0U;
  c10_info[2].fileTime2 = 0U;
  c10_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[3].name = "ge";
  c10_info[3].dominantType = "double";
  c10_info[3].resolved = "[B]ge";
  c10_info[3].fileLength = 0U;
  c10_info[3].fileTime1 = 0U;
  c10_info[3].fileTime2 = 0U;
  c10_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[4].name = "isscalar";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved = "[B]isscalar";
  c10_info[4].fileLength = 0U;
  c10_info[4].fileTime1 = 0U;
  c10_info[4].fileTime2 = 0U;
  c10_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[5].name = "rdivide";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[5].fileLength = 620U;
  c10_info[5].fileTime1 = 1213914166U;
  c10_info[5].fileTime2 = 0U;
  c10_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[6].name = "gt";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved = "[B]gt";
  c10_info[6].fileLength = 0U;
  c10_info[6].fileTime1 = 0U;
  c10_info[6].fileTime2 = 0U;
  c10_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[7].name = "isa";
  c10_info[7].dominantType = "double";
  c10_info[7].resolved = "[B]isa";
  c10_info[7].fileLength = 0U;
  c10_info[7].fileTime1 = 0U;
  c10_info[7].fileTime2 = 0U;
  c10_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[8].name = "isempty";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved = "[B]isempty";
  c10_info[8].fileLength = 0U;
  c10_info[8].fileTime1 = 0U;
  c10_info[8].fileTime2 = 0U;
  c10_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[9].name = "not";
  c10_info[9].dominantType = "logical";
  c10_info[9].resolved = "[B]not";
  c10_info[9].fileLength = 0U;
  c10_info[9].fileTime1 = 0U;
  c10_info[9].fileTime2 = 0U;
  c10_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[10].name = "strcmp";
  c10_info[10].dominantType = "char";
  c10_info[10].resolved = "[B]strcmp";
  c10_info[10].fileLength = 0U;
  c10_info[10].fileTime1 = 0U;
  c10_info[10].fileTime2 = 0U;
  c10_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[11].name = "eq";
  c10_info[11].dominantType = "double";
  c10_info[11].resolved = "[B]eq";
  c10_info[11].fileLength = 0U;
  c10_info[11].fileTime1 = 0U;
  c10_info[11].fileTime2 = 0U;
  c10_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[12].name = "eml_warning";
  c10_info[12].dominantType = "char";
  c10_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c10_info[12].fileLength = 262U;
  c10_info[12].fileTime1 = 1236241078U;
  c10_info[12].fileTime2 = 0U;
  c10_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[13].name = "eml_div";
  c10_info[13].dominantType = "double";
  c10_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[13].fileLength = 4269U;
  c10_info[13].fileTime1 = 1228077626U;
  c10_info[13].fileTime2 = 0U;
  c10_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[14].name = "isinteger";
  c10_info[14].dominantType = "double";
  c10_info[14].resolved = "[B]isinteger";
  c10_info[14].fileLength = 0U;
  c10_info[14].fileTime1 = 0U;
  c10_info[14].fileTime2 = 0U;
  c10_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c10_info[15].name = "isreal";
  c10_info[15].dominantType = "double";
  c10_info[15].resolved = "[B]isreal";
  c10_info[15].fileLength = 0U;
  c10_info[15].fileTime1 = 0U;
  c10_info[15].fileTime2 = 0U;
  c10_info[16].context = "";
  c10_info[16].name = "plus";
  c10_info[16].dominantType = "double";
  c10_info[16].resolved = "[B]plus";
  c10_info[16].fileLength = 0U;
  c10_info[16].fileTime1 = 0U;
  c10_info[16].fileTime2 = 0U;
}

static const mxArray *c10_c_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  boolean_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  c10_b_u = *((boolean_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c10_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1008783335U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1529668163U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1223407855U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1753105808U);
}

mxArray *sf_c10_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1696892486U);
    pr[1] = (double)(3281932529U);
    pr[2] = (double)(4258979837U);
    pr[3] = (double)(1164524302U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c10_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"B\",},{M[1],M[5],T\"dB\",},{M[8],M[0],T\"is_active_c10_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_adcs_v15_integral_PowerMachineNumber_,
           10,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_adcs_v15_integral_PowerMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_adcs_v15_integral_PowerMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"B",0,(MexFcnForType)c10_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"B_l",0,(MexFcnForType)c10_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"B_k",0,(MexFcnForType)c10_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"dB",0,(MexFcnForType)c10_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_FRAME_SIZE",0,(MexFcnForType)c10_b_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,181);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c10_B)[3];
          real_T (*c10_B_l)[3];
          real_T (*c10_B_k)[3];
          real_T (*c10_dB)[3];
          c10_dB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
          c10_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c10_B_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c10_B_l = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_B);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_B_l);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_B_k);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_dB);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance.c10_s_FRAME_SIZE);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c10_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c10_adcs_v15_integral_Power();
  initialize_c10_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c10_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c10_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c10_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c10_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c10_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c10_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c10_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c10_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c10_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c10_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c10_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c10_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c10_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c10_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c10_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     s_FRAME_SIZE
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for s_FRAME_SIZE*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",10,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",10,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",10,2);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1933536562U));
  ssSetChecksum1(S,(2503232675U));
  ssSetChecksum2(S,(2361959942U));
  ssSetChecksum3(S,(814093922U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c10_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c10_adcs_v15_integral_Power;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c10_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
