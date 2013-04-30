/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun.h"
#include "c7_adcs_v15_integral_Power_nom_no_charge_in_detumb.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c7_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc7_adcs_v15_integral_Power_nom_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void initialize_params_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void);
static void enable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void disable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c7_update_debugger_state_c7_adcs_v15_integral_Power_nom_no_char(void);
static void ext_mode_exec_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void);
static const mxArray
  *get_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void set_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c7_st);
static void finalize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static void c7_eml_scalar_eg(void);
static real_T c7_ceval_xdot(int32_T c7_n, real_T c7_x[4], int32_T c7_ix0,
  int32_T c7_incx, real_T c7_y[4], int32_T c7_iy0, int32_T c7_incy);
static void c7_eml_error(void);
static void c7_eml_warning(void);
static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_c_sf_marshall(void *c7_chartInstance, void *c7_u);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[49]);
static const mxArray *c7_d_sf_marshall(void *c7_chartInstance, void *c7_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  uint8_T *c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb = 0U;
}

static void initialize_params_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
}

static void enable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c7_update_debugger_state_c7_adcs_v15_integral_Power_nom_no_char(void)
{
}

static void ext_mode_exec_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  c7_update_debugger_state_c7_adcs_v15_integral_Power_nom_no_char();
}

static const mxArray
  *get_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  const mxArray *c7_st = NULL;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[7];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  uint8_T *c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  real_T (*c7_xN)[7];
  c7_xN = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2));
  for (c7_i0 = 0; c7_i0 < 7; c7_i0 = c7_i0 + 1) {
    c7_u[c7_i0] = (*c7_xN)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_u = *c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y);
  return c7_st;
}

static void set_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c7_st)
{
  const mxArray *c7_u;
  const mxArray *c7_xN;
  real_T c7_dv0[7];
  int32_T c7_i1;
  real_T c7_y[7];
  int32_T c7_i2;
  const mxArray *c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  uint8_T c7_u0;
  uint8_T c7_b_y;
  boolean_T *c7_doneDoubleBufferReInit;
  uint8_T *c7_b_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detu;
  real_T (*c7_b_xN)[7];
  c7_b_xN = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c7_b_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detu = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c7_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_xN = sf_mex_dup(sf_mex_getcell(c7_u, 0));
  sf_mex_import("xN", sf_mex_dup(c7_xN), &c7_dv0, 1, 0, 0U, 1, 0U, 1, 7);
  for (c7_i1 = 0; c7_i1 < 7; c7_i1 = c7_i1 + 1) {
    c7_y[c7_i1] = c7_dv0[c7_i1];
  }

  sf_mex_destroy(&c7_xN);
  for (c7_i2 = 0; c7_i2 < 7; c7_i2 = c7_i2 + 1) {
    (*c7_b_xN)[c7_i2] = c7_y[c7_i2];
  }

  c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb = sf_mex_dup
    (sf_mex_getcell(c7_u, 1));
  sf_mex_import("is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb",
                sf_mex_dup(
    c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb), &c7_u0, 1,
                3, 0U, 0, 0U, 0);
  c7_b_y = c7_u0;
  sf_mex_destroy
    (&c7_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb);
  *c7_b_is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detu = c7_b_y;
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_adcs_v15_integral_Power_nom_no_char();
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
}

static void sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_previousEvent;
  int32_T c7_i5;
  real_T c7_x[7];
  real_T c7_nargout = 1.0;
  real_T c7_nargin = 1.0;
  real_T c7_q[4];
  real_T c7_xN[7];
  int32_T c7_i6;
  int32_T c7_i7;
  real_T c7_A[4];
  int32_T c7_i8;
  real_T c7_a[4];
  int32_T c7_i9;
  real_T c7_b[4];
  int32_T c7_i10;
  real_T c7_b_a[4];
  int32_T c7_i11;
  real_T c7_b_b[4];
  int32_T c7_i12;
  real_T c7_b_x[4];
  int32_T c7_i13;
  real_T c7_y[4];
  int32_T c7_i14;
  real_T c7_c_x[4];
  int32_T c7_i15;
  real_T c7_b_y[4];
  int32_T c7_i16;
  real_T c7_d_x[4];
  int32_T c7_i17;
  real_T c7_c_y[4];
  int32_T c7_i18;
  real_T c7_e_x[4];
  int32_T c7_i19;
  real_T c7_d_y[4];
  real_T c7_f_x;
  real_T c7_B;
  real_T c7_g_x;
  int32_T c7_i20;
  real_T c7_h_x[4];
  real_T c7_e_y;
  int32_T c7_i21;
  real_T c7_i_x[4];
  real_T c7_f_y;
  int32_T c7_i22;
  real_T c7_j_x[4];
  real_T c7_g_y;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  real_T (*c7_b_xN)[7];
  real_T (*c7_k_x)[7];
  c7_k_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c7_b_xN = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,5);
  for (c7_i3 = 0; c7_i3 < 7; c7_i3 = c7_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_k_x)[c7_i3], 0U);
  }

  for (c7_i4 = 0; c7_i4 < 7; c7_i4 = c7_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_b_xN)[c7_i4], 1U);
  }

  c7_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,5);
  for (c7_i5 = 0; c7_i5 < 7; c7_i5 = c7_i5 + 1) {
    c7_x[c7_i5] = (*c7_k_x)[c7_i5];
  }

  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c7_nargout, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c7_nargin, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("q", &c7_q, c7_b_sf_marshall);
  sf_debug_symbol_scope_add("xN", &c7_xN, c7_sf_marshall);
  sf_debug_symbol_scope_add("x", &c7_x, c7_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block gives DCM for converting from ECI to ORBIT frames */
  /*  inputs: state vector in ECI */
  /*  output: DCM */
  _SFD_EML_CALL(0,6);
  for (c7_i6 = 0; c7_i6 < 4; c7_i6 = c7_i6 + 1) {
    c7_q[c7_i6] = c7_x[c7_i6];
  }

  _SFD_EML_CALL(0,7);
  for (c7_i7 = 0; c7_i7 < 4; c7_i7 = c7_i7 + 1) {
    c7_A[c7_i7] = c7_q[c7_i7];
  }

  for (c7_i8 = 0; c7_i8 < 4; c7_i8 = c7_i8 + 1) {
    c7_a[c7_i8] = c7_q[c7_i8];
  }

  for (c7_i9 = 0; c7_i9 < 4; c7_i9 = c7_i9 + 1) {
    c7_b[c7_i9] = c7_q[c7_i9];
  }

  c7_eml_scalar_eg();
  for (c7_i10 = 0; c7_i10 < 4; c7_i10 = c7_i10 + 1) {
    c7_b_a[c7_i10] = c7_a[c7_i10];
  }

  for (c7_i11 = 0; c7_i11 < 4; c7_i11 = c7_i11 + 1) {
    c7_b_b[c7_i11] = c7_b[c7_i11];
  }

  for (c7_i12 = 0; c7_i12 < 4; c7_i12 = c7_i12 + 1) {
    c7_b_x[c7_i12] = c7_b_a[c7_i12];
  }

  for (c7_i13 = 0; c7_i13 < 4; c7_i13 = c7_i13 + 1) {
    c7_y[c7_i13] = c7_b_b[c7_i13];
  }

  for (c7_i14 = 0; c7_i14 < 4; c7_i14 = c7_i14 + 1) {
    c7_c_x[c7_i14] = c7_b_x[c7_i14];
  }

  for (c7_i15 = 0; c7_i15 < 4; c7_i15 = c7_i15 + 1) {
    c7_b_y[c7_i15] = c7_y[c7_i15];
  }

  for (c7_i16 = 0; c7_i16 < 4; c7_i16 = c7_i16 + 1) {
    c7_d_x[c7_i16] = c7_c_x[c7_i16];
  }

  for (c7_i17 = 0; c7_i17 < 4; c7_i17 = c7_i17 + 1) {
    c7_c_y[c7_i17] = c7_b_y[c7_i17];
  }

  for (c7_i18 = 0; c7_i18 < 4; c7_i18 = c7_i18 + 1) {
    c7_e_x[c7_i18] = c7_d_x[c7_i18];
  }

  for (c7_i19 = 0; c7_i19 < 4; c7_i19 = c7_i19 + 1) {
    c7_d_y[c7_i19] = c7_c_y[c7_i19];
  }

  c7_f_x = c7_ceval_xdot(4, c7_e_x, 1, 1, c7_d_y, 1, 1);
  c7_B = c7_f_x;
  if (c7_B < 0.0) {
    c7_eml_error();
  }

  c7_g_x = c7_B;
  c7_B = c7_g_x;
  c7_B = muDoubleScalarSqrt(c7_B);
  for (c7_i20 = 0; c7_i20 < 4; c7_i20 = c7_i20 + 1) {
    c7_h_x[c7_i20] = c7_A[c7_i20];
  }

  c7_e_y = c7_B;
  if (c7_e_y == 0.0) {
    c7_eml_warning();
  }

  for (c7_i21 = 0; c7_i21 < 4; c7_i21 = c7_i21 + 1) {
    c7_i_x[c7_i21] = c7_h_x[c7_i21];
  }

  c7_f_y = c7_e_y;
  for (c7_i22 = 0; c7_i22 < 4; c7_i22 = c7_i22 + 1) {
    c7_j_x[c7_i22] = c7_i_x[c7_i22];
  }

  c7_g_y = c7_f_y;
  for (c7_i23 = 0; c7_i23 < 4; c7_i23 = c7_i23 + 1) {
    c7_q[c7_i23] = c7_j_x[c7_i23] / c7_g_y;
  }

  _SFD_EML_CALL(0,8);
  for (c7_i24 = 0; c7_i24 < 4; c7_i24 = c7_i24 + 1) {
    c7_xN[c7_i24] = c7_q[c7_i24];
  }

  for (c7_i25 = 0; c7_i25 < 3; c7_i25 = c7_i25 + 1) {
    c7_xN[c7_i25 + 4] = c7_x[c7_i25 + 4];
  }

  _SFD_EML_CALL(0,-8);
  sf_debug_symbol_scope_pop();
  for (c7_i26 = 0; c7_i26 < 7; c7_i26 = c7_i26 + 1) {
    (*c7_b_xN)[c7_i26] = c7_xN[c7_i26];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
  _sfEvent_ = c7_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static void c7_eml_scalar_eg(void)
{
}

static real_T c7_ceval_xdot(int32_T c7_n, real_T c7_x[4], int32_T c7_ix0,
  int32_T c7_incx, real_T c7_y[4], int32_T c7_iy0, int32_T
  c7_incy)
{
  real_T c7_d;
  c7_d = 0.0;
  if ((real_T)c7_n > 0.0) {
    return ddot32(&c7_n, &c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c7_ix0), 1, 4, 1, 0) - 1], &
                  c7_incx, &c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c7_iy0), 1, 4, 1, 0) - 1], &c7_incy);
  }

  return c7_d;
}

static void c7_eml_error(void)
{
  int32_T c7_i27;
  static char_T c7_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c7_u[77];
  const mxArray *c7_y = NULL;
  int32_T c7_i28;
  static char_T c7_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c7_b_u[31];
  const mxArray *c7_b_y = NULL;
  for (c7_i27 = 0; c7_i27 < 77; c7_i27 = c7_i27 + 1) {
    c7_u[c7_i27] = c7_cv0[c7_i27];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c7_i28 = 0; c7_i28 < 31; c7_i28 = c7_i28 + 1) {
    c7_b_u[c7_i28] = c7_cv1[c7_i28];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c7_b_y, 14, c7_y);
}

static void c7_eml_warning(void)
{
  int32_T c7_i29;
  static char_T c7_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c7_u[15];
  const mxArray *c7_y = NULL;
  int32_T c7_i30;
  static char_T c7_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c7_b_u[19];
  const mxArray *c7_b_y = NULL;
  for (c7_i29 = 0; c7_i29 < 15; c7_i29 = c7_i29 + 1) {
    c7_u[c7_i29] = c7_cv2[c7_i29];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c7_i30 = 0; c7_i30 < 19; c7_i30 = c7_i30 + 1) {
    c7_b_u[c7_i30] = c7_cv3[c7_i30];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c7_b_y, 14, c7_y);
}

static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i31;
  real_T c7_b_u[7];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for (c7_i31 = 0; c7_i31 < 7; c7_i31 = c7_i31 + 1) {
    c7_b_u[c7_i31] = (*((real_T (*)[7])c7_u))[c7_i31];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i32;
  real_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for (c7_i32 = 0; c7_i32 < 4; c7_i32 = c7_i32 + 1) {
    c7_b_u[c7_i32] = (*((real_T (*)[4])c7_u))[c7_i32];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_c_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((real_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

const mxArray
  *sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_ResolvedFunctionInfo c7_info[49];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i33;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for (c7_i33 = 0; c7_i33 < 49; c7_i33 = c7_i33 + 1) {
    c7_r0 = &c7_info[c7_i33];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context",
                    "nameCaptureInfo", c7_i33);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name",
                    "nameCaptureInfo", c7_i33);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c7_i33);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c7_i33);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c7_i33);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c7_i33
                    );
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c7_i33
                    );
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[49])
{
  c7_info[0].context = "";
  c7_info[0].name = "dot";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[0].fileLength = 2812U;
  c7_info[0].fileTime1 = 1236241088U;
  c7_info[0].fileTime2 = 0U;
  c7_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[1].name = "nargin";
  c7_info[1].dominantType = "";
  c7_info[1].resolved = "[B]nargin";
  c7_info[1].fileLength = 0U;
  c7_info[1].fileTime1 = 0U;
  c7_info[1].fileTime2 = 0U;
  c7_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[2].name = "gt";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved = "[B]gt";
  c7_info[2].fileLength = 0U;
  c7_info[2].fileTime1 = 0U;
  c7_info[2].fileTime2 = 0U;
  c7_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[3].name = "isa";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[B]isa";
  c7_info[3].fileLength = 0U;
  c7_info[3].fileTime1 = 0U;
  c7_info[3].fileTime2 = 0U;
  c7_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[4].name = "size";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved = "[B]size";
  c7_info[4].fileLength = 0U;
  c7_info[4].fileTime1 = 0U;
  c7_info[4].fileTime2 = 0U;
  c7_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[5].name = "isequal";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[5].fileLength = 180U;
  c7_info[5].fileTime1 = 1226561072U;
  c7_info[5].fileTime2 = 0U;
  c7_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[6].name = "false";
  c7_info[6].dominantType = "";
  c7_info[6].resolved = "[B]false";
  c7_info[6].fileLength = 0U;
  c7_info[6].fileTime1 = 0U;
  c7_info[6].fileTime2 = 0U;
  c7_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[7].name = "eml_isequal_core";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[7].fileLength = 3981U;
  c7_info[7].fileTime1 = 1236241072U;
  c7_info[7].fileTime2 = 0U;
  c7_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[8].name = "ge";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved = "[B]ge";
  c7_info[8].fileLength = 0U;
  c7_info[8].fileTime1 = 0U;
  c7_info[8].fileTime2 = 0U;
  c7_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[9].name = "isscalar";
  c7_info[9].dominantType = "logical";
  c7_info[9].resolved = "[B]isscalar";
  c7_info[9].fileLength = 0U;
  c7_info[9].fileTime1 = 0U;
  c7_info[9].fileTime2 = 0U;
  c7_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[10].name = "islogical";
  c7_info[10].dominantType = "logical";
  c7_info[10].resolved = "[B]islogical";
  c7_info[10].fileLength = 0U;
  c7_info[10].fileTime1 = 0U;
  c7_info[10].fileTime2 = 0U;
  c7_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[11].name = "minus";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved = "[B]minus";
  c7_info[11].fileLength = 0U;
  c7_info[11].fileTime1 = 0U;
  c7_info[11].fileTime2 = 0U;
  c7_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[12].name = "isnumeric";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved = "[B]isnumeric";
  c7_info[12].fileLength = 0U;
  c7_info[12].fileTime1 = 0U;
  c7_info[12].fileTime2 = 0U;
  c7_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c7_info[13].name = "ndims";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved = "[B]ndims";
  c7_info[13].fileLength = 0U;
  c7_info[13].fileTime1 = 0U;
  c7_info[13].fileTime2 = 0U;
  c7_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c7_info[14].name = "ne";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved = "[B]ne";
  c7_info[14].fileLength = 0U;
  c7_info[14].fileTime1 = 0U;
  c7_info[14].fileTime2 = 0U;
  c7_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c7_info[15].name = "true";
  c7_info[15].dominantType = "";
  c7_info[15].resolved = "[B]true";
  c7_info[15].fileLength = 0U;
  c7_info[15].fileTime1 = 0U;
  c7_info[15].fileTime2 = 0U;
  c7_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c7_info[16].name = "isstruct";
  c7_info[16].dominantType = "double";
  c7_info[16].resolved = "[B]isstruct";
  c7_info[16].fileLength = 0U;
  c7_info[16].fileTime1 = 0U;
  c7_info[16].fileTime2 = 0U;
  c7_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c7_info[17].name = "eq";
  c7_info[17].dominantType = "logical";
  c7_info[17].resolved = "[B]eq";
  c7_info[17].fileLength = 0U;
  c7_info[17].fileTime1 = 0U;
  c7_info[17].fileTime2 = 0U;
  c7_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c7_info[18].name = "isempty";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved = "[B]isempty";
  c7_info[18].fileLength = 0U;
  c7_info[18].fileTime1 = 0U;
  c7_info[18].fileTime2 = 0U;
  c7_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c7_info[19].name = "not";
  c7_info[19].dominantType = "logical";
  c7_info[19].resolved = "[B]not";
  c7_info[19].fileLength = 0U;
  c7_info[19].fileTime1 = 0U;
  c7_info[19].fileTime2 = 0U;
  c7_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c7_info[20].name = "isnan";
  c7_info[20].dominantType = "double";
  c7_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c7_info[20].fileLength = 506U;
  c7_info[20].fileTime1 = 1228077610U;
  c7_info[20].fileTime2 = 0U;
  c7_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c7_info[21].name = "isreal";
  c7_info[21].dominantType = "double";
  c7_info[21].resolved = "[B]isreal";
  c7_info[21].fileLength = 0U;
  c7_info[21].fileTime1 = 0U;
  c7_info[21].fileTime2 = 0U;
  c7_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[22].name = "eml_index_class";
  c7_info[22].dominantType = "";
  c7_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[22].fileLength = 909U;
  c7_info[22].fileTime1 = 1192454182U;
  c7_info[22].fileTime2 = 0U;
  c7_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[23].name = "ones";
  c7_info[23].dominantType = "char";
  c7_info[23].resolved = "[B]ones";
  c7_info[23].fileLength = 0U;
  c7_info[23].fileTime1 = 0U;
  c7_info[23].fileTime2 = 0U;
  c7_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[24].name = "isfloat";
  c7_info[24].dominantType = "double";
  c7_info[24].resolved = "[B]isfloat";
  c7_info[24].fileLength = 0U;
  c7_info[24].fileTime1 = 0U;
  c7_info[24].fileTime2 = 0U;
  c7_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[25].name = "eml_scalar_eg";
  c7_info[25].dominantType = "double";
  c7_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[25].fileLength = 3068U;
  c7_info[25].fileTime1 = 1240249410U;
  c7_info[25].fileTime2 = 0U;
  c7_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c7_info[26].name = "class";
  c7_info[26].dominantType = "double";
  c7_info[26].resolved = "[B]class";
  c7_info[26].fileLength = 0U;
  c7_info[26].fileTime1 = 0U;
  c7_info[26].fileTime2 = 0U;
  c7_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c7_info[27].name = "cast";
  c7_info[27].dominantType = "double";
  c7_info[27].resolved = "[B]cast";
  c7_info[27].fileLength = 0U;
  c7_info[27].fileTime1 = 0U;
  c7_info[27].fileTime2 = 0U;
  c7_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c7_info[28].name = "plus";
  c7_info[28].dominantType = "double";
  c7_info[28].resolved = "[B]plus";
  c7_info[28].fileLength = 0U;
  c7_info[28].fileTime1 = 0U;
  c7_info[28].fileTime2 = 0U;
  c7_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[29].name = "lt";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved = "[B]lt";
  c7_info[29].fileLength = 0U;
  c7_info[29].fileTime1 = 0U;
  c7_info[29].fileTime2 = 0U;
  c7_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c7_info[30].name = "isvector";
  c7_info[30].dominantType = "double";
  c7_info[30].resolved = "[B]isvector";
  c7_info[30].fileLength = 0U;
  c7_info[30].fileTime1 = 0U;
  c7_info[30].fileTime2 = 0U;
  c7_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c7_info[31].name = "eml_xdotc";
  c7_info[31].dominantType = "int32";
  c7_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c7_info[31].fileLength = 1453U;
  c7_info[31].fileTime1 = 1209318250U;
  c7_info[31].fileTime2 = 0U;
  c7_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c7_info[32].name = "eml_xdot";
  c7_info[32].dominantType = "int32";
  c7_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c7_info[32].fileLength = 1330U;
  c7_info[32].fileTime1 = 1209318250U;
  c7_info[32].fileTime2 = 0U;
  c7_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c7_info[33].name = "strcmp";
  c7_info[33].dominantType = "char";
  c7_info[33].resolved = "[B]strcmp";
  c7_info[33].fileLength = 0U;
  c7_info[33].fileTime1 = 0U;
  c7_info[33].fileTime2 = 0U;
  c7_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c7_info[34].name = "eml_refblas_xdot";
  c7_info[34].dominantType = "int32";
  c7_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c7_info[34].fileLength = 343U;
  c7_info[34].fileTime1 = 1211203444U;
  c7_info[34].fileTime2 = 0U;
  c7_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c7_info[35].name = "eml_refblas_xdotx";
  c7_info[35].dominantType = "int32";
  c7_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[35].fileLength = 1605U;
  c7_info[35].fileTime1 = 1236241080U;
  c7_info[35].fileTime2 = 0U;
  c7_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[36].name = "ischar";
  c7_info[36].dominantType = "char";
  c7_info[36].resolved = "[B]ischar";
  c7_info[36].fileLength = 0U;
  c7_info[36].fileTime1 = 0U;
  c7_info[36].fileTime2 = 0U;
  c7_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[37].name = "times";
  c7_info[37].dominantType = "double";
  c7_info[37].resolved = "[B]times";
  c7_info[37].fileLength = 0U;
  c7_info[37].fileTime1 = 0U;
  c7_info[37].fileTime2 = 0U;
  c7_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[38].name = "uminus";
  c7_info[38].dominantType = "int32";
  c7_info[38].resolved = "[B]uminus";
  c7_info[38].fileLength = 0U;
  c7_info[38].fileTime1 = 0U;
  c7_info[38].fileTime2 = 0U;
  c7_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[39].name = "eml_index_minus";
  c7_info[39].dominantType = "int32";
  c7_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[39].fileLength = 277U;
  c7_info[39].fileTime1 = 1192454184U;
  c7_info[39].fileTime2 = 0U;
  c7_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[40].name = "eml_index_plus";
  c7_info[40].dominantType = "int32";
  c7_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[40].fileLength = 272U;
  c7_info[40].fileTime1 = 1192454186U;
  c7_info[40].fileTime2 = 0U;
  c7_info[41].context = "";
  c7_info[41].name = "sqrt";
  c7_info[41].dominantType = "double";
  c7_info[41].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[41].fileLength = 572U;
  c7_info[41].fileTime1 = 1203431846U;
  c7_info[41].fileTime2 = 0U;
  c7_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[42].name = "eml_error";
  c7_info[42].dominantType = "char";
  c7_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[42].fileLength = 315U;
  c7_info[42].fileTime1 = 1213914146U;
  c7_info[42].fileTime2 = 0U;
  c7_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[43].name = "eml_scalar_sqrt";
  c7_info[43].dominantType = "double";
  c7_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c7_info[43].fileLength = 664U;
  c7_info[43].fileTime1 = 1209318194U;
  c7_info[43].fileTime2 = 0U;
  c7_info[44].context = "";
  c7_info[44].name = "mrdivide";
  c7_info[44].dominantType = "double";
  c7_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[44].fileLength = 800U;
  c7_info[44].fileTime1 = 1238421692U;
  c7_info[44].fileTime2 = 0U;
  c7_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[45].name = "rdivide";
  c7_info[45].dominantType = "double";
  c7_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[45].fileLength = 620U;
  c7_info[45].fileTime1 = 1213914166U;
  c7_info[45].fileTime2 = 0U;
  c7_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[46].name = "eml_warning";
  c7_info[46].dominantType = "char";
  c7_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c7_info[46].fileLength = 262U;
  c7_info[46].fileTime1 = 1236241078U;
  c7_info[46].fileTime2 = 0U;
  c7_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[47].name = "eml_div";
  c7_info[47].dominantType = "double";
  c7_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[47].fileLength = 4269U;
  c7_info[47].fileTime1 = 1228077626U;
  c7_info[47].fileTime2 = 0U;
  c7_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[48].name = "isinteger";
  c7_info[48].dominantType = "double";
  c7_info[48].resolved = "[B]isinteger";
  c7_info[48].fileLength = 0U;
  c7_info[48].fileTime1 = 0U;
  c7_info[48].fileTime2 = 0U;
}

static const mxArray *c7_d_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  boolean_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((boolean_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1258247369U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1987909585U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1514654565U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1666986650U);
}

mxArray
  *sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2850577013U);
    pr[1] = (double)(2446799496U);
    pr[2] = (double)(2808134508U);
    pr[3] = (double)(98542371U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"xN\",},{M[8],M[0],T\"is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
    (&mxChecksum);
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
          (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
           7,
           1,
           1,
           2,
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
          init_script_number_translation
            (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x",0,(MexFcnForType)c7_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"xN",0,(MexFcnForType)c7_sf_marshall);
          }

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
          real_T (*c7_x)[7];
          real_T (*c7_xN)[7];
          c7_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
          c7_xN = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_xN);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void
  sf_opaque_initialize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  initialize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_enable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_disable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  disable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_gateway_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  sf_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  ext_mode_exec_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(sf_mex_dup(st));
}

static void
  sf_opaque_terminate_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",7,1);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",7,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom_no_charge_in_detumb",
                          "adcs_v15_integral_Power_nom_no_charge_in_detumb",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3765657755U));
  ssSetChecksum1(S,(3892594898U));
  ssSetChecksum2(S,(2218658498U));
  ssSetChecksum3(S,(3604933180U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(SimStruct *
  S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb;
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

void c7_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
