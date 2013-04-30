/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_dist_sfun.h"
#include "c1_adcs_v15_integral_Power_dist.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_dist_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_adcs_v15_integral_Power_distInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_adcs_v15_integral_Power_dist(void);
static void initialize_params_c1_adcs_v15_integral_Power_dist(void);
static void enable_c1_adcs_v15_integral_Power_dist(void);
static void disable_c1_adcs_v15_integral_Power_dist(void);
static void c1_update_debugger_state_c1_adcs_v15_integral_Power_dist(void);
static void ext_mode_exec_c1_adcs_v15_integral_Power_dist(void);
static const mxArray *get_sim_state_c1_adcs_v15_integral_Power_dist(void);
static void set_sim_state_c1_adcs_v15_integral_Power_dist(const mxArray *c1_st);
static void finalize_c1_adcs_v15_integral_Power_dist(void);
static void sf_c1_adcs_v15_integral_Power_dist(void);
static void c1_c1_adcs_v15_integral_Power_dist(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_eml_scalar_eg(void);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[43]);
static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_adcs_v15_integral_Power_dist(void)
{
  uint8_T *c1_is_active_c1_adcs_v15_integral_Power_dist;
  c1_is_active_c1_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c1_is_active_c1_adcs_v15_integral_Power_dist = 0U;
}

static void initialize_params_c1_adcs_v15_integral_Power_dist(void)
{
}

static void enable_c1_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c1_update_debugger_state_c1_adcs_v15_integral_Power_dist(void)
{
}

static void ext_mode_exec_c1_adcs_v15_integral_Power_dist(void)
{
  c1_update_debugger_state_c1_adcs_v15_integral_Power_dist();
}

static const mxArray *get_sim_state_c1_adcs_v15_integral_Power_dist(void)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[9];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T *c1_is_active_c1_adcs_v15_integral_Power_dist;
  real_T (*c1_DCM)[9];
  c1_DCM = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 1);
  c1_is_active_c1_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  for (c1_i0 = 0; c1_i0 < 9; c1_i0 = c1_i0 + 1) {
    c1_u[c1_i0] = (*c1_DCM)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_u = *c1_is_active_c1_adcs_v15_integral_Power_dist;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_adcs_v15_integral_Power_dist(const mxArray *c1_st)
{
  const mxArray *c1_u;
  const mxArray *c1_DCM;
  real_T c1_dv0[9];
  int32_T c1_i1;
  real_T c1_y[9];
  int32_T c1_i2;
  const mxArray *c1_is_active_c1_adcs_v15_integral_Power_dist;
  uint8_T c1_u0;
  uint8_T c1_b_y;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_b_is_active_c1_adcs_v15_integral_Power_dist;
  real_T (*c1_b_DCM)[9];
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c1_b_DCM = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 1);
  c1_b_is_active_c1_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_DCM = sf_mex_dup(sf_mex_getcell(c1_u, 0));
  sf_mex_import("DCM", sf_mex_dup(c1_DCM), &c1_dv0, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1 = c1_i1 + 1) {
    c1_y[c1_i1] = c1_dv0[c1_i1];
  }

  sf_mex_destroy(&c1_DCM);
  for (c1_i2 = 0; c1_i2 < 9; c1_i2 = c1_i2 + 1) {
    (*c1_b_DCM)[c1_i2] = c1_y[c1_i2];
  }

  c1_is_active_c1_adcs_v15_integral_Power_dist = sf_mex_dup(sf_mex_getcell(c1_u,
    1));
  sf_mex_import("is_active_c1_adcs_v15_integral_Power_dist", sf_mex_dup
                (c1_is_active_c1_adcs_v15_integral_Power_dist), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_b_y = c1_u0;
  sf_mex_destroy(&c1_is_active_c1_adcs_v15_integral_Power_dist);
  *c1_b_is_active_c1_adcs_v15_integral_Power_dist = c1_b_y;
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_adcs_v15_integral_Power_dist();
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_adcs_v15_integral_Power_dist(void)
{
}

static void sf_c1_adcs_v15_integral_Power_dist(void)
{
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_previousEvent;
  real_T (*c1_DCM)[9];
  real_T (*c1_euler)[3];
  c1_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c1_DCM = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_euler)[c1_i3], 0U);
  }

  for (c1_i4 = 0; c1_i4 < 9; c1_i4 = c1_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_DCM)[c1_i4], 1U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_adcs_v15_integral_Power_dist();
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_distMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c1_c1_adcs_v15_integral_Power_dist(void)
{
  int32_T c1_i5;
  real_T c1_euler[3];
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 1.0;
  real_T c1_rot_z[9];
  real_T c1_rot_y[9];
  real_T c1_rot_x[9];
  real_T c1_yaw;
  real_T c1_pitch;
  real_T c1_roll;
  real_T c1_DCM[9];
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  int32_T c1_i6;
  int32_T c1_i7;
  static real_T c1_dv1[3] = { 1.0, 0.0, 0.0 };

  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  int32_T c1_i8;
  int32_T c1_i9;
  static real_T c1_dv2[3] = { 0.0, 1.0, 0.0 };

  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_jb_x;
  real_T c1_kb_x;
  int32_T c1_i10;
  int32_T c1_i11;
  static real_T c1_dv3[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i12;
  real_T c1_a[9];
  int32_T c1_i13;
  real_T c1_b[9];
  int32_T c1_i14;
  real_T c1_A[9];
  int32_T c1_i15;
  real_T c1_B[9];
  int32_T c1_i16;
  real_T c1_b_A[9];
  int32_T c1_i17;
  real_T c1_b_B[9];
  int32_T c1_i18;
  real_T c1_c_A[9];
  int32_T c1_i19;
  real_T c1_c_B[9];
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_b_a[9];
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  real_T c1_b_b[9];
  int32_T c1_i26;
  real_T c1_d_A[9];
  int32_T c1_i27;
  real_T c1_d_B[9];
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_e_A[9];
  int32_T c1_i30;
  real_T c1_e_B[9];
  int32_T c1_i31;
  real_T c1_f_A[9];
  int32_T c1_i32;
  real_T c1_f_B[9];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  real_T (*c1_b_DCM)[9];
  real_T (*c1_b_euler)[3];
  c1_b_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c1_b_DCM = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5 = c1_i5 + 1) {
    c1_euler[c1_i5] = (*c1_b_euler)[c1_i5];
  }

  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("rot_z", &c1_rot_z, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("rot_y", &c1_rot_y, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("rot_x", &c1_rot_x, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("yaw", &c1_yaw, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("pitch", &c1_pitch, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("roll", &c1_roll, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("DCM", &c1_DCM, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("euler", &c1_euler, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c1_roll = c1_euler[0];
  _SFD_EML_CALL(0,6);
  c1_pitch = c1_euler[1];
  _SFD_EML_CALL(0,7);
  c1_yaw = c1_euler[2];
  _SFD_EML_CALL(0,9);
  c1_x = c1_roll;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_b_x = c1_c_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_d_x = c1_roll;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_e_x = c1_f_x;
  c1_e_x = muDoubleScalarSin(c1_e_x);
  c1_g_x = c1_roll;
  c1_h_x = c1_g_x;
  c1_i_x = c1_h_x;
  c1_h_x = c1_i_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_j_x = c1_roll;
  c1_k_x = c1_j_x;
  c1_l_x = c1_k_x;
  c1_k_x = c1_l_x;
  c1_k_x = muDoubleScalarCos(c1_k_x);
  c1_i6 = 0;
  for (c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
    c1_rot_x[c1_i6] = c1_dv1[c1_i7];
    c1_i6 = c1_i6 + 3;
  }

  c1_rot_x[1] = 0.0;
  c1_rot_x[4] = c1_k_x;
  c1_rot_x[7] = c1_h_x;
  c1_rot_x[2] = 0.0;
  c1_rot_x[5] = -c1_e_x;
  c1_rot_x[8] = c1_b_x;
  _SFD_EML_CALL(0,13);
  c1_m_x = c1_pitch;
  c1_n_x = c1_m_x;
  c1_o_x = c1_n_x;
  c1_n_x = c1_o_x;
  c1_n_x = muDoubleScalarCos(c1_n_x);
  c1_p_x = c1_pitch;
  c1_q_x = c1_p_x;
  c1_r_x = c1_q_x;
  c1_q_x = c1_r_x;
  c1_q_x = muDoubleScalarSin(c1_q_x);
  c1_s_x = c1_pitch;
  c1_t_x = c1_s_x;
  c1_u_x = c1_t_x;
  c1_t_x = c1_u_x;
  c1_t_x = muDoubleScalarSin(c1_t_x);
  c1_v_x = c1_pitch;
  c1_w_x = c1_v_x;
  c1_x_x = c1_w_x;
  c1_w_x = c1_x_x;
  c1_w_x = muDoubleScalarCos(c1_w_x);
  c1_rot_y[0] = c1_w_x;
  c1_rot_y[3] = 0.0;
  c1_rot_y[6] = -c1_t_x;
  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
    c1_rot_y[c1_i8 + 1] = c1_dv2[c1_i9];
    c1_i8 = c1_i8 + 3;
  }

  c1_rot_y[2] = c1_q_x;
  c1_rot_y[5] = 0.0;
  c1_rot_y[8] = c1_n_x;
  _SFD_EML_CALL(0,17);
  c1_y_x = c1_yaw;
  c1_ab_x = c1_y_x;
  c1_bb_x = c1_ab_x;
  c1_ab_x = c1_bb_x;
  c1_ab_x = muDoubleScalarCos(c1_ab_x);
  c1_cb_x = c1_yaw;
  c1_db_x = c1_cb_x;
  c1_eb_x = c1_db_x;
  c1_db_x = c1_eb_x;
  c1_db_x = muDoubleScalarSin(c1_db_x);
  c1_fb_x = c1_yaw;
  c1_gb_x = c1_fb_x;
  c1_hb_x = c1_gb_x;
  c1_gb_x = c1_hb_x;
  c1_gb_x = muDoubleScalarSin(c1_gb_x);
  c1_ib_x = c1_yaw;
  c1_jb_x = c1_ib_x;
  c1_kb_x = c1_jb_x;
  c1_jb_x = c1_kb_x;
  c1_jb_x = muDoubleScalarCos(c1_jb_x);
  c1_rot_z[0] = c1_jb_x;
  c1_rot_z[3] = c1_gb_x;
  c1_rot_z[6] = 0.0;
  c1_rot_z[1] = -c1_db_x;
  c1_rot_z[4] = c1_ab_x;
  c1_rot_z[7] = 0.0;
  c1_i10 = 0;
  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    c1_rot_z[c1_i10 + 2] = c1_dv3[c1_i11];
    c1_i10 = c1_i10 + 3;
  }

  _SFD_EML_CALL(0,21);
  for (c1_i12 = 0; c1_i12 < 9; c1_i12 = c1_i12 + 1) {
    c1_a[c1_i12] = c1_rot_z[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 9; c1_i13 = c1_i13 + 1) {
    c1_b[c1_i13] = c1_rot_y[c1_i13];
  }

  c1_eml_scalar_eg();
  c1_eml_scalar_eg();
  for (c1_i14 = 0; c1_i14 < 9; c1_i14 = c1_i14 + 1) {
    c1_A[c1_i14] = c1_a[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 9; c1_i15 = c1_i15 + 1) {
    c1_B[c1_i15] = c1_b[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 9; c1_i16 = c1_i16 + 1) {
    c1_b_A[c1_i16] = c1_A[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 9; c1_i17 = c1_i17 + 1) {
    c1_b_B[c1_i17] = c1_B[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 9; c1_i18 = c1_i18 + 1) {
    c1_c_A[c1_i18] = c1_b_A[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 9; c1_i19 = c1_i19 + 1) {
    c1_c_B[c1_i19] = c1_b_B[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 3; c1_i20 = c1_i20 + 1) {
    c1_i21 = 0;
    for (c1_i22 = 0; c1_i22 < 3; c1_i22 = c1_i22 + 1) {
      c1_b_a[c1_i21 + c1_i20] = 0.0;
      c1_i23 = 0;
      for (c1_i24 = 0; c1_i24 < 3; c1_i24 = c1_i24 + 1) {
        c1_b_a[c1_i21 + c1_i20] = c1_b_a[c1_i21 + c1_i20] + c1_c_A[c1_i23 +
          c1_i20] * c1_c_B[c1_i24 + c1_i21];
        c1_i23 = c1_i23 + 3;
      }

      c1_i21 = c1_i21 + 3;
    }
  }

  for (c1_i25 = 0; c1_i25 < 9; c1_i25 = c1_i25 + 1) {
    c1_b_b[c1_i25] = c1_rot_x[c1_i25];
  }

  c1_eml_scalar_eg();
  c1_eml_scalar_eg();
  for (c1_i26 = 0; c1_i26 < 9; c1_i26 = c1_i26 + 1) {
    c1_d_A[c1_i26] = c1_b_a[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 9; c1_i27 = c1_i27 + 1) {
    c1_d_B[c1_i27] = c1_b_b[c1_i27];
  }

  for (c1_i28 = 0; c1_i28 < 9; c1_i28 = c1_i28 + 1) {
    c1_DCM[c1_i28] = 0.0;
  }

  for (c1_i29 = 0; c1_i29 < 9; c1_i29 = c1_i29 + 1) {
    c1_e_A[c1_i29] = c1_d_A[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 9; c1_i30 = c1_i30 + 1) {
    c1_e_B[c1_i30] = c1_d_B[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 9; c1_i31 = c1_i31 + 1) {
    c1_f_A[c1_i31] = c1_e_A[c1_i31];
  }

  for (c1_i32 = 0; c1_i32 < 9; c1_i32 = c1_i32 + 1) {
    c1_f_B[c1_i32] = c1_e_B[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 3; c1_i33 = c1_i33 + 1) {
    c1_i34 = 0;
    for (c1_i35 = 0; c1_i35 < 3; c1_i35 = c1_i35 + 1) {
      c1_DCM[c1_i34 + c1_i33] = 0.0;
      c1_i36 = 0;
      for (c1_i37 = 0; c1_i37 < 3; c1_i37 = c1_i37 + 1) {
        c1_DCM[c1_i34 + c1_i33] = c1_DCM[c1_i34 + c1_i33] + c1_f_A[c1_i36 +
          c1_i33] * c1_f_B[c1_i37 + c1_i34];
        c1_i36 = c1_i36 + 3;
      }

      c1_i34 = c1_i34 + 3;
    }
  }

  _SFD_EML_CALL(0,-21);
  sf_debug_symbol_scope_pop();
  for (c1_i38 = 0; c1_i38 < 9; c1_i38 = c1_i38 + 1) {
    (*c1_b_DCM)[c1_i38] = c1_DCM[c1_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_eml_scalar_eg(void)
{
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i39;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for (c1_i39 = 0; c1_i39 < 3; c1_i39 = c1_i39 + 1) {
    c1_b_u[c1_i39] = (*((real_T (*)[3])c1_u))[c1_i39];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  real_T c1_b_u[9];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_i40 = 0;
  for (c1_i41 = 0; c1_i41 < 3; c1_i41 = c1_i41 + 1) {
    for (c1_i42 = 0; c1_i42 < 3; c1_i42 = c1_i42 + 1) {
      c1_b_u[c1_i42 + c1_i40] = (*((real_T (*)[9])c1_u))[c1_i42 + c1_i40];
    }

    c1_i40 = c1_i40 + 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray
  *sf_c1_adcs_v15_integral_Power_dist_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[43];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i43;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 43));
  for (c1_i43 = 0; c1_i43 < 43; c1_i43 = c1_i43 + 1) {
    c1_r0 = &c1_info[c1_i43];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i43);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i43);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i43);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i43);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i43);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i43
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i43
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[43])
{
  c1_info[0].context = "";
  c1_info[0].name = "cos";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[0].fileLength = 324U;
  c1_info[0].fileTime1 = 1203431752U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[1].name = "nargin";
  c1_info[1].dominantType = "";
  c1_info[1].resolved = "[B]nargin";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[2].name = "gt";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[B]gt";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[3].name = "isa";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]isa";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[4].name = "eml_scalar_cos";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[4].fileLength = 602U;
  c1_info[4].fileTime1 = 1209318188U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[5].name = "isreal";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]isreal";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "sin";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[6].fileLength = 324U;
  c1_info[6].fileTime1 = 1203431842U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[7].name = "eml_scalar_sin";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[7].fileLength = 601U;
  c1_info[7].fileTime1 = 1209318192U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "";
  c1_info[8].name = "uminus";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]uminus";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileLength = 3302U;
  c1_info[9].fileTime1 = 1242738294U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "isinteger";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]isinteger";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[11].name = "isscalar";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]isscalar";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[12].name = "ndims";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]ndims";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[13].name = "le";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]le";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[14].name = "size";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]size";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[15].name = "eq";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[B]eq";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[16].name = "not";
  c1_info[16].dominantType = "logical";
  c1_info[16].resolved = "[B]not";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[17].name = "strcmp";
  c1_info[17].dominantType = "char";
  c1_info[17].resolved = "[B]strcmp";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[18].name = "class";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]class";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[19].name = "ne";
  c1_info[19].dominantType = "logical";
  c1_info[19].resolved = "[B]ne";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[20].name = "eml_index_class";
  c1_info[20].dominantType = "";
  c1_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[20].fileLength = 909U;
  c1_info[20].fileTime1 = 1192454182U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[21].name = "ones";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved = "[B]ones";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[22].name = "cast";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[B]cast";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[23].name = "eml_scalar_eg";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[23].fileLength = 3068U;
  c1_info[23].fileTime1 = 1240249410U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c1_info[24].name = "false";
  c1_info[24].dominantType = "";
  c1_info[24].resolved = "[B]false";
  c1_info[24].fileLength = 0U;
  c1_info[24].fileTime1 = 0U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[25].name = "isstruct";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved = "[B]isstruct";
  c1_info[25].fileLength = 0U;
  c1_info[25].fileTime1 = 0U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[26].name = "plus";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]plus";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[27].name = "isempty";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]isempty";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[28].name = "eml_xgemm";
  c1_info[28].dominantType = "int32";
  c1_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[28].fileLength = 3184U;
  c1_info[28].fileTime1 = 1209318252U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[29].name = "lt";
  c1_info[29].dominantType = "int32";
  c1_info[29].resolved = "[B]lt";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c1_info[30].name = "length";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[30].fileLength = 326U;
  c1_info[30].fileTime1 = 1226561076U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c1_info[31].name = "min";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[31].fileLength = 308U;
  c1_info[31].fileTime1 = 1192454034U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[32].name = "nargout";
  c1_info[32].dominantType = "";
  c1_info[32].resolved = "[B]nargout";
  c1_info[32].fileLength = 0U;
  c1_info[32].fileTime1 = 0U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[33].name = "eml_min_or_max";
  c1_info[33].dominantType = "char";
  c1_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[33].fileLength = 9969U;
  c1_info[33].fileTime1 = 1240249408U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[34].name = "ischar";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved = "[B]ischar";
  c1_info[34].fileLength = 0U;
  c1_info[34].fileTime1 = 0U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[35].name = "isnumeric";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]isnumeric";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c1_info[36].name = "islogical";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]islogical";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c1_info[37].name = "eml_scalexp_alloc";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[37].fileLength = 808U;
  c1_info[37].fileTime1 = 1230478500U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[38].name = "minus";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]minus";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[39].name = "eml_refblas_xgemm";
  c1_info[39].dominantType = "int32";
  c1_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[39].fileLength = 5748U;
  c1_info[39].fileTime1 = 1228077674U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[40].name = "eml_index_minus";
  c1_info[40].dominantType = "int32";
  c1_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[40].fileLength = 277U;
  c1_info[40].fileTime1 = 1192454184U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[41].name = "eml_index_times";
  c1_info[41].dominantType = "int32";
  c1_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[41].fileLength = 280U;
  c1_info[41].fileTime1 = 1192454188U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[42].name = "eml_index_plus";
  c1_info[42].dominantType = "int32";
  c1_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[42].fileLength = 272U;
  c1_info[42].fileTime1 = 1192454186U;
  c1_info[42].fileTime2 = 0U;
}

static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_adcs_v15_integral_Power_dist_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3296272322U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2139819927U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3967409550U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1698245420U);
}

mxArray *sf_c1_adcs_v15_integral_Power_dist_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(544876946U);
    pr[1] = (double)(3961474887U);
    pr[2] = (double)(3628485340U);
    pr[3] = (double)(2478549584U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_adcs_v15_integral_Power_dist(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"DCM\",},{M[8],M[0],T\"is_active_c1_adcs_v15_integral_Power_dist\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_adcs_v15_integral_Power_dist_get_check_sum(&mxChecksum);
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
           1,
           1,
           1,
           2,
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
                                1.0,0,"euler",0,(MexFcnForType)c1_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"DCM",0,(MexFcnForType)c1_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,593);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c1_euler)[3];
          real_T (*c1_DCM)[9];
          c1_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c1_DCM = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_euler);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_DCM);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_distMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_adcs_v15_integral_Power_dist();
  initialize_c1_adcs_v15_integral_Power_dist();
}

static void sf_opaque_enable_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  enable_c1_adcs_v15_integral_Power_dist();
}

static void sf_opaque_disable_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  disable_c1_adcs_v15_integral_Power_dist();
}

static void sf_opaque_gateway_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  sf_c1_adcs_v15_integral_Power_dist();
}

static void sf_opaque_ext_mode_exec_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  ext_mode_exec_c1_adcs_v15_integral_Power_dist();
}

static mxArray* sf_opaque_get_sim_state_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_adcs_v15_integral_Power_dist();
  return st;
}

static void sf_opaque_set_sim_state_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c1_adcs_v15_integral_Power_dist(sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_adcs_v15_integral_Power_dist();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_adcs_v15_integral_Power_dist(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_adcs_v15_integral_Power_dist();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c1_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_dist",
                "adcs_v15_integral_Power_dist",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_dist","adcs_v15_integral_Power_dist",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",1,1);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",1,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_dist",
                          "adcs_v15_integral_Power_dist",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(4085785042U));
  ssSetChecksum1(S,(257962037U));
  ssSetChecksum2(S,(749819047U));
  ssSetChecksum3(S,(832108664U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_adcs_v15_integral_Power_dist(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_adcs_v15_integral_Power_dist;
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

void c1_adcs_v15_integral_Power_dist_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_adcs_v15_integral_Power_dist(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_adcs_v15_integral_Power_dist_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
