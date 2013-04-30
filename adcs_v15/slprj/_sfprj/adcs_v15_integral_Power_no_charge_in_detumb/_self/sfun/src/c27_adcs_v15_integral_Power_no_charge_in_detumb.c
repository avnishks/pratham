/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_no_charge_in_detumb_sfun.h"
#include "c27_adcs_v15_integral_Power_no_charge_in_detumb.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c27_IN_NO_ACTIVE_CHILD         (0)
#define c27_b_s_FRAME_SIZE             (2.0)

/* Variable Declarations */

/* Variable Definitions */
static SFc27_adcs_v15_integral_Power_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void initialize_params_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void);
static void enable_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void disable_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void c27_update_debugger_state_c27_adcs_v15_integral_Power_no_charge(void);
static void ext_mode_exec_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static const mxArray
  *get_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void set_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(const
  mxArray *c27_st);
static void finalize_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void sf_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void c27_c27_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber);
static void c27_eml_warning(void);
static void c27_eml_scalar_eg(void);
static const mxArray *c27_sf_marshall(void *c27_chartInstance, void *c27_u);
static const mxArray *c27_b_sf_marshall(void *c27_chartInstance, void *c27_u);
static const mxArray *c27_c_sf_marshall(void *c27_chartInstance, void *c27_u);
static const mxArray *c27_d_sf_marshall(void *c27_chartInstance, void *c27_u);
static void c27_info_helper(c27_ResolvedFunctionInfo c27_info[58]);
static const mxArray *c27_e_sf_marshall(void *c27_chartInstance, void *c27_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  uint8_T *c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb = 0U;
}

static void initialize_params_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void)
{
  real_T c27_d0;
  real_T c27_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_FRAME_SIZE' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c27_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c27_s_FRAME_SIZE = c27_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_TAU_W' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c27_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c27_s_TAU_W = c27_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c27_update_debugger_state_c27_adcs_v15_integral_Power_no_charge(void)
{
}

static void ext_mode_exec_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  c27_update_debugger_state_c27_adcs_v15_integral_Power_no_charge();
}

static const mxArray
  *get_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  const mxArray *c27_st = NULL;
  const mxArray *c27_y = NULL;
  int32_T c27_i0;
  real_T c27_u[3];
  const mxArray *c27_b_y = NULL;
  int32_T c27_i1;
  real_T c27_b_u[3];
  const mxArray *c27_c_y = NULL;
  uint8_T c27_c_u;
  const mxArray *c27_d_y = NULL;
  uint8_T *c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  real_T (*c27_w_l)[3];
  real_T (*c27_w)[3];
  c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c27_w_l = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c27_w = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellarray(3));
  for (c27_i0 = 0; c27_i0 < 3; c27_i0 = c27_i0 + 1) {
    c27_u[c27_i0] = (*c27_w)[c27_i0];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c27_y, 0, c27_b_y);
  for (c27_i1 = 0; c27_i1 < 3; c27_i1 = c27_i1 + 1) {
    c27_b_u[c27_i1] = (*c27_w_l)[c27_i1];
  }

  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c27_y, 1, c27_c_y);
  c27_c_u = *c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c27_y, 2, c27_d_y);
  sf_mex_assign(&c27_st, c27_y);
  return c27_st;
}

static void set_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(const
  mxArray *c27_st)
{
  const mxArray *c27_u;
  const mxArray *c27_w;
  real_T c27_dv0[3];
  int32_T c27_i2;
  real_T c27_y[3];
  int32_T c27_i3;
  const mxArray *c27_b_w;
  real_T c27_dv1[3];
  int32_T c27_i4;
  real_T c27_b_y[3];
  int32_T c27_i5;
  const mxArray *c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T c27_u0;
  uint8_T c27_c_y;
  boolean_T *c27_doneDoubleBufferReInit;
  uint8_T *c27_b_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  real_T (*c27_c_w)[3];
  real_T (*c27_w_l)[3];
  c27_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c27_b_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c27_w_l = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c27_c_w = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  *c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  c27_w = sf_mex_dup(sf_mex_getcell(c27_u, 0));
  sf_mex_import("w", sf_mex_dup(c27_w), &c27_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c27_i2 = 0; c27_i2 < 3; c27_i2 = c27_i2 + 1) {
    c27_y[c27_i2] = c27_dv0[c27_i2];
  }

  sf_mex_destroy(&c27_w);
  for (c27_i3 = 0; c27_i3 < 3; c27_i3 = c27_i3 + 1) {
    (*c27_c_w)[c27_i3] = c27_y[c27_i3];
  }

  c27_b_w = sf_mex_dup(sf_mex_getcell(c27_u, 1));
  sf_mex_import("w_l", sf_mex_dup(c27_b_w), &c27_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c27_i4 = 0; c27_i4 < 3; c27_i4 = c27_i4 + 1) {
    c27_b_y[c27_i4] = c27_dv1[c27_i4];
  }

  sf_mex_destroy(&c27_b_w);
  for (c27_i5 = 0; c27_i5 < 3; c27_i5 = c27_i5 + 1) {
    (*c27_w_l)[c27_i5] = c27_b_y[c27_i5];
  }

  c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb = sf_mex_dup
    (sf_mex_getcell(c27_u, 2));
  sf_mex_import("is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb",
                sf_mex_dup(
    c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb), &c27_u0, 1,
                3, 0U, 0, 0U, 0);
  c27_c_y = c27_u0;
  sf_mex_destroy(&c27_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb);
  *c27_b_is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb = c27_c_y;
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_adcs_v15_integral_Power_no_charge();
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
}

static void sf_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  int32_T c27_i6;
  int32_T c27_i7;
  int32_T c27_i8;
  int32_T c27_i9;
  int32_T c27_i10;
  int32_T c27_previousEvent;
  real_T (*c27_w)[3];
  real_T (*c27_q_BI_k)[4];
  real_T (*c27_q_BI_l)[4];
  real_T (*c27_w_k)[3];
  real_T (*c27_w_l)[3];
  c27_w_l = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c27_w_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c27_q_BI_l = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 1);
  c27_q_BI_k = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
  c27_w = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,20);
  for (c27_i6 = 0; c27_i6 < 3; c27_i6 = c27_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c27_w_l)[c27_i6], 0U);
  }

  for (c27_i7 = 0; c27_i7 < 3; c27_i7 = c27_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c27_w_k)[c27_i7], 1U);
  }

  for (c27_i8 = 0; c27_i8 < 4; c27_i8 = c27_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c27_q_BI_l)[c27_i8], 2U);
  }

  for (c27_i9 = 0; c27_i9 < 4; c27_i9 = c27_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c27_q_BI_k)[c27_i9], 3U);
  }

  for (c27_i10 = 0; c27_i10 < 3; c27_i10 = c27_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c27_w)[c27_i10], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c27_s_FRAME_SIZE, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c27_s_TAU_W, 6U);
  c27_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c27_c27_adcs_v15_integral_Power_no_charge_in_detumb();
  _sfEvent_ = c27_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c27_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  int32_T c27_i11;
  real_T c27_w_k[3];
  int32_T c27_i12;
  real_T c27_q_BI_l[4];
  int32_T c27_i13;
  real_T c27_q_BI_k[4];
  real_T c27_b_s_TAU_W;
  real_T c27_nargout = 2.0;
  real_T c27_nargin = 5.0;
  real_T c27_c_s_FRAME_SIZE = c27_b_s_FRAME_SIZE;
  real_T c27_a;
  real_T c27_ex[9];
  real_T c27_n;
  real_T c27_e[3];
  real_T c27_de[3];
  real_T c27_q[4];
  real_T c27_dq[4];
  real_T c27_w[3];
  real_T c27_w_l[3];
  int32_T c27_i14;
  real_T c27_A[4];
  int32_T c27_i15;
  real_T c27_x[4];
  int32_T c27_i16;
  real_T c27_b_x[4];
  int32_T c27_i17;
  real_T c27_c_x[4];
  int32_T c27_i18;
  int32_T c27_i19;
  real_T c27_b_A[4];
  int32_T c27_i20;
  real_T c27_d_x[4];
  int32_T c27_i21;
  real_T c27_e_x[4];
  int32_T c27_i22;
  real_T c27_f_x[4];
  int32_T c27_i23;
  int32_T c27_i24;
  int32_T c27_i25;
  int32_T c27_i26;
  real_T c27_b_a[3];
  int32_T c27_i27;
  real_T c27_b[3];
  int32_T c27_i28;
  int32_T c27_i29;
  int32_T c27_i30;
  real_T c27_y[9];
  real_T c27_c_a;
  int32_T c27_i31;
  real_T c27_b_b[9];
  int32_T c27_i32;
  real_T c27_b_y[9];
  real_T c27_d_a;
  real_T c27_c_b;
  real_T c27_e_a;
  int32_T c27_i33;
  static real_T c27_dv2[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c27_c_y[9];
  int32_T c27_i34;
  real_T c27_d_b[9];
  int32_T c27_i35;
  real_T c27_f_a[9];
  int32_T c27_i36;
  real_T c27_e_b[3];
  int32_T c27_i37;
  real_T c27_c_A[9];
  int32_T c27_i38;
  real_T c27_B[3];
  int32_T c27_i39;
  real_T c27_d_A[9];
  int32_T c27_i40;
  real_T c27_b_B[3];
  int32_T c27_i41;
  real_T c27_e_A[9];
  int32_T c27_i42;
  real_T c27_c_B[3];
  int32_T c27_i43;
  real_T c27_f_A[3];
  int32_T c27_i44;
  int32_T c27_i45;
  real_T c27_d_B;
  int32_T c27_i46;
  real_T c27_g_x[3];
  real_T c27_d_y;
  int32_T c27_i47;
  real_T c27_h_x[3];
  real_T c27_e_y;
  int32_T c27_i48;
  real_T c27_i_x[3];
  real_T c27_f_y;
  int32_T c27_i49;
  real_T c27_e_B;
  real_T c27_g_y;
  real_T c27_h_y;
  real_T c27_i_y;
  real_T c27_g_a;
  int32_T c27_i50;
  real_T c27_f_b[3];
  int32_T c27_i51;
  real_T c27_j_y[3];
  real_T c27_h_a;
  int32_T c27_i52;
  real_T c27_g_b[3];
  int32_T c27_i53;
  real_T c27_k_y[3];
  int32_T c27_i54;
  int32_T c27_i55;
  int32_T c27_i56;
  real_T (*c27_b_w_l)[3];
  real_T (*c27_b_w)[3];
  real_T (*c27_b_q_BI_k)[4];
  real_T (*c27_b_q_BI_l)[4];
  real_T (*c27_b_w_k)[3];
  c27_b_w_l = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c27_b_w_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c27_b_q_BI_l = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 1);
  c27_b_q_BI_k = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
  c27_b_w = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,20);
  for (c27_i11 = 0; c27_i11 < 3; c27_i11 = c27_i11 + 1) {
    c27_w_k[c27_i11] = (*c27_b_w_k)[c27_i11];
  }

  for (c27_i12 = 0; c27_i12 < 4; c27_i12 = c27_i12 + 1) {
    c27_q_BI_l[c27_i12] = (*c27_b_q_BI_l)[c27_i12];
  }

  for (c27_i13 = 0; c27_i13 < 4; c27_i13 = c27_i13 + 1) {
    c27_q_BI_k[c27_i13] = (*c27_b_q_BI_k)[c27_i13];
  }

  c27_b_s_TAU_W = chartInstance.c27_s_TAU_W;
  sf_debug_symbol_scope_push(16U, 0U);
  sf_debug_symbol_scope_add("nargout", &c27_nargout, c27_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c27_nargin, c27_c_sf_marshall);
  sf_debug_symbol_scope_add("s_FRAME_SIZE", &c27_c_s_FRAME_SIZE,
    c27_c_sf_marshall);
  sf_debug_symbol_scope_add("a", &c27_a, c27_c_sf_marshall);
  sf_debug_symbol_scope_add("ex", &c27_ex, c27_d_sf_marshall);
  sf_debug_symbol_scope_add("n", &c27_n, c27_c_sf_marshall);
  sf_debug_symbol_scope_add("e", &c27_e, c27_sf_marshall);
  sf_debug_symbol_scope_add("de", &c27_de, c27_sf_marshall);
  sf_debug_symbol_scope_add("q", &c27_q, c27_b_sf_marshall);
  sf_debug_symbol_scope_add("dq", &c27_dq, c27_b_sf_marshall);
  sf_debug_symbol_scope_add("w", &c27_w, c27_sf_marshall);
  sf_debug_symbol_scope_add("w_l", &c27_w_l, c27_sf_marshall);
  sf_debug_symbol_scope_add("s_TAU_W", &c27_b_s_TAU_W, c27_c_sf_marshall);
  sf_debug_symbol_scope_add("q_BI_k", &c27_q_BI_k, c27_b_sf_marshall);
  sf_debug_symbol_scope_add("q_BI_l", &c27_q_BI_l, c27_b_sf_marshall);
  sf_debug_symbol_scope_add("w_k", &c27_w_k, c27_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,4);
  for (c27_i14 = 0; c27_i14 < 4; c27_i14 = c27_i14 + 1) {
    c27_A[c27_i14] = c27_q_BI_l[c27_i14] - c27_q_BI_k[c27_i14];
  }

  for (c27_i15 = 0; c27_i15 < 4; c27_i15 = c27_i15 + 1) {
    c27_x[c27_i15] = c27_A[c27_i15];
  }

  for (c27_i16 = 0; c27_i16 < 4; c27_i16 = c27_i16 + 1) {
    c27_b_x[c27_i16] = c27_x[c27_i16];
  }

  for (c27_i17 = 0; c27_i17 < 4; c27_i17 = c27_i17 + 1) {
    c27_c_x[c27_i17] = c27_b_x[c27_i17];
  }

  for (c27_i18 = 0; c27_i18 < 4; c27_i18 = c27_i18 + 1) {
    c27_dq[c27_i18] = c27_c_x[c27_i18] / c27_b_s_FRAME_SIZE;
  }

  _SFD_EML_CALL(0,5);
  for (c27_i19 = 0; c27_i19 < 4; c27_i19 = c27_i19 + 1) {
    c27_b_A[c27_i19] = c27_q_BI_l[c27_i19] + c27_q_BI_k[c27_i19];
  }

  for (c27_i20 = 0; c27_i20 < 4; c27_i20 = c27_i20 + 1) {
    c27_d_x[c27_i20] = c27_b_A[c27_i20];
  }

  for (c27_i21 = 0; c27_i21 < 4; c27_i21 = c27_i21 + 1) {
    c27_e_x[c27_i21] = c27_d_x[c27_i21];
  }

  for (c27_i22 = 0; c27_i22 < 4; c27_i22 = c27_i22 + 1) {
    c27_f_x[c27_i22] = c27_e_x[c27_i22];
  }

  for (c27_i23 = 0; c27_i23 < 4; c27_i23 = c27_i23 + 1) {
    c27_q[c27_i23] = c27_f_x[c27_i23] / 2.0;
  }

  _SFD_EML_CALL(0,7);
  for (c27_i24 = 0; c27_i24 < 3; c27_i24 = c27_i24 + 1) {
    c27_de[c27_i24] = c27_dq[c27_i24];
  }

  _SFD_EML_CALL(0,8);
  for (c27_i25 = 0; c27_i25 < 3; c27_i25 = c27_i25 + 1) {
    c27_e[c27_i25] = c27_q[c27_i25];
  }

  _SFD_EML_CALL(0,9);
  c27_n = c27_q[3];
  _SFD_EML_CALL(0,11);
  c27_ex[0] = 0.0;
  c27_ex[3] = -c27_e[2];
  c27_ex[6] = c27_e[1];
  c27_ex[1] = c27_e[2];
  c27_ex[4] = 0.0;
  c27_ex[7] = -c27_e[0];
  c27_ex[2] = -c27_e[1];
  c27_ex[5] = c27_e[0];
  c27_ex[8] = 0.0;
  _SFD_EML_CALL(0,15);
  for (c27_i26 = 0; c27_i26 < 3; c27_i26 = c27_i26 + 1) {
    c27_b_a[c27_i26] = c27_e[c27_i26];
  }

  for (c27_i27 = 0; c27_i27 < 3; c27_i27 = c27_i27 + 1) {
    c27_b[c27_i27] = c27_e[c27_i27];
  }

  c27_i28 = 0;
  for (c27_i29 = 0; c27_i29 < 3; c27_i29 = c27_i29 + 1) {
    for (c27_i30 = 0; c27_i30 < 3; c27_i30 = c27_i30 + 1) {
      c27_y[c27_i30 + c27_i28] = c27_b_a[c27_i30] * c27_b[c27_i29];
    }

    c27_i28 = c27_i28 + 3;
  }

  c27_c_a = c27_n;
  for (c27_i31 = 0; c27_i31 < 9; c27_i31 = c27_i31 + 1) {
    c27_b_b[c27_i31] = c27_ex[c27_i31];
  }

  for (c27_i32 = 0; c27_i32 < 9; c27_i32 = c27_i32 + 1) {
    c27_b_y[c27_i32] = c27_c_a * c27_b_b[c27_i32];
  }

  c27_d_a = c27_n;
  c27_c_b = c27_n;
  c27_e_a = c27_d_a * c27_c_b;
  for (c27_i33 = 0; c27_i33 < 9; c27_i33 = c27_i33 + 1) {
    c27_c_y[c27_i33] = c27_e_a * c27_dv2[c27_i33];
  }

  for (c27_i34 = 0; c27_i34 < 9; c27_i34 = c27_i34 + 1) {
    c27_d_b[c27_i34] = (c27_c_y[c27_i34] - c27_b_y[c27_i34]) + c27_y[c27_i34];
  }

  for (c27_i35 = 0; c27_i35 < 9; c27_i35 = c27_i35 + 1) {
    c27_f_a[c27_i35] = 2.0 * c27_d_b[c27_i35];
  }

  for (c27_i36 = 0; c27_i36 < 3; c27_i36 = c27_i36 + 1) {
    c27_e_b[c27_i36] = c27_de[c27_i36];
  }

  c27_eml_scalar_eg();
  c27_eml_scalar_eg();
  for (c27_i37 = 0; c27_i37 < 9; c27_i37 = c27_i37 + 1) {
    c27_c_A[c27_i37] = c27_f_a[c27_i37];
  }

  for (c27_i38 = 0; c27_i38 < 3; c27_i38 = c27_i38 + 1) {
    c27_B[c27_i38] = c27_e_b[c27_i38];
  }

  for (c27_i39 = 0; c27_i39 < 9; c27_i39 = c27_i39 + 1) {
    c27_d_A[c27_i39] = c27_c_A[c27_i39];
  }

  for (c27_i40 = 0; c27_i40 < 3; c27_i40 = c27_i40 + 1) {
    c27_b_B[c27_i40] = c27_B[c27_i40];
  }

  for (c27_i41 = 0; c27_i41 < 9; c27_i41 = c27_i41 + 1) {
    c27_e_A[c27_i41] = c27_d_A[c27_i41];
  }

  for (c27_i42 = 0; c27_i42 < 3; c27_i42 = c27_i42 + 1) {
    c27_c_B[c27_i42] = c27_b_B[c27_i42];
  }

  for (c27_i43 = 0; c27_i43 < 3; c27_i43 = c27_i43 + 1) {
    c27_f_A[c27_i43] = 0.0;
    c27_i44 = 0;
    for (c27_i45 = 0; c27_i45 < 3; c27_i45 = c27_i45 + 1) {
      c27_f_A[c27_i43] = c27_f_A[c27_i43] + c27_e_A[c27_i44 + c27_i43] *
        c27_c_B[c27_i45];
      c27_i44 = c27_i44 + 3;
    }
  }

  c27_d_B = c27_n;
  for (c27_i46 = 0; c27_i46 < 3; c27_i46 = c27_i46 + 1) {
    c27_g_x[c27_i46] = c27_f_A[c27_i46];
  }

  c27_d_y = c27_d_B;
  if (c27_d_y == 0.0) {
    c27_eml_warning();
  }

  for (c27_i47 = 0; c27_i47 < 3; c27_i47 = c27_i47 + 1) {
    c27_h_x[c27_i47] = c27_g_x[c27_i47];
  }

  c27_e_y = c27_d_y;
  for (c27_i48 = 0; c27_i48 < 3; c27_i48 = c27_i48 + 1) {
    c27_i_x[c27_i48] = c27_h_x[c27_i48];
  }

  c27_f_y = c27_e_y;
  for (c27_i49 = 0; c27_i49 < 3; c27_i49 = c27_i49 + 1) {
    c27_w[c27_i49] = c27_i_x[c27_i49] / c27_f_y;
  }

  /*  filtering: */
  _SFD_EML_CALL(0,19);
  c27_e_B = c27_b_s_FRAME_SIZE + c27_b_s_TAU_W;
  c27_g_y = c27_e_B;
  if (c27_g_y == 0.0) {
    c27_eml_warning();
  }

  c27_h_y = c27_g_y;
  c27_i_y = c27_h_y;
  c27_a = 2.0 / c27_i_y;
  _SFD_EML_CALL(0,20);
  c27_g_a = 1.0 - c27_a;
  for (c27_i50 = 0; c27_i50 < 3; c27_i50 = c27_i50 + 1) {
    c27_f_b[c27_i50] = c27_w_k[c27_i50];
  }

  for (c27_i51 = 0; c27_i51 < 3; c27_i51 = c27_i51 + 1) {
    c27_j_y[c27_i51] = c27_g_a * c27_f_b[c27_i51];
  }

  c27_h_a = c27_a;
  for (c27_i52 = 0; c27_i52 < 3; c27_i52 = c27_i52 + 1) {
    c27_g_b[c27_i52] = c27_w[c27_i52];
  }

  for (c27_i53 = 0; c27_i53 < 3; c27_i53 = c27_i53 + 1) {
    c27_k_y[c27_i53] = c27_h_a * c27_g_b[c27_i53];
  }

  for (c27_i54 = 0; c27_i54 < 3; c27_i54 = c27_i54 + 1) {
    c27_w_l[c27_i54] = c27_k_y[c27_i54] + c27_j_y[c27_i54];
  }

  _SFD_EML_CALL(0,-20);
  sf_debug_symbol_scope_pop();
  for (c27_i55 = 0; c27_i55 < 3; c27_i55 = c27_i55 + 1) {
    (*c27_b_w_l)[c27_i55] = c27_w_l[c27_i55];
  }

  for (c27_i56 = 0; c27_i56 < 3; c27_i56 = c27_i56 + 1) {
    (*c27_b_w)[c27_i56] = c27_w[c27_i56];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,20);
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber)
{
}

static void c27_eml_warning(void)
{
  int32_T c27_i57;
  static char_T c27_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c27_u[15];
  const mxArray *c27_y = NULL;
  int32_T c27_i58;
  static char_T c27_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c27_b_u[19];
  const mxArray *c27_b_y = NULL;
  for (c27_i57 = 0; c27_i57 < 15; c27_i57 = c27_i57 + 1) {
    c27_u[c27_i57] = c27_cv0[c27_i57];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c27_i58 = 0; c27_i58 < 19; c27_i58 = c27_i58 + 1) {
    c27_b_u[c27_i58] = c27_cv1[c27_i58];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c27_b_y, 14, c27_y);
}

static void c27_eml_scalar_eg(void)
{
}

static const mxArray *c27_sf_marshall(void *c27_chartInstance, void *c27_u)
{
  const mxArray *c27_y = NULL;
  int32_T c27_i59;
  real_T c27_b_u[3];
  const mxArray *c27_b_y = NULL;
  c27_y = NULL;
  for (c27_i59 = 0; c27_i59 < 3; c27_i59 = c27_i59 + 1) {
    c27_b_u[c27_i59] = (*((real_T (*)[3])c27_u))[c27_i59];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c27_y, c27_b_y);
  return c27_y;
}

static const mxArray *c27_b_sf_marshall(void *c27_chartInstance, void *c27_u)
{
  const mxArray *c27_y = NULL;
  int32_T c27_i60;
  real_T c27_b_u[4];
  const mxArray *c27_b_y = NULL;
  c27_y = NULL;
  for (c27_i60 = 0; c27_i60 < 4; c27_i60 = c27_i60 + 1) {
    c27_b_u[c27_i60] = (*((real_T (*)[4])c27_u))[c27_i60];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c27_y, c27_b_y);
  return c27_y;
}

static const mxArray *c27_c_sf_marshall(void *c27_chartInstance, void *c27_u)
{
  const mxArray *c27_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_b_y = NULL;
  c27_y = NULL;
  c27_b_u = *((real_T *)c27_u);
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c27_y, c27_b_y);
  return c27_y;
}

static const mxArray *c27_d_sf_marshall(void *c27_chartInstance, void *c27_u)
{
  const mxArray *c27_y = NULL;
  int32_T c27_i61;
  int32_T c27_i62;
  int32_T c27_i63;
  real_T c27_b_u[9];
  const mxArray *c27_b_y = NULL;
  c27_y = NULL;
  c27_i61 = 0;
  for (c27_i62 = 0; c27_i62 < 3; c27_i62 = c27_i62 + 1) {
    for (c27_i63 = 0; c27_i63 < 3; c27_i63 = c27_i63 + 1) {
      c27_b_u[c27_i63 + c27_i61] = (*((real_T (*)[9])c27_u))[c27_i63 + c27_i61];
    }

    c27_i61 = c27_i61 + 3;
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c27_y, c27_b_y);
  return c27_y;
}

const mxArray
  *sf_c27_adcs_v15_integral_Power_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_ResolvedFunctionInfo c27_info[58];
  const mxArray *c27_m0 = NULL;
  int32_T c27_i64;
  c27_ResolvedFunctionInfo *c27_r0;
  c27_nameCaptureInfo = NULL;
  c27_info_helper(c27_info);
  sf_mex_assign(&c27_m0, sf_mex_createstruct("nameCaptureInfo", 1, 58));
  for (c27_i64 = 0; c27_i64 < 58; c27_i64 = c27_i64 + 1) {
    c27_r0 = &c27_info[c27_i64];
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->context)), "context"
                    , "nameCaptureInfo", c27_i64);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->name)), "name",
                    "nameCaptureInfo", c27_i64);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      c27_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c27_i64);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->resolved)),
                    "resolved", "nameCaptureInfo", c27_i64);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c27_i64);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c27_i64);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c27_i64);
  }

  sf_mex_assign(&c27_nameCaptureInfo, c27_m0);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(c27_ResolvedFunctionInfo c27_info[58])
{
  c27_info[0].context = "";
  c27_info[0].name = "minus";
  c27_info[0].dominantType = "double";
  c27_info[0].resolved = "[B]minus";
  c27_info[0].fileLength = 0U;
  c27_info[0].fileTime1 = 0U;
  c27_info[0].fileTime2 = 0U;
  c27_info[1].context = "";
  c27_info[1].name = "mrdivide";
  c27_info[1].dominantType = "double";
  c27_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c27_info[1].fileLength = 800U;
  c27_info[1].fileTime1 = 1238421692U;
  c27_info[1].fileTime2 = 0U;
  c27_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c27_info[2].name = "nargin";
  c27_info[2].dominantType = "";
  c27_info[2].resolved = "[B]nargin";
  c27_info[2].fileLength = 0U;
  c27_info[2].fileTime1 = 0U;
  c27_info[2].fileTime2 = 0U;
  c27_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c27_info[3].name = "ge";
  c27_info[3].dominantType = "double";
  c27_info[3].resolved = "[B]ge";
  c27_info[3].fileLength = 0U;
  c27_info[3].fileTime1 = 0U;
  c27_info[3].fileTime2 = 0U;
  c27_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c27_info[4].name = "isscalar";
  c27_info[4].dominantType = "double";
  c27_info[4].resolved = "[B]isscalar";
  c27_info[4].fileLength = 0U;
  c27_info[4].fileTime1 = 0U;
  c27_info[4].fileTime2 = 0U;
  c27_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c27_info[5].name = "rdivide";
  c27_info[5].dominantType = "double";
  c27_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[5].fileLength = 620U;
  c27_info[5].fileTime1 = 1213914166U;
  c27_info[5].fileTime2 = 0U;
  c27_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[6].name = "gt";
  c27_info[6].dominantType = "double";
  c27_info[6].resolved = "[B]gt";
  c27_info[6].fileLength = 0U;
  c27_info[6].fileTime1 = 0U;
  c27_info[6].fileTime2 = 0U;
  c27_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[7].name = "isa";
  c27_info[7].dominantType = "double";
  c27_info[7].resolved = "[B]isa";
  c27_info[7].fileLength = 0U;
  c27_info[7].fileTime1 = 0U;
  c27_info[7].fileTime2 = 0U;
  c27_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[8].name = "isempty";
  c27_info[8].dominantType = "double";
  c27_info[8].resolved = "[B]isempty";
  c27_info[8].fileLength = 0U;
  c27_info[8].fileTime1 = 0U;
  c27_info[8].fileTime2 = 0U;
  c27_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[9].name = "not";
  c27_info[9].dominantType = "logical";
  c27_info[9].resolved = "[B]not";
  c27_info[9].fileLength = 0U;
  c27_info[9].fileTime1 = 0U;
  c27_info[9].fileTime2 = 0U;
  c27_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[10].name = "strcmp";
  c27_info[10].dominantType = "char";
  c27_info[10].resolved = "[B]strcmp";
  c27_info[10].fileLength = 0U;
  c27_info[10].fileTime1 = 0U;
  c27_info[10].fileTime2 = 0U;
  c27_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[11].name = "eq";
  c27_info[11].dominantType = "double";
  c27_info[11].resolved = "[B]eq";
  c27_info[11].fileLength = 0U;
  c27_info[11].fileTime1 = 0U;
  c27_info[11].fileTime2 = 0U;
  c27_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[12].name = "eml_warning";
  c27_info[12].dominantType = "char";
  c27_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c27_info[12].fileLength = 262U;
  c27_info[12].fileTime1 = 1236241078U;
  c27_info[12].fileTime2 = 0U;
  c27_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[13].name = "eml_div";
  c27_info[13].dominantType = "double";
  c27_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c27_info[13].fileLength = 4269U;
  c27_info[13].fileTime1 = 1228077626U;
  c27_info[13].fileTime2 = 0U;
  c27_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c27_info[14].name = "isinteger";
  c27_info[14].dominantType = "double";
  c27_info[14].resolved = "[B]isinteger";
  c27_info[14].fileLength = 0U;
  c27_info[14].fileTime1 = 0U;
  c27_info[14].fileTime2 = 0U;
  c27_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c27_info[15].name = "isreal";
  c27_info[15].dominantType = "double";
  c27_info[15].resolved = "[B]isreal";
  c27_info[15].fileLength = 0U;
  c27_info[15].fileTime1 = 0U;
  c27_info[15].fileTime2 = 0U;
  c27_info[16].context = "";
  c27_info[16].name = "plus";
  c27_info[16].dominantType = "double";
  c27_info[16].resolved = "[B]plus";
  c27_info[16].fileLength = 0U;
  c27_info[16].fileTime1 = 0U;
  c27_info[16].fileTime2 = 0U;
  c27_info[17].context = "";
  c27_info[17].name = "uminus";
  c27_info[17].dominantType = "double";
  c27_info[17].resolved = "[B]uminus";
  c27_info[17].fileLength = 0U;
  c27_info[17].fileTime1 = 0U;
  c27_info[17].fileTime2 = 0U;
  c27_info[18].context = "";
  c27_info[18].name = "mtimes";
  c27_info[18].dominantType = "double";
  c27_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[18].fileLength = 3302U;
  c27_info[18].fileTime1 = 1242738294U;
  c27_info[18].fileTime2 = 0U;
  c27_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[19].name = "size";
  c27_info[19].dominantType = "double";
  c27_info[19].resolved = "[B]size";
  c27_info[19].fileLength = 0U;
  c27_info[19].fileTime1 = 0U;
  c27_info[19].fileTime2 = 0U;
  c27_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[20].name = "class";
  c27_info[20].dominantType = "double";
  c27_info[20].resolved = "[B]class";
  c27_info[20].fileLength = 0U;
  c27_info[20].fileTime1 = 0U;
  c27_info[20].fileTime2 = 0U;
  c27_info[21].context = "";
  c27_info[21].name = "eye";
  c27_info[21].dominantType = "double";
  c27_info[21].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c27_info[21].fileLength = 1765U;
  c27_info[21].fileTime1 = 1219740290U;
  c27_info[21].fileTime2 = 0U;
  c27_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c27_info[22].name = "ischar";
  c27_info[22].dominantType = "double";
  c27_info[22].resolved = "[B]ischar";
  c27_info[22].fileLength = 0U;
  c27_info[22].fileTime1 = 0U;
  c27_info[22].fileTime2 = 0U;
  c27_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c27_info[23].name = "eml_assert_valid_size_arg";
  c27_info[23].dominantType = "double";
  c27_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c27_info[23].fileLength = 3237U;
  c27_info[23].fileTime1 = 1228077624U;
  c27_info[23].fileTime2 = 0U;
  c27_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isVariableSizing";
  c27_info[24].name = "false";
  c27_info[24].dominantType = "";
  c27_info[24].resolved = "[B]false";
  c27_info[24].fileLength = 0U;
  c27_info[24].fileTime1 = 0U;
  c27_info[24].fileTime2 = 0U;
  c27_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c27_info[25].name = "isnumeric";
  c27_info[25].dominantType = "double";
  c27_info[25].resolved = "[B]isnumeric";
  c27_info[25].fileLength = 0U;
  c27_info[25].fileTime1 = 0U;
  c27_info[25].fileTime2 = 0U;
  c27_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c27_info[26].name = "ne";
  c27_info[26].dominantType = "double";
  c27_info[26].resolved = "[B]ne";
  c27_info[26].fileLength = 0U;
  c27_info[26].fileTime1 = 0U;
  c27_info[26].fileTime2 = 0U;
  c27_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c27_info[27].name = "isfinite";
  c27_info[27].dominantType = "double";
  c27_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c27_info[27].fileLength = 364U;
  c27_info[27].fileTime1 = 1226561072U;
  c27_info[27].fileTime2 = 0U;
  c27_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c27_info[28].name = "isinf";
  c27_info[28].dominantType = "double";
  c27_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c27_info[28].fileLength = 506U;
  c27_info[28].fileTime1 = 1228077610U;
  c27_info[28].fileTime2 = 0U;
  c27_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c27_info[29].name = "isnan";
  c27_info[29].dominantType = "double";
  c27_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c27_info[29].fileLength = 506U;
  c27_info[29].fileTime1 = 1228077610U;
  c27_info[29].fileTime2 = 0U;
  c27_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c27_info[30].name = "and";
  c27_info[30].dominantType = "logical";
  c27_info[30].resolved = "[B]and";
  c27_info[30].fileLength = 0U;
  c27_info[30].fileTime1 = 0U;
  c27_info[30].fileTime2 = 0U;
  c27_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c27_info[31].name = "true";
  c27_info[31].dominantType = "";
  c27_info[31].resolved = "[B]true";
  c27_info[31].fileLength = 0U;
  c27_info[31].fileTime1 = 0U;
  c27_info[31].fileTime2 = 0U;
  c27_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c27_info[32].name = "le";
  c27_info[32].dominantType = "double";
  c27_info[32].resolved = "[B]le";
  c27_info[32].fileLength = 0U;
  c27_info[32].fileTime1 = 0U;
  c27_info[32].fileTime2 = 0U;
  c27_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c27_info[33].name = "double";
  c27_info[33].dominantType = "double";
  c27_info[33].resolved = "[B]double";
  c27_info[33].fileLength = 0U;
  c27_info[33].fileTime1 = 0U;
  c27_info[33].fileTime2 = 0U;
  c27_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c27_info[34].name = "eml_index_class";
  c27_info[34].dominantType = "";
  c27_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c27_info[34].fileLength = 909U;
  c27_info[34].fileTime1 = 1192454182U;
  c27_info[34].fileTime2 = 0U;
  c27_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c27_info[35].name = "intmax";
  c27_info[35].dominantType = "char";
  c27_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c27_info[35].fileLength = 1535U;
  c27_info[35].fileTime1 = 1192454128U;
  c27_info[35].fileTime2 = 0U;
  c27_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c27_info[36].name = "int32";
  c27_info[36].dominantType = "double";
  c27_info[36].resolved = "[B]int32";
  c27_info[36].fileLength = 0U;
  c27_info[36].fileTime1 = 0U;
  c27_info[36].fileTime2 = 0U;
  c27_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c27_info[37].name = "eml_is_float_class";
  c27_info[37].dominantType = "char";
  c27_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c27_info[37].fileLength = 226U;
  c27_info[37].fileTime1 = 1197834242U;
  c27_info[37].fileTime2 = 0U;
  c27_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c27_info[38].name = "zeros";
  c27_info[38].dominantType = "double";
  c27_info[38].resolved = "[B]zeros";
  c27_info[38].fileLength = 0U;
  c27_info[38].fileTime1 = 0U;
  c27_info[38].fileTime2 = 0U;
  c27_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c27_info[39].name = "real";
  c27_info[39].dominantType = "double";
  c27_info[39].resolved = "[B]real";
  c27_info[39].fileLength = 0U;
  c27_info[39].fileTime1 = 0U;
  c27_info[39].fileTime2 = 0U;
  c27_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c27_info[40].name = "min";
  c27_info[40].dominantType = "double";
  c27_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c27_info[40].fileLength = 308U;
  c27_info[40].fileTime1 = 1192454034U;
  c27_info[40].fileTime2 = 0U;
  c27_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c27_info[41].name = "nargout";
  c27_info[41].dominantType = "";
  c27_info[41].resolved = "[B]nargout";
  c27_info[41].fileLength = 0U;
  c27_info[41].fileTime1 = 0U;
  c27_info[41].fileTime2 = 0U;
  c27_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c27_info[42].name = "eml_min_or_max";
  c27_info[42].dominantType = "char";
  c27_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c27_info[42].fileLength = 9969U;
  c27_info[42].fileTime1 = 1240249408U;
  c27_info[42].fileTime2 = 0U;
  c27_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c27_info[43].name = "islogical";
  c27_info[43].dominantType = "double";
  c27_info[43].resolved = "[B]islogical";
  c27_info[43].fileLength = 0U;
  c27_info[43].fileTime1 = 0U;
  c27_info[43].fileTime2 = 0U;
  c27_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c27_info[44].name = "eml_scalar_eg";
  c27_info[44].dominantType = "double";
  c27_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c27_info[44].fileLength = 3068U;
  c27_info[44].fileTime1 = 1240249410U;
  c27_info[44].fileTime2 = 0U;
  c27_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c27_info[45].name = "isstruct";
  c27_info[45].dominantType = "double";
  c27_info[45].resolved = "[B]isstruct";
  c27_info[45].fileLength = 0U;
  c27_info[45].fileTime1 = 0U;
  c27_info[45].fileTime2 = 0U;
  c27_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c27_info[46].name = "cast";
  c27_info[46].dominantType = "double";
  c27_info[46].resolved = "[B]cast";
  c27_info[46].fileLength = 0U;
  c27_info[46].fileTime1 = 0U;
  c27_info[46].fileTime2 = 0U;
  c27_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c27_info[47].name = "eml_scalexp_alloc";
  c27_info[47].dominantType = "double";
  c27_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c27_info[47].fileLength = 808U;
  c27_info[47].fileTime1 = 1230478500U;
  c27_info[47].fileTime2 = 0U;
  c27_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c27_info[48].name = "ones";
  c27_info[48].dominantType = "char";
  c27_info[48].resolved = "[B]ones";
  c27_info[48].fileLength = 0U;
  c27_info[48].fileTime1 = 0U;
  c27_info[48].fileTime2 = 0U;
  c27_info[49].context = "";
  c27_info[49].name = "ctranspose";
  c27_info[49].dominantType = "double";
  c27_info[49].resolved = "[B]ctranspose";
  c27_info[49].fileLength = 0U;
  c27_info[49].fileTime1 = 0U;
  c27_info[49].fileTime2 = 0U;
  c27_info[50].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[50].name = "ndims";
  c27_info[50].dominantType = "double";
  c27_info[50].resolved = "[B]ndims";
  c27_info[50].fileLength = 0U;
  c27_info[50].fileTime1 = 0U;
  c27_info[50].fileTime2 = 0U;
  c27_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[51].name = "eml_xgemm";
  c27_info[51].dominantType = "int32";
  c27_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c27_info[51].fileLength = 3184U;
  c27_info[51].fileTime1 = 1209318252U;
  c27_info[51].fileTime2 = 0U;
  c27_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c27_info[52].name = "lt";
  c27_info[52].dominantType = "int32";
  c27_info[52].resolved = "[B]lt";
  c27_info[52].fileLength = 0U;
  c27_info[52].fileTime1 = 0U;
  c27_info[52].fileTime2 = 0U;
  c27_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c27_info[53].name = "length";
  c27_info[53].dominantType = "double";
  c27_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c27_info[53].fileLength = 326U;
  c27_info[53].fileTime1 = 1226561076U;
  c27_info[53].fileTime2 = 0U;
  c27_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c27_info[54].name = "eml_refblas_xgemm";
  c27_info[54].dominantType = "int32";
  c27_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c27_info[54].fileLength = 5748U;
  c27_info[54].fileTime1 = 1228077674U;
  c27_info[54].fileTime2 = 0U;
  c27_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c27_info[55].name = "eml_index_minus";
  c27_info[55].dominantType = "int32";
  c27_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c27_info[55].fileLength = 277U;
  c27_info[55].fileTime1 = 1192454184U;
  c27_info[55].fileTime2 = 0U;
  c27_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c27_info[56].name = "eml_index_times";
  c27_info[56].dominantType = "int32";
  c27_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c27_info[56].fileLength = 280U;
  c27_info[56].fileTime1 = 1192454188U;
  c27_info[56].fileTime2 = 0U;
  c27_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c27_info[57].name = "eml_index_plus";
  c27_info[57].dominantType = "int32";
  c27_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c27_info[57].fileLength = 272U;
  c27_info[57].fileTime1 = 1192454186U;
  c27_info[57].fileTime2 = 0U;
}

static const mxArray *c27_e_sf_marshall(void *c27_chartInstance, void *c27_u)
{
  const mxArray *c27_y = NULL;
  boolean_T c27_b_u;
  const mxArray *c27_b_y = NULL;
  c27_y = NULL;
  c27_b_u = *((boolean_T *)c27_u);
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c27_y, c27_b_y);
  return c27_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c27_adcs_v15_integral_Power_no_charge_in_detumb_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1102337655U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2247902236U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2372611850U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1435446721U);
}

mxArray
  *sf_c27_adcs_v15_integral_Power_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(320683012U);
    pr[1] = (double)(1749748144U);
    pr[2] = (double)(2464601499U);
    pr[3] = (double)(1040742907U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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

static mxArray
  *sf_get_sim_state_info_c27_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"w\",},{M[1],M[12],T\"w_l\",},{M[8],M[0],T\"is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_adcs_v15_integral_Power_no_charge_in_detumb_get_check_sum(&mxChecksum);
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
          (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
           27,
           1,
           1,
           7,
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
            (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w_l",0,(MexFcnForType)c27_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w_k",0,(MexFcnForType)c27_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_BI_l",0,(MexFcnForType)
                                c27_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_BI_k",0,(MexFcnForType)
                                c27_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"w",0,(MexFcnForType)c27_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(5,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_FRAME_SIZE",0,(MexFcnForType)c27_c_sf_marshall);
          _SFD_SET_DATA_PROPS(6,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_TAU_W",0,(MexFcnForType)c27_c_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,443);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c27_w_l)[3];
          real_T (*c27_w_k)[3];
          real_T (*c27_q_BI_l)[4];
          real_T (*c27_q_BI_k)[4];
          real_T (*c27_w)[3];
          c27_w_l = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c27_w_k = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c27_q_BI_l = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 1);
          c27_q_BI_k = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
          c27_w = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c27_w_l);
          _SFD_SET_DATA_VALUE_PTR(1U, c27_w_k);
          _SFD_SET_DATA_VALUE_PTR(2U, c27_q_BI_l);
          _SFD_SET_DATA_VALUE_PTR(3U, c27_q_BI_k);
          _SFD_SET_DATA_VALUE_PTR(4U, c27_w);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance.c27_s_FRAME_SIZE);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c27_s_TAU_W);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c27_adcs_v15_integral_Power_no_charge_in_detumb();
  initialize_c27_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_enable_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c27_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_disable_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  disable_c27_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_gateway_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  sf_c27_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c27_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar)
{
  ext_mode_exec_c27_adcs_v15_integral_Power_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb(sf_mex_dup(st));
}

static void sf_opaque_terminate_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c27_adcs_v15_integral_Power_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c27_adcs_v15_integral_Power_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c27_adcs_v15_integral_Power_no_charge_in_detumb
  (SimStruct *S)
{
  /* Actual parameters from chart:
     s_FRAME_SIZE s_TAU_W
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for s_FRAME_SIZE*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for s_TAU_W*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_no_charge_in_detumb",
                "adcs_v15_integral_Power_no_charge_in_detumb",27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",27,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_no_charge_in_detumb",
        "adcs_v15_integral_Power_no_charge_in_detumb",27,3);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_no_charge_in_detumb",
        "adcs_v15_integral_Power_no_charge_in_detumb",27,2);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_no_charge_in_detumb",
                          "adcs_v15_integral_Power_no_charge_in_detumb",27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(497013U));
  ssSetChecksum1(S,(1167614613U));
  ssSetChecksum2(S,(1901640393U));
  ssSetChecksum3(S,(4177227409U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c27_adcs_v15_integral_Power_no_charge_in_detumb(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",27);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_adcs_v15_integral_Power_no_charge_in_detumb(SimStruct
  *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c27_adcs_v15_integral_Power_no_charge_in_detumb;
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

void c27_adcs_v15_integral_Power_no_charge_in_detumb_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_adcs_v15_integral_Power_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
