/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c24_adcs_v15_integral_Power.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c24_IN_NO_ACTIVE_CHILD         (0)
#define c24_b_tol_w                    (0.004)
#define c24_b_tolw_n2d                 (0.01)
#define c24_b_tol_q4                   (0.85)
#define c24_b_check_time               (10000.0)

/* Variable Declarations */

/* Variable Definitions */
static SFc24_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c24_adcs_v15_integral_Power(void);
static void initialize_params_c24_adcs_v15_integral_Power(void);
static void enable_c24_adcs_v15_integral_Power(void);
static void disable_c24_adcs_v15_integral_Power(void);
static void c24_update_debugger_state_c24_adcs_v15_integral_Power(void);
static void ext_mode_exec_c24_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c24_adcs_v15_integral_Power(void);
static void set_sim_state_c24_adcs_v15_integral_Power(const mxArray *c24_st);
static void finalize_c24_adcs_v15_integral_Power(void);
static void sf_c24_adcs_v15_integral_Power(void);
static void c24_c24_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber);
static void c24_eml_scalar_eg(void);
static real_T c24_ceval_xdot(int32_T c24_n, real_T c24_x[3], int32_T c24_ix0,
  int32_T c24_incx, real_T c24_y[3], int32_T c24_iy0, int32_T c24_incy);
static void c24_eml_error(void);
static const mxArray *c24_sf_marshall(void *c24_chartInstance, void *c24_u);
static const mxArray *c24_b_sf_marshall(void *c24_chartInstance, void *c24_u);
static const mxArray *c24_c_sf_marshall(void *c24_chartInstance, void *c24_u);
static const mxArray *c24_d_sf_marshall(void *c24_chartInstance, void *c24_u);
static void c24_info_helper(c24_ResolvedFunctionInfo c24_info[49]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c24_adcs_v15_integral_Power(void)
{
  uint8_T *c24_is_active_c24_adcs_v15_integral_Power;
  c24_is_active_c24_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c24_is_active_c24_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c24_adcs_v15_integral_Power(void)
{
  real_T c24_d0;
  real_T c24_d1;
  real_T c24_d2;
  real_T c24_d3;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'tol_w' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    2, 0), &c24_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c24_tol_w = c24_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'tolw_n2d' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    3, 0), &c24_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c24_tolw_n2d = c24_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'tol_q4' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c24_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c24_tol_q4 = c24_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'check_time' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c24_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c24_check_time = c24_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c24_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c24_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c24_update_debugger_state_c24_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c24_adcs_v15_integral_Power(void)
{
  c24_update_debugger_state_c24_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c24_adcs_v15_integral_Power(void)
{
  const mxArray *c24_st = NULL;
  const mxArray *c24_y = NULL;
  real_T c24_u;
  const mxArray *c24_b_y = NULL;
  int32_T c24_i0;
  real_T c24_b_u[3];
  const mxArray *c24_c_y = NULL;
  real_T c24_c_u;
  const mxArray *c24_d_y = NULL;
  uint8_T c24_d_u;
  const mxArray *c24_e_y = NULL;
  real_T *c24_N;
  real_T *c24_t_now;
  uint8_T *c24_is_active_c24_adcs_v15_integral_Power;
  real_T (*c24_P)[3];
  c24_t_now = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c24_is_active_c24_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c24_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c24_N = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellarray(4));
  c24_u = *c24_N;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c24_y, 0, c24_b_y);
  for (c24_i0 = 0; c24_i0 < 3; c24_i0 = c24_i0 + 1) {
    c24_b_u[c24_i0] = (*c24_P)[c24_i0];
  }

  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c24_y, 1, c24_c_y);
  c24_c_u = *c24_t_now;
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c24_y, 2, c24_d_y);
  c24_d_u = *c24_is_active_c24_adcs_v15_integral_Power;
  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", &c24_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c24_y, 3, c24_e_y);
  sf_mex_assign(&c24_st, c24_y);
  return c24_st;
}

static void set_sim_state_c24_adcs_v15_integral_Power(const mxArray *c24_st)
{
  const mxArray *c24_u;
  const mxArray *c24_N;
  real_T c24_d4;
  real_T c24_y;
  const mxArray *c24_P;
  real_T c24_dv0[3];
  int32_T c24_i1;
  real_T c24_b_y[3];
  int32_T c24_i2;
  const mxArray *c24_b_N;
  real_T c24_d5;
  real_T c24_c_y;
  const mxArray *c24_is_active_c24_adcs_v15_integral_Power;
  uint8_T c24_u0;
  uint8_T c24_d_y;
  boolean_T *c24_doneDoubleBufferReInit;
  real_T *c24_c_N;
  real_T *c24_t_now;
  uint8_T *c24_b_is_active_c24_adcs_v15_integral_Power;
  real_T (*c24_b_P)[3];
  c24_t_now = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c24_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c24_b_is_active_c24_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c24_b_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c24_c_N = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  *c24_doneDoubleBufferReInit = true;
  c24_u = sf_mex_dup(c24_st);
  c24_N = sf_mex_dup(sf_mex_getcell(c24_u, 0));
  sf_mex_import("N", sf_mex_dup(c24_N), &c24_d4, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d4;
  sf_mex_destroy(&c24_N);
  *c24_c_N = c24_y;
  c24_P = sf_mex_dup(sf_mex_getcell(c24_u, 1));
  sf_mex_import("P", sf_mex_dup(c24_P), &c24_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c24_i1 = 0; c24_i1 < 3; c24_i1 = c24_i1 + 1) {
    c24_b_y[c24_i1] = c24_dv0[c24_i1];
  }

  sf_mex_destroy(&c24_P);
  for (c24_i2 = 0; c24_i2 < 3; c24_i2 = c24_i2 + 1) {
    (*c24_b_P)[c24_i2] = c24_b_y[c24_i2];
  }

  c24_b_N = sf_mex_dup(sf_mex_getcell(c24_u, 2));
  sf_mex_import("t_now", sf_mex_dup(c24_b_N), &c24_d5, 1, 0, 0U, 0, 0U, 0);
  c24_c_y = c24_d5;
  sf_mex_destroy(&c24_b_N);
  *c24_t_now = c24_c_y;
  c24_is_active_c24_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c24_u, 3));
  sf_mex_import("is_active_c24_adcs_v15_integral_Power", sf_mex_dup
                (c24_is_active_c24_adcs_v15_integral_Power), &c24_u0, 1, 3, 0U,
                0,
                0U, 0);
  c24_d_y = c24_u0;
  sf_mex_destroy(&c24_is_active_c24_adcs_v15_integral_Power);
  *c24_b_is_active_c24_adcs_v15_integral_Power = c24_d_y;
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_adcs_v15_integral_Power();
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_adcs_v15_integral_Power(void)
{
}

static void sf_c24_adcs_v15_integral_Power(void)
{
  int32_T c24_i3;
  int32_T c24_i4;
  int32_T c24_i5;
  int32_T c24_previousEvent;
  real_T *c24_N_prev;
  real_T *c24_N;
  real_T *c24_t;
  real_T *c24_light_flag;
  real_T *c24_w_ctrl;
  real_T *c24_t_now;
  real_T *c24_t_now_prev;
  real_T (*c24_P)[3];
  real_T (*c24_q)[4];
  real_T (*c24_w)[3];
  c24_w = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c24_t_now = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c24_t_now_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c24_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c24_w_ctrl = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c24_N_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c24_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c24_light_flag = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c24_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
  c24_N = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,17);
  _SFD_DATA_RANGE_CHECK(*c24_N_prev, 0U);
  for (c24_i3 = 0; c24_i3 < 3; c24_i3 = c24_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c24_w)[c24_i3], 1U);
  }

  for (c24_i4 = 0; c24_i4 < 4; c24_i4 = c24_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c24_q)[c24_i4], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c24_tol_w, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c24_tolw_n2d, 4U);
  _SFD_DATA_RANGE_CHECK(*c24_N, 5U);
  for (c24_i5 = 0; c24_i5 < 3; c24_i5 = c24_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c24_P)[c24_i5], 6U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c24_tol_q4, 7U);
  _SFD_DATA_RANGE_CHECK(*c24_t, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c24_check_time, 9U);
  _SFD_DATA_RANGE_CHECK(*c24_light_flag, 10U);
  _SFD_DATA_RANGE_CHECK(*c24_w_ctrl, 11U);
  _SFD_DATA_RANGE_CHECK(*c24_t_now, 12U);
  _SFD_DATA_RANGE_CHECK(*c24_t_now_prev, 13U);
  c24_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c24_c24_adcs_v15_integral_Power();
  _sfEvent_ = c24_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c24_c24_adcs_v15_integral_Power(void)
{
  real_T c24_N_prev;
  int32_T c24_i6;
  real_T c24_w[3];
  int32_T c24_i7;
  real_T c24_q[4];
  real_T c24_t;
  real_T c24_light_flag;
  real_T c24_w_ctrl;
  real_T c24_t_now_prev;
  real_T c24_nargout = 3.0;
  real_T c24_nargin = 11.0;
  real_T c24_c_check_time = c24_b_check_time;
  real_T c24_c_tol_q4 = c24_b_tol_q4;
  real_T c24_c_tolw_n2d = c24_b_tolw_n2d;
  real_T c24_c_tol_w = c24_b_tol_w;
  boolean_T c24_switch_n2d;
  boolean_T c24_switch_d2n;
  real_T c24_modw;
  real_T c24_t_now;
  real_T c24_P[3];
  real_T c24_N;
  int32_T c24_i8;
  real_T c24_a[3];
  int32_T c24_i9;
  real_T c24_b[3];
  int32_T c24_i10;
  real_T c24_b_a[3];
  int32_T c24_i11;
  real_T c24_b_b[3];
  int32_T c24_i12;
  real_T c24_x[3];
  int32_T c24_i13;
  real_T c24_y[3];
  int32_T c24_i14;
  real_T c24_b_x[3];
  int32_T c24_i15;
  real_T c24_b_y[3];
  int32_T c24_i16;
  real_T c24_c_x[3];
  int32_T c24_i17;
  real_T c24_c_y[3];
  int32_T c24_i18;
  real_T c24_d_x[3];
  int32_T c24_i19;
  real_T c24_d_y[3];
  real_T c24_e_x;
  real_T c24_f_x;
  real_T c24_c_a;
  real_T c24_c_b;
  real_T c24_e_y;
  boolean_T c24_b0;
  real_T c24_d_a;
  real_T c24_d_b;
  real_T c24_f_y;
  boolean_T c24_e_b;
  real_T c24_g_y;
  boolean_T c24_f_b;
  real_T c24_h_y;
  real_T c24_g_x;
  real_T c24_h_x;
  real_T c24_i_y;
  boolean_T c24_g_b;
  real_T c24_j_y;
  int32_T c24_i20;
  real_T *c24_b_N_prev;
  real_T *c24_b_t;
  real_T *c24_b_light_flag;
  real_T *c24_b_w_ctrl;
  real_T *c24_b_t_now_prev;
  real_T *c24_b_N;
  real_T *c24_b_t_now;
  real_T (*c24_b_P)[3];
  real_T (*c24_b_q)[4];
  real_T (*c24_b_w)[3];
  c24_b_w = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c24_b_t_now = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c24_b_t_now_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c24_b_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c24_b_w_ctrl = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c24_b_N_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c24_b_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c24_b_light_flag = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c24_b_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
  c24_b_N = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,17);
  c24_N_prev = *c24_b_N_prev;
  for (c24_i6 = 0; c24_i6 < 3; c24_i6 = c24_i6 + 1) {
    c24_w[c24_i6] = (*c24_b_w)[c24_i6];
  }

  for (c24_i7 = 0; c24_i7 < 4; c24_i7 = c24_i7 + 1) {
    c24_q[c24_i7] = (*c24_b_q)[c24_i7];
  }

  c24_t = *c24_b_t;
  c24_light_flag = *c24_b_light_flag;
  c24_w_ctrl = *c24_b_w_ctrl;
  c24_t_now_prev = *c24_b_t_now_prev;
  sf_debug_symbol_scope_push(19U, 0U);
  sf_debug_symbol_scope_add("nargout", &c24_nargout, c24_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c24_nargin, c24_sf_marshall);
  sf_debug_symbol_scope_add("check_time", &c24_c_check_time, c24_sf_marshall);
  sf_debug_symbol_scope_add("tol_q4", &c24_c_tol_q4, c24_sf_marshall);
  sf_debug_symbol_scope_add("tolw_n2d", &c24_c_tolw_n2d, c24_sf_marshall);
  sf_debug_symbol_scope_add("tol_w", &c24_c_tol_w, c24_sf_marshall);
  sf_debug_symbol_scope_add("switch_n2d", &c24_switch_n2d, c24_d_sf_marshall);
  sf_debug_symbol_scope_add("switch_d2n", &c24_switch_d2n, c24_d_sf_marshall);
  sf_debug_symbol_scope_add("modw", &c24_modw, c24_sf_marshall);
  sf_debug_symbol_scope_add("t_now", &c24_t_now, c24_sf_marshall);
  sf_debug_symbol_scope_add("P", &c24_P, c24_b_sf_marshall);
  sf_debug_symbol_scope_add("N", &c24_N, c24_sf_marshall);
  sf_debug_symbol_scope_add("t_now_prev", &c24_t_now_prev, c24_sf_marshall);
  sf_debug_symbol_scope_add("w_ctrl", &c24_w_ctrl, c24_sf_marshall);
  sf_debug_symbol_scope_add("light_flag", &c24_light_flag, c24_sf_marshall);
  sf_debug_symbol_scope_add("t", &c24_t, c24_sf_marshall);
  sf_debug_symbol_scope_add("q", &c24_q, c24_c_sf_marshall);
  sf_debug_symbol_scope_add("w", &c24_w, c24_b_sf_marshall);
  sf_debug_symbol_scope_add("N_prev", &c24_N_prev, c24_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c24_i8 = 0; c24_i8 < 3; c24_i8 = c24_i8 + 1) {
    c24_a[c24_i8] = c24_w[c24_i8];
  }

  for (c24_i9 = 0; c24_i9 < 3; c24_i9 = c24_i9 + 1) {
    c24_b[c24_i9] = c24_w[c24_i9];
  }

  c24_eml_scalar_eg();
  for (c24_i10 = 0; c24_i10 < 3; c24_i10 = c24_i10 + 1) {
    c24_b_a[c24_i10] = c24_a[c24_i10];
  }

  for (c24_i11 = 0; c24_i11 < 3; c24_i11 = c24_i11 + 1) {
    c24_b_b[c24_i11] = c24_b[c24_i11];
  }

  for (c24_i12 = 0; c24_i12 < 3; c24_i12 = c24_i12 + 1) {
    c24_x[c24_i12] = c24_b_a[c24_i12];
  }

  for (c24_i13 = 0; c24_i13 < 3; c24_i13 = c24_i13 + 1) {
    c24_y[c24_i13] = c24_b_b[c24_i13];
  }

  for (c24_i14 = 0; c24_i14 < 3; c24_i14 = c24_i14 + 1) {
    c24_b_x[c24_i14] = c24_x[c24_i14];
  }

  for (c24_i15 = 0; c24_i15 < 3; c24_i15 = c24_i15 + 1) {
    c24_b_y[c24_i15] = c24_y[c24_i15];
  }

  for (c24_i16 = 0; c24_i16 < 3; c24_i16 = c24_i16 + 1) {
    c24_c_x[c24_i16] = c24_b_x[c24_i16];
  }

  for (c24_i17 = 0; c24_i17 < 3; c24_i17 = c24_i17 + 1) {
    c24_c_y[c24_i17] = c24_b_y[c24_i17];
  }

  for (c24_i18 = 0; c24_i18 < 3; c24_i18 = c24_i18 + 1) {
    c24_d_x[c24_i18] = c24_c_x[c24_i18];
  }

  for (c24_i19 = 0; c24_i19 < 3; c24_i19 = c24_i19 + 1) {
    c24_d_y[c24_i19] = c24_c_y[c24_i19];
  }

  c24_e_x = c24_ceval_xdot(3, c24_d_x, 1, 1, c24_d_y, 1, 1);
  c24_modw = c24_e_x;
  if (c24_modw < 0.0) {
    c24_eml_error();
  }

  c24_f_x = c24_modw;
  c24_modw = c24_f_x;
  c24_modw = muDoubleScalarSqrt(c24_modw);
  _SFD_EML_CALL(0,4);
  if (c24_modw < c24_b_tol_w) {
    c24_c_a = c24_light_flag;
    c24_c_b = c24_w_ctrl;
    c24_e_y = c24_c_a * c24_c_b;
    if (c24_e_y == 1.0) {
      c24_b0 = true;
      goto label_1;
    }
  }

  c24_b0 = false;
 label_1:
  ;
  c24_switch_d2n = c24_b0;
  _SFD_EML_CALL(0,5);
  c24_switch_n2d = (c24_modw > c24_b_tolw_n2d);

  /*  condition check - DEBUG purpose */
  _SFD_EML_CALL(0,8);
  c24_d_a = c24_light_flag;
  c24_d_b = c24_w_ctrl;
  c24_f_y = c24_d_a * c24_d_b;
  c24_e_b = (c24_f_y == 1.0);
  c24_g_y = (real_T)c24_e_b;
  c24_f_b = (c24_modw < c24_b_tol_w);
  c24_h_y = (real_T)c24_f_b;
  c24_g_x = c24_q[3];
  c24_h_x = c24_g_x;
  c24_i_y = muDoubleScalarAbs(c24_h_x);
  c24_g_b = (c24_i_y > c24_b_tol_q4);
  c24_j_y = (real_T)c24_g_b;
  c24_P[0] = c24_j_y + 0.1;
  c24_P[1] = c24_h_y;
  c24_P[2] = c24_g_y + 0.3;

  /* %%%%%%%%%% */
  _SFD_EML_CALL(0,13);
  c24_N = c24_N_prev;
  _SFD_EML_CALL(0,14);
  c24_t_now = c24_t_now_prev;
  _SFD_EML_CALL(0,16);
  if (CV_EML_IF(0, 0, c24_t < 2000.0)) {
    _SFD_EML_CALL(0,17);
    c24_N = 0.0;
    _SFD_EML_CALL(0,18);
    c24_t_now = 0.0;
  }

  _SFD_EML_CALL(0,21);
  if (CV_EML_COND(0, 0, (real_T)c24_switch_d2n == 1.0)) {
    if (CV_EML_COND(0, 1, c24_N_prev == 0.0)) {
      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 1, true);
      _SFD_EML_CALL(0,22);
      c24_N = 1.0;
      _SFD_EML_CALL(0,23);
      c24_t_now = c24_t;
      goto label_2;
    }
  }

  CV_EML_MCDC(0, 0, false);
  CV_EML_IF(0, 1, false);
 label_2:
  ;
  _SFD_EML_CALL(0,26);
  if (CV_EML_COND(0, 2, (real_T)c24_switch_n2d == 1.0)) {
    if (CV_EML_COND(0, 3, c24_N_prev == 1.0)) {
      if (CV_EML_COND(0, 4, c24_t > c24_t_now_prev + c24_b_check_time)) {
        CV_EML_MCDC(0, 1, true);
        CV_EML_IF(0, 2, true);
        _SFD_EML_CALL(0,27);
        c24_N = 0.0;
        _SFD_EML_CALL(0,28);
        c24_t_now = c24_t;
        goto label_3;
      } else {
        goto label_4;
      }
    }
  }

 label_4:
  ;
  CV_EML_MCDC(0, 1, false);
  CV_EML_IF(0, 2, false);
 label_3:
  ;
  _SFD_EML_CALL(0,-28);
  sf_debug_symbol_scope_pop();
  *c24_b_N = c24_N;
  for (c24_i20 = 0; c24_i20 < 3; c24_i20 = c24_i20 + 1) {
    (*c24_b_P)[c24_i20] = c24_P[c24_i20];
  }

  *c24_b_t_now = c24_t_now;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,17);
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber)
{
}

static void c24_eml_scalar_eg(void)
{
}

static real_T c24_ceval_xdot(int32_T c24_n, real_T c24_x[3], int32_T c24_ix0,
  int32_T c24_incx, real_T c24_y[3], int32_T c24_iy0,
  int32_T c24_incy)
{
  real_T c24_d;
  c24_d = 0.0;
  if ((real_T)c24_n > 0.0) {
    return ddot32(&c24_n, &c24_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c24_ix0), 1, 3, 1, 0) - 1]
                  , &c24_incx, &c24_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c24_iy0), 1, 3, 1, 0) - 1], &
                  c24_incy);
  }

  return c24_d;
}

static void c24_eml_error(void)
{
  int32_T c24_i21;
  static char_T c24_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c24_u[77];
  const mxArray *c24_y = NULL;
  int32_T c24_i22;
  static char_T c24_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c24_b_u[31];
  const mxArray *c24_b_y = NULL;
  for (c24_i21 = 0; c24_i21 < 77; c24_i21 = c24_i21 + 1) {
    c24_u[c24_i21] = c24_cv0[c24_i21];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c24_i22 = 0; c24_i22 < 31; c24_i22 = c24_i22 + 1) {
    c24_b_u[c24_i22] = c24_cv1[c24_i22];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c24_b_y, 14, c24_y);
}

static const mxArray *c24_sf_marshall(void *c24_chartInstance, void *c24_u)
{
  const mxArray *c24_y = NULL;
  real_T c24_b_u;
  const mxArray *c24_b_y = NULL;
  c24_y = NULL;
  c24_b_u = *((real_T *)c24_u);
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c24_y, c24_b_y);
  return c24_y;
}

static const mxArray *c24_b_sf_marshall(void *c24_chartInstance, void *c24_u)
{
  const mxArray *c24_y = NULL;
  int32_T c24_i23;
  real_T c24_b_u[3];
  const mxArray *c24_b_y = NULL;
  c24_y = NULL;
  for (c24_i23 = 0; c24_i23 < 3; c24_i23 = c24_i23 + 1) {
    c24_b_u[c24_i23] = (*((real_T (*)[3])c24_u))[c24_i23];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c24_y, c24_b_y);
  return c24_y;
}

static const mxArray *c24_c_sf_marshall(void *c24_chartInstance, void *c24_u)
{
  const mxArray *c24_y = NULL;
  int32_T c24_i24;
  real_T c24_b_u[4];
  const mxArray *c24_b_y = NULL;
  c24_y = NULL;
  for (c24_i24 = 0; c24_i24 < 4; c24_i24 = c24_i24 + 1) {
    c24_b_u[c24_i24] = (*((real_T (*)[4])c24_u))[c24_i24];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c24_y, c24_b_y);
  return c24_y;
}

static const mxArray *c24_d_sf_marshall(void *c24_chartInstance, void *c24_u)
{
  const mxArray *c24_y = NULL;
  boolean_T c24_b_u;
  const mxArray *c24_b_y = NULL;
  c24_y = NULL;
  c24_b_u = *((boolean_T *)c24_u);
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c24_y, c24_b_y);
  return c24_y;
}

const mxArray *sf_c24_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_ResolvedFunctionInfo c24_info[49];
  const mxArray *c24_m0 = NULL;
  int32_T c24_i25;
  c24_ResolvedFunctionInfo *c24_r0;
  c24_nameCaptureInfo = NULL;
  c24_info_helper(c24_info);
  sf_mex_assign(&c24_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for (c24_i25 = 0; c24_i25 < 49; c24_i25 = c24_i25 + 1) {
    c24_r0 = &c24_info[c24_i25];
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c24_r0->context)), "context"
                    , "nameCaptureInfo", c24_i25);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c24_r0->name)), "name",
                    "nameCaptureInfo", c24_i25);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      c24_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c24_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c24_i25);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c24_r0->resolved)),
                    "resolved", "nameCaptureInfo", c24_i25);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c24_i25);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c24_i25);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c24_i25);
  }

  sf_mex_assign(&c24_nameCaptureInfo, c24_m0);
  return c24_nameCaptureInfo;
}

static void c24_info_helper(c24_ResolvedFunctionInfo c24_info[49])
{
  c24_info[0].context = "";
  c24_info[0].name = "dot";
  c24_info[0].dominantType = "double";
  c24_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[0].fileLength = 2812U;
  c24_info[0].fileTime1 = 1236241088U;
  c24_info[0].fileTime2 = 0U;
  c24_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[1].name = "nargin";
  c24_info[1].dominantType = "";
  c24_info[1].resolved = "[B]nargin";
  c24_info[1].fileLength = 0U;
  c24_info[1].fileTime1 = 0U;
  c24_info[1].fileTime2 = 0U;
  c24_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[2].name = "gt";
  c24_info[2].dominantType = "double";
  c24_info[2].resolved = "[B]gt";
  c24_info[2].fileLength = 0U;
  c24_info[2].fileTime1 = 0U;
  c24_info[2].fileTime2 = 0U;
  c24_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[3].name = "isa";
  c24_info[3].dominantType = "double";
  c24_info[3].resolved = "[B]isa";
  c24_info[3].fileLength = 0U;
  c24_info[3].fileTime1 = 0U;
  c24_info[3].fileTime2 = 0U;
  c24_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[4].name = "size";
  c24_info[4].dominantType = "double";
  c24_info[4].resolved = "[B]size";
  c24_info[4].fileLength = 0U;
  c24_info[4].fileTime1 = 0U;
  c24_info[4].fileTime2 = 0U;
  c24_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[5].name = "isequal";
  c24_info[5].dominantType = "double";
  c24_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c24_info[5].fileLength = 180U;
  c24_info[5].fileTime1 = 1226561072U;
  c24_info[5].fileTime2 = 0U;
  c24_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c24_info[6].name = "false";
  c24_info[6].dominantType = "";
  c24_info[6].resolved = "[B]false";
  c24_info[6].fileLength = 0U;
  c24_info[6].fileTime1 = 0U;
  c24_info[6].fileTime2 = 0U;
  c24_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c24_info[7].name = "eml_isequal_core";
  c24_info[7].dominantType = "double";
  c24_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c24_info[7].fileLength = 3981U;
  c24_info[7].fileTime1 = 1236241072U;
  c24_info[7].fileTime2 = 0U;
  c24_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c24_info[8].name = "ge";
  c24_info[8].dominantType = "double";
  c24_info[8].resolved = "[B]ge";
  c24_info[8].fileLength = 0U;
  c24_info[8].fileTime1 = 0U;
  c24_info[8].fileTime2 = 0U;
  c24_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c24_info[9].name = "isscalar";
  c24_info[9].dominantType = "logical";
  c24_info[9].resolved = "[B]isscalar";
  c24_info[9].fileLength = 0U;
  c24_info[9].fileTime1 = 0U;
  c24_info[9].fileTime2 = 0U;
  c24_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c24_info[10].name = "islogical";
  c24_info[10].dominantType = "logical";
  c24_info[10].resolved = "[B]islogical";
  c24_info[10].fileLength = 0U;
  c24_info[10].fileTime1 = 0U;
  c24_info[10].fileTime2 = 0U;
  c24_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c24_info[11].name = "minus";
  c24_info[11].dominantType = "double";
  c24_info[11].resolved = "[B]minus";
  c24_info[11].fileLength = 0U;
  c24_info[11].fileTime1 = 0U;
  c24_info[11].fileTime2 = 0U;
  c24_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c24_info[12].name = "isnumeric";
  c24_info[12].dominantType = "double";
  c24_info[12].resolved = "[B]isnumeric";
  c24_info[12].fileLength = 0U;
  c24_info[12].fileTime1 = 0U;
  c24_info[12].fileTime2 = 0U;
  c24_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c24_info[13].name = "ndims";
  c24_info[13].dominantType = "double";
  c24_info[13].resolved = "[B]ndims";
  c24_info[13].fileLength = 0U;
  c24_info[13].fileTime1 = 0U;
  c24_info[13].fileTime2 = 0U;
  c24_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c24_info[14].name = "ne";
  c24_info[14].dominantType = "double";
  c24_info[14].resolved = "[B]ne";
  c24_info[14].fileLength = 0U;
  c24_info[14].fileTime1 = 0U;
  c24_info[14].fileTime2 = 0U;
  c24_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c24_info[15].name = "true";
  c24_info[15].dominantType = "";
  c24_info[15].resolved = "[B]true";
  c24_info[15].fileLength = 0U;
  c24_info[15].fileTime1 = 0U;
  c24_info[15].fileTime2 = 0U;
  c24_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c24_info[16].name = "isstruct";
  c24_info[16].dominantType = "double";
  c24_info[16].resolved = "[B]isstruct";
  c24_info[16].fileLength = 0U;
  c24_info[16].fileTime1 = 0U;
  c24_info[16].fileTime2 = 0U;
  c24_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c24_info[17].name = "eq";
  c24_info[17].dominantType = "logical";
  c24_info[17].resolved = "[B]eq";
  c24_info[17].fileLength = 0U;
  c24_info[17].fileTime1 = 0U;
  c24_info[17].fileTime2 = 0U;
  c24_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c24_info[18].name = "isempty";
  c24_info[18].dominantType = "double";
  c24_info[18].resolved = "[B]isempty";
  c24_info[18].fileLength = 0U;
  c24_info[18].fileTime1 = 0U;
  c24_info[18].fileTime2 = 0U;
  c24_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c24_info[19].name = "not";
  c24_info[19].dominantType = "logical";
  c24_info[19].resolved = "[B]not";
  c24_info[19].fileLength = 0U;
  c24_info[19].fileTime1 = 0U;
  c24_info[19].fileTime2 = 0U;
  c24_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c24_info[20].name = "isnan";
  c24_info[20].dominantType = "double";
  c24_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c24_info[20].fileLength = 506U;
  c24_info[20].fileTime1 = 1228077610U;
  c24_info[20].fileTime2 = 0U;
  c24_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c24_info[21].name = "isreal";
  c24_info[21].dominantType = "double";
  c24_info[21].resolved = "[B]isreal";
  c24_info[21].fileLength = 0U;
  c24_info[21].fileTime1 = 0U;
  c24_info[21].fileTime2 = 0U;
  c24_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[22].name = "eml_index_class";
  c24_info[22].dominantType = "";
  c24_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c24_info[22].fileLength = 909U;
  c24_info[22].fileTime1 = 1192454182U;
  c24_info[22].fileTime2 = 0U;
  c24_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[23].name = "ones";
  c24_info[23].dominantType = "char";
  c24_info[23].resolved = "[B]ones";
  c24_info[23].fileLength = 0U;
  c24_info[23].fileTime1 = 0U;
  c24_info[23].fileTime2 = 0U;
  c24_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[24].name = "isfloat";
  c24_info[24].dominantType = "double";
  c24_info[24].resolved = "[B]isfloat";
  c24_info[24].fileLength = 0U;
  c24_info[24].fileTime1 = 0U;
  c24_info[24].fileTime2 = 0U;
  c24_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[25].name = "eml_scalar_eg";
  c24_info[25].dominantType = "double";
  c24_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c24_info[25].fileLength = 3068U;
  c24_info[25].fileTime1 = 1240249410U;
  c24_info[25].fileTime2 = 0U;
  c24_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c24_info[26].name = "class";
  c24_info[26].dominantType = "double";
  c24_info[26].resolved = "[B]class";
  c24_info[26].fileLength = 0U;
  c24_info[26].fileTime1 = 0U;
  c24_info[26].fileTime2 = 0U;
  c24_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c24_info[27].name = "cast";
  c24_info[27].dominantType = "double";
  c24_info[27].resolved = "[B]cast";
  c24_info[27].fileLength = 0U;
  c24_info[27].fileTime1 = 0U;
  c24_info[27].fileTime2 = 0U;
  c24_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c24_info[28].name = "plus";
  c24_info[28].dominantType = "double";
  c24_info[28].resolved = "[B]plus";
  c24_info[28].fileLength = 0U;
  c24_info[28].fileTime1 = 0U;
  c24_info[28].fileTime2 = 0U;
  c24_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[29].name = "lt";
  c24_info[29].dominantType = "double";
  c24_info[29].resolved = "[B]lt";
  c24_info[29].fileLength = 0U;
  c24_info[29].fileTime1 = 0U;
  c24_info[29].fileTime2 = 0U;
  c24_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c24_info[30].name = "isvector";
  c24_info[30].dominantType = "double";
  c24_info[30].resolved = "[B]isvector";
  c24_info[30].fileLength = 0U;
  c24_info[30].fileTime1 = 0U;
  c24_info[30].fileTime2 = 0U;
  c24_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c24_info[31].name = "eml_xdotc";
  c24_info[31].dominantType = "int32";
  c24_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c24_info[31].fileLength = 1453U;
  c24_info[31].fileTime1 = 1209318250U;
  c24_info[31].fileTime2 = 0U;
  c24_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c24_info[32].name = "eml_xdot";
  c24_info[32].dominantType = "int32";
  c24_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c24_info[32].fileLength = 1330U;
  c24_info[32].fileTime1 = 1209318250U;
  c24_info[32].fileTime2 = 0U;
  c24_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c24_info[33].name = "strcmp";
  c24_info[33].dominantType = "char";
  c24_info[33].resolved = "[B]strcmp";
  c24_info[33].fileLength = 0U;
  c24_info[33].fileTime1 = 0U;
  c24_info[33].fileTime2 = 0U;
  c24_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c24_info[34].name = "eml_refblas_xdot";
  c24_info[34].dominantType = "int32";
  c24_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c24_info[34].fileLength = 343U;
  c24_info[34].fileTime1 = 1211203444U;
  c24_info[34].fileTime2 = 0U;
  c24_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c24_info[35].name = "eml_refblas_xdotx";
  c24_info[35].dominantType = "int32";
  c24_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[35].fileLength = 1605U;
  c24_info[35].fileTime1 = 1236241080U;
  c24_info[35].fileTime2 = 0U;
  c24_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[36].name = "ischar";
  c24_info[36].dominantType = "char";
  c24_info[36].resolved = "[B]ischar";
  c24_info[36].fileLength = 0U;
  c24_info[36].fileTime1 = 0U;
  c24_info[36].fileTime2 = 0U;
  c24_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[37].name = "times";
  c24_info[37].dominantType = "double";
  c24_info[37].resolved = "[B]times";
  c24_info[37].fileLength = 0U;
  c24_info[37].fileTime1 = 0U;
  c24_info[37].fileTime2 = 0U;
  c24_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[38].name = "uminus";
  c24_info[38].dominantType = "int32";
  c24_info[38].resolved = "[B]uminus";
  c24_info[38].fileLength = 0U;
  c24_info[38].fileTime1 = 0U;
  c24_info[38].fileTime2 = 0U;
  c24_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[39].name = "eml_index_minus";
  c24_info[39].dominantType = "int32";
  c24_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c24_info[39].fileLength = 277U;
  c24_info[39].fileTime1 = 1192454184U;
  c24_info[39].fileTime2 = 0U;
  c24_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[40].name = "eml_index_plus";
  c24_info[40].dominantType = "int32";
  c24_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c24_info[40].fileLength = 272U;
  c24_info[40].fileTime1 = 1192454186U;
  c24_info[40].fileTime2 = 0U;
  c24_info[41].context = "";
  c24_info[41].name = "sqrt";
  c24_info[41].dominantType = "double";
  c24_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c24_info[41].fileLength = 572U;
  c24_info[41].fileTime1 = 1203431846U;
  c24_info[41].fileTime2 = 0U;
  c24_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c24_info[42].name = "eml_error";
  c24_info[42].dominantType = "char";
  c24_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c24_info[42].fileLength = 315U;
  c24_info[42].fileTime1 = 1213914146U;
  c24_info[42].fileTime2 = 0U;
  c24_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c24_info[43].name = "eml_scalar_sqrt";
  c24_info[43].dominantType = "double";
  c24_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c24_info[43].fileLength = 664U;
  c24_info[43].fileTime1 = 1209318194U;
  c24_info[43].fileTime2 = 0U;
  c24_info[44].context = "";
  c24_info[44].name = "mtimes";
  c24_info[44].dominantType = "double";
  c24_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c24_info[44].fileLength = 3302U;
  c24_info[44].fileTime1 = 1242738294U;
  c24_info[44].fileTime2 = 0U;
  c24_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c24_info[45].name = "isinteger";
  c24_info[45].dominantType = "double";
  c24_info[45].resolved = "[B]isinteger";
  c24_info[45].fileLength = 0U;
  c24_info[45].fileTime1 = 0U;
  c24_info[45].fileTime2 = 0U;
  c24_info[46].context = "";
  c24_info[46].name = "abs";
  c24_info[46].dominantType = "double";
  c24_info[46].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c24_info[46].fileLength = 566U;
  c24_info[46].fileTime1 = 1221254534U;
  c24_info[46].fileTime2 = 0U;
  c24_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c24_info[47].name = "zeros";
  c24_info[47].dominantType = "double";
  c24_info[47].resolved = "[B]zeros";
  c24_info[47].fileLength = 0U;
  c24_info[47].fileTime1 = 0U;
  c24_info[47].fileTime2 = 0U;
  c24_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c24_info[48].name = "eml_scalar_abs";
  c24_info[48].dominantType = "double";
  c24_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c24_info[48].fileLength = 461U;
  c24_info[48].fileTime1 = 1203431760U;
  c24_info[48].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c24_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2353935783U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(940204465U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4127986158U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2539026543U);
}

mxArray *sf_c24_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(652561482U);
    pr[1] = (double)(3548214496U);
    pr[2] = (double)(3635758653U);
    pr[3] = (double)(666719373U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c24_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"N\",},{M[1],M[25],T\"P\",},{M[1],M[10],T\"t_now\",},{M[8],M[0],T\"is_active_c24_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           24,
           1,
           1,
           14,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"N_prev",
                              0,(MexFcnForType)c24_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w",0,(MexFcnForType)c24_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q",0,(MexFcnForType)c24_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tol_w",
                              0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(4,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "tolw_n2d",0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"N",0,
                              (MexFcnForType)c24_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"P",0,(MexFcnForType)c24_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(7,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tol_q4",
                              0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t",0,
                              (MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(9,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "check_time",0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "light_flag",0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"w_ctrl",
                              0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t_now",
                              0,(MexFcnForType)c24_sf_marshall);
          _SFD_SET_DATA_PROPS(13,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "t_now_prev",0,(MexFcnForType)c24_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,5,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,630);
        _SFD_CV_INIT_EML_IF(0,0,411,422,-1,452);
        _SFD_CV_INIT_EML_IF(0,1,454,493,-1,523);
        _SFD_CV_INIT_EML_IF(0,2,525,596,-1,628);

        {
          static int condStart[] = { 459, 480 };

          static int condEnd[] = { 474, 491 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,458,492,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 530, 551, 568 };

          static int condEnd[] = { 545, 562, 595 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,529,596,3,2,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c24_N_prev;
          real_T (*c24_w)[3];
          real_T (*c24_q)[4];
          real_T *c24_N;
          real_T (*c24_P)[3];
          real_T *c24_t;
          real_T *c24_light_flag;
          real_T *c24_w_ctrl;
          real_T *c24_t_now;
          real_T *c24_t_now_prev;
          c24_w = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c24_t_now = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c24_t_now_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
          c24_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c24_w_ctrl = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c24_N_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c24_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
          c24_light_flag = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c24_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
          c24_N = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c24_N_prev);
          _SFD_SET_DATA_VALUE_PTR(1U, c24_w);
          _SFD_SET_DATA_VALUE_PTR(2U, c24_q);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance.c24_tol_w);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance.c24_tolw_n2d);
          _SFD_SET_DATA_VALUE_PTR(5U, c24_N);
          _SFD_SET_DATA_VALUE_PTR(6U, c24_P);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance.c24_tol_q4);
          _SFD_SET_DATA_VALUE_PTR(8U, c24_t);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance.c24_check_time);
          _SFD_SET_DATA_VALUE_PTR(10U, c24_light_flag);
          _SFD_SET_DATA_VALUE_PTR(11U, c24_w_ctrl);
          _SFD_SET_DATA_VALUE_PTR(12U, c24_t_now);
          _SFD_SET_DATA_VALUE_PTR(13U, c24_t_now_prev);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c24_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c24_adcs_v15_integral_Power();
  initialize_c24_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c24_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c24_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c24_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c24_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c24_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c24_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c24_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c24_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c24_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c24_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c24_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c24_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c24_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c24_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c24_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c24_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     check_time tol_q4 tol_w tolw_n2d
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for check_time*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for tol_q4*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for tol_w*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for tolw_n2d*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",24,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",24,7);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",24,3);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(937897230U));
  ssSetChecksum1(S,(1297346424U));
  ssSetChecksum2(S,(3760568471U));
  ssSetChecksum3(S,(60982410U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c24_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",24);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c24_adcs_v15_integral_Power;
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

void c24_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
