/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c13_adcs_v15_integral_Power.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c13_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc13_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c13_adcs_v15_integral_Power(void);
static void initialize_params_c13_adcs_v15_integral_Power(void);
static void enable_c13_adcs_v15_integral_Power(void);
static void disable_c13_adcs_v15_integral_Power(void);
static void c13_update_debugger_state_c13_adcs_v15_integral_Power(void);
static void ext_mode_exec_c13_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c13_adcs_v15_integral_Power(void);
static void set_sim_state_c13_adcs_v15_integral_Power(const mxArray *c13_st);
static void finalize_c13_adcs_v15_integral_Power(void);
static void sf_c13_adcs_v15_integral_Power(void);
static void c13_c13_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static real_T c13_dot(real_T c13_c_a[3], real_T c13_b[3]);
static void c13_eml_scalar_eg(void);
static real_T c13_ceval_xdot(int32_T c13_n, real_T c13_x[3], int32_T c13_ix0,
  int32_T c13_incx, real_T c13_y[3], int32_T c13_iy0, int32_T c13_incy);
static void c13_eml_error(void);
static void c13_b_eml_scalar_eg(void);
static real_T c13_b_ceval_xdot(int32_T c13_n, real_T c13_x[4], int32_T c13_ix0,
  int32_T c13_incx, real_T c13_y[4], int32_T c13_iy0, int32_T c13_incy);
static void c13_eml_warning(void);
static void c13_c_eml_scalar_eg(void);
static void c13_eml_xgemm(real_T c13_A[9], real_T c13_B[3], real_T c13_C[3],
  real_T c13_b_C[3]);
static void c13_d_eml_scalar_eg(void);
static const mxArray *c13_sf_marshall(void *c13_chartInstance, void *c13_u);
static const mxArray *c13_b_sf_marshall(void *c13_chartInstance, void *c13_u);
static const mxArray *c13_c_sf_marshall(void *c13_chartInstance, void *c13_u);
static const mxArray *c13_d_sf_marshall(void *c13_chartInstance, void *c13_u);
static void c13_info_helper(c13_ResolvedFunctionInfo c13_info[63]);
static const mxArray *c13_e_sf_marshall(void *c13_chartInstance, void *c13_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c13_adcs_v15_integral_Power(void)
{
  uint8_T *c13_is_active_c13_adcs_v15_integral_Power;
  c13_is_active_c13_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c13_is_active_c13_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c13_adcs_v15_integral_Power(void)
{
  real_T c13_dv0[9];
  int32_T c13_i0;
  real_T c13_dv1[9];
  int32_T c13_i1;
  real_T c13_dv2[9];
  int32_T c13_i2;
  real_T c13_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Kp' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    2, 0), &c13_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c13_i0 = 0; c13_i0 < 9; c13_i0 = c13_i0 + 1) {
    chartInstance.c13_Kp[c13_i0] = c13_dv0[c13_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Kd' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c13_dv1, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c13_i1 = 0; c13_i1 < 9; c13_i1 = c13_i1 + 1) {
    chartInstance.c13_Kd[c13_i1] = c13_dv1[c13_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ki' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c13_dv2, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c13_i2 = 0; c13_i2 < 9; c13_i2 = c13_i2 + 1) {
    chartInstance.c13_Ki[c13_i2] = c13_dv2[c13_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_FRAME_SIZE' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    3, 0), &c13_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c13_s_FRAME_SIZE = c13_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c13_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c13_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c13_update_debugger_state_c13_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c13_adcs_v15_integral_Power(void)
{
  c13_update_debugger_state_c13_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c13_adcs_v15_integral_Power(void)
{
  const mxArray *c13_st = NULL;
  const mxArray *c13_y = NULL;
  int32_T c13_i3;
  real_T c13_u[3];
  const mxArray *c13_b_y = NULL;
  int32_T c13_i4;
  real_T c13_b_u[3];
  const mxArray *c13_c_y = NULL;
  int32_T c13_i5;
  real_T c13_c_u[3];
  const mxArray *c13_d_y = NULL;
  int32_T c13_i6;
  real_T c13_d_u[3];
  const mxArray *c13_e_y = NULL;
  uint8_T c13_e_u;
  const mxArray *c13_f_y = NULL;
  uint8_T *c13_is_active_c13_adcs_v15_integral_Power;
  real_T (*c13_m_N)[3];
  real_T (*c13_m)[3];
  real_T (*c13_ieu)[3];
  real_T (*c13_eu)[3];
  c13_ieu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c13_m_N = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c13_m = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c13_is_active_c13_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c13_eu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(5));
  for (c13_i3 = 0; c13_i3 < 3; c13_i3 = c13_i3 + 1) {
    c13_u[c13_i3] = (*c13_eu)[c13_i3];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c13_y, 0, c13_b_y);
  for (c13_i4 = 0; c13_i4 < 3; c13_i4 = c13_i4 + 1) {
    c13_b_u[c13_i4] = (*c13_ieu)[c13_i4];
  }

  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c13_y, 1, c13_c_y);
  for (c13_i5 = 0; c13_i5 < 3; c13_i5 = c13_i5 + 1) {
    c13_c_u[c13_i5] = (*c13_m)[c13_i5];
  }

  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c13_y, 2, c13_d_y);
  for (c13_i6 = 0; c13_i6 < 3; c13_i6 = c13_i6 + 1) {
    c13_d_u[c13_i6] = (*c13_m_N)[c13_i6];
  }

  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_e_u = *c13_is_active_c13_adcs_v15_integral_Power;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c13_y, 4, c13_f_y);
  sf_mex_assign(&c13_st, c13_y);
  return c13_st;
}

static void set_sim_state_c13_adcs_v15_integral_Power(const mxArray *c13_st)
{
  const mxArray *c13_u;
  const mxArray *c13_eu;
  real_T c13_dv3[3];
  int32_T c13_i7;
  real_T c13_y[3];
  int32_T c13_i8;
  const mxArray *c13_b_eu;
  real_T c13_dv4[3];
  int32_T c13_i9;
  real_T c13_b_y[3];
  int32_T c13_i10;
  const mxArray *c13_c_eu;
  real_T c13_dv5[3];
  int32_T c13_i11;
  real_T c13_c_y[3];
  int32_T c13_i12;
  const mxArray *c13_d_eu;
  real_T c13_dv6[3];
  int32_T c13_i13;
  real_T c13_d_y[3];
  int32_T c13_i14;
  const mxArray *c13_is_active_c13_adcs_v15_integral_Power;
  uint8_T c13_u0;
  uint8_T c13_e_y;
  boolean_T *c13_doneDoubleBufferReInit;
  uint8_T *c13_b_is_active_c13_adcs_v15_integral_Power;
  real_T (*c13_e_eu)[3];
  real_T (*c13_ieu)[3];
  real_T (*c13_m)[3];
  real_T (*c13_m_N)[3];
  c13_ieu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c13_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c13_m_N = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c13_m = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c13_b_is_active_c13_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c13_e_eu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  *c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  c13_eu = sf_mex_dup(sf_mex_getcell(c13_u, 0));
  sf_mex_import("eu", sf_mex_dup(c13_eu), &c13_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i7 = 0; c13_i7 < 3; c13_i7 = c13_i7 + 1) {
    c13_y[c13_i7] = c13_dv3[c13_i7];
  }

  sf_mex_destroy(&c13_eu);
  for (c13_i8 = 0; c13_i8 < 3; c13_i8 = c13_i8 + 1) {
    (*c13_e_eu)[c13_i8] = c13_y[c13_i8];
  }

  c13_b_eu = sf_mex_dup(sf_mex_getcell(c13_u, 1));
  sf_mex_import("ieu", sf_mex_dup(c13_b_eu), &c13_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i9 = 0; c13_i9 < 3; c13_i9 = c13_i9 + 1) {
    c13_b_y[c13_i9] = c13_dv4[c13_i9];
  }

  sf_mex_destroy(&c13_b_eu);
  for (c13_i10 = 0; c13_i10 < 3; c13_i10 = c13_i10 + 1) {
    (*c13_ieu)[c13_i10] = c13_b_y[c13_i10];
  }

  c13_c_eu = sf_mex_dup(sf_mex_getcell(c13_u, 2));
  sf_mex_import("m", sf_mex_dup(c13_c_eu), &c13_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i11 = 0; c13_i11 < 3; c13_i11 = c13_i11 + 1) {
    c13_c_y[c13_i11] = c13_dv5[c13_i11];
  }

  sf_mex_destroy(&c13_c_eu);
  for (c13_i12 = 0; c13_i12 < 3; c13_i12 = c13_i12 + 1) {
    (*c13_m)[c13_i12] = c13_c_y[c13_i12];
  }

  c13_d_eu = sf_mex_dup(sf_mex_getcell(c13_u, 3));
  sf_mex_import("m_N", sf_mex_dup(c13_d_eu), &c13_dv6, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i13 = 0; c13_i13 < 3; c13_i13 = c13_i13 + 1) {
    c13_d_y[c13_i13] = c13_dv6[c13_i13];
  }

  sf_mex_destroy(&c13_d_eu);
  for (c13_i14 = 0; c13_i14 < 3; c13_i14 = c13_i14 + 1) {
    (*c13_m_N)[c13_i14] = c13_d_y[c13_i14];
  }

  c13_is_active_c13_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c13_u, 4));
  sf_mex_import("is_active_c13_adcs_v15_integral_Power", sf_mex_dup
                (c13_is_active_c13_adcs_v15_integral_Power), &c13_u0, 1, 3, 0U,
                0,
                0U, 0);
  c13_e_y = c13_u0;
  sf_mex_destroy(&c13_is_active_c13_adcs_v15_integral_Power);
  *c13_b_is_active_c13_adcs_v15_integral_Power = c13_e_y;
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_adcs_v15_integral_Power();
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_adcs_v15_integral_Power(void)
{
}

static void sf_c13_adcs_v15_integral_Power(void)
{
  int32_T c13_i15;
  int32_T c13_i16;
  int32_T c13_i17;
  int32_T c13_i18;
  int32_T c13_i19;
  int32_T c13_i20;
  int32_T c13_i21;
  int32_T c13_i22;
  int32_T c13_i23;
  int32_T c13_i24;
  int32_T c13_i25;
  int32_T c13_previousEvent;
  real_T *c13_light;
  real_T (*c13_q)[4];
  real_T (*c13_v_B)[3];
  real_T (*c13_m_N)[3];
  real_T (*c13_w)[3];
  real_T (*c13_m)[3];
  real_T (*c13_eu)[3];
  real_T (*c13_ieu_prev)[3];
  real_T (*c13_ieu)[3];
  c13_ieu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c13_ieu_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c13_w = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c13_m_N = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c13_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 3);
  c13_m = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c13_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 4);
  c13_eu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c13_light = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,11);
  for (c13_i15 = 0; c13_i15 < 3; c13_i15 = c13_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_ieu)[c13_i15], 0U);
  }

  for (c13_i16 = 0; c13_i16 < 3; c13_i16 = c13_i16 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_ieu_prev)[c13_i16], 1U);
  }

  for (c13_i17 = 0; c13_i17 < 3; c13_i17 = c13_i17 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_eu)[c13_i17], 2U);
  }

  for (c13_i18 = 0; c13_i18 < 3; c13_i18 = c13_i18 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_m)[c13_i18], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c13_light, 4U);
  for (c13_i19 = 0; c13_i19 < 3; c13_i19 = c13_i19 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_w)[c13_i19], 5U);
  }

  for (c13_i20 = 0; c13_i20 < 3; c13_i20 = c13_i20 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_m_N)[c13_i20], 6U);
  }

  for (c13_i21 = 0; c13_i21 < 3; c13_i21 = c13_i21 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_v_B)[c13_i21], 7U);
  }

  for (c13_i22 = 0; c13_i22 < 9; c13_i22 = c13_i22 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c13_Kp[c13_i22], 8U);
  }

  for (c13_i23 = 0; c13_i23 < 9; c13_i23 = c13_i23 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c13_Kd[c13_i23], 9U);
  }

  for (c13_i24 = 0; c13_i24 < 9; c13_i24 = c13_i24 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c13_Ki[c13_i24], 10U);
  }

  for (c13_i25 = 0; c13_i25 < 4; c13_i25 = c13_i25 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_q)[c13_i25], 11U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c13_s_FRAME_SIZE, 12U);
  c13_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c13_c13_adcs_v15_integral_Power();
  _sfEvent_ = c13_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c13_c13_adcs_v15_integral_Power(void)
{
  int32_T c13_i26;
  real_T c13_ieu_prev[3];
  real_T c13_light;
  int32_T c13_i27;
  real_T c13_w[3];
  int32_T c13_i28;
  real_T c13_v_B[3];
  int32_T c13_i29;
  real_T c13_b_Ki[9];
  int32_T c13_i30;
  real_T c13_q[4];
  real_T c13_b_s_FRAME_SIZE;
  real_T c13_nargout = 4.0;
  real_T c13_nargin = 9.0;
  real_T c13_b_Kd[9] = { 6.7710427973701772E-004, -4.2419745512218675E-006,
    -3.5737964722194352E-006, -4.2419745512218675E-006,
    6.8317419624151548E-004, -1.4355590362665846E-005, -3.5737964722194352E-006,
    -1.4355590362665846E-005,
    6.3136412874267845E-004 };

  real_T c13_b_Kp[9] = { 3.4796209949396335E-007, -2.1799395086033269E-009,
    -1.8365645600712765E-009, -2.1799395086033269E-009,
    3.5108141354035872E-007, -7.3772999396911418E-009, -1.8365645600712765E-009,
    -7.3772999396911418E-009,
    3.2445635680785487E-007 };

  real_T c13_qs;
  real_T c13_qv[3];
  real_T c13_Bnorm;
  real_T c13_m_N[3];
  real_T c13_m[3];
  real_T c13_eu[3];
  real_T c13_ieu[3];
  int32_T c13_i31;
  real_T c13_b_v_B[3];
  int32_T c13_i32;
  real_T c13_c_v_B[3];
  real_T c13_x;
  real_T c13_b_x;
  int32_T c13_i33;
  real_T c13_A[4];
  int32_T c13_i34;
  real_T c13_c_a[4];
  int32_T c13_i35;
  real_T c13_b[4];
  int32_T c13_i36;
  real_T c13_d_a[4];
  int32_T c13_i37;
  real_T c13_b_b[4];
  int32_T c13_i38;
  real_T c13_c_x[4];
  int32_T c13_i39;
  real_T c13_y[4];
  int32_T c13_i40;
  real_T c13_d_x[4];
  int32_T c13_i41;
  real_T c13_b_y[4];
  int32_T c13_i42;
  real_T c13_e_x[4];
  int32_T c13_i43;
  real_T c13_c_y[4];
  int32_T c13_i44;
  real_T c13_f_x[4];
  int32_T c13_i45;
  real_T c13_d_y[4];
  real_T c13_g_x;
  real_T c13_B;
  real_T c13_h_x;
  int32_T c13_i46;
  real_T c13_i_x[4];
  real_T c13_e_y;
  int32_T c13_i47;
  real_T c13_j_x[4];
  real_T c13_f_y;
  int32_T c13_i48;
  real_T c13_k_x[4];
  real_T c13_g_y;
  int32_T c13_i49;
  int32_T c13_i50;
  int32_T c13_i51;
  real_T c13_c_b[3];
  int32_T c13_i52;
  real_T c13_e_a[3];
  real_T c13_d_b;
  int32_T c13_i53;
  int32_T c13_i54;
  real_T c13_f_a[3];
  real_T c13_e_b;
  int32_T c13_i55;
  real_T c13_h_y[3];
  int32_T c13_i56;
  int32_T c13_i57;
  real_T c13_f_b[3];
  int32_T c13_i58;
  static real_T c13_dv7[9] = { 6.7710427973701772E-004, -4.2419745512218675E-006,
    -3.5737964722194352E-006, -4.2419745512218675E-006,
    6.8317419624151548E-004, -1.4355590362665846E-005, -3.5737964722194352E-006,
    -1.4355590362665846E-005,
    6.3136412874267845E-004 };

  real_T c13_dv8[9];
  int32_T c13_i59;
  real_T c13_g_b[3];
  int32_T c13_i60;
  real_T c13_dv9[3];
  real_T c13_i_y[3];
  int32_T c13_i61;
  real_T c13_g_a[9];
  int32_T c13_i62;
  real_T c13_h_b[3];
  int32_T c13_i63;
  real_T c13_h_a[9];
  int32_T c13_i64;
  real_T c13_i_b[3];
  int32_T c13_i65;
  real_T c13_dv10[3];
  real_T c13_j_y[3];
  int32_T c13_i66;
  real_T c13_j_b[3];
  int32_T c13_i67;
  static real_T c13_dv11[9] = { 3.4796209949396335E-007,
    -2.1799395086033269E-009, -1.8365645600712765E-009, -2.1799395086033269E-009
    , 3.5108141354035872E-007, -7.3772999396911418E-009,
    -1.8365645600712765E-009,
    -7.3772999396911418E-009, 3.2445635680785487E-007 };

  real_T c13_dv12[9];
  int32_T c13_i68;
  real_T c13_k_b[3];
  int32_T c13_i69;
  real_T c13_dv13[3];
  real_T c13_k_y[3];
  int32_T c13_i70;
  real_T c13_b_A[3];
  real_T c13_i_a;
  real_T c13_j_a;
  real_T c13_ak;
  real_T c13_b_B;
  int32_T c13_i71;
  real_T c13_l_x[3];
  real_T c13_l_y;
  int32_T c13_i72;
  real_T c13_m_x[3];
  real_T c13_m_y;
  int32_T c13_i73;
  real_T c13_n_x[3];
  real_T c13_n_y;
  int32_T c13_i74;
  int32_T c13_i75;
  real_T c13_k_a[3];
  int32_T c13_i76;
  real_T c13_l_b[3];
  real_T c13_l_a;
  real_T c13_m_b;
  real_T c13_o_y;
  real_T c13_m_a;
  real_T c13_n_b;
  real_T c13_p_y;
  real_T c13_c1;
  real_T c13_n_a;
  real_T c13_o_b;
  real_T c13_q_y;
  real_T c13_o_a;
  real_T c13_p_b;
  real_T c13_r_y;
  real_T c13_c2;
  real_T c13_p_a;
  real_T c13_q_b;
  real_T c13_s_y;
  real_T c13_q_a;
  real_T c13_r_b;
  real_T c13_t_y;
  real_T c13_c3;
  real_T c13_r_a[3];
  real_T c13_s_b;
  int32_T c13_i77;
  int32_T c13_i78;
  int32_T c13_i79;
  int32_T c13_i80;
  int32_T c13_i81;
  real_T *c13_b_light;
  real_T (*c13_b_ieu)[3];
  real_T (*c13_b_eu)[3];
  real_T (*c13_b_m)[3];
  real_T (*c13_b_m_N)[3];
  real_T (*c13_b_q)[4];
  real_T (*c13_d_v_B)[3];
  real_T (*c13_b_w)[3];
  real_T (*c13_b_ieu_prev)[3];
  c13_b_ieu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c13_b_ieu_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c13_b_w = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c13_b_m_N = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c13_d_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 3);
  c13_b_m = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c13_b_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 4);
  c13_b_eu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c13_b_light = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,11);
  for (c13_i26 = 0; c13_i26 < 3; c13_i26 = c13_i26 + 1) {
    c13_ieu_prev[c13_i26] = (*c13_b_ieu_prev)[c13_i26];
  }

  c13_light = *c13_b_light;
  for (c13_i27 = 0; c13_i27 < 3; c13_i27 = c13_i27 + 1) {
    c13_w[c13_i27] = (*c13_b_w)[c13_i27];
  }

  for (c13_i28 = 0; c13_i28 < 3; c13_i28 = c13_i28 + 1) {
    c13_v_B[c13_i28] = (*c13_d_v_B)[c13_i28];
  }

  for (c13_i29 = 0; c13_i29 < 9; c13_i29 = c13_i29 + 1) {
    c13_b_Ki[c13_i29] = chartInstance.c13_Ki[c13_i29];
  }

  for (c13_i30 = 0; c13_i30 < 4; c13_i30 = c13_i30 + 1) {
    c13_q[c13_i30] = (*c13_b_q)[c13_i30];
  }

  c13_b_s_FRAME_SIZE = chartInstance.c13_s_FRAME_SIZE;
  sf_debug_symbol_scope_push(18U, 0U);
  sf_debug_symbol_scope_add("nargout", &c13_nargout, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c13_nargin, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("Kd", &c13_b_Kd, c13_c_sf_marshall);
  sf_debug_symbol_scope_add("Kp", &c13_b_Kp, c13_c_sf_marshall);
  sf_debug_symbol_scope_add("qs", &c13_qs, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("qv", &c13_qv, c13_sf_marshall);
  sf_debug_symbol_scope_add("Bnorm", &c13_Bnorm, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("m_N", &c13_m_N, c13_sf_marshall);
  sf_debug_symbol_scope_add("m", &c13_m, c13_sf_marshall);
  sf_debug_symbol_scope_add("eu", &c13_eu, c13_sf_marshall);
  sf_debug_symbol_scope_add("ieu", &c13_ieu, c13_sf_marshall);
  sf_debug_symbol_scope_add("s_FRAME_SIZE", &c13_b_s_FRAME_SIZE,
    c13_b_sf_marshall);
  sf_debug_symbol_scope_add("q", &c13_q, c13_d_sf_marshall);
  sf_debug_symbol_scope_add("Ki", &c13_b_Ki, c13_c_sf_marshall);
  sf_debug_symbol_scope_add("v_B", &c13_v_B, c13_sf_marshall);
  sf_debug_symbol_scope_add("w", &c13_w, c13_sf_marshall);
  sf_debug_symbol_scope_add("light", &c13_light, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("ieu_prev", &c13_ieu_prev, c13_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c13_i31 = 0; c13_i31 < 3; c13_i31 = c13_i31 + 1) {
    c13_b_v_B[c13_i31] = c13_v_B[c13_i31];
  }

  for (c13_i32 = 0; c13_i32 < 3; c13_i32 = c13_i32 + 1) {
    c13_c_v_B[c13_i32] = c13_v_B[c13_i32];
  }

  c13_x = c13_dot(c13_b_v_B, c13_c_v_B);
  c13_Bnorm = c13_x;
  if (c13_Bnorm < 0.0) {
    c13_eml_error();
  }

  c13_b_x = c13_Bnorm;
  c13_Bnorm = c13_b_x;
  c13_Bnorm = muDoubleScalarSqrt(c13_Bnorm);
  _SFD_EML_CALL(0,7);
  for (c13_i33 = 0; c13_i33 < 4; c13_i33 = c13_i33 + 1) {
    c13_A[c13_i33] = c13_q[c13_i33];
  }

  for (c13_i34 = 0; c13_i34 < 4; c13_i34 = c13_i34 + 1) {
    c13_c_a[c13_i34] = c13_q[c13_i34];
  }

  for (c13_i35 = 0; c13_i35 < 4; c13_i35 = c13_i35 + 1) {
    c13_b[c13_i35] = c13_q[c13_i35];
  }

  c13_b_eml_scalar_eg();
  for (c13_i36 = 0; c13_i36 < 4; c13_i36 = c13_i36 + 1) {
    c13_d_a[c13_i36] = c13_c_a[c13_i36];
  }

  for (c13_i37 = 0; c13_i37 < 4; c13_i37 = c13_i37 + 1) {
    c13_b_b[c13_i37] = c13_b[c13_i37];
  }

  for (c13_i38 = 0; c13_i38 < 4; c13_i38 = c13_i38 + 1) {
    c13_c_x[c13_i38] = c13_d_a[c13_i38];
  }

  for (c13_i39 = 0; c13_i39 < 4; c13_i39 = c13_i39 + 1) {
    c13_y[c13_i39] = c13_b_b[c13_i39];
  }

  for (c13_i40 = 0; c13_i40 < 4; c13_i40 = c13_i40 + 1) {
    c13_d_x[c13_i40] = c13_c_x[c13_i40];
  }

  for (c13_i41 = 0; c13_i41 < 4; c13_i41 = c13_i41 + 1) {
    c13_b_y[c13_i41] = c13_y[c13_i41];
  }

  for (c13_i42 = 0; c13_i42 < 4; c13_i42 = c13_i42 + 1) {
    c13_e_x[c13_i42] = c13_d_x[c13_i42];
  }

  for (c13_i43 = 0; c13_i43 < 4; c13_i43 = c13_i43 + 1) {
    c13_c_y[c13_i43] = c13_b_y[c13_i43];
  }

  for (c13_i44 = 0; c13_i44 < 4; c13_i44 = c13_i44 + 1) {
    c13_f_x[c13_i44] = c13_e_x[c13_i44];
  }

  for (c13_i45 = 0; c13_i45 < 4; c13_i45 = c13_i45 + 1) {
    c13_d_y[c13_i45] = c13_c_y[c13_i45];
  }

  c13_g_x = c13_b_ceval_xdot(4, c13_f_x, 1, 1, c13_d_y, 1, 1);
  c13_B = c13_g_x;
  if (c13_B < 0.0) {
    c13_eml_error();
  }

  c13_h_x = c13_B;
  c13_B = c13_h_x;
  c13_B = muDoubleScalarSqrt(c13_B);
  for (c13_i46 = 0; c13_i46 < 4; c13_i46 = c13_i46 + 1) {
    c13_i_x[c13_i46] = c13_A[c13_i46];
  }

  c13_e_y = c13_B;
  if (c13_e_y == 0.0) {
    c13_eml_warning();
  }

  for (c13_i47 = 0; c13_i47 < 4; c13_i47 = c13_i47 + 1) {
    c13_j_x[c13_i47] = c13_i_x[c13_i47];
  }

  c13_f_y = c13_e_y;
  for (c13_i48 = 0; c13_i48 < 4; c13_i48 = c13_i48 + 1) {
    c13_k_x[c13_i48] = c13_j_x[c13_i48];
  }

  c13_g_y = c13_f_y;
  for (c13_i49 = 0; c13_i49 < 4; c13_i49 = c13_i49 + 1) {
    c13_q[c13_i49] = c13_k_x[c13_i49] / c13_g_y;
  }

  _SFD_EML_CALL(0,9);
  for (c13_i50 = 0; c13_i50 < 3; c13_i50 = c13_i50 + 1) {
    c13_qv[c13_i50] = c13_q[c13_i50];
  }

  /*  e*sin(t/2) */
  _SFD_EML_CALL(0,10);
  c13_qs = c13_q[3];

  /*    cos(t/2) */
  _SFD_EML_CALL(0,12);
  for (c13_i51 = 0; c13_i51 < 3; c13_i51 = c13_i51 + 1) {
    c13_c_b[c13_i51] = c13_qv[c13_i51];
  }

  for (c13_i52 = 0; c13_i52 < 3; c13_i52 = c13_i52 + 1) {
    c13_e_a[c13_i52] = 2.0 * c13_c_b[c13_i52];
  }

  c13_d_b = c13_qs;
  for (c13_i53 = 0; c13_i53 < 3; c13_i53 = c13_i53 + 1) {
    c13_eu[c13_i53] = c13_e_a[c13_i53] * c13_d_b;
  }

  /*  2*e*sin(t/2)*cos(t/2) = e*sin(t)    % P variable */
  _SFD_EML_CALL(0,14);
  for (c13_i54 = 0; c13_i54 < 3; c13_i54 = c13_i54 + 1) {
    c13_f_a[c13_i54] = c13_eu[c13_i54];
  }

  c13_e_b = c13_b_s_FRAME_SIZE;
  for (c13_i55 = 0; c13_i55 < 3; c13_i55 = c13_i55 + 1) {
    c13_h_y[c13_i55] = c13_f_a[c13_i55] * c13_e_b;
  }

  for (c13_i56 = 0; c13_i56 < 3; c13_i56 = c13_i56 + 1) {
    c13_ieu[c13_i56] = c13_ieu_prev[c13_i56] + c13_h_y[c13_i56];
  }

  /*  integral eu dt,   % I variable */
  _SFD_EML_CALL(0,16);
  for (c13_i57 = 0; c13_i57 < 3; c13_i57 = c13_i57 + 1) {
    c13_f_b[c13_i57] = c13_w[c13_i57];
  }

  c13_c_eml_scalar_eg();
  c13_c_eml_scalar_eg();
  for (c13_i58 = 0; c13_i58 < 9; c13_i58 = c13_i58 + 1) {
    c13_dv8[c13_i58] = c13_dv7[c13_i58];
  }

  for (c13_i59 = 0; c13_i59 < 3; c13_i59 = c13_i59 + 1) {
    c13_g_b[c13_i59] = c13_f_b[c13_i59];
  }

  for (c13_i60 = 0; c13_i60 < 3; c13_i60 = c13_i60 + 1) {
    c13_dv9[c13_i60] = 0.0;
  }

  c13_eml_xgemm(c13_dv8, c13_g_b, c13_dv9, c13_i_y);
  for (c13_i61 = 0; c13_i61 < 9; c13_i61 = c13_i61 + 1) {
    c13_g_a[c13_i61] = c13_b_Ki[c13_i61];
  }

  for (c13_i62 = 0; c13_i62 < 3; c13_i62 = c13_i62 + 1) {
    c13_h_b[c13_i62] = c13_ieu[c13_i62];
  }

  c13_c_eml_scalar_eg();
  c13_c_eml_scalar_eg();
  for (c13_i63 = 0; c13_i63 < 9; c13_i63 = c13_i63 + 1) {
    c13_h_a[c13_i63] = c13_g_a[c13_i63];
  }

  for (c13_i64 = 0; c13_i64 < 3; c13_i64 = c13_i64 + 1) {
    c13_i_b[c13_i64] = c13_h_b[c13_i64];
  }

  for (c13_i65 = 0; c13_i65 < 3; c13_i65 = c13_i65 + 1) {
    c13_dv10[c13_i65] = 0.0;
  }

  c13_eml_xgemm(c13_h_a, c13_i_b, c13_dv10, c13_j_y);
  for (c13_i66 = 0; c13_i66 < 3; c13_i66 = c13_i66 + 1) {
    c13_j_b[c13_i66] = c13_eu[c13_i66];
  }

  c13_c_eml_scalar_eg();
  c13_c_eml_scalar_eg();
  for (c13_i67 = 0; c13_i67 < 9; c13_i67 = c13_i67 + 1) {
    c13_dv12[c13_i67] = c13_dv11[c13_i67];
  }

  for (c13_i68 = 0; c13_i68 < 3; c13_i68 = c13_i68 + 1) {
    c13_k_b[c13_i68] = c13_j_b[c13_i68];
  }

  for (c13_i69 = 0; c13_i69 < 3; c13_i69 = c13_i69 + 1) {
    c13_dv13[c13_i69] = 0.0;
  }

  c13_eml_xgemm(c13_dv12, c13_k_b, c13_dv13, c13_k_y);
  for (c13_i70 = 0; c13_i70 < 3; c13_i70 = c13_i70 + 1) {
    c13_b_A[c13_i70] = (c13_k_y[c13_i70] + c13_j_y[c13_i70]) + c13_i_y[c13_i70];
  }

  c13_i_a = c13_Bnorm;
  c13_j_a = c13_i_a;
  c13_d_eml_scalar_eg();
  c13_ak = c13_j_a;
  c13_b_B = muDoubleScalarPower(c13_ak, 2.0);
  for (c13_i71 = 0; c13_i71 < 3; c13_i71 = c13_i71 + 1) {
    c13_l_x[c13_i71] = c13_b_A[c13_i71];
  }

  c13_l_y = c13_b_B;
  if (c13_l_y == 0.0) {
    c13_eml_warning();
  }

  for (c13_i72 = 0; c13_i72 < 3; c13_i72 = c13_i72 + 1) {
    c13_m_x[c13_i72] = c13_l_x[c13_i72];
  }

  c13_m_y = c13_l_y;
  for (c13_i73 = 0; c13_i73 < 3; c13_i73 = c13_i73 + 1) {
    c13_n_x[c13_i73] = c13_m_x[c13_i73];
  }

  c13_n_y = c13_m_y;
  for (c13_i74 = 0; c13_i74 < 3; c13_i74 = c13_i74 + 1) {
    c13_m[c13_i74] = c13_n_x[c13_i74] / c13_n_y;
  }

  _SFD_EML_CALL(0,18);
  for (c13_i75 = 0; c13_i75 < 3; c13_i75 = c13_i75 + 1) {
    c13_k_a[c13_i75] = c13_m[c13_i75];
  }

  for (c13_i76 = 0; c13_i76 < 3; c13_i76 = c13_i76 + 1) {
    c13_l_b[c13_i76] = c13_v_B[c13_i76];
  }

  c13_l_a = c13_k_a[2];
  c13_m_b = c13_l_b[1];
  c13_o_y = c13_l_a * c13_m_b;
  c13_m_a = c13_k_a[1];
  c13_n_b = c13_l_b[2];
  c13_p_y = c13_m_a * c13_n_b;
  c13_c1 = c13_p_y - c13_o_y;
  c13_n_a = c13_k_a[0];
  c13_o_b = c13_l_b[2];
  c13_q_y = c13_n_a * c13_o_b;
  c13_o_a = c13_k_a[2];
  c13_p_b = c13_l_b[0];
  c13_r_y = c13_o_a * c13_p_b;
  c13_c2 = c13_r_y - c13_q_y;
  c13_p_a = c13_k_a[1];
  c13_q_b = c13_l_b[0];
  c13_s_y = c13_p_a * c13_q_b;
  c13_q_a = c13_k_a[0];
  c13_r_b = c13_l_b[1];
  c13_t_y = c13_q_a * c13_r_b;
  c13_c3 = c13_t_y - c13_s_y;
  c13_r_a[0] = c13_c1;
  c13_r_a[1] = c13_c2;
  c13_r_a[2] = c13_c3;
  c13_s_b = c13_light;
  for (c13_i77 = 0; c13_i77 < 3; c13_i77 = c13_i77 + 1) {
    c13_m_N[c13_i77] = c13_r_a[c13_i77] * c13_s_b;
  }

  _SFD_EML_CALL(0,-18);
  sf_debug_symbol_scope_pop();
  for (c13_i78 = 0; c13_i78 < 3; c13_i78 = c13_i78 + 1) {
    (*c13_b_ieu)[c13_i78] = c13_ieu[c13_i78];
  }

  for (c13_i79 = 0; c13_i79 < 3; c13_i79 = c13_i79 + 1) {
    (*c13_b_eu)[c13_i79] = c13_eu[c13_i79];
  }

  for (c13_i80 = 0; c13_i80 < 3; c13_i80 = c13_i80 + 1) {
    (*c13_b_m)[c13_i80] = c13_m[c13_i80];
  }

  for (c13_i81 = 0; c13_i81 < 3; c13_i81 = c13_i81 + 1) {
    (*c13_b_m_N)[c13_i81] = c13_m_N[c13_i81];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static real_T c13_dot(real_T c13_c_a[3], real_T c13_b[3])
{
  int32_T c13_i82;
  real_T c13_d_a[3];
  int32_T c13_i83;
  real_T c13_b_b[3];
  int32_T c13_i84;
  real_T c13_x[3];
  int32_T c13_i85;
  real_T c13_y[3];
  int32_T c13_i86;
  real_T c13_b_x[3];
  int32_T c13_i87;
  real_T c13_b_y[3];
  int32_T c13_i88;
  real_T c13_c_x[3];
  int32_T c13_i89;
  real_T c13_c_y[3];
  int32_T c13_i90;
  real_T c13_d_x[3];
  int32_T c13_i91;
  real_T c13_d_y[3];
  c13_eml_scalar_eg();
  for (c13_i82 = 0; c13_i82 < 3; c13_i82 = c13_i82 + 1) {
    c13_d_a[c13_i82] = c13_c_a[c13_i82];
  }

  for (c13_i83 = 0; c13_i83 < 3; c13_i83 = c13_i83 + 1) {
    c13_b_b[c13_i83] = c13_b[c13_i83];
  }

  for (c13_i84 = 0; c13_i84 < 3; c13_i84 = c13_i84 + 1) {
    c13_x[c13_i84] = c13_d_a[c13_i84];
  }

  for (c13_i85 = 0; c13_i85 < 3; c13_i85 = c13_i85 + 1) {
    c13_y[c13_i85] = c13_b_b[c13_i85];
  }

  for (c13_i86 = 0; c13_i86 < 3; c13_i86 = c13_i86 + 1) {
    c13_b_x[c13_i86] = c13_x[c13_i86];
  }

  for (c13_i87 = 0; c13_i87 < 3; c13_i87 = c13_i87 + 1) {
    c13_b_y[c13_i87] = c13_y[c13_i87];
  }

  for (c13_i88 = 0; c13_i88 < 3; c13_i88 = c13_i88 + 1) {
    c13_c_x[c13_i88] = c13_b_x[c13_i88];
  }

  for (c13_i89 = 0; c13_i89 < 3; c13_i89 = c13_i89 + 1) {
    c13_c_y[c13_i89] = c13_b_y[c13_i89];
  }

  for (c13_i90 = 0; c13_i90 < 3; c13_i90 = c13_i90 + 1) {
    c13_d_x[c13_i90] = c13_c_x[c13_i90];
  }

  for (c13_i91 = 0; c13_i91 < 3; c13_i91 = c13_i91 + 1) {
    c13_d_y[c13_i91] = c13_c_y[c13_i91];
  }

  return c13_ceval_xdot(3, c13_d_x, 1, 1, c13_d_y, 1, 1);
}

static void c13_eml_scalar_eg(void)
{
}

static real_T c13_ceval_xdot(int32_T c13_n, real_T c13_x[3], int32_T c13_ix0,
  int32_T c13_incx, real_T c13_y[3], int32_T c13_iy0,
  int32_T c13_incy)
{
  real_T c13_d;
  c13_d = 0.0;
  if ((real_T)c13_n > 0.0) {
    return ddot32(&c13_n, &c13_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c13_ix0), 1, 3, 1, 0) - 1]
                  , &c13_incx, &c13_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c13_iy0), 1, 3, 1, 0) - 1], &
                  c13_incy);
  }

  return c13_d;
}

static void c13_eml_error(void)
{
  int32_T c13_i92;
  static char_T c13_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c13_u[77];
  const mxArray *c13_y = NULL;
  int32_T c13_i93;
  static char_T c13_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c13_b_u[31];
  const mxArray *c13_b_y = NULL;
  for (c13_i92 = 0; c13_i92 < 77; c13_i92 = c13_i92 + 1) {
    c13_u[c13_i92] = c13_cv0[c13_i92];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c13_i93 = 0; c13_i93 < 31; c13_i93 = c13_i93 + 1) {
    c13_b_u[c13_i93] = c13_cv1[c13_i93];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c13_b_y, 14, c13_y);
}

static void c13_b_eml_scalar_eg(void)
{
}

static real_T c13_b_ceval_xdot(int32_T c13_n, real_T c13_x[4], int32_T c13_ix0,
  int32_T c13_incx, real_T c13_y[4], int32_T c13_iy0,
  int32_T c13_incy)
{
  real_T c13_d;
  c13_d = 0.0;
  if ((real_T)c13_n > 0.0) {
    return ddot32(&c13_n, &c13_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c13_ix0), 1, 4, 1, 0) - 1]
                  , &c13_incx, &c13_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c13_iy0), 1, 4, 1, 0) - 1], &
                  c13_incy);
  }

  return c13_d;
}

static void c13_eml_warning(void)
{
  int32_T c13_i94;
  static char_T c13_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c13_u[15];
  const mxArray *c13_y = NULL;
  int32_T c13_i95;
  static char_T c13_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c13_b_u[19];
  const mxArray *c13_b_y = NULL;
  for (c13_i94 = 0; c13_i94 < 15; c13_i94 = c13_i94 + 1) {
    c13_u[c13_i94] = c13_cv2[c13_i94];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c13_i95 = 0; c13_i95 < 19; c13_i95 = c13_i95 + 1) {
    c13_b_u[c13_i95] = c13_cv3[c13_i95];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c13_b_y, 14, c13_y);
}

static void c13_c_eml_scalar_eg(void)
{
}

static void c13_eml_xgemm(real_T c13_A[9], real_T c13_B[3], real_T c13_C[3],
  real_T c13_b_C[3])
{
  int32_T c13_i96;
  real_T c13_b_A[9];
  int32_T c13_i97;
  real_T c13_b_B[3];
  int32_T c13_i98;
  real_T c13_c_A[9];
  int32_T c13_i99;
  real_T c13_c_B[3];
  int32_T c13_i100;
  int32_T c13_i101;
  int32_T c13_i102;
  for (c13_i96 = 0; c13_i96 < 9; c13_i96 = c13_i96 + 1) {
    c13_b_A[c13_i96] = c13_A[c13_i96];
  }

  for (c13_i97 = 0; c13_i97 < 3; c13_i97 = c13_i97 + 1) {
    c13_b_B[c13_i97] = c13_B[c13_i97];
  }

  for (c13_i98 = 0; c13_i98 < 9; c13_i98 = c13_i98 + 1) {
    c13_c_A[c13_i98] = c13_b_A[c13_i98];
  }

  for (c13_i99 = 0; c13_i99 < 3; c13_i99 = c13_i99 + 1) {
    c13_c_B[c13_i99] = c13_b_B[c13_i99];
  }

  for (c13_i100 = 0; c13_i100 < 3; c13_i100 = c13_i100 + 1) {
    c13_b_C[c13_i100] = 0.0;
    c13_i101 = 0;
    for (c13_i102 = 0; c13_i102 < 3; c13_i102 = c13_i102 + 1) {
      c13_b_C[c13_i100] = c13_b_C[c13_i100] + c13_c_A[c13_i101 + c13_i100] *
        c13_c_B[c13_i102];
      c13_i101 = c13_i101 + 3;
    }
  }
}

static void c13_d_eml_scalar_eg(void)
{
}

static const mxArray *c13_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  int32_T c13_i103;
  real_T c13_b_u[3];
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  for (c13_i103 = 0; c13_i103 < 3; c13_i103 = c13_i103 + 1) {
    c13_b_u[c13_i103] = (*((real_T (*)[3])c13_u))[c13_i103];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static const mxArray *c13_b_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  c13_b_u = *((real_T *)c13_u);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static const mxArray *c13_c_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  int32_T c13_i104;
  int32_T c13_i105;
  int32_T c13_i106;
  real_T c13_b_u[9];
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  c13_i104 = 0;
  for (c13_i105 = 0; c13_i105 < 3; c13_i105 = c13_i105 + 1) {
    for (c13_i106 = 0; c13_i106 < 3; c13_i106 = c13_i106 + 1) {
      c13_b_u[c13_i106 + c13_i104] = (*((real_T (*)[9])c13_u))[c13_i106 +
        c13_i104];
    }

    c13_i104 = c13_i104 + 3;
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static const mxArray *c13_d_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  int32_T c13_i107;
  real_T c13_b_u[4];
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  for (c13_i107 = 0; c13_i107 < 4; c13_i107 = c13_i107 + 1) {
    c13_b_u[c13_i107] = (*((real_T (*)[4])c13_u))[c13_i107];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

const mxArray *sf_c13_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_ResolvedFunctionInfo c13_info[63];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i108;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_info_helper(c13_info);
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 63));
  for (c13_i108 = 0; c13_i108 < 63; c13_i108 = c13_i108 + 1) {
    c13_r0 = &c13_info[c13_i108];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context"
                    , "nameCaptureInfo", c13_i108);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name",
                    "nameCaptureInfo", c13_i108);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i108);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)),
                    "resolved", "nameCaptureInfo", c13_i108);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c13_i108);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c13_i108);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c13_i108);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(c13_ResolvedFunctionInfo c13_info[63])
{
  c13_info[0].context = "";
  c13_info[0].name = "dot";
  c13_info[0].dominantType = "double";
  c13_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[0].fileLength = 2812U;
  c13_info[0].fileTime1 = 1236241088U;
  c13_info[0].fileTime2 = 0U;
  c13_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[1].name = "nargin";
  c13_info[1].dominantType = "";
  c13_info[1].resolved = "[B]nargin";
  c13_info[1].fileLength = 0U;
  c13_info[1].fileTime1 = 0U;
  c13_info[1].fileTime2 = 0U;
  c13_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[2].name = "gt";
  c13_info[2].dominantType = "double";
  c13_info[2].resolved = "[B]gt";
  c13_info[2].fileLength = 0U;
  c13_info[2].fileTime1 = 0U;
  c13_info[2].fileTime2 = 0U;
  c13_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[3].name = "isa";
  c13_info[3].dominantType = "double";
  c13_info[3].resolved = "[B]isa";
  c13_info[3].fileLength = 0U;
  c13_info[3].fileTime1 = 0U;
  c13_info[3].fileTime2 = 0U;
  c13_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[4].name = "size";
  c13_info[4].dominantType = "double";
  c13_info[4].resolved = "[B]size";
  c13_info[4].fileLength = 0U;
  c13_info[4].fileTime1 = 0U;
  c13_info[4].fileTime2 = 0U;
  c13_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[5].name = "isequal";
  c13_info[5].dominantType = "double";
  c13_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c13_info[5].fileLength = 180U;
  c13_info[5].fileTime1 = 1226561072U;
  c13_info[5].fileTime2 = 0U;
  c13_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c13_info[6].name = "false";
  c13_info[6].dominantType = "";
  c13_info[6].resolved = "[B]false";
  c13_info[6].fileLength = 0U;
  c13_info[6].fileTime1 = 0U;
  c13_info[6].fileTime2 = 0U;
  c13_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c13_info[7].name = "eml_isequal_core";
  c13_info[7].dominantType = "double";
  c13_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c13_info[7].fileLength = 3981U;
  c13_info[7].fileTime1 = 1236241072U;
  c13_info[7].fileTime2 = 0U;
  c13_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c13_info[8].name = "ge";
  c13_info[8].dominantType = "double";
  c13_info[8].resolved = "[B]ge";
  c13_info[8].fileLength = 0U;
  c13_info[8].fileTime1 = 0U;
  c13_info[8].fileTime2 = 0U;
  c13_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c13_info[9].name = "isscalar";
  c13_info[9].dominantType = "logical";
  c13_info[9].resolved = "[B]isscalar";
  c13_info[9].fileLength = 0U;
  c13_info[9].fileTime1 = 0U;
  c13_info[9].fileTime2 = 0U;
  c13_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c13_info[10].name = "islogical";
  c13_info[10].dominantType = "logical";
  c13_info[10].resolved = "[B]islogical";
  c13_info[10].fileLength = 0U;
  c13_info[10].fileTime1 = 0U;
  c13_info[10].fileTime2 = 0U;
  c13_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c13_info[11].name = "minus";
  c13_info[11].dominantType = "double";
  c13_info[11].resolved = "[B]minus";
  c13_info[11].fileLength = 0U;
  c13_info[11].fileTime1 = 0U;
  c13_info[11].fileTime2 = 0U;
  c13_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c13_info[12].name = "isnumeric";
  c13_info[12].dominantType = "double";
  c13_info[12].resolved = "[B]isnumeric";
  c13_info[12].fileLength = 0U;
  c13_info[12].fileTime1 = 0U;
  c13_info[12].fileTime2 = 0U;
  c13_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c13_info[13].name = "ndims";
  c13_info[13].dominantType = "double";
  c13_info[13].resolved = "[B]ndims";
  c13_info[13].fileLength = 0U;
  c13_info[13].fileTime1 = 0U;
  c13_info[13].fileTime2 = 0U;
  c13_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c13_info[14].name = "ne";
  c13_info[14].dominantType = "double";
  c13_info[14].resolved = "[B]ne";
  c13_info[14].fileLength = 0U;
  c13_info[14].fileTime1 = 0U;
  c13_info[14].fileTime2 = 0U;
  c13_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c13_info[15].name = "true";
  c13_info[15].dominantType = "";
  c13_info[15].resolved = "[B]true";
  c13_info[15].fileLength = 0U;
  c13_info[15].fileTime1 = 0U;
  c13_info[15].fileTime2 = 0U;
  c13_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c13_info[16].name = "isstruct";
  c13_info[16].dominantType = "double";
  c13_info[16].resolved = "[B]isstruct";
  c13_info[16].fileLength = 0U;
  c13_info[16].fileTime1 = 0U;
  c13_info[16].fileTime2 = 0U;
  c13_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c13_info[17].name = "eq";
  c13_info[17].dominantType = "logical";
  c13_info[17].resolved = "[B]eq";
  c13_info[17].fileLength = 0U;
  c13_info[17].fileTime1 = 0U;
  c13_info[17].fileTime2 = 0U;
  c13_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c13_info[18].name = "isempty";
  c13_info[18].dominantType = "double";
  c13_info[18].resolved = "[B]isempty";
  c13_info[18].fileLength = 0U;
  c13_info[18].fileTime1 = 0U;
  c13_info[18].fileTime2 = 0U;
  c13_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c13_info[19].name = "not";
  c13_info[19].dominantType = "logical";
  c13_info[19].resolved = "[B]not";
  c13_info[19].fileLength = 0U;
  c13_info[19].fileTime1 = 0U;
  c13_info[19].fileTime2 = 0U;
  c13_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c13_info[20].name = "isnan";
  c13_info[20].dominantType = "double";
  c13_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c13_info[20].fileLength = 506U;
  c13_info[20].fileTime1 = 1228077610U;
  c13_info[20].fileTime2 = 0U;
  c13_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c13_info[21].name = "isreal";
  c13_info[21].dominantType = "double";
  c13_info[21].resolved = "[B]isreal";
  c13_info[21].fileLength = 0U;
  c13_info[21].fileTime1 = 0U;
  c13_info[21].fileTime2 = 0U;
  c13_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[22].name = "eml_index_class";
  c13_info[22].dominantType = "";
  c13_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c13_info[22].fileLength = 909U;
  c13_info[22].fileTime1 = 1192454182U;
  c13_info[22].fileTime2 = 0U;
  c13_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[23].name = "ones";
  c13_info[23].dominantType = "char";
  c13_info[23].resolved = "[B]ones";
  c13_info[23].fileLength = 0U;
  c13_info[23].fileTime1 = 0U;
  c13_info[23].fileTime2 = 0U;
  c13_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[24].name = "isfloat";
  c13_info[24].dominantType = "double";
  c13_info[24].resolved = "[B]isfloat";
  c13_info[24].fileLength = 0U;
  c13_info[24].fileTime1 = 0U;
  c13_info[24].fileTime2 = 0U;
  c13_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[25].name = "eml_scalar_eg";
  c13_info[25].dominantType = "double";
  c13_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[25].fileLength = 3068U;
  c13_info[25].fileTime1 = 1240249410U;
  c13_info[25].fileTime2 = 0U;
  c13_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c13_info[26].name = "class";
  c13_info[26].dominantType = "double";
  c13_info[26].resolved = "[B]class";
  c13_info[26].fileLength = 0U;
  c13_info[26].fileTime1 = 0U;
  c13_info[26].fileTime2 = 0U;
  c13_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c13_info[27].name = "cast";
  c13_info[27].dominantType = "double";
  c13_info[27].resolved = "[B]cast";
  c13_info[27].fileLength = 0U;
  c13_info[27].fileTime1 = 0U;
  c13_info[27].fileTime2 = 0U;
  c13_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c13_info[28].name = "plus";
  c13_info[28].dominantType = "double";
  c13_info[28].resolved = "[B]plus";
  c13_info[28].fileLength = 0U;
  c13_info[28].fileTime1 = 0U;
  c13_info[28].fileTime2 = 0U;
  c13_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[29].name = "lt";
  c13_info[29].dominantType = "double";
  c13_info[29].resolved = "[B]lt";
  c13_info[29].fileLength = 0U;
  c13_info[29].fileTime1 = 0U;
  c13_info[29].fileTime2 = 0U;
  c13_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c13_info[30].name = "isvector";
  c13_info[30].dominantType = "double";
  c13_info[30].resolved = "[B]isvector";
  c13_info[30].fileLength = 0U;
  c13_info[30].fileTime1 = 0U;
  c13_info[30].fileTime2 = 0U;
  c13_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c13_info[31].name = "eml_xdotc";
  c13_info[31].dominantType = "int32";
  c13_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c13_info[31].fileLength = 1453U;
  c13_info[31].fileTime1 = 1209318250U;
  c13_info[31].fileTime2 = 0U;
  c13_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c13_info[32].name = "eml_xdot";
  c13_info[32].dominantType = "int32";
  c13_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c13_info[32].fileLength = 1330U;
  c13_info[32].fileTime1 = 1209318250U;
  c13_info[32].fileTime2 = 0U;
  c13_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c13_info[33].name = "strcmp";
  c13_info[33].dominantType = "char";
  c13_info[33].resolved = "[B]strcmp";
  c13_info[33].fileLength = 0U;
  c13_info[33].fileTime1 = 0U;
  c13_info[33].fileTime2 = 0U;
  c13_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c13_info[34].name = "eml_refblas_xdot";
  c13_info[34].dominantType = "int32";
  c13_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c13_info[34].fileLength = 343U;
  c13_info[34].fileTime1 = 1211203444U;
  c13_info[34].fileTime2 = 0U;
  c13_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c13_info[35].name = "eml_refblas_xdotx";
  c13_info[35].dominantType = "int32";
  c13_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c13_info[35].fileLength = 1605U;
  c13_info[35].fileTime1 = 1236241080U;
  c13_info[35].fileTime2 = 0U;
  c13_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c13_info[36].name = "ischar";
  c13_info[36].dominantType = "char";
  c13_info[36].resolved = "[B]ischar";
  c13_info[36].fileLength = 0U;
  c13_info[36].fileTime1 = 0U;
  c13_info[36].fileTime2 = 0U;
  c13_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c13_info[37].name = "times";
  c13_info[37].dominantType = "double";
  c13_info[37].resolved = "[B]times";
  c13_info[37].fileLength = 0U;
  c13_info[37].fileTime1 = 0U;
  c13_info[37].fileTime2 = 0U;
  c13_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c13_info[38].name = "uminus";
  c13_info[38].dominantType = "int32";
  c13_info[38].resolved = "[B]uminus";
  c13_info[38].fileLength = 0U;
  c13_info[38].fileTime1 = 0U;
  c13_info[38].fileTime2 = 0U;
  c13_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c13_info[39].name = "eml_index_minus";
  c13_info[39].dominantType = "int32";
  c13_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c13_info[39].fileLength = 277U;
  c13_info[39].fileTime1 = 1192454184U;
  c13_info[39].fileTime2 = 0U;
  c13_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c13_info[40].name = "eml_index_plus";
  c13_info[40].dominantType = "int32";
  c13_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c13_info[40].fileLength = 272U;
  c13_info[40].fileTime1 = 1192454186U;
  c13_info[40].fileTime2 = 0U;
  c13_info[41].context = "";
  c13_info[41].name = "sqrt";
  c13_info[41].dominantType = "double";
  c13_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c13_info[41].fileLength = 572U;
  c13_info[41].fileTime1 = 1203431846U;
  c13_info[41].fileTime2 = 0U;
  c13_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c13_info[42].name = "eml_error";
  c13_info[42].dominantType = "char";
  c13_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c13_info[42].fileLength = 315U;
  c13_info[42].fileTime1 = 1213914146U;
  c13_info[42].fileTime2 = 0U;
  c13_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c13_info[43].name = "eml_scalar_sqrt";
  c13_info[43].dominantType = "double";
  c13_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c13_info[43].fileLength = 664U;
  c13_info[43].fileTime1 = 1209318194U;
  c13_info[43].fileTime2 = 0U;
  c13_info[44].context = "";
  c13_info[44].name = "mrdivide";
  c13_info[44].dominantType = "double";
  c13_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c13_info[44].fileLength = 800U;
  c13_info[44].fileTime1 = 1238421692U;
  c13_info[44].fileTime2 = 0U;
  c13_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c13_info[45].name = "rdivide";
  c13_info[45].dominantType = "double";
  c13_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c13_info[45].fileLength = 620U;
  c13_info[45].fileTime1 = 1213914166U;
  c13_info[45].fileTime2 = 0U;
  c13_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c13_info[46].name = "eml_warning";
  c13_info[46].dominantType = "char";
  c13_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c13_info[46].fileLength = 262U;
  c13_info[46].fileTime1 = 1236241078U;
  c13_info[46].fileTime2 = 0U;
  c13_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c13_info[47].name = "eml_div";
  c13_info[47].dominantType = "double";
  c13_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c13_info[47].fileLength = 4269U;
  c13_info[47].fileTime1 = 1228077626U;
  c13_info[47].fileTime2 = 0U;
  c13_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c13_info[48].name = "isinteger";
  c13_info[48].dominantType = "double";
  c13_info[48].resolved = "[B]isinteger";
  c13_info[48].fileLength = 0U;
  c13_info[48].fileTime1 = 0U;
  c13_info[48].fileTime2 = 0U;
  c13_info[49].context = "";
  c13_info[49].name = "mtimes";
  c13_info[49].dominantType = "double";
  c13_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[49].fileLength = 3302U;
  c13_info[49].fileTime1 = 1242738294U;
  c13_info[49].fileTime2 = 0U;
  c13_info[50].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[50].name = "le";
  c13_info[50].dominantType = "double";
  c13_info[50].resolved = "[B]le";
  c13_info[50].fileLength = 0U;
  c13_info[50].fileTime1 = 0U;
  c13_info[50].fileTime2 = 0U;
  c13_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[51].name = "eml_xgemm";
  c13_info[51].dominantType = "int32";
  c13_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c13_info[51].fileLength = 3184U;
  c13_info[51].fileTime1 = 1209318252U;
  c13_info[51].fileTime2 = 0U;
  c13_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c13_info[52].name = "length";
  c13_info[52].dominantType = "double";
  c13_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c13_info[52].fileLength = 326U;
  c13_info[52].fileTime1 = 1226561076U;
  c13_info[52].fileTime2 = 0U;
  c13_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c13_info[53].name = "min";
  c13_info[53].dominantType = "double";
  c13_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c13_info[53].fileLength = 308U;
  c13_info[53].fileTime1 = 1192454034U;
  c13_info[53].fileTime2 = 0U;
  c13_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c13_info[54].name = "nargout";
  c13_info[54].dominantType = "";
  c13_info[54].resolved = "[B]nargout";
  c13_info[54].fileLength = 0U;
  c13_info[54].fileTime1 = 0U;
  c13_info[54].fileTime2 = 0U;
  c13_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c13_info[55].name = "eml_min_or_max";
  c13_info[55].dominantType = "char";
  c13_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[55].fileLength = 9969U;
  c13_info[55].fileTime1 = 1240249408U;
  c13_info[55].fileTime2 = 0U;
  c13_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c13_info[56].name = "eml_scalexp_alloc";
  c13_info[56].dominantType = "double";
  c13_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c13_info[56].fileLength = 808U;
  c13_info[56].fileTime1 = 1230478500U;
  c13_info[56].fileTime2 = 0U;
  c13_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c13_info[57].name = "eml_refblas_xgemm";
  c13_info[57].dominantType = "int32";
  c13_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c13_info[57].fileLength = 5748U;
  c13_info[57].fileTime1 = 1228077674U;
  c13_info[57].fileTime2 = 0U;
  c13_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c13_info[58].name = "eml_index_times";
  c13_info[58].dominantType = "int32";
  c13_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c13_info[58].fileLength = 280U;
  c13_info[58].fileTime1 = 1192454188U;
  c13_info[58].fileTime2 = 0U;
  c13_info[59].context = "";
  c13_info[59].name = "mpower";
  c13_info[59].dominantType = "double";
  c13_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c13_info[59].fileLength = 3710U;
  c13_info[59].fileTime1 = 1238421690U;
  c13_info[59].fileTime2 = 0U;
  c13_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c13_info[60].name = "power";
  c13_info[60].dominantType = "double";
  c13_info[60].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c13_info[60].fileLength = 5380U;
  c13_info[60].fileTime1 = 1228077698U;
  c13_info[60].fileTime2 = 0U;
  c13_info[61].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c13_info[61].name = "eml_scalar_floor";
  c13_info[61].dominantType = "double";
  c13_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c13_info[61].fileLength = 260U;
  c13_info[61].fileTime1 = 1209318190U;
  c13_info[61].fileTime2 = 0U;
  c13_info[62].context = "";
  c13_info[62].name = "cross";
  c13_info[62].dominantType = "double";
  c13_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c13_info[62].fileLength = 3157U;
  c13_info[62].fileTime1 = 1240249462U;
  c13_info[62].fileTime2 = 0U;
}

static const mxArray *c13_e_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  boolean_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  c13_b_u = *((boolean_T *)c13_u);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c13_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2379712254U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3001806973U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2736611477U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2546805965U);
}

mxArray *sf_c13_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(708778027U);
    pr[1] = (double)(824937060U);
    pr[2] = (double)(1359015868U);
    pr[3] = (double)(3694731144U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c13_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[16],T\"eu\",},{M[1],M[22],T\"ieu\",},{M[1],M[15],T\"m\",},{M[1],M[5],T\"m_N\",},{M[8],M[0],T\"is_active_c13_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           13,
           1,
           1,
           13,
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
                                1.0,0,"ieu",0,(MexFcnForType)c13_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ieu_prev",0,(MexFcnForType)
                                c13_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eu",0,(MexFcnForType)c13_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m",0,(MexFcnForType)c13_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"light",0,
                              (MexFcnForType)c13_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w",0,(MexFcnForType)c13_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_N",0,(MexFcnForType)c13_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_B",0,(MexFcnForType)c13_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(8,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Kp",0,(MexFcnForType)c13_c_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(9,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Kd",0,(MexFcnForType)c13_c_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(10,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Ki",0,(MexFcnForType)c13_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q",0,(MexFcnForType)c13_d_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(12,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_FRAME_SIZE",0,(MexFcnForType)c13_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,505);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c13_ieu)[3];
          real_T (*c13_ieu_prev)[3];
          real_T (*c13_eu)[3];
          real_T (*c13_m)[3];
          real_T *c13_light;
          real_T (*c13_w)[3];
          real_T (*c13_m_N)[3];
          real_T (*c13_v_B)[3];
          real_T (*c13_q)[4];
          c13_ieu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c13_ieu_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c13_w = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
          c13_m_N = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
          c13_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 3);
          c13_m = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
          c13_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 4);
          c13_eu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
          c13_light = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_ieu);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_ieu_prev);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_eu);
          _SFD_SET_DATA_VALUE_PTR(3U, c13_m);
          _SFD_SET_DATA_VALUE_PTR(4U, c13_light);
          _SFD_SET_DATA_VALUE_PTR(5U, c13_w);
          _SFD_SET_DATA_VALUE_PTR(6U, c13_m_N);
          _SFD_SET_DATA_VALUE_PTR(7U, c13_v_B);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance.c13_Kp);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance.c13_Kd);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance.c13_Ki);
          _SFD_SET_DATA_VALUE_PTR(11U, c13_q);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance.c13_s_FRAME_SIZE);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c13_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c13_adcs_v15_integral_Power();
  initialize_c13_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c13_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c13_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c13_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c13_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c13_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c13_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c13_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c13_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c13_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c13_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c13_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c13_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c13_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c13_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c13_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     Kd Ki Kp s_FRAME_SIZE
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Kd*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Ki*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Kp*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for s_FRAME_SIZE*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",13,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",13,5);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",13,4);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(15027730U));
  ssSetChecksum1(S,(4117886677U));
  ssSetChecksum2(S,(2810786436U));
  ssSetChecksum3(S,(2363021319U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c13_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",13);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c13_adcs_v15_integral_Power;
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

void c13_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
