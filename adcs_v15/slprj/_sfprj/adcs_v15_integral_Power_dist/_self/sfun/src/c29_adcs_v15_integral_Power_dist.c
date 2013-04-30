/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_dist_sfun.h"
#include "c29_adcs_v15_integral_Power_dist.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_dist_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c29_IN_NO_ACTIVE_CHILD         (0)
#define c29_b_s_W_SAT                  (1.0345212007894661E-003)

/* Variable Declarations */

/* Variable Definitions */
static SFc29_adcs_v15_integral_Power_distInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c29_adcs_v15_integral_Power_dist(void);
static void initialize_params_c29_adcs_v15_integral_Power_dist(void);
static void enable_c29_adcs_v15_integral_Power_dist(void);
static void disable_c29_adcs_v15_integral_Power_dist(void);
static void c29_update_debugger_state_c29_adcs_v15_integral_Power_dist(void);
static void ext_mode_exec_c29_adcs_v15_integral_Power_dist(void);
static const mxArray *get_sim_state_c29_adcs_v15_integral_Power_dist(void);
static void set_sim_state_c29_adcs_v15_integral_Power_dist(const mxArray *c29_st);
static void finalize_c29_adcs_v15_integral_Power_dist(void);
static void sf_c29_adcs_v15_integral_Power_dist(void);
static void c29_c29_adcs_v15_integral_Power_dist(void);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber);
static void c29_cross(real_T c29_a[3], real_T c29_b[3], real_T c29_c[3]);
static real_T c29_dot(real_T c29_a[3], real_T c29_b[3]);
static void c29_eml_scalar_eg(void);
static real_T c29_ceval_xdot(int32_T c29_n, real_T c29_x[3], int32_T c29_ix0,
  int32_T c29_incx, real_T c29_y[3], int32_T c29_iy0, int32_T c29_incy);
static real_T c29_sqrt(real_T c29_x);
static void c29_eml_error(void);
static void c29_mrdivide(real_T c29_A[3], real_T c29_B, real_T c29_y[3]);
static void c29_eml_warning(void);
static real_T c29_trace(real_T c29_a[9]);
static void c29_b_mrdivide(real_T c29_A[4], real_T c29_B, real_T c29_y[4]);
static real_T c29_c_mrdivide(real_T c29_A, real_T c29_B);
static void c29_b_eml_scalar_eg(void);
static void c29_c_eml_scalar_eg(void);
static real_T c29_mpower(real_T c29_a);
static real_T c29_atan2(real_T c29_y, real_T c29_x);
static real_T c29_asin(real_T c29_x);
static void c29_b_eml_error(void);
static void c29_d_eml_scalar_eg(void);
static const mxArray *c29_sf_marshall(void *c29_chartInstance, void *c29_u);
static const mxArray *c29_b_sf_marshall(void *c29_chartInstance, void *c29_u);
static const mxArray *c29_c_sf_marshall(void *c29_chartInstance, void *c29_u);
static const mxArray *c29_d_sf_marshall(void *c29_chartInstance, void *c29_u);
static const mxArray *c29_e_sf_marshall(void *c29_chartInstance, void *c29_u);
static const mxArray *c29_f_sf_marshall(void *c29_chartInstance, void *c29_u);
static const mxArray *c29_g_sf_marshall(void *c29_chartInstance, void *c29_u);
static void c29_info_helper(c29_ResolvedFunctionInfo c29_info[69]);
static const mxArray *c29_h_sf_marshall(void *c29_chartInstance, void *c29_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c29_adcs_v15_integral_Power_dist(void)
{
  uint8_T *c29_is_active_c29_adcs_v15_integral_Power_dist;
  c29_is_active_c29_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c29_is_active_c29_adcs_v15_integral_Power_dist = 0U;
}

static void initialize_params_c29_adcs_v15_integral_Power_dist(void)
{
  real_T c29_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_W_SAT' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c29_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c29_s_W_SAT = c29_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c29_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c29_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c29_update_debugger_state_c29_adcs_v15_integral_Power_dist(void)
{
}

static void ext_mode_exec_c29_adcs_v15_integral_Power_dist(void)
{
  c29_update_debugger_state_c29_adcs_v15_integral_Power_dist();
}

static const mxArray *get_sim_state_c29_adcs_v15_integral_Power_dist(void)
{
  const mxArray *c29_st = NULL;
  const mxArray *c29_y = NULL;
  int32_T c29_i0;
  real_T c29_u[3];
  const mxArray *c29_b_y = NULL;
  real_T c29_b_u;
  const mxArray *c29_c_y = NULL;
  int32_T c29_i1;
  real_T c29_c_u[4];
  const mxArray *c29_d_y = NULL;
  int32_T c29_i2;
  real_T c29_d_u[3];
  const mxArray *c29_e_y = NULL;
  int32_T c29_i3;
  real_T c29_e_u[3];
  const mxArray *c29_f_y = NULL;
  uint8_T c29_f_u;
  const mxArray *c29_g_y = NULL;
  real_T *c29_modw;
  uint8_T *c29_is_active_c29_adcs_v15_integral_Power_dist;
  real_T (*c29_w_BOB)[3];
  real_T (*c29_w_BIB)[3];
  real_T (*c29_q_BO)[4];
  real_T (*c29_euler)[3];
  c29_is_active_c29_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c29_modw = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c29_w_BOB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c29_q_BO = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 2);
  c29_w_BIB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c29_euler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c29_st = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_createcellarray(6));
  for (c29_i0 = 0; c29_i0 < 3; c29_i0 = c29_i0 + 1) {
    c29_u[c29_i0] = (*c29_euler)[c29_i0];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c29_y, 0, c29_b_y);
  c29_b_u = *c29_modw;
  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", &c29_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c29_y, 1, c29_c_y);
  for (c29_i1 = 0; c29_i1 < 4; c29_i1 = c29_i1 + 1) {
    c29_c_u[c29_i1] = (*c29_q_BO)[c29_i1];
  }

  c29_d_y = NULL;
  sf_mex_assign(&c29_d_y, sf_mex_create("y", &c29_c_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c29_y, 2, c29_d_y);
  for (c29_i2 = 0; c29_i2 < 3; c29_i2 = c29_i2 + 1) {
    c29_d_u[c29_i2] = (*c29_w_BIB)[c29_i2];
  }

  c29_e_y = NULL;
  sf_mex_assign(&c29_e_y, sf_mex_create("y", &c29_d_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c29_y, 3, c29_e_y);
  for (c29_i3 = 0; c29_i3 < 3; c29_i3 = c29_i3 + 1) {
    c29_e_u[c29_i3] = (*c29_w_BOB)[c29_i3];
  }

  c29_f_y = NULL;
  sf_mex_assign(&c29_f_y, sf_mex_create("y", &c29_e_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c29_y, 4, c29_f_y);
  c29_f_u = *c29_is_active_c29_adcs_v15_integral_Power_dist;
  c29_g_y = NULL;
  sf_mex_assign(&c29_g_y, sf_mex_create("y", &c29_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c29_y, 5, c29_g_y);
  sf_mex_assign(&c29_st, c29_y);
  return c29_st;
}

static void set_sim_state_c29_adcs_v15_integral_Power_dist(const mxArray *c29_st)
{
  const mxArray *c29_u;
  const mxArray *c29_euler;
  real_T c29_dv0[3];
  int32_T c29_i4;
  real_T c29_y[3];
  int32_T c29_i5;
  const mxArray *c29_modw;
  real_T c29_d1;
  real_T c29_b_y;
  const mxArray *c29_q_BO;
  real_T c29_dv1[4];
  int32_T c29_i6;
  real_T c29_c_y[4];
  int32_T c29_i7;
  const mxArray *c29_b_euler;
  real_T c29_dv2[3];
  int32_T c29_i8;
  real_T c29_d_y[3];
  int32_T c29_i9;
  const mxArray *c29_c_euler;
  real_T c29_dv3[3];
  int32_T c29_i10;
  real_T c29_e_y[3];
  int32_T c29_i11;
  const mxArray *c29_is_active_c29_adcs_v15_integral_Power_dist;
  uint8_T c29_u0;
  uint8_T c29_f_y;
  boolean_T *c29_doneDoubleBufferReInit;
  real_T *c29_b_modw;
  uint8_T *c29_b_is_active_c29_adcs_v15_integral_Power_dist;
  real_T (*c29_d_euler)[3];
  real_T (*c29_b_q_BO)[4];
  real_T (*c29_w_BIB)[3];
  real_T (*c29_w_BOB)[3];
  c29_b_is_active_c29_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c29_b_modw = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c29_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c29_w_BOB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c29_b_q_BO = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 2);
  c29_w_BIB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c29_d_euler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  *c29_doneDoubleBufferReInit = true;
  c29_u = sf_mex_dup(c29_st);
  c29_euler = sf_mex_dup(sf_mex_getcell(c29_u, 0));
  sf_mex_import("euler", sf_mex_dup(c29_euler), &c29_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c29_i4 = 0; c29_i4 < 3; c29_i4 = c29_i4 + 1) {
    c29_y[c29_i4] = c29_dv0[c29_i4];
  }

  sf_mex_destroy(&c29_euler);
  for (c29_i5 = 0; c29_i5 < 3; c29_i5 = c29_i5 + 1) {
    (*c29_d_euler)[c29_i5] = c29_y[c29_i5];
  }

  c29_modw = sf_mex_dup(sf_mex_getcell(c29_u, 1));
  sf_mex_import("modw", sf_mex_dup(c29_modw), &c29_d1, 1, 0, 0U, 0, 0U, 0);
  c29_b_y = c29_d1;
  sf_mex_destroy(&c29_modw);
  *c29_b_modw = c29_b_y;
  c29_q_BO = sf_mex_dup(sf_mex_getcell(c29_u, 2));
  sf_mex_import("q_BO", sf_mex_dup(c29_q_BO), &c29_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c29_i6 = 0; c29_i6 < 4; c29_i6 = c29_i6 + 1) {
    c29_c_y[c29_i6] = c29_dv1[c29_i6];
  }

  sf_mex_destroy(&c29_q_BO);
  for (c29_i7 = 0; c29_i7 < 4; c29_i7 = c29_i7 + 1) {
    (*c29_b_q_BO)[c29_i7] = c29_c_y[c29_i7];
  }

  c29_b_euler = sf_mex_dup(sf_mex_getcell(c29_u, 3));
  sf_mex_import("w_BIB", sf_mex_dup(c29_b_euler), &c29_dv2, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c29_i8 = 0; c29_i8 < 3; c29_i8 = c29_i8 + 1) {
    c29_d_y[c29_i8] = c29_dv2[c29_i8];
  }

  sf_mex_destroy(&c29_b_euler);
  for (c29_i9 = 0; c29_i9 < 3; c29_i9 = c29_i9 + 1) {
    (*c29_w_BIB)[c29_i9] = c29_d_y[c29_i9];
  }

  c29_c_euler = sf_mex_dup(sf_mex_getcell(c29_u, 4));
  sf_mex_import("w_BOB", sf_mex_dup(c29_c_euler), &c29_dv3, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c29_i10 = 0; c29_i10 < 3; c29_i10 = c29_i10 + 1) {
    c29_e_y[c29_i10] = c29_dv3[c29_i10];
  }

  sf_mex_destroy(&c29_c_euler);
  for (c29_i11 = 0; c29_i11 < 3; c29_i11 = c29_i11 + 1) {
    (*c29_w_BOB)[c29_i11] = c29_e_y[c29_i11];
  }

  c29_is_active_c29_adcs_v15_integral_Power_dist = sf_mex_dup(sf_mex_getcell
    (c29_u, 5));
  sf_mex_import("is_active_c29_adcs_v15_integral_Power_dist", sf_mex_dup
                (c29_is_active_c29_adcs_v15_integral_Power_dist), &c29_u0, 1,
                3, 0U, 0, 0U, 0);
  c29_f_y = c29_u0;
  sf_mex_destroy(&c29_is_active_c29_adcs_v15_integral_Power_dist);
  *c29_b_is_active_c29_adcs_v15_integral_Power_dist = c29_f_y;
  sf_mex_destroy(&c29_u);
  c29_update_debugger_state_c29_adcs_v15_integral_Power_dist();
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_adcs_v15_integral_Power_dist(void)
{
}

static void sf_c29_adcs_v15_integral_Power_dist(void)
{
  int32_T c29_i12;
  int32_T c29_i13;
  int32_T c29_i14;
  int32_T c29_i15;
  int32_T c29_i16;
  int32_T c29_i17;
  int32_T c29_previousEvent;
  real_T *c29_modw;
  real_T (*c29_w_BIB)[3];
  real_T (*c29_w_BOB)[3];
  real_T (*c29_q_BO)[4];
  real_T (*c29_v_Si)[6];
  real_T (*c29_euler)[3];
  real_T (*c29_x)[7];
  c29_modw = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c29_w_BOB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c29_q_BO = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 2);
  c29_w_BIB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c29_v_Si = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c29_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c29_euler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,22);
  for (c29_i12 = 0; c29_i12 < 7; c29_i12 = c29_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c29_x)[c29_i12], 0U);
  }

  for (c29_i13 = 0; c29_i13 < 3; c29_i13 = c29_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c29_euler)[c29_i13], 1U);
  }

  for (c29_i14 = 0; c29_i14 < 6; c29_i14 = c29_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c29_v_Si)[c29_i14], 2U);
  }

  for (c29_i15 = 0; c29_i15 < 4; c29_i15 = c29_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c29_q_BO)[c29_i15], 3U);
  }

  for (c29_i16 = 0; c29_i16 < 3; c29_i16 = c29_i16 + 1) {
    _SFD_DATA_RANGE_CHECK((*c29_w_BOB)[c29_i16], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c29_modw, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c29_s_W_SAT, 6U);
  for (c29_i17 = 0; c29_i17 < 3; c29_i17 = c29_i17 + 1) {
    _SFD_DATA_RANGE_CHECK((*c29_w_BIB)[c29_i17], 7U);
  }

  c29_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c29_c29_adcs_v15_integral_Power_dist();
  _sfEvent_ = c29_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_distMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c29_c29_adcs_v15_integral_Power_dist(void)
{
  int32_T c29_i18;
  real_T c29_x[7];
  int32_T c29_i19;
  real_T c29_v_Si[6];
  real_T c29_nargout = 5.0;
  real_T c29_nargin = 3.0;
  real_T c29_c_s_W_SAT = c29_b_s_W_SAT;
  real_T c29_w_OIB[3];
  real_T c29_TBO[9];
  real_T c29_q0;
  real_T c29_w_OIO[3];
  real_T c29_q_BIx[16];
  real_T c29_q_BI[4];
  real_T c29_q3;
  real_T c29_q2;
  real_T c29_q1;
  real_T c29_q4;
  real_T c29_norm;
  real_T c29_e3;
  real_T c29_e2;
  real_T c29_e1;
  real_T c29_q_IO[4];
  real_T c29_TIO[9];
  real_T c29_ox[3];
  real_T c29_oz[3];
  real_T c29_oy[3];
  real_T c29_v[3];
  real_T c29_r[3];
  real_T c29_w_BIB[3];
  real_T c29_modw;
  real_T c29_w_BOB[3];
  real_T c29_q_BO[4];
  real_T c29_euler[3];
  int32_T c29_i20;
  int32_T c29_i21;
  int32_T c29_i22;
  real_T c29_b_v[3];
  int32_T c29_i23;
  real_T c29_b_r[3];
  real_T c29_dv4[3];
  int32_T c29_i24;
  int32_T c29_i25;
  real_T c29_b_oy[3];
  int32_T c29_i26;
  real_T c29_c_oy[3];
  int32_T c29_i27;
  real_T c29_d_oy[3];
  real_T c29_dv5[3];
  int32_T c29_i28;
  int32_T c29_i29;
  real_T c29_c_r[3];
  int32_T c29_i30;
  real_T c29_d_r[3];
  int32_T c29_i31;
  real_T c29_e_r[3];
  real_T c29_dv6[3];
  int32_T c29_i32;
  int32_T c29_i33;
  real_T c29_e_oy[3];
  int32_T c29_i34;
  real_T c29_b_oz[3];
  real_T c29_dv7[3];
  int32_T c29_i35;
  int32_T c29_i36;
  real_T c29_b_ox[3];
  int32_T c29_i37;
  real_T c29_c_ox[3];
  int32_T c29_i38;
  real_T c29_d_ox[3];
  real_T c29_dv8[3];
  int32_T c29_i39;
  int32_T c29_i40;
  int32_T c29_i41;
  int32_T c29_i42;
  int32_T c29_i43;
  real_T c29_b_TIO[9];
  int32_T c29_i44;
  static real_T c29_dv9[4] = { 1.0, 0.0, 0.0, 0.0 };

  int32_T c29_i45;
  static real_T c29_dv10[4] = { 0.0, 1.0, 0.0, 0.0 };

  int32_T c29_i46;
  static real_T c29_dv11[4] = { 0.0, 0.0, 1.0, 0.0 };

  real_T c29_a;
  real_T c29_b;
  real_T c29_b_a;
  real_T c29_b_b;
  real_T c29_c_a;
  real_T c29_c_b;
  real_T c29_d_a;
  real_T c29_d_b;
  real_T c29_y;
  real_T c29_e_a;
  real_T c29_e_b;
  real_T c29_b_y;
  real_T c29_f_a;
  real_T c29_f_b;
  real_T c29_c_y;
  real_T c29_b_e1[4];
  real_T c29_dv12[4];
  int32_T c29_i47;
  int32_T c29_i48;
  real_T c29_c_TIO[9];
  real_T c29_g_b;
  real_T c29_h_b;
  real_T c29_d_y;
  real_T c29_i_b;
  real_T c29_e_y;
  real_T c29_j_b;
  real_T c29_f_y;
  int32_T c29_i49;
  int32_T c29_i50;
  real_T c29_g_a[16];
  int32_T c29_i51;
  real_T c29_k_b[4];
  int32_T c29_i52;
  real_T c29_A[16];
  int32_T c29_i53;
  real_T c29_B[4];
  int32_T c29_i54;
  int32_T c29_i55;
  real_T c29_b_A[16];
  int32_T c29_i56;
  real_T c29_b_B[4];
  int32_T c29_i57;
  real_T c29_c_A[16];
  int32_T c29_i58;
  real_T c29_c_B[4];
  int32_T c29_i59;
  int32_T c29_i60;
  int32_T c29_i61;
  real_T c29_l_b;
  real_T c29_g_y;
  real_T c29_h_a;
  real_T c29_m_b;
  real_T c29_h_y;
  real_T c29_i_a;
  real_T c29_n_b;
  real_T c29_i_y;
  real_T c29_o_b;
  real_T c29_j_y;
  real_T c29_j_a;
  real_T c29_p_b;
  real_T c29_k_y;
  real_T c29_k_a;
  real_T c29_q_b;
  real_T c29_l_y;
  real_T c29_r_b;
  real_T c29_m_y;
  real_T c29_s_b;
  real_T c29_n_y;
  real_T c29_l_a;
  real_T c29_t_b;
  real_T c29_o_y;
  real_T c29_m_a;
  real_T c29_u_b;
  real_T c29_p_y;
  real_T c29_v_b;
  real_T c29_q_y;
  real_T c29_d2;
  real_T c29_d3;
  real_T c29_d4;
  real_T c29_w_b[3];
  int32_T c29_i62;
  int32_T c29_i63;
  int32_T c29_i64;
  static real_T c29_dv13[3] = { 0.0, -1.0345212007894661E-003, 0.0 };

  real_T c29_x_b;
  real_T c29_n_a;
  real_T c29_y_b;
  real_T c29_r_y;
  real_T c29_ab_b;
  real_T c29_o_a;
  real_T c29_bb_b;
  real_T c29_s_y;
  real_T c29_cb_b;
  real_T c29_p_a;
  real_T c29_db_b;
  real_T c29_t_y;
  real_T c29_eb_b;
  real_T c29_q_a;
  real_T c29_fb_b;
  real_T c29_u_y;
  real_T c29_gb_b;
  real_T c29_r_a;
  real_T c29_hb_b;
  real_T c29_v_y;
  real_T c29_ib_b;
  real_T c29_s_a;
  real_T c29_jb_b;
  real_T c29_w_y;
  real_T c29_kb_b;
  real_T c29_t_a;
  real_T c29_lb_b;
  real_T c29_x_y;
  real_T c29_mb_b;
  real_T c29_u_a;
  real_T c29_nb_b;
  real_T c29_y_y;
  real_T c29_ob_b;
  real_T c29_v_a;
  real_T c29_pb_b;
  real_T c29_ab_y;
  real_T c29_qb_b;
  real_T c29_w_a;
  real_T c29_rb_b;
  real_T c29_bb_y;
  real_T c29_sb_b;
  real_T c29_x_a;
  real_T c29_tb_b;
  real_T c29_cb_y;
  real_T c29_ub_b;
  real_T c29_y_a;
  real_T c29_vb_b;
  real_T c29_db_y;
  real_T c29_d5;
  real_T c29_d6;
  real_T c29_d7;
  int32_T c29_i65;
  real_T c29_ab_a[9];
  int32_T c29_i66;
  real_T c29_d_A[9];
  int32_T c29_i67;
  int32_T c29_i68;
  real_T c29_e_A[9];
  int32_T c29_i69;
  real_T c29_f_A[9];
  int32_T c29_i70;
  int32_T c29_i71;
  int32_T c29_i72;
  int32_T c29_i73;
  int32_T c29_i74;
  real_T c29_b_w_BOB[3];
  int32_T c29_i75;
  real_T c29_c_w_BOB[3];
  real_T c29_b_x;
  real_T c29_c_x;
  int32_T c29_i76;
  int32_T c29_i77;
  int32_T c29_i78;
  int32_T c29_i79;
  real_T *c29_b_modw;
  real_T (*c29_b_euler)[3];
  real_T (*c29_b_q_BO)[4];
  real_T (*c29_d_w_BOB)[3];
  real_T (*c29_b_w_BIB)[3];
  real_T (*c29_b_v_Si)[6];
  real_T (*c29_d_x)[7];
  c29_b_modw = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c29_d_w_BOB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c29_b_q_BO = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 2);
  c29_b_w_BIB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c29_b_v_Si = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c29_d_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c29_b_euler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,22);
  for (c29_i18 = 0; c29_i18 < 7; c29_i18 = c29_i18 + 1) {
    c29_x[c29_i18] = (*c29_d_x)[c29_i18];
  }

  for (c29_i19 = 0; c29_i19 < 6; c29_i19 = c29_i19 + 1) {
    c29_v_Si[c29_i19] = (*c29_b_v_Si)[c29_i19];
  }

  sf_debug_symbol_scope_push(31U, 0U);
  sf_debug_symbol_scope_add("nargout", &c29_nargout, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c29_nargin, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("s_W_SAT", &c29_c_s_W_SAT, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("w_OIB", &c29_w_OIB, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("TBO", &c29_TBO, c29_f_sf_marshall);
  sf_debug_symbol_scope_add("q0", &c29_q0, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("w_OIO", &c29_w_OIO, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("q_BIx", &c29_q_BIx, c29_g_sf_marshall);
  sf_debug_symbol_scope_add("q_BI", &c29_q_BI, c29_d_sf_marshall);
  sf_debug_symbol_scope_add("q3", &c29_q3, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("q2", &c29_q2, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("q1", &c29_q1, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("q4", &c29_q4, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("norm", &c29_norm, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("e3", &c29_e3, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("e2", &c29_e2, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("e1", &c29_e1, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("q_IO", &c29_q_IO, c29_d_sf_marshall);
  sf_debug_symbol_scope_add("TIO", &c29_TIO, c29_f_sf_marshall);
  sf_debug_symbol_scope_add("ox", &c29_ox, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("oz", &c29_oz, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("oy", &c29_oy, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("v", &c29_v, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("r", &c29_r, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("w_BIB", &c29_w_BIB, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("modw", &c29_modw, c29_e_sf_marshall);
  sf_debug_symbol_scope_add("w_BOB", &c29_w_BOB, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("q_BO", &c29_q_BO, c29_d_sf_marshall);
  sf_debug_symbol_scope_add("euler", &c29_euler, c29_c_sf_marshall);
  sf_debug_symbol_scope_add("v_Si", &c29_v_Si, c29_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c29_x, c29_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /*  ECI to TIO  */
  _SFD_EML_CALL(0,6);
  for (c29_i20 = 0; c29_i20 < 3; c29_i20 = c29_i20 + 1) {
    c29_r[c29_i20] = c29_v_Si[c29_i20];
  }

  /*  position vector in ECI */
  _SFD_EML_CALL(0,7);
  for (c29_i21 = 0; c29_i21 < 3; c29_i21 = c29_i21 + 1) {
    c29_v[c29_i21] = c29_v_Si[c29_i21 + 3];
  }

  /*  velocity vector in ECI */
  _SFD_EML_CALL(0,9);
  for (c29_i22 = 0; c29_i22 < 3; c29_i22 = c29_i22 + 1) {
    c29_b_v[c29_i22] = c29_v[c29_i22];
  }

  for (c29_i23 = 0; c29_i23 < 3; c29_i23 = c29_i23 + 1) {
    c29_b_r[c29_i23] = c29_r[c29_i23];
  }

  c29_cross(c29_b_v, c29_b_r, c29_dv4);
  for (c29_i24 = 0; c29_i24 < 3; c29_i24 = c29_i24 + 1) {
    c29_oy[c29_i24] = c29_dv4[c29_i24];
  }

  /*  orbit frame x... */
  _SFD_EML_CALL(0,10);
  for (c29_i25 = 0; c29_i25 < 3; c29_i25 = c29_i25 + 1) {
    c29_b_oy[c29_i25] = c29_oy[c29_i25];
  }

  for (c29_i26 = 0; c29_i26 < 3; c29_i26 = c29_i26 + 1) {
    c29_c_oy[c29_i26] = c29_oy[c29_i26];
  }

  for (c29_i27 = 0; c29_i27 < 3; c29_i27 = c29_i27 + 1) {
    c29_d_oy[c29_i27] = c29_oy[c29_i27];
  }

  c29_mrdivide(c29_d_oy, c29_sqrt(c29_dot(c29_b_oy, c29_c_oy)), c29_dv5);
  for (c29_i28 = 0; c29_i28 < 3; c29_i28 = c29_i28 + 1) {
    c29_oy[c29_i28] = c29_dv5[c29_i28];
  }

  _SFD_EML_CALL(0,12);
  for (c29_i29 = 0; c29_i29 < 3; c29_i29 = c29_i29 + 1) {
    c29_c_r[c29_i29] = c29_r[c29_i29];
  }

  for (c29_i30 = 0; c29_i30 < 3; c29_i30 = c29_i30 + 1) {
    c29_d_r[c29_i30] = c29_r[c29_i30];
  }

  for (c29_i31 = 0; c29_i31 < 3; c29_i31 = c29_i31 + 1) {
    c29_e_r[c29_i31] = -c29_r[c29_i31];
  }

  c29_mrdivide(c29_e_r, c29_sqrt(c29_dot(c29_c_r, c29_d_r)), c29_dv6);
  for (c29_i32 = 0; c29_i32 < 3; c29_i32 = c29_i32 + 1) {
    c29_oz[c29_i32] = c29_dv6[c29_i32];
  }

  _SFD_EML_CALL(0,14);
  for (c29_i33 = 0; c29_i33 < 3; c29_i33 = c29_i33 + 1) {
    c29_e_oy[c29_i33] = c29_oy[c29_i33];
  }

  for (c29_i34 = 0; c29_i34 < 3; c29_i34 = c29_i34 + 1) {
    c29_b_oz[c29_i34] = c29_oz[c29_i34];
  }

  c29_cross(c29_e_oy, c29_b_oz, c29_dv7);
  for (c29_i35 = 0; c29_i35 < 3; c29_i35 = c29_i35 + 1) {
    c29_ox[c29_i35] = c29_dv7[c29_i35];
  }

  _SFD_EML_CALL(0,15);
  for (c29_i36 = 0; c29_i36 < 3; c29_i36 = c29_i36 + 1) {
    c29_b_ox[c29_i36] = c29_ox[c29_i36];
  }

  for (c29_i37 = 0; c29_i37 < 3; c29_i37 = c29_i37 + 1) {
    c29_c_ox[c29_i37] = c29_ox[c29_i37];
  }

  for (c29_i38 = 0; c29_i38 < 3; c29_i38 = c29_i38 + 1) {
    c29_d_ox[c29_i38] = c29_ox[c29_i38];
  }

  c29_mrdivide(c29_d_ox, c29_sqrt(c29_dot(c29_b_ox, c29_c_ox)), c29_dv8);
  for (c29_i39 = 0; c29_i39 < 3; c29_i39 = c29_i39 + 1) {
    c29_ox[c29_i39] = c29_dv8[c29_i39];
  }

  _SFD_EML_CALL(0,17);
  for (c29_i40 = 0; c29_i40 < 3; c29_i40 = c29_i40 + 1) {
    c29_TIO[c29_i40] = c29_ox[c29_i40];
  }

  for (c29_i41 = 0; c29_i41 < 3; c29_i41 = c29_i41 + 1) {
    c29_TIO[c29_i41 + 3] = c29_oy[c29_i41];
  }

  for (c29_i42 = 0; c29_i42 < 3; c29_i42 = c29_i42 + 1) {
    c29_TIO[c29_i42 + 6] = c29_oz[c29_i42];
  }

  /*  qIO from TIO */
  _SFD_EML_CALL(0,20);
  for (c29_i43 = 0; c29_i43 < 9; c29_i43 = c29_i43 + 1) {
    c29_b_TIO[c29_i43] = c29_TIO[c29_i43];
  }

  if (CV_EML_IF(0, 0, c29_trace(c29_b_TIO) == -1.0)) {
    _SFD_EML_CALL(0,21);
    if (CV_EML_COND(0, 0, c29_TIO[3] == 0.0)) {
      if (CV_EML_COND(0, 1, c29_TIO[6] == 0.0)) {
        CV_EML_MCDC(0, 0, true);
        CV_EML_IF(0, 1, true);
        _SFD_EML_CALL(0,22);
        for (c29_i44 = 0; c29_i44 < 4; c29_i44 = c29_i44 + 1) {
          c29_q_IO[c29_i44] = c29_dv9[c29_i44];
        }

        goto label_1;
      }
    }

    CV_EML_MCDC(0, 0, false);
    CV_EML_IF(0, 1, false);
    _SFD_EML_CALL(0,23);
    if (CV_EML_COND(0, 2, c29_TIO[3] == 0.0)) {
      if (CV_EML_COND(0, 3, c29_TIO[7] == 0.0)) {
        CV_EML_MCDC(0, 1, true);
        CV_EML_IF(0, 2, true);
        _SFD_EML_CALL(0,24);
        for (c29_i45 = 0; c29_i45 < 4; c29_i45 = c29_i45 + 1) {
          c29_q_IO[c29_i45] = c29_dv10[c29_i45];
        }

        goto label_2;
      }
    }

    CV_EML_MCDC(0, 1, false);
    CV_EML_IF(0, 2, false);
    _SFD_EML_CALL(0,25);
    if (CV_EML_COND(0, 4, c29_TIO[6] == 0.0)) {
      if (CV_EML_COND(0, 5, c29_TIO[7] == 0.0)) {
        CV_EML_MCDC(0, 2, true);
        CV_EML_IF(0, 3, true);
        _SFD_EML_CALL(0,26);
        for (c29_i46 = 0; c29_i46 < 4; c29_i46 = c29_i46 + 1) {
          c29_q_IO[c29_i46] = c29_dv11[c29_i46];
        }

        goto label_3;
      }
    }

    CV_EML_MCDC(0, 2, false);
    CV_EML_IF(0, 3, false);
    _SFD_EML_CALL(0,28);
    c29_a = c29_TIO[3];
    c29_b = c29_TIO[6];
    c29_e1 = c29_a * c29_b;
    _SFD_EML_CALL(0,29);
    c29_b_a = c29_TIO[3];
    c29_b_b = c29_TIO[7];
    c29_e2 = c29_b_a * c29_b_b;
    _SFD_EML_CALL(0,30);
    c29_c_a = c29_TIO[6];
    c29_c_b = c29_TIO[7];
    c29_e3 = c29_c_a * c29_c_b;
    _SFD_EML_CALL(0,31);
    c29_d_a = c29_e3;
    c29_d_b = c29_e3;
    c29_y = c29_d_a * c29_d_b;
    c29_e_a = c29_e2;
    c29_e_b = c29_e2;
    c29_b_y = c29_e_a * c29_e_b;
    c29_f_a = c29_e1;
    c29_f_b = c29_e1;
    c29_c_y = c29_f_a * c29_f_b;
    c29_norm = c29_sqrt((c29_c_y + c29_b_y) + c29_y);
    _SFD_EML_CALL(0,32);
    c29_b_e1[0] = c29_e1;
    c29_b_e1[1] = c29_e2;
    c29_b_e1[2] = c29_e3;
    c29_b_e1[3] = 0.0;
    c29_b_mrdivide(c29_b_e1, c29_norm, c29_dv12);
    for (c29_i47 = 0; c29_i47 < 4; c29_i47 = c29_i47 + 1) {
      c29_q_IO[c29_i47] = c29_dv12[c29_i47];
    }

   label_3:
    ;
   label_2:
    ;
   label_1:
    ;
  } else {
    _SFD_EML_CALL(0,35);
    for (c29_i48 = 0; c29_i48 < 9; c29_i48 = c29_i48 + 1) {
      c29_c_TIO[c29_i48] = c29_TIO[c29_i48];
    }

    c29_g_b = c29_sqrt(1.0 + c29_trace(c29_c_TIO));
    c29_q4 = 0.5 * c29_g_b;
    _SFD_EML_CALL(0,36);
    c29_h_b = c29_q4;
    c29_d_y = 4.0 * c29_h_b;
    c29_q1 = c29_c_mrdivide(-(c29_TIO[5] - c29_TIO[7]), c29_d_y);
    _SFD_EML_CALL(0,37);
    c29_i_b = c29_q4;
    c29_e_y = 4.0 * c29_i_b;
    c29_q2 = c29_c_mrdivide(-(c29_TIO[6] - c29_TIO[2]), c29_e_y);
    _SFD_EML_CALL(0,38);
    c29_j_b = c29_q4;
    c29_f_y = 4.0 * c29_j_b;
    c29_q3 = c29_c_mrdivide(-(c29_TIO[1] - c29_TIO[3]), c29_f_y);
    _SFD_EML_CALL(0,39);
    c29_q_IO[0] = c29_q1;
    c29_q_IO[1] = c29_q2;
    c29_q_IO[2] = c29_q3;
    c29_q_IO[3] = c29_q4;
  }

  _SFD_EML_CALL(0,42);
  for (c29_i49 = 0; c29_i49 < 4; c29_i49 = c29_i49 + 1) {
    c29_q_BI[c29_i49] = c29_x[c29_i49];
  }

  /*  q_BO = q_BI*q_IO */
  _SFD_EML_CALL(0,45);
  c29_q_BIx[0] = c29_q_BI[3];
  c29_q_BIx[4] = c29_q_BI[2];
  c29_q_BIx[8] = -c29_q_BI[1];
  c29_q_BIx[12] = c29_q_BI[0];
  c29_q_BIx[1] = -c29_q_BI[2];
  c29_q_BIx[5] = c29_q_BI[3];
  c29_q_BIx[9] = c29_q_BI[0];
  c29_q_BIx[13] = c29_q_BI[1];
  c29_q_BIx[2] = c29_q_BI[1];
  c29_q_BIx[6] = -c29_q_BI[0];
  c29_q_BIx[10] = c29_q_BI[3];
  c29_q_BIx[14] = c29_q_BI[2];
  c29_q_BIx[3] = -c29_q_BI[0];
  c29_q_BIx[7] = -c29_q_BI[1];
  c29_q_BIx[11] = -c29_q_BI[2];
  c29_q_BIx[15] = c29_q_BI[3];
  _SFD_EML_CALL(0,51);
  for (c29_i50 = 0; c29_i50 < 16; c29_i50 = c29_i50 + 1) {
    c29_g_a[c29_i50] = c29_q_BIx[c29_i50];
  }

  for (c29_i51 = 0; c29_i51 < 4; c29_i51 = c29_i51 + 1) {
    c29_k_b[c29_i51] = c29_q_IO[c29_i51];
  }

  c29_b_eml_scalar_eg();
  c29_b_eml_scalar_eg();
  for (c29_i52 = 0; c29_i52 < 16; c29_i52 = c29_i52 + 1) {
    c29_A[c29_i52] = c29_g_a[c29_i52];
  }

  for (c29_i53 = 0; c29_i53 < 4; c29_i53 = c29_i53 + 1) {
    c29_B[c29_i53] = c29_k_b[c29_i53];
  }

  for (c29_i54 = 0; c29_i54 < 4; c29_i54 = c29_i54 + 1) {
    c29_q_BO[c29_i54] = 0.0;
  }

  for (c29_i55 = 0; c29_i55 < 16; c29_i55 = c29_i55 + 1) {
    c29_b_A[c29_i55] = c29_A[c29_i55];
  }

  for (c29_i56 = 0; c29_i56 < 4; c29_i56 = c29_i56 + 1) {
    c29_b_B[c29_i56] = c29_B[c29_i56];
  }

  for (c29_i57 = 0; c29_i57 < 16; c29_i57 = c29_i57 + 1) {
    c29_c_A[c29_i57] = c29_b_A[c29_i57];
  }

  for (c29_i58 = 0; c29_i58 < 4; c29_i58 = c29_i58 + 1) {
    c29_c_B[c29_i58] = c29_b_B[c29_i58];
  }

  for (c29_i59 = 0; c29_i59 < 4; c29_i59 = c29_i59 + 1) {
    c29_q_BO[c29_i59] = 0.0;
    c29_i60 = 0;
    for (c29_i61 = 0; c29_i61 < 4; c29_i61 = c29_i61 + 1) {
      c29_q_BO[c29_i59] = c29_q_BO[c29_i59] + c29_c_A[c29_i60 + c29_i59] *
        c29_c_B[c29_i61];
      c29_i60 = c29_i60 + 4;
    }
  }

  _SFD_EML_CALL(0,53);
  c29_l_b = c29_mpower(c29_q_BO[1]) + c29_mpower(c29_q_BO[2]);
  c29_g_y = 2.0 * c29_l_b;
  c29_h_a = c29_q_BO[0];
  c29_m_b = c29_q_BO[1];
  c29_h_y = c29_h_a * c29_m_b;
  c29_i_a = c29_q_BO[3];
  c29_n_b = c29_q_BO[2];
  c29_i_y = c29_i_a * c29_n_b;
  c29_o_b = c29_i_y - c29_h_y;
  c29_j_y = 2.0 * c29_o_b;
  c29_j_a = c29_q_BO[2];
  c29_p_b = c29_q_BO[0];
  c29_k_y = c29_j_a * c29_p_b;
  c29_k_a = c29_q_BO[3];
  c29_q_b = c29_q_BO[1];
  c29_l_y = c29_k_a * c29_q_b;
  c29_r_b = c29_l_y + c29_k_y;
  c29_m_y = 2.0 * c29_r_b;
  c29_s_b = c29_mpower(c29_q_BO[0]) + c29_mpower(c29_q_BO[1]);
  c29_n_y = 2.0 * c29_s_b;
  c29_l_a = c29_q_BO[1];
  c29_t_b = c29_q_BO[2];
  c29_o_y = c29_l_a * c29_t_b;
  c29_m_a = c29_q_BO[3];
  c29_u_b = c29_q_BO[0];
  c29_p_y = c29_m_a * c29_u_b;
  c29_v_b = c29_p_y - c29_o_y;
  c29_q_y = 2.0 * c29_v_b;
  c29_d2 = c29_atan2(c29_q_y, 1.0 - c29_n_y);
  c29_d3 = c29_asin(c29_m_y);
  c29_d4 = c29_atan2(c29_j_y, 1.0 - c29_g_y);
  c29_w_b[0] = c29_d2;
  c29_w_b[1] = c29_d3;
  c29_w_b[2] = c29_d4;
  for (c29_i62 = 0; c29_i62 < 3; c29_i62 = c29_i62 + 1) {
    c29_euler[c29_i62] = 5.7295779513082323E+001 * c29_w_b[c29_i62];
  }

  _SFD_EML_CALL(0,57);
  for (c29_i63 = 0; c29_i63 < 3; c29_i63 = c29_i63 + 1) {
    c29_w_BIB[c29_i63] = c29_x[c29_i63 + 4];
  }

  _SFD_EML_CALL(0,58);
  for (c29_i64 = 0; c29_i64 < 3; c29_i64 = c29_i64 + 1) {
    c29_w_OIO[c29_i64] = c29_dv13[c29_i64];
  }

  _SFD_EML_CALL(0,60);
  c29_q0 = c29_q_BO[3];
  _SFD_EML_CALL(0,60);
  c29_q1 = c29_q_BO[0];
  _SFD_EML_CALL(0,60);
  c29_q2 = c29_q_BO[1];
  _SFD_EML_CALL(0,60);
  c29_q3 = c29_q_BO[2];
  _SFD_EML_CALL(0,62);
  c29_x_b = c29_q0;
  c29_n_a = 2.0 * c29_x_b;
  c29_y_b = c29_q1;
  c29_r_y = c29_n_a * c29_y_b;
  c29_ab_b = c29_q2;
  c29_o_a = 2.0 * c29_ab_b;
  c29_bb_b = c29_q3;
  c29_s_y = c29_o_a * c29_bb_b;
  c29_cb_b = c29_q1;
  c29_p_a = 2.0 * c29_cb_b;
  c29_db_b = c29_q3;
  c29_t_y = c29_p_a * c29_db_b;
  c29_eb_b = c29_q0;
  c29_q_a = 2.0 * c29_eb_b;
  c29_fb_b = c29_q2;
  c29_u_y = c29_q_a * c29_fb_b;
  c29_gb_b = c29_q2;
  c29_r_a = 2.0 * c29_gb_b;
  c29_hb_b = c29_q3;
  c29_v_y = c29_r_a * c29_hb_b;
  c29_ib_b = c29_q0;
  c29_s_a = 2.0 * c29_ib_b;
  c29_jb_b = c29_q1;
  c29_w_y = c29_s_a * c29_jb_b;
  c29_kb_b = c29_q0;
  c29_t_a = 2.0 * c29_kb_b;
  c29_lb_b = c29_q3;
  c29_x_y = c29_t_a * c29_lb_b;
  c29_mb_b = c29_q1;
  c29_u_a = 2.0 * c29_mb_b;
  c29_nb_b = c29_q2;
  c29_y_y = c29_u_a * c29_nb_b;
  c29_ob_b = c29_q0;
  c29_v_a = 2.0 * c29_ob_b;
  c29_pb_b = c29_q2;
  c29_ab_y = c29_v_a * c29_pb_b;
  c29_qb_b = c29_q1;
  c29_w_a = 2.0 * c29_qb_b;
  c29_rb_b = c29_q3;
  c29_bb_y = c29_w_a * c29_rb_b;
  c29_sb_b = c29_q1;
  c29_x_a = 2.0 * c29_sb_b;
  c29_tb_b = c29_q2;
  c29_cb_y = c29_x_a * c29_tb_b;
  c29_ub_b = c29_q0;
  c29_y_a = 2.0 * c29_ub_b;
  c29_vb_b = c29_q3;
  c29_db_y = c29_y_a * c29_vb_b;
  c29_d5 = ((c29_mpower(c29_q0) + c29_mpower(c29_q1)) - c29_mpower(c29_q2)) -
    c29_mpower(c29_q3);
  c29_d6 = ((c29_mpower(c29_q0) - c29_mpower(c29_q1)) + c29_mpower(c29_q2)) -
    c29_mpower(c29_q3);
  c29_d7 = ((c29_mpower(c29_q0) - c29_mpower(c29_q1)) - c29_mpower(c29_q2)) +
    c29_mpower(c29_q3);
  c29_TBO[0] = c29_d5;
  c29_TBO[3] = c29_db_y + c29_cb_y;
  c29_TBO[6] = c29_bb_y - c29_ab_y;
  c29_TBO[1] = c29_y_y - c29_x_y;
  c29_TBO[4] = c29_d6;
  c29_TBO[7] = c29_w_y + c29_v_y;
  c29_TBO[2] = c29_u_y + c29_t_y;
  c29_TBO[5] = c29_s_y - c29_r_y;
  c29_TBO[8] = c29_d7;
  _SFD_EML_CALL(0,66);
  for (c29_i65 = 0; c29_i65 < 9; c29_i65 = c29_i65 + 1) {
    c29_ab_a[c29_i65] = c29_TBO[c29_i65];
  }

  c29_d_eml_scalar_eg();
  c29_d_eml_scalar_eg();
  for (c29_i66 = 0; c29_i66 < 9; c29_i66 = c29_i66 + 1) {
    c29_d_A[c29_i66] = c29_ab_a[c29_i66];
  }

  for (c29_i67 = 0; c29_i67 < 3; c29_i67 = c29_i67 + 1) {
    c29_w_OIB[c29_i67] = 0.0;
  }

  for (c29_i68 = 0; c29_i68 < 9; c29_i68 = c29_i68 + 1) {
    c29_e_A[c29_i68] = c29_d_A[c29_i68];
  }

  for (c29_i69 = 0; c29_i69 < 9; c29_i69 = c29_i69 + 1) {
    c29_f_A[c29_i69] = c29_e_A[c29_i69];
  }

  for (c29_i70 = 0; c29_i70 < 3; c29_i70 = c29_i70 + 1) {
    c29_w_OIB[c29_i70] = 0.0;
    c29_i71 = 0;
    for (c29_i72 = 0; c29_i72 < 3; c29_i72 = c29_i72 + 1) {
      c29_w_OIB[c29_i70] = c29_w_OIB[c29_i70] + c29_f_A[c29_i71 + c29_i70] *
        c29_dv13[c29_i72];
      c29_i71 = c29_i71 + 3;
    }
  }

  _SFD_EML_CALL(0,67);
  for (c29_i73 = 0; c29_i73 < 3; c29_i73 = c29_i73 + 1) {
    c29_w_BOB[c29_i73] = c29_w_BIB[c29_i73] - c29_w_OIB[c29_i73];
  }

  _SFD_EML_CALL(0,69);
  for (c29_i74 = 0; c29_i74 < 3; c29_i74 = c29_i74 + 1) {
    c29_b_w_BOB[c29_i74] = c29_w_BOB[c29_i74];
  }

  for (c29_i75 = 0; c29_i75 < 3; c29_i75 = c29_i75 + 1) {
    c29_c_w_BOB[c29_i75] = c29_w_BOB[c29_i75];
  }

  c29_b_x = c29_dot(c29_b_w_BOB, c29_c_w_BOB);
  c29_modw = c29_b_x;
  if (c29_modw < 0.0) {
    c29_eml_error();
  }

  c29_c_x = c29_modw;
  c29_modw = c29_c_x;
  c29_modw = muDoubleScalarSqrt(c29_modw);
  _SFD_EML_CALL(0,-69);
  sf_debug_symbol_scope_pop();
  for (c29_i76 = 0; c29_i76 < 3; c29_i76 = c29_i76 + 1) {
    (*c29_b_euler)[c29_i76] = c29_euler[c29_i76];
  }

  for (c29_i77 = 0; c29_i77 < 4; c29_i77 = c29_i77 + 1) {
    (*c29_b_q_BO)[c29_i77] = c29_q_BO[c29_i77];
  }

  for (c29_i78 = 0; c29_i78 < 3; c29_i78 = c29_i78 + 1) {
    (*c29_d_w_BOB)[c29_i78] = c29_w_BOB[c29_i78];
  }

  *c29_b_modw = c29_modw;
  for (c29_i79 = 0; c29_i79 < 3; c29_i79 = c29_i79 + 1) {
    (*c29_b_w_BIB)[c29_i79] = c29_w_BIB[c29_i79];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber)
{
}

static void c29_cross(real_T c29_a[3], real_T c29_b[3], real_T c29_c[3])
{
  real_T c29_b_a;
  real_T c29_b_b;
  real_T c29_y;
  real_T c29_c_a;
  real_T c29_c_b;
  real_T c29_b_y;
  real_T c29_c1;
  real_T c29_d_a;
  real_T c29_d_b;
  real_T c29_c_y;
  real_T c29_e_a;
  real_T c29_e_b;
  real_T c29_d_y;
  real_T c29_c2;
  real_T c29_f_a;
  real_T c29_f_b;
  real_T c29_e_y;
  real_T c29_g_a;
  real_T c29_g_b;
  real_T c29_f_y;
  real_T c29_c3;
  c29_b_a = c29_a[2];
  c29_b_b = c29_b[1];
  c29_y = c29_b_a * c29_b_b;
  c29_c_a = c29_a[1];
  c29_c_b = c29_b[2];
  c29_b_y = c29_c_a * c29_c_b;
  c29_c1 = c29_b_y - c29_y;
  c29_d_a = c29_a[0];
  c29_d_b = c29_b[2];
  c29_c_y = c29_d_a * c29_d_b;
  c29_e_a = c29_a[2];
  c29_e_b = c29_b[0];
  c29_d_y = c29_e_a * c29_e_b;
  c29_c2 = c29_d_y - c29_c_y;
  c29_f_a = c29_a[1];
  c29_f_b = c29_b[0];
  c29_e_y = c29_f_a * c29_f_b;
  c29_g_a = c29_a[0];
  c29_g_b = c29_b[1];
  c29_f_y = c29_g_a * c29_g_b;
  c29_c3 = c29_f_y - c29_e_y;
  c29_c[0] = c29_c1;
  c29_c[1] = c29_c2;
  c29_c[2] = c29_c3;
}

static real_T c29_dot(real_T c29_a[3], real_T c29_b[3])
{
  int32_T c29_i80;
  real_T c29_b_a[3];
  int32_T c29_i81;
  real_T c29_b_b[3];
  int32_T c29_i82;
  real_T c29_x[3];
  int32_T c29_i83;
  real_T c29_y[3];
  int32_T c29_i84;
  real_T c29_b_x[3];
  int32_T c29_i85;
  real_T c29_b_y[3];
  int32_T c29_i86;
  real_T c29_c_x[3];
  int32_T c29_i87;
  real_T c29_c_y[3];
  int32_T c29_i88;
  real_T c29_d_x[3];
  int32_T c29_i89;
  real_T c29_d_y[3];
  c29_eml_scalar_eg();
  for (c29_i80 = 0; c29_i80 < 3; c29_i80 = c29_i80 + 1) {
    c29_b_a[c29_i80] = c29_a[c29_i80];
  }

  for (c29_i81 = 0; c29_i81 < 3; c29_i81 = c29_i81 + 1) {
    c29_b_b[c29_i81] = c29_b[c29_i81];
  }

  for (c29_i82 = 0; c29_i82 < 3; c29_i82 = c29_i82 + 1) {
    c29_x[c29_i82] = c29_b_a[c29_i82];
  }

  for (c29_i83 = 0; c29_i83 < 3; c29_i83 = c29_i83 + 1) {
    c29_y[c29_i83] = c29_b_b[c29_i83];
  }

  for (c29_i84 = 0; c29_i84 < 3; c29_i84 = c29_i84 + 1) {
    c29_b_x[c29_i84] = c29_x[c29_i84];
  }

  for (c29_i85 = 0; c29_i85 < 3; c29_i85 = c29_i85 + 1) {
    c29_b_y[c29_i85] = c29_y[c29_i85];
  }

  for (c29_i86 = 0; c29_i86 < 3; c29_i86 = c29_i86 + 1) {
    c29_c_x[c29_i86] = c29_b_x[c29_i86];
  }

  for (c29_i87 = 0; c29_i87 < 3; c29_i87 = c29_i87 + 1) {
    c29_c_y[c29_i87] = c29_b_y[c29_i87];
  }

  for (c29_i88 = 0; c29_i88 < 3; c29_i88 = c29_i88 + 1) {
    c29_d_x[c29_i88] = c29_c_x[c29_i88];
  }

  for (c29_i89 = 0; c29_i89 < 3; c29_i89 = c29_i89 + 1) {
    c29_d_y[c29_i89] = c29_c_y[c29_i89];
  }

  return c29_ceval_xdot(3, c29_d_x, 1, 1, c29_d_y, 1, 1);
}

static void c29_eml_scalar_eg(void)
{
}

static real_T c29_ceval_xdot(int32_T c29_n, real_T c29_x[3], int32_T c29_ix0,
  int32_T c29_incx, real_T c29_y[3], int32_T c29_iy0,
  int32_T c29_incy)
{
  real_T c29_d;
  c29_d = 0.0;
  if ((real_T)c29_n > 0.0) {
    return ddot32(&c29_n, &c29_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c29_ix0), 1, 3, 1, 0) - 1]
                  , &c29_incx, &c29_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c29_iy0), 1, 3, 1, 0) - 1], &
                  c29_incy);
  }

  return c29_d;
}

static real_T c29_sqrt(real_T c29_x)
{
  real_T c29_b_x;
  real_T c29_c_x;
  c29_b_x = c29_x;
  if (c29_b_x < 0.0) {
    c29_eml_error();
  }

  c29_c_x = c29_b_x;
  c29_b_x = c29_c_x;
  return muDoubleScalarSqrt(c29_b_x);
}

static void c29_eml_error(void)
{
  int32_T c29_i90;
  static char_T c29_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c29_u[77];
  const mxArray *c29_y = NULL;
  int32_T c29_i91;
  static char_T c29_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c29_b_u[31];
  const mxArray *c29_b_y = NULL;
  for (c29_i90 = 0; c29_i90 < 77; c29_i90 = c29_i90 + 1) {
    c29_u[c29_i90] = c29_cv0[c29_i90];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c29_i91 = 0; c29_i91 < 31; c29_i91 = c29_i91 + 1) {
    c29_b_u[c29_i91] = c29_cv1[c29_i91];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c29_b_y, 14, c29_y);
}

static void c29_mrdivide(real_T c29_A[3], real_T c29_B, real_T c29_y[3])
{
  int32_T c29_i92;
  real_T c29_x[3];
  real_T c29_b_y;
  int32_T c29_i93;
  real_T c29_b_x[3];
  real_T c29_c_y;
  int32_T c29_i94;
  real_T c29_c_x[3];
  real_T c29_d_y;
  int32_T c29_i95;
  for (c29_i92 = 0; c29_i92 < 3; c29_i92 = c29_i92 + 1) {
    c29_x[c29_i92] = c29_A[c29_i92];
  }

  c29_b_y = c29_B;
  if (c29_b_y == 0.0) {
    c29_eml_warning();
  }

  for (c29_i93 = 0; c29_i93 < 3; c29_i93 = c29_i93 + 1) {
    c29_b_x[c29_i93] = c29_x[c29_i93];
  }

  c29_c_y = c29_b_y;
  for (c29_i94 = 0; c29_i94 < 3; c29_i94 = c29_i94 + 1) {
    c29_c_x[c29_i94] = c29_b_x[c29_i94];
  }

  c29_d_y = c29_c_y;
  for (c29_i95 = 0; c29_i95 < 3; c29_i95 = c29_i95 + 1) {
    c29_y[c29_i95] = c29_c_x[c29_i95] / c29_d_y;
  }
}

static void c29_eml_warning(void)
{
  int32_T c29_i96;
  static char_T c29_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c29_u[15];
  const mxArray *c29_y = NULL;
  int32_T c29_i97;
  static char_T c29_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c29_b_u[19];
  const mxArray *c29_b_y = NULL;
  for (c29_i96 = 0; c29_i96 < 15; c29_i96 = c29_i96 + 1) {
    c29_u[c29_i96] = c29_cv2[c29_i96];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c29_i97 = 0; c29_i97 < 19; c29_i97 = c29_i97 + 1) {
    c29_b_u[c29_i97] = c29_cv3[c29_i97];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c29_b_y, 14, c29_y);
}

static real_T c29_trace(real_T c29_a[9])
{
  real_T c29_t;
  real_T c29_k;
  real_T c29_b_k;
  c29_t = 0.0;
  for (c29_k = 1.0; c29_k <= 3.0; c29_k = c29_k + 1.0) {
    c29_b_k = c29_k;
    c29_t = c29_t + c29_a[(_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
      _SFD_INTEGER_CHECK("k", c29_b_k), 1, 3, 1, 0) - 1) + 3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK("k", c29_b_k),
      1, 3, 2, 0) - 1)];
  }

  return c29_t;
}

static void c29_b_mrdivide(real_T c29_A[4], real_T c29_B, real_T c29_y[4])
{
  int32_T c29_i98;
  real_T c29_x[4];
  real_T c29_b_y;
  int32_T c29_i99;
  real_T c29_b_x[4];
  real_T c29_c_y;
  int32_T c29_i100;
  real_T c29_c_x[4];
  real_T c29_d_y;
  int32_T c29_i101;
  for (c29_i98 = 0; c29_i98 < 4; c29_i98 = c29_i98 + 1) {
    c29_x[c29_i98] = c29_A[c29_i98];
  }

  c29_b_y = c29_B;
  if (c29_b_y == 0.0) {
    c29_eml_warning();
  }

  for (c29_i99 = 0; c29_i99 < 4; c29_i99 = c29_i99 + 1) {
    c29_b_x[c29_i99] = c29_x[c29_i99];
  }

  c29_c_y = c29_b_y;
  for (c29_i100 = 0; c29_i100 < 4; c29_i100 = c29_i100 + 1) {
    c29_c_x[c29_i100] = c29_b_x[c29_i100];
  }

  c29_d_y = c29_c_y;
  for (c29_i101 = 0; c29_i101 < 4; c29_i101 = c29_i101 + 1) {
    c29_y[c29_i101] = c29_c_x[c29_i101] / c29_d_y;
  }
}

static real_T c29_c_mrdivide(real_T c29_A, real_T c29_B)
{
  real_T c29_x;
  real_T c29_b_y;
  real_T c29_b_x;
  real_T c29_c_y;
  real_T c29_c_x;
  real_T c29_d_y;
  c29_x = c29_A;
  c29_b_y = c29_B;
  if (c29_b_y == 0.0) {
    c29_eml_warning();
  }

  c29_b_x = c29_x;
  c29_c_y = c29_b_y;
  c29_c_x = c29_b_x;
  c29_d_y = c29_c_y;
  return c29_c_x / c29_d_y;
}

static void c29_b_eml_scalar_eg(void)
{
}

static void c29_c_eml_scalar_eg(void)
{
}

static real_T c29_mpower(real_T c29_a)
{
  real_T c29_b_a;
  real_T c29_ak;
  c29_b_a = c29_a;
  c29_c_eml_scalar_eg();
  c29_ak = c29_b_a;
  return muDoubleScalarPower(c29_ak, 2.0);
}

static real_T c29_atan2(real_T c29_y, real_T c29_x)
{
  real_T c29_b_y;
  real_T c29_b_x;
  c29_c_eml_scalar_eg();
  c29_b_y = c29_y;
  c29_b_x = c29_x;
  return muDoubleScalarAtan2(c29_b_y, c29_b_x);
}

static real_T c29_asin(real_T c29_x)
{
  real_T c29_b_x;
  real_T c29_c_x;
  c29_b_x = c29_x;
  if (c29_b_x < -1.0) {
  } else if (1.0 < c29_b_x) {
  } else {
    goto label_1;
  }

  c29_b_eml_error();
 label_1:
  ;
  c29_c_x = c29_b_x;
  c29_b_x = c29_c_x;
  return muDoubleScalarAsin(c29_b_x);
}

static void c29_b_eml_error(void)
{
  int32_T c29_i102;
  static char_T c29_cv4[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 'a',
    's', 'i', 'n', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c29_u[77];
  const mxArray *c29_y = NULL;
  int32_T c29_i103;
  static char_T c29_cv5[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 's', 'i', 'n', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c29_b_u[31];
  const mxArray *c29_b_y = NULL;
  for (c29_i102 = 0; c29_i102 < 77; c29_i102 = c29_i102 + 1) {
    c29_u[c29_i102] = c29_cv4[c29_i102];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c29_i103 = 0; c29_i103 < 31; c29_i103 = c29_i103 + 1) {
    c29_b_u[c29_i103] = c29_cv5[c29_i103];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c29_b_y, 14, c29_y);
}

static void c29_d_eml_scalar_eg(void)
{
}

static const mxArray *c29_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  int32_T c29_i104;
  real_T c29_b_u[7];
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  for (c29_i104 = 0; c29_i104 < 7; c29_i104 = c29_i104 + 1) {
    c29_b_u[c29_i104] = (*((real_T (*)[7])c29_u))[c29_i104];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static const mxArray *c29_b_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  int32_T c29_i105;
  real_T c29_b_u[6];
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  for (c29_i105 = 0; c29_i105 < 6; c29_i105 = c29_i105 + 1) {
    c29_b_u[c29_i105] = (*((real_T (*)[6])c29_u))[c29_i105];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static const mxArray *c29_c_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  int32_T c29_i106;
  real_T c29_b_u[3];
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  for (c29_i106 = 0; c29_i106 < 3; c29_i106 = c29_i106 + 1) {
    c29_b_u[c29_i106] = (*((real_T (*)[3])c29_u))[c29_i106];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static const mxArray *c29_d_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  int32_T c29_i107;
  real_T c29_b_u[4];
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  for (c29_i107 = 0; c29_i107 < 4; c29_i107 = c29_i107 + 1) {
    c29_b_u[c29_i107] = (*((real_T (*)[4])c29_u))[c29_i107];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static const mxArray *c29_e_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  real_T c29_b_u;
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  c29_b_u = *((real_T *)c29_u);
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static const mxArray *c29_f_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  int32_T c29_i108;
  int32_T c29_i109;
  int32_T c29_i110;
  real_T c29_b_u[9];
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  c29_i108 = 0;
  for (c29_i109 = 0; c29_i109 < 3; c29_i109 = c29_i109 + 1) {
    for (c29_i110 = 0; c29_i110 < 3; c29_i110 = c29_i110 + 1) {
      c29_b_u[c29_i110 + c29_i108] = (*((real_T (*)[9])c29_u))[c29_i110 +
        c29_i108];
    }

    c29_i108 = c29_i108 + 3;
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static const mxArray *c29_g_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  int32_T c29_i111;
  int32_T c29_i112;
  int32_T c29_i113;
  real_T c29_b_u[16];
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  c29_i111 = 0;
  for (c29_i112 = 0; c29_i112 < 4; c29_i112 = c29_i112 + 1) {
    for (c29_i113 = 0; c29_i113 < 4; c29_i113 = c29_i113 + 1) {
      c29_b_u[c29_i113 + c29_i111] = (*((real_T (*)[16])c29_u))[c29_i113 +
        c29_i111];
    }

    c29_i111 = c29_i111 + 4;
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

const mxArray
  *sf_c29_adcs_v15_integral_Power_dist_get_eml_resolved_functions_info(void)
{
  const mxArray *c29_nameCaptureInfo = NULL;
  c29_ResolvedFunctionInfo c29_info[69];
  c29_ResolvedFunctionInfo (*c29_b_info)[69];
  const mxArray *c29_m0 = NULL;
  int32_T c29_i114;
  c29_ResolvedFunctionInfo *c29_r0;
  c29_nameCaptureInfo = NULL;
  c29_info_helper(c29_info);
  c29_b_info = (c29_ResolvedFunctionInfo (*)[69])c29_info;
  (*c29_b_info)[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c29_b_info)[64].name = "eml_scalar_floor";
  (*c29_b_info)[64].dominantType = "double";
  (*c29_b_info)[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c29_b_info)[64].fileLength = 260U;
  (*c29_b_info)[64].fileTime1 = 1209318190U;
  (*c29_b_info)[64].fileTime2 = 0U;
  (*c29_b_info)[65].context = "";
  (*c29_b_info)[65].name = "atan2";
  (*c29_b_info)[65].dominantType = "double";
  (*c29_b_info)[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  (*c29_b_info)[65].fileLength = 605U;
  (*c29_b_info)[65].fileTime1 = 1236241054U;
  (*c29_b_info)[65].fileTime2 = 0U;
  (*c29_b_info)[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  (*c29_b_info)[66].name = "eml_scalar_atan2";
  (*c29_b_info)[66].dominantType = "double";
  (*c29_b_info)[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  (*c29_b_info)[66].fileLength = 964U;
  (*c29_b_info)[66].fileTime1 = 1209318186U;
  (*c29_b_info)[66].fileTime2 = 0U;
  (*c29_b_info)[67].context = "";
  (*c29_b_info)[67].name = "asin";
  (*c29_b_info)[67].dominantType = "double";
  (*c29_b_info)[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  (*c29_b_info)[67].fileLength = 585U;
  (*c29_b_info)[67].fileTime1 = 1203431744U;
  (*c29_b_info)[67].fileTime2 = 0U;
  (*c29_b_info)[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  (*c29_b_info)[68].name = "eml_scalar_asin";
  (*c29_b_info)[68].dominantType = "double";
  (*c29_b_info)[68].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  (*c29_b_info)[68].fileLength = 588U;
  (*c29_b_info)[68].fileTime1 = 1203431774U;
  (*c29_b_info)[68].fileTime2 = 0U;
  sf_mex_assign(&c29_m0, sf_mex_createstruct("nameCaptureInfo", 1, 69));
  for (c29_i114 = 0; c29_i114 < 69; c29_i114 = c29_i114 + 1) {
    c29_r0 = &c29_info[c29_i114];
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", c29_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c29_r0->context)), "context"
                    , "nameCaptureInfo", c29_i114);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", c29_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c29_r0->name)), "name",
                    "nameCaptureInfo", c29_i114);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo",
      c29_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c29_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c29_i114);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", c29_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c29_r0->resolved)),
                    "resolved", "nameCaptureInfo", c29_i114);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c29_i114);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c29_i114);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c29_i114);
  }

  sf_mex_assign(&c29_nameCaptureInfo, c29_m0);
  return c29_nameCaptureInfo;
}

static void c29_info_helper(c29_ResolvedFunctionInfo c29_info[69])
{
  c29_info[0].context = "";
  c29_info[0].name = "cross";
  c29_info[0].dominantType = "double";
  c29_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[0].fileLength = 3157U;
  c29_info[0].fileTime1 = 1240249462U;
  c29_info[0].fileTime2 = 0U;
  c29_info[1].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[1].name = "nargin";
  c29_info[1].dominantType = "";
  c29_info[1].resolved = "[B]nargin";
  c29_info[1].fileLength = 0U;
  c29_info[1].fileTime1 = 0U;
  c29_info[1].fileTime2 = 0U;
  c29_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[2].name = "gt";
  c29_info[2].dominantType = "double";
  c29_info[2].resolved = "[B]gt";
  c29_info[2].fileLength = 0U;
  c29_info[2].fileTime1 = 0U;
  c29_info[2].fileTime2 = 0U;
  c29_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[3].name = "eq";
  c29_info[3].dominantType = "double";
  c29_info[3].resolved = "[B]eq";
  c29_info[3].fileLength = 0U;
  c29_info[3].fileTime1 = 0U;
  c29_info[3].fileTime2 = 0U;
  c29_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[4].name = "isa";
  c29_info[4].dominantType = "double";
  c29_info[4].resolved = "[B]isa";
  c29_info[4].fileLength = 0U;
  c29_info[4].fileTime1 = 0U;
  c29_info[4].fileTime2 = 0U;
  c29_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[5].name = "isvector";
  c29_info[5].dominantType = "double";
  c29_info[5].resolved = "[B]isvector";
  c29_info[5].fileLength = 0U;
  c29_info[5].fileTime1 = 0U;
  c29_info[5].fileTime2 = 0U;
  c29_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[6].name = "mtimes";
  c29_info[6].dominantType = "double";
  c29_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[6].fileLength = 3302U;
  c29_info[6].fileTime1 = 1242738294U;
  c29_info[6].fileTime2 = 0U;
  c29_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[7].name = "isinteger";
  c29_info[7].dominantType = "double";
  c29_info[7].resolved = "[B]isinteger";
  c29_info[7].fileLength = 0U;
  c29_info[7].fileTime1 = 0U;
  c29_info[7].fileTime2 = 0U;
  c29_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[8].name = "isscalar";
  c29_info[8].dominantType = "double";
  c29_info[8].resolved = "[B]isscalar";
  c29_info[8].fileLength = 0U;
  c29_info[8].fileTime1 = 0U;
  c29_info[8].fileTime2 = 0U;
  c29_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[9].name = "strcmp";
  c29_info[9].dominantType = "char";
  c29_info[9].resolved = "[B]strcmp";
  c29_info[9].fileLength = 0U;
  c29_info[9].fileTime1 = 0U;
  c29_info[9].fileTime2 = 0U;
  c29_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[10].name = "size";
  c29_info[10].dominantType = "double";
  c29_info[10].resolved = "[B]size";
  c29_info[10].fileLength = 0U;
  c29_info[10].fileTime1 = 0U;
  c29_info[10].fileTime2 = 0U;
  c29_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[11].name = "class";
  c29_info[11].dominantType = "double";
  c29_info[11].resolved = "[B]class";
  c29_info[11].fileLength = 0U;
  c29_info[11].fileTime1 = 0U;
  c29_info[11].fileTime2 = 0U;
  c29_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[12].name = "not";
  c29_info[12].dominantType = "logical";
  c29_info[12].resolved = "[B]not";
  c29_info[12].fileLength = 0U;
  c29_info[12].fileTime1 = 0U;
  c29_info[12].fileTime2 = 0U;
  c29_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c29_info[13].name = "minus";
  c29_info[13].dominantType = "double";
  c29_info[13].resolved = "[B]minus";
  c29_info[13].fileLength = 0U;
  c29_info[13].fileTime1 = 0U;
  c29_info[13].fileTime2 = 0U;
  c29_info[14].context = "";
  c29_info[14].name = "dot";
  c29_info[14].dominantType = "double";
  c29_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[14].fileLength = 2812U;
  c29_info[14].fileTime1 = 1236241088U;
  c29_info[14].fileTime2 = 0U;
  c29_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[15].name = "isequal";
  c29_info[15].dominantType = "double";
  c29_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c29_info[15].fileLength = 180U;
  c29_info[15].fileTime1 = 1226561072U;
  c29_info[15].fileTime2 = 0U;
  c29_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c29_info[16].name = "false";
  c29_info[16].dominantType = "";
  c29_info[16].resolved = "[B]false";
  c29_info[16].fileLength = 0U;
  c29_info[16].fileTime1 = 0U;
  c29_info[16].fileTime2 = 0U;
  c29_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c29_info[17].name = "eml_isequal_core";
  c29_info[17].dominantType = "double";
  c29_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c29_info[17].fileLength = 3981U;
  c29_info[17].fileTime1 = 1236241072U;
  c29_info[17].fileTime2 = 0U;
  c29_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c29_info[18].name = "ge";
  c29_info[18].dominantType = "double";
  c29_info[18].resolved = "[B]ge";
  c29_info[18].fileLength = 0U;
  c29_info[18].fileTime1 = 0U;
  c29_info[18].fileTime2 = 0U;
  c29_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c29_info[19].name = "islogical";
  c29_info[19].dominantType = "logical";
  c29_info[19].resolved = "[B]islogical";
  c29_info[19].fileLength = 0U;
  c29_info[19].fileTime1 = 0U;
  c29_info[19].fileTime2 = 0U;
  c29_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c29_info[20].name = "isnumeric";
  c29_info[20].dominantType = "double";
  c29_info[20].resolved = "[B]isnumeric";
  c29_info[20].fileLength = 0U;
  c29_info[20].fileTime1 = 0U;
  c29_info[20].fileTime2 = 0U;
  c29_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c29_info[21].name = "ndims";
  c29_info[21].dominantType = "double";
  c29_info[21].resolved = "[B]ndims";
  c29_info[21].fileLength = 0U;
  c29_info[21].fileTime1 = 0U;
  c29_info[21].fileTime2 = 0U;
  c29_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c29_info[22].name = "ne";
  c29_info[22].dominantType = "double";
  c29_info[22].resolved = "[B]ne";
  c29_info[22].fileLength = 0U;
  c29_info[22].fileTime1 = 0U;
  c29_info[22].fileTime2 = 0U;
  c29_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c29_info[23].name = "true";
  c29_info[23].dominantType = "";
  c29_info[23].resolved = "[B]true";
  c29_info[23].fileLength = 0U;
  c29_info[23].fileTime1 = 0U;
  c29_info[23].fileTime2 = 0U;
  c29_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c29_info[24].name = "isstruct";
  c29_info[24].dominantType = "double";
  c29_info[24].resolved = "[B]isstruct";
  c29_info[24].fileLength = 0U;
  c29_info[24].fileTime1 = 0U;
  c29_info[24].fileTime2 = 0U;
  c29_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c29_info[25].name = "isempty";
  c29_info[25].dominantType = "double";
  c29_info[25].resolved = "[B]isempty";
  c29_info[25].fileLength = 0U;
  c29_info[25].fileTime1 = 0U;
  c29_info[25].fileTime2 = 0U;
  c29_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c29_info[26].name = "isnan";
  c29_info[26].dominantType = "double";
  c29_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c29_info[26].fileLength = 506U;
  c29_info[26].fileTime1 = 1228077610U;
  c29_info[26].fileTime2 = 0U;
  c29_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c29_info[27].name = "isreal";
  c29_info[27].dominantType = "double";
  c29_info[27].resolved = "[B]isreal";
  c29_info[27].fileLength = 0U;
  c29_info[27].fileTime1 = 0U;
  c29_info[27].fileTime2 = 0U;
  c29_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[28].name = "eml_index_class";
  c29_info[28].dominantType = "";
  c29_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c29_info[28].fileLength = 909U;
  c29_info[28].fileTime1 = 1192454182U;
  c29_info[28].fileTime2 = 0U;
  c29_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[29].name = "ones";
  c29_info[29].dominantType = "char";
  c29_info[29].resolved = "[B]ones";
  c29_info[29].fileLength = 0U;
  c29_info[29].fileTime1 = 0U;
  c29_info[29].fileTime2 = 0U;
  c29_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[30].name = "isfloat";
  c29_info[30].dominantType = "double";
  c29_info[30].resolved = "[B]isfloat";
  c29_info[30].fileLength = 0U;
  c29_info[30].fileTime1 = 0U;
  c29_info[30].fileTime2 = 0U;
  c29_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[31].name = "eml_scalar_eg";
  c29_info[31].dominantType = "double";
  c29_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c29_info[31].fileLength = 3068U;
  c29_info[31].fileTime1 = 1240249410U;
  c29_info[31].fileTime2 = 0U;
  c29_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c29_info[32].name = "cast";
  c29_info[32].dominantType = "double";
  c29_info[32].resolved = "[B]cast";
  c29_info[32].fileLength = 0U;
  c29_info[32].fileTime1 = 0U;
  c29_info[32].fileTime2 = 0U;
  c29_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c29_info[33].name = "plus";
  c29_info[33].dominantType = "double";
  c29_info[33].resolved = "[B]plus";
  c29_info[33].fileLength = 0U;
  c29_info[33].fileTime1 = 0U;
  c29_info[33].fileTime2 = 0U;
  c29_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c29_info[34].name = "lt";
  c29_info[34].dominantType = "double";
  c29_info[34].resolved = "[B]lt";
  c29_info[34].fileLength = 0U;
  c29_info[34].fileTime1 = 0U;
  c29_info[34].fileTime2 = 0U;
  c29_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c29_info[35].name = "eml_xdotc";
  c29_info[35].dominantType = "int32";
  c29_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c29_info[35].fileLength = 1453U;
  c29_info[35].fileTime1 = 1209318250U;
  c29_info[35].fileTime2 = 0U;
  c29_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c29_info[36].name = "eml_xdot";
  c29_info[36].dominantType = "int32";
  c29_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c29_info[36].fileLength = 1330U;
  c29_info[36].fileTime1 = 1209318250U;
  c29_info[36].fileTime2 = 0U;
  c29_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c29_info[37].name = "eml_refblas_xdot";
  c29_info[37].dominantType = "int32";
  c29_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c29_info[37].fileLength = 343U;
  c29_info[37].fileTime1 = 1211203444U;
  c29_info[37].fileTime2 = 0U;
  c29_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c29_info[38].name = "eml_refblas_xdotx";
  c29_info[38].dominantType = "int32";
  c29_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c29_info[38].fileLength = 1605U;
  c29_info[38].fileTime1 = 1236241080U;
  c29_info[38].fileTime2 = 0U;
  c29_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c29_info[39].name = "ischar";
  c29_info[39].dominantType = "char";
  c29_info[39].resolved = "[B]ischar";
  c29_info[39].fileLength = 0U;
  c29_info[39].fileTime1 = 0U;
  c29_info[39].fileTime2 = 0U;
  c29_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c29_info[40].name = "times";
  c29_info[40].dominantType = "double";
  c29_info[40].resolved = "[B]times";
  c29_info[40].fileLength = 0U;
  c29_info[40].fileTime1 = 0U;
  c29_info[40].fileTime2 = 0U;
  c29_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c29_info[41].name = "uminus";
  c29_info[41].dominantType = "int32";
  c29_info[41].resolved = "[B]uminus";
  c29_info[41].fileLength = 0U;
  c29_info[41].fileTime1 = 0U;
  c29_info[41].fileTime2 = 0U;
  c29_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c29_info[42].name = "eml_index_minus";
  c29_info[42].dominantType = "int32";
  c29_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c29_info[42].fileLength = 277U;
  c29_info[42].fileTime1 = 1192454184U;
  c29_info[42].fileTime2 = 0U;
  c29_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c29_info[43].name = "eml_index_plus";
  c29_info[43].dominantType = "int32";
  c29_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c29_info[43].fileLength = 272U;
  c29_info[43].fileTime1 = 1192454186U;
  c29_info[43].fileTime2 = 0U;
  c29_info[44].context = "";
  c29_info[44].name = "sqrt";
  c29_info[44].dominantType = "double";
  c29_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c29_info[44].fileLength = 572U;
  c29_info[44].fileTime1 = 1203431846U;
  c29_info[44].fileTime2 = 0U;
  c29_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c29_info[45].name = "eml_error";
  c29_info[45].dominantType = "char";
  c29_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c29_info[45].fileLength = 315U;
  c29_info[45].fileTime1 = 1213914146U;
  c29_info[45].fileTime2 = 0U;
  c29_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c29_info[46].name = "eml_scalar_sqrt";
  c29_info[46].dominantType = "double";
  c29_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c29_info[46].fileLength = 664U;
  c29_info[46].fileTime1 = 1209318194U;
  c29_info[46].fileTime2 = 0U;
  c29_info[47].context = "";
  c29_info[47].name = "mrdivide";
  c29_info[47].dominantType = "double";
  c29_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c29_info[47].fileLength = 800U;
  c29_info[47].fileTime1 = 1238421692U;
  c29_info[47].fileTime2 = 0U;
  c29_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c29_info[48].name = "rdivide";
  c29_info[48].dominantType = "double";
  c29_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c29_info[48].fileLength = 620U;
  c29_info[48].fileTime1 = 1213914166U;
  c29_info[48].fileTime2 = 0U;
  c29_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c29_info[49].name = "eml_warning";
  c29_info[49].dominantType = "char";
  c29_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c29_info[49].fileLength = 262U;
  c29_info[49].fileTime1 = 1236241078U;
  c29_info[49].fileTime2 = 0U;
  c29_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c29_info[50].name = "eml_div";
  c29_info[50].dominantType = "double";
  c29_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c29_info[50].fileLength = 4269U;
  c29_info[50].fileTime1 = 1228077626U;
  c29_info[50].fileTime2 = 0U;
  c29_info[51].context = "";
  c29_info[51].name = "trace";
  c29_info[51].dominantType = "double";
  c29_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/trace.m";
  c29_info[51].fileLength = 582U;
  c29_info[51].fileTime1 = 1238421684U;
  c29_info[51].fileTime2 = 0U;
  c29_info[52].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[52].name = "le";
  c29_info[52].dominantType = "double";
  c29_info[52].resolved = "[B]le";
  c29_info[52].fileLength = 0U;
  c29_info[52].fileTime1 = 0U;
  c29_info[52].fileTime2 = 0U;
  c29_info[53].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[53].name = "eml_xgemm";
  c29_info[53].dominantType = "int32";
  c29_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c29_info[53].fileLength = 3184U;
  c29_info[53].fileTime1 = 1209318252U;
  c29_info[53].fileTime2 = 0U;
  c29_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c29_info[54].name = "length";
  c29_info[54].dominantType = "double";
  c29_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c29_info[54].fileLength = 326U;
  c29_info[54].fileTime1 = 1226561076U;
  c29_info[54].fileTime2 = 0U;
  c29_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c29_info[55].name = "min";
  c29_info[55].dominantType = "double";
  c29_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[55].fileLength = 308U;
  c29_info[55].fileTime1 = 1192454034U;
  c29_info[55].fileTime2 = 0U;
  c29_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[56].name = "nargout";
  c29_info[56].dominantType = "";
  c29_info[56].resolved = "[B]nargout";
  c29_info[56].fileLength = 0U;
  c29_info[56].fileTime1 = 0U;
  c29_info[56].fileTime2 = 0U;
  c29_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[57].name = "eml_min_or_max";
  c29_info[57].dominantType = "char";
  c29_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c29_info[57].fileLength = 9969U;
  c29_info[57].fileTime1 = 1240249408U;
  c29_info[57].fileTime2 = 0U;
  c29_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c29_info[58].name = "eml_scalexp_alloc";
  c29_info[58].dominantType = "double";
  c29_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c29_info[58].fileLength = 808U;
  c29_info[58].fileTime1 = 1230478500U;
  c29_info[58].fileTime2 = 0U;
  c29_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c29_info[59].name = "eml_refblas_xgemm";
  c29_info[59].dominantType = "int32";
  c29_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[59].fileLength = 5748U;
  c29_info[59].fileTime1 = 1228077674U;
  c29_info[59].fileTime2 = 0U;
  c29_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[60].name = "eml_index_times";
  c29_info[60].dominantType = "int32";
  c29_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c29_info[60].fileLength = 280U;
  c29_info[60].fileTime1 = 1192454188U;
  c29_info[60].fileTime2 = 0U;
  c29_info[61].context = "";
  c29_info[61].name = "pi";
  c29_info[61].dominantType = "";
  c29_info[61].resolved = "[B]pi";
  c29_info[61].fileLength = 0U;
  c29_info[61].fileTime1 = 0U;
  c29_info[61].fileTime2 = 0U;
  c29_info[62].context = "";
  c29_info[62].name = "mpower";
  c29_info[62].dominantType = "double";
  c29_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c29_info[62].fileLength = 3710U;
  c29_info[62].fileTime1 = 1238421690U;
  c29_info[62].fileTime2 = 0U;
  c29_info[63].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c29_info[63].name = "power";
  c29_info[63].dominantType = "double";
  c29_info[63].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c29_info[63].fileLength = 5380U;
  c29_info[63].fileTime1 = 1228077698U;
  c29_info[63].fileTime2 = 0U;
}

static const mxArray *c29_h_sf_marshall(void *c29_chartInstance, void *c29_u)
{
  const mxArray *c29_y = NULL;
  boolean_T c29_b_u;
  const mxArray *c29_b_y = NULL;
  c29_y = NULL;
  c29_b_u = *((boolean_T *)c29_u);
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c29_y, c29_b_y);
  return c29_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c29_adcs_v15_integral_Power_dist_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3066204660U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3359207554U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1031336905U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4147724174U);
}

mxArray *sf_c29_adcs_v15_integral_Power_dist_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1870462868U);
    pr[1] = (double)(1567940936U);
    pr[2] = (double)(2667323208U);
    pr[3] = (double)(3670541733U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c29_adcs_v15_integral_Power_dist(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[9],T\"euler\",},{M[1],M[11],T\"modw\",},{M[1],M[5],T\"q_BO\",},{M[1],M[13],T\"w_BIB\",},{M[1],M[10],T\"w_BOB\",},{M[8],M[0],T\"is_active_c29_adcs_v15_integral_Power_dist\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_adcs_v15_integral_Power_dist_get_check_sum(&mxChecksum);
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
          (_adcs_v15_integral_Power_distMachineNumber_,
           29,
           1,
           1,
           8,
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
            (_adcs_v15_integral_Power_distMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_adcs_v15_integral_Power_distMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_adcs_v15_integral_Power_distMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x",0,(MexFcnForType)c29_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"euler",0,(MexFcnForType)c29_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_Si",0,(MexFcnForType)c29_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_BO",0,(MexFcnForType)c29_d_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w_BOB",0,(MexFcnForType)c29_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"modw",0,
                              (MexFcnForType)c29_e_sf_marshall);
          _SFD_SET_DATA_PROPS(6,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_W_SAT",0,(MexFcnForType)c29_e_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w_BIB",0,(MexFcnForType)c29_c_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,4,0,0,0,6,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1994);
        _SFD_CV_INIT_EML_IF(0,0,419,440,862,1060);
        _SFD_CV_INIT_EML_IF(0,1,445,479,515,853);
        _SFD_CV_INIT_EML_IF(0,2,515,553,589,853);
        _SFD_CV_INIT_EML_IF(0,3,589,627,663,853);

        {
          static int condStart[] = { 450, 467 };

          static int condEnd[] = { 463, 479 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,450,479,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 524, 541 };

          static int condEnd[] = { 537, 553 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,524,553,2,2,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 598, 615 };

          static int condEnd[] = { 611, 627 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,2,598,627,2,4,&(condStart[0]),&(condEnd[0]),3,
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
          real_T (*c29_x)[7];
          real_T (*c29_euler)[3];
          real_T (*c29_v_Si)[6];
          real_T (*c29_q_BO)[4];
          real_T (*c29_w_BOB)[3];
          real_T *c29_modw;
          real_T (*c29_w_BIB)[3];
          c29_modw = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c29_w_BOB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
          c29_q_BO = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 2);
          c29_w_BIB = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
          c29_v_Si = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
          c29_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
          c29_euler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c29_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c29_euler);
          _SFD_SET_DATA_VALUE_PTR(2U, c29_v_Si);
          _SFD_SET_DATA_VALUE_PTR(3U, c29_q_BO);
          _SFD_SET_DATA_VALUE_PTR(4U, c29_w_BOB);
          _SFD_SET_DATA_VALUE_PTR(5U, c29_modw);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c29_s_W_SAT);
          _SFD_SET_DATA_VALUE_PTR(7U, c29_w_BIB);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_distMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c29_adcs_v15_integral_Power_dist();
  initialize_c29_adcs_v15_integral_Power_dist();
}

static void sf_opaque_enable_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  enable_c29_adcs_v15_integral_Power_dist();
}

static void sf_opaque_disable_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  disable_c29_adcs_v15_integral_Power_dist();
}

static void sf_opaque_gateway_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  sf_c29_adcs_v15_integral_Power_dist();
}

static void sf_opaque_ext_mode_exec_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  ext_mode_exec_c29_adcs_v15_integral_Power_dist();
}

static mxArray* sf_opaque_get_sim_state_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c29_adcs_v15_integral_Power_dist();
  return st;
}

static void sf_opaque_set_sim_state_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c29_adcs_v15_integral_Power_dist(sf_mex_dup(st));
}

static void sf_opaque_terminate_c29_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c29_adcs_v15_integral_Power_dist();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_adcs_v15_integral_Power_dist(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c29_adcs_v15_integral_Power_dist();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c29_adcs_v15_integral_Power_dist(SimStruct *S)
{
  /* Actual parameters from chart:
     s_W_SAT
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for s_W_SAT*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_dist",
                "adcs_v15_integral_Power_dist",29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_dist","adcs_v15_integral_Power_dist",29,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",29,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",29,5);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_dist",
                          "adcs_v15_integral_Power_dist",29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(959706747U));
  ssSetChecksum1(S,(2488958225U));
  ssSetChecksum2(S,(4167183491U));
  ssSetChecksum3(S,(333766769U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c29_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",29);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_adcs_v15_integral_Power_dist(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlStart = mdlStart_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c29_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c29_adcs_v15_integral_Power_dist;
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

void c29_adcs_v15_integral_Power_dist_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_adcs_v15_integral_Power_dist(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_adcs_v15_integral_Power_dist_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
