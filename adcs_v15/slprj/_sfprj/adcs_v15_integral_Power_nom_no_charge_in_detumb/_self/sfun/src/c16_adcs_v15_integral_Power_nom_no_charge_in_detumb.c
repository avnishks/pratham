/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun.h"
#include "c16_adcs_v15_integral_Power_nom_no_charge_in_detumb.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c16_IN_NO_ACTIVE_CHILD         (0)
#define c16_b_side                     (0.26)

/* Variable Declarations */

/* Variable Definitions */
static SFc16_adcs_v15_integral_Power_nom_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void
  initialize_params_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void enable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void disable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c16_update_debugger_state_c16_adcs_v15_integral_Power_nom_no_ch(void);
static void ext_mode_exec_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void);
static const mxArray
  *get_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void set_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c16_st);
static void finalize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c16_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static real_T c16_dot(real_T c16_b_a[3], real_T c16_b[3]);
static void c16_eml_scalar_eg(void);
static real_T c16_ceval_xdot(int32_T c16_n, real_T c16_x[3], int32_T c16_ix0,
  int32_T c16_incx, real_T c16_y[3], int32_T c16_iy0, int32_T c16_incy);
static void c16_eml_error(void);
static void c16_eml_warning(void);
static const mxArray *c16_sf_marshall(void *c16_chartInstance, void *c16_u);
static const mxArray *c16_b_sf_marshall(void *c16_chartInstance, void *c16_u);
static const mxArray *c16_c_sf_marshall(void *c16_chartInstance, void *c16_u);
static void c16_info_helper(c16_ResolvedFunctionInfo c16_info[56]);
static const mxArray *c16_d_sf_marshall(void *c16_chartInstance, void *c16_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  uint8_T *c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu;
  c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu = 0U;
}

static void
  initialize_params_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  real_T c16_d0;
  real_T c16_d1;
  real_T c16_dv0[3];
  int32_T c16_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'side' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c16_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c16_side = c16_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Cd' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c16_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c16_Cd = c16_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'v_COM_to_COP_b' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    2, 0), &c16_dv0, 0, 0, 0U, 1, 0U, 1, 3);
  for (c16_i0 = 0; c16_i0 < 3; c16_i0 = c16_i0 + 1) {
    chartInstance.c16_v_COM_to_COP_b[c16_i0] = c16_dv0[c16_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c16_update_debugger_state_c16_adcs_v15_integral_Power_nom_no_ch(void)
{
}

static void ext_mode_exec_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  c16_update_debugger_state_c16_adcs_v15_integral_Power_nom_no_ch();
}

static const mxArray
  *get_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  const mxArray *c16_st = NULL;
  const mxArray *c16_y = NULL;
  int32_T c16_i1;
  real_T c16_u[3];
  const mxArray *c16_b_y = NULL;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  uint8_T *c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu;
  real_T (*c16_u_aero)[3];
  c16_u_aero = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(2));
  for (c16_i1 = 0; c16_i1 < 3; c16_i1 = c16_i1 + 1) {
    c16_u[c16_i1] = (*c16_u_aero)[c16_i1];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_u = *c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y);
  return c16_st;
}

static void set_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c16_st)
{
  const mxArray *c16_u;
  const mxArray *c16_u_aero;
  real_T c16_dv1[3];
  int32_T c16_i2;
  real_T c16_y[3];
  int32_T c16_i3;
  const mxArray *c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu;
  uint8_T c16_u0;
  uint8_T c16_b_y;
  boolean_T *c16_doneDoubleBufferReInit;
  uint8_T *c16_b_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_de;
  real_T (*c16_b_u_aero)[3];
  c16_b_u_aero = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c16_b_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_de = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c16_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c16_doneDoubleBufferReInit = true;
  c16_u = sf_mex_dup(c16_st);
  c16_u_aero = sf_mex_dup(sf_mex_getcell(c16_u, 0));
  sf_mex_import("u_aero", sf_mex_dup(c16_u_aero), &c16_dv1, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c16_i2 = 0; c16_i2 < 3; c16_i2 = c16_i2 + 1) {
    c16_y[c16_i2] = c16_dv1[c16_i2];
  }

  sf_mex_destroy(&c16_u_aero);
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    (*c16_b_u_aero)[c16_i3] = c16_y[c16_i3];
  }

  c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu = sf_mex_dup
    (sf_mex_getcell(c16_u, 1));
  sf_mex_import("is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb",
                sf_mex_dup(
    c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu), &c16_u0, 1,
                3, 0U, 0, 0U, 0);
  c16_b_y = c16_u0;
  sf_mex_destroy
    (&c16_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detu);
  *c16_b_is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_de = c16_b_y;
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_adcs_v15_integral_Power_nom_no_ch();
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
}

static void sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  int32_T c16_i4;
  int32_T c16_i5;
  int32_T c16_i6;
  int32_T c16_previousEvent;
  real_T *c16_rho;
  real_T (*c16_u_aero)[3];
  real_T (*c16_v_B)[3];
  c16_rho = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c16_u_aero = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c16_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,12);
  _SFD_DATA_RANGE_CHECK(*c16_rho, 0U);
  for (c16_i4 = 0; c16_i4 < 3; c16_i4 = c16_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c16_v_B)[c16_i4], 1U);
  }

  for (c16_i5 = 0; c16_i5 < 3; c16_i5 = c16_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c16_u_aero)[c16_i5], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c16_side, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c16_Cd, 4U);
  for (c16_i6 = 0; c16_i6 < 3; c16_i6 = c16_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c16_v_COM_to_COP_b[c16_i6], 5U);
  }

  c16_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c16_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  _sfEvent_ = c16_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c16_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  real_T c16_rho;
  int32_T c16_i7;
  real_T c16_v_B[3];
  real_T c16_b_Cd;
  real_T c16_nargout = 1.0;
  real_T c16_nargin = 5.0;
  real_T c16_b_v_COM_to_COP_b[3] = { 0.002, 0.0175, 0.002 };

  real_T c16_c_side = c16_b_side;
  real_T c16_F_aero[3];
  real_T c16_Ap;
  real_T c16_x;
  real_T c16_i;
  real_T c16_b[18];
  real_T c16_b_a;
  real_T c16_y;
  real_T c16_v_unit[3];
  real_T c16_vnorm;
  real_T c16_u_aero[3];
  int32_T c16_i8;
  real_T c16_b_v_B[3];
  int32_T c16_i9;
  real_T c16_c_v_B[3];
  real_T c16_b_x;
  real_T c16_c_x;
  int32_T c16_i10;
  real_T c16_A[3];
  real_T c16_B;
  int32_T c16_i11;
  real_T c16_d_x[3];
  real_T c16_b_y;
  int32_T c16_i12;
  real_T c16_e_x[3];
  real_T c16_c_y;
  int32_T c16_i13;
  real_T c16_f_x[3];
  real_T c16_d_y;
  int32_T c16_i14;
  int32_T c16_i15;
  int32_T c16_i16;
  static real_T c16_dv2[3] = { 6.7600000000000007E-002, 0.0, 0.0 };

  int32_T c16_i17;
  static real_T c16_dv3[3] = { 0.0, 6.7600000000000007E-002, 0.0 };

  int32_T c16_i18;
  static real_T c16_dv4[3] = { 0.0, 0.0, 6.7600000000000007E-002 };

  int32_T c16_i19;
  static real_T c16_dv5[3] = { -6.7600000000000007E-002, 0.0, 0.0 };

  int32_T c16_i20;
  static real_T c16_dv6[3] = { 0.0, -6.7600000000000007E-002, 0.0 };

  int32_T c16_i21;
  static real_T c16_dv7[3] = { 0.0, 0.0, -6.7600000000000007E-002 };

  real_T c16_b_i;
  int32_T c16_c_i;
  int32_T c16_i22;
  real_T c16_b_b[3];
  int32_T c16_i23;
  real_T c16_b_v_unit[3];
  real_T c16_c_b;
  real_T c16_c_a;
  real_T c16_d_b;
  real_T c16_d_a;
  real_T c16_e_b;
  real_T c16_e_a;
  real_T c16_f_a;
  real_T c16_g_a;
  real_T c16_ak;
  real_T c16_f_b;
  real_T c16_h_a;
  int32_T c16_i24;
  real_T c16_g_b[3];
  int32_T c16_i25;
  int32_T c16_i26;
  real_T c16_h_b[3];
  real_T c16_i_b;
  real_T c16_e_y;
  real_T c16_j_b;
  real_T c16_f_y;
  real_T c16_c1;
  real_T c16_k_b;
  real_T c16_g_y;
  real_T c16_l_b;
  real_T c16_h_y;
  real_T c16_c2;
  real_T c16_m_b;
  real_T c16_i_y;
  real_T c16_n_b;
  real_T c16_j_y;
  real_T c16_c3;
  int32_T c16_i27;
  real_T *c16_b_rho;
  real_T (*c16_b_u_aero)[3];
  real_T (*c16_d_v_B)[3];
  c16_b_rho = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c16_b_u_aero = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c16_d_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,12);
  c16_rho = *c16_b_rho;
  for (c16_i7 = 0; c16_i7 < 3; c16_i7 = c16_i7 + 1) {
    c16_v_B[c16_i7] = (*c16_d_v_B)[c16_i7];
  }

  c16_b_Cd = chartInstance.c16_Cd;
  sf_debug_symbol_scope_push(17U, 0U);
  sf_debug_symbol_scope_add("nargout", &c16_nargout, c16_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c16_nargin, c16_sf_marshall);
  sf_debug_symbol_scope_add("v_COM_to_COP_b", &c16_b_v_COM_to_COP_b,
    c16_b_sf_marshall);
  sf_debug_symbol_scope_add("side", &c16_c_side, c16_sf_marshall);
  sf_debug_symbol_scope_add("F_aero", &c16_F_aero, c16_b_sf_marshall);
  sf_debug_symbol_scope_add("Ap", &c16_Ap, c16_sf_marshall);
  sf_debug_symbol_scope_add("x", &c16_x, c16_sf_marshall);
  sf_debug_symbol_scope_add("i", &c16_i, c16_sf_marshall);
  sf_debug_symbol_scope_add("b", &c16_b, c16_c_sf_marshall);
  sf_debug_symbol_scope_add("a", &c16_b_a, c16_sf_marshall);
  sf_debug_symbol_scope_add("y", &c16_y, c16_sf_marshall);
  sf_debug_symbol_scope_add("v_unit", &c16_v_unit, c16_b_sf_marshall);
  sf_debug_symbol_scope_add("vnorm", &c16_vnorm, c16_sf_marshall);
  sf_debug_symbol_scope_add("u_aero", &c16_u_aero, c16_b_sf_marshall);
  sf_debug_symbol_scope_add("Cd", &c16_b_Cd, c16_sf_marshall);
  sf_debug_symbol_scope_add("v_B", &c16_v_B, c16_b_sf_marshall);
  sf_debug_symbol_scope_add("rho", &c16_rho, c16_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  x = 1; */
  /*  z = x*1; */
  /*  y = z*u; */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  dot product of area vector and velocity vector */
  _SFD_EML_CALL(0,11);
  for (c16_i8 = 0; c16_i8 < 3; c16_i8 = c16_i8 + 1) {
    c16_b_v_B[c16_i8] = c16_v_B[c16_i8];
  }

  for (c16_i9 = 0; c16_i9 < 3; c16_i9 = c16_i9 + 1) {
    c16_c_v_B[c16_i9] = c16_v_B[c16_i9];
  }

  c16_b_x = c16_dot(c16_b_v_B, c16_c_v_B);
  c16_vnorm = c16_b_x;
  if (c16_vnorm < 0.0) {
    c16_eml_error();
  }

  c16_c_x = c16_vnorm;
  c16_vnorm = c16_c_x;
  c16_vnorm = muDoubleScalarSqrt(c16_vnorm);
  _SFD_EML_CALL(0,12);
  for (c16_i10 = 0; c16_i10 < 3; c16_i10 = c16_i10 + 1) {
    c16_A[c16_i10] = c16_v_B[c16_i10];
  }

  c16_B = c16_vnorm;
  for (c16_i11 = 0; c16_i11 < 3; c16_i11 = c16_i11 + 1) {
    c16_d_x[c16_i11] = c16_A[c16_i11];
  }

  c16_b_y = c16_B;
  if (c16_b_y == 0.0) {
    c16_eml_warning();
  }

  for (c16_i12 = 0; c16_i12 < 3; c16_i12 = c16_i12 + 1) {
    c16_e_x[c16_i12] = c16_d_x[c16_i12];
  }

  c16_c_y = c16_b_y;
  for (c16_i13 = 0; c16_i13 < 3; c16_i13 = c16_i13 + 1) {
    c16_f_x[c16_i13] = c16_e_x[c16_i13];
  }

  c16_d_y = c16_c_y;
  for (c16_i14 = 0; c16_i14 < 3; c16_i14 = c16_i14 + 1) {
    c16_v_unit[c16_i14] = c16_f_x[c16_i14] / c16_d_y;
  }

  _SFD_EML_CALL(0,14);
  c16_y = 0.0;
  _SFD_EML_CALL(0,15);
  c16_b_a = c16_b_side;
  _SFD_EML_CALL(0,16);
  c16_b_a = 6.7600000000000007E-002;

  /* Area of satellite */
  _SFD_EML_CALL(0,17);
  for (c16_i15 = 0; c16_i15 < 18; c16_i15 = c16_i15 + 1) {
    c16_b[c16_i15] = 0.0;
  }

  _SFD_EML_CALL(0,18);
  for (c16_i16 = 0; c16_i16 < 3; c16_i16 = c16_i16 + 1) {
    c16_b[c16_i16] = c16_dv2[c16_i16];
  }

  _SFD_EML_CALL(0,19);
  for (c16_i17 = 0; c16_i17 < 3; c16_i17 = c16_i17 + 1) {
    c16_b[c16_i17 + 3] = c16_dv3[c16_i17];
  }

  _SFD_EML_CALL(0,20);
  for (c16_i18 = 0; c16_i18 < 3; c16_i18 = c16_i18 + 1) {
    c16_b[c16_i18 + 6] = c16_dv4[c16_i18];
  }

  _SFD_EML_CALL(0,21);
  for (c16_i19 = 0; c16_i19 < 3; c16_i19 = c16_i19 + 1) {
    c16_b[c16_i19 + 9] = c16_dv5[c16_i19];
  }

  _SFD_EML_CALL(0,22);
  for (c16_i20 = 0; c16_i20 < 3; c16_i20 = c16_i20 + 1) {
    c16_b[c16_i20 + 12] = c16_dv6[c16_i20];
  }

  _SFD_EML_CALL(0,23);
  for (c16_i21 = 0; c16_i21 < 3; c16_i21 = c16_i21 + 1) {
    c16_b[c16_i21 + 15] = c16_dv7[c16_i21];
  }

  c16_i = 1.0;
  c16_b_i = 1.0;
  while (c16_b_i <= 6.0) {
    c16_i = c16_b_i;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0,26);
    c16_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("b", (int32_T)_SFD_INTEGER_CHECK("i",
      c16_i), 1, 6, 2, 0) - 1;
    for (c16_i22 = 0; c16_i22 < 3; c16_i22 = c16_i22 + 1) {
      c16_b_b[c16_i22] = c16_b[c16_i22 + 3 * c16_c_i];
    }

    for (c16_i23 = 0; c16_i23 < 3; c16_i23 = c16_i23 + 1) {
      c16_b_v_unit[c16_i23] = c16_v_unit[c16_i23];
    }

    c16_x = c16_dot(c16_b_b, c16_b_v_unit);
    _SFD_EML_CALL(0,27);
    if (CV_EML_IF(0, 0, c16_x > 0.0)) {
      _SFD_EML_CALL(0,28);
      c16_y = c16_y + c16_x;
    }

    c16_b_i = c16_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_EML_FOR(0, 0, 0);
  _SFD_EML_CALL(0,31);
  c16_Ap = c16_y;

  /*  total exposed area */
  _SFD_EML_CALL(0,33);
  c16_c_b = c16_b_Cd;
  c16_c_a = -0.5 * c16_c_b;
  c16_d_b = c16_rho;
  c16_d_a = c16_c_a * c16_d_b;
  c16_e_b = c16_Ap;
  c16_e_a = c16_d_a * c16_e_b;
  c16_f_a = c16_vnorm;
  c16_g_a = c16_f_a;
  c16_ak = c16_g_a;
  c16_f_b = muDoubleScalarPower(c16_ak, 2.0);
  c16_h_a = c16_e_a * c16_f_b;
  for (c16_i24 = 0; c16_i24 < 3; c16_i24 = c16_i24 + 1) {
    c16_g_b[c16_i24] = c16_v_unit[c16_i24];
  }

  for (c16_i25 = 0; c16_i25 < 3; c16_i25 = c16_i25 + 1) {
    c16_F_aero[c16_i25] = c16_h_a * c16_g_b[c16_i25];
  }

  _SFD_EML_CALL(0,35);
  for (c16_i26 = 0; c16_i26 < 3; c16_i26 = c16_i26 + 1) {
    c16_h_b[c16_i26] = c16_F_aero[c16_i26];
  }

  c16_i_b = c16_h_b[1];
  c16_e_y = 0.002 * c16_i_b;
  c16_j_b = c16_h_b[2];
  c16_f_y = 0.0175 * c16_j_b;
  c16_c1 = c16_f_y - c16_e_y;
  c16_k_b = c16_h_b[2];
  c16_g_y = 0.002 * c16_k_b;
  c16_l_b = c16_h_b[0];
  c16_h_y = 0.002 * c16_l_b;
  c16_c2 = c16_h_y - c16_g_y;
  c16_m_b = c16_h_b[0];
  c16_i_y = 0.0175 * c16_m_b;
  c16_n_b = c16_h_b[1];
  c16_j_y = 0.002 * c16_n_b;
  c16_c3 = c16_j_y - c16_i_y;
  c16_u_aero[0] = c16_c1;
  c16_u_aero[1] = c16_c2;
  c16_u_aero[2] = c16_c3;
  _SFD_EML_CALL(0,-35);
  sf_debug_symbol_scope_pop();
  for (c16_i27 = 0; c16_i27 < 3; c16_i27 = c16_i27 + 1) {
    (*c16_b_u_aero)[c16_i27] = c16_u_aero[c16_i27];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static real_T c16_dot(real_T c16_b_a[3], real_T c16_b[3])
{
  int32_T c16_i28;
  real_T c16_c_a[3];
  int32_T c16_i29;
  real_T c16_b_b[3];
  int32_T c16_i30;
  real_T c16_x[3];
  int32_T c16_i31;
  real_T c16_y[3];
  int32_T c16_i32;
  real_T c16_b_x[3];
  int32_T c16_i33;
  real_T c16_b_y[3];
  int32_T c16_i34;
  real_T c16_c_x[3];
  int32_T c16_i35;
  real_T c16_c_y[3];
  int32_T c16_i36;
  real_T c16_d_x[3];
  int32_T c16_i37;
  real_T c16_d_y[3];
  c16_eml_scalar_eg();
  for (c16_i28 = 0; c16_i28 < 3; c16_i28 = c16_i28 + 1) {
    c16_c_a[c16_i28] = c16_b_a[c16_i28];
  }

  for (c16_i29 = 0; c16_i29 < 3; c16_i29 = c16_i29 + 1) {
    c16_b_b[c16_i29] = c16_b[c16_i29];
  }

  for (c16_i30 = 0; c16_i30 < 3; c16_i30 = c16_i30 + 1) {
    c16_x[c16_i30] = c16_c_a[c16_i30];
  }

  for (c16_i31 = 0; c16_i31 < 3; c16_i31 = c16_i31 + 1) {
    c16_y[c16_i31] = c16_b_b[c16_i31];
  }

  for (c16_i32 = 0; c16_i32 < 3; c16_i32 = c16_i32 + 1) {
    c16_b_x[c16_i32] = c16_x[c16_i32];
  }

  for (c16_i33 = 0; c16_i33 < 3; c16_i33 = c16_i33 + 1) {
    c16_b_y[c16_i33] = c16_y[c16_i33];
  }

  for (c16_i34 = 0; c16_i34 < 3; c16_i34 = c16_i34 + 1) {
    c16_c_x[c16_i34] = c16_b_x[c16_i34];
  }

  for (c16_i35 = 0; c16_i35 < 3; c16_i35 = c16_i35 + 1) {
    c16_c_y[c16_i35] = c16_b_y[c16_i35];
  }

  for (c16_i36 = 0; c16_i36 < 3; c16_i36 = c16_i36 + 1) {
    c16_d_x[c16_i36] = c16_c_x[c16_i36];
  }

  for (c16_i37 = 0; c16_i37 < 3; c16_i37 = c16_i37 + 1) {
    c16_d_y[c16_i37] = c16_c_y[c16_i37];
  }

  return c16_ceval_xdot(3, c16_d_x, 1, 1, c16_d_y, 1, 1);
}

static void c16_eml_scalar_eg(void)
{
}

static real_T c16_ceval_xdot(int32_T c16_n, real_T c16_x[3], int32_T c16_ix0,
  int32_T c16_incx, real_T c16_y[3], int32_T c16_iy0,
  int32_T c16_incy)
{
  real_T c16_d;
  c16_d = 0.0;
  if ((real_T)c16_n > 0.0) {
    return ddot32(&c16_n, &c16_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c16_ix0), 1, 3, 1, 0) - 1]
                  , &c16_incx, &c16_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c16_iy0), 1, 3, 1, 0) - 1], &
                  c16_incy);
  }

  return c16_d;
}

static void c16_eml_error(void)
{
  int32_T c16_i38;
  static char_T c16_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c16_u[77];
  const mxArray *c16_y = NULL;
  int32_T c16_i39;
  static char_T c16_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c16_b_u[31];
  const mxArray *c16_b_y = NULL;
  for (c16_i38 = 0; c16_i38 < 77; c16_i38 = c16_i38 + 1) {
    c16_u[c16_i38] = c16_cv0[c16_i38];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c16_i39 = 0; c16_i39 < 31; c16_i39 = c16_i39 + 1) {
    c16_b_u[c16_i39] = c16_cv1[c16_i39];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c16_b_y, 14, c16_y);
}

static void c16_eml_warning(void)
{
  int32_T c16_i40;
  static char_T c16_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c16_u[15];
  const mxArray *c16_y = NULL;
  int32_T c16_i41;
  static char_T c16_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c16_b_u[19];
  const mxArray *c16_b_y = NULL;
  for (c16_i40 = 0; c16_i40 < 15; c16_i40 = c16_i40 + 1) {
    c16_u[c16_i40] = c16_cv2[c16_i40];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c16_i41 = 0; c16_i41 < 19; c16_i41 = c16_i41 + 1) {
    c16_b_u[c16_i41] = c16_cv3[c16_i41];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c16_b_y, 14, c16_y);
}

static const mxArray *c16_sf_marshall(void *c16_chartInstance, void *c16_u)
{
  const mxArray *c16_y = NULL;
  real_T c16_b_u;
  const mxArray *c16_b_y = NULL;
  c16_y = NULL;
  c16_b_u = *((real_T *)c16_u);
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c16_y, c16_b_y);
  return c16_y;
}

static const mxArray *c16_b_sf_marshall(void *c16_chartInstance, void *c16_u)
{
  const mxArray *c16_y = NULL;
  int32_T c16_i42;
  real_T c16_b_u[3];
  const mxArray *c16_b_y = NULL;
  c16_y = NULL;
  for (c16_i42 = 0; c16_i42 < 3; c16_i42 = c16_i42 + 1) {
    c16_b_u[c16_i42] = (*((real_T (*)[3])c16_u))[c16_i42];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c16_y, c16_b_y);
  return c16_y;
}

static const mxArray *c16_c_sf_marshall(void *c16_chartInstance, void *c16_u)
{
  const mxArray *c16_y = NULL;
  int32_T c16_i43;
  int32_T c16_i44;
  int32_T c16_i45;
  real_T c16_b_u[18];
  const mxArray *c16_b_y = NULL;
  c16_y = NULL;
  c16_i43 = 0;
  for (c16_i44 = 0; c16_i44 < 6; c16_i44 = c16_i44 + 1) {
    for (c16_i45 = 0; c16_i45 < 3; c16_i45 = c16_i45 + 1) {
      c16_b_u[c16_i45 + c16_i43] = (*((real_T (*)[18])c16_u))[c16_i45 + c16_i43];
    }

    c16_i43 = c16_i43 + 3;
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 0, 0U, 1U, 0U, 2, 3, 6));
  sf_mex_assign(&c16_y, c16_b_y);
  return c16_y;
}

const mxArray
  *sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_ResolvedFunctionInfo c16_info[56];
  const mxArray *c16_m0 = NULL;
  int32_T c16_i46;
  c16_ResolvedFunctionInfo *c16_r0;
  c16_nameCaptureInfo = NULL;
  c16_info_helper(c16_info);
  sf_mex_assign(&c16_m0, sf_mex_createstruct("nameCaptureInfo", 1, 56));
  for (c16_i46 = 0; c16_i46 < 56; c16_i46 = c16_i46 + 1) {
    c16_r0 = &c16_info[c16_i46];
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->context)), "context"
                    , "nameCaptureInfo", c16_i46);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->name)), "name",
                    "nameCaptureInfo", c16_i46);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      c16_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c16_i46);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->resolved)),
                    "resolved", "nameCaptureInfo", c16_i46);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c16_i46);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c16_i46);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c16_i46);
  }

  sf_mex_assign(&c16_nameCaptureInfo, c16_m0);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(c16_ResolvedFunctionInfo c16_info[56])
{
  c16_info[0].context = "";
  c16_info[0].name = "dot";
  c16_info[0].dominantType = "double";
  c16_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[0].fileLength = 2812U;
  c16_info[0].fileTime1 = 1236241088U;
  c16_info[0].fileTime2 = 0U;
  c16_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[1].name = "nargin";
  c16_info[1].dominantType = "";
  c16_info[1].resolved = "[B]nargin";
  c16_info[1].fileLength = 0U;
  c16_info[1].fileTime1 = 0U;
  c16_info[1].fileTime2 = 0U;
  c16_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[2].name = "gt";
  c16_info[2].dominantType = "double";
  c16_info[2].resolved = "[B]gt";
  c16_info[2].fileLength = 0U;
  c16_info[2].fileTime1 = 0U;
  c16_info[2].fileTime2 = 0U;
  c16_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[3].name = "isa";
  c16_info[3].dominantType = "double";
  c16_info[3].resolved = "[B]isa";
  c16_info[3].fileLength = 0U;
  c16_info[3].fileTime1 = 0U;
  c16_info[3].fileTime2 = 0U;
  c16_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[4].name = "size";
  c16_info[4].dominantType = "double";
  c16_info[4].resolved = "[B]size";
  c16_info[4].fileLength = 0U;
  c16_info[4].fileTime1 = 0U;
  c16_info[4].fileTime2 = 0U;
  c16_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[5].name = "isequal";
  c16_info[5].dominantType = "double";
  c16_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c16_info[5].fileLength = 180U;
  c16_info[5].fileTime1 = 1226561072U;
  c16_info[5].fileTime2 = 0U;
  c16_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c16_info[6].name = "false";
  c16_info[6].dominantType = "";
  c16_info[6].resolved = "[B]false";
  c16_info[6].fileLength = 0U;
  c16_info[6].fileTime1 = 0U;
  c16_info[6].fileTime2 = 0U;
  c16_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c16_info[7].name = "eml_isequal_core";
  c16_info[7].dominantType = "double";
  c16_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c16_info[7].fileLength = 3981U;
  c16_info[7].fileTime1 = 1236241072U;
  c16_info[7].fileTime2 = 0U;
  c16_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c16_info[8].name = "ge";
  c16_info[8].dominantType = "double";
  c16_info[8].resolved = "[B]ge";
  c16_info[8].fileLength = 0U;
  c16_info[8].fileTime1 = 0U;
  c16_info[8].fileTime2 = 0U;
  c16_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c16_info[9].name = "isscalar";
  c16_info[9].dominantType = "logical";
  c16_info[9].resolved = "[B]isscalar";
  c16_info[9].fileLength = 0U;
  c16_info[9].fileTime1 = 0U;
  c16_info[9].fileTime2 = 0U;
  c16_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c16_info[10].name = "islogical";
  c16_info[10].dominantType = "logical";
  c16_info[10].resolved = "[B]islogical";
  c16_info[10].fileLength = 0U;
  c16_info[10].fileTime1 = 0U;
  c16_info[10].fileTime2 = 0U;
  c16_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c16_info[11].name = "minus";
  c16_info[11].dominantType = "double";
  c16_info[11].resolved = "[B]minus";
  c16_info[11].fileLength = 0U;
  c16_info[11].fileTime1 = 0U;
  c16_info[11].fileTime2 = 0U;
  c16_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c16_info[12].name = "isnumeric";
  c16_info[12].dominantType = "double";
  c16_info[12].resolved = "[B]isnumeric";
  c16_info[12].fileLength = 0U;
  c16_info[12].fileTime1 = 0U;
  c16_info[12].fileTime2 = 0U;
  c16_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c16_info[13].name = "ndims";
  c16_info[13].dominantType = "double";
  c16_info[13].resolved = "[B]ndims";
  c16_info[13].fileLength = 0U;
  c16_info[13].fileTime1 = 0U;
  c16_info[13].fileTime2 = 0U;
  c16_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c16_info[14].name = "ne";
  c16_info[14].dominantType = "double";
  c16_info[14].resolved = "[B]ne";
  c16_info[14].fileLength = 0U;
  c16_info[14].fileTime1 = 0U;
  c16_info[14].fileTime2 = 0U;
  c16_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c16_info[15].name = "true";
  c16_info[15].dominantType = "";
  c16_info[15].resolved = "[B]true";
  c16_info[15].fileLength = 0U;
  c16_info[15].fileTime1 = 0U;
  c16_info[15].fileTime2 = 0U;
  c16_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c16_info[16].name = "isstruct";
  c16_info[16].dominantType = "double";
  c16_info[16].resolved = "[B]isstruct";
  c16_info[16].fileLength = 0U;
  c16_info[16].fileTime1 = 0U;
  c16_info[16].fileTime2 = 0U;
  c16_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c16_info[17].name = "eq";
  c16_info[17].dominantType = "logical";
  c16_info[17].resolved = "[B]eq";
  c16_info[17].fileLength = 0U;
  c16_info[17].fileTime1 = 0U;
  c16_info[17].fileTime2 = 0U;
  c16_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c16_info[18].name = "isempty";
  c16_info[18].dominantType = "double";
  c16_info[18].resolved = "[B]isempty";
  c16_info[18].fileLength = 0U;
  c16_info[18].fileTime1 = 0U;
  c16_info[18].fileTime2 = 0U;
  c16_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c16_info[19].name = "not";
  c16_info[19].dominantType = "logical";
  c16_info[19].resolved = "[B]not";
  c16_info[19].fileLength = 0U;
  c16_info[19].fileTime1 = 0U;
  c16_info[19].fileTime2 = 0U;
  c16_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c16_info[20].name = "isnan";
  c16_info[20].dominantType = "double";
  c16_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c16_info[20].fileLength = 506U;
  c16_info[20].fileTime1 = 1228077610U;
  c16_info[20].fileTime2 = 0U;
  c16_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c16_info[21].name = "isreal";
  c16_info[21].dominantType = "double";
  c16_info[21].resolved = "[B]isreal";
  c16_info[21].fileLength = 0U;
  c16_info[21].fileTime1 = 0U;
  c16_info[21].fileTime2 = 0U;
  c16_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[22].name = "eml_index_class";
  c16_info[22].dominantType = "";
  c16_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[22].fileLength = 909U;
  c16_info[22].fileTime1 = 1192454182U;
  c16_info[22].fileTime2 = 0U;
  c16_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[23].name = "ones";
  c16_info[23].dominantType = "char";
  c16_info[23].resolved = "[B]ones";
  c16_info[23].fileLength = 0U;
  c16_info[23].fileTime1 = 0U;
  c16_info[23].fileTime2 = 0U;
  c16_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[24].name = "isfloat";
  c16_info[24].dominantType = "double";
  c16_info[24].resolved = "[B]isfloat";
  c16_info[24].fileLength = 0U;
  c16_info[24].fileTime1 = 0U;
  c16_info[24].fileTime2 = 0U;
  c16_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[25].name = "eml_scalar_eg";
  c16_info[25].dominantType = "double";
  c16_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[25].fileLength = 3068U;
  c16_info[25].fileTime1 = 1240249410U;
  c16_info[25].fileTime2 = 0U;
  c16_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c16_info[26].name = "class";
  c16_info[26].dominantType = "double";
  c16_info[26].resolved = "[B]class";
  c16_info[26].fileLength = 0U;
  c16_info[26].fileTime1 = 0U;
  c16_info[26].fileTime2 = 0U;
  c16_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c16_info[27].name = "cast";
  c16_info[27].dominantType = "double";
  c16_info[27].resolved = "[B]cast";
  c16_info[27].fileLength = 0U;
  c16_info[27].fileTime1 = 0U;
  c16_info[27].fileTime2 = 0U;
  c16_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c16_info[28].name = "plus";
  c16_info[28].dominantType = "double";
  c16_info[28].resolved = "[B]plus";
  c16_info[28].fileLength = 0U;
  c16_info[28].fileTime1 = 0U;
  c16_info[28].fileTime2 = 0U;
  c16_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[29].name = "lt";
  c16_info[29].dominantType = "double";
  c16_info[29].resolved = "[B]lt";
  c16_info[29].fileLength = 0U;
  c16_info[29].fileTime1 = 0U;
  c16_info[29].fileTime2 = 0U;
  c16_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c16_info[30].name = "isvector";
  c16_info[30].dominantType = "double";
  c16_info[30].resolved = "[B]isvector";
  c16_info[30].fileLength = 0U;
  c16_info[30].fileTime1 = 0U;
  c16_info[30].fileTime2 = 0U;
  c16_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c16_info[31].name = "eml_xdotc";
  c16_info[31].dominantType = "int32";
  c16_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c16_info[31].fileLength = 1453U;
  c16_info[31].fileTime1 = 1209318250U;
  c16_info[31].fileTime2 = 0U;
  c16_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c16_info[32].name = "eml_xdot";
  c16_info[32].dominantType = "int32";
  c16_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c16_info[32].fileLength = 1330U;
  c16_info[32].fileTime1 = 1209318250U;
  c16_info[32].fileTime2 = 0U;
  c16_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c16_info[33].name = "strcmp";
  c16_info[33].dominantType = "char";
  c16_info[33].resolved = "[B]strcmp";
  c16_info[33].fileLength = 0U;
  c16_info[33].fileTime1 = 0U;
  c16_info[33].fileTime2 = 0U;
  c16_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c16_info[34].name = "eml_refblas_xdot";
  c16_info[34].dominantType = "int32";
  c16_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c16_info[34].fileLength = 343U;
  c16_info[34].fileTime1 = 1211203444U;
  c16_info[34].fileTime2 = 0U;
  c16_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c16_info[35].name = "eml_refblas_xdotx";
  c16_info[35].dominantType = "int32";
  c16_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c16_info[35].fileLength = 1605U;
  c16_info[35].fileTime1 = 1236241080U;
  c16_info[35].fileTime2 = 0U;
  c16_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c16_info[36].name = "ischar";
  c16_info[36].dominantType = "char";
  c16_info[36].resolved = "[B]ischar";
  c16_info[36].fileLength = 0U;
  c16_info[36].fileTime1 = 0U;
  c16_info[36].fileTime2 = 0U;
  c16_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c16_info[37].name = "times";
  c16_info[37].dominantType = "double";
  c16_info[37].resolved = "[B]times";
  c16_info[37].fileLength = 0U;
  c16_info[37].fileTime1 = 0U;
  c16_info[37].fileTime2 = 0U;
  c16_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c16_info[38].name = "uminus";
  c16_info[38].dominantType = "int32";
  c16_info[38].resolved = "[B]uminus";
  c16_info[38].fileLength = 0U;
  c16_info[38].fileTime1 = 0U;
  c16_info[38].fileTime2 = 0U;
  c16_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c16_info[39].name = "eml_index_minus";
  c16_info[39].dominantType = "int32";
  c16_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c16_info[39].fileLength = 277U;
  c16_info[39].fileTime1 = 1192454184U;
  c16_info[39].fileTime2 = 0U;
  c16_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c16_info[40].name = "eml_index_plus";
  c16_info[40].dominantType = "int32";
  c16_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c16_info[40].fileLength = 272U;
  c16_info[40].fileTime1 = 1192454186U;
  c16_info[40].fileTime2 = 0U;
  c16_info[41].context = "";
  c16_info[41].name = "sqrt";
  c16_info[41].dominantType = "double";
  c16_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c16_info[41].fileLength = 572U;
  c16_info[41].fileTime1 = 1203431846U;
  c16_info[41].fileTime2 = 0U;
  c16_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c16_info[42].name = "eml_error";
  c16_info[42].dominantType = "char";
  c16_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c16_info[42].fileLength = 315U;
  c16_info[42].fileTime1 = 1213914146U;
  c16_info[42].fileTime2 = 0U;
  c16_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c16_info[43].name = "eml_scalar_sqrt";
  c16_info[43].dominantType = "double";
  c16_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c16_info[43].fileLength = 664U;
  c16_info[43].fileTime1 = 1209318194U;
  c16_info[43].fileTime2 = 0U;
  c16_info[44].context = "";
  c16_info[44].name = "mrdivide";
  c16_info[44].dominantType = "double";
  c16_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[44].fileLength = 800U;
  c16_info[44].fileTime1 = 1238421692U;
  c16_info[44].fileTime2 = 0U;
  c16_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[45].name = "rdivide";
  c16_info[45].dominantType = "double";
  c16_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[45].fileLength = 620U;
  c16_info[45].fileTime1 = 1213914166U;
  c16_info[45].fileTime2 = 0U;
  c16_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[46].name = "eml_warning";
  c16_info[46].dominantType = "char";
  c16_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c16_info[46].fileLength = 262U;
  c16_info[46].fileTime1 = 1236241078U;
  c16_info[46].fileTime2 = 0U;
  c16_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[47].name = "eml_div";
  c16_info[47].dominantType = "double";
  c16_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c16_info[47].fileLength = 4269U;
  c16_info[47].fileTime1 = 1228077626U;
  c16_info[47].fileTime2 = 0U;
  c16_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c16_info[48].name = "isinteger";
  c16_info[48].dominantType = "double";
  c16_info[48].resolved = "[B]isinteger";
  c16_info[48].fileLength = 0U;
  c16_info[48].fileTime1 = 0U;
  c16_info[48].fileTime2 = 0U;
  c16_info[49].context = "";
  c16_info[49].name = "mtimes";
  c16_info[49].dominantType = "double";
  c16_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[49].fileLength = 3302U;
  c16_info[49].fileTime1 = 1242738294U;
  c16_info[49].fileTime2 = 0U;
  c16_info[50].context = "";
  c16_info[50].name = "zeros";
  c16_info[50].dominantType = "double";
  c16_info[50].resolved = "[B]zeros";
  c16_info[50].fileLength = 0U;
  c16_info[50].fileTime1 = 0U;
  c16_info[50].fileTime2 = 0U;
  c16_info[51].context = "";
  c16_info[51].name = "mpower";
  c16_info[51].dominantType = "double";
  c16_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c16_info[51].fileLength = 3710U;
  c16_info[51].fileTime1 = 1238421690U;
  c16_info[51].fileTime2 = 0U;
  c16_info[52].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c16_info[52].name = "power";
  c16_info[52].dominantType = "double";
  c16_info[52].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c16_info[52].fileLength = 5380U;
  c16_info[52].fileTime1 = 1228077698U;
  c16_info[52].fileTime2 = 0U;
  c16_info[53].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c16_info[53].name = "eml_scalexp_alloc";
  c16_info[53].dominantType = "double";
  c16_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c16_info[53].fileLength = 808U;
  c16_info[53].fileTime1 = 1230478500U;
  c16_info[53].fileTime2 = 0U;
  c16_info[54].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c16_info[54].name = "eml_scalar_floor";
  c16_info[54].dominantType = "double";
  c16_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c16_info[54].fileLength = 260U;
  c16_info[54].fileTime1 = 1209318190U;
  c16_info[54].fileTime2 = 0U;
  c16_info[55].context = "";
  c16_info[55].name = "cross";
  c16_info[55].dominantType = "double";
  c16_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c16_info[55].fileLength = 3157U;
  c16_info[55].fileTime1 = 1240249462U;
  c16_info[55].fileTime2 = 0U;
}

static const mxArray *c16_d_sf_marshall(void *c16_chartInstance, void *c16_u)
{
  const mxArray *c16_y = NULL;
  boolean_T c16_b_u;
  const mxArray *c16_b_y = NULL;
  c16_y = NULL;
  c16_b_u = *((boolean_T *)c16_u);
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c16_y, c16_b_y);
  return c16_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
  (mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3451136439U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(148707357U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4015609505U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3186737845U);
}

mxArray
  *sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2057784846U);
    pr[1] = (double)(2583312518U);
    pr[2] = (double)(1447791380U);
    pr[3] = (double)(1462198515U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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

static mxArray
  *sf_get_sim_state_info_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_aero\",},{M[8],M[0],T\"is_active_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
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
           16,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"rho",0,
                              (MexFcnForType)c16_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_B",0,(MexFcnForType)c16_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"u_aero",0,(MexFcnForType)
                                c16_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"side",0,
                              (MexFcnForType)c16_sf_marshall);
          _SFD_SET_DATA_PROPS(4,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Cd",0,
                              (MexFcnForType)c16_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,10,0,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_COM_to_COP_b",0,(MexFcnForType)
                                c16_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,683);
        _SFD_CV_INIT_EML_IF(0,0,522,529,-1,558);
        _SFD_CV_INIT_EML_FOR(0,0,479,489,562);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c16_rho;
          real_T (*c16_v_B)[3];
          real_T (*c16_u_aero)[3];
          c16_rho = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c16_u_aero = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c16_v_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c16_rho);
          _SFD_SET_DATA_VALUE_PTR(1U, c16_v_B);
          _SFD_SET_DATA_VALUE_PTR(2U, c16_u_aero);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance.c16_side);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance.c16_Cd);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance.c16_v_COM_to_COP_b);
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
  sf_opaque_initialize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void *
  chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  initialize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_enable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_disable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  disable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_gateway_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  sf_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  ext_mode_exec_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(sf_mex_dup
    (st));
}

static void
  sf_opaque_terminate_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  /* Actual parameters from chart:
     Cd side v_COM_to_COP_b
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Cd*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for side*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for v_COM_to_COP_b*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",16,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",16,2);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",16,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom_no_charge_in_detumb",
                          "adcs_v15_integral_Power_nom_no_charge_in_detumb",16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(366869282U));
  ssSetChecksum1(S,(1977454300U));
  ssSetChecksum2(S,(3728620716U));
  ssSetChecksum3(S,(1329984936U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",16);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb;
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

void c16_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
