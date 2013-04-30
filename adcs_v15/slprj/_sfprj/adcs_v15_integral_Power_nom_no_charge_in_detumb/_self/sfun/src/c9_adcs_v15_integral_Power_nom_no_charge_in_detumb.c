/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun.h"
#include "c9_adcs_v15_integral_Power_nom_no_charge_in_detumb.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c9_IN_NO_ACTIVE_CHILD          (0)
#define c9_b_mu                        (3.98658366E+014)

/* Variable Declarations */

/* Variable Definitions */
static SFc9_adcs_v15_integral_Power_nom_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void initialize_params_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void);
static void enable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void disable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c9_update_debugger_state_c9_adcs_v15_integral_Power_nom_no_char(void);
static void ext_mode_exec_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void);
static const mxArray
  *get_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void set_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c9_st);
static void finalize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c9_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static real_T c9_mpower(real_T c9_b_a);
static real_T c9_power(real_T c9_b_a, real_T c9_b);
static void c9_eml_scalar_eg(void);
static void c9_eml_error(void);
static void c9_b_eml_scalar_eg(void);
static void c9_c_eml_scalar_eg(void);
static real_T c9_ceval_xdot(int32_T c9_n, real_T c9_x[3], int32_T c9_ix0,
  int32_T c9_incx, real_T c9_y[3], int32_T c9_iy0, int32_T c9_incy);
static void c9_b_eml_error(void);
static void c9_eml_warning(void);
static const mxArray *c9_sf_marshall(void *c9_chartInstance, void *c9_u);
static const mxArray *c9_b_sf_marshall(void *c9_chartInstance, void *c9_u);
static const mxArray *c9_c_sf_marshall(void *c9_chartInstance, void *c9_u);
static const mxArray *c9_d_sf_marshall(void *c9_chartInstance, void *c9_u);
static const mxArray *c9_e_sf_marshall(void *c9_chartInstance, void *c9_u);
static const mxArray *c9_f_sf_marshall(void *c9_chartInstance, void *c9_u);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[63]);
static const mxArray *c9_g_sf_marshall(void *c9_chartInstance, void *c9_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  uint8_T *c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb = 0U;
}

static void initialize_params_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  real_T c9_d0;
  real_T c9_dv0[9];
  int32_T c9_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'mu' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c9_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c9_mu = c9_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'm_INERTIA' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c9_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i0 = 0; c9_i0 < 9; c9_i0 = c9_i0 + 1) {
    chartInstance.c9_m_INERTIA[c9_i0] = c9_dv0[c9_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c9_update_debugger_state_c9_adcs_v15_integral_Power_nom_no_char(void)
{
}

static void ext_mode_exec_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  c9_update_debugger_state_c9_adcs_v15_integral_Power_nom_no_char();
}

static const mxArray
  *get_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  const mxArray *c9_st = NULL;
  const mxArray *c9_y = NULL;
  int32_T c9_i1;
  real_T c9_u[3];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  uint8_T *c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  real_T (*c9_tau)[3];
  c9_tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2));
  for (c9_i1 = 0; c9_i1 < 3; c9_i1 = c9_i1 + 1) {
    c9_u[c9_i1] = (*c9_tau)[c9_i1];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_u = *c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c9_st)
{
  const mxArray *c9_u;
  const mxArray *c9_tau;
  real_T c9_dv1[3];
  int32_T c9_i2;
  real_T c9_y[3];
  int32_T c9_i3;
  const mxArray *c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  uint8_T c9_u0;
  uint8_T c9_b_y;
  boolean_T *c9_doneDoubleBufferReInit;
  uint8_T *c9_b_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detu;
  real_T (*c9_b_tau)[3];
  c9_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c9_b_tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c9_b_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detu = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_tau = sf_mex_dup(sf_mex_getcell(c9_u, 0));
  sf_mex_import("tau", sf_mex_dup(c9_tau), &c9_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c9_i2 = 0; c9_i2 < 3; c9_i2 = c9_i2 + 1) {
    c9_y[c9_i2] = c9_dv1[c9_i2];
  }

  sf_mex_destroy(&c9_tau);
  for (c9_i3 = 0; c9_i3 < 3; c9_i3 = c9_i3 + 1) {
    (*c9_b_tau)[c9_i3] = c9_y[c9_i3];
  }

  c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb = sf_mex_dup
    (sf_mex_getcell(c9_u, 1));
  sf_mex_import("is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb",
                sf_mex_dup(
    c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb), &c9_u0, 1,
                3, 0U, 0, 0U, 0);
  c9_b_y = c9_u0;
  sf_mex_destroy
    (&c9_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb);
  *c9_b_is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detu = c9_b_y;
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_adcs_v15_integral_Power_nom_no_char();
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
}

static void sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_previousEvent;
  real_T (*c9_v_Si)[6];
  real_T (*c9_tau)[3];
  real_T (*c9_x)[7];
  c9_v_Si = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c9_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c9_tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,7);
  for (c9_i4 = 0; c9_i4 < 7; c9_i4 = c9_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_x)[c9_i4], 0U);
  }

  for (c9_i5 = 0; c9_i5 < 3; c9_i5 = c9_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_tau)[c9_i5], 1U);
  }

  for (c9_i6 = 0; c9_i6 < 6; c9_i6 = c9_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_v_Si)[c9_i6], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c9_mu, 3U);
  for (c9_i7 = 0; c9_i7 < 9; c9_i7 = c9_i7 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c9_m_INERTIA[c9_i7], 4U);
  }

  c9_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c9_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  _sfEvent_ = c9_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c9_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  int32_T c9_i8;
  real_T c9_x[7];
  int32_T c9_i9;
  real_T c9_v_Si[6];
  real_T c9_nargout = 1.0;
  real_T c9_nargin = 4.0;
  real_T c9_b_m_INERTIA[9] = { 1.7007470856000001E-001, -1.0654970099999998E-003,
    -8.9766438000000006E-004, -1.0654970099999998E-003,
    0.1715993471, -0.003605829885, -8.9766438000000006E-004, -0.003605829885,
    0.1585857207 };

  real_T c9_c_mu = c9_b_mu;
  real_T c9_R;
  real_T c9_r_B[3];
  real_T c9_r_I[3];
  real_T c9_TBI[9];
  real_T c9_q3;
  real_T c9_q2;
  real_T c9_q1;
  real_T c9_q0;
  real_T c9_q[4];
  real_T c9_tau[3];
  int32_T c9_i10;
  real_T c9_b;
  real_T c9_b_a;
  real_T c9_b_b;
  real_T c9_y;
  real_T c9_c_b;
  real_T c9_c_a;
  real_T c9_d_b;
  real_T c9_b_y;
  real_T c9_e_b;
  real_T c9_d_a;
  real_T c9_f_b;
  real_T c9_c_y;
  real_T c9_g_b;
  real_T c9_e_a;
  real_T c9_h_b;
  real_T c9_d_y;
  real_T c9_i_b;
  real_T c9_f_a;
  real_T c9_j_b;
  real_T c9_e_y;
  real_T c9_k_b;
  real_T c9_g_a;
  real_T c9_l_b;
  real_T c9_f_y;
  real_T c9_m_b;
  real_T c9_h_a;
  real_T c9_n_b;
  real_T c9_g_y;
  real_T c9_o_b;
  real_T c9_i_a;
  real_T c9_p_b;
  real_T c9_h_y;
  real_T c9_q_b;
  real_T c9_j_a;
  real_T c9_r_b;
  real_T c9_i_y;
  real_T c9_s_b;
  real_T c9_k_a;
  real_T c9_t_b;
  real_T c9_j_y;
  real_T c9_u_b;
  real_T c9_l_a;
  real_T c9_v_b;
  real_T c9_k_y;
  real_T c9_w_b;
  real_T c9_m_a;
  real_T c9_x_b;
  real_T c9_l_y;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  int32_T c9_i11;
  int32_T c9_i12;
  real_T c9_n_a[9];
  int32_T c9_i13;
  real_T c9_y_b[3];
  int32_T c9_i14;
  real_T c9_A[9];
  int32_T c9_i15;
  real_T c9_B[3];
  int32_T c9_i16;
  int32_T c9_i17;
  real_T c9_b_A[9];
  int32_T c9_i18;
  real_T c9_b_B[3];
  int32_T c9_i19;
  real_T c9_c_A[9];
  int32_T c9_i20;
  real_T c9_c_B[3];
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  real_T c9_o_a[3];
  int32_T c9_i25;
  real_T c9_ab_b[3];
  int32_T c9_i26;
  real_T c9_p_a[3];
  int32_T c9_i27;
  real_T c9_bb_b[3];
  int32_T c9_i28;
  real_T c9_b_x[3];
  int32_T c9_i29;
  real_T c9_m_y[3];
  int32_T c9_i30;
  real_T c9_c_x[3];
  int32_T c9_i31;
  real_T c9_n_y[3];
  int32_T c9_i32;
  real_T c9_d_x[3];
  int32_T c9_i33;
  real_T c9_o_y[3];
  int32_T c9_i34;
  real_T c9_e_x[3];
  int32_T c9_i35;
  real_T c9_p_y[3];
  real_T c9_f_x;
  real_T c9_g_x;
  int32_T c9_i36;
  real_T c9_q_a[3];
  int32_T c9_i37;
  real_T c9_cb_b[3];
  int32_T c9_i38;
  real_T c9_d_B[3];
  int32_T c9_i39;
  real_T c9_e_B[3];
  int32_T c9_i40;
  real_T c9_f_B[3];
  int32_T c9_i41;
  real_T c9_db_b[3];
  int32_T c9_i42;
  int32_T c9_i43;
  static real_T c9_dv2[9] = { 1.7007470856000001E-001, -1.0654970099999998E-003,
    -8.9766438000000006E-004, -1.0654970099999998E-003,
    0.1715993471, -0.003605829885, -8.9766438000000006E-004, -0.003605829885,
    0.1585857207 };

  real_T c9_r_a;
  real_T c9_eb_b;
  real_T c9_q_y;
  real_T c9_s_a;
  real_T c9_fb_b;
  real_T c9_r_y;
  real_T c9_c1;
  real_T c9_t_a;
  real_T c9_gb_b;
  real_T c9_s_y;
  real_T c9_u_a;
  real_T c9_hb_b;
  real_T c9_t_y;
  real_T c9_c2;
  real_T c9_v_a;
  real_T c9_ib_b;
  real_T c9_u_y;
  real_T c9_w_a;
  real_T c9_jb_b;
  real_T c9_v_y;
  real_T c9_c3;
  real_T c9_kb_b[3];
  int32_T c9_i44;
  real_T c9_d_A[3];
  real_T c9_x_a;
  real_T c9_g_B;
  int32_T c9_i45;
  real_T c9_h_x[3];
  real_T c9_w_y;
  int32_T c9_i46;
  real_T c9_i_x[3];
  real_T c9_x_y;
  int32_T c9_i47;
  real_T c9_j_x[3];
  real_T c9_y_y;
  int32_T c9_i48;
  int32_T c9_i49;
  real_T (*c9_b_tau)[3];
  real_T (*c9_b_v_Si)[6];
  real_T (*c9_k_x)[7];
  c9_b_v_Si = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c9_k_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c9_b_tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,7);
  for (c9_i8 = 0; c9_i8 < 7; c9_i8 = c9_i8 + 1) {
    c9_x[c9_i8] = (*c9_k_x)[c9_i8];
  }

  for (c9_i9 = 0; c9_i9 < 6; c9_i9 = c9_i9 + 1) {
    c9_v_Si[c9_i9] = (*c9_b_v_Si)[c9_i9];
  }

  sf_debug_symbol_scope_push(16U, 0U);
  sf_debug_symbol_scope_add("nargout", &c9_nargout, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c9_nargin, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("m_INERTIA", &c9_b_m_INERTIA, c9_f_sf_marshall);
  sf_debug_symbol_scope_add("mu", &c9_c_mu, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("R", &c9_R, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("r_B", &c9_r_B, c9_c_sf_marshall);
  sf_debug_symbol_scope_add("r_I", &c9_r_I, c9_c_sf_marshall);
  sf_debug_symbol_scope_add("TBI", &c9_TBI, c9_f_sf_marshall);
  sf_debug_symbol_scope_add("q3", &c9_q3, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("q2", &c9_q2, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("q1", &c9_q1, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("q0", &c9_q0, c9_e_sf_marshall);
  sf_debug_symbol_scope_add("q", &c9_q, c9_d_sf_marshall);
  sf_debug_symbol_scope_add("tau", &c9_tau, c9_c_sf_marshall);
  sf_debug_symbol_scope_add("v_Si", &c9_v_Si, c9_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c9_x, c9_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c9_i10 = 0; c9_i10 < 4; c9_i10 = c9_i10 + 1) {
    c9_q[c9_i10] = c9_x[c9_i10];
  }

  _SFD_EML_CALL(0,7);
  c9_q0 = c9_q[3];
  _SFD_EML_CALL(0,7);
  c9_q1 = c9_q[0];
  _SFD_EML_CALL(0,7);
  c9_q2 = c9_q[1];
  _SFD_EML_CALL(0,7);
  c9_q3 = c9_q[2];
  _SFD_EML_CALL(0,9);
  c9_b = c9_q0;
  c9_b_a = 2.0 * c9_b;
  c9_b_b = c9_q1;
  c9_y = c9_b_a * c9_b_b;
  c9_c_b = c9_q2;
  c9_c_a = 2.0 * c9_c_b;
  c9_d_b = c9_q3;
  c9_b_y = c9_c_a * c9_d_b;
  c9_e_b = c9_q1;
  c9_d_a = 2.0 * c9_e_b;
  c9_f_b = c9_q3;
  c9_c_y = c9_d_a * c9_f_b;
  c9_g_b = c9_q0;
  c9_e_a = 2.0 * c9_g_b;
  c9_h_b = c9_q2;
  c9_d_y = c9_e_a * c9_h_b;
  c9_i_b = c9_q2;
  c9_f_a = 2.0 * c9_i_b;
  c9_j_b = c9_q3;
  c9_e_y = c9_f_a * c9_j_b;
  c9_k_b = c9_q0;
  c9_g_a = 2.0 * c9_k_b;
  c9_l_b = c9_q1;
  c9_f_y = c9_g_a * c9_l_b;
  c9_m_b = c9_q0;
  c9_h_a = 2.0 * c9_m_b;
  c9_n_b = c9_q3;
  c9_g_y = c9_h_a * c9_n_b;
  c9_o_b = c9_q1;
  c9_i_a = 2.0 * c9_o_b;
  c9_p_b = c9_q2;
  c9_h_y = c9_i_a * c9_p_b;
  c9_q_b = c9_q0;
  c9_j_a = 2.0 * c9_q_b;
  c9_r_b = c9_q2;
  c9_i_y = c9_j_a * c9_r_b;
  c9_s_b = c9_q1;
  c9_k_a = 2.0 * c9_s_b;
  c9_t_b = c9_q3;
  c9_j_y = c9_k_a * c9_t_b;
  c9_u_b = c9_q1;
  c9_l_a = 2.0 * c9_u_b;
  c9_v_b = c9_q2;
  c9_k_y = c9_l_a * c9_v_b;
  c9_w_b = c9_q0;
  c9_m_a = 2.0 * c9_w_b;
  c9_x_b = c9_q3;
  c9_l_y = c9_m_a * c9_x_b;
  c9_d1 = ((c9_mpower(c9_q0) + c9_mpower(c9_q1)) - c9_mpower(c9_q2)) - c9_mpower
    (c9_q3);
  c9_d2 = ((c9_mpower(c9_q0) - c9_mpower(c9_q1)) + c9_mpower(c9_q2)) - c9_mpower
    (c9_q3);
  c9_d3 = ((c9_mpower(c9_q0) - c9_mpower(c9_q1)) - c9_mpower(c9_q2)) + c9_mpower
    (c9_q3);
  c9_TBI[0] = c9_d1;
  c9_TBI[3] = c9_l_y + c9_k_y;
  c9_TBI[6] = c9_j_y - c9_i_y;
  c9_TBI[1] = c9_h_y - c9_g_y;
  c9_TBI[4] = c9_d2;
  c9_TBI[7] = c9_f_y + c9_e_y;
  c9_TBI[2] = c9_d_y + c9_c_y;
  c9_TBI[5] = c9_b_y - c9_y;
  c9_TBI[8] = c9_d3;
  _SFD_EML_CALL(0,13);
  for (c9_i11 = 0; c9_i11 < 3; c9_i11 = c9_i11 + 1) {
    c9_r_I[c9_i11] = c9_v_Si[c9_i11];
  }

  _SFD_EML_CALL(0,14);
  for (c9_i12 = 0; c9_i12 < 9; c9_i12 = c9_i12 + 1) {
    c9_n_a[c9_i12] = c9_TBI[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 3; c9_i13 = c9_i13 + 1) {
    c9_y_b[c9_i13] = c9_r_I[c9_i13];
  }

  c9_b_eml_scalar_eg();
  c9_b_eml_scalar_eg();
  for (c9_i14 = 0; c9_i14 < 9; c9_i14 = c9_i14 + 1) {
    c9_A[c9_i14] = c9_n_a[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 3; c9_i15 = c9_i15 + 1) {
    c9_B[c9_i15] = c9_y_b[c9_i15];
  }

  for (c9_i16 = 0; c9_i16 < 3; c9_i16 = c9_i16 + 1) {
    c9_r_B[c9_i16] = 0.0;
  }

  for (c9_i17 = 0; c9_i17 < 9; c9_i17 = c9_i17 + 1) {
    c9_b_A[c9_i17] = c9_A[c9_i17];
  }

  for (c9_i18 = 0; c9_i18 < 3; c9_i18 = c9_i18 + 1) {
    c9_b_B[c9_i18] = c9_B[c9_i18];
  }

  for (c9_i19 = 0; c9_i19 < 9; c9_i19 = c9_i19 + 1) {
    c9_c_A[c9_i19] = c9_b_A[c9_i19];
  }

  for (c9_i20 = 0; c9_i20 < 3; c9_i20 = c9_i20 + 1) {
    c9_c_B[c9_i20] = c9_b_B[c9_i20];
  }

  for (c9_i21 = 0; c9_i21 < 3; c9_i21 = c9_i21 + 1) {
    c9_r_B[c9_i21] = 0.0;
    c9_i22 = 0;
    for (c9_i23 = 0; c9_i23 < 3; c9_i23 = c9_i23 + 1) {
      c9_r_B[c9_i21] = c9_r_B[c9_i21] + c9_c_A[c9_i22 + c9_i21] * c9_c_B[c9_i23];
      c9_i22 = c9_i22 + 3;
    }
  }

  _SFD_EML_CALL(0,16);
  for (c9_i24 = 0; c9_i24 < 3; c9_i24 = c9_i24 + 1) {
    c9_o_a[c9_i24] = c9_r_B[c9_i24];
  }

  for (c9_i25 = 0; c9_i25 < 3; c9_i25 = c9_i25 + 1) {
    c9_ab_b[c9_i25] = c9_r_B[c9_i25];
  }

  c9_c_eml_scalar_eg();
  for (c9_i26 = 0; c9_i26 < 3; c9_i26 = c9_i26 + 1) {
    c9_p_a[c9_i26] = c9_o_a[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 3; c9_i27 = c9_i27 + 1) {
    c9_bb_b[c9_i27] = c9_ab_b[c9_i27];
  }

  for (c9_i28 = 0; c9_i28 < 3; c9_i28 = c9_i28 + 1) {
    c9_b_x[c9_i28] = c9_p_a[c9_i28];
  }

  for (c9_i29 = 0; c9_i29 < 3; c9_i29 = c9_i29 + 1) {
    c9_m_y[c9_i29] = c9_bb_b[c9_i29];
  }

  for (c9_i30 = 0; c9_i30 < 3; c9_i30 = c9_i30 + 1) {
    c9_c_x[c9_i30] = c9_b_x[c9_i30];
  }

  for (c9_i31 = 0; c9_i31 < 3; c9_i31 = c9_i31 + 1) {
    c9_n_y[c9_i31] = c9_m_y[c9_i31];
  }

  for (c9_i32 = 0; c9_i32 < 3; c9_i32 = c9_i32 + 1) {
    c9_d_x[c9_i32] = c9_c_x[c9_i32];
  }

  for (c9_i33 = 0; c9_i33 < 3; c9_i33 = c9_i33 + 1) {
    c9_o_y[c9_i33] = c9_n_y[c9_i33];
  }

  for (c9_i34 = 0; c9_i34 < 3; c9_i34 = c9_i34 + 1) {
    c9_e_x[c9_i34] = c9_d_x[c9_i34];
  }

  for (c9_i35 = 0; c9_i35 < 3; c9_i35 = c9_i35 + 1) {
    c9_p_y[c9_i35] = c9_o_y[c9_i35];
  }

  c9_f_x = c9_ceval_xdot(3, c9_e_x, 1, 1, c9_p_y, 1, 1);
  c9_R = c9_f_x;
  if (c9_R < 0.0) {
    c9_b_eml_error();
  }

  c9_g_x = c9_R;
  c9_R = c9_g_x;
  c9_R = muDoubleScalarSqrt(c9_R);
  _SFD_EML_CALL(0,17);
  for (c9_i36 = 0; c9_i36 < 3; c9_i36 = c9_i36 + 1) {
    c9_q_a[c9_i36] = c9_r_B[c9_i36];
  }

  for (c9_i37 = 0; c9_i37 < 3; c9_i37 = c9_i37 + 1) {
    c9_cb_b[c9_i37] = c9_r_B[c9_i37];
  }

  c9_b_eml_scalar_eg();
  c9_b_eml_scalar_eg();
  for (c9_i38 = 0; c9_i38 < 3; c9_i38 = c9_i38 + 1) {
    c9_d_B[c9_i38] = c9_cb_b[c9_i38];
  }

  for (c9_i39 = 0; c9_i39 < 3; c9_i39 = c9_i39 + 1) {
    c9_e_B[c9_i39] = c9_d_B[c9_i39];
  }

  for (c9_i40 = 0; c9_i40 < 3; c9_i40 = c9_i40 + 1) {
    c9_f_B[c9_i40] = c9_e_B[c9_i40];
  }

  for (c9_i41 = 0; c9_i41 < 3; c9_i41 = c9_i41 + 1) {
    c9_db_b[c9_i41] = 0.0;
    c9_i42 = 0;
    for (c9_i43 = 0; c9_i43 < 3; c9_i43 = c9_i43 + 1) {
      c9_db_b[c9_i41] = c9_db_b[c9_i41] + c9_dv2[c9_i42 + c9_i41] *
        c9_f_B[c9_i43];
      c9_i42 = c9_i42 + 3;
    }
  }

  c9_r_a = c9_q_a[2];
  c9_eb_b = c9_db_b[1];
  c9_q_y = c9_r_a * c9_eb_b;
  c9_s_a = c9_q_a[1];
  c9_fb_b = c9_db_b[2];
  c9_r_y = c9_s_a * c9_fb_b;
  c9_c1 = c9_r_y - c9_q_y;
  c9_t_a = c9_q_a[0];
  c9_gb_b = c9_db_b[2];
  c9_s_y = c9_t_a * c9_gb_b;
  c9_u_a = c9_q_a[2];
  c9_hb_b = c9_db_b[0];
  c9_t_y = c9_u_a * c9_hb_b;
  c9_c2 = c9_t_y - c9_s_y;
  c9_v_a = c9_q_a[1];
  c9_ib_b = c9_db_b[0];
  c9_u_y = c9_v_a * c9_ib_b;
  c9_w_a = c9_q_a[0];
  c9_jb_b = c9_db_b[1];
  c9_v_y = c9_w_a * c9_jb_b;
  c9_c3 = c9_v_y - c9_u_y;
  c9_kb_b[0] = c9_c1;
  c9_kb_b[1] = c9_c2;
  c9_kb_b[2] = c9_c3;
  for (c9_i44 = 0; c9_i44 < 3; c9_i44 = c9_i44 + 1) {
    c9_d_A[c9_i44] = 1.195975098E+015 * c9_kb_b[c9_i44];
  }

  c9_x_a = c9_R;
  c9_g_B = c9_power(c9_x_a, 5.0);
  for (c9_i45 = 0; c9_i45 < 3; c9_i45 = c9_i45 + 1) {
    c9_h_x[c9_i45] = c9_d_A[c9_i45];
  }

  c9_w_y = c9_g_B;
  if (c9_w_y == 0.0) {
    c9_eml_warning();
  }

  for (c9_i46 = 0; c9_i46 < 3; c9_i46 = c9_i46 + 1) {
    c9_i_x[c9_i46] = c9_h_x[c9_i46];
  }

  c9_x_y = c9_w_y;
  for (c9_i47 = 0; c9_i47 < 3; c9_i47 = c9_i47 + 1) {
    c9_j_x[c9_i47] = c9_i_x[c9_i47];
  }

  c9_y_y = c9_x_y;
  for (c9_i48 = 0; c9_i48 < 3; c9_i48 = c9_i48 + 1) {
    c9_tau[c9_i48] = c9_j_x[c9_i48] / c9_y_y;
  }

  _SFD_EML_CALL(0,-17);
  sf_debug_symbol_scope_pop();
  for (c9_i49 = 0; c9_i49 < 3; c9_i49 = c9_i49 + 1) {
    (*c9_b_tau)[c9_i49] = c9_tau[c9_i49];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static real_T c9_mpower(real_T c9_b_a)
{
  return c9_power(c9_b_a, 2.0);
}

static real_T c9_power(real_T c9_b_a, real_T c9_b)
{
  real_T c9_ak;
  real_T c9_bk;
  real_T c9_x;
  real_T c9_b_x;
  c9_eml_scalar_eg();
  c9_ak = c9_b_a;
  c9_bk = c9_b;
  if (c9_ak < 0.0) {
    c9_x = c9_bk;
    c9_b_x = c9_x;
    c9_b_x = muDoubleScalarFloor(c9_b_x);
    if (c9_b_x != c9_bk) {
      c9_eml_error();
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c9_ak, c9_bk);
}

static void c9_eml_scalar_eg(void)
{
}

static void c9_eml_error(void)
{
  int32_T c9_i50;
  static char_T c9_cv0[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
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

  char_T c9_u[102];
  const mxArray *c9_y = NULL;
  int32_T c9_i51;
  static char_T c9_cv1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c9_b_u[32];
  const mxArray *c9_b_y = NULL;
  for (c9_i50 = 0; c9_i50 < 102; c9_i50 = c9_i50 + 1) {
    c9_u[c9_i50] = c9_cv0[c9_i50];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c9_i51 = 0; c9_i51 < 32; c9_i51 = c9_i51 + 1) {
    c9_b_u[c9_i51] = c9_cv1[c9_i51];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c9_b_y, 14, c9_y);
}

static void c9_b_eml_scalar_eg(void)
{
}

static void c9_c_eml_scalar_eg(void)
{
}

static real_T c9_ceval_xdot(int32_T c9_n, real_T c9_x[3], int32_T c9_ix0,
  int32_T c9_incx, real_T c9_y[3], int32_T c9_iy0, int32_T
  c9_incy)
{
  real_T c9_d;
  c9_d = 0.0;
  if ((real_T)c9_n > 0.0) {
    return ddot32(&c9_n, &c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c9_ix0), 1, 3, 1, 0) - 1], &
                  c9_incx, &c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c9_iy0), 1, 3, 1, 0) - 1], &c9_incy);
  }

  return c9_d;
}

static void c9_b_eml_error(void)
{
  int32_T c9_i52;
  static char_T c9_cv2[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c9_u[77];
  const mxArray *c9_y = NULL;
  int32_T c9_i53;
  static char_T c9_cv3[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c9_b_u[31];
  const mxArray *c9_b_y = NULL;
  for (c9_i52 = 0; c9_i52 < 77; c9_i52 = c9_i52 + 1) {
    c9_u[c9_i52] = c9_cv2[c9_i52];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c9_i53 = 0; c9_i53 < 31; c9_i53 = c9_i53 + 1) {
    c9_b_u[c9_i53] = c9_cv3[c9_i53];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c9_b_y, 14, c9_y);
}

static void c9_eml_warning(void)
{
  int32_T c9_i54;
  static char_T c9_cv4[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c9_u[15];
  const mxArray *c9_y = NULL;
  int32_T c9_i55;
  static char_T c9_cv5[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c9_b_u[19];
  const mxArray *c9_b_y = NULL;
  for (c9_i54 = 0; c9_i54 < 15; c9_i54 = c9_i54 + 1) {
    c9_u[c9_i54] = c9_cv4[c9_i54];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c9_i55 = 0; c9_i55 < 19; c9_i55 = c9_i55 + 1) {
    c9_b_u[c9_i55] = c9_cv5[c9_i55];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c9_b_y, 14, c9_y);
}

static const mxArray *c9_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i56;
  real_T c9_b_u[7];
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  for (c9_i56 = 0; c9_i56 < 7; c9_i56 = c9_i56 + 1) {
    c9_b_u[c9_i56] = (*((real_T (*)[7])c9_u))[c9_i56];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_b_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i57;
  real_T c9_b_u[6];
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  for (c9_i57 = 0; c9_i57 < 6; c9_i57 = c9_i57 + 1) {
    c9_b_u[c9_i57] = (*((real_T (*)[6])c9_u))[c9_i57];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_c_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i58;
  real_T c9_b_u[3];
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  for (c9_i58 = 0; c9_i58 < 3; c9_i58 = c9_i58 + 1) {
    c9_b_u[c9_i58] = (*((real_T (*)[3])c9_u))[c9_i58];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_d_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i59;
  real_T c9_b_u[4];
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  for (c9_i59 = 0; c9_i59 < 4; c9_i59 = c9_i59 + 1) {
    c9_b_u[c9_i59] = (*((real_T (*)[4])c9_u))[c9_i59];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_e_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  c9_b_u = *((real_T *)c9_u);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_f_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i60;
  int32_T c9_i61;
  int32_T c9_i62;
  real_T c9_b_u[9];
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  c9_i60 = 0;
  for (c9_i61 = 0; c9_i61 < 3; c9_i61 = c9_i61 + 1) {
    for (c9_i62 = 0; c9_i62 < 3; c9_i62 = c9_i62 + 1) {
      c9_b_u[c9_i62 + c9_i60] = (*((real_T (*)[9])c9_u))[c9_i62 + c9_i60];
    }

    c9_i60 = c9_i60 + 3;
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

const mxArray
  *sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_ResolvedFunctionInfo c9_info[63];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i63;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 63));
  for (c9_i63 = 0; c9_i63 < 63; c9_i63 = c9_i63 + 1) {
    c9_r0 = &c9_info[c9_i63];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context",
                    "nameCaptureInfo", c9_i63);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name",
                    "nameCaptureInfo", c9_i63);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c9_i63);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c9_i63);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c9_i63);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c9_i63
                    );
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c9_i63
                    );
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[63])
{
  c9_info[0].context = "";
  c9_info[0].name = "mpower";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[0].fileLength = 3710U;
  c9_info[0].fileTime1 = 1238421690U;
  c9_info[0].fileTime2 = 0U;
  c9_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[1].name = "nargin";
  c9_info[1].dominantType = "";
  c9_info[1].resolved = "[B]nargin";
  c9_info[1].fileLength = 0U;
  c9_info[1].fileTime1 = 0U;
  c9_info[1].fileTime2 = 0U;
  c9_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[2].name = "gt";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[B]gt";
  c9_info[2].fileLength = 0U;
  c9_info[2].fileTime1 = 0U;
  c9_info[2].fileTime2 = 0U;
  c9_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[3].name = "isa";
  c9_info[3].dominantType = "double";
  c9_info[3].resolved = "[B]isa";
  c9_info[3].fileLength = 0U;
  c9_info[3].fileTime1 = 0U;
  c9_info[3].fileTime2 = 0U;
  c9_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[4].name = "isinteger";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved = "[B]isinteger";
  c9_info[4].fileLength = 0U;
  c9_info[4].fileTime1 = 0U;
  c9_info[4].fileTime2 = 0U;
  c9_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[5].name = "isscalar";
  c9_info[5].dominantType = "double";
  c9_info[5].resolved = "[B]isscalar";
  c9_info[5].fileLength = 0U;
  c9_info[5].fileTime1 = 0U;
  c9_info[5].fileTime2 = 0U;
  c9_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[6].name = "ndims";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved = "[B]ndims";
  c9_info[6].fileLength = 0U;
  c9_info[6].fileTime1 = 0U;
  c9_info[6].fileTime2 = 0U;
  c9_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[7].name = "eq";
  c9_info[7].dominantType = "double";
  c9_info[7].resolved = "[B]eq";
  c9_info[7].fileLength = 0U;
  c9_info[7].fileTime1 = 0U;
  c9_info[7].fileTime2 = 0U;
  c9_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[8].name = "size";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved = "[B]size";
  c9_info[8].fileLength = 0U;
  c9_info[8].fileTime1 = 0U;
  c9_info[8].fileTime2 = 0U;
  c9_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[9].name = "power";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[9].fileLength = 5380U;
  c9_info[9].fileTime1 = 1228077698U;
  c9_info[9].fileTime2 = 0U;
  c9_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[10].name = "eml_scalar_eg";
  c9_info[10].dominantType = "double";
  c9_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[10].fileLength = 3068U;
  c9_info[10].fileTime1 = 1240249410U;
  c9_info[10].fileTime2 = 0U;
  c9_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c9_info[11].name = "false";
  c9_info[11].dominantType = "";
  c9_info[11].resolved = "[B]false";
  c9_info[11].fileLength = 0U;
  c9_info[11].fileTime1 = 0U;
  c9_info[11].fileTime2 = 0U;
  c9_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[12].name = "isstruct";
  c9_info[12].dominantType = "double";
  c9_info[12].resolved = "[B]isstruct";
  c9_info[12].fileLength = 0U;
  c9_info[12].fileTime1 = 0U;
  c9_info[12].fileTime2 = 0U;
  c9_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[13].name = "class";
  c9_info[13].dominantType = "double";
  c9_info[13].resolved = "[B]class";
  c9_info[13].fileLength = 0U;
  c9_info[13].fileTime1 = 0U;
  c9_info[13].fileTime2 = 0U;
  c9_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[14].name = "cast";
  c9_info[14].dominantType = "double";
  c9_info[14].resolved = "[B]cast";
  c9_info[14].fileLength = 0U;
  c9_info[14].fileTime1 = 0U;
  c9_info[14].fileTime2 = 0U;
  c9_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[15].name = "plus";
  c9_info[15].dominantType = "double";
  c9_info[15].resolved = "[B]plus";
  c9_info[15].fileLength = 0U;
  c9_info[15].fileTime1 = 0U;
  c9_info[15].fileTime2 = 0U;
  c9_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c9_info[16].name = "isreal";
  c9_info[16].dominantType = "double";
  c9_info[16].resolved = "[B]isreal";
  c9_info[16].fileLength = 0U;
  c9_info[16].fileTime1 = 0U;
  c9_info[16].fileTime2 = 0U;
  c9_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[17].name = "eml_scalexp_alloc";
  c9_info[17].dominantType = "double";
  c9_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[17].fileLength = 808U;
  c9_info[17].fileTime1 = 1230478500U;
  c9_info[17].fileTime2 = 0U;
  c9_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[18].name = "minus";
  c9_info[18].dominantType = "double";
  c9_info[18].resolved = "[B]minus";
  c9_info[18].fileLength = 0U;
  c9_info[18].fileTime1 = 0U;
  c9_info[18].fileTime2 = 0U;
  c9_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[19].name = "not";
  c9_info[19].dominantType = "logical";
  c9_info[19].resolved = "[B]not";
  c9_info[19].fileLength = 0U;
  c9_info[19].fileTime1 = 0U;
  c9_info[19].fileTime2 = 0U;
  c9_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[20].name = "lt";
  c9_info[20].dominantType = "double";
  c9_info[20].resolved = "[B]lt";
  c9_info[20].fileLength = 0U;
  c9_info[20].fileTime1 = 0U;
  c9_info[20].fileTime2 = 0U;
  c9_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[21].name = "eml_scalar_floor";
  c9_info[21].dominantType = "double";
  c9_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c9_info[21].fileLength = 260U;
  c9_info[21].fileTime1 = 1209318190U;
  c9_info[21].fileTime2 = 0U;
  c9_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[22].name = "ne";
  c9_info[22].dominantType = "double";
  c9_info[22].resolved = "[B]ne";
  c9_info[22].fileLength = 0U;
  c9_info[22].fileTime1 = 0U;
  c9_info[22].fileTime2 = 0U;
  c9_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[23].name = "eml_error";
  c9_info[23].dominantType = "char";
  c9_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c9_info[23].fileLength = 315U;
  c9_info[23].fileTime1 = 1213914146U;
  c9_info[23].fileTime2 = 0U;
  c9_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c9_info[24].name = "strcmp";
  c9_info[24].dominantType = "char";
  c9_info[24].resolved = "[B]strcmp";
  c9_info[24].fileLength = 0U;
  c9_info[24].fileTime1 = 0U;
  c9_info[24].fileTime2 = 0U;
  c9_info[25].context = "";
  c9_info[25].name = "mtimes";
  c9_info[25].dominantType = "double";
  c9_info[25].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[25].fileLength = 3302U;
  c9_info[25].fileTime1 = 1242738294U;
  c9_info[25].fileTime2 = 0U;
  c9_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[26].name = "le";
  c9_info[26].dominantType = "double";
  c9_info[26].resolved = "[B]le";
  c9_info[26].fileLength = 0U;
  c9_info[26].fileTime1 = 0U;
  c9_info[26].fileTime2 = 0U;
  c9_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[27].name = "eml_index_class";
  c9_info[27].dominantType = "";
  c9_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[27].fileLength = 909U;
  c9_info[27].fileTime1 = 1192454182U;
  c9_info[27].fileTime2 = 0U;
  c9_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[28].name = "ones";
  c9_info[28].dominantType = "char";
  c9_info[28].resolved = "[B]ones";
  c9_info[28].fileLength = 0U;
  c9_info[28].fileTime1 = 0U;
  c9_info[28].fileTime2 = 0U;
  c9_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[29].name = "isempty";
  c9_info[29].dominantType = "double";
  c9_info[29].resolved = "[B]isempty";
  c9_info[29].fileLength = 0U;
  c9_info[29].fileTime1 = 0U;
  c9_info[29].fileTime2 = 0U;
  c9_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[30].name = "eml_xgemm";
  c9_info[30].dominantType = "int32";
  c9_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[30].fileLength = 3184U;
  c9_info[30].fileTime1 = 1209318252U;
  c9_info[30].fileTime2 = 0U;
  c9_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c9_info[31].name = "length";
  c9_info[31].dominantType = "double";
  c9_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c9_info[31].fileLength = 326U;
  c9_info[31].fileTime1 = 1226561076U;
  c9_info[31].fileTime2 = 0U;
  c9_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c9_info[32].name = "min";
  c9_info[32].dominantType = "double";
  c9_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[32].fileLength = 308U;
  c9_info[32].fileTime1 = 1192454034U;
  c9_info[32].fileTime2 = 0U;
  c9_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[33].name = "nargout";
  c9_info[33].dominantType = "";
  c9_info[33].resolved = "[B]nargout";
  c9_info[33].fileLength = 0U;
  c9_info[33].fileTime1 = 0U;
  c9_info[33].fileTime2 = 0U;
  c9_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[34].name = "eml_min_or_max";
  c9_info[34].dominantType = "char";
  c9_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[34].fileLength = 9969U;
  c9_info[34].fileTime1 = 1240249408U;
  c9_info[34].fileTime2 = 0U;
  c9_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[35].name = "ischar";
  c9_info[35].dominantType = "char";
  c9_info[35].resolved = "[B]ischar";
  c9_info[35].fileLength = 0U;
  c9_info[35].fileTime1 = 0U;
  c9_info[35].fileTime2 = 0U;
  c9_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[36].name = "isnumeric";
  c9_info[36].dominantType = "double";
  c9_info[36].resolved = "[B]isnumeric";
  c9_info[36].fileLength = 0U;
  c9_info[36].fileTime1 = 0U;
  c9_info[36].fileTime2 = 0U;
  c9_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c9_info[37].name = "islogical";
  c9_info[37].dominantType = "double";
  c9_info[37].resolved = "[B]islogical";
  c9_info[37].fileLength = 0U;
  c9_info[37].fileTime1 = 0U;
  c9_info[37].fileTime2 = 0U;
  c9_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[38].name = "eml_refblas_xgemm";
  c9_info[38].dominantType = "int32";
  c9_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[38].fileLength = 5748U;
  c9_info[38].fileTime1 = 1228077674U;
  c9_info[38].fileTime2 = 0U;
  c9_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[39].name = "eml_index_minus";
  c9_info[39].dominantType = "int32";
  c9_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[39].fileLength = 277U;
  c9_info[39].fileTime1 = 1192454184U;
  c9_info[39].fileTime2 = 0U;
  c9_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[40].name = "eml_index_times";
  c9_info[40].dominantType = "int32";
  c9_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[40].fileLength = 280U;
  c9_info[40].fileTime1 = 1192454188U;
  c9_info[40].fileTime2 = 0U;
  c9_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[41].name = "eml_index_plus";
  c9_info[41].dominantType = "int32";
  c9_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[41].fileLength = 272U;
  c9_info[41].fileTime1 = 1192454186U;
  c9_info[41].fileTime2 = 0U;
  c9_info[42].context = "";
  c9_info[42].name = "dot";
  c9_info[42].dominantType = "double";
  c9_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c9_info[42].fileLength = 2812U;
  c9_info[42].fileTime1 = 1236241088U;
  c9_info[42].fileTime2 = 0U;
  c9_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c9_info[43].name = "isequal";
  c9_info[43].dominantType = "double";
  c9_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c9_info[43].fileLength = 180U;
  c9_info[43].fileTime1 = 1226561072U;
  c9_info[43].fileTime2 = 0U;
  c9_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c9_info[44].name = "eml_isequal_core";
  c9_info[44].dominantType = "double";
  c9_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c9_info[44].fileLength = 3981U;
  c9_info[44].fileTime1 = 1236241072U;
  c9_info[44].fileTime2 = 0U;
  c9_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c9_info[45].name = "ge";
  c9_info[45].dominantType = "double";
  c9_info[45].resolved = "[B]ge";
  c9_info[45].fileLength = 0U;
  c9_info[45].fileTime1 = 0U;
  c9_info[45].fileTime2 = 0U;
  c9_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c9_info[46].name = "true";
  c9_info[46].dominantType = "";
  c9_info[46].resolved = "[B]true";
  c9_info[46].fileLength = 0U;
  c9_info[46].fileTime1 = 0U;
  c9_info[46].fileTime2 = 0U;
  c9_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c9_info[47].name = "isnan";
  c9_info[47].dominantType = "double";
  c9_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c9_info[47].fileLength = 506U;
  c9_info[47].fileTime1 = 1228077610U;
  c9_info[47].fileTime2 = 0U;
  c9_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c9_info[48].name = "isfloat";
  c9_info[48].dominantType = "double";
  c9_info[48].resolved = "[B]isfloat";
  c9_info[48].fileLength = 0U;
  c9_info[48].fileTime1 = 0U;
  c9_info[48].fileTime2 = 0U;
  c9_info[49].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c9_info[49].name = "isvector";
  c9_info[49].dominantType = "double";
  c9_info[49].resolved = "[B]isvector";
  c9_info[49].fileLength = 0U;
  c9_info[49].fileTime1 = 0U;
  c9_info[49].fileTime2 = 0U;
  c9_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c9_info[50].name = "eml_xdotc";
  c9_info[50].dominantType = "int32";
  c9_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c9_info[50].fileLength = 1453U;
  c9_info[50].fileTime1 = 1209318250U;
  c9_info[50].fileTime2 = 0U;
  c9_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c9_info[51].name = "eml_xdot";
  c9_info[51].dominantType = "int32";
  c9_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c9_info[51].fileLength = 1330U;
  c9_info[51].fileTime1 = 1209318250U;
  c9_info[51].fileTime2 = 0U;
  c9_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c9_info[52].name = "eml_refblas_xdot";
  c9_info[52].dominantType = "int32";
  c9_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c9_info[52].fileLength = 343U;
  c9_info[52].fileTime1 = 1211203444U;
  c9_info[52].fileTime2 = 0U;
  c9_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c9_info[53].name = "eml_refblas_xdotx";
  c9_info[53].dominantType = "int32";
  c9_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[53].fileLength = 1605U;
  c9_info[53].fileTime1 = 1236241080U;
  c9_info[53].fileTime2 = 0U;
  c9_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[54].name = "times";
  c9_info[54].dominantType = "double";
  c9_info[54].resolved = "[B]times";
  c9_info[54].fileLength = 0U;
  c9_info[54].fileTime1 = 0U;
  c9_info[54].fileTime2 = 0U;
  c9_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[55].name = "uminus";
  c9_info[55].dominantType = "int32";
  c9_info[55].resolved = "[B]uminus";
  c9_info[55].fileLength = 0U;
  c9_info[55].fileTime1 = 0U;
  c9_info[55].fileTime2 = 0U;
  c9_info[56].context = "";
  c9_info[56].name = "sqrt";
  c9_info[56].dominantType = "double";
  c9_info[56].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c9_info[56].fileLength = 572U;
  c9_info[56].fileTime1 = 1203431846U;
  c9_info[56].fileTime2 = 0U;
  c9_info[57].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c9_info[57].name = "eml_scalar_sqrt";
  c9_info[57].dominantType = "double";
  c9_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c9_info[57].fileLength = 664U;
  c9_info[57].fileTime1 = 1209318194U;
  c9_info[57].fileTime2 = 0U;
  c9_info[58].context = "";
  c9_info[58].name = "cross";
  c9_info[58].dominantType = "double";
  c9_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c9_info[58].fileLength = 3157U;
  c9_info[58].fileTime1 = 1240249462U;
  c9_info[58].fileTime2 = 0U;
  c9_info[59].context = "";
  c9_info[59].name = "mrdivide";
  c9_info[59].dominantType = "double";
  c9_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[59].fileLength = 800U;
  c9_info[59].fileTime1 = 1238421692U;
  c9_info[59].fileTime2 = 0U;
  c9_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[60].name = "rdivide";
  c9_info[60].dominantType = "double";
  c9_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[60].fileLength = 620U;
  c9_info[60].fileTime1 = 1213914166U;
  c9_info[60].fileTime2 = 0U;
  c9_info[61].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[61].name = "eml_warning";
  c9_info[61].dominantType = "char";
  c9_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c9_info[61].fileLength = 262U;
  c9_info[61].fileTime1 = 1236241078U;
  c9_info[61].fileTime2 = 0U;
  c9_info[62].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[62].name = "eml_div";
  c9_info[62].dominantType = "double";
  c9_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[62].fileLength = 4269U;
  c9_info[62].fileTime1 = 1228077626U;
  c9_info[62].fileTime2 = 0U;
}

static const mxArray *c9_g_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  boolean_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  c9_b_u = *((boolean_T *)c9_u);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3434473667U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1059858120U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3399387819U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2260480441U);
}

mxArray
  *sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3759271293U);
    pr[1] = (double)(391522981U);
    pr[2] = (double)(526627934U);
    pr[3] = (double)(681424450U);
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

static mxArray
  *sf_get_sim_state_info_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"tau\",},{M[8],M[0],T\"is_active_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
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
           9,
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

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x",0,(MexFcnForType)c9_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"tau",0,(MexFcnForType)c9_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_Si",0,(MexFcnForType)c9_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"mu",0,
                              (MexFcnForType)c9_e_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(4,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_INERTIA",0,(MexFcnForType)
                                c9_f_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,550);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c9_x)[7];
          real_T (*c9_tau)[3];
          real_T (*c9_v_Si)[6];
          c9_v_Si = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
          c9_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
          c9_tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_tau);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_v_Si);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance.c9_mu);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance.c9_m_INERTIA);
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
  sf_opaque_initialize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  initialize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_enable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_disable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  disable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_gateway_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  sf_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  ext_mode_exec_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(sf_mex_dup(st));
}

static void
  sf_opaque_terminate_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  /* Actual parameters from chart:
     m_INERTIA mu
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for m_INERTIA*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for mu*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",9,2);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",9,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom_no_charge_in_detumb",
                          "adcs_v15_integral_Power_nom_no_charge_in_detumb",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1741016361U));
  ssSetChecksum1(S,(698403271U));
  ssSetChecksum2(S,(338215346U));
  ssSetChecksum3(S,(822211522U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(SimStruct *
  S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb;
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

void c9_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
