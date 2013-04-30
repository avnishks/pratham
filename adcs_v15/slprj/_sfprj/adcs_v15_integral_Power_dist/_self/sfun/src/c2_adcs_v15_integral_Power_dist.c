/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_dist_sfun.h"
#include "c2_adcs_v15_integral_Power_dist.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_dist_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_adcs_v15_integral_Power_distInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_adcs_v15_integral_Power_dist(void);
static void initialize_params_c2_adcs_v15_integral_Power_dist(void);
static void enable_c2_adcs_v15_integral_Power_dist(void);
static void disable_c2_adcs_v15_integral_Power_dist(void);
static void c2_update_debugger_state_c2_adcs_v15_integral_Power_dist(void);
static void ext_mode_exec_c2_adcs_v15_integral_Power_dist(void);
static const mxArray *get_sim_state_c2_adcs_v15_integral_Power_dist(void);
static void set_sim_state_c2_adcs_v15_integral_Power_dist(const mxArray *c2_st);
static void finalize_c2_adcs_v15_integral_Power_dist(void);
static void sf_c2_adcs_v15_integral_Power_dist(void);
static void c2_c2_adcs_v15_integral_Power_dist(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_eml_scalar_eg(void);
static void c2_b_eml_scalar_eg(void);
static void c2_eml_xgemm(real_T c2_A[9], real_T c2_B[3], real_T c2_C[3], real_T
  c2_b_C[3]);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[54]);
static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_adcs_v15_integral_Power_dist(void)
{
  uint8_T *c2_is_active_c2_adcs_v15_integral_Power_dist;
  c2_is_active_c2_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c2_is_active_c2_adcs_v15_integral_Power_dist = 0U;
}

static void initialize_params_c2_adcs_v15_integral_Power_dist(void)
{
  real_T c2_dv0[9];
  int32_T c2_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'm_INERTIA' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c2_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i0 = 0; c2_i0 < 9; c2_i0 = c2_i0 + 1) {
    chartInstance.c2_m_INERTIA[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_adcs_v15_integral_Power_dist(void)
{
}

static void ext_mode_exec_c2_adcs_v15_integral_Power_dist(void)
{
  c2_update_debugger_state_c2_adcs_v15_integral_Power_dist();
}

static const mxArray *get_sim_state_c2_adcs_v15_integral_Power_dist(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_i1;
  real_T c2_u[7];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T *c2_is_active_c2_adcs_v15_integral_Power_dist;
  real_T (*c2_xdot)[7];
  c2_xdot = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_is_active_c2_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i1 = 0; c2_i1 < 7; c2_i1 = c2_i1 + 1) {
    c2_u[c2_i1] = (*c2_xdot)[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = *c2_is_active_c2_adcs_v15_integral_Power_dist;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_adcs_v15_integral_Power_dist(const mxArray *c2_st)
{
  const mxArray *c2_u;
  const mxArray *c2_xdot;
  real_T c2_dv1[7];
  int32_T c2_i2;
  real_T c2_y[7];
  int32_T c2_i3;
  const mxArray *c2_is_active_c2_adcs_v15_integral_Power_dist;
  uint8_T c2_u0;
  uint8_T c2_b_y;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_b_is_active_c2_adcs_v15_integral_Power_dist;
  real_T (*c2_b_xdot)[7];
  c2_b_xdot = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c2_b_is_active_c2_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_xdot = sf_mex_dup(sf_mex_getcell(c2_u, 0));
  sf_mex_import("xdot", sf_mex_dup(c2_xdot), &c2_dv1, 1, 0, 0U, 1, 0U, 1, 7);
  for (c2_i2 = 0; c2_i2 < 7; c2_i2 = c2_i2 + 1) {
    c2_y[c2_i2] = c2_dv1[c2_i2];
  }

  sf_mex_destroy(&c2_xdot);
  for (c2_i3 = 0; c2_i3 < 7; c2_i3 = c2_i3 + 1) {
    (*c2_b_xdot)[c2_i3] = c2_y[c2_i3];
  }

  c2_is_active_c2_adcs_v15_integral_Power_dist = sf_mex_dup(sf_mex_getcell(c2_u,
    1));
  sf_mex_import("is_active_c2_adcs_v15_integral_Power_dist", sf_mex_dup
                (c2_is_active_c2_adcs_v15_integral_Power_dist), &c2_u0, 1, 3,
                0U, 0, 0U, 0);
  c2_b_y = c2_u0;
  sf_mex_destroy(&c2_is_active_c2_adcs_v15_integral_Power_dist);
  *c2_b_is_active_c2_adcs_v15_integral_Power_dist = c2_b_y;
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_adcs_v15_integral_Power_dist();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_adcs_v15_integral_Power_dist(void)
{
}

static void sf_c2_adcs_v15_integral_Power_dist(void)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_previousEvent;
  real_T (*c2_xdot)[7];
  real_T (*c2_u)[3];
  real_T (*c2_x)[7];
  c2_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c2_xdot = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c2_i4 = 0; c2_i4 < 7; c2_i4 = c2_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_x)[c2_i4], 0U);
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_u)[c2_i5], 1U);
  }

  for (c2_i6 = 0; c2_i6 < 7; c2_i6 = c2_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_xdot)[c2_i6], 2U);
  }

  for (c2_i7 = 0; c2_i7 < 9; c2_i7 = c2_i7 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c2_m_INERTIA[c2_i7], 3U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_adcs_v15_integral_Power_dist();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_distMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c2_c2_adcs_v15_integral_Power_dist(void)
{
  int32_T c2_i8;
  real_T c2_x[7];
  int32_T c2_i9;
  real_T c2_u[3];
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 3.0;
  real_T c2_b_m_INERTIA[9] = { 1.7007470856000001E-001, -0.00071033134,
    -0.00059844292, -0.00071033134, 0.1715993471, -0.00240388659,
    -0.00059844292, -0.00240388659, 0.1585857207 };

  real_T c2_wdot[3];
  real_T c2_qdot[4];
  real_T c2_W[16];
  real_T c2_w[3];
  real_T c2_q[4];
  real_T c2_xdot[7];
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T c2_b[16];
  int32_T c2_i13;
  real_T c2_b_a[16];
  int32_T c2_i14;
  real_T c2_b_b[4];
  int32_T c2_i15;
  real_T c2_A[16];
  int32_T c2_i16;
  real_T c2_B[4];
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_b_A[16];
  int32_T c2_i19;
  real_T c2_b_B[4];
  int32_T c2_i20;
  real_T c2_c_A[16];
  int32_T c2_i21;
  real_T c2_c_B[4];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  real_T c2_c_a[3];
  int32_T c2_i26;
  real_T c2_c_b[3];
  int32_T c2_i27;
  static real_T c2_dv2[9] = { 1.7007470856000001E-001, -0.00071033134,
    -0.00059844292, -0.00071033134, 0.1715993471, -0.00240388659,
    -0.00059844292, -0.00240388659, 0.1585857207 };

  real_T c2_dv3[9];
  int32_T c2_i28;
  real_T c2_d_b[3];
  int32_T c2_i29;
  real_T c2_dv4[3];
  real_T c2_e_b[3];
  real_T c2_d_a;
  real_T c2_f_b;
  real_T c2_y;
  real_T c2_e_a;
  real_T c2_g_b;
  real_T c2_b_y;
  real_T c2_c1;
  real_T c2_f_a;
  real_T c2_h_b;
  real_T c2_c_y;
  real_T c2_g_a;
  real_T c2_i_b;
  real_T c2_d_y;
  real_T c2_c2;
  real_T c2_h_a;
  real_T c2_j_b;
  real_T c2_e_y;
  real_T c2_i_a;
  real_T c2_k_b;
  real_T c2_f_y;
  real_T c2_c3;
  real_T c2_c[3];
  int32_T c2_i30;
  real_T c2_l_b[3];
  int32_T c2_i31;
  static real_T c2_dv5[9] = { 5.8799513739451559E+000, 2.4655987494540597E-002,
    2.2562469379899763E-002, 2.4655987494540597E-002,
    5.8288691151065288E+000, 8.8448666373664678E-002, 2.2562469379899763E-002,
    8.8448666373664692E-002,
    6.3071638385728717E+000 };

  real_T c2_dv6[9];
  int32_T c2_i32;
  real_T c2_m_b[3];
  int32_T c2_i33;
  real_T c2_dv7[3];
  real_T c2_dv8[3];
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T (*c2_b_xdot)[7];
  real_T (*c2_b_u)[3];
  real_T (*c2_b_x)[7];
  c2_b_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_xdot = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c2_i8 = 0; c2_i8 < 7; c2_i8 = c2_i8 + 1) {
    c2_x[c2_i8] = (*c2_b_x)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9 = c2_i9 + 1) {
    c2_u[c2_i9] = (*c2_b_u)[c2_i9];
  }

  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("m_INERTIA", &c2_b_m_INERTIA, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("wdot", &c2_wdot, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("qdot", &c2_qdot, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("W", &c2_W, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("w", &c2_w, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("q", &c2_q, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("xdot", &c2_xdot, c2_sf_marshall);
  sf_debug_symbol_scope_add("u", &c2_u, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c2_x, c2_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c2_i10 = 0; c2_i10 < 4; c2_i10 = c2_i10 + 1) {
    c2_q[c2_i10] = c2_x[c2_i10];
  }

  _SFD_EML_CALL(0,6);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11 = c2_i11 + 1) {
    c2_w[c2_i11] = c2_x[c2_i11 + 4];
  }

  _SFD_EML_CALL(0,8);
  c2_W[0] = 0.0;
  c2_W[4] = c2_w[2];
  c2_W[8] = -c2_w[1];
  c2_W[12] = c2_w[0];
  c2_W[1] = -c2_w[2];
  c2_W[5] = 0.0;
  c2_W[9] = c2_w[0];
  c2_W[13] = c2_w[1];
  c2_W[2] = c2_w[1];
  c2_W[6] = -c2_w[0];
  c2_W[10] = 0.0;
  c2_W[14] = c2_w[2];
  c2_W[3] = -c2_w[0];
  c2_W[7] = -c2_w[1];
  c2_W[11] = -c2_w[2];
  c2_W[15] = 0.0;
  _SFD_EML_CALL(0,14);
  for (c2_i12 = 0; c2_i12 < 16; c2_i12 = c2_i12 + 1) {
    c2_b[c2_i12] = c2_W[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 16; c2_i13 = c2_i13 + 1) {
    c2_b_a[c2_i13] = 0.5 * c2_b[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 4; c2_i14 = c2_i14 + 1) {
    c2_b_b[c2_i14] = c2_q[c2_i14];
  }

  c2_eml_scalar_eg();
  c2_eml_scalar_eg();
  for (c2_i15 = 0; c2_i15 < 16; c2_i15 = c2_i15 + 1) {
    c2_A[c2_i15] = c2_b_a[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 4; c2_i16 = c2_i16 + 1) {
    c2_B[c2_i16] = c2_b_b[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 4; c2_i17 = c2_i17 + 1) {
    c2_qdot[c2_i17] = 0.0;
  }

  for (c2_i18 = 0; c2_i18 < 16; c2_i18 = c2_i18 + 1) {
    c2_b_A[c2_i18] = c2_A[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 4; c2_i19 = c2_i19 + 1) {
    c2_b_B[c2_i19] = c2_B[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 16; c2_i20 = c2_i20 + 1) {
    c2_c_A[c2_i20] = c2_b_A[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 4; c2_i21 = c2_i21 + 1) {
    c2_c_B[c2_i21] = c2_b_B[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 4; c2_i22 = c2_i22 + 1) {
    c2_qdot[c2_i22] = 0.0;
    c2_i23 = 0;
    for (c2_i24 = 0; c2_i24 < 4; c2_i24 = c2_i24 + 1) {
      c2_qdot[c2_i22] = c2_qdot[c2_i22] + c2_c_A[c2_i23 + c2_i22] *
        c2_c_B[c2_i24];
      c2_i23 = c2_i23 + 4;
    }
  }

  _SFD_EML_CALL(0,15);
  for (c2_i25 = 0; c2_i25 < 3; c2_i25 = c2_i25 + 1) {
    c2_c_a[c2_i25] = c2_w[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 3; c2_i26 = c2_i26 + 1) {
    c2_c_b[c2_i26] = c2_w[c2_i26];
  }

  c2_b_eml_scalar_eg();
  c2_b_eml_scalar_eg();
  for (c2_i27 = 0; c2_i27 < 9; c2_i27 = c2_i27 + 1) {
    c2_dv3[c2_i27] = c2_dv2[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 3; c2_i28 = c2_i28 + 1) {
    c2_d_b[c2_i28] = c2_c_b[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 3; c2_i29 = c2_i29 + 1) {
    c2_dv4[c2_i29] = 0.0;
  }

  c2_eml_xgemm(c2_dv3, c2_d_b, c2_dv4, c2_e_b);
  c2_d_a = c2_c_a[2];
  c2_f_b = c2_e_b[1];
  c2_y = c2_d_a * c2_f_b;
  c2_e_a = c2_c_a[1];
  c2_g_b = c2_e_b[2];
  c2_b_y = c2_e_a * c2_g_b;
  c2_c1 = c2_b_y - c2_y;
  c2_f_a = c2_c_a[0];
  c2_h_b = c2_e_b[2];
  c2_c_y = c2_f_a * c2_h_b;
  c2_g_a = c2_c_a[2];
  c2_i_b = c2_e_b[0];
  c2_d_y = c2_g_a * c2_i_b;
  c2_c2 = c2_d_y - c2_c_y;
  c2_h_a = c2_c_a[1];
  c2_j_b = c2_e_b[0];
  c2_e_y = c2_h_a * c2_j_b;
  c2_i_a = c2_c_a[0];
  c2_k_b = c2_e_b[1];
  c2_f_y = c2_i_a * c2_k_b;
  c2_c3 = c2_f_y - c2_e_y;
  c2_c[0] = c2_c1;
  c2_c[1] = c2_c2;
  c2_c[2] = c2_c3;
  for (c2_i30 = 0; c2_i30 < 3; c2_i30 = c2_i30 + 1) {
    c2_l_b[c2_i30] = c2_u[c2_i30] - c2_c[c2_i30];
  }

  c2_b_eml_scalar_eg();
  c2_b_eml_scalar_eg();
  for (c2_i31 = 0; c2_i31 < 9; c2_i31 = c2_i31 + 1) {
    c2_dv6[c2_i31] = c2_dv5[c2_i31];
  }

  for (c2_i32 = 0; c2_i32 < 3; c2_i32 = c2_i32 + 1) {
    c2_m_b[c2_i32] = c2_l_b[c2_i32];
  }

  for (c2_i33 = 0; c2_i33 < 3; c2_i33 = c2_i33 + 1) {
    c2_dv7[c2_i33] = 0.0;
  }

  c2_eml_xgemm(c2_dv6, c2_m_b, c2_dv7, c2_dv8);
  for (c2_i34 = 0; c2_i34 < 3; c2_i34 = c2_i34 + 1) {
    c2_wdot[c2_i34] = c2_dv8[c2_i34];
  }

  _SFD_EML_CALL(0,17);
  for (c2_i35 = 0; c2_i35 < 4; c2_i35 = c2_i35 + 1) {
    c2_xdot[c2_i35] = c2_qdot[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 3; c2_i36 = c2_i36 + 1) {
    c2_xdot[c2_i36 + 4] = c2_wdot[c2_i36];
  }

  _SFD_EML_CALL(0,-17);
  sf_debug_symbol_scope_pop();
  for (c2_i37 = 0; c2_i37 < 7; c2_i37 = c2_i37 + 1) {
    (*c2_b_xdot)[c2_i37] = c2_xdot[c2_i37];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_eml_scalar_eg(void)
{
}

static void c2_b_eml_scalar_eg(void)
{
}

static void c2_eml_xgemm(real_T c2_A[9], real_T c2_B[3], real_T c2_C[3], real_T
  c2_b_C[3])
{
  int32_T c2_i38;
  real_T c2_b_A[9];
  int32_T c2_i39;
  real_T c2_b_B[3];
  int32_T c2_i40;
  real_T c2_c_A[9];
  int32_T c2_i41;
  real_T c2_c_B[3];
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  for (c2_i38 = 0; c2_i38 < 9; c2_i38 = c2_i38 + 1) {
    c2_b_A[c2_i38] = c2_A[c2_i38];
  }

  for (c2_i39 = 0; c2_i39 < 3; c2_i39 = c2_i39 + 1) {
    c2_b_B[c2_i39] = c2_B[c2_i39];
  }

  for (c2_i40 = 0; c2_i40 < 9; c2_i40 = c2_i40 + 1) {
    c2_c_A[c2_i40] = c2_b_A[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 3; c2_i41 = c2_i41 + 1) {
    c2_c_B[c2_i41] = c2_b_B[c2_i41];
  }

  for (c2_i42 = 0; c2_i42 < 3; c2_i42 = c2_i42 + 1) {
    c2_b_C[c2_i42] = 0.0;
    c2_i43 = 0;
    for (c2_i44 = 0; c2_i44 < 3; c2_i44 = c2_i44 + 1) {
      c2_b_C[c2_i42] = c2_b_C[c2_i42] + c2_c_A[c2_i43 + c2_i42] * c2_c_B[c2_i44];
      c2_i43 = c2_i43 + 3;
    }
  }
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i45;
  real_T c2_b_u[7];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i45 = 0; c2_i45 < 7; c2_i45 = c2_i45 + 1) {
    c2_b_u[c2_i45] = (*((real_T (*)[7])c2_u))[c2_i45];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i46;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i46 = 0; c2_i46 < 3; c2_i46 = c2_i46 + 1) {
    c2_b_u[c2_i46] = (*((real_T (*)[3])c2_u))[c2_i46];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i47;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i47 = 0; c2_i47 < 4; c2_i47 = c2_i47 + 1) {
    c2_b_u[c2_i47] = (*((real_T (*)[4])c2_u))[c2_i47];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_b_u[16];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_i48 = 0;
  for (c2_i49 = 0; c2_i49 < 4; c2_i49 = c2_i49 + 1) {
    for (c2_i50 = 0; c2_i50 < 4; c2_i50 = c2_i50 + 1) {
      c2_b_u[c2_i50 + c2_i48] = (*((real_T (*)[16])c2_u))[c2_i50 + c2_i48];
    }

    c2_i48 = c2_i48 + 4;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_b_u[9];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_i51 = 0;
  for (c2_i52 = 0; c2_i52 < 3; c2_i52 = c2_i52 + 1) {
    for (c2_i53 = 0; c2_i53 < 3; c2_i53 = c2_i53 + 1) {
      c2_b_u[c2_i53 + c2_i51] = (*((real_T (*)[9])c2_u))[c2_i53 + c2_i51];
    }

    c2_i51 = c2_i51 + 3;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray
  *sf_c2_adcs_v15_integral_Power_dist_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[54];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i54;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 54));
  for (c2_i54 = 0; c2_i54 < 54; c2_i54 = c2_i54 + 1) {
    c2_r0 = &c2_info[c2_i54];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i54);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i54);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i54);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i54);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i54);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i54
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i54
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[54])
{
  c2_info[0].context = "";
  c2_info[0].name = "uminus";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]uminus";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "mtimes";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[1].fileLength = 3302U;
  c2_info[1].fileTime1 = 1242738294U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[2].name = "nargin";
  c2_info[2].dominantType = "";
  c2_info[2].resolved = "[B]nargin";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[3].name = "gt";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]gt";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].name = "isa";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isa";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[5].name = "isinteger";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isinteger";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].name = "isscalar";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]isscalar";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].name = "strcmp";
  c2_info[7].dominantType = "char";
  c2_info[7].resolved = "[B]strcmp";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].name = "size";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]size";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "eq";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]eq";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "class";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]class";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "not";
  c2_info[11].dominantType = "logical";
  c2_info[11].resolved = "[B]not";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].name = "ndims";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]ndims";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].name = "le";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]le";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].name = "isreal";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]isreal";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].name = "ne";
  c2_info[15].dominantType = "logical";
  c2_info[15].resolved = "[B]ne";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[16].name = "eml_index_class";
  c2_info[16].dominantType = "";
  c2_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[16].fileLength = 909U;
  c2_info[16].fileTime1 = 1192454182U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[17].name = "ones";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved = "[B]ones";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[18].name = "cast";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]cast";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[19].name = "eml_scalar_eg";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[19].fileLength = 3068U;
  c2_info[19].fileTime1 = 1240249410U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c2_info[20].name = "false";
  c2_info[20].dominantType = "";
  c2_info[20].resolved = "[B]false";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[21].name = "isstruct";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]isstruct";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[22].name = "plus";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]plus";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[23].name = "isempty";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]isempty";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[24].name = "eml_xgemm";
  c2_info[24].dominantType = "int32";
  c2_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[24].fileLength = 3184U;
  c2_info[24].fileTime1 = 1209318252U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[25].name = "lt";
  c2_info[25].dominantType = "int32";
  c2_info[25].resolved = "[B]lt";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c2_info[26].name = "length";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[26].fileLength = 326U;
  c2_info[26].fileTime1 = 1226561076U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c2_info[27].name = "min";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[27].fileLength = 308U;
  c2_info[27].fileTime1 = 1192454034U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[28].name = "nargout";
  c2_info[28].dominantType = "";
  c2_info[28].resolved = "[B]nargout";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[29].name = "eml_min_or_max";
  c2_info[29].dominantType = "char";
  c2_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[29].fileLength = 9969U;
  c2_info[29].fileTime1 = 1240249408U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[30].name = "ischar";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved = "[B]ischar";
  c2_info[30].fileLength = 0U;
  c2_info[30].fileTime1 = 0U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[31].name = "isnumeric";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]isnumeric";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[32].name = "islogical";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[B]islogical";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[33].name = "eml_scalexp_alloc";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[33].fileLength = 808U;
  c2_info[33].fileTime1 = 1230478500U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[34].name = "minus";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved = "[B]minus";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[35].name = "eml_refblas_xgemm";
  c2_info[35].dominantType = "int32";
  c2_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[35].fileLength = 5748U;
  c2_info[35].fileTime1 = 1228077674U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[36].name = "eml_index_minus";
  c2_info[36].dominantType = "int32";
  c2_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[36].fileLength = 277U;
  c2_info[36].fileTime1 = 1192454184U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[37].name = "eml_index_times";
  c2_info[37].dominantType = "int32";
  c2_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[37].fileLength = 280U;
  c2_info[37].fileTime1 = 1192454188U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[38].name = "eml_index_plus";
  c2_info[38].dominantType = "int32";
  c2_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[38].fileLength = 272U;
  c2_info[38].fileTime1 = 1192454186U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context = "";
  c2_info[39].name = "inv";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[39].fileLength = 4597U;
  c2_info[39].fileTime1 = 1228077680U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/inv3x3";
  c2_info[40].name = "abs";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[40].fileLength = 566U;
  c2_info[40].fileTime1 = 1221254534U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[41].name = "zeros";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved = "[B]zeros";
  c2_info[41].fileLength = 0U;
  c2_info[41].fileTime1 = 0U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[42].name = "eml_scalar_abs";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[42].fileLength = 461U;
  c2_info[42].fileTime1 = 1203431760U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/inv3x3";
  c2_info[43].name = "eml_div";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[43].fileLength = 4269U;
  c2_info[43].fileTime1 = 1228077626U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c2_info[44].name = "norm";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[44].fileLength = 5186U;
  c2_info[44].fileTime1 = 1240249448U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[45].name = "isvector";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved = "[B]isvector";
  c2_info[45].fileLength = 0U;
  c2_info[45].fileTime1 = 0U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[46].name = "inf";
  c2_info[46].dominantType = "";
  c2_info[46].resolved = "[B]inf";
  c2_info[46].fileLength = 0U;
  c2_info[46].fileTime1 = 0U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  c2_info[47].name = "isnan";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[47].fileLength = 506U;
  c2_info[47].fileTime1 = 1228077610U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  c2_info[48].name = "eml_guarded_nan";
  c2_info[48].dominantType = "char";
  c2_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[48].fileLength = 485U;
  c2_info[48].fileTime1 = 1192454180U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[49].name = "eml_is_float_class";
  c2_info[49].dominantType = "char";
  c2_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[49].fileLength = 226U;
  c2_info[49].fileTime1 = 1197834242U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[50].name = "nan";
  c2_info[50].dominantType = "char";
  c2_info[50].resolved = "[B]nan";
  c2_info[50].fileLength = 0U;
  c2_info[50].fileTime1 = 0U;
  c2_info[50].fileTime2 = 0U;
  c2_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c2_info[51].name = "eml_warning";
  c2_info[51].dominantType = "char";
  c2_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[51].fileLength = 262U;
  c2_info[51].fileTime1 = 1236241078U;
  c2_info[51].fileTime2 = 0U;
  c2_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c2_info[52].name = "eps";
  c2_info[52].dominantType = "char";
  c2_info[52].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[52].fileLength = 1337U;
  c2_info[52].fileTime1 = 1228077600U;
  c2_info[52].fileTime2 = 0U;
  c2_info[53].context = "";
  c2_info[53].name = "cross";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c2_info[53].fileLength = 3157U;
  c2_info[53].fileTime1 = 1240249462U;
  c2_info[53].fileTime2 = 0U;
}

static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_adcs_v15_integral_Power_dist_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3953070666U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(220694214U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2964612974U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3336028151U);
}

mxArray *sf_c2_adcs_v15_integral_Power_dist_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(112668144U);
    pr[1] = (double)(1284344723U);
    pr[2] = (double)(1920699066U);
    pr[3] = (double)(3753975790U);
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_adcs_v15_integral_Power_dist(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"xdot\",},{M[8],M[0],T\"is_active_c2_adcs_v15_integral_Power_dist\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_adcs_v15_integral_Power_dist_get_check_sum(&mxChecksum);
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
           2,
           1,
           1,
           4,
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
                                1.0,0,"x",0,(MexFcnForType)c2_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"u",0,(MexFcnForType)c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"xdot",0,(MexFcnForType)c2_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_INERTIA",0,(MexFcnForType)
                                c2_e_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,365);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c2_x)[7];
          real_T (*c2_u)[3];
          real_T (*c2_xdot)[7];
          c2_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
          c2_xdot = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
          c2_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_xdot);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance.c2_m_INERTIA);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_distMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_adcs_v15_integral_Power_dist();
  initialize_c2_adcs_v15_integral_Power_dist();
}

static void sf_opaque_enable_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  enable_c2_adcs_v15_integral_Power_dist();
}

static void sf_opaque_disable_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  disable_c2_adcs_v15_integral_Power_dist();
}

static void sf_opaque_gateway_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  sf_c2_adcs_v15_integral_Power_dist();
}

static void sf_opaque_ext_mode_exec_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  ext_mode_exec_c2_adcs_v15_integral_Power_dist();
}

static mxArray* sf_opaque_get_sim_state_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_adcs_v15_integral_Power_dist();
  return st;
}

static void sf_opaque_set_sim_state_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c2_adcs_v15_integral_Power_dist(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_adcs_v15_integral_Power_dist();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_adcs_v15_integral_Power_dist(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_adcs_v15_integral_Power_dist();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c2_adcs_v15_integral_Power_dist(SimStruct *S)
{
  /* Actual parameters from chart:
     m_INERTIA
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for m_INERTIA*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_dist",
                "adcs_v15_integral_Power_dist",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_dist","adcs_v15_integral_Power_dist",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",2,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",2,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_dist",
                          "adcs_v15_integral_Power_dist",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(671730364U));
  ssSetChecksum1(S,(1140581915U));
  ssSetChecksum2(S,(729886387U));
  ssSetChecksum3(S,(1501024675U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_adcs_v15_integral_Power_dist(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_adcs_v15_integral_Power_dist;
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

void c2_adcs_v15_integral_Power_dist_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_adcs_v15_integral_Power_dist(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_adcs_v15_integral_Power_dist_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
