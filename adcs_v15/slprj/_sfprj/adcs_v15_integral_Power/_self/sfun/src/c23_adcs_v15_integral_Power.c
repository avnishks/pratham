/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c23_adcs_v15_integral_Power.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c23_IN_NO_ACTIVE_CHILD         (0)
#define c23_b_s_MAG_B                  (2.5E-005)

/* Variable Declarations */

/* Variable Definitions */
static SFc23_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c23_adcs_v15_integral_Power(void);
static void initialize_params_c23_adcs_v15_integral_Power(void);
static void enable_c23_adcs_v15_integral_Power(void);
static void disable_c23_adcs_v15_integral_Power(void);
static void c23_update_debugger_state_c23_adcs_v15_integral_Power(void);
static void ext_mode_exec_c23_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c23_adcs_v15_integral_Power(void);
static void set_sim_state_c23_adcs_v15_integral_Power(const mxArray *c23_st);
static void finalize_c23_adcs_v15_integral_Power(void);
static void sf_c23_adcs_v15_integral_Power(void);
static void c23_c23_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static void c23_eml_scalar_eg(void);
static real_T c23_ceval_xdot(int32_T c23_n, real_T c23_x[3], int32_T c23_ix0,
  int32_T c23_incx, real_T c23_y[3], int32_T c23_iy0, int32_T c23_incy);
static void c23_eml_error(void);
static void c23_b_eml_scalar_eg(void);
static void c23_eml_warning(void);
static const mxArray *c23_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_b_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_c_sf_marshall(void *c23_chartInstance, void *c23_u);
static void c23_info_helper(c23_ResolvedFunctionInfo c23_info[59]);
static const mxArray *c23_d_sf_marshall(void *c23_chartInstance, void *c23_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c23_adcs_v15_integral_Power(void)
{
  uint8_T *c23_is_active_c23_adcs_v15_integral_Power;
  c23_is_active_c23_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c23_is_active_c23_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c23_adcs_v15_integral_Power(void)
{
  real_T c23_dv0[9];
  int32_T c23_i0;
  real_T c23_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Kdetumb' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c23_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c23_i0 = 0; c23_i0 < 9; c23_i0 = c23_i0 + 1) {
    chartInstance.c23_Kdetumb[c23_i0] = c23_dv0[c23_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_MAG_B' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c23_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c23_s_MAG_B = c23_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c23_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c23_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c23_update_debugger_state_c23_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c23_adcs_v15_integral_Power(void)
{
  c23_update_debugger_state_c23_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c23_adcs_v15_integral_Power(void)
{
  const mxArray *c23_st = NULL;
  const mxArray *c23_y = NULL;
  int32_T c23_i1;
  real_T c23_u[3];
  const mxArray *c23_b_y = NULL;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  uint8_T *c23_is_active_c23_adcs_v15_integral_Power;
  real_T (*c23_m_D)[3];
  c23_is_active_c23_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c23_m_D = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2));
  for (c23_i1 = 0; c23_i1 < 3; c23_i1 = c23_i1 + 1) {
    c23_u[c23_i1] = (*c23_m_D)[c23_i1];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_u = *c23_is_active_c23_adcs_v15_integral_Power;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y);
  return c23_st;
}

static void set_sim_state_c23_adcs_v15_integral_Power(const mxArray *c23_st)
{
  const mxArray *c23_u;
  const mxArray *c23_m_D;
  real_T c23_dv1[3];
  int32_T c23_i2;
  real_T c23_y[3];
  int32_T c23_i3;
  const mxArray *c23_is_active_c23_adcs_v15_integral_Power;
  uint8_T c23_u0;
  uint8_T c23_b_y;
  boolean_T *c23_doneDoubleBufferReInit;
  uint8_T *c23_b_is_active_c23_adcs_v15_integral_Power;
  real_T (*c23_b_m_D)[3];
  c23_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c23_b_is_active_c23_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c23_b_m_D = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  *c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  c23_m_D = sf_mex_dup(sf_mex_getcell(c23_u, 0));
  sf_mex_import("m_D", sf_mex_dup(c23_m_D), &c23_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c23_i2 = 0; c23_i2 < 3; c23_i2 = c23_i2 + 1) {
    c23_y[c23_i2] = c23_dv1[c23_i2];
  }

  sf_mex_destroy(&c23_m_D);
  for (c23_i3 = 0; c23_i3 < 3; c23_i3 = c23_i3 + 1) {
    (*c23_b_m_D)[c23_i3] = c23_y[c23_i3];
  }

  c23_is_active_c23_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c23_u, 1));
  sf_mex_import("is_active_c23_adcs_v15_integral_Power", sf_mex_dup
                (c23_is_active_c23_adcs_v15_integral_Power), &c23_u0, 1, 3, 0U,
                0,
                0U, 0);
  c23_b_y = c23_u0;
  sf_mex_destroy(&c23_is_active_c23_adcs_v15_integral_Power);
  *c23_b_is_active_c23_adcs_v15_integral_Power = c23_b_y;
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_adcs_v15_integral_Power();
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_adcs_v15_integral_Power(void)
{
}

static void sf_c23_adcs_v15_integral_Power(void)
{
  int32_T c23_i4;
  int32_T c23_i5;
  int32_T c23_i6;
  int32_T c23_i7;
  int32_T c23_previousEvent;
  real_T (*c23_m_D)[3];
  real_T (*c23_Bdot)[3];
  real_T (*c23_v_B)[3];
  c23_Bdot = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c23_m_D = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c23_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,16);
  for (c23_i4 = 0; c23_i4 < 3; c23_i4 = c23_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c23_v_B)[c23_i4], 0U);
  }

  for (c23_i5 = 0; c23_i5 < 3; c23_i5 = c23_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c23_Bdot)[c23_i5], 1U);
  }

  for (c23_i6 = 0; c23_i6 < 9; c23_i6 = c23_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c23_Kdetumb[c23_i6], 2U);
  }

  for (c23_i7 = 0; c23_i7 < 3; c23_i7 = c23_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c23_m_D)[c23_i7], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c23_s_MAG_B, 4U);
  c23_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c23_c23_adcs_v15_integral_Power();
  _sfEvent_ = c23_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c23_c23_adcs_v15_integral_Power(void)
{
  int32_T c23_i8;
  real_T c23_v_B[3];
  int32_T c23_i9;
  real_T c23_Bdot[3];
  real_T c23_nargout = 1.0;
  real_T c23_nargin = 4.0;
  real_T c23_c_s_MAG_B = c23_b_s_MAG_B;
  real_T c23_b_Kdetumb[9] = { 40000.0, 0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0,
    40000.0 };

  real_T c23_Bnorm;
  real_T c23_m_D[3];
  int32_T c23_i10;
  real_T c23_a[3];
  int32_T c23_i11;
  real_T c23_b[3];
  int32_T c23_i12;
  real_T c23_b_a[3];
  int32_T c23_i13;
  real_T c23_b_b[3];
  int32_T c23_i14;
  real_T c23_x[3];
  int32_T c23_i15;
  real_T c23_y[3];
  int32_T c23_i16;
  real_T c23_b_x[3];
  int32_T c23_i17;
  real_T c23_b_y[3];
  int32_T c23_i18;
  real_T c23_c_x[3];
  int32_T c23_i19;
  real_T c23_c_y[3];
  int32_T c23_i20;
  real_T c23_d_x[3];
  int32_T c23_i21;
  real_T c23_d_y[3];
  real_T c23_e_x;
  real_T c23_f_x;
  int32_T c23_i22;
  real_T c23_c_b[3];
  int32_T c23_i23;
  real_T c23_B[3];
  int32_T c23_i24;
  real_T c23_b_B[3];
  int32_T c23_i25;
  real_T c23_c_B[3];
  int32_T c23_i26;
  real_T c23_c_a[3];
  int32_T c23_i27;
  int32_T c23_i28;
  static real_T c23_dv2[9] = { -40000.0, 0.0, 0.0, 0.0, -40000.0, 0.0, 0.0, 0.0,
    -40000.0 };

  real_T c23_d_B;
  real_T c23_e_y;
  real_T c23_f_y;
  real_T c23_g_y;
  real_T c23_d_b;
  int32_T c23_i29;
  int32_T c23_i30;
  real_T (*c23_b_m_D)[3];
  real_T (*c23_b_Bdot)[3];
  real_T (*c23_b_v_B)[3];
  c23_b_Bdot = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c23_b_m_D = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c23_b_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,16);
  for (c23_i8 = 0; c23_i8 < 3; c23_i8 = c23_i8 + 1) {
    c23_v_B[c23_i8] = (*c23_b_v_B)[c23_i8];
  }

  for (c23_i9 = 0; c23_i9 < 3; c23_i9 = c23_i9 + 1) {
    c23_Bdot[c23_i9] = (*c23_b_Bdot)[c23_i9];
  }

  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("nargout", &c23_nargout, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c23_nargin, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("s_MAG_B", &c23_c_s_MAG_B, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("Kdetumb", &c23_b_Kdetumb, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("Bnorm", &c23_Bnorm, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("m_D", &c23_m_D, c23_sf_marshall);
  sf_debug_symbol_scope_add("Bdot", &c23_Bdot, c23_sf_marshall);
  sf_debug_symbol_scope_add("v_B", &c23_v_B, c23_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c23_i10 = 0; c23_i10 < 3; c23_i10 = c23_i10 + 1) {
    c23_a[c23_i10] = c23_v_B[c23_i10];
  }

  for (c23_i11 = 0; c23_i11 < 3; c23_i11 = c23_i11 + 1) {
    c23_b[c23_i11] = c23_v_B[c23_i11];
  }

  c23_eml_scalar_eg();
  for (c23_i12 = 0; c23_i12 < 3; c23_i12 = c23_i12 + 1) {
    c23_b_a[c23_i12] = c23_a[c23_i12];
  }

  for (c23_i13 = 0; c23_i13 < 3; c23_i13 = c23_i13 + 1) {
    c23_b_b[c23_i13] = c23_b[c23_i13];
  }

  for (c23_i14 = 0; c23_i14 < 3; c23_i14 = c23_i14 + 1) {
    c23_x[c23_i14] = c23_b_a[c23_i14];
  }

  for (c23_i15 = 0; c23_i15 < 3; c23_i15 = c23_i15 + 1) {
    c23_y[c23_i15] = c23_b_b[c23_i15];
  }

  for (c23_i16 = 0; c23_i16 < 3; c23_i16 = c23_i16 + 1) {
    c23_b_x[c23_i16] = c23_x[c23_i16];
  }

  for (c23_i17 = 0; c23_i17 < 3; c23_i17 = c23_i17 + 1) {
    c23_b_y[c23_i17] = c23_y[c23_i17];
  }

  for (c23_i18 = 0; c23_i18 < 3; c23_i18 = c23_i18 + 1) {
    c23_c_x[c23_i18] = c23_b_x[c23_i18];
  }

  for (c23_i19 = 0; c23_i19 < 3; c23_i19 = c23_i19 + 1) {
    c23_c_y[c23_i19] = c23_b_y[c23_i19];
  }

  for (c23_i20 = 0; c23_i20 < 3; c23_i20 = c23_i20 + 1) {
    c23_d_x[c23_i20] = c23_c_x[c23_i20];
  }

  for (c23_i21 = 0; c23_i21 < 3; c23_i21 = c23_i21 + 1) {
    c23_d_y[c23_i21] = c23_c_y[c23_i21];
  }

  c23_e_x = c23_ceval_xdot(3, c23_d_x, 1, 1, c23_d_y, 1, 1);
  c23_Bnorm = c23_e_x;
  if (c23_Bnorm < 0.0) {
    c23_eml_error();
  }

  c23_f_x = c23_Bnorm;
  c23_Bnorm = c23_f_x;
  c23_Bnorm = muDoubleScalarSqrt(c23_Bnorm);
  _SFD_EML_CALL(0,6);
  for (c23_i22 = 0; c23_i22 < 3; c23_i22 = c23_i22 + 1) {
    c23_c_b[c23_i22] = c23_Bdot[c23_i22];
  }

  c23_b_eml_scalar_eg();
  c23_b_eml_scalar_eg();
  for (c23_i23 = 0; c23_i23 < 3; c23_i23 = c23_i23 + 1) {
    c23_B[c23_i23] = c23_c_b[c23_i23];
  }

  for (c23_i24 = 0; c23_i24 < 3; c23_i24 = c23_i24 + 1) {
    c23_b_B[c23_i24] = c23_B[c23_i24];
  }

  for (c23_i25 = 0; c23_i25 < 3; c23_i25 = c23_i25 + 1) {
    c23_c_B[c23_i25] = c23_b_B[c23_i25];
  }

  for (c23_i26 = 0; c23_i26 < 3; c23_i26 = c23_i26 + 1) {
    c23_c_a[c23_i26] = 0.0;
    c23_i27 = 0;
    for (c23_i28 = 0; c23_i28 < 3; c23_i28 = c23_i28 + 1) {
      c23_c_a[c23_i26] = c23_c_a[c23_i26] + c23_dv2[c23_i27 + c23_i26] *
        c23_c_B[c23_i28];
      c23_i27 = c23_i27 + 3;
    }
  }

  c23_d_B = c23_Bnorm;
  c23_e_y = c23_d_B;
  if (c23_e_y == 0.0) {
    c23_eml_warning();
  }

  c23_f_y = c23_e_y;
  c23_g_y = c23_f_y;
  c23_d_b = 2.5E-005 / c23_g_y;
  for (c23_i29 = 0; c23_i29 < 3; c23_i29 = c23_i29 + 1) {
    c23_m_D[c23_i29] = c23_c_a[c23_i29] * c23_d_b;
  }

  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  for (c23_i30 = 0; c23_i30 < 3; c23_i30 = c23_i30 + 1) {
    (*c23_b_m_D)[c23_i30] = c23_m_D[c23_i30];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
}

static void c23_eml_scalar_eg(void)
{
}

static real_T c23_ceval_xdot(int32_T c23_n, real_T c23_x[3], int32_T c23_ix0,
  int32_T c23_incx, real_T c23_y[3], int32_T c23_iy0,
  int32_T c23_incy)
{
  real_T c23_d;
  c23_d = 0.0;
  if ((real_T)c23_n > 0.0) {
    return ddot32(&c23_n, &c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c23_ix0), 1, 3, 1, 0) - 1]
                  , &c23_incx, &c23_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c23_iy0), 1, 3, 1, 0) - 1], &
                  c23_incy);
  }

  return c23_d;
}

static void c23_eml_error(void)
{
  int32_T c23_i31;
  static char_T c23_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c23_u[77];
  const mxArray *c23_y = NULL;
  int32_T c23_i32;
  static char_T c23_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c23_b_u[31];
  const mxArray *c23_b_y = NULL;
  for (c23_i31 = 0; c23_i31 < 77; c23_i31 = c23_i31 + 1) {
    c23_u[c23_i31] = c23_cv0[c23_i31];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c23_i32 = 0; c23_i32 < 31; c23_i32 = c23_i32 + 1) {
    c23_b_u[c23_i32] = c23_cv1[c23_i32];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c23_b_y, 14, c23_y);
}

static void c23_b_eml_scalar_eg(void)
{
}

static void c23_eml_warning(void)
{
  int32_T c23_i33;
  static char_T c23_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c23_u[15];
  const mxArray *c23_y = NULL;
  int32_T c23_i34;
  static char_T c23_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c23_b_u[19];
  const mxArray *c23_b_y = NULL;
  for (c23_i33 = 0; c23_i33 < 15; c23_i33 = c23_i33 + 1) {
    c23_u[c23_i33] = c23_cv2[c23_i33];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c23_i34 = 0; c23_i34 < 19; c23_i34 = c23_i34 + 1) {
    c23_b_u[c23_i34] = c23_cv3[c23_i34];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c23_b_y, 14, c23_y);
}

static const mxArray *c23_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i35;
  real_T c23_b_u[3];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  for (c23_i35 = 0; c23_i35 < 3; c23_i35 = c23_i35 + 1) {
    c23_b_u[c23_i35] = (*((real_T (*)[3])c23_u))[c23_i35];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_b_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_b_u = *((real_T *)c23_u);
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_c_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i36;
  int32_T c23_i37;
  int32_T c23_i38;
  real_T c23_b_u[9];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_i36 = 0;
  for (c23_i37 = 0; c23_i37 < 3; c23_i37 = c23_i37 + 1) {
    for (c23_i38 = 0; c23_i38 < 3; c23_i38 = c23_i38 + 1) {
      c23_b_u[c23_i38 + c23_i36] = (*((real_T (*)[9])c23_u))[c23_i38 + c23_i36];
    }

    c23_i36 = c23_i36 + 3;
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

const mxArray *sf_c23_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_ResolvedFunctionInfo c23_info[59];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i39;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_info_helper(c23_info);
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 59));
  for (c23_i39 = 0; c23_i39 < 59; c23_i39 = c23_i39 + 1) {
    c23_r0 = &c23_info[c23_i39];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context"
                    , "nameCaptureInfo", c23_i39);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name",
                    "nameCaptureInfo", c23_i39);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i39);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)),
                    "resolved", "nameCaptureInfo", c23_i39);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c23_i39);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c23_i39);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c23_i39);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0);
  return c23_nameCaptureInfo;
}

static void c23_info_helper(c23_ResolvedFunctionInfo c23_info[59])
{
  c23_info[0].context = "";
  c23_info[0].name = "dot";
  c23_info[0].dominantType = "double";
  c23_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[0].fileLength = 2812U;
  c23_info[0].fileTime1 = 1236241088U;
  c23_info[0].fileTime2 = 0U;
  c23_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[1].name = "nargin";
  c23_info[1].dominantType = "";
  c23_info[1].resolved = "[B]nargin";
  c23_info[1].fileLength = 0U;
  c23_info[1].fileTime1 = 0U;
  c23_info[1].fileTime2 = 0U;
  c23_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[2].name = "gt";
  c23_info[2].dominantType = "double";
  c23_info[2].resolved = "[B]gt";
  c23_info[2].fileLength = 0U;
  c23_info[2].fileTime1 = 0U;
  c23_info[2].fileTime2 = 0U;
  c23_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[3].name = "isa";
  c23_info[3].dominantType = "double";
  c23_info[3].resolved = "[B]isa";
  c23_info[3].fileLength = 0U;
  c23_info[3].fileTime1 = 0U;
  c23_info[3].fileTime2 = 0U;
  c23_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[4].name = "size";
  c23_info[4].dominantType = "double";
  c23_info[4].resolved = "[B]size";
  c23_info[4].fileLength = 0U;
  c23_info[4].fileTime1 = 0U;
  c23_info[4].fileTime2 = 0U;
  c23_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[5].name = "isequal";
  c23_info[5].dominantType = "double";
  c23_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c23_info[5].fileLength = 180U;
  c23_info[5].fileTime1 = 1226561072U;
  c23_info[5].fileTime2 = 0U;
  c23_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c23_info[6].name = "false";
  c23_info[6].dominantType = "";
  c23_info[6].resolved = "[B]false";
  c23_info[6].fileLength = 0U;
  c23_info[6].fileTime1 = 0U;
  c23_info[6].fileTime2 = 0U;
  c23_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c23_info[7].name = "eml_isequal_core";
  c23_info[7].dominantType = "double";
  c23_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c23_info[7].fileLength = 3981U;
  c23_info[7].fileTime1 = 1236241072U;
  c23_info[7].fileTime2 = 0U;
  c23_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c23_info[8].name = "ge";
  c23_info[8].dominantType = "double";
  c23_info[8].resolved = "[B]ge";
  c23_info[8].fileLength = 0U;
  c23_info[8].fileTime1 = 0U;
  c23_info[8].fileTime2 = 0U;
  c23_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c23_info[9].name = "isscalar";
  c23_info[9].dominantType = "logical";
  c23_info[9].resolved = "[B]isscalar";
  c23_info[9].fileLength = 0U;
  c23_info[9].fileTime1 = 0U;
  c23_info[9].fileTime2 = 0U;
  c23_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c23_info[10].name = "islogical";
  c23_info[10].dominantType = "logical";
  c23_info[10].resolved = "[B]islogical";
  c23_info[10].fileLength = 0U;
  c23_info[10].fileTime1 = 0U;
  c23_info[10].fileTime2 = 0U;
  c23_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c23_info[11].name = "minus";
  c23_info[11].dominantType = "double";
  c23_info[11].resolved = "[B]minus";
  c23_info[11].fileLength = 0U;
  c23_info[11].fileTime1 = 0U;
  c23_info[11].fileTime2 = 0U;
  c23_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c23_info[12].name = "isnumeric";
  c23_info[12].dominantType = "double";
  c23_info[12].resolved = "[B]isnumeric";
  c23_info[12].fileLength = 0U;
  c23_info[12].fileTime1 = 0U;
  c23_info[12].fileTime2 = 0U;
  c23_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c23_info[13].name = "ndims";
  c23_info[13].dominantType = "double";
  c23_info[13].resolved = "[B]ndims";
  c23_info[13].fileLength = 0U;
  c23_info[13].fileTime1 = 0U;
  c23_info[13].fileTime2 = 0U;
  c23_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c23_info[14].name = "ne";
  c23_info[14].dominantType = "double";
  c23_info[14].resolved = "[B]ne";
  c23_info[14].fileLength = 0U;
  c23_info[14].fileTime1 = 0U;
  c23_info[14].fileTime2 = 0U;
  c23_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c23_info[15].name = "true";
  c23_info[15].dominantType = "";
  c23_info[15].resolved = "[B]true";
  c23_info[15].fileLength = 0U;
  c23_info[15].fileTime1 = 0U;
  c23_info[15].fileTime2 = 0U;
  c23_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c23_info[16].name = "isstruct";
  c23_info[16].dominantType = "double";
  c23_info[16].resolved = "[B]isstruct";
  c23_info[16].fileLength = 0U;
  c23_info[16].fileTime1 = 0U;
  c23_info[16].fileTime2 = 0U;
  c23_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c23_info[17].name = "eq";
  c23_info[17].dominantType = "logical";
  c23_info[17].resolved = "[B]eq";
  c23_info[17].fileLength = 0U;
  c23_info[17].fileTime1 = 0U;
  c23_info[17].fileTime2 = 0U;
  c23_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c23_info[18].name = "isempty";
  c23_info[18].dominantType = "double";
  c23_info[18].resolved = "[B]isempty";
  c23_info[18].fileLength = 0U;
  c23_info[18].fileTime1 = 0U;
  c23_info[18].fileTime2 = 0U;
  c23_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c23_info[19].name = "not";
  c23_info[19].dominantType = "logical";
  c23_info[19].resolved = "[B]not";
  c23_info[19].fileLength = 0U;
  c23_info[19].fileTime1 = 0U;
  c23_info[19].fileTime2 = 0U;
  c23_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c23_info[20].name = "isnan";
  c23_info[20].dominantType = "double";
  c23_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c23_info[20].fileLength = 506U;
  c23_info[20].fileTime1 = 1228077610U;
  c23_info[20].fileTime2 = 0U;
  c23_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c23_info[21].name = "isreal";
  c23_info[21].dominantType = "double";
  c23_info[21].resolved = "[B]isreal";
  c23_info[21].fileLength = 0U;
  c23_info[21].fileTime1 = 0U;
  c23_info[21].fileTime2 = 0U;
  c23_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[22].name = "eml_index_class";
  c23_info[22].dominantType = "";
  c23_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[22].fileLength = 909U;
  c23_info[22].fileTime1 = 1192454182U;
  c23_info[22].fileTime2 = 0U;
  c23_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[23].name = "ones";
  c23_info[23].dominantType = "char";
  c23_info[23].resolved = "[B]ones";
  c23_info[23].fileLength = 0U;
  c23_info[23].fileTime1 = 0U;
  c23_info[23].fileTime2 = 0U;
  c23_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[24].name = "isfloat";
  c23_info[24].dominantType = "double";
  c23_info[24].resolved = "[B]isfloat";
  c23_info[24].fileLength = 0U;
  c23_info[24].fileTime1 = 0U;
  c23_info[24].fileTime2 = 0U;
  c23_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[25].name = "eml_scalar_eg";
  c23_info[25].dominantType = "double";
  c23_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[25].fileLength = 3068U;
  c23_info[25].fileTime1 = 1240249410U;
  c23_info[25].fileTime2 = 0U;
  c23_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c23_info[26].name = "class";
  c23_info[26].dominantType = "double";
  c23_info[26].resolved = "[B]class";
  c23_info[26].fileLength = 0U;
  c23_info[26].fileTime1 = 0U;
  c23_info[26].fileTime2 = 0U;
  c23_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c23_info[27].name = "cast";
  c23_info[27].dominantType = "double";
  c23_info[27].resolved = "[B]cast";
  c23_info[27].fileLength = 0U;
  c23_info[27].fileTime1 = 0U;
  c23_info[27].fileTime2 = 0U;
  c23_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c23_info[28].name = "plus";
  c23_info[28].dominantType = "double";
  c23_info[28].resolved = "[B]plus";
  c23_info[28].fileLength = 0U;
  c23_info[28].fileTime1 = 0U;
  c23_info[28].fileTime2 = 0U;
  c23_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[29].name = "lt";
  c23_info[29].dominantType = "double";
  c23_info[29].resolved = "[B]lt";
  c23_info[29].fileLength = 0U;
  c23_info[29].fileTime1 = 0U;
  c23_info[29].fileTime2 = 0U;
  c23_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c23_info[30].name = "isvector";
  c23_info[30].dominantType = "double";
  c23_info[30].resolved = "[B]isvector";
  c23_info[30].fileLength = 0U;
  c23_info[30].fileTime1 = 0U;
  c23_info[30].fileTime2 = 0U;
  c23_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c23_info[31].name = "eml_xdotc";
  c23_info[31].dominantType = "int32";
  c23_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c23_info[31].fileLength = 1453U;
  c23_info[31].fileTime1 = 1209318250U;
  c23_info[31].fileTime2 = 0U;
  c23_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c23_info[32].name = "eml_xdot";
  c23_info[32].dominantType = "int32";
  c23_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c23_info[32].fileLength = 1330U;
  c23_info[32].fileTime1 = 1209318250U;
  c23_info[32].fileTime2 = 0U;
  c23_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c23_info[33].name = "strcmp";
  c23_info[33].dominantType = "char";
  c23_info[33].resolved = "[B]strcmp";
  c23_info[33].fileLength = 0U;
  c23_info[33].fileTime1 = 0U;
  c23_info[33].fileTime2 = 0U;
  c23_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c23_info[34].name = "eml_refblas_xdot";
  c23_info[34].dominantType = "int32";
  c23_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c23_info[34].fileLength = 343U;
  c23_info[34].fileTime1 = 1211203444U;
  c23_info[34].fileTime2 = 0U;
  c23_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c23_info[35].name = "eml_refblas_xdotx";
  c23_info[35].dominantType = "int32";
  c23_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[35].fileLength = 1605U;
  c23_info[35].fileTime1 = 1236241080U;
  c23_info[35].fileTime2 = 0U;
  c23_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[36].name = "ischar";
  c23_info[36].dominantType = "char";
  c23_info[36].resolved = "[B]ischar";
  c23_info[36].fileLength = 0U;
  c23_info[36].fileTime1 = 0U;
  c23_info[36].fileTime2 = 0U;
  c23_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[37].name = "times";
  c23_info[37].dominantType = "double";
  c23_info[37].resolved = "[B]times";
  c23_info[37].fileLength = 0U;
  c23_info[37].fileTime1 = 0U;
  c23_info[37].fileTime2 = 0U;
  c23_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[38].name = "uminus";
  c23_info[38].dominantType = "int32";
  c23_info[38].resolved = "[B]uminus";
  c23_info[38].fileLength = 0U;
  c23_info[38].fileTime1 = 0U;
  c23_info[38].fileTime2 = 0U;
  c23_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[39].name = "eml_index_minus";
  c23_info[39].dominantType = "int32";
  c23_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[39].fileLength = 277U;
  c23_info[39].fileTime1 = 1192454184U;
  c23_info[39].fileTime2 = 0U;
  c23_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c23_info[40].name = "eml_index_plus";
  c23_info[40].dominantType = "int32";
  c23_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[40].fileLength = 272U;
  c23_info[40].fileTime1 = 1192454186U;
  c23_info[40].fileTime2 = 0U;
  c23_info[41].context = "";
  c23_info[41].name = "sqrt";
  c23_info[41].dominantType = "double";
  c23_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[41].fileLength = 572U;
  c23_info[41].fileTime1 = 1203431846U;
  c23_info[41].fileTime2 = 0U;
  c23_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[42].name = "eml_error";
  c23_info[42].dominantType = "char";
  c23_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c23_info[42].fileLength = 315U;
  c23_info[42].fileTime1 = 1213914146U;
  c23_info[42].fileTime2 = 0U;
  c23_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c23_info[43].name = "eml_scalar_sqrt";
  c23_info[43].dominantType = "double";
  c23_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c23_info[43].fileLength = 664U;
  c23_info[43].fileTime1 = 1209318194U;
  c23_info[43].fileTime2 = 0U;
  c23_info[44].context = "";
  c23_info[44].name = "mtimes";
  c23_info[44].dominantType = "double";
  c23_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[44].fileLength = 3302U;
  c23_info[44].fileTime1 = 1242738294U;
  c23_info[44].fileTime2 = 0U;
  c23_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[45].name = "isinteger";
  c23_info[45].dominantType = "double";
  c23_info[45].resolved = "[B]isinteger";
  c23_info[45].fileLength = 0U;
  c23_info[45].fileTime1 = 0U;
  c23_info[45].fileTime2 = 0U;
  c23_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[46].name = "le";
  c23_info[46].dominantType = "double";
  c23_info[46].resolved = "[B]le";
  c23_info[46].fileLength = 0U;
  c23_info[46].fileTime1 = 0U;
  c23_info[46].fileTime2 = 0U;
  c23_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[47].name = "eml_xgemm";
  c23_info[47].dominantType = "int32";
  c23_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c23_info[47].fileLength = 3184U;
  c23_info[47].fileTime1 = 1209318252U;
  c23_info[47].fileTime2 = 0U;
  c23_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c23_info[48].name = "length";
  c23_info[48].dominantType = "double";
  c23_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c23_info[48].fileLength = 326U;
  c23_info[48].fileTime1 = 1226561076U;
  c23_info[48].fileTime2 = 0U;
  c23_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c23_info[49].name = "min";
  c23_info[49].dominantType = "double";
  c23_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[49].fileLength = 308U;
  c23_info[49].fileTime1 = 1192454034U;
  c23_info[49].fileTime2 = 0U;
  c23_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[50].name = "nargout";
  c23_info[50].dominantType = "";
  c23_info[50].resolved = "[B]nargout";
  c23_info[50].fileLength = 0U;
  c23_info[50].fileTime1 = 0U;
  c23_info[50].fileTime2 = 0U;
  c23_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[51].name = "eml_min_or_max";
  c23_info[51].dominantType = "char";
  c23_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c23_info[51].fileLength = 9969U;
  c23_info[51].fileTime1 = 1240249408U;
  c23_info[51].fileTime2 = 0U;
  c23_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c23_info[52].name = "eml_scalexp_alloc";
  c23_info[52].dominantType = "double";
  c23_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c23_info[52].fileLength = 808U;
  c23_info[52].fileTime1 = 1230478500U;
  c23_info[52].fileTime2 = 0U;
  c23_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c23_info[53].name = "eml_refblas_xgemm";
  c23_info[53].dominantType = "int32";
  c23_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c23_info[53].fileLength = 5748U;
  c23_info[53].fileTime1 = 1228077674U;
  c23_info[53].fileTime2 = 0U;
  c23_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c23_info[54].name = "eml_index_times";
  c23_info[54].dominantType = "int32";
  c23_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c23_info[54].fileLength = 280U;
  c23_info[54].fileTime1 = 1192454188U;
  c23_info[54].fileTime2 = 0U;
  c23_info[55].context = "";
  c23_info[55].name = "mrdivide";
  c23_info[55].dominantType = "double";
  c23_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[55].fileLength = 800U;
  c23_info[55].fileTime1 = 1238421692U;
  c23_info[55].fileTime2 = 0U;
  c23_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[56].name = "rdivide";
  c23_info[56].dominantType = "double";
  c23_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[56].fileLength = 620U;
  c23_info[56].fileTime1 = 1213914166U;
  c23_info[56].fileTime2 = 0U;
  c23_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[57].name = "eml_warning";
  c23_info[57].dominantType = "char";
  c23_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c23_info[57].fileLength = 262U;
  c23_info[57].fileTime1 = 1236241078U;
  c23_info[57].fileTime2 = 0U;
  c23_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[58].name = "eml_div";
  c23_info[58].dominantType = "double";
  c23_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c23_info[58].fileLength = 4269U;
  c23_info[58].fileTime1 = 1228077626U;
  c23_info[58].fileTime2 = 0U;
}

static const mxArray *c23_d_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  boolean_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_b_u = *((boolean_T *)c23_u);
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c23_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3764435002U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(840265561U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3931642U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1008475294U);
}

mxArray *sf_c23_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(5075336U);
    pr[1] = (double)(2989704660U);
    pr[2] = (double)(315041351U);
    pr[3] = (double)(3693402339U);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c23_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"m_D\",},{M[8],M[0],T\"is_active_c23_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           23,
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
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_B",0,(MexFcnForType)c23_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Bdot",0,(MexFcnForType)c23_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(2,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Kdetumb",0,(MexFcnForType)
                                c23_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_D",0,(MexFcnForType)c23_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_MAG_B",0,(MexFcnForType)c23_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,204);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c23_v_B)[3];
          real_T (*c23_Bdot)[3];
          real_T (*c23_m_D)[3];
          c23_Bdot = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c23_m_D = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c23_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c23_v_B);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_Bdot);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance.c23_Kdetumb);
          _SFD_SET_DATA_VALUE_PTR(3U, c23_m_D);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance.c23_s_MAG_B);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c23_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c23_adcs_v15_integral_Power();
  initialize_c23_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c23_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c23_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c23_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c23_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c23_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c23_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c23_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c23_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c23_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c23_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c23_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c23_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c23_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c23_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c23_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     Kdetumb s_MAG_B
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Kdetumb*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for s_MAG_B*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",23,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",23,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",23,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1987415611U));
  ssSetChecksum1(S,(2659255913U));
  ssSetChecksum2(S,(2973388373U));
  ssSetChecksum3(S,(1108629423U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",23);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c23_adcs_v15_integral_Power;
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

void c23_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
