/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_sfun.h"
#include "c25_adcs_v15_integral_Power_nom.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c25_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc25_adcs_v15_integral_Power_nomInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c25_adcs_v15_integral_Power_nom(void);
static void initialize_params_c25_adcs_v15_integral_Power_nom(void);
static void enable_c25_adcs_v15_integral_Power_nom(void);
static void disable_c25_adcs_v15_integral_Power_nom(void);
static void c25_update_debugger_state_c25_adcs_v15_integral_Power_nom(void);
static void ext_mode_exec_c25_adcs_v15_integral_Power_nom(void);
static const mxArray *get_sim_state_c25_adcs_v15_integral_Power_nom(void);
static void set_sim_state_c25_adcs_v15_integral_Power_nom(const mxArray *c25_st);
static void finalize_c25_adcs_v15_integral_Power_nom(void);
static void sf_c25_adcs_v15_integral_Power_nom(void);
static void c25_c25_adcs_v15_integral_Power_nom(void);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber);
static void c25_cross(real_T c25_a[3], real_T c25_b[3], real_T c25_c[3]);
static real_T c25_dot(real_T c25_a[3], real_T c25_b[3]);
static void c25_eml_scalar_eg(void);
static real_T c25_ceval_xdot(int32_T c25_n, real_T c25_x[3], int32_T c25_ix0,
  int32_T c25_incx, real_T c25_y[3], int32_T c25_iy0, int32_T c25_incy);
static void c25_eml_error(void);
static void c25_eml_warning(void);
static void c25_b_eml_scalar_eg(void);
static const mxArray *c25_sf_marshall(void *c25_chartInstance, void *c25_u);
static const mxArray *c25_b_sf_marshall(void *c25_chartInstance, void *c25_u);
static const mxArray *c25_c_sf_marshall(void *c25_chartInstance, void *c25_u);
static const mxArray *c25_d_sf_marshall(void *c25_chartInstance, void *c25_u);
static void c25_info_helper(c25_ResolvedFunctionInfo c25_info[61]);
static const mxArray *c25_e_sf_marshall(void *c25_chartInstance, void *c25_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c25_adcs_v15_integral_Power_nom(void)
{
  uint8_T *c25_is_active_c25_adcs_v15_integral_Power_nom;
  c25_is_active_c25_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c25_is_active_c25_adcs_v15_integral_Power_nom = 0U;
}

static void initialize_params_c25_adcs_v15_integral_Power_nom(void)
{
}

static void enable_c25_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c25_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c25_update_debugger_state_c25_adcs_v15_integral_Power_nom(void)
{
}

static void ext_mode_exec_c25_adcs_v15_integral_Power_nom(void)
{
  c25_update_debugger_state_c25_adcs_v15_integral_Power_nom();
}

static const mxArray *get_sim_state_c25_adcs_v15_integral_Power_nom(void)
{
  const mxArray *c25_st = NULL;
  const mxArray *c25_y = NULL;
  int32_T c25_i0;
  real_T c25_u[3];
  const mxArray *c25_b_y = NULL;
  uint8_T c25_b_u;
  const mxArray *c25_c_y = NULL;
  uint8_T *c25_is_active_c25_adcs_v15_integral_Power_nom;
  real_T (*c25_v_O)[3];
  c25_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c25_is_active_c25_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellarray(2));
  for (c25_i0 = 0; c25_i0 < 3; c25_i0 = c25_i0 + 1) {
    c25_u[c25_i0] = (*c25_v_O)[c25_i0];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c25_y, 0, c25_b_y);
  c25_b_u = *c25_is_active_c25_adcs_v15_integral_Power_nom;
  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", &c25_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c25_y, 1, c25_c_y);
  sf_mex_assign(&c25_st, c25_y);
  return c25_st;
}

static void set_sim_state_c25_adcs_v15_integral_Power_nom(const mxArray *c25_st)
{
  const mxArray *c25_u;
  const mxArray *c25_v_O;
  real_T c25_dv0[3];
  int32_T c25_i1;
  real_T c25_y[3];
  int32_T c25_i2;
  const mxArray *c25_is_active_c25_adcs_v15_integral_Power_nom;
  uint8_T c25_u0;
  uint8_T c25_b_y;
  boolean_T *c25_doneDoubleBufferReInit;
  uint8_T *c25_b_is_active_c25_adcs_v15_integral_Power_nom;
  real_T (*c25_b_v_O)[3];
  c25_b_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c25_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c25_b_is_active_c25_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c25_doneDoubleBufferReInit = true;
  c25_u = sf_mex_dup(c25_st);
  c25_v_O = sf_mex_dup(sf_mex_getcell(c25_u, 0));
  sf_mex_import("v_O", sf_mex_dup(c25_v_O), &c25_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c25_i1 = 0; c25_i1 < 3; c25_i1 = c25_i1 + 1) {
    c25_y[c25_i1] = c25_dv0[c25_i1];
  }

  sf_mex_destroy(&c25_v_O);
  for (c25_i2 = 0; c25_i2 < 3; c25_i2 = c25_i2 + 1) {
    (*c25_b_v_O)[c25_i2] = c25_y[c25_i2];
  }

  c25_is_active_c25_adcs_v15_integral_Power_nom = sf_mex_dup(sf_mex_getcell
    (c25_u, 1));
  sf_mex_import("is_active_c25_adcs_v15_integral_Power_nom", sf_mex_dup
                (c25_is_active_c25_adcs_v15_integral_Power_nom), &c25_u0, 1, 3
                , 0U, 0, 0U, 0);
  c25_b_y = c25_u0;
  sf_mex_destroy(&c25_is_active_c25_adcs_v15_integral_Power_nom);
  *c25_b_is_active_c25_adcs_v15_integral_Power_nom = c25_b_y;
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_adcs_v15_integral_Power_nom();
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_adcs_v15_integral_Power_nom(void)
{
}

static void sf_c25_adcs_v15_integral_Power_nom(void)
{
  int32_T c25_i3;
  int32_T c25_i4;
  int32_T c25_i5;
  int32_T c25_previousEvent;
  real_T (*c25_v_I)[3];
  real_T (*c25_v_O)[3];
  real_T (*c25_ECI)[6];
  c25_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c25_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c25_ECI = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,18);
  for (c25_i3 = 0; c25_i3 < 6; c25_i3 = c25_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c25_ECI)[c25_i3], 0U);
  }

  for (c25_i4 = 0; c25_i4 < 3; c25_i4 = c25_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c25_v_O)[c25_i4], 1U);
  }

  for (c25_i5 = 0; c25_i5 < 3; c25_i5 = c25_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c25_v_I)[c25_i5], 2U);
  }

  c25_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c25_c25_adcs_v15_integral_Power_nom();
  _sfEvent_ = c25_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nomMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c25_c25_adcs_v15_integral_Power_nom(void)
{
  int32_T c25_i6;
  real_T c25_ECI[6];
  int32_T c25_i7;
  real_T c25_v_I[3];
  real_T c25_nargout = 1.0;
  real_T c25_nargin = 2.0;
  real_T c25_TOI[9];
  real_T c25_ox[3];
  real_T c25_oz[3];
  real_T c25_oy[3];
  real_T c25_v[3];
  real_T c25_r[3];
  real_T c25_v_O[3];
  int32_T c25_i8;
  int32_T c25_i9;
  int32_T c25_i10;
  real_T c25_b_v[3];
  int32_T c25_i11;
  real_T c25_b_r[3];
  real_T c25_dv1[3];
  int32_T c25_i12;
  int32_T c25_i13;
  real_T c25_A[3];
  int32_T c25_i14;
  real_T c25_b_oy[3];
  int32_T c25_i15;
  real_T c25_c_oy[3];
  real_T c25_x;
  real_T c25_B;
  real_T c25_b_x;
  int32_T c25_i16;
  real_T c25_c_x[3];
  real_T c25_y;
  int32_T c25_i17;
  real_T c25_d_x[3];
  real_T c25_b_y;
  int32_T c25_i18;
  real_T c25_e_x[3];
  real_T c25_c_y;
  int32_T c25_i19;
  int32_T c25_i20;
  real_T c25_b_A[3];
  int32_T c25_i21;
  real_T c25_c_r[3];
  int32_T c25_i22;
  real_T c25_d_r[3];
  real_T c25_f_x;
  real_T c25_b_B;
  real_T c25_g_x;
  int32_T c25_i23;
  real_T c25_h_x[3];
  real_T c25_d_y;
  int32_T c25_i24;
  real_T c25_i_x[3];
  real_T c25_e_y;
  int32_T c25_i25;
  real_T c25_j_x[3];
  real_T c25_f_y;
  int32_T c25_i26;
  int32_T c25_i27;
  real_T c25_d_oy[3];
  int32_T c25_i28;
  real_T c25_b_oz[3];
  real_T c25_dv2[3];
  int32_T c25_i29;
  int32_T c25_i30;
  real_T c25_c_A[3];
  int32_T c25_i31;
  real_T c25_b_ox[3];
  int32_T c25_i32;
  real_T c25_c_ox[3];
  real_T c25_k_x;
  real_T c25_c_B;
  real_T c25_l_x;
  int32_T c25_i33;
  real_T c25_m_x[3];
  real_T c25_g_y;
  int32_T c25_i34;
  real_T c25_n_x[3];
  real_T c25_h_y;
  int32_T c25_i35;
  real_T c25_o_x[3];
  real_T c25_i_y;
  int32_T c25_i36;
  int32_T c25_i37;
  int32_T c25_i38;
  int32_T c25_i39;
  int32_T c25_i40;
  int32_T c25_i41;
  int32_T c25_i42;
  int32_T c25_i43;
  real_T c25_a[9];
  int32_T c25_i44;
  real_T c25_b[3];
  int32_T c25_i45;
  real_T c25_d_A[9];
  int32_T c25_i46;
  real_T c25_d_B[3];
  int32_T c25_i47;
  int32_T c25_i48;
  real_T c25_e_A[9];
  int32_T c25_i49;
  real_T c25_e_B[3];
  int32_T c25_i50;
  real_T c25_f_A[9];
  int32_T c25_i51;
  real_T c25_f_B[3];
  int32_T c25_i52;
  int32_T c25_i53;
  int32_T c25_i54;
  int32_T c25_i55;
  real_T (*c25_b_v_O)[3];
  real_T (*c25_b_v_I)[3];
  real_T (*c25_b_ECI)[6];
  c25_b_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c25_b_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c25_b_ECI = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,18);
  for (c25_i6 = 0; c25_i6 < 6; c25_i6 = c25_i6 + 1) {
    c25_ECI[c25_i6] = (*c25_b_ECI)[c25_i6];
  }

  for (c25_i7 = 0; c25_i7 < 3; c25_i7 = c25_i7 + 1) {
    c25_v_I[c25_i7] = (*c25_b_v_I)[c25_i7];
  }

  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c25_nargout, c25_d_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c25_nargin, c25_d_sf_marshall);
  sf_debug_symbol_scope_add("TOI", &c25_TOI, c25_c_sf_marshall);
  sf_debug_symbol_scope_add("ox", &c25_ox, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("oz", &c25_oz, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("oy", &c25_oy, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("v", &c25_v, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("r", &c25_r, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("v_O", &c25_v_O, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("v_I", &c25_v_I, c25_b_sf_marshall);
  sf_debug_symbol_scope_add("ECI", &c25_ECI, c25_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block gives DCM for converting from ECI to ORBIT frames */
  /*  inputs: state vector in ECI */
  /*  output: DCM */
  _SFD_EML_CALL(0,6);
  for (c25_i8 = 0; c25_i8 < 3; c25_i8 = c25_i8 + 1) {
    c25_r[c25_i8] = c25_ECI[c25_i8];
  }

  /*  position vector in ECI */
  _SFD_EML_CALL(0,7);
  for (c25_i9 = 0; c25_i9 < 3; c25_i9 = c25_i9 + 1) {
    c25_v[c25_i9] = c25_ECI[c25_i9 + 3];
  }

  /*  velocity vector in ECI */
  _SFD_EML_CALL(0,9);
  for (c25_i10 = 0; c25_i10 < 3; c25_i10 = c25_i10 + 1) {
    c25_b_v[c25_i10] = c25_v[c25_i10];
  }

  for (c25_i11 = 0; c25_i11 < 3; c25_i11 = c25_i11 + 1) {
    c25_b_r[c25_i11] = c25_r[c25_i11];
  }

  c25_cross(c25_b_v, c25_b_r, c25_dv1);
  for (c25_i12 = 0; c25_i12 < 3; c25_i12 = c25_i12 + 1) {
    c25_oy[c25_i12] = c25_dv1[c25_i12];
  }

  /*  orbit frame x... */
  _SFD_EML_CALL(0,10);
  for (c25_i13 = 0; c25_i13 < 3; c25_i13 = c25_i13 + 1) {
    c25_A[c25_i13] = c25_oy[c25_i13];
  }

  for (c25_i14 = 0; c25_i14 < 3; c25_i14 = c25_i14 + 1) {
    c25_b_oy[c25_i14] = c25_oy[c25_i14];
  }

  for (c25_i15 = 0; c25_i15 < 3; c25_i15 = c25_i15 + 1) {
    c25_c_oy[c25_i15] = c25_oy[c25_i15];
  }

  c25_x = c25_dot(c25_b_oy, c25_c_oy);
  c25_B = c25_x;
  if (c25_B < 0.0) {
    c25_eml_error();
  }

  c25_b_x = c25_B;
  c25_B = c25_b_x;
  c25_B = muDoubleScalarSqrt(c25_B);
  for (c25_i16 = 0; c25_i16 < 3; c25_i16 = c25_i16 + 1) {
    c25_c_x[c25_i16] = c25_A[c25_i16];
  }

  c25_y = c25_B;
  if (c25_y == 0.0) {
    c25_eml_warning();
  }

  for (c25_i17 = 0; c25_i17 < 3; c25_i17 = c25_i17 + 1) {
    c25_d_x[c25_i17] = c25_c_x[c25_i17];
  }

  c25_b_y = c25_y;
  for (c25_i18 = 0; c25_i18 < 3; c25_i18 = c25_i18 + 1) {
    c25_e_x[c25_i18] = c25_d_x[c25_i18];
  }

  c25_c_y = c25_b_y;
  for (c25_i19 = 0; c25_i19 < 3; c25_i19 = c25_i19 + 1) {
    c25_oy[c25_i19] = c25_e_x[c25_i19] / c25_c_y;
  }

  _SFD_EML_CALL(0,12);
  for (c25_i20 = 0; c25_i20 < 3; c25_i20 = c25_i20 + 1) {
    c25_b_A[c25_i20] = -c25_r[c25_i20];
  }

  for (c25_i21 = 0; c25_i21 < 3; c25_i21 = c25_i21 + 1) {
    c25_c_r[c25_i21] = c25_r[c25_i21];
  }

  for (c25_i22 = 0; c25_i22 < 3; c25_i22 = c25_i22 + 1) {
    c25_d_r[c25_i22] = c25_r[c25_i22];
  }

  c25_f_x = c25_dot(c25_c_r, c25_d_r);
  c25_b_B = c25_f_x;
  if (c25_b_B < 0.0) {
    c25_eml_error();
  }

  c25_g_x = c25_b_B;
  c25_b_B = c25_g_x;
  c25_b_B = muDoubleScalarSqrt(c25_b_B);
  for (c25_i23 = 0; c25_i23 < 3; c25_i23 = c25_i23 + 1) {
    c25_h_x[c25_i23] = c25_b_A[c25_i23];
  }

  c25_d_y = c25_b_B;
  if (c25_d_y == 0.0) {
    c25_eml_warning();
  }

  for (c25_i24 = 0; c25_i24 < 3; c25_i24 = c25_i24 + 1) {
    c25_i_x[c25_i24] = c25_h_x[c25_i24];
  }

  c25_e_y = c25_d_y;
  for (c25_i25 = 0; c25_i25 < 3; c25_i25 = c25_i25 + 1) {
    c25_j_x[c25_i25] = c25_i_x[c25_i25];
  }

  c25_f_y = c25_e_y;
  for (c25_i26 = 0; c25_i26 < 3; c25_i26 = c25_i26 + 1) {
    c25_oz[c25_i26] = c25_j_x[c25_i26] / c25_f_y;
  }

  _SFD_EML_CALL(0,14);
  for (c25_i27 = 0; c25_i27 < 3; c25_i27 = c25_i27 + 1) {
    c25_d_oy[c25_i27] = c25_oy[c25_i27];
  }

  for (c25_i28 = 0; c25_i28 < 3; c25_i28 = c25_i28 + 1) {
    c25_b_oz[c25_i28] = c25_oz[c25_i28];
  }

  c25_cross(c25_d_oy, c25_b_oz, c25_dv2);
  for (c25_i29 = 0; c25_i29 < 3; c25_i29 = c25_i29 + 1) {
    c25_ox[c25_i29] = c25_dv2[c25_i29];
  }

  _SFD_EML_CALL(0,15);
  for (c25_i30 = 0; c25_i30 < 3; c25_i30 = c25_i30 + 1) {
    c25_c_A[c25_i30] = c25_ox[c25_i30];
  }

  for (c25_i31 = 0; c25_i31 < 3; c25_i31 = c25_i31 + 1) {
    c25_b_ox[c25_i31] = c25_ox[c25_i31];
  }

  for (c25_i32 = 0; c25_i32 < 3; c25_i32 = c25_i32 + 1) {
    c25_c_ox[c25_i32] = c25_ox[c25_i32];
  }

  c25_k_x = c25_dot(c25_b_ox, c25_c_ox);
  c25_c_B = c25_k_x;
  if (c25_c_B < 0.0) {
    c25_eml_error();
  }

  c25_l_x = c25_c_B;
  c25_c_B = c25_l_x;
  c25_c_B = muDoubleScalarSqrt(c25_c_B);
  for (c25_i33 = 0; c25_i33 < 3; c25_i33 = c25_i33 + 1) {
    c25_m_x[c25_i33] = c25_c_A[c25_i33];
  }

  c25_g_y = c25_c_B;
  if (c25_g_y == 0.0) {
    c25_eml_warning();
  }

  for (c25_i34 = 0; c25_i34 < 3; c25_i34 = c25_i34 + 1) {
    c25_n_x[c25_i34] = c25_m_x[c25_i34];
  }

  c25_h_y = c25_g_y;
  for (c25_i35 = 0; c25_i35 < 3; c25_i35 = c25_i35 + 1) {
    c25_o_x[c25_i35] = c25_n_x[c25_i35];
  }

  c25_i_y = c25_h_y;
  for (c25_i36 = 0; c25_i36 < 3; c25_i36 = c25_i36 + 1) {
    c25_ox[c25_i36] = c25_o_x[c25_i36] / c25_i_y;
  }

  _SFD_EML_CALL(0,17);
  c25_i37 = 0;
  for (c25_i38 = 0; c25_i38 < 3; c25_i38 = c25_i38 + 1) {
    c25_TOI[c25_i37] = c25_ox[c25_i38];
    c25_i37 = c25_i37 + 3;
  }

  c25_i39 = 0;
  for (c25_i40 = 0; c25_i40 < 3; c25_i40 = c25_i40 + 1) {
    c25_TOI[c25_i39 + 1] = c25_oy[c25_i40];
    c25_i39 = c25_i39 + 3;
  }

  c25_i41 = 0;
  for (c25_i42 = 0; c25_i42 < 3; c25_i42 = c25_i42 + 1) {
    c25_TOI[c25_i41 + 2] = c25_oz[c25_i42];
    c25_i41 = c25_i41 + 3;
  }

  _SFD_EML_CALL(0,19);
  for (c25_i43 = 0; c25_i43 < 9; c25_i43 = c25_i43 + 1) {
    c25_a[c25_i43] = c25_TOI[c25_i43];
  }

  for (c25_i44 = 0; c25_i44 < 3; c25_i44 = c25_i44 + 1) {
    c25_b[c25_i44] = c25_v_I[c25_i44];
  }

  c25_b_eml_scalar_eg();
  c25_b_eml_scalar_eg();
  for (c25_i45 = 0; c25_i45 < 9; c25_i45 = c25_i45 + 1) {
    c25_d_A[c25_i45] = c25_a[c25_i45];
  }

  for (c25_i46 = 0; c25_i46 < 3; c25_i46 = c25_i46 + 1) {
    c25_d_B[c25_i46] = c25_b[c25_i46];
  }

  for (c25_i47 = 0; c25_i47 < 3; c25_i47 = c25_i47 + 1) {
    c25_v_O[c25_i47] = 0.0;
  }

  for (c25_i48 = 0; c25_i48 < 9; c25_i48 = c25_i48 + 1) {
    c25_e_A[c25_i48] = c25_d_A[c25_i48];
  }

  for (c25_i49 = 0; c25_i49 < 3; c25_i49 = c25_i49 + 1) {
    c25_e_B[c25_i49] = c25_d_B[c25_i49];
  }

  for (c25_i50 = 0; c25_i50 < 9; c25_i50 = c25_i50 + 1) {
    c25_f_A[c25_i50] = c25_e_A[c25_i50];
  }

  for (c25_i51 = 0; c25_i51 < 3; c25_i51 = c25_i51 + 1) {
    c25_f_B[c25_i51] = c25_e_B[c25_i51];
  }

  for (c25_i52 = 0; c25_i52 < 3; c25_i52 = c25_i52 + 1) {
    c25_v_O[c25_i52] = 0.0;
    c25_i53 = 0;
    for (c25_i54 = 0; c25_i54 < 3; c25_i54 = c25_i54 + 1) {
      c25_v_O[c25_i52] = c25_v_O[c25_i52] + c25_f_A[c25_i53 + c25_i52] *
        c25_f_B[c25_i54];
      c25_i53 = c25_i53 + 3;
    }
  }

  _SFD_EML_CALL(0,-19);
  sf_debug_symbol_scope_pop();
  for (c25_i55 = 0; c25_i55 < 3; c25_i55 = c25_i55 + 1) {
    (*c25_b_v_O)[c25_i55] = c25_v_O[c25_i55];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,18);
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber)
{
}

static void c25_cross(real_T c25_a[3], real_T c25_b[3], real_T c25_c[3])
{
  real_T c25_b_a;
  real_T c25_b_b;
  real_T c25_y;
  real_T c25_c_a;
  real_T c25_c_b;
  real_T c25_b_y;
  real_T c25_c1;
  real_T c25_d_a;
  real_T c25_d_b;
  real_T c25_c_y;
  real_T c25_e_a;
  real_T c25_e_b;
  real_T c25_d_y;
  real_T c25_c2;
  real_T c25_f_a;
  real_T c25_f_b;
  real_T c25_e_y;
  real_T c25_g_a;
  real_T c25_g_b;
  real_T c25_f_y;
  real_T c25_c3;
  c25_b_a = c25_a[2];
  c25_b_b = c25_b[1];
  c25_y = c25_b_a * c25_b_b;
  c25_c_a = c25_a[1];
  c25_c_b = c25_b[2];
  c25_b_y = c25_c_a * c25_c_b;
  c25_c1 = c25_b_y - c25_y;
  c25_d_a = c25_a[0];
  c25_d_b = c25_b[2];
  c25_c_y = c25_d_a * c25_d_b;
  c25_e_a = c25_a[2];
  c25_e_b = c25_b[0];
  c25_d_y = c25_e_a * c25_e_b;
  c25_c2 = c25_d_y - c25_c_y;
  c25_f_a = c25_a[1];
  c25_f_b = c25_b[0];
  c25_e_y = c25_f_a * c25_f_b;
  c25_g_a = c25_a[0];
  c25_g_b = c25_b[1];
  c25_f_y = c25_g_a * c25_g_b;
  c25_c3 = c25_f_y - c25_e_y;
  c25_c[0] = c25_c1;
  c25_c[1] = c25_c2;
  c25_c[2] = c25_c3;
}

static real_T c25_dot(real_T c25_a[3], real_T c25_b[3])
{
  int32_T c25_i56;
  real_T c25_b_a[3];
  int32_T c25_i57;
  real_T c25_b_b[3];
  int32_T c25_i58;
  real_T c25_x[3];
  int32_T c25_i59;
  real_T c25_y[3];
  int32_T c25_i60;
  real_T c25_b_x[3];
  int32_T c25_i61;
  real_T c25_b_y[3];
  int32_T c25_i62;
  real_T c25_c_x[3];
  int32_T c25_i63;
  real_T c25_c_y[3];
  int32_T c25_i64;
  real_T c25_d_x[3];
  int32_T c25_i65;
  real_T c25_d_y[3];
  c25_eml_scalar_eg();
  for (c25_i56 = 0; c25_i56 < 3; c25_i56 = c25_i56 + 1) {
    c25_b_a[c25_i56] = c25_a[c25_i56];
  }

  for (c25_i57 = 0; c25_i57 < 3; c25_i57 = c25_i57 + 1) {
    c25_b_b[c25_i57] = c25_b[c25_i57];
  }

  for (c25_i58 = 0; c25_i58 < 3; c25_i58 = c25_i58 + 1) {
    c25_x[c25_i58] = c25_b_a[c25_i58];
  }

  for (c25_i59 = 0; c25_i59 < 3; c25_i59 = c25_i59 + 1) {
    c25_y[c25_i59] = c25_b_b[c25_i59];
  }

  for (c25_i60 = 0; c25_i60 < 3; c25_i60 = c25_i60 + 1) {
    c25_b_x[c25_i60] = c25_x[c25_i60];
  }

  for (c25_i61 = 0; c25_i61 < 3; c25_i61 = c25_i61 + 1) {
    c25_b_y[c25_i61] = c25_y[c25_i61];
  }

  for (c25_i62 = 0; c25_i62 < 3; c25_i62 = c25_i62 + 1) {
    c25_c_x[c25_i62] = c25_b_x[c25_i62];
  }

  for (c25_i63 = 0; c25_i63 < 3; c25_i63 = c25_i63 + 1) {
    c25_c_y[c25_i63] = c25_b_y[c25_i63];
  }

  for (c25_i64 = 0; c25_i64 < 3; c25_i64 = c25_i64 + 1) {
    c25_d_x[c25_i64] = c25_c_x[c25_i64];
  }

  for (c25_i65 = 0; c25_i65 < 3; c25_i65 = c25_i65 + 1) {
    c25_d_y[c25_i65] = c25_c_y[c25_i65];
  }

  return c25_ceval_xdot(3, c25_d_x, 1, 1, c25_d_y, 1, 1);
}

static void c25_eml_scalar_eg(void)
{
}

static real_T c25_ceval_xdot(int32_T c25_n, real_T c25_x[3], int32_T c25_ix0,
  int32_T c25_incx, real_T c25_y[3], int32_T c25_iy0,
  int32_T c25_incy)
{
  real_T c25_d;
  c25_d = 0.0;
  if ((real_T)c25_n > 0.0) {
    return ddot32(&c25_n, &c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c25_ix0), 1, 3, 1, 0) - 1]
                  , &c25_incx, &c25_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c25_iy0), 1, 3, 1, 0) - 1], &
                  c25_incy);
  }

  return c25_d;
}

static void c25_eml_error(void)
{
  int32_T c25_i66;
  static char_T c25_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c25_u[77];
  const mxArray *c25_y = NULL;
  int32_T c25_i67;
  static char_T c25_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c25_b_u[31];
  const mxArray *c25_b_y = NULL;
  for (c25_i66 = 0; c25_i66 < 77; c25_i66 = c25_i66 + 1) {
    c25_u[c25_i66] = c25_cv0[c25_i66];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c25_i67 = 0; c25_i67 < 31; c25_i67 = c25_i67 + 1) {
    c25_b_u[c25_i67] = c25_cv1[c25_i67];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c25_b_y, 14, c25_y);
}

static void c25_eml_warning(void)
{
  int32_T c25_i68;
  static char_T c25_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c25_u[15];
  const mxArray *c25_y = NULL;
  int32_T c25_i69;
  static char_T c25_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c25_b_u[19];
  const mxArray *c25_b_y = NULL;
  for (c25_i68 = 0; c25_i68 < 15; c25_i68 = c25_i68 + 1) {
    c25_u[c25_i68] = c25_cv2[c25_i68];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c25_i69 = 0; c25_i69 < 19; c25_i69 = c25_i69 + 1) {
    c25_b_u[c25_i69] = c25_cv3[c25_i69];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c25_b_y, 14, c25_y);
}

static void c25_b_eml_scalar_eg(void)
{
}

static const mxArray *c25_sf_marshall(void *c25_chartInstance, void *c25_u)
{
  const mxArray *c25_y = NULL;
  int32_T c25_i70;
  real_T c25_b_u[6];
  const mxArray *c25_b_y = NULL;
  c25_y = NULL;
  for (c25_i70 = 0; c25_i70 < 6; c25_i70 = c25_i70 + 1) {
    c25_b_u[c25_i70] = (*((real_T (*)[6])c25_u))[c25_i70];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c25_y, c25_b_y);
  return c25_y;
}

static const mxArray *c25_b_sf_marshall(void *c25_chartInstance, void *c25_u)
{
  const mxArray *c25_y = NULL;
  int32_T c25_i71;
  real_T c25_b_u[3];
  const mxArray *c25_b_y = NULL;
  c25_y = NULL;
  for (c25_i71 = 0; c25_i71 < 3; c25_i71 = c25_i71 + 1) {
    c25_b_u[c25_i71] = (*((real_T (*)[3])c25_u))[c25_i71];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c25_y, c25_b_y);
  return c25_y;
}

static const mxArray *c25_c_sf_marshall(void *c25_chartInstance, void *c25_u)
{
  const mxArray *c25_y = NULL;
  int32_T c25_i72;
  int32_T c25_i73;
  int32_T c25_i74;
  real_T c25_b_u[9];
  const mxArray *c25_b_y = NULL;
  c25_y = NULL;
  c25_i72 = 0;
  for (c25_i73 = 0; c25_i73 < 3; c25_i73 = c25_i73 + 1) {
    for (c25_i74 = 0; c25_i74 < 3; c25_i74 = c25_i74 + 1) {
      c25_b_u[c25_i74 + c25_i72] = (*((real_T (*)[9])c25_u))[c25_i74 + c25_i72];
    }

    c25_i72 = c25_i72 + 3;
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c25_y, c25_b_y);
  return c25_y;
}

static const mxArray *c25_d_sf_marshall(void *c25_chartInstance, void *c25_u)
{
  const mxArray *c25_y = NULL;
  real_T c25_b_u;
  const mxArray *c25_b_y = NULL;
  c25_y = NULL;
  c25_b_u = *((real_T *)c25_u);
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c25_y, c25_b_y);
  return c25_y;
}

const mxArray
  *sf_c25_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_ResolvedFunctionInfo c25_info[61];
  const mxArray *c25_m0 = NULL;
  int32_T c25_i75;
  c25_ResolvedFunctionInfo *c25_r0;
  c25_nameCaptureInfo = NULL;
  c25_info_helper(c25_info);
  sf_mex_assign(&c25_m0, sf_mex_createstruct("nameCaptureInfo", 1, 61));
  for (c25_i75 = 0; c25_i75 < 61; c25_i75 = c25_i75 + 1) {
    c25_r0 = &c25_info[c25_i75];
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", c25_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c25_r0->context)), "context"
                    , "nameCaptureInfo", c25_i75);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", c25_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c25_r0->name)), "name",
                    "nameCaptureInfo", c25_i75);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo",
      c25_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c25_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c25_i75);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", c25_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c25_r0->resolved)),
                    "resolved", "nameCaptureInfo", c25_i75);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", &c25_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c25_i75);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", &c25_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c25_i75);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", &c25_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c25_i75);
  }

  sf_mex_assign(&c25_nameCaptureInfo, c25_m0);
  return c25_nameCaptureInfo;
}

static void c25_info_helper(c25_ResolvedFunctionInfo c25_info[61])
{
  c25_info[0].context = "";
  c25_info[0].name = "cross";
  c25_info[0].dominantType = "double";
  c25_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[0].fileLength = 3157U;
  c25_info[0].fileTime1 = 1240249462U;
  c25_info[0].fileTime2 = 0U;
  c25_info[1].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[1].name = "nargin";
  c25_info[1].dominantType = "";
  c25_info[1].resolved = "[B]nargin";
  c25_info[1].fileLength = 0U;
  c25_info[1].fileTime1 = 0U;
  c25_info[1].fileTime2 = 0U;
  c25_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[2].name = "gt";
  c25_info[2].dominantType = "double";
  c25_info[2].resolved = "[B]gt";
  c25_info[2].fileLength = 0U;
  c25_info[2].fileTime1 = 0U;
  c25_info[2].fileTime2 = 0U;
  c25_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[3].name = "eq";
  c25_info[3].dominantType = "double";
  c25_info[3].resolved = "[B]eq";
  c25_info[3].fileLength = 0U;
  c25_info[3].fileTime1 = 0U;
  c25_info[3].fileTime2 = 0U;
  c25_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[4].name = "isa";
  c25_info[4].dominantType = "double";
  c25_info[4].resolved = "[B]isa";
  c25_info[4].fileLength = 0U;
  c25_info[4].fileTime1 = 0U;
  c25_info[4].fileTime2 = 0U;
  c25_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[5].name = "isvector";
  c25_info[5].dominantType = "double";
  c25_info[5].resolved = "[B]isvector";
  c25_info[5].fileLength = 0U;
  c25_info[5].fileTime1 = 0U;
  c25_info[5].fileTime2 = 0U;
  c25_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[6].name = "mtimes";
  c25_info[6].dominantType = "double";
  c25_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[6].fileLength = 3302U;
  c25_info[6].fileTime1 = 1242738294U;
  c25_info[6].fileTime2 = 0U;
  c25_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[7].name = "isinteger";
  c25_info[7].dominantType = "double";
  c25_info[7].resolved = "[B]isinteger";
  c25_info[7].fileLength = 0U;
  c25_info[7].fileTime1 = 0U;
  c25_info[7].fileTime2 = 0U;
  c25_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[8].name = "isscalar";
  c25_info[8].dominantType = "double";
  c25_info[8].resolved = "[B]isscalar";
  c25_info[8].fileLength = 0U;
  c25_info[8].fileTime1 = 0U;
  c25_info[8].fileTime2 = 0U;
  c25_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[9].name = "strcmp";
  c25_info[9].dominantType = "char";
  c25_info[9].resolved = "[B]strcmp";
  c25_info[9].fileLength = 0U;
  c25_info[9].fileTime1 = 0U;
  c25_info[9].fileTime2 = 0U;
  c25_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[10].name = "size";
  c25_info[10].dominantType = "double";
  c25_info[10].resolved = "[B]size";
  c25_info[10].fileLength = 0U;
  c25_info[10].fileTime1 = 0U;
  c25_info[10].fileTime2 = 0U;
  c25_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[11].name = "class";
  c25_info[11].dominantType = "double";
  c25_info[11].resolved = "[B]class";
  c25_info[11].fileLength = 0U;
  c25_info[11].fileTime1 = 0U;
  c25_info[11].fileTime2 = 0U;
  c25_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[12].name = "not";
  c25_info[12].dominantType = "logical";
  c25_info[12].resolved = "[B]not";
  c25_info[12].fileLength = 0U;
  c25_info[12].fileTime1 = 0U;
  c25_info[12].fileTime2 = 0U;
  c25_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c25_info[13].name = "minus";
  c25_info[13].dominantType = "double";
  c25_info[13].resolved = "[B]minus";
  c25_info[13].fileLength = 0U;
  c25_info[13].fileTime1 = 0U;
  c25_info[13].fileTime2 = 0U;
  c25_info[14].context = "";
  c25_info[14].name = "dot";
  c25_info[14].dominantType = "double";
  c25_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[14].fileLength = 2812U;
  c25_info[14].fileTime1 = 1236241088U;
  c25_info[14].fileTime2 = 0U;
  c25_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[15].name = "isequal";
  c25_info[15].dominantType = "double";
  c25_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c25_info[15].fileLength = 180U;
  c25_info[15].fileTime1 = 1226561072U;
  c25_info[15].fileTime2 = 0U;
  c25_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c25_info[16].name = "false";
  c25_info[16].dominantType = "";
  c25_info[16].resolved = "[B]false";
  c25_info[16].fileLength = 0U;
  c25_info[16].fileTime1 = 0U;
  c25_info[16].fileTime2 = 0U;
  c25_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c25_info[17].name = "eml_isequal_core";
  c25_info[17].dominantType = "double";
  c25_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c25_info[17].fileLength = 3981U;
  c25_info[17].fileTime1 = 1236241072U;
  c25_info[17].fileTime2 = 0U;
  c25_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c25_info[18].name = "ge";
  c25_info[18].dominantType = "double";
  c25_info[18].resolved = "[B]ge";
  c25_info[18].fileLength = 0U;
  c25_info[18].fileTime1 = 0U;
  c25_info[18].fileTime2 = 0U;
  c25_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c25_info[19].name = "islogical";
  c25_info[19].dominantType = "logical";
  c25_info[19].resolved = "[B]islogical";
  c25_info[19].fileLength = 0U;
  c25_info[19].fileTime1 = 0U;
  c25_info[19].fileTime2 = 0U;
  c25_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c25_info[20].name = "isnumeric";
  c25_info[20].dominantType = "double";
  c25_info[20].resolved = "[B]isnumeric";
  c25_info[20].fileLength = 0U;
  c25_info[20].fileTime1 = 0U;
  c25_info[20].fileTime2 = 0U;
  c25_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c25_info[21].name = "ndims";
  c25_info[21].dominantType = "double";
  c25_info[21].resolved = "[B]ndims";
  c25_info[21].fileLength = 0U;
  c25_info[21].fileTime1 = 0U;
  c25_info[21].fileTime2 = 0U;
  c25_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c25_info[22].name = "ne";
  c25_info[22].dominantType = "double";
  c25_info[22].resolved = "[B]ne";
  c25_info[22].fileLength = 0U;
  c25_info[22].fileTime1 = 0U;
  c25_info[22].fileTime2 = 0U;
  c25_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c25_info[23].name = "true";
  c25_info[23].dominantType = "";
  c25_info[23].resolved = "[B]true";
  c25_info[23].fileLength = 0U;
  c25_info[23].fileTime1 = 0U;
  c25_info[23].fileTime2 = 0U;
  c25_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c25_info[24].name = "isstruct";
  c25_info[24].dominantType = "double";
  c25_info[24].resolved = "[B]isstruct";
  c25_info[24].fileLength = 0U;
  c25_info[24].fileTime1 = 0U;
  c25_info[24].fileTime2 = 0U;
  c25_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c25_info[25].name = "isempty";
  c25_info[25].dominantType = "double";
  c25_info[25].resolved = "[B]isempty";
  c25_info[25].fileLength = 0U;
  c25_info[25].fileTime1 = 0U;
  c25_info[25].fileTime2 = 0U;
  c25_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c25_info[26].name = "isnan";
  c25_info[26].dominantType = "double";
  c25_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c25_info[26].fileLength = 506U;
  c25_info[26].fileTime1 = 1228077610U;
  c25_info[26].fileTime2 = 0U;
  c25_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c25_info[27].name = "isreal";
  c25_info[27].dominantType = "double";
  c25_info[27].resolved = "[B]isreal";
  c25_info[27].fileLength = 0U;
  c25_info[27].fileTime1 = 0U;
  c25_info[27].fileTime2 = 0U;
  c25_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[28].name = "eml_index_class";
  c25_info[28].dominantType = "";
  c25_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c25_info[28].fileLength = 909U;
  c25_info[28].fileTime1 = 1192454182U;
  c25_info[28].fileTime2 = 0U;
  c25_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[29].name = "ones";
  c25_info[29].dominantType = "char";
  c25_info[29].resolved = "[B]ones";
  c25_info[29].fileLength = 0U;
  c25_info[29].fileTime1 = 0U;
  c25_info[29].fileTime2 = 0U;
  c25_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[30].name = "isfloat";
  c25_info[30].dominantType = "double";
  c25_info[30].resolved = "[B]isfloat";
  c25_info[30].fileLength = 0U;
  c25_info[30].fileTime1 = 0U;
  c25_info[30].fileTime2 = 0U;
  c25_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[31].name = "eml_scalar_eg";
  c25_info[31].dominantType = "double";
  c25_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c25_info[31].fileLength = 3068U;
  c25_info[31].fileTime1 = 1240249410U;
  c25_info[31].fileTime2 = 0U;
  c25_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c25_info[32].name = "cast";
  c25_info[32].dominantType = "double";
  c25_info[32].resolved = "[B]cast";
  c25_info[32].fileLength = 0U;
  c25_info[32].fileTime1 = 0U;
  c25_info[32].fileTime2 = 0U;
  c25_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c25_info[33].name = "plus";
  c25_info[33].dominantType = "double";
  c25_info[33].resolved = "[B]plus";
  c25_info[33].fileLength = 0U;
  c25_info[33].fileTime1 = 0U;
  c25_info[33].fileTime2 = 0U;
  c25_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c25_info[34].name = "lt";
  c25_info[34].dominantType = "double";
  c25_info[34].resolved = "[B]lt";
  c25_info[34].fileLength = 0U;
  c25_info[34].fileTime1 = 0U;
  c25_info[34].fileTime2 = 0U;
  c25_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c25_info[35].name = "eml_xdotc";
  c25_info[35].dominantType = "int32";
  c25_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c25_info[35].fileLength = 1453U;
  c25_info[35].fileTime1 = 1209318250U;
  c25_info[35].fileTime2 = 0U;
  c25_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c25_info[36].name = "eml_xdot";
  c25_info[36].dominantType = "int32";
  c25_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c25_info[36].fileLength = 1330U;
  c25_info[36].fileTime1 = 1209318250U;
  c25_info[36].fileTime2 = 0U;
  c25_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c25_info[37].name = "eml_refblas_xdot";
  c25_info[37].dominantType = "int32";
  c25_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c25_info[37].fileLength = 343U;
  c25_info[37].fileTime1 = 1211203444U;
  c25_info[37].fileTime2 = 0U;
  c25_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c25_info[38].name = "eml_refblas_xdotx";
  c25_info[38].dominantType = "int32";
  c25_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c25_info[38].fileLength = 1605U;
  c25_info[38].fileTime1 = 1236241080U;
  c25_info[38].fileTime2 = 0U;
  c25_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c25_info[39].name = "ischar";
  c25_info[39].dominantType = "char";
  c25_info[39].resolved = "[B]ischar";
  c25_info[39].fileLength = 0U;
  c25_info[39].fileTime1 = 0U;
  c25_info[39].fileTime2 = 0U;
  c25_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c25_info[40].name = "times";
  c25_info[40].dominantType = "double";
  c25_info[40].resolved = "[B]times";
  c25_info[40].fileLength = 0U;
  c25_info[40].fileTime1 = 0U;
  c25_info[40].fileTime2 = 0U;
  c25_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c25_info[41].name = "uminus";
  c25_info[41].dominantType = "int32";
  c25_info[41].resolved = "[B]uminus";
  c25_info[41].fileLength = 0U;
  c25_info[41].fileTime1 = 0U;
  c25_info[41].fileTime2 = 0U;
  c25_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c25_info[42].name = "eml_index_minus";
  c25_info[42].dominantType = "int32";
  c25_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c25_info[42].fileLength = 277U;
  c25_info[42].fileTime1 = 1192454184U;
  c25_info[42].fileTime2 = 0U;
  c25_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c25_info[43].name = "eml_index_plus";
  c25_info[43].dominantType = "int32";
  c25_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c25_info[43].fileLength = 272U;
  c25_info[43].fileTime1 = 1192454186U;
  c25_info[43].fileTime2 = 0U;
  c25_info[44].context = "";
  c25_info[44].name = "sqrt";
  c25_info[44].dominantType = "double";
  c25_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c25_info[44].fileLength = 572U;
  c25_info[44].fileTime1 = 1203431846U;
  c25_info[44].fileTime2 = 0U;
  c25_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c25_info[45].name = "eml_error";
  c25_info[45].dominantType = "char";
  c25_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c25_info[45].fileLength = 315U;
  c25_info[45].fileTime1 = 1213914146U;
  c25_info[45].fileTime2 = 0U;
  c25_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c25_info[46].name = "eml_scalar_sqrt";
  c25_info[46].dominantType = "double";
  c25_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c25_info[46].fileLength = 664U;
  c25_info[46].fileTime1 = 1209318194U;
  c25_info[46].fileTime2 = 0U;
  c25_info[47].context = "";
  c25_info[47].name = "mrdivide";
  c25_info[47].dominantType = "double";
  c25_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c25_info[47].fileLength = 800U;
  c25_info[47].fileTime1 = 1238421692U;
  c25_info[47].fileTime2 = 0U;
  c25_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c25_info[48].name = "rdivide";
  c25_info[48].dominantType = "double";
  c25_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c25_info[48].fileLength = 620U;
  c25_info[48].fileTime1 = 1213914166U;
  c25_info[48].fileTime2 = 0U;
  c25_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c25_info[49].name = "eml_warning";
  c25_info[49].dominantType = "char";
  c25_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c25_info[49].fileLength = 262U;
  c25_info[49].fileTime1 = 1236241078U;
  c25_info[49].fileTime2 = 0U;
  c25_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c25_info[50].name = "eml_div";
  c25_info[50].dominantType = "double";
  c25_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c25_info[50].fileLength = 4269U;
  c25_info[50].fileTime1 = 1228077626U;
  c25_info[50].fileTime2 = 0U;
  c25_info[51].context = "";
  c25_info[51].name = "ctranspose";
  c25_info[51].dominantType = "double";
  c25_info[51].resolved = "[B]ctranspose";
  c25_info[51].fileLength = 0U;
  c25_info[51].fileTime1 = 0U;
  c25_info[51].fileTime2 = 0U;
  c25_info[52].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[52].name = "le";
  c25_info[52].dominantType = "double";
  c25_info[52].resolved = "[B]le";
  c25_info[52].fileLength = 0U;
  c25_info[52].fileTime1 = 0U;
  c25_info[52].fileTime2 = 0U;
  c25_info[53].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c25_info[53].name = "eml_xgemm";
  c25_info[53].dominantType = "int32";
  c25_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c25_info[53].fileLength = 3184U;
  c25_info[53].fileTime1 = 1209318252U;
  c25_info[53].fileTime2 = 0U;
  c25_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c25_info[54].name = "length";
  c25_info[54].dominantType = "double";
  c25_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c25_info[54].fileLength = 326U;
  c25_info[54].fileTime1 = 1226561076U;
  c25_info[54].fileTime2 = 0U;
  c25_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c25_info[55].name = "min";
  c25_info[55].dominantType = "double";
  c25_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c25_info[55].fileLength = 308U;
  c25_info[55].fileTime1 = 1192454034U;
  c25_info[55].fileTime2 = 0U;
  c25_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c25_info[56].name = "nargout";
  c25_info[56].dominantType = "";
  c25_info[56].resolved = "[B]nargout";
  c25_info[56].fileLength = 0U;
  c25_info[56].fileTime1 = 0U;
  c25_info[56].fileTime2 = 0U;
  c25_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c25_info[57].name = "eml_min_or_max";
  c25_info[57].dominantType = "char";
  c25_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c25_info[57].fileLength = 9969U;
  c25_info[57].fileTime1 = 1240249408U;
  c25_info[57].fileTime2 = 0U;
  c25_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c25_info[58].name = "eml_scalexp_alloc";
  c25_info[58].dominantType = "double";
  c25_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c25_info[58].fileLength = 808U;
  c25_info[58].fileTime1 = 1230478500U;
  c25_info[58].fileTime2 = 0U;
  c25_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c25_info[59].name = "eml_refblas_xgemm";
  c25_info[59].dominantType = "int32";
  c25_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c25_info[59].fileLength = 5748U;
  c25_info[59].fileTime1 = 1228077674U;
  c25_info[59].fileTime2 = 0U;
  c25_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c25_info[60].name = "eml_index_times";
  c25_info[60].dominantType = "int32";
  c25_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c25_info[60].fileLength = 280U;
  c25_info[60].fileTime1 = 1192454188U;
  c25_info[60].fileTime2 = 0U;
}

static const mxArray *c25_e_sf_marshall(void *c25_chartInstance, void *c25_u)
{
  const mxArray *c25_y = NULL;
  boolean_T c25_b_u;
  const mxArray *c25_b_y = NULL;
  c25_y = NULL;
  c25_b_u = *((boolean_T *)c25_u);
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c25_y, c25_b_y);
  return c25_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c25_adcs_v15_integral_Power_nom_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1536414087U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2567120209U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3388750256U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3423742336U);
}

mxArray *sf_c25_adcs_v15_integral_Power_nom_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4178958154U);
    pr[1] = (double)(3069588916U);
    pr[2] = (double)(1895436190U);
    pr[3] = (double)(3924267666U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

static mxArray *sf_get_sim_state_info_c25_adcs_v15_integral_Power_nom(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_O\",},{M[8],M[0],T\"is_active_c25_adcs_v15_integral_Power_nom\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_adcs_v15_integral_Power_nom_get_check_sum(&mxChecksum);
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
          (_adcs_v15_integral_Power_nomMachineNumber_,
           25,
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
            (_adcs_v15_integral_Power_nomMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_adcs_v15_integral_Power_nomMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_adcs_v15_integral_Power_nomMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ECI",0,(MexFcnForType)c25_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_O",0,(MexFcnForType)c25_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_I",0,(MexFcnForType)c25_b_sf_marshall);
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
          real_T (*c25_ECI)[6];
          real_T (*c25_v_O)[3];
          real_T (*c25_v_I)[3];
          c25_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c25_v_O = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c25_ECI = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c25_ECI);
          _SFD_SET_DATA_VALUE_PTR(1U, c25_v_O);
          _SFD_SET_DATA_VALUE_PTR(2U, c25_v_I);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_nomMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c25_adcs_v15_integral_Power_nom();
  initialize_c25_adcs_v15_integral_Power_nom();
}

static void sf_opaque_enable_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  enable_c25_adcs_v15_integral_Power_nom();
}

static void sf_opaque_disable_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  disable_c25_adcs_v15_integral_Power_nom();
}

static void sf_opaque_gateway_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  sf_c25_adcs_v15_integral_Power_nom();
}

static void sf_opaque_ext_mode_exec_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  ext_mode_exec_c25_adcs_v15_integral_Power_nom();
}

static mxArray* sf_opaque_get_sim_state_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c25_adcs_v15_integral_Power_nom();
  return st;
}

static void sf_opaque_set_sim_state_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c25_adcs_v15_integral_Power_nom(sf_mex_dup(st));
}

static void sf_opaque_terminate_c25_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c25_adcs_v15_integral_Power_nom();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_adcs_v15_integral_Power_nom(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c25_adcs_v15_integral_Power_nom();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c25_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_nom",
                "adcs_v15_integral_Power_nom",25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom","adcs_v15_integral_Power_nom",25,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",25,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",25,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom",
                          "adcs_v15_integral_Power_nom",25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1090043337U));
  ssSetChecksum1(S,(3899404654U));
  ssSetChecksum2(S,(4230352522U));
  ssSetChecksum3(S,(1093437847U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c25_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",25);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_adcs_v15_integral_Power_nom(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlStart = mdlStart_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c25_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c25_adcs_v15_integral_Power_nom;
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

void c25_adcs_v15_integral_Power_nom_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_adcs_v15_integral_Power_nom(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_adcs_v15_integral_Power_nom_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
