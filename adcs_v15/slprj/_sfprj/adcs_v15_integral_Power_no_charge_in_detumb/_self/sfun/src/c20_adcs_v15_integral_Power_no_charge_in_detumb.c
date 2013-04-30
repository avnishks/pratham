/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_no_charge_in_detumb_sfun.h"
#include "c20_adcs_v15_integral_Power_no_charge_in_detumb.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c20_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc20_adcs_v15_integral_Power_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void initialize_params_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void);
static void enable_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void disable_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void c20_update_debugger_state_c20_adcs_v15_integral_Power_no_charge(void);
static void ext_mode_exec_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static const mxArray
  *get_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void set_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(const
  mxArray *c20_st);
static void finalize_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void sf_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void c20_c20_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static real_T c20_mpower(real_T c20_a);
static void c20_eml_scalar_eg(void);
static void c20_b_eml_scalar_eg(void);
static const mxArray *c20_sf_marshall(void *c20_chartInstance, void *c20_u);
static const mxArray *c20_b_sf_marshall(void *c20_chartInstance, void *c20_u);
static const mxArray *c20_c_sf_marshall(void *c20_chartInstance, void *c20_u);
static const mxArray *c20_d_sf_marshall(void *c20_chartInstance, void *c20_u);
static const mxArray *c20_e_sf_marshall(void *c20_chartInstance, void *c20_u);
static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[42]);
static const mxArray *c20_f_sf_marshall(void *c20_chartInstance, void *c20_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  uint8_T *c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb = 0U;
}

static void initialize_params_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void)
{
}

static void enable_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c20_update_debugger_state_c20_adcs_v15_integral_Power_no_charge(void)
{
}

static void ext_mode_exec_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  c20_update_debugger_state_c20_adcs_v15_integral_Power_no_charge();
}

static const mxArray
  *get_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  const mxArray *c20_st = NULL;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  real_T c20_u[3];
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  uint8_T *c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  real_T (*c20_v_B)[3];
  c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c20_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2));
  for (c20_i0 = 0; c20_i0 < 3; c20_i0 = c20_i0 + 1) {
    c20_u[c20_i0] = (*c20_v_B)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_u = *c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y);
  return c20_st;
}

static void set_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(const
  mxArray *c20_st)
{
  const mxArray *c20_u;
  const mxArray *c20_v_B;
  real_T c20_dv0[3];
  int32_T c20_i1;
  real_T c20_y[3];
  int32_T c20_i2;
  const mxArray *c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T c20_u0;
  uint8_T c20_b_y;
  boolean_T *c20_doneDoubleBufferReInit;
  uint8_T *c20_b_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  real_T (*c20_b_v_B)[3];
  c20_b_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c20_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c20_b_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  *c20_doneDoubleBufferReInit = true;
  c20_u = sf_mex_dup(c20_st);
  c20_v_B = sf_mex_dup(sf_mex_getcell(c20_u, 0));
  sf_mex_import("v_B", sf_mex_dup(c20_v_B), &c20_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c20_i1 = 0; c20_i1 < 3; c20_i1 = c20_i1 + 1) {
    c20_y[c20_i1] = c20_dv0[c20_i1];
  }

  sf_mex_destroy(&c20_v_B);
  for (c20_i2 = 0; c20_i2 < 3; c20_i2 = c20_i2 + 1) {
    (*c20_b_v_B)[c20_i2] = c20_y[c20_i2];
  }

  c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb = sf_mex_dup
    (sf_mex_getcell(c20_u, 1));
  sf_mex_import("is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb",
                sf_mex_dup(
    c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb), &c20_u0, 1,
                3, 0U, 0, 0U, 0);
  c20_b_y = c20_u0;
  sf_mex_destroy(&c20_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb);
  *c20_b_is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb = c20_b_y;
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_adcs_v15_integral_Power_no_charge();
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
}

static void sf_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  int32_T c20_i3;
  int32_T c20_i4;
  int32_T c20_i5;
  int32_T c20_previousEvent;
  real_T (*c20_v_B)[3];
  real_T (*c20_x)[7];
  real_T (*c20_v_I)[3];
  c20_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c20_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c20_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,14);
  for (c20_i3 = 0; c20_i3 < 3; c20_i3 = c20_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_v_I)[c20_i3], 0U);
  }

  for (c20_i4 = 0; c20_i4 < 7; c20_i4 = c20_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_x)[c20_i4], 1U);
  }

  for (c20_i5 = 0; c20_i5 < 3; c20_i5 = c20_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_v_B)[c20_i5], 2U);
  }

  c20_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c20_c20_adcs_v15_integral_Power_no_charge_in_detumb();
  _sfEvent_ = c20_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c20_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  int32_T c20_i6;
  real_T c20_v_I[3];
  int32_T c20_i7;
  real_T c20_x[7];
  real_T c20_nargout = 1.0;
  real_T c20_nargin = 2.0;
  real_T c20_TBI[9];
  real_T c20_q3;
  real_T c20_q2;
  real_T c20_q1;
  real_T c20_q0;
  real_T c20_q[4];
  real_T c20_v_B[3];
  int32_T c20_i8;
  real_T c20_b;
  real_T c20_a;
  real_T c20_b_b;
  real_T c20_y;
  real_T c20_c_b;
  real_T c20_b_a;
  real_T c20_d_b;
  real_T c20_b_y;
  real_T c20_e_b;
  real_T c20_c_a;
  real_T c20_f_b;
  real_T c20_c_y;
  real_T c20_g_b;
  real_T c20_d_a;
  real_T c20_h_b;
  real_T c20_d_y;
  real_T c20_i_b;
  real_T c20_e_a;
  real_T c20_j_b;
  real_T c20_e_y;
  real_T c20_k_b;
  real_T c20_f_a;
  real_T c20_l_b;
  real_T c20_f_y;
  real_T c20_m_b;
  real_T c20_g_a;
  real_T c20_n_b;
  real_T c20_g_y;
  real_T c20_o_b;
  real_T c20_h_a;
  real_T c20_p_b;
  real_T c20_h_y;
  real_T c20_q_b;
  real_T c20_i_a;
  real_T c20_r_b;
  real_T c20_i_y;
  real_T c20_s_b;
  real_T c20_j_a;
  real_T c20_t_b;
  real_T c20_j_y;
  real_T c20_u_b;
  real_T c20_k_a;
  real_T c20_v_b;
  real_T c20_k_y;
  real_T c20_w_b;
  real_T c20_l_a;
  real_T c20_x_b;
  real_T c20_l_y;
  real_T c20_d0;
  real_T c20_d1;
  real_T c20_d2;
  int32_T c20_i9;
  real_T c20_m_a[9];
  int32_T c20_i10;
  real_T c20_y_b[3];
  int32_T c20_i11;
  real_T c20_A[9];
  int32_T c20_i12;
  real_T c20_B[3];
  int32_T c20_i13;
  int32_T c20_i14;
  real_T c20_b_A[9];
  int32_T c20_i15;
  real_T c20_b_B[3];
  int32_T c20_i16;
  real_T c20_c_A[9];
  int32_T c20_i17;
  real_T c20_c_B[3];
  int32_T c20_i18;
  int32_T c20_i19;
  int32_T c20_i20;
  int32_T c20_i21;
  real_T (*c20_b_v_B)[3];
  real_T (*c20_b_x)[7];
  real_T (*c20_b_v_I)[3];
  c20_b_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c20_b_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c20_b_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,14);
  for (c20_i6 = 0; c20_i6 < 3; c20_i6 = c20_i6 + 1) {
    c20_v_I[c20_i6] = (*c20_b_v_I)[c20_i6];
  }

  for (c20_i7 = 0; c20_i7 < 7; c20_i7 = c20_i7 + 1) {
    c20_x[c20_i7] = (*c20_b_x)[c20_i7];
  }

  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c20_nargout, c20_d_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c20_nargin, c20_d_sf_marshall);
  sf_debug_symbol_scope_add("TBI", &c20_TBI, c20_e_sf_marshall);
  sf_debug_symbol_scope_add("q3", &c20_q3, c20_d_sf_marshall);
  sf_debug_symbol_scope_add("q2", &c20_q2, c20_d_sf_marshall);
  sf_debug_symbol_scope_add("q1", &c20_q1, c20_d_sf_marshall);
  sf_debug_symbol_scope_add("q0", &c20_q0, c20_d_sf_marshall);
  sf_debug_symbol_scope_add("q", &c20_q, c20_c_sf_marshall);
  sf_debug_symbol_scope_add("v_B", &c20_v_B, c20_sf_marshall);
  sf_debug_symbol_scope_add("x", &c20_x, c20_b_sf_marshall);
  sf_debug_symbol_scope_add("v_I", &c20_v_I, c20_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c20_i8 = 0; c20_i8 < 4; c20_i8 = c20_i8 + 1) {
    c20_q[c20_i8] = c20_x[c20_i8];
  }

  _SFD_EML_CALL(0,7);
  c20_q0 = c20_q[3];
  _SFD_EML_CALL(0,7);
  c20_q1 = c20_q[0];
  _SFD_EML_CALL(0,7);
  c20_q2 = c20_q[1];
  _SFD_EML_CALL(0,7);
  c20_q3 = c20_q[2];
  _SFD_EML_CALL(0,9);
  c20_b = c20_q0;
  c20_a = 2.0 * c20_b;
  c20_b_b = c20_q1;
  c20_y = c20_a * c20_b_b;
  c20_c_b = c20_q2;
  c20_b_a = 2.0 * c20_c_b;
  c20_d_b = c20_q3;
  c20_b_y = c20_b_a * c20_d_b;
  c20_e_b = c20_q1;
  c20_c_a = 2.0 * c20_e_b;
  c20_f_b = c20_q3;
  c20_c_y = c20_c_a * c20_f_b;
  c20_g_b = c20_q0;
  c20_d_a = 2.0 * c20_g_b;
  c20_h_b = c20_q2;
  c20_d_y = c20_d_a * c20_h_b;
  c20_i_b = c20_q2;
  c20_e_a = 2.0 * c20_i_b;
  c20_j_b = c20_q3;
  c20_e_y = c20_e_a * c20_j_b;
  c20_k_b = c20_q0;
  c20_f_a = 2.0 * c20_k_b;
  c20_l_b = c20_q1;
  c20_f_y = c20_f_a * c20_l_b;
  c20_m_b = c20_q0;
  c20_g_a = 2.0 * c20_m_b;
  c20_n_b = c20_q3;
  c20_g_y = c20_g_a * c20_n_b;
  c20_o_b = c20_q1;
  c20_h_a = 2.0 * c20_o_b;
  c20_p_b = c20_q2;
  c20_h_y = c20_h_a * c20_p_b;
  c20_q_b = c20_q0;
  c20_i_a = 2.0 * c20_q_b;
  c20_r_b = c20_q2;
  c20_i_y = c20_i_a * c20_r_b;
  c20_s_b = c20_q1;
  c20_j_a = 2.0 * c20_s_b;
  c20_t_b = c20_q3;
  c20_j_y = c20_j_a * c20_t_b;
  c20_u_b = c20_q1;
  c20_k_a = 2.0 * c20_u_b;
  c20_v_b = c20_q2;
  c20_k_y = c20_k_a * c20_v_b;
  c20_w_b = c20_q0;
  c20_l_a = 2.0 * c20_w_b;
  c20_x_b = c20_q3;
  c20_l_y = c20_l_a * c20_x_b;
  c20_d0 = ((c20_mpower(c20_q0) + c20_mpower(c20_q1)) - c20_mpower(c20_q2)) -
    c20_mpower(c20_q3);
  c20_d1 = ((c20_mpower(c20_q0) - c20_mpower(c20_q1)) + c20_mpower(c20_q2)) -
    c20_mpower(c20_q3);
  c20_d2 = ((c20_mpower(c20_q0) - c20_mpower(c20_q1)) - c20_mpower(c20_q2)) +
    c20_mpower(c20_q3);
  c20_TBI[0] = c20_d0;
  c20_TBI[3] = c20_l_y + c20_k_y;
  c20_TBI[6] = c20_j_y - c20_i_y;
  c20_TBI[1] = c20_h_y - c20_g_y;
  c20_TBI[4] = c20_d1;
  c20_TBI[7] = c20_f_y + c20_e_y;
  c20_TBI[2] = c20_d_y + c20_c_y;
  c20_TBI[5] = c20_b_y - c20_y;
  c20_TBI[8] = c20_d2;
  _SFD_EML_CALL(0,13);
  for (c20_i9 = 0; c20_i9 < 9; c20_i9 = c20_i9 + 1) {
    c20_m_a[c20_i9] = c20_TBI[c20_i9];
  }

  for (c20_i10 = 0; c20_i10 < 3; c20_i10 = c20_i10 + 1) {
    c20_y_b[c20_i10] = c20_v_I[c20_i10];
  }

  c20_b_eml_scalar_eg();
  c20_b_eml_scalar_eg();
  for (c20_i11 = 0; c20_i11 < 9; c20_i11 = c20_i11 + 1) {
    c20_A[c20_i11] = c20_m_a[c20_i11];
  }

  for (c20_i12 = 0; c20_i12 < 3; c20_i12 = c20_i12 + 1) {
    c20_B[c20_i12] = c20_y_b[c20_i12];
  }

  for (c20_i13 = 0; c20_i13 < 3; c20_i13 = c20_i13 + 1) {
    c20_v_B[c20_i13] = 0.0;
  }

  for (c20_i14 = 0; c20_i14 < 9; c20_i14 = c20_i14 + 1) {
    c20_b_A[c20_i14] = c20_A[c20_i14];
  }

  for (c20_i15 = 0; c20_i15 < 3; c20_i15 = c20_i15 + 1) {
    c20_b_B[c20_i15] = c20_B[c20_i15];
  }

  for (c20_i16 = 0; c20_i16 < 9; c20_i16 = c20_i16 + 1) {
    c20_c_A[c20_i16] = c20_b_A[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 3; c20_i17 = c20_i17 + 1) {
    c20_c_B[c20_i17] = c20_b_B[c20_i17];
  }

  for (c20_i18 = 0; c20_i18 < 3; c20_i18 = c20_i18 + 1) {
    c20_v_B[c20_i18] = 0.0;
    c20_i19 = 0;
    for (c20_i20 = 0; c20_i20 < 3; c20_i20 = c20_i20 + 1) {
      c20_v_B[c20_i18] = c20_v_B[c20_i18] + c20_c_A[c20_i19 + c20_i18] *
        c20_c_B[c20_i20];
      c20_i19 = c20_i19 + 3;
    }
  }

  _SFD_EML_CALL(0,-13);
  sf_debug_symbol_scope_pop();
  for (c20_i21 = 0; c20_i21 < 3; c20_i21 = c20_i21 + 1) {
    (*c20_b_v_B)[c20_i21] = c20_v_B[c20_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

static real_T c20_mpower(real_T c20_a)
{
  real_T c20_b_a;
  real_T c20_ak;
  c20_b_a = c20_a;
  c20_eml_scalar_eg();
  c20_ak = c20_b_a;
  return muDoubleScalarPower(c20_ak, 2.0);
}

static void c20_eml_scalar_eg(void)
{
}

static void c20_b_eml_scalar_eg(void)
{
}

static const mxArray *c20_sf_marshall(void *c20_chartInstance, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i22;
  real_T c20_b_u[3];
  const mxArray *c20_b_y = NULL;
  c20_y = NULL;
  for (c20_i22 = 0; c20_i22 < 3; c20_i22 = c20_i22 + 1) {
    c20_b_u[c20_i22] = (*((real_T (*)[3])c20_u))[c20_i22];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_b_sf_marshall(void *c20_chartInstance, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i23;
  real_T c20_b_u[7];
  const mxArray *c20_b_y = NULL;
  c20_y = NULL;
  for (c20_i23 = 0; c20_i23 < 7; c20_i23 = c20_i23 + 1) {
    c20_b_u[c20_i23] = (*((real_T (*)[7])c20_u))[c20_i23];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_c_sf_marshall(void *c20_chartInstance, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i24;
  real_T c20_b_u[4];
  const mxArray *c20_b_y = NULL;
  c20_y = NULL;
  for (c20_i24 = 0; c20_i24 < 4; c20_i24 = c20_i24 + 1) {
    c20_b_u[c20_i24] = (*((real_T (*)[4])c20_u))[c20_i24];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_d_sf_marshall(void *c20_chartInstance, void *c20_u)
{
  const mxArray *c20_y = NULL;
  real_T c20_b_u;
  const mxArray *c20_b_y = NULL;
  c20_y = NULL;
  c20_b_u = *((real_T *)c20_u);
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_e_sf_marshall(void *c20_chartInstance, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i25;
  int32_T c20_i26;
  int32_T c20_i27;
  real_T c20_b_u[9];
  const mxArray *c20_b_y = NULL;
  c20_y = NULL;
  c20_i25 = 0;
  for (c20_i26 = 0; c20_i26 < 3; c20_i26 = c20_i26 + 1) {
    for (c20_i27 = 0; c20_i27 < 3; c20_i27 = c20_i27 + 1) {
      c20_b_u[c20_i27 + c20_i25] = (*((real_T (*)[9])c20_u))[c20_i27 + c20_i25];
    }

    c20_i25 = c20_i25 + 3;
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

const mxArray
  *sf_c20_adcs_v15_integral_Power_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_ResolvedFunctionInfo c20_info[42];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i28;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_info_helper(c20_info);
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 42));
  for (c20_i28 = 0; c20_i28 < 42; c20_i28 = c20_i28 + 1) {
    c20_r0 = &c20_info[c20_i28];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->context)), "context"
                    , "nameCaptureInfo", c20_i28);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->name)), "name",
                    "nameCaptureInfo", c20_i28);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c20_i28);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->resolved)),
                    "resolved", "nameCaptureInfo", c20_i28);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c20_i28);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c20_i28);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c20_i28);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[42])
{
  c20_info[0].context = "";
  c20_info[0].name = "mpower";
  c20_info[0].dominantType = "double";
  c20_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[0].fileLength = 3710U;
  c20_info[0].fileTime1 = 1238421690U;
  c20_info[0].fileTime2 = 0U;
  c20_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[1].name = "nargin";
  c20_info[1].dominantType = "";
  c20_info[1].resolved = "[B]nargin";
  c20_info[1].fileLength = 0U;
  c20_info[1].fileTime1 = 0U;
  c20_info[1].fileTime2 = 0U;
  c20_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[2].name = "gt";
  c20_info[2].dominantType = "double";
  c20_info[2].resolved = "[B]gt";
  c20_info[2].fileLength = 0U;
  c20_info[2].fileTime1 = 0U;
  c20_info[2].fileTime2 = 0U;
  c20_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[3].name = "isa";
  c20_info[3].dominantType = "double";
  c20_info[3].resolved = "[B]isa";
  c20_info[3].fileLength = 0U;
  c20_info[3].fileTime1 = 0U;
  c20_info[3].fileTime2 = 0U;
  c20_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[4].name = "isinteger";
  c20_info[4].dominantType = "double";
  c20_info[4].resolved = "[B]isinteger";
  c20_info[4].fileLength = 0U;
  c20_info[4].fileTime1 = 0U;
  c20_info[4].fileTime2 = 0U;
  c20_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[5].name = "isscalar";
  c20_info[5].dominantType = "double";
  c20_info[5].resolved = "[B]isscalar";
  c20_info[5].fileLength = 0U;
  c20_info[5].fileTime1 = 0U;
  c20_info[5].fileTime2 = 0U;
  c20_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[6].name = "ndims";
  c20_info[6].dominantType = "double";
  c20_info[6].resolved = "[B]ndims";
  c20_info[6].fileLength = 0U;
  c20_info[6].fileTime1 = 0U;
  c20_info[6].fileTime2 = 0U;
  c20_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[7].name = "eq";
  c20_info[7].dominantType = "double";
  c20_info[7].resolved = "[B]eq";
  c20_info[7].fileLength = 0U;
  c20_info[7].fileTime1 = 0U;
  c20_info[7].fileTime2 = 0U;
  c20_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[8].name = "size";
  c20_info[8].dominantType = "double";
  c20_info[8].resolved = "[B]size";
  c20_info[8].fileLength = 0U;
  c20_info[8].fileTime1 = 0U;
  c20_info[8].fileTime2 = 0U;
  c20_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[9].name = "power";
  c20_info[9].dominantType = "double";
  c20_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[9].fileLength = 5380U;
  c20_info[9].fileTime1 = 1228077698U;
  c20_info[9].fileTime2 = 0U;
  c20_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[10].name = "eml_scalar_eg";
  c20_info[10].dominantType = "double";
  c20_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[10].fileLength = 3068U;
  c20_info[10].fileTime1 = 1240249410U;
  c20_info[10].fileTime2 = 0U;
  c20_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c20_info[11].name = "false";
  c20_info[11].dominantType = "";
  c20_info[11].resolved = "[B]false";
  c20_info[11].fileLength = 0U;
  c20_info[11].fileTime1 = 0U;
  c20_info[11].fileTime2 = 0U;
  c20_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[12].name = "isstruct";
  c20_info[12].dominantType = "double";
  c20_info[12].resolved = "[B]isstruct";
  c20_info[12].fileLength = 0U;
  c20_info[12].fileTime1 = 0U;
  c20_info[12].fileTime2 = 0U;
  c20_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c20_info[13].name = "class";
  c20_info[13].dominantType = "double";
  c20_info[13].resolved = "[B]class";
  c20_info[13].fileLength = 0U;
  c20_info[13].fileTime1 = 0U;
  c20_info[13].fileTime2 = 0U;
  c20_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c20_info[14].name = "cast";
  c20_info[14].dominantType = "double";
  c20_info[14].resolved = "[B]cast";
  c20_info[14].fileLength = 0U;
  c20_info[14].fileTime1 = 0U;
  c20_info[14].fileTime2 = 0U;
  c20_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c20_info[15].name = "plus";
  c20_info[15].dominantType = "double";
  c20_info[15].resolved = "[B]plus";
  c20_info[15].fileLength = 0U;
  c20_info[15].fileTime1 = 0U;
  c20_info[15].fileTime2 = 0U;
  c20_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c20_info[16].name = "isreal";
  c20_info[16].dominantType = "double";
  c20_info[16].resolved = "[B]isreal";
  c20_info[16].fileLength = 0U;
  c20_info[16].fileTime1 = 0U;
  c20_info[16].fileTime2 = 0U;
  c20_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[17].name = "eml_scalexp_alloc";
  c20_info[17].dominantType = "double";
  c20_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[17].fileLength = 808U;
  c20_info[17].fileTime1 = 1230478500U;
  c20_info[17].fileTime2 = 0U;
  c20_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[18].name = "minus";
  c20_info[18].dominantType = "double";
  c20_info[18].resolved = "[B]minus";
  c20_info[18].fileLength = 0U;
  c20_info[18].fileTime1 = 0U;
  c20_info[18].fileTime2 = 0U;
  c20_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[19].name = "not";
  c20_info[19].dominantType = "logical";
  c20_info[19].resolved = "[B]not";
  c20_info[19].fileLength = 0U;
  c20_info[19].fileTime1 = 0U;
  c20_info[19].fileTime2 = 0U;
  c20_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[20].name = "lt";
  c20_info[20].dominantType = "double";
  c20_info[20].resolved = "[B]lt";
  c20_info[20].fileLength = 0U;
  c20_info[20].fileTime1 = 0U;
  c20_info[20].fileTime2 = 0U;
  c20_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[21].name = "eml_scalar_floor";
  c20_info[21].dominantType = "double";
  c20_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c20_info[21].fileLength = 260U;
  c20_info[21].fileTime1 = 1209318190U;
  c20_info[21].fileTime2 = 0U;
  c20_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[22].name = "ne";
  c20_info[22].dominantType = "double";
  c20_info[22].resolved = "[B]ne";
  c20_info[22].fileLength = 0U;
  c20_info[22].fileTime1 = 0U;
  c20_info[22].fileTime2 = 0U;
  c20_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[23].name = "eml_error";
  c20_info[23].dominantType = "char";
  c20_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[23].fileLength = 315U;
  c20_info[23].fileTime1 = 1213914146U;
  c20_info[23].fileTime2 = 0U;
  c20_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[24].name = "strcmp";
  c20_info[24].dominantType = "char";
  c20_info[24].resolved = "[B]strcmp";
  c20_info[24].fileLength = 0U;
  c20_info[24].fileTime1 = 0U;
  c20_info[24].fileTime2 = 0U;
  c20_info[25].context = "";
  c20_info[25].name = "mtimes";
  c20_info[25].dominantType = "double";
  c20_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[25].fileLength = 3302U;
  c20_info[25].fileTime1 = 1242738294U;
  c20_info[25].fileTime2 = 0U;
  c20_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[26].name = "le";
  c20_info[26].dominantType = "double";
  c20_info[26].resolved = "[B]le";
  c20_info[26].fileLength = 0U;
  c20_info[26].fileTime1 = 0U;
  c20_info[26].fileTime2 = 0U;
  c20_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[27].name = "eml_index_class";
  c20_info[27].dominantType = "";
  c20_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[27].fileLength = 909U;
  c20_info[27].fileTime1 = 1192454182U;
  c20_info[27].fileTime2 = 0U;
  c20_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[28].name = "ones";
  c20_info[28].dominantType = "char";
  c20_info[28].resolved = "[B]ones";
  c20_info[28].fileLength = 0U;
  c20_info[28].fileTime1 = 0U;
  c20_info[28].fileTime2 = 0U;
  c20_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[29].name = "isempty";
  c20_info[29].dominantType = "double";
  c20_info[29].resolved = "[B]isempty";
  c20_info[29].fileLength = 0U;
  c20_info[29].fileTime1 = 0U;
  c20_info[29].fileTime2 = 0U;
  c20_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[30].name = "eml_xgemm";
  c20_info[30].dominantType = "int32";
  c20_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c20_info[30].fileLength = 3184U;
  c20_info[30].fileTime1 = 1209318252U;
  c20_info[30].fileTime2 = 0U;
  c20_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c20_info[31].name = "length";
  c20_info[31].dominantType = "double";
  c20_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[31].fileLength = 326U;
  c20_info[31].fileTime1 = 1226561076U;
  c20_info[31].fileTime2 = 0U;
  c20_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c20_info[32].name = "min";
  c20_info[32].dominantType = "double";
  c20_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[32].fileLength = 308U;
  c20_info[32].fileTime1 = 1192454034U;
  c20_info[32].fileTime2 = 0U;
  c20_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[33].name = "nargout";
  c20_info[33].dominantType = "";
  c20_info[33].resolved = "[B]nargout";
  c20_info[33].fileLength = 0U;
  c20_info[33].fileTime1 = 0U;
  c20_info[33].fileTime2 = 0U;
  c20_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[34].name = "eml_min_or_max";
  c20_info[34].dominantType = "char";
  c20_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[34].fileLength = 9969U;
  c20_info[34].fileTime1 = 1240249408U;
  c20_info[34].fileTime2 = 0U;
  c20_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[35].name = "ischar";
  c20_info[35].dominantType = "char";
  c20_info[35].resolved = "[B]ischar";
  c20_info[35].fileLength = 0U;
  c20_info[35].fileTime1 = 0U;
  c20_info[35].fileTime2 = 0U;
  c20_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[36].name = "isnumeric";
  c20_info[36].dominantType = "double";
  c20_info[36].resolved = "[B]isnumeric";
  c20_info[36].fileLength = 0U;
  c20_info[36].fileTime1 = 0U;
  c20_info[36].fileTime2 = 0U;
  c20_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c20_info[37].name = "islogical";
  c20_info[37].dominantType = "double";
  c20_info[37].resolved = "[B]islogical";
  c20_info[37].fileLength = 0U;
  c20_info[37].fileTime1 = 0U;
  c20_info[37].fileTime2 = 0U;
  c20_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c20_info[38].name = "eml_refblas_xgemm";
  c20_info[38].dominantType = "int32";
  c20_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[38].fileLength = 5748U;
  c20_info[38].fileTime1 = 1228077674U;
  c20_info[38].fileTime2 = 0U;
  c20_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[39].name = "eml_index_minus";
  c20_info[39].dominantType = "int32";
  c20_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[39].fileLength = 277U;
  c20_info[39].fileTime1 = 1192454184U;
  c20_info[39].fileTime2 = 0U;
  c20_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[40].name = "eml_index_times";
  c20_info[40].dominantType = "int32";
  c20_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[40].fileLength = 280U;
  c20_info[40].fileTime1 = 1192454188U;
  c20_info[40].fileTime2 = 0U;
  c20_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[41].name = "eml_index_plus";
  c20_info[41].dominantType = "int32";
  c20_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[41].fileLength = 272U;
  c20_info[41].fileTime1 = 1192454186U;
  c20_info[41].fileTime2 = 0U;
}

static const mxArray *c20_f_sf_marshall(void *c20_chartInstance, void *c20_u)
{
  const mxArray *c20_y = NULL;
  boolean_T c20_b_u;
  const mxArray *c20_b_y = NULL;
  c20_y = NULL;
  c20_b_u = *((boolean_T *)c20_u);
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c20_adcs_v15_integral_Power_no_charge_in_detumb_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(52922484U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2731999759U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3687537818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3491957224U);
}

mxArray
  *sf_c20_adcs_v15_integral_Power_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2170724032U);
    pr[1] = (double)(2529967911U);
    pr[2] = (double)(1346026062U);
    pr[3] = (double)(2588629971U);
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
      pr[0] = (double)(7);
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

static mxArray
  *sf_get_sim_state_info_c20_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_B\",},{M[8],M[0],T\"is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_adcs_v15_integral_Power_no_charge_in_detumb_get_check_sum(&mxChecksum);
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
           20,
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
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_I",0,(MexFcnForType)c20_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x",0,(MexFcnForType)c20_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_B",0,(MexFcnForType)c20_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,444);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c20_v_I)[3];
          real_T (*c20_x)[7];
          real_T (*c20_v_B)[3];
          c20_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c20_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c20_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c20_v_I);
          _SFD_SET_DATA_VALUE_PTR(1U, c20_x);
          _SFD_SET_DATA_VALUE_PTR(2U, c20_v_B);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c20_adcs_v15_integral_Power_no_charge_in_detumb();
  initialize_c20_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_enable_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c20_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_disable_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  disable_c20_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_gateway_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  sf_c20_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c20_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar)
{
  ext_mode_exec_c20_adcs_v15_integral_Power_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb(sf_mex_dup(st));
}

static void sf_opaque_terminate_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c20_adcs_v15_integral_Power_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_adcs_v15_integral_Power_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c20_adcs_v15_integral_Power_no_charge_in_detumb
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_no_charge_in_detumb",
                "adcs_v15_integral_Power_no_charge_in_detumb",20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",20,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_no_charge_in_detumb",
        "adcs_v15_integral_Power_no_charge_in_detumb",20,2);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_no_charge_in_detumb",
        "adcs_v15_integral_Power_no_charge_in_detumb",20,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_no_charge_in_detumb",
                          "adcs_v15_integral_Power_no_charge_in_detumb",20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1438108338U));
  ssSetChecksum1(S,(2004638737U));
  ssSetChecksum2(S,(2564207442U));
  ssSetChecksum3(S,(1506645853U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c20_adcs_v15_integral_Power_no_charge_in_detumb(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",20);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_adcs_v15_integral_Power_no_charge_in_detumb(SimStruct
  *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c20_adcs_v15_integral_Power_no_charge_in_detumb;
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

void c20_adcs_v15_integral_Power_no_charge_in_detumb_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_adcs_v15_integral_Power_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
