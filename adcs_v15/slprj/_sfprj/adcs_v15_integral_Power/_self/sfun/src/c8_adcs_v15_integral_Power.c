/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c8_adcs_v15_integral_Power.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c8_IN_NO_ACTIVE_CHILD          (0)
#define c8_b_side                      (0.26)
#define c8_b_Ca_Solar_Drag             (1.4)
#define c8_b_P_momentum_flux_from_the_sun (4.4E-006)

/* Variable Declarations */

/* Variable Definitions */
static SFc8_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c8_adcs_v15_integral_Power(void);
static void initialize_params_c8_adcs_v15_integral_Power(void);
static void enable_c8_adcs_v15_integral_Power(void);
static void disable_c8_adcs_v15_integral_Power(void);
static void c8_update_debugger_state_c8_adcs_v15_integral_Power(void);
static void ext_mode_exec_c8_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c8_adcs_v15_integral_Power(void);
static void set_sim_state_c8_adcs_v15_integral_Power(const mxArray *c8_st);
static void finalize_c8_adcs_v15_integral_Power(void);
static void sf_c8_adcs_v15_integral_Power(void);
static void c8_c8_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static real_T c8_genpnorm(real_T c8_x[3], real_T c8_p);
static real_T c8_eml_xnrm2(real_T c8_x[3]);
static real_T c8_ceval_xnrm2(int32_T c8_n, real_T c8_x[3], real_T c8_ix0,
  int32_T c8_incx);
static real_T c8_power(real_T c8_a, real_T c8_b);
static void c8_eml_error(void);
static void c8_eml_warning(void);
static void c8_eml_scalar_eg(void);
static real_T c8_ceval_xdot(int32_T c8_n, real_T c8_x[3], int32_T c8_ix0,
  int32_T c8_incx, real_T c8_y[3], int32_T c8_iy0, int32_T c8_incy);
static const mxArray *c8_sf_marshall(void *c8_chartInstance, void *c8_u);
static const mxArray *c8_b_sf_marshall(void *c8_chartInstance, void *c8_u);
static const mxArray *c8_c_sf_marshall(void *c8_chartInstance, void *c8_u);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[68]);
static const mxArray *c8_d_sf_marshall(void *c8_chartInstance, void *c8_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c8_adcs_v15_integral_Power(void)
{
  uint8_T *c8_is_active_c8_adcs_v15_integral_Power;
  c8_is_active_c8_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c8_is_active_c8_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c8_adcs_v15_integral_Power(void)
{
  real_T c8_d0;
  real_T c8_d1;
  real_T c8_d2;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ca_Solar_Drag' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c8_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c8_Ca_Solar_Drag = c8_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'P_momentum_flux_from_the_sun' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c8_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c8_P_momentum_flux_from_the_sun = c8_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'side' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    2, 0), &c8_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c8_side = c8_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c8_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c8_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c8_update_debugger_state_c8_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c8_adcs_v15_integral_Power(void)
{
  c8_update_debugger_state_c8_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c8_adcs_v15_integral_Power(void)
{
  const mxArray *c8_st = NULL;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[3];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T *c8_is_active_c8_adcs_v15_integral_Power;
  real_T (*c8_solar_drag)[3];
  c8_solar_drag = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c8_is_active_c8_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2));
  for (c8_i0 = 0; c8_i0 < 3; c8_i0 = c8_i0 + 1) {
    c8_u[c8_i0] = (*c8_solar_drag)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_u = *c8_is_active_c8_adcs_v15_integral_Power;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_adcs_v15_integral_Power(const mxArray *c8_st)
{
  const mxArray *c8_u;
  const mxArray *c8_solar_drag;
  real_T c8_dv0[3];
  int32_T c8_i1;
  real_T c8_y[3];
  int32_T c8_i2;
  const mxArray *c8_is_active_c8_adcs_v15_integral_Power;
  uint8_T c8_u0;
  uint8_T c8_b_y;
  boolean_T *c8_doneDoubleBufferReInit;
  uint8_T *c8_b_is_active_c8_adcs_v15_integral_Power;
  real_T (*c8_b_solar_drag)[3];
  c8_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c8_b_solar_drag = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c8_b_is_active_c8_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  c8_solar_drag = sf_mex_dup(sf_mex_getcell(c8_u, 0));
  sf_mex_import("solar_drag", sf_mex_dup(c8_solar_drag), &c8_dv0, 1, 0, 0U, 1,
                0U, 1, 3);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1 = c8_i1 + 1) {
    c8_y[c8_i1] = c8_dv0[c8_i1];
  }

  sf_mex_destroy(&c8_solar_drag);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    (*c8_b_solar_drag)[c8_i2] = c8_y[c8_i2];
  }

  c8_is_active_c8_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c8_u, 1));
  sf_mex_import("is_active_c8_adcs_v15_integral_Power", sf_mex_dup
                (c8_is_active_c8_adcs_v15_integral_Power), &c8_u0, 1, 3, 0U, 0,
                0U,
                0);
  c8_b_y = c8_u0;
  sf_mex_destroy(&c8_is_active_c8_adcs_v15_integral_Power);
  *c8_b_is_active_c8_adcs_v15_integral_Power = c8_b_y;
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_adcs_v15_integral_Power();
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_adcs_v15_integral_Power(void)
{
}

static void sf_c8_adcs_v15_integral_Power(void)
{
  int32_T c8_i3;
  int32_T c8_i4;
  int32_T c8_previousEvent;
  real_T *c8_light;
  real_T (*c8_solar_drag)[3];
  real_T (*c8_v_Sun_b)[3];
  c8_solar_drag = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c8_light = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c8_v_Sun_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,6);
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_v_Sun_b)[c8_i3], 0U);
  }

  for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_solar_drag)[c8_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c8_Ca_Solar_Drag, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c8_P_momentum_flux_from_the_sun, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_light, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c8_side, 5U);
  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c8_c8_adcs_v15_integral_Power();
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c8_c8_adcs_v15_integral_Power(void)
{
  int32_T c8_i5;
  real_T c8_v_Sun_b[3];
  real_T c8_light;
  real_T c8_nargout = 1.0;
  real_T c8_nargin = 5.0;
  real_T c8_c_side = c8_b_side;
  real_T c8_c_P_momentum_flux_from_the_sun = c8_b_P_momentum_flux_from_the_sun;
  real_T c8_c_Ca_Solar_Drag = c8_b_Ca_Solar_Drag;
  real_T c8_Ap;
  real_T c8_i;
  real_T c8_x;
  real_T c8_b[18];
  real_T c8_a;
  real_T c8_y;
  real_T c8_u[3];
  real_T c8_solar_drag[3];
  int32_T c8_i6;
  real_T c8_b_x[3];
  int32_T c8_i7;
  real_T c8_c_x[3];
  real_T c8_b_y;
  int32_T c8_i8;
  static real_T c8_dv1[3] = { 1.0, 0.0, 0.0 };

  int32_T c8_i9;
  real_T c8_A[3];
  int32_T c8_i10;
  real_T c8_d_x[3];
  int32_T c8_i11;
  real_T c8_e_x[3];
  real_T c8_B;
  int32_T c8_i12;
  real_T c8_f_x[3];
  real_T c8_c_y;
  int32_T c8_i13;
  real_T c8_g_x[3];
  real_T c8_d_y;
  int32_T c8_i14;
  real_T c8_h_x[3];
  real_T c8_e_y;
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  static real_T c8_dv2[3] = { 6.7600000000000007E-002, 0.0, 0.0 };

  int32_T c8_i18;
  static real_T c8_dv3[3] = { 0.0, 6.7600000000000007E-002, 0.0 };

  int32_T c8_i19;
  static real_T c8_dv4[3] = { 0.0, 0.0, 6.7600000000000007E-002 };

  int32_T c8_i20;
  static real_T c8_dv5[3] = { -6.7600000000000007E-002, 0.0, 0.0 };

  int32_T c8_i21;
  static real_T c8_dv6[3] = { 0.0, -6.7600000000000007E-002, 0.0 };

  int32_T c8_i22;
  static real_T c8_dv7[3] = { 0.0, 0.0, -6.7600000000000007E-002 };

  real_T c8_b_i;
  int32_T c8_c_i;
  int32_T c8_i23;
  real_T c8_b_a[3];
  int32_T c8_i24;
  real_T c8_b_b[3];
  int32_T c8_i25;
  real_T c8_c_a[3];
  int32_T c8_i26;
  real_T c8_c_b[3];
  int32_T c8_i27;
  real_T c8_i_x[3];
  int32_T c8_i28;
  real_T c8_f_y[3];
  int32_T c8_i29;
  real_T c8_j_x[3];
  int32_T c8_i30;
  real_T c8_g_y[3];
  int32_T c8_i31;
  real_T c8_k_x[3];
  int32_T c8_i32;
  real_T c8_h_y[3];
  int32_T c8_i33;
  real_T c8_l_x[3];
  int32_T c8_i34;
  real_T c8_i_y[3];
  real_T c8_d_a;
  real_T c8_e_a;
  real_T c8_f_a;
  int32_T c8_i35;
  real_T c8_d_b[3];
  int32_T c8_i36;
  real_T c8_g_a[3];
  real_T c8_e_b;
  int32_T c8_i37;
  int32_T c8_i38;
  real_T *c8_b_light;
  real_T (*c8_b_solar_drag)[3];
  real_T (*c8_b_v_Sun_b)[3];
  c8_b_solar_drag = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c8_b_light = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c8_b_v_Sun_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,6);
  for (c8_i5 = 0; c8_i5 < 3; c8_i5 = c8_i5 + 1) {
    c8_v_Sun_b[c8_i5] = (*c8_b_v_Sun_b)[c8_i5];
  }

  c8_light = *c8_b_light;
  sf_debug_symbol_scope_push(15U, 0U);
  sf_debug_symbol_scope_add("nargout", &c8_nargout, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c8_nargin, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("side", &c8_c_side, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("P_momentum_flux_from_the_sun",
    &c8_c_P_momentum_flux_from_the_sun, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("Ca_Solar_Drag", &c8_c_Ca_Solar_Drag,
    c8_b_sf_marshall);
  sf_debug_symbol_scope_add("Ap", &c8_Ap, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("i", &c8_i, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c8_x, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("b", &c8_b, c8_c_sf_marshall);
  sf_debug_symbol_scope_add("a", &c8_a, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("y", &c8_y, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c8_u, c8_sf_marshall);
  sf_debug_symbol_scope_add("solar_drag", &c8_solar_drag, c8_sf_marshall);
  sf_debug_symbol_scope_add("light", &c8_light, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("v_Sun_b", &c8_v_Sun_b, c8_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /*  dot product of area vector and sun vector */
  _SFD_EML_CALL(0,6);
  for (c8_i6 = 0; c8_i6 < 3; c8_i6 = c8_i6 + 1) {
    c8_b_x[c8_i6] = c8_v_Sun_b[c8_i6];
  }

  for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
    c8_c_x[c8_i7] = c8_b_x[c8_i7];
  }

  c8_b_y = c8_genpnorm(c8_c_x, 2.0);
  if (CV_EML_IF(0, 0, c8_b_y == 0.0)) {
    _SFD_EML_CALL(0,7);
    for (c8_i8 = 0; c8_i8 < 3; c8_i8 = c8_i8 + 1) {
      c8_u[c8_i8] = c8_dv1[c8_i8];
    }
  } else {
    _SFD_EML_CALL(0,9);
    for (c8_i9 = 0; c8_i9 < 3; c8_i9 = c8_i9 + 1) {
      c8_A[c8_i9] = c8_v_Sun_b[c8_i9];
    }

    for (c8_i10 = 0; c8_i10 < 3; c8_i10 = c8_i10 + 1) {
      c8_d_x[c8_i10] = c8_v_Sun_b[c8_i10];
    }

    for (c8_i11 = 0; c8_i11 < 3; c8_i11 = c8_i11 + 1) {
      c8_e_x[c8_i11] = c8_d_x[c8_i11];
    }

    c8_B = c8_genpnorm(c8_e_x, 2.0);
    for (c8_i12 = 0; c8_i12 < 3; c8_i12 = c8_i12 + 1) {
      c8_f_x[c8_i12] = c8_A[c8_i12];
    }

    c8_c_y = c8_B;
    if (c8_c_y == 0.0) {
      c8_eml_warning();
    }

    for (c8_i13 = 0; c8_i13 < 3; c8_i13 = c8_i13 + 1) {
      c8_g_x[c8_i13] = c8_f_x[c8_i13];
    }

    c8_d_y = c8_c_y;
    for (c8_i14 = 0; c8_i14 < 3; c8_i14 = c8_i14 + 1) {
      c8_h_x[c8_i14] = c8_g_x[c8_i14];
    }

    c8_e_y = c8_d_y;
    for (c8_i15 = 0; c8_i15 < 3; c8_i15 = c8_i15 + 1) {
      c8_u[c8_i15] = c8_h_x[c8_i15] / c8_e_y;
    }
  }

  _SFD_EML_CALL(0,12);
  c8_y = 0.0;
  _SFD_EML_CALL(0,13);
  c8_a = c8_b_side;
  _SFD_EML_CALL(0,14);
  c8_a = 6.7600000000000007E-002;

  /* Area of satellite */
  _SFD_EML_CALL(0,15);
  for (c8_i16 = 0; c8_i16 < 18; c8_i16 = c8_i16 + 1) {
    c8_b[c8_i16] = 0.0;
  }

  _SFD_EML_CALL(0,16);
  for (c8_i17 = 0; c8_i17 < 3; c8_i17 = c8_i17 + 1) {
    c8_b[c8_i17] = c8_dv2[c8_i17];
  }

  _SFD_EML_CALL(0,17);
  for (c8_i18 = 0; c8_i18 < 3; c8_i18 = c8_i18 + 1) {
    c8_b[c8_i18 + 3] = c8_dv3[c8_i18];
  }

  _SFD_EML_CALL(0,18);
  for (c8_i19 = 0; c8_i19 < 3; c8_i19 = c8_i19 + 1) {
    c8_b[c8_i19 + 6] = c8_dv4[c8_i19];
  }

  _SFD_EML_CALL(0,19);
  for (c8_i20 = 0; c8_i20 < 3; c8_i20 = c8_i20 + 1) {
    c8_b[c8_i20 + 9] = c8_dv5[c8_i20];
  }

  _SFD_EML_CALL(0,20);
  for (c8_i21 = 0; c8_i21 < 3; c8_i21 = c8_i21 + 1) {
    c8_b[c8_i21 + 12] = c8_dv6[c8_i21];
  }

  _SFD_EML_CALL(0,21);
  for (c8_i22 = 0; c8_i22 < 3; c8_i22 = c8_i22 + 1) {
    c8_b[c8_i22 + 15] = c8_dv7[c8_i22];
  }

  _SFD_EML_CALL(0,23);
  c8_x = 0.0;
  c8_i = 1.0;
  c8_b_i = 1.0;
  while (c8_b_i <= 6.0) {
    c8_i = c8_b_i;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0,25);
    c8_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("b", (int32_T)_SFD_INTEGER_CHECK("i",
      c8_i), 1, 6, 2, 0) - 1;
    for (c8_i23 = 0; c8_i23 < 3; c8_i23 = c8_i23 + 1) {
      c8_b_a[c8_i23] = c8_b[c8_i23 + 3 * c8_c_i];
    }

    for (c8_i24 = 0; c8_i24 < 3; c8_i24 = c8_i24 + 1) {
      c8_b_b[c8_i24] = c8_u[c8_i24];
    }

    c8_eml_scalar_eg();
    for (c8_i25 = 0; c8_i25 < 3; c8_i25 = c8_i25 + 1) {
      c8_c_a[c8_i25] = c8_b_a[c8_i25];
    }

    for (c8_i26 = 0; c8_i26 < 3; c8_i26 = c8_i26 + 1) {
      c8_c_b[c8_i26] = c8_b_b[c8_i26];
    }

    for (c8_i27 = 0; c8_i27 < 3; c8_i27 = c8_i27 + 1) {
      c8_i_x[c8_i27] = c8_c_a[c8_i27];
    }

    for (c8_i28 = 0; c8_i28 < 3; c8_i28 = c8_i28 + 1) {
      c8_f_y[c8_i28] = c8_c_b[c8_i28];
    }

    for (c8_i29 = 0; c8_i29 < 3; c8_i29 = c8_i29 + 1) {
      c8_j_x[c8_i29] = c8_i_x[c8_i29];
    }

    for (c8_i30 = 0; c8_i30 < 3; c8_i30 = c8_i30 + 1) {
      c8_g_y[c8_i30] = c8_f_y[c8_i30];
    }

    for (c8_i31 = 0; c8_i31 < 3; c8_i31 = c8_i31 + 1) {
      c8_k_x[c8_i31] = c8_j_x[c8_i31];
    }

    for (c8_i32 = 0; c8_i32 < 3; c8_i32 = c8_i32 + 1) {
      c8_h_y[c8_i32] = c8_g_y[c8_i32];
    }

    for (c8_i33 = 0; c8_i33 < 3; c8_i33 = c8_i33 + 1) {
      c8_l_x[c8_i33] = c8_k_x[c8_i33];
    }

    for (c8_i34 = 0; c8_i34 < 3; c8_i34 = c8_i34 + 1) {
      c8_i_y[c8_i34] = c8_h_y[c8_i34];
    }

    c8_x = c8_ceval_xdot(3, c8_l_x, 1, 1, c8_i_y, 1, 1);
    _SFD_EML_CALL(0,26);
    if (CV_EML_IF(0, 1, c8_x > 0.0)) {
      _SFD_EML_CALL(0,27);
      c8_y = c8_y + c8_x;
    }

    c8_b_i = c8_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_EML_FOR(0, 0, 0);
  _SFD_EML_CALL(0,30);
  c8_Ap = c8_y;
  _SFD_EML_CALL(0,32);
  c8_d_a = -c8_Ap;
  c8_e_a = c8_d_a * 1.4;
  c8_f_a = c8_e_a * 4.4E-006;
  for (c8_i35 = 0; c8_i35 < 3; c8_i35 = c8_i35 + 1) {
    c8_d_b[c8_i35] = c8_u[c8_i35];
  }

  for (c8_i36 = 0; c8_i36 < 3; c8_i36 = c8_i36 + 1) {
    c8_g_a[c8_i36] = c8_f_a * c8_d_b[c8_i36];
  }

  c8_e_b = c8_light;
  for (c8_i37 = 0; c8_i37 < 3; c8_i37 = c8_i37 + 1) {
    c8_solar_drag[c8_i37] = c8_g_a[c8_i37] * c8_e_b;
  }

  _SFD_EML_CALL(0,-32);
  sf_debug_symbol_scope_pop();
  for (c8_i38 = 0; c8_i38 < 3; c8_i38 = c8_i38 + 1) {
    (*c8_b_solar_drag)[c8_i38] = c8_solar_drag[c8_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static real_T c8_genpnorm(real_T c8_x[3], real_T c8_p)
{
  real_T c8_y;
  int32_T c8_i39;
  real_T c8_b_x[3];
  real_T c8_k;
  real_T c8_b_k;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_absx;
  real_T c8_e_x;
  boolean_T c8_b;
  real_T c8_c_k;
  real_T c8_f_x;
  real_T c8_g_x;
  real_T c8_b_y;
  real_T c8_d_k;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T c8_j_x;
  boolean_T c8_b_b;
  int32_T c8_i40;
  real_T c8_k_x[3];
  real_T c8_b_p;
  real_T c8_scale;
  real_T c8_e_k;
  real_T c8_f_k;
  real_T c8_l_x;
  real_T c8_m_x;
  real_T c8_b_absx;
  real_T c8_n_x;
  boolean_T c8_c_b;
  real_T c8_o_x;
  boolean_T c8_d_b;
  real_T c8_d3;
  real_T c8_j;
  real_T c8_b_j;
  real_T c8_p_x;
  boolean_T c8_e_b;
  real_T c8_a;
  real_T c8_f_b;
  real_T c8_c_y;
  real_T c8_q_x;
  boolean_T c8_g_b;
  real_T c8_b_a;
  real_T c8_h_b;
  int32_T c8_i41;
  real_T c8_r_x[3];
  real_T c8_c_p;
  real_T c8_b_scale;
  real_T c8_g_k;
  real_T c8_h_k;
  real_T c8_s_x;
  real_T c8_t_x;
  real_T c8_c_absx;
  real_T c8_u_x;
  boolean_T c8_i_b;
  real_T c8_d4;
  real_T c8_c_j;
  real_T c8_d_j;
  real_T c8_v_x;
  boolean_T c8_j_b;
  real_T c8_c_a;
  real_T c8_k_b;
  real_T c8_d_y;
  real_T c8_w_x;
  boolean_T c8_l_b;
  real_T c8_x_x;
  boolean_T c8_m_b;
  real_T c8_d_a;
  real_T c8_e_a;
  real_T c8_n_b;
  real_T c8_o_b;
  if (c8_p == 2.0) {
    for (c8_i39 = 0; c8_i39 < 3; c8_i39 = c8_i39 + 1) {
      c8_b_x[c8_i39] = c8_x[c8_i39];
    }

    return c8_eml_xnrm2(c8_b_x);
  } else if (c8_p == rtInf) {
    c8_y = 0.0;
    c8_k = 1.0;
   label_1:
    ;
    if (c8_k <= 3.0) {
      c8_b_k = c8_k;
      c8_c_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
        ("k", c8_b_k), 1, 3, 1, 0) - 1];
      c8_d_x = c8_c_x;
      c8_absx = muDoubleScalarAbs(c8_d_x);
      c8_e_x = c8_absx;
      c8_b = rtIsNaN(c8_e_x);
      if (c8_b) {
        return rtNaN;
      } else {
        if (c8_absx > c8_y) {
          c8_y = c8_absx;
        }

        c8_k = c8_k + 1.0;
        goto label_1;
      }
    }
  } else if (c8_p == 1.0) {
    c8_y = 0.0;
    for (c8_c_k = 1.0; c8_c_k <= 3.0; c8_c_k = c8_c_k + 1.0) {
      c8_b_k = c8_c_k;
      c8_f_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
        ("k", c8_b_k), 1, 3, 1, 0) - 1];
      c8_g_x = c8_f_x;
      c8_b_y = muDoubleScalarAbs(c8_g_x);
      c8_y = c8_y + c8_b_y;
    }
  } else if (c8_p == rtMinusInf) {
    c8_y = rtInf;
    c8_d_k = 1.0;
   label_2:
    ;
    if (c8_d_k <= 3.0) {
      c8_b_k = c8_d_k;
      c8_h_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
        ("k", c8_b_k), 1, 3, 1, 0) - 1];
      c8_i_x = c8_h_x;
      c8_absx = muDoubleScalarAbs(c8_i_x);
      c8_j_x = c8_absx;
      c8_b_b = rtIsNaN(c8_j_x);
      if (c8_b_b) {
        return rtNaN;
      } else {
        if (c8_absx < c8_y) {
          c8_y = c8_absx;
        }

        c8_d_k = c8_d_k + 1.0;
        goto label_2;
      }
    }
  } else if (c8_p > 0.0) {
    for (c8_i40 = 0; c8_i40 < 3; c8_i40 = c8_i40 + 1) {
      c8_k_x[c8_i40] = c8_x[c8_i40];
    }

    c8_b_p = c8_p;
    c8_y = 0.0;
    c8_scale = 0.0;
    c8_e_k = 1.0;
   label_3:
    ;
    if (c8_e_k <= 3.0) {
      c8_f_k = c8_e_k;
      c8_l_x = c8_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c8_f_k), 1, 3, 1, 0) - 1];
      c8_m_x = c8_l_x;
      c8_b_absx = muDoubleScalarAbs(c8_m_x);
      c8_n_x = c8_b_absx;
      c8_c_b = rtIsNaN(c8_n_x);
      if (c8_c_b) {
        return rtNaN;
      } else {
        c8_o_x = c8_b_absx;
        c8_d_b = rtIsInf(c8_o_x);
        if (c8_d_b) {
          c8_y = rtInf;
          c8_d3 = c8_f_k + 1.0;
          c8_j = c8_d3;
        } else {
          if (c8_b_absx > 0.0) {
            if (c8_scale < c8_b_absx) {
              c8_a = c8_y;
              c8_f_b = c8_power(c8_scale / c8_b_absx, c8_b_p);
              c8_c_y = c8_a * c8_f_b;
              c8_y = 1.0 + c8_c_y;
              c8_scale = c8_b_absx;
            } else {
              c8_y = c8_y + c8_power(c8_b_absx / c8_scale, c8_b_p);
            }
          }

          c8_e_k = c8_e_k + 1.0;
          goto label_3;
        }
      }
    } else {
      if (c8_y > 0.0) {
        c8_q_x = c8_y;
        c8_g_b = rtIsInf(c8_q_x);
        if (!c8_g_b) {
          c8_b_a = c8_scale;
          c8_h_b = c8_power(c8_y, 1.0 / c8_b_p);
          return c8_b_a * c8_h_b;
        }
      }

      return c8_y;
    }

   label_4:
    ;
    if (c8_j <= 3.0) {
      c8_b_j = c8_j;
      c8_p_x = c8_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c8_b_j), 1, 3, 1, 0) - 1];
      c8_e_b = rtIsNaN(c8_p_x);
      if (c8_e_b) {
        return rtNaN;
      } else {
        c8_j = c8_j + 1.0;
        goto label_4;
      }
    }
  } else if (c8_p < 0.0) {
    for (c8_i41 = 0; c8_i41 < 3; c8_i41 = c8_i41 + 1) {
      c8_r_x[c8_i41] = c8_x[c8_i41];
    }

    c8_c_p = c8_p;
    c8_y = 0.0;
    c8_b_scale = rtInf;
    c8_g_k = 1.0;
   label_5:
    ;
    if (c8_g_k <= 3.0) {
      c8_h_k = c8_g_k;
      c8_s_x = c8_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c8_h_k), 1, 3, 1, 0) - 1];
      c8_t_x = c8_s_x;
      c8_c_absx = muDoubleScalarAbs(c8_t_x);
      c8_u_x = c8_c_absx;
      c8_i_b = rtIsNaN(c8_u_x);
      if (c8_i_b) {
        return rtNaN;
      } else if (c8_c_absx == 0.0) {
        c8_y = 0.0;
        c8_d4 = c8_h_k + 1.0;
        c8_c_j = c8_d4;
      } else {
        if (c8_c_absx < c8_b_scale) {
          c8_c_a = c8_y;
          c8_k_b = c8_power(c8_b_scale / c8_c_absx, c8_c_p);
          c8_d_y = c8_c_a * c8_k_b;
          c8_y = 1.0 + c8_d_y;
          c8_b_scale = c8_c_absx;
        } else {
          c8_w_x = c8_c_absx;
          c8_l_b = rtIsInf(c8_w_x);
          if (!c8_l_b) {
            c8_y = c8_y + c8_power(c8_c_absx / c8_b_scale, c8_c_p);
          }
        }

        c8_g_k = c8_g_k + 1.0;
        goto label_5;
      }
    } else {
      if (c8_y > 0.0) {
        c8_x_x = c8_y;
        c8_m_b = rtIsInf(c8_x_x);
        if (!c8_m_b) {
          c8_d_a = c8_b_scale;
          c8_e_a = c8_y;
          c8_n_b = 1.0 / c8_c_p;
          c8_o_b = c8_power(c8_e_a, c8_n_b);
          return c8_d_a * c8_o_b;
        }
      }

      return c8_y;
    }

   label_6:
    ;
    if (c8_c_j <= 3.0) {
      c8_d_j = c8_c_j;
      c8_v_x = c8_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c8_d_j), 1, 3, 1, 0) - 1];
      c8_j_b = rtIsNaN(c8_v_x);
      if (c8_j_b) {
        return rtNaN;
      } else {
        c8_c_j = c8_c_j + 1.0;
        goto label_6;
      }
    }
  } else if (c8_p == 0.0) {
    return rtInf;
  } else {
    return rtNaN;
  }

  return c8_y;
}

static real_T c8_eml_xnrm2(real_T c8_x[3])
{
  int32_T c8_i42;
  real_T c8_b_x[3];
  int32_T c8_i43;
  real_T c8_c_x[3];
  for (c8_i42 = 0; c8_i42 < 3; c8_i42 = c8_i42 + 1) {
    c8_b_x[c8_i42] = c8_x[c8_i42];
  }

  for (c8_i43 = 0; c8_i43 < 3; c8_i43 = c8_i43 + 1) {
    c8_c_x[c8_i43] = c8_b_x[c8_i43];
  }

  return c8_ceval_xnrm2(3, c8_c_x, 1.0, 1);
}

static real_T c8_ceval_xnrm2(int32_T c8_n, real_T c8_x[3], real_T c8_ix0,
  int32_T c8_incx)
{
  return dnrm232(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
    _SFD_INTEGER_CHECK("ix0", c8_ix0), 1, 3, 1, 0) - 1], &c8_incx);
}

static real_T c8_power(real_T c8_a, real_T c8_b)
{
  real_T c8_ak;
  real_T c8_bk;
  real_T c8_x;
  real_T c8_b_x;
  c8_ak = c8_a;
  c8_bk = c8_b;
  if (c8_ak < 0.0) {
    c8_x = c8_bk;
    c8_b_x = c8_x;
    c8_b_x = muDoubleScalarFloor(c8_b_x);
    if (c8_b_x != c8_bk) {
      c8_eml_error();
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c8_ak, c8_bk);
}

static void c8_eml_error(void)
{
  int32_T c8_i44;
  static char_T c8_cv0[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c8_u[102];
  const mxArray *c8_y = NULL;
  int32_T c8_i45;
  static char_T c8_cv1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c8_b_u[32];
  const mxArray *c8_b_y = NULL;
  for (c8_i44 = 0; c8_i44 < 102; c8_i44 = c8_i44 + 1) {
    c8_u[c8_i44] = c8_cv0[c8_i44];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c8_i45 = 0; c8_i45 < 32; c8_i45 = c8_i45 + 1) {
    c8_b_u[c8_i45] = c8_cv1[c8_i45];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c8_b_y, 14, c8_y);
}

static void c8_eml_warning(void)
{
  int32_T c8_i46;
  static char_T c8_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c8_u[15];
  const mxArray *c8_y = NULL;
  int32_T c8_i47;
  static char_T c8_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c8_b_u[19];
  const mxArray *c8_b_y = NULL;
  for (c8_i46 = 0; c8_i46 < 15; c8_i46 = c8_i46 + 1) {
    c8_u[c8_i46] = c8_cv2[c8_i46];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c8_i47 = 0; c8_i47 < 19; c8_i47 = c8_i47 + 1) {
    c8_b_u[c8_i47] = c8_cv3[c8_i47];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c8_b_y, 14, c8_y);
}

static void c8_eml_scalar_eg(void)
{
}

static real_T c8_ceval_xdot(int32_T c8_n, real_T c8_x[3], int32_T c8_ix0,
  int32_T c8_incx, real_T c8_y[3], int32_T c8_iy0, int32_T
  c8_incy)
{
  real_T c8_d;
  c8_d = 0.0;
  if ((real_T)c8_n > 0.0) {
    return ddot32(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c8_ix0), 1, 3, 1, 0) - 1], &
                  c8_incx, &c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c8_iy0), 1, 3, 1, 0) - 1], &c8_incy);
  }

  return c8_d;
}

static const mxArray *c8_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i48;
  real_T c8_b_u[3];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  for (c8_i48 = 0; c8_i48 < 3; c8_i48 = c8_i48 + 1) {
    c8_b_u[c8_i48] = (*((real_T (*)[3])c8_u))[c8_i48];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_b_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_b_u = *((real_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_c_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i49;
  int32_T c8_i50;
  int32_T c8_i51;
  real_T c8_b_u[18];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_i49 = 0;
  for (c8_i50 = 0; c8_i50 < 6; c8_i50 = c8_i50 + 1) {
    for (c8_i51 = 0; c8_i51 < 3; c8_i51 = c8_i51 + 1) {
      c8_b_u[c8_i51 + c8_i49] = (*((real_T (*)[18])c8_u))[c8_i51 + c8_i49];
    }

    c8_i49 = c8_i49 + 3;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 1U, 0U, 2, 3, 6));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

const mxArray *sf_c8_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_ResolvedFunctionInfo c8_info[68];
  c8_ResolvedFunctionInfo (*c8_b_info)[68];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i52;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  c8_b_info = (c8_ResolvedFunctionInfo (*)[68])c8_info;
  (*c8_b_info)[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  (*c8_b_info)[64].name = "eml_xdotc";
  (*c8_b_info)[64].dominantType = "int32";
  (*c8_b_info)[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  (*c8_b_info)[64].fileLength = 1453U;
  (*c8_b_info)[64].fileTime1 = 1209318250U;
  (*c8_b_info)[64].fileTime2 = 0U;
  (*c8_b_info)[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  (*c8_b_info)[65].name = "eml_xdot";
  (*c8_b_info)[65].dominantType = "int32";
  (*c8_b_info)[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  (*c8_b_info)[65].fileLength = 1330U;
  (*c8_b_info)[65].fileTime1 = 1209318250U;
  (*c8_b_info)[65].fileTime2 = 0U;
  (*c8_b_info)[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  (*c8_b_info)[66].name = "eml_refblas_xdot";
  (*c8_b_info)[66].dominantType = "int32";
  (*c8_b_info)[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  (*c8_b_info)[66].fileLength = 343U;
  (*c8_b_info)[66].fileTime1 = 1211203444U;
  (*c8_b_info)[66].fileTime2 = 0U;
  (*c8_b_info)[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  (*c8_b_info)[67].name = "eml_refblas_xdotx";
  (*c8_b_info)[67].dominantType = "int32";
  (*c8_b_info)[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  (*c8_b_info)[67].fileLength = 1605U;
  (*c8_b_info)[67].fileTime1 = 1236241080U;
  (*c8_b_info)[67].fileTime2 = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 68));
  for (c8_i52 = 0; c8_i52 < 68; c8_i52 = c8_i52 + 1) {
    c8_r0 = &c8_info[c8_i52];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context",
                    "nameCaptureInfo", c8_i52);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name",
                    "nameCaptureInfo", c8_i52);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c8_i52);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c8_i52);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c8_i52);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c8_i52
                    );
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c8_i52
                    );
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[68])
{
  c8_info[0].context = "";
  c8_info[0].name = "norm";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[0].fileLength = 5186U;
  c8_info[0].fileTime1 = 1240249448U;
  c8_info[0].fileTime2 = 0U;
  c8_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[1].name = "nargin";
  c8_info[1].dominantType = "";
  c8_info[1].resolved = "[B]nargin";
  c8_info[1].fileLength = 0U;
  c8_info[1].fileTime1 = 0U;
  c8_info[1].fileTime2 = 0U;
  c8_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[2].name = "gt";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved = "[B]gt";
  c8_info[2].fileLength = 0U;
  c8_info[2].fileTime1 = 0U;
  c8_info[2].fileTime2 = 0U;
  c8_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[3].name = "isa";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved = "[B]isa";
  c8_info[3].fileLength = 0U;
  c8_info[3].fileTime1 = 0U;
  c8_info[3].fileTime2 = 0U;
  c8_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[4].name = "ndims";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved = "[B]ndims";
  c8_info[4].fileLength = 0U;
  c8_info[4].fileTime1 = 0U;
  c8_info[4].fileTime2 = 0U;
  c8_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[5].name = "le";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved = "[B]le";
  c8_info[5].fileLength = 0U;
  c8_info[5].fileTime1 = 0U;
  c8_info[5].fileTime2 = 0U;
  c8_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[6].name = "eq";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved = "[B]eq";
  c8_info[6].fileLength = 0U;
  c8_info[6].fileTime1 = 0U;
  c8_info[6].fileTime2 = 0U;
  c8_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[7].name = "lt";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved = "[B]lt";
  c8_info[7].fileLength = 0U;
  c8_info[7].fileTime1 = 0U;
  c8_info[7].fileTime2 = 0U;
  c8_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[8].name = "size";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved = "[B]size";
  c8_info[8].fileLength = 0U;
  c8_info[8].fileTime1 = 0U;
  c8_info[8].fileTime2 = 0U;
  c8_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[9].name = "isempty";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved = "[B]isempty";
  c8_info[9].fileLength = 0U;
  c8_info[9].fileTime1 = 0U;
  c8_info[9].fileTime2 = 0U;
  c8_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[10].name = "isscalar";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved = "[B]isscalar";
  c8_info[10].fileLength = 0U;
  c8_info[10].fileTime1 = 0U;
  c8_info[10].fileTime2 = 0U;
  c8_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[11].name = "isvector";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved = "[B]isvector";
  c8_info[11].fileLength = 0U;
  c8_info[11].fileTime1 = 0U;
  c8_info[11].fileTime2 = 0U;
  c8_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[12].name = "ischar";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved = "[B]ischar";
  c8_info[12].fileLength = 0U;
  c8_info[12].fileTime1 = 0U;
  c8_info[12].fileTime2 = 0U;
  c8_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[13].name = "eml_xnrm2";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[13].fileLength = 718U;
  c8_info[13].fileTime1 = 1209318258U;
  c8_info[13].fileTime2 = 0U;
  c8_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c8_info[14].name = "strcmp";
  c8_info[14].dominantType = "char";
  c8_info[14].resolved = "[B]strcmp";
  c8_info[14].fileLength = 0U;
  c8_info[14].fileTime1 = 0U;
  c8_info[14].fileTime2 = 0U;
  c8_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[15].name = "cast";
  c8_info[15].dominantType = "double";
  c8_info[15].resolved = "[B]cast";
  c8_info[15].fileLength = 0U;
  c8_info[15].fileTime1 = 0U;
  c8_info[15].fileTime2 = 0U;
  c8_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[16].name = "eml_refblas_xnrm2";
  c8_info[16].dominantType = "int32";
  c8_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[16].fileLength = 1433U;
  c8_info[16].fileTime1 = 1240249444U;
  c8_info[16].fileTime2 = 0U;
  c8_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[17].name = "class";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved = "[B]class";
  c8_info[17].fileLength = 0U;
  c8_info[17].fileTime1 = 0U;
  c8_info[17].fileTime2 = 0U;
  c8_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[18].name = "zeros";
  c8_info[18].dominantType = "char";
  c8_info[18].resolved = "[B]zeros";
  c8_info[18].fileLength = 0U;
  c8_info[18].fileTime1 = 0U;
  c8_info[18].fileTime2 = 0U;
  c8_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[19].name = "ones";
  c8_info[19].dominantType = "char";
  c8_info[19].resolved = "[B]ones";
  c8_info[19].fileLength = 0U;
  c8_info[19].fileTime1 = 0U;
  c8_info[19].fileTime2 = 0U;
  c8_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[20].name = "true";
  c8_info[20].dominantType = "";
  c8_info[20].resolved = "[B]true";
  c8_info[20].fileLength = 0U;
  c8_info[20].fileTime1 = 0U;
  c8_info[20].fileTime2 = 0U;
  c8_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[21].name = "eml_index_class";
  c8_info[21].dominantType = "";
  c8_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[21].fileLength = 909U;
  c8_info[21].fileTime1 = 1192454182U;
  c8_info[21].fileTime2 = 0U;
  c8_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[22].name = "eml_index_minus";
  c8_info[22].dominantType = "int32";
  c8_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[22].fileLength = 277U;
  c8_info[22].fileTime1 = 1192454184U;
  c8_info[22].fileTime2 = 0U;
  c8_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[23].name = "eml_index_times";
  c8_info[23].dominantType = "int32";
  c8_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[23].fileLength = 280U;
  c8_info[23].fileTime1 = 1192454188U;
  c8_info[23].fileTime2 = 0U;
  c8_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[24].name = "eml_index_plus";
  c8_info[24].dominantType = "int32";
  c8_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[24].fileLength = 272U;
  c8_info[24].fileTime1 = 1192454186U;
  c8_info[24].fileTime2 = 0U;
  c8_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[25].name = "real";
  c8_info[25].dominantType = "double";
  c8_info[25].resolved = "[B]real";
  c8_info[25].fileLength = 0U;
  c8_info[25].fileTime1 = 0U;
  c8_info[25].fileTime2 = 0U;
  c8_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[26].name = "ne";
  c8_info[26].dominantType = "double";
  c8_info[26].resolved = "[B]ne";
  c8_info[26].fileLength = 0U;
  c8_info[26].fileTime1 = 0U;
  c8_info[26].fileTime2 = 0U;
  c8_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[27].name = "abs";
  c8_info[27].dominantType = "double";
  c8_info[27].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[27].fileLength = 566U;
  c8_info[27].fileTime1 = 1221254534U;
  c8_info[27].fileTime2 = 0U;
  c8_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[28].name = "islogical";
  c8_info[28].dominantType = "double";
  c8_info[28].resolved = "[B]islogical";
  c8_info[28].fileLength = 0U;
  c8_info[28].fileTime1 = 0U;
  c8_info[28].fileTime2 = 0U;
  c8_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[29].name = "eml_scalar_abs";
  c8_info[29].dominantType = "double";
  c8_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[29].fileLength = 461U;
  c8_info[29].fileTime1 = 1203431760U;
  c8_info[29].fileTime2 = 0U;
  c8_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[30].name = "isinteger";
  c8_info[30].dominantType = "double";
  c8_info[30].resolved = "[B]isinteger";
  c8_info[30].fileLength = 0U;
  c8_info[30].fileTime1 = 0U;
  c8_info[30].fileTime2 = 0U;
  c8_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[31].name = "isreal";
  c8_info[31].dominantType = "double";
  c8_info[31].resolved = "[B]isreal";
  c8_info[31].fileLength = 0U;
  c8_info[31].fileTime1 = 0U;
  c8_info[31].fileTime2 = 0U;
  c8_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[32].name = "false";
  c8_info[32].dominantType = "";
  c8_info[32].resolved = "[B]false";
  c8_info[32].fileLength = 0U;
  c8_info[32].fileTime1 = 0U;
  c8_info[32].fileTime2 = 0U;
  c8_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[33].name = "times";
  c8_info[33].dominantType = "double";
  c8_info[33].resolved = "[B]times";
  c8_info[33].fileLength = 0U;
  c8_info[33].fileTime1 = 0U;
  c8_info[33].fileTime2 = 0U;
  c8_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[34].name = "plus";
  c8_info[34].dominantType = "double";
  c8_info[34].resolved = "[B]plus";
  c8_info[34].fileLength = 0U;
  c8_info[34].fileTime1 = 0U;
  c8_info[34].fileTime2 = 0U;
  c8_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[35].name = "imag";
  c8_info[35].dominantType = "double";
  c8_info[35].resolved = "[B]imag";
  c8_info[35].fileLength = 0U;
  c8_info[35].fileTime1 = 0U;
  c8_info[35].fileTime2 = 0U;
  c8_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[36].name = "inf";
  c8_info[36].dominantType = "";
  c8_info[36].resolved = "[B]inf";
  c8_info[36].fileLength = 0U;
  c8_info[36].fileTime1 = 0U;
  c8_info[36].fileTime2 = 0U;
  c8_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[37].name = "isnan";
  c8_info[37].dominantType = "double";
  c8_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[37].fileLength = 506U;
  c8_info[37].fileTime1 = 1228077610U;
  c8_info[37].fileTime2 = 0U;
  c8_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[38].name = "eml_guarded_nan";
  c8_info[38].dominantType = "char";
  c8_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[38].fileLength = 485U;
  c8_info[38].fileTime1 = 1192454180U;
  c8_info[38].fileTime2 = 0U;
  c8_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[39].name = "eml_is_float_class";
  c8_info[39].dominantType = "char";
  c8_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[39].fileLength = 226U;
  c8_info[39].fileTime1 = 1197834242U;
  c8_info[39].fileTime2 = 0U;
  c8_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[40].name = "nan";
  c8_info[40].dominantType = "char";
  c8_info[40].resolved = "[B]nan";
  c8_info[40].fileLength = 0U;
  c8_info[40].fileTime1 = 0U;
  c8_info[40].fileTime2 = 0U;
  c8_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[41].name = "uminus";
  c8_info[41].dominantType = "double";
  c8_info[41].resolved = "[B]uminus";
  c8_info[41].fileLength = 0U;
  c8_info[41].fileTime1 = 0U;
  c8_info[41].fileTime2 = 0U;
  c8_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[42].name = "eml_guarded_inf";
  c8_info[42].dominantType = "char";
  c8_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  c8_info[42].fileLength = 495U;
  c8_info[42].fileTime1 = 1192454178U;
  c8_info[42].fileTime2 = 0U;
  c8_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecpospnorm";
  c8_info[43].name = "isinf";
  c8_info[43].dominantType = "double";
  c8_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c8_info[43].fileLength = 506U;
  c8_info[43].fileTime1 = 1228077610U;
  c8_info[43].fileTime2 = 0U;
  c8_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecpospnorm";
  c8_info[44].name = "power";
  c8_info[44].dominantType = "double";
  c8_info[44].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[44].fileLength = 5380U;
  c8_info[44].fileTime1 = 1228077698U;
  c8_info[44].fileTime2 = 0U;
  c8_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[45].name = "eml_scalar_eg";
  c8_info[45].dominantType = "double";
  c8_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[45].fileLength = 3068U;
  c8_info[45].fileTime1 = 1240249410U;
  c8_info[45].fileTime2 = 0U;
  c8_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[46].name = "isstruct";
  c8_info[46].dominantType = "double";
  c8_info[46].resolved = "[B]isstruct";
  c8_info[46].fileLength = 0U;
  c8_info[46].fileTime1 = 0U;
  c8_info[46].fileTime2 = 0U;
  c8_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[47].name = "eml_scalexp_alloc";
  c8_info[47].dominantType = "double";
  c8_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[47].fileLength = 808U;
  c8_info[47].fileTime1 = 1230478500U;
  c8_info[47].fileTime2 = 0U;
  c8_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[48].name = "minus";
  c8_info[48].dominantType = "double";
  c8_info[48].resolved = "[B]minus";
  c8_info[48].fileLength = 0U;
  c8_info[48].fileTime1 = 0U;
  c8_info[48].fileTime2 = 0U;
  c8_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[49].name = "not";
  c8_info[49].dominantType = "logical";
  c8_info[49].resolved = "[B]not";
  c8_info[49].fileLength = 0U;
  c8_info[49].fileTime1 = 0U;
  c8_info[49].fileTime2 = 0U;
  c8_info[50].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[50].name = "eml_scalar_floor";
  c8_info[50].dominantType = "double";
  c8_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[50].fileLength = 260U;
  c8_info[50].fileTime1 = 1209318190U;
  c8_info[50].fileTime2 = 0U;
  c8_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[51].name = "eml_error";
  c8_info[51].dominantType = "char";
  c8_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c8_info[51].fileLength = 315U;
  c8_info[51].fileTime1 = 1213914146U;
  c8_info[51].fileTime2 = 0U;
  c8_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecpospnorm";
  c8_info[52].name = "mtimes";
  c8_info[52].dominantType = "double";
  c8_info[52].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[52].fileLength = 3302U;
  c8_info[52].fileTime1 = 1242738294U;
  c8_info[52].fileTime2 = 0U;
  c8_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecnegpnorm";
  c8_info[53].name = "mpower";
  c8_info[53].dominantType = "double";
  c8_info[53].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[53].fileLength = 3710U;
  c8_info[53].fileTime1 = 1238421690U;
  c8_info[53].fileTime2 = 0U;
  c8_info[54].context = "";
  c8_info[54].name = "mrdivide";
  c8_info[54].dominantType = "double";
  c8_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[54].fileLength = 800U;
  c8_info[54].fileTime1 = 1238421692U;
  c8_info[54].fileTime2 = 0U;
  c8_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[55].name = "ge";
  c8_info[55].dominantType = "double";
  c8_info[55].resolved = "[B]ge";
  c8_info[55].fileLength = 0U;
  c8_info[55].fileTime1 = 0U;
  c8_info[55].fileTime2 = 0U;
  c8_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[56].name = "rdivide";
  c8_info[56].dominantType = "double";
  c8_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[56].fileLength = 620U;
  c8_info[56].fileTime1 = 1213914166U;
  c8_info[56].fileTime2 = 0U;
  c8_info[57].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[57].name = "eml_warning";
  c8_info[57].dominantType = "char";
  c8_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c8_info[57].fileLength = 262U;
  c8_info[57].fileTime1 = 1236241078U;
  c8_info[57].fileTime2 = 0U;
  c8_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[58].name = "eml_div";
  c8_info[58].dominantType = "double";
  c8_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[58].fileLength = 4269U;
  c8_info[58].fileTime1 = 1228077626U;
  c8_info[58].fileTime2 = 0U;
  c8_info[59].context = "";
  c8_info[59].name = "dot";
  c8_info[59].dominantType = "double";
  c8_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c8_info[59].fileLength = 2812U;
  c8_info[59].fileTime1 = 1236241088U;
  c8_info[59].fileTime2 = 0U;
  c8_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c8_info[60].name = "isequal";
  c8_info[60].dominantType = "double";
  c8_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[60].fileLength = 180U;
  c8_info[60].fileTime1 = 1226561072U;
  c8_info[60].fileTime2 = 0U;
  c8_info[61].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[61].name = "eml_isequal_core";
  c8_info[61].dominantType = "double";
  c8_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[61].fileLength = 3981U;
  c8_info[61].fileTime1 = 1236241072U;
  c8_info[61].fileTime2 = 0U;
  c8_info[62].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[62].name = "isnumeric";
  c8_info[62].dominantType = "double";
  c8_info[62].resolved = "[B]isnumeric";
  c8_info[62].fileLength = 0U;
  c8_info[62].fileTime1 = 0U;
  c8_info[62].fileTime2 = 0U;
  c8_info[63].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c8_info[63].name = "isfloat";
  c8_info[63].dominantType = "double";
  c8_info[63].resolved = "[B]isfloat";
  c8_info[63].fileLength = 0U;
  c8_info[63].fileTime1 = 0U;
  c8_info[63].fileTime2 = 0U;
}

static const mxArray *c8_d_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  boolean_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_b_u = *((boolean_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c8_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3769996806U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2007055943U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4262790002U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4168072932U);
}

mxArray *sf_c8_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2652782353U);
    pr[1] = (double)(520028945U);
    pr[2] = (double)(3297511018U);
    pr[3] = (double)(3544970137U);
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

static mxArray *sf_get_sim_state_info_c8_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"solar_drag\",},{M[8],M[0],T\"is_active_c8_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           8,
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
                                1.0,0,"v_Sun_b",0,(MexFcnForType)c8_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"solar_drag",0,(MexFcnForType)
                                c8_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Ca_Solar_Drag",0,(MexFcnForType)c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "P_momentum_flux_from_the_sun",0,(MexFcnForType)
                              c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"light",0,
                              (MexFcnForType)c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(5,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"side",0,
                              (MexFcnForType)c8_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,2,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,661);
        _SFD_CV_INIT_EML_IF(0,0,219,242,260,301);
        _SFD_CV_INIT_EML_IF(0,1,535,542,-1,571);
        _SFD_CV_INIT_EML_FOR(0,0,497,507,575);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c8_v_Sun_b)[3];
          real_T (*c8_solar_drag)[3];
          real_T *c8_light;
          c8_solar_drag = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S,
            1);
          c8_light = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c8_v_Sun_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_v_Sun_b);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_solar_drag);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance.c8_Ca_Solar_Drag);
          _SFD_SET_DATA_VALUE_PTR(3U,
            &chartInstance.c8_P_momentum_flux_from_the_sun);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_light);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance.c8_side);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c8_adcs_v15_integral_Power();
  initialize_c8_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c8_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c8_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c8_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c8_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c8_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c8_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c8_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c8_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c8_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c8_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c8_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c8_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c8_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c8_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c8_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     Ca_Solar_Drag P_momentum_flux_from_the_sun side
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Ca_Solar_Drag*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for P_momentum_flux_from_the_sun*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for side*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",8,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",8,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",8,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2330672108U));
  ssSetChecksum1(S,(4023252211U));
  ssSetChecksum2(S,(2694936797U));
  ssSetChecksum3(S,(1773980896U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c8_adcs_v15_integral_Power;
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

void c8_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
