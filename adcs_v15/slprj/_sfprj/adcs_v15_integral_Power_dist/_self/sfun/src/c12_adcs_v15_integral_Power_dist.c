/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_dist_sfun.h"
#include "c12_adcs_v15_integral_Power_dist.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_dist_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c12_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc12_adcs_v15_integral_Power_distInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c12_adcs_v15_integral_Power_dist(void);
static void initialize_params_c12_adcs_v15_integral_Power_dist(void);
static void enable_c12_adcs_v15_integral_Power_dist(void);
static void disable_c12_adcs_v15_integral_Power_dist(void);
static void c12_update_debugger_state_c12_adcs_v15_integral_Power_dist(void);
static void ext_mode_exec_c12_adcs_v15_integral_Power_dist(void);
static const mxArray *get_sim_state_c12_adcs_v15_integral_Power_dist(void);
static void set_sim_state_c12_adcs_v15_integral_Power_dist(const mxArray *c12_st);
static void finalize_c12_adcs_v15_integral_Power_dist(void);
static void sf_c12_adcs_v15_integral_Power_dist(void);
static void c12_c12_adcs_v15_integral_Power_dist(void);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static void c12_cross(real_T c12_a[3], real_T c12_b[3], real_T c12_c[3]);
static real_T c12_dot(real_T c12_a[3], real_T c12_b[3]);
static void c12_eml_scalar_eg(void);
static real_T c12_ceval_xdot(int32_T c12_n, real_T c12_x[3], int32_T c12_ix0,
  int32_T c12_incx, real_T c12_y[3], int32_T c12_iy0, int32_T c12_incy);
static void c12_eml_error(void);
static void c12_eml_warning(void);
static void c12_b_eml_scalar_eg(void);
static const mxArray *c12_sf_marshall(void *c12_chartInstance, void *c12_u);
static const mxArray *c12_b_sf_marshall(void *c12_chartInstance, void *c12_u);
static const mxArray *c12_c_sf_marshall(void *c12_chartInstance, void *c12_u);
static const mxArray *c12_d_sf_marshall(void *c12_chartInstance, void *c12_u);
static void c12_info_helper(c12_ResolvedFunctionInfo c12_info[61]);
static const mxArray *c12_e_sf_marshall(void *c12_chartInstance, void *c12_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c12_adcs_v15_integral_Power_dist(void)
{
  uint8_T *c12_is_active_c12_adcs_v15_integral_Power_dist;
  c12_is_active_c12_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c12_is_active_c12_adcs_v15_integral_Power_dist = 0U;
}

static void initialize_params_c12_adcs_v15_integral_Power_dist(void)
{
}

static void enable_c12_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c12_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c12_update_debugger_state_c12_adcs_v15_integral_Power_dist(void)
{
}

static void ext_mode_exec_c12_adcs_v15_integral_Power_dist(void)
{
  c12_update_debugger_state_c12_adcs_v15_integral_Power_dist();
}

static const mxArray *get_sim_state_c12_adcs_v15_integral_Power_dist(void)
{
  const mxArray *c12_st = NULL;
  const mxArray *c12_y = NULL;
  int32_T c12_i0;
  real_T c12_u[3];
  const mxArray *c12_b_y = NULL;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  uint8_T *c12_is_active_c12_adcs_v15_integral_Power_dist;
  real_T (*c12_v_O)[3];
  c12_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c12_is_active_c12_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2));
  for (c12_i0 = 0; c12_i0 < 3; c12_i0 = c12_i0 + 1) {
    c12_u[c12_i0] = (*c12_v_O)[c12_i0];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_u = *c12_is_active_c12_adcs_v15_integral_Power_dist;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y);
  return c12_st;
}

static void set_sim_state_c12_adcs_v15_integral_Power_dist(const mxArray *c12_st)
{
  const mxArray *c12_u;
  const mxArray *c12_v_O;
  real_T c12_dv0[3];
  int32_T c12_i1;
  real_T c12_y[3];
  int32_T c12_i2;
  const mxArray *c12_is_active_c12_adcs_v15_integral_Power_dist;
  uint8_T c12_u0;
  uint8_T c12_b_y;
  boolean_T *c12_doneDoubleBufferReInit;
  uint8_T *c12_b_is_active_c12_adcs_v15_integral_Power_dist;
  real_T (*c12_b_v_O)[3];
  c12_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c12_b_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c12_b_is_active_c12_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  c12_v_O = sf_mex_dup(sf_mex_getcell(c12_u, 0));
  sf_mex_import("v_O", sf_mex_dup(c12_v_O), &c12_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c12_i1 = 0; c12_i1 < 3; c12_i1 = c12_i1 + 1) {
    c12_y[c12_i1] = c12_dv0[c12_i1];
  }

  sf_mex_destroy(&c12_v_O);
  for (c12_i2 = 0; c12_i2 < 3; c12_i2 = c12_i2 + 1) {
    (*c12_b_v_O)[c12_i2] = c12_y[c12_i2];
  }

  c12_is_active_c12_adcs_v15_integral_Power_dist = sf_mex_dup(sf_mex_getcell
    (c12_u, 1));
  sf_mex_import("is_active_c12_adcs_v15_integral_Power_dist", sf_mex_dup
                (c12_is_active_c12_adcs_v15_integral_Power_dist), &c12_u0, 1,
                3, 0U, 0, 0U, 0);
  c12_b_y = c12_u0;
  sf_mex_destroy(&c12_is_active_c12_adcs_v15_integral_Power_dist);
  *c12_b_is_active_c12_adcs_v15_integral_Power_dist = c12_b_y;
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_adcs_v15_integral_Power_dist();
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_adcs_v15_integral_Power_dist(void)
{
}

static void sf_c12_adcs_v15_integral_Power_dist(void)
{
  int32_T c12_i3;
  int32_T c12_i4;
  int32_T c12_i5;
  int32_T c12_previousEvent;
  real_T (*c12_v_O)[3];
  real_T (*c12_ECI)[6];
  real_T (*c12_v_I)[3];
  c12_ECI = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c12_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c12_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,10);
  for (c12_i3 = 0; c12_i3 < 3; c12_i3 = c12_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c12_v_I)[c12_i3], 0U);
  }

  for (c12_i4 = 0; c12_i4 < 6; c12_i4 = c12_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c12_ECI)[c12_i4], 1U);
  }

  for (c12_i5 = 0; c12_i5 < 3; c12_i5 = c12_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c12_v_O)[c12_i5], 2U);
  }

  c12_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c12_c12_adcs_v15_integral_Power_dist();
  _sfEvent_ = c12_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_distMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c12_c12_adcs_v15_integral_Power_dist(void)
{
  int32_T c12_i6;
  real_T c12_v_I[3];
  int32_T c12_i7;
  real_T c12_ECI[6];
  real_T c12_nargout = 1.0;
  real_T c12_nargin = 2.0;
  real_T c12_TOI[9];
  real_T c12_ox[3];
  real_T c12_oz[3];
  real_T c12_oy[3];
  real_T c12_v[3];
  real_T c12_r[3];
  real_T c12_v_O[3];
  int32_T c12_i8;
  int32_T c12_i9;
  int32_T c12_i10;
  real_T c12_b_v[3];
  int32_T c12_i11;
  real_T c12_b_r[3];
  real_T c12_dv1[3];
  int32_T c12_i12;
  int32_T c12_i13;
  real_T c12_A[3];
  int32_T c12_i14;
  real_T c12_b_oy[3];
  int32_T c12_i15;
  real_T c12_c_oy[3];
  real_T c12_x;
  real_T c12_B;
  real_T c12_b_x;
  int32_T c12_i16;
  real_T c12_c_x[3];
  real_T c12_y;
  int32_T c12_i17;
  real_T c12_d_x[3];
  real_T c12_b_y;
  int32_T c12_i18;
  real_T c12_e_x[3];
  real_T c12_c_y;
  int32_T c12_i19;
  int32_T c12_i20;
  real_T c12_b_A[3];
  int32_T c12_i21;
  real_T c12_c_r[3];
  int32_T c12_i22;
  real_T c12_d_r[3];
  real_T c12_f_x;
  real_T c12_b_B;
  real_T c12_g_x;
  int32_T c12_i23;
  real_T c12_h_x[3];
  real_T c12_d_y;
  int32_T c12_i24;
  real_T c12_i_x[3];
  real_T c12_e_y;
  int32_T c12_i25;
  real_T c12_j_x[3];
  real_T c12_f_y;
  int32_T c12_i26;
  int32_T c12_i27;
  real_T c12_d_oy[3];
  int32_T c12_i28;
  real_T c12_b_oz[3];
  real_T c12_dv2[3];
  int32_T c12_i29;
  int32_T c12_i30;
  real_T c12_c_A[3];
  int32_T c12_i31;
  real_T c12_b_ox[3];
  int32_T c12_i32;
  real_T c12_c_ox[3];
  real_T c12_k_x;
  real_T c12_c_B;
  real_T c12_l_x;
  int32_T c12_i33;
  real_T c12_m_x[3];
  real_T c12_g_y;
  int32_T c12_i34;
  real_T c12_n_x[3];
  real_T c12_h_y;
  int32_T c12_i35;
  real_T c12_o_x[3];
  real_T c12_i_y;
  int32_T c12_i36;
  int32_T c12_i37;
  int32_T c12_i38;
  int32_T c12_i39;
  int32_T c12_i40;
  int32_T c12_i41;
  int32_T c12_i42;
  int32_T c12_i43;
  real_T c12_a[9];
  int32_T c12_i44;
  real_T c12_b[3];
  int32_T c12_i45;
  real_T c12_d_A[9];
  int32_T c12_i46;
  real_T c12_d_B[3];
  int32_T c12_i47;
  int32_T c12_i48;
  real_T c12_e_A[9];
  int32_T c12_i49;
  real_T c12_e_B[3];
  int32_T c12_i50;
  real_T c12_f_A[9];
  int32_T c12_i51;
  real_T c12_f_B[3];
  int32_T c12_i52;
  int32_T c12_i53;
  int32_T c12_i54;
  int32_T c12_i55;
  real_T (*c12_b_v_O)[3];
  real_T (*c12_b_ECI)[6];
  real_T (*c12_b_v_I)[3];
  c12_b_ECI = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c12_b_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c12_b_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,10);
  for (c12_i6 = 0; c12_i6 < 3; c12_i6 = c12_i6 + 1) {
    c12_v_I[c12_i6] = (*c12_b_v_I)[c12_i6];
  }

  for (c12_i7 = 0; c12_i7 < 6; c12_i7 = c12_i7 + 1) {
    c12_ECI[c12_i7] = (*c12_b_ECI)[c12_i7];
  }

  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c12_nargout, c12_d_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c12_nargin, c12_d_sf_marshall);
  sf_debug_symbol_scope_add("TOI", &c12_TOI, c12_c_sf_marshall);
  sf_debug_symbol_scope_add("ox", &c12_ox, c12_sf_marshall);
  sf_debug_symbol_scope_add("oz", &c12_oz, c12_sf_marshall);
  sf_debug_symbol_scope_add("oy", &c12_oy, c12_sf_marshall);
  sf_debug_symbol_scope_add("v", &c12_v, c12_sf_marshall);
  sf_debug_symbol_scope_add("r", &c12_r, c12_sf_marshall);
  sf_debug_symbol_scope_add("v_O", &c12_v_O, c12_sf_marshall);
  sf_debug_symbol_scope_add("ECI", &c12_ECI, c12_b_sf_marshall);
  sf_debug_symbol_scope_add("v_I", &c12_v_I, c12_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block gives DCM for converting from ECI to ORBIT frames */
  /*  inputs: state vector in ECI */
  /*  output: DCM */
  _SFD_EML_CALL(0,6);
  for (c12_i8 = 0; c12_i8 < 3; c12_i8 = c12_i8 + 1) {
    c12_r[c12_i8] = c12_ECI[c12_i8];
  }

  /*  position vector in ECI */
  _SFD_EML_CALL(0,7);
  for (c12_i9 = 0; c12_i9 < 3; c12_i9 = c12_i9 + 1) {
    c12_v[c12_i9] = c12_ECI[c12_i9 + 3];
  }

  /*  velocity vector in ECI */
  _SFD_EML_CALL(0,9);
  for (c12_i10 = 0; c12_i10 < 3; c12_i10 = c12_i10 + 1) {
    c12_b_v[c12_i10] = c12_v[c12_i10];
  }

  for (c12_i11 = 0; c12_i11 < 3; c12_i11 = c12_i11 + 1) {
    c12_b_r[c12_i11] = c12_r[c12_i11];
  }

  c12_cross(c12_b_v, c12_b_r, c12_dv1);
  for (c12_i12 = 0; c12_i12 < 3; c12_i12 = c12_i12 + 1) {
    c12_oy[c12_i12] = c12_dv1[c12_i12];
  }

  /*  orbit frame x... */
  _SFD_EML_CALL(0,10);
  for (c12_i13 = 0; c12_i13 < 3; c12_i13 = c12_i13 + 1) {
    c12_A[c12_i13] = c12_oy[c12_i13];
  }

  for (c12_i14 = 0; c12_i14 < 3; c12_i14 = c12_i14 + 1) {
    c12_b_oy[c12_i14] = c12_oy[c12_i14];
  }

  for (c12_i15 = 0; c12_i15 < 3; c12_i15 = c12_i15 + 1) {
    c12_c_oy[c12_i15] = c12_oy[c12_i15];
  }

  c12_x = c12_dot(c12_b_oy, c12_c_oy);
  c12_B = c12_x;
  if (c12_B < 0.0) {
    c12_eml_error();
  }

  c12_b_x = c12_B;
  c12_B = c12_b_x;
  c12_B = muDoubleScalarSqrt(c12_B);
  for (c12_i16 = 0; c12_i16 < 3; c12_i16 = c12_i16 + 1) {
    c12_c_x[c12_i16] = c12_A[c12_i16];
  }

  c12_y = c12_B;
  if (c12_y == 0.0) {
    c12_eml_warning();
  }

  for (c12_i17 = 0; c12_i17 < 3; c12_i17 = c12_i17 + 1) {
    c12_d_x[c12_i17] = c12_c_x[c12_i17];
  }

  c12_b_y = c12_y;
  for (c12_i18 = 0; c12_i18 < 3; c12_i18 = c12_i18 + 1) {
    c12_e_x[c12_i18] = c12_d_x[c12_i18];
  }

  c12_c_y = c12_b_y;
  for (c12_i19 = 0; c12_i19 < 3; c12_i19 = c12_i19 + 1) {
    c12_oy[c12_i19] = c12_e_x[c12_i19] / c12_c_y;
  }

  _SFD_EML_CALL(0,12);
  for (c12_i20 = 0; c12_i20 < 3; c12_i20 = c12_i20 + 1) {
    c12_b_A[c12_i20] = -c12_r[c12_i20];
  }

  for (c12_i21 = 0; c12_i21 < 3; c12_i21 = c12_i21 + 1) {
    c12_c_r[c12_i21] = c12_r[c12_i21];
  }

  for (c12_i22 = 0; c12_i22 < 3; c12_i22 = c12_i22 + 1) {
    c12_d_r[c12_i22] = c12_r[c12_i22];
  }

  c12_f_x = c12_dot(c12_c_r, c12_d_r);
  c12_b_B = c12_f_x;
  if (c12_b_B < 0.0) {
    c12_eml_error();
  }

  c12_g_x = c12_b_B;
  c12_b_B = c12_g_x;
  c12_b_B = muDoubleScalarSqrt(c12_b_B);
  for (c12_i23 = 0; c12_i23 < 3; c12_i23 = c12_i23 + 1) {
    c12_h_x[c12_i23] = c12_b_A[c12_i23];
  }

  c12_d_y = c12_b_B;
  if (c12_d_y == 0.0) {
    c12_eml_warning();
  }

  for (c12_i24 = 0; c12_i24 < 3; c12_i24 = c12_i24 + 1) {
    c12_i_x[c12_i24] = c12_h_x[c12_i24];
  }

  c12_e_y = c12_d_y;
  for (c12_i25 = 0; c12_i25 < 3; c12_i25 = c12_i25 + 1) {
    c12_j_x[c12_i25] = c12_i_x[c12_i25];
  }

  c12_f_y = c12_e_y;
  for (c12_i26 = 0; c12_i26 < 3; c12_i26 = c12_i26 + 1) {
    c12_oz[c12_i26] = c12_j_x[c12_i26] / c12_f_y;
  }

  _SFD_EML_CALL(0,14);
  for (c12_i27 = 0; c12_i27 < 3; c12_i27 = c12_i27 + 1) {
    c12_d_oy[c12_i27] = c12_oy[c12_i27];
  }

  for (c12_i28 = 0; c12_i28 < 3; c12_i28 = c12_i28 + 1) {
    c12_b_oz[c12_i28] = c12_oz[c12_i28];
  }

  c12_cross(c12_d_oy, c12_b_oz, c12_dv2);
  for (c12_i29 = 0; c12_i29 < 3; c12_i29 = c12_i29 + 1) {
    c12_ox[c12_i29] = c12_dv2[c12_i29];
  }

  _SFD_EML_CALL(0,15);
  for (c12_i30 = 0; c12_i30 < 3; c12_i30 = c12_i30 + 1) {
    c12_c_A[c12_i30] = c12_ox[c12_i30];
  }

  for (c12_i31 = 0; c12_i31 < 3; c12_i31 = c12_i31 + 1) {
    c12_b_ox[c12_i31] = c12_ox[c12_i31];
  }

  for (c12_i32 = 0; c12_i32 < 3; c12_i32 = c12_i32 + 1) {
    c12_c_ox[c12_i32] = c12_ox[c12_i32];
  }

  c12_k_x = c12_dot(c12_b_ox, c12_c_ox);
  c12_c_B = c12_k_x;
  if (c12_c_B < 0.0) {
    c12_eml_error();
  }

  c12_l_x = c12_c_B;
  c12_c_B = c12_l_x;
  c12_c_B = muDoubleScalarSqrt(c12_c_B);
  for (c12_i33 = 0; c12_i33 < 3; c12_i33 = c12_i33 + 1) {
    c12_m_x[c12_i33] = c12_c_A[c12_i33];
  }

  c12_g_y = c12_c_B;
  if (c12_g_y == 0.0) {
    c12_eml_warning();
  }

  for (c12_i34 = 0; c12_i34 < 3; c12_i34 = c12_i34 + 1) {
    c12_n_x[c12_i34] = c12_m_x[c12_i34];
  }

  c12_h_y = c12_g_y;
  for (c12_i35 = 0; c12_i35 < 3; c12_i35 = c12_i35 + 1) {
    c12_o_x[c12_i35] = c12_n_x[c12_i35];
  }

  c12_i_y = c12_h_y;
  for (c12_i36 = 0; c12_i36 < 3; c12_i36 = c12_i36 + 1) {
    c12_ox[c12_i36] = c12_o_x[c12_i36] / c12_i_y;
  }

  _SFD_EML_CALL(0,17);
  c12_i37 = 0;
  for (c12_i38 = 0; c12_i38 < 3; c12_i38 = c12_i38 + 1) {
    c12_TOI[c12_i37] = c12_ox[c12_i38];
    c12_i37 = c12_i37 + 3;
  }

  c12_i39 = 0;
  for (c12_i40 = 0; c12_i40 < 3; c12_i40 = c12_i40 + 1) {
    c12_TOI[c12_i39 + 1] = c12_oy[c12_i40];
    c12_i39 = c12_i39 + 3;
  }

  c12_i41 = 0;
  for (c12_i42 = 0; c12_i42 < 3; c12_i42 = c12_i42 + 1) {
    c12_TOI[c12_i41 + 2] = c12_oz[c12_i42];
    c12_i41 = c12_i41 + 3;
  }

  _SFD_EML_CALL(0,19);
  for (c12_i43 = 0; c12_i43 < 9; c12_i43 = c12_i43 + 1) {
    c12_a[c12_i43] = c12_TOI[c12_i43];
  }

  for (c12_i44 = 0; c12_i44 < 3; c12_i44 = c12_i44 + 1) {
    c12_b[c12_i44] = c12_v_I[c12_i44];
  }

  c12_b_eml_scalar_eg();
  c12_b_eml_scalar_eg();
  for (c12_i45 = 0; c12_i45 < 9; c12_i45 = c12_i45 + 1) {
    c12_d_A[c12_i45] = c12_a[c12_i45];
  }

  for (c12_i46 = 0; c12_i46 < 3; c12_i46 = c12_i46 + 1) {
    c12_d_B[c12_i46] = c12_b[c12_i46];
  }

  for (c12_i47 = 0; c12_i47 < 3; c12_i47 = c12_i47 + 1) {
    c12_v_O[c12_i47] = 0.0;
  }

  for (c12_i48 = 0; c12_i48 < 9; c12_i48 = c12_i48 + 1) {
    c12_e_A[c12_i48] = c12_d_A[c12_i48];
  }

  for (c12_i49 = 0; c12_i49 < 3; c12_i49 = c12_i49 + 1) {
    c12_e_B[c12_i49] = c12_d_B[c12_i49];
  }

  for (c12_i50 = 0; c12_i50 < 9; c12_i50 = c12_i50 + 1) {
    c12_f_A[c12_i50] = c12_e_A[c12_i50];
  }

  for (c12_i51 = 0; c12_i51 < 3; c12_i51 = c12_i51 + 1) {
    c12_f_B[c12_i51] = c12_e_B[c12_i51];
  }

  for (c12_i52 = 0; c12_i52 < 3; c12_i52 = c12_i52 + 1) {
    c12_v_O[c12_i52] = 0.0;
    c12_i53 = 0;
    for (c12_i54 = 0; c12_i54 < 3; c12_i54 = c12_i54 + 1) {
      c12_v_O[c12_i52] = c12_v_O[c12_i52] + c12_f_A[c12_i53 + c12_i52] *
        c12_f_B[c12_i54];
      c12_i53 = c12_i53 + 3;
    }
  }

  _SFD_EML_CALL(0,-19);
  sf_debug_symbol_scope_pop();
  for (c12_i55 = 0; c12_i55 < 3; c12_i55 = c12_i55 + 1) {
    (*c12_b_v_O)[c12_i55] = c12_v_O[c12_i55];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static void c12_cross(real_T c12_a[3], real_T c12_b[3], real_T c12_c[3])
{
  real_T c12_b_a;
  real_T c12_b_b;
  real_T c12_y;
  real_T c12_c_a;
  real_T c12_c_b;
  real_T c12_b_y;
  real_T c12_c1;
  real_T c12_d_a;
  real_T c12_d_b;
  real_T c12_c_y;
  real_T c12_e_a;
  real_T c12_e_b;
  real_T c12_d_y;
  real_T c12_c2;
  real_T c12_f_a;
  real_T c12_f_b;
  real_T c12_e_y;
  real_T c12_g_a;
  real_T c12_g_b;
  real_T c12_f_y;
  real_T c12_c3;
  c12_b_a = c12_a[2];
  c12_b_b = c12_b[1];
  c12_y = c12_b_a * c12_b_b;
  c12_c_a = c12_a[1];
  c12_c_b = c12_b[2];
  c12_b_y = c12_c_a * c12_c_b;
  c12_c1 = c12_b_y - c12_y;
  c12_d_a = c12_a[0];
  c12_d_b = c12_b[2];
  c12_c_y = c12_d_a * c12_d_b;
  c12_e_a = c12_a[2];
  c12_e_b = c12_b[0];
  c12_d_y = c12_e_a * c12_e_b;
  c12_c2 = c12_d_y - c12_c_y;
  c12_f_a = c12_a[1];
  c12_f_b = c12_b[0];
  c12_e_y = c12_f_a * c12_f_b;
  c12_g_a = c12_a[0];
  c12_g_b = c12_b[1];
  c12_f_y = c12_g_a * c12_g_b;
  c12_c3 = c12_f_y - c12_e_y;
  c12_c[0] = c12_c1;
  c12_c[1] = c12_c2;
  c12_c[2] = c12_c3;
}

static real_T c12_dot(real_T c12_a[3], real_T c12_b[3])
{
  int32_T c12_i56;
  real_T c12_b_a[3];
  int32_T c12_i57;
  real_T c12_b_b[3];
  int32_T c12_i58;
  real_T c12_x[3];
  int32_T c12_i59;
  real_T c12_y[3];
  int32_T c12_i60;
  real_T c12_b_x[3];
  int32_T c12_i61;
  real_T c12_b_y[3];
  int32_T c12_i62;
  real_T c12_c_x[3];
  int32_T c12_i63;
  real_T c12_c_y[3];
  int32_T c12_i64;
  real_T c12_d_x[3];
  int32_T c12_i65;
  real_T c12_d_y[3];
  c12_eml_scalar_eg();
  for (c12_i56 = 0; c12_i56 < 3; c12_i56 = c12_i56 + 1) {
    c12_b_a[c12_i56] = c12_a[c12_i56];
  }

  for (c12_i57 = 0; c12_i57 < 3; c12_i57 = c12_i57 + 1) {
    c12_b_b[c12_i57] = c12_b[c12_i57];
  }

  for (c12_i58 = 0; c12_i58 < 3; c12_i58 = c12_i58 + 1) {
    c12_x[c12_i58] = c12_b_a[c12_i58];
  }

  for (c12_i59 = 0; c12_i59 < 3; c12_i59 = c12_i59 + 1) {
    c12_y[c12_i59] = c12_b_b[c12_i59];
  }

  for (c12_i60 = 0; c12_i60 < 3; c12_i60 = c12_i60 + 1) {
    c12_b_x[c12_i60] = c12_x[c12_i60];
  }

  for (c12_i61 = 0; c12_i61 < 3; c12_i61 = c12_i61 + 1) {
    c12_b_y[c12_i61] = c12_y[c12_i61];
  }

  for (c12_i62 = 0; c12_i62 < 3; c12_i62 = c12_i62 + 1) {
    c12_c_x[c12_i62] = c12_b_x[c12_i62];
  }

  for (c12_i63 = 0; c12_i63 < 3; c12_i63 = c12_i63 + 1) {
    c12_c_y[c12_i63] = c12_b_y[c12_i63];
  }

  for (c12_i64 = 0; c12_i64 < 3; c12_i64 = c12_i64 + 1) {
    c12_d_x[c12_i64] = c12_c_x[c12_i64];
  }

  for (c12_i65 = 0; c12_i65 < 3; c12_i65 = c12_i65 + 1) {
    c12_d_y[c12_i65] = c12_c_y[c12_i65];
  }

  return c12_ceval_xdot(3, c12_d_x, 1, 1, c12_d_y, 1, 1);
}

static void c12_eml_scalar_eg(void)
{
}

static real_T c12_ceval_xdot(int32_T c12_n, real_T c12_x[3], int32_T c12_ix0,
  int32_T c12_incx, real_T c12_y[3], int32_T c12_iy0,
  int32_T c12_incy)
{
  real_T c12_d;
  c12_d = 0.0;
  if ((real_T)c12_n > 0.0) {
    return ddot32(&c12_n, &c12_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c12_ix0), 1, 3, 1, 0) - 1]
                  , &c12_incx, &c12_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c12_iy0), 1, 3, 1, 0) - 1], &
                  c12_incy);
  }

  return c12_d;
}

static void c12_eml_error(void)
{
  int32_T c12_i66;
  static char_T c12_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c12_u[77];
  const mxArray *c12_y = NULL;
  int32_T c12_i67;
  static char_T c12_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c12_b_u[31];
  const mxArray *c12_b_y = NULL;
  for (c12_i66 = 0; c12_i66 < 77; c12_i66 = c12_i66 + 1) {
    c12_u[c12_i66] = c12_cv0[c12_i66];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c12_i67 = 0; c12_i67 < 31; c12_i67 = c12_i67 + 1) {
    c12_b_u[c12_i67] = c12_cv1[c12_i67];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c12_b_y, 14, c12_y);
}

static void c12_eml_warning(void)
{
  int32_T c12_i68;
  static char_T c12_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c12_u[15];
  const mxArray *c12_y = NULL;
  int32_T c12_i69;
  static char_T c12_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c12_b_u[19];
  const mxArray *c12_b_y = NULL;
  for (c12_i68 = 0; c12_i68 < 15; c12_i68 = c12_i68 + 1) {
    c12_u[c12_i68] = c12_cv2[c12_i68];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c12_i69 = 0; c12_i69 < 19; c12_i69 = c12_i69 + 1) {
    c12_b_u[c12_i69] = c12_cv3[c12_i69];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c12_b_y, 14, c12_y);
}

static void c12_b_eml_scalar_eg(void)
{
}

static const mxArray *c12_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  int32_T c12_i70;
  real_T c12_b_u[3];
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  for (c12_i70 = 0; c12_i70 < 3; c12_i70 = c12_i70 + 1) {
    c12_b_u[c12_i70] = (*((real_T (*)[3])c12_u))[c12_i70];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static const mxArray *c12_b_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  int32_T c12_i71;
  real_T c12_b_u[6];
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  for (c12_i71 = 0; c12_i71 < 6; c12_i71 = c12_i71 + 1) {
    c12_b_u[c12_i71] = (*((real_T (*)[6])c12_u))[c12_i71];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static const mxArray *c12_c_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  int32_T c12_i72;
  int32_T c12_i73;
  int32_T c12_i74;
  real_T c12_b_u[9];
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  c12_i72 = 0;
  for (c12_i73 = 0; c12_i73 < 3; c12_i73 = c12_i73 + 1) {
    for (c12_i74 = 0; c12_i74 < 3; c12_i74 = c12_i74 + 1) {
      c12_b_u[c12_i74 + c12_i72] = (*((real_T (*)[9])c12_u))[c12_i74 + c12_i72];
    }

    c12_i72 = c12_i72 + 3;
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static const mxArray *c12_d_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  c12_b_u = *((real_T *)c12_u);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

const mxArray
  *sf_c12_adcs_v15_integral_Power_dist_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_ResolvedFunctionInfo c12_info[61];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i75;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_info_helper(c12_info);
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 61));
  for (c12_i75 = 0; c12_i75 < 61; c12_i75 = c12_i75 + 1) {
    c12_r0 = &c12_info[c12_i75];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context"
                    , "nameCaptureInfo", c12_i75);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name",
                    "nameCaptureInfo", c12_i75);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i75);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)),
                    "resolved", "nameCaptureInfo", c12_i75);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c12_i75);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c12_i75);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c12_i75);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(c12_ResolvedFunctionInfo c12_info[61])
{
  c12_info[0].context = "";
  c12_info[0].name = "cross";
  c12_info[0].dominantType = "double";
  c12_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[0].fileLength = 3157U;
  c12_info[0].fileTime1 = 1240249462U;
  c12_info[0].fileTime2 = 0U;
  c12_info[1].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[1].name = "nargin";
  c12_info[1].dominantType = "";
  c12_info[1].resolved = "[B]nargin";
  c12_info[1].fileLength = 0U;
  c12_info[1].fileTime1 = 0U;
  c12_info[1].fileTime2 = 0U;
  c12_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[2].name = "gt";
  c12_info[2].dominantType = "double";
  c12_info[2].resolved = "[B]gt";
  c12_info[2].fileLength = 0U;
  c12_info[2].fileTime1 = 0U;
  c12_info[2].fileTime2 = 0U;
  c12_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[3].name = "eq";
  c12_info[3].dominantType = "double";
  c12_info[3].resolved = "[B]eq";
  c12_info[3].fileLength = 0U;
  c12_info[3].fileTime1 = 0U;
  c12_info[3].fileTime2 = 0U;
  c12_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[4].name = "isa";
  c12_info[4].dominantType = "double";
  c12_info[4].resolved = "[B]isa";
  c12_info[4].fileLength = 0U;
  c12_info[4].fileTime1 = 0U;
  c12_info[4].fileTime2 = 0U;
  c12_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[5].name = "isvector";
  c12_info[5].dominantType = "double";
  c12_info[5].resolved = "[B]isvector";
  c12_info[5].fileLength = 0U;
  c12_info[5].fileTime1 = 0U;
  c12_info[5].fileTime2 = 0U;
  c12_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[6].name = "mtimes";
  c12_info[6].dominantType = "double";
  c12_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[6].fileLength = 3302U;
  c12_info[6].fileTime1 = 1242738294U;
  c12_info[6].fileTime2 = 0U;
  c12_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[7].name = "isinteger";
  c12_info[7].dominantType = "double";
  c12_info[7].resolved = "[B]isinteger";
  c12_info[7].fileLength = 0U;
  c12_info[7].fileTime1 = 0U;
  c12_info[7].fileTime2 = 0U;
  c12_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[8].name = "isscalar";
  c12_info[8].dominantType = "double";
  c12_info[8].resolved = "[B]isscalar";
  c12_info[8].fileLength = 0U;
  c12_info[8].fileTime1 = 0U;
  c12_info[8].fileTime2 = 0U;
  c12_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[9].name = "strcmp";
  c12_info[9].dominantType = "char";
  c12_info[9].resolved = "[B]strcmp";
  c12_info[9].fileLength = 0U;
  c12_info[9].fileTime1 = 0U;
  c12_info[9].fileTime2 = 0U;
  c12_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[10].name = "size";
  c12_info[10].dominantType = "double";
  c12_info[10].resolved = "[B]size";
  c12_info[10].fileLength = 0U;
  c12_info[10].fileTime1 = 0U;
  c12_info[10].fileTime2 = 0U;
  c12_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[11].name = "class";
  c12_info[11].dominantType = "double";
  c12_info[11].resolved = "[B]class";
  c12_info[11].fileLength = 0U;
  c12_info[11].fileTime1 = 0U;
  c12_info[11].fileTime2 = 0U;
  c12_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[12].name = "not";
  c12_info[12].dominantType = "logical";
  c12_info[12].resolved = "[B]not";
  c12_info[12].fileLength = 0U;
  c12_info[12].fileTime1 = 0U;
  c12_info[12].fileTime2 = 0U;
  c12_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c12_info[13].name = "minus";
  c12_info[13].dominantType = "double";
  c12_info[13].resolved = "[B]minus";
  c12_info[13].fileLength = 0U;
  c12_info[13].fileTime1 = 0U;
  c12_info[13].fileTime2 = 0U;
  c12_info[14].context = "";
  c12_info[14].name = "dot";
  c12_info[14].dominantType = "double";
  c12_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[14].fileLength = 2812U;
  c12_info[14].fileTime1 = 1236241088U;
  c12_info[14].fileTime2 = 0U;
  c12_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[15].name = "isequal";
  c12_info[15].dominantType = "double";
  c12_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c12_info[15].fileLength = 180U;
  c12_info[15].fileTime1 = 1226561072U;
  c12_info[15].fileTime2 = 0U;
  c12_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c12_info[16].name = "false";
  c12_info[16].dominantType = "";
  c12_info[16].resolved = "[B]false";
  c12_info[16].fileLength = 0U;
  c12_info[16].fileTime1 = 0U;
  c12_info[16].fileTime2 = 0U;
  c12_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c12_info[17].name = "eml_isequal_core";
  c12_info[17].dominantType = "double";
  c12_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c12_info[17].fileLength = 3981U;
  c12_info[17].fileTime1 = 1236241072U;
  c12_info[17].fileTime2 = 0U;
  c12_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c12_info[18].name = "ge";
  c12_info[18].dominantType = "double";
  c12_info[18].resolved = "[B]ge";
  c12_info[18].fileLength = 0U;
  c12_info[18].fileTime1 = 0U;
  c12_info[18].fileTime2 = 0U;
  c12_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c12_info[19].name = "islogical";
  c12_info[19].dominantType = "logical";
  c12_info[19].resolved = "[B]islogical";
  c12_info[19].fileLength = 0U;
  c12_info[19].fileTime1 = 0U;
  c12_info[19].fileTime2 = 0U;
  c12_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c12_info[20].name = "isnumeric";
  c12_info[20].dominantType = "double";
  c12_info[20].resolved = "[B]isnumeric";
  c12_info[20].fileLength = 0U;
  c12_info[20].fileTime1 = 0U;
  c12_info[20].fileTime2 = 0U;
  c12_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c12_info[21].name = "ndims";
  c12_info[21].dominantType = "double";
  c12_info[21].resolved = "[B]ndims";
  c12_info[21].fileLength = 0U;
  c12_info[21].fileTime1 = 0U;
  c12_info[21].fileTime2 = 0U;
  c12_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c12_info[22].name = "ne";
  c12_info[22].dominantType = "double";
  c12_info[22].resolved = "[B]ne";
  c12_info[22].fileLength = 0U;
  c12_info[22].fileTime1 = 0U;
  c12_info[22].fileTime2 = 0U;
  c12_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c12_info[23].name = "true";
  c12_info[23].dominantType = "";
  c12_info[23].resolved = "[B]true";
  c12_info[23].fileLength = 0U;
  c12_info[23].fileTime1 = 0U;
  c12_info[23].fileTime2 = 0U;
  c12_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c12_info[24].name = "isstruct";
  c12_info[24].dominantType = "double";
  c12_info[24].resolved = "[B]isstruct";
  c12_info[24].fileLength = 0U;
  c12_info[24].fileTime1 = 0U;
  c12_info[24].fileTime2 = 0U;
  c12_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c12_info[25].name = "isempty";
  c12_info[25].dominantType = "double";
  c12_info[25].resolved = "[B]isempty";
  c12_info[25].fileLength = 0U;
  c12_info[25].fileTime1 = 0U;
  c12_info[25].fileTime2 = 0U;
  c12_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c12_info[26].name = "isnan";
  c12_info[26].dominantType = "double";
  c12_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c12_info[26].fileLength = 506U;
  c12_info[26].fileTime1 = 1228077610U;
  c12_info[26].fileTime2 = 0U;
  c12_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c12_info[27].name = "isreal";
  c12_info[27].dominantType = "double";
  c12_info[27].resolved = "[B]isreal";
  c12_info[27].fileLength = 0U;
  c12_info[27].fileTime1 = 0U;
  c12_info[27].fileTime2 = 0U;
  c12_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[28].name = "eml_index_class";
  c12_info[28].dominantType = "";
  c12_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c12_info[28].fileLength = 909U;
  c12_info[28].fileTime1 = 1192454182U;
  c12_info[28].fileTime2 = 0U;
  c12_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[29].name = "ones";
  c12_info[29].dominantType = "char";
  c12_info[29].resolved = "[B]ones";
  c12_info[29].fileLength = 0U;
  c12_info[29].fileTime1 = 0U;
  c12_info[29].fileTime2 = 0U;
  c12_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[30].name = "isfloat";
  c12_info[30].dominantType = "double";
  c12_info[30].resolved = "[B]isfloat";
  c12_info[30].fileLength = 0U;
  c12_info[30].fileTime1 = 0U;
  c12_info[30].fileTime2 = 0U;
  c12_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[31].name = "eml_scalar_eg";
  c12_info[31].dominantType = "double";
  c12_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c12_info[31].fileLength = 3068U;
  c12_info[31].fileTime1 = 1240249410U;
  c12_info[31].fileTime2 = 0U;
  c12_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c12_info[32].name = "cast";
  c12_info[32].dominantType = "double";
  c12_info[32].resolved = "[B]cast";
  c12_info[32].fileLength = 0U;
  c12_info[32].fileTime1 = 0U;
  c12_info[32].fileTime2 = 0U;
  c12_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c12_info[33].name = "plus";
  c12_info[33].dominantType = "double";
  c12_info[33].resolved = "[B]plus";
  c12_info[33].fileLength = 0U;
  c12_info[33].fileTime1 = 0U;
  c12_info[33].fileTime2 = 0U;
  c12_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c12_info[34].name = "lt";
  c12_info[34].dominantType = "double";
  c12_info[34].resolved = "[B]lt";
  c12_info[34].fileLength = 0U;
  c12_info[34].fileTime1 = 0U;
  c12_info[34].fileTime2 = 0U;
  c12_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c12_info[35].name = "eml_xdotc";
  c12_info[35].dominantType = "int32";
  c12_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c12_info[35].fileLength = 1453U;
  c12_info[35].fileTime1 = 1209318250U;
  c12_info[35].fileTime2 = 0U;
  c12_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c12_info[36].name = "eml_xdot";
  c12_info[36].dominantType = "int32";
  c12_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c12_info[36].fileLength = 1330U;
  c12_info[36].fileTime1 = 1209318250U;
  c12_info[36].fileTime2 = 0U;
  c12_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c12_info[37].name = "eml_refblas_xdot";
  c12_info[37].dominantType = "int32";
  c12_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c12_info[37].fileLength = 343U;
  c12_info[37].fileTime1 = 1211203444U;
  c12_info[37].fileTime2 = 0U;
  c12_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c12_info[38].name = "eml_refblas_xdotx";
  c12_info[38].dominantType = "int32";
  c12_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c12_info[38].fileLength = 1605U;
  c12_info[38].fileTime1 = 1236241080U;
  c12_info[38].fileTime2 = 0U;
  c12_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c12_info[39].name = "ischar";
  c12_info[39].dominantType = "char";
  c12_info[39].resolved = "[B]ischar";
  c12_info[39].fileLength = 0U;
  c12_info[39].fileTime1 = 0U;
  c12_info[39].fileTime2 = 0U;
  c12_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c12_info[40].name = "times";
  c12_info[40].dominantType = "double";
  c12_info[40].resolved = "[B]times";
  c12_info[40].fileLength = 0U;
  c12_info[40].fileTime1 = 0U;
  c12_info[40].fileTime2 = 0U;
  c12_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c12_info[41].name = "uminus";
  c12_info[41].dominantType = "int32";
  c12_info[41].resolved = "[B]uminus";
  c12_info[41].fileLength = 0U;
  c12_info[41].fileTime1 = 0U;
  c12_info[41].fileTime2 = 0U;
  c12_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c12_info[42].name = "eml_index_minus";
  c12_info[42].dominantType = "int32";
  c12_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c12_info[42].fileLength = 277U;
  c12_info[42].fileTime1 = 1192454184U;
  c12_info[42].fileTime2 = 0U;
  c12_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c12_info[43].name = "eml_index_plus";
  c12_info[43].dominantType = "int32";
  c12_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c12_info[43].fileLength = 272U;
  c12_info[43].fileTime1 = 1192454186U;
  c12_info[43].fileTime2 = 0U;
  c12_info[44].context = "";
  c12_info[44].name = "sqrt";
  c12_info[44].dominantType = "double";
  c12_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c12_info[44].fileLength = 572U;
  c12_info[44].fileTime1 = 1203431846U;
  c12_info[44].fileTime2 = 0U;
  c12_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c12_info[45].name = "eml_error";
  c12_info[45].dominantType = "char";
  c12_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c12_info[45].fileLength = 315U;
  c12_info[45].fileTime1 = 1213914146U;
  c12_info[45].fileTime2 = 0U;
  c12_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c12_info[46].name = "eml_scalar_sqrt";
  c12_info[46].dominantType = "double";
  c12_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c12_info[46].fileLength = 664U;
  c12_info[46].fileTime1 = 1209318194U;
  c12_info[46].fileTime2 = 0U;
  c12_info[47].context = "";
  c12_info[47].name = "mrdivide";
  c12_info[47].dominantType = "double";
  c12_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c12_info[47].fileLength = 800U;
  c12_info[47].fileTime1 = 1238421692U;
  c12_info[47].fileTime2 = 0U;
  c12_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c12_info[48].name = "rdivide";
  c12_info[48].dominantType = "double";
  c12_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c12_info[48].fileLength = 620U;
  c12_info[48].fileTime1 = 1213914166U;
  c12_info[48].fileTime2 = 0U;
  c12_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c12_info[49].name = "eml_warning";
  c12_info[49].dominantType = "char";
  c12_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c12_info[49].fileLength = 262U;
  c12_info[49].fileTime1 = 1236241078U;
  c12_info[49].fileTime2 = 0U;
  c12_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c12_info[50].name = "eml_div";
  c12_info[50].dominantType = "double";
  c12_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c12_info[50].fileLength = 4269U;
  c12_info[50].fileTime1 = 1228077626U;
  c12_info[50].fileTime2 = 0U;
  c12_info[51].context = "";
  c12_info[51].name = "ctranspose";
  c12_info[51].dominantType = "double";
  c12_info[51].resolved = "[B]ctranspose";
  c12_info[51].fileLength = 0U;
  c12_info[51].fileTime1 = 0U;
  c12_info[51].fileTime2 = 0U;
  c12_info[52].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[52].name = "le";
  c12_info[52].dominantType = "double";
  c12_info[52].resolved = "[B]le";
  c12_info[52].fileLength = 0U;
  c12_info[52].fileTime1 = 0U;
  c12_info[52].fileTime2 = 0U;
  c12_info[53].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[53].name = "eml_xgemm";
  c12_info[53].dominantType = "int32";
  c12_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c12_info[53].fileLength = 3184U;
  c12_info[53].fileTime1 = 1209318252U;
  c12_info[53].fileTime2 = 0U;
  c12_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c12_info[54].name = "length";
  c12_info[54].dominantType = "double";
  c12_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c12_info[54].fileLength = 326U;
  c12_info[54].fileTime1 = 1226561076U;
  c12_info[54].fileTime2 = 0U;
  c12_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c12_info[55].name = "min";
  c12_info[55].dominantType = "double";
  c12_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c12_info[55].fileLength = 308U;
  c12_info[55].fileTime1 = 1192454034U;
  c12_info[55].fileTime2 = 0U;
  c12_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c12_info[56].name = "nargout";
  c12_info[56].dominantType = "";
  c12_info[56].resolved = "[B]nargout";
  c12_info[56].fileLength = 0U;
  c12_info[56].fileTime1 = 0U;
  c12_info[56].fileTime2 = 0U;
  c12_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c12_info[57].name = "eml_min_or_max";
  c12_info[57].dominantType = "char";
  c12_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c12_info[57].fileLength = 9969U;
  c12_info[57].fileTime1 = 1240249408U;
  c12_info[57].fileTime2 = 0U;
  c12_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c12_info[58].name = "eml_scalexp_alloc";
  c12_info[58].dominantType = "double";
  c12_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c12_info[58].fileLength = 808U;
  c12_info[58].fileTime1 = 1230478500U;
  c12_info[58].fileTime2 = 0U;
  c12_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c12_info[59].name = "eml_refblas_xgemm";
  c12_info[59].dominantType = "int32";
  c12_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c12_info[59].fileLength = 5748U;
  c12_info[59].fileTime1 = 1228077674U;
  c12_info[59].fileTime2 = 0U;
  c12_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c12_info[60].name = "eml_index_times";
  c12_info[60].dominantType = "int32";
  c12_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c12_info[60].fileLength = 280U;
  c12_info[60].fileTime1 = 1192454188U;
  c12_info[60].fileTime2 = 0U;
}

static const mxArray *c12_e_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  boolean_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  c12_b_u = *((boolean_T *)c12_u);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c12_adcs_v15_integral_Power_dist_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4144095184U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3990681562U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(980132045U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2901485994U);
}

mxArray *sf_c12_adcs_v15_integral_Power_dist_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2744726819U);
    pr[1] = (double)(2956793208U);
    pr[2] = (double)(2290097205U);
    pr[3] = (double)(737232664U);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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

static mxArray *sf_get_sim_state_info_c12_adcs_v15_integral_Power_dist(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_O\",},{M[8],M[0],T\"is_active_c12_adcs_v15_integral_Power_dist\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_adcs_v15_integral_Power_dist_get_check_sum(&mxChecksum);
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
           12,
           1,
           1,
           3,
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
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_I",0,(MexFcnForType)c12_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ECI",0,(MexFcnForType)c12_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_O",0,(MexFcnForType)c12_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,392);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c12_v_I)[3];
          real_T (*c12_ECI)[6];
          real_T (*c12_v_O)[3];
          c12_ECI = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
          c12_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c12_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_v_I);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_ECI);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_v_O);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_distMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c12_adcs_v15_integral_Power_dist();
  initialize_c12_adcs_v15_integral_Power_dist();
}

static void sf_opaque_enable_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  enable_c12_adcs_v15_integral_Power_dist();
}

static void sf_opaque_disable_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  disable_c12_adcs_v15_integral_Power_dist();
}

static void sf_opaque_gateway_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  sf_c12_adcs_v15_integral_Power_dist();
}

static void sf_opaque_ext_mode_exec_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  ext_mode_exec_c12_adcs_v15_integral_Power_dist();
}

static mxArray* sf_opaque_get_sim_state_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c12_adcs_v15_integral_Power_dist();
  return st;
}

static void sf_opaque_set_sim_state_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c12_adcs_v15_integral_Power_dist(sf_mex_dup(st));
}

static void sf_opaque_terminate_c12_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c12_adcs_v15_integral_Power_dist();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_adcs_v15_integral_Power_dist(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_adcs_v15_integral_Power_dist();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c12_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_dist",
                "adcs_v15_integral_Power_dist",12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_dist","adcs_v15_integral_Power_dist",12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",12,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",12,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_dist",
                          "adcs_v15_integral_Power_dist",12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1835607689U));
  ssSetChecksum1(S,(2946204970U));
  ssSetChecksum2(S,(1167471133U));
  ssSetChecksum3(S,(3361612686U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",12);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_adcs_v15_integral_Power_dist(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlStart = mdlStart_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c12_adcs_v15_integral_Power_dist;
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

void c12_adcs_v15_integral_Power_dist_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_adcs_v15_integral_Power_dist(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_adcs_v15_integral_Power_dist_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
