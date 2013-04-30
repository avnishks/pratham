/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_sfun.h"
#include "c4_adcs_v15_integral_Power_nom.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_adcs_v15_integral_Power_nomInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_adcs_v15_integral_Power_nom(void);
static void initialize_params_c4_adcs_v15_integral_Power_nom(void);
static void enable_c4_adcs_v15_integral_Power_nom(void);
static void disable_c4_adcs_v15_integral_Power_nom(void);
static void c4_update_debugger_state_c4_adcs_v15_integral_Power_nom(void);
static void ext_mode_exec_c4_adcs_v15_integral_Power_nom(void);
static const mxArray *get_sim_state_c4_adcs_v15_integral_Power_nom(void);
static void set_sim_state_c4_adcs_v15_integral_Power_nom(const mxArray *c4_st);
static void finalize_c4_adcs_v15_integral_Power_nom(void);
static void sf_c4_adcs_v15_integral_Power_nom(void);
static void c4_c4_adcs_v15_integral_Power_nom(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static real_T c4_mpower(real_T c4_a);
static void c4_eml_scalar_eg(void);
static void c4_b_eml_scalar_eg(void);
static void c4_c_eml_scalar_eg(void);
static real_T c4_ceval_xdot(int32_T c4_n, real_T c4_x[3], int32_T c4_ix0,
  int32_T c4_incx, real_T c4_y[3], int32_T c4_iy0, int32_T c4_incy);
static void c4_eml_error(void);
static void c4_eml_warning(void);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_c_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_d_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_e_sf_marshall(void *c4_chartInstance, void *c4_u);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[62]);
static const mxArray *c4_f_sf_marshall(void *c4_chartInstance, void *c4_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_adcs_v15_integral_Power_nom(void)
{
  uint8_T *c4_is_active_c4_adcs_v15_integral_Power_nom;
  c4_is_active_c4_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c4_is_active_c4_adcs_v15_integral_Power_nom = 0U;
}

static void initialize_params_c4_adcs_v15_integral_Power_nom(void)
{
}

static void enable_c4_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c4_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c4_update_debugger_state_c4_adcs_v15_integral_Power_nom(void)
{
}

static void ext_mode_exec_c4_adcs_v15_integral_Power_nom(void)
{
  c4_update_debugger_state_c4_adcs_v15_integral_Power_nom();
}

static const mxArray *get_sim_state_c4_adcs_v15_integral_Power_nom(void)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T *c4_is_active_c4_adcs_v15_integral_Power_nom;
  real_T (*c4_v_B)[3];
  c4_is_active_c4_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c4_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2));
  for (c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    c4_u[c4_i0] = (*c4_v_B)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_u = *c4_is_active_c4_adcs_v15_integral_Power_nom;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_adcs_v15_integral_Power_nom(const mxArray *c4_st)
{
  const mxArray *c4_u;
  const mxArray *c4_v_B;
  real_T c4_dv0[3];
  int32_T c4_i1;
  real_T c4_y[3];
  int32_T c4_i2;
  const mxArray *c4_is_active_c4_adcs_v15_integral_Power_nom;
  uint8_T c4_u0;
  uint8_T c4_b_y;
  boolean_T *c4_doneDoubleBufferReInit;
  uint8_T *c4_b_is_active_c4_adcs_v15_integral_Power_nom;
  real_T (*c4_b_v_B)[3];
  c4_b_is_active_c4_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c4_b_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_v_B = sf_mex_dup(sf_mex_getcell(c4_u, 0));
  sf_mex_import("v_B", sf_mex_dup(c4_v_B), &c4_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1 = c4_i1 + 1) {
    c4_y[c4_i1] = c4_dv0[c4_i1];
  }

  sf_mex_destroy(&c4_v_B);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2 = c4_i2 + 1) {
    (*c4_b_v_B)[c4_i2] = c4_y[c4_i2];
  }

  c4_is_active_c4_adcs_v15_integral_Power_nom = sf_mex_dup(sf_mex_getcell(c4_u,
    1));
  sf_mex_import("is_active_c4_adcs_v15_integral_Power_nom", sf_mex_dup
                (c4_is_active_c4_adcs_v15_integral_Power_nom), &c4_u0, 1, 3, 0U
                , 0, 0U, 0);
  c4_b_y = c4_u0;
  sf_mex_destroy(&c4_is_active_c4_adcs_v15_integral_Power_nom);
  *c4_b_is_active_c4_adcs_v15_integral_Power_nom = c4_b_y;
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_adcs_v15_integral_Power_nom();
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_adcs_v15_integral_Power_nom(void)
{
}

static void sf_c4_adcs_v15_integral_Power_nom(void)
{
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_previousEvent;
  real_T (*c4_v_I)[3];
  real_T (*c4_v_B)[3];
  real_T (*c4_x)[7];
  c4_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c4_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c4_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  for (c4_i3 = 0; c4_i3 < 7; c4_i3 = c4_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_x)[c4_i3], 0U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4 = c4_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_v_B)[c4_i4], 1U);
  }

  for (c4_i5 = 0; c4_i5 < 3; c4_i5 = c4_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_v_I)[c4_i5], 2U);
  }

  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c4_c4_adcs_v15_integral_Power_nom();
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nomMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c4_c4_adcs_v15_integral_Power_nom(void)
{
  int32_T c4_i6;
  real_T c4_x[7];
  int32_T c4_i7;
  real_T c4_v_I[3];
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 2.0;
  real_T c4_TBI[9];
  real_T c4_q3;
  real_T c4_q2;
  real_T c4_q1;
  real_T c4_q0;
  real_T c4_q[4];
  real_T c4_v_B[3];
  int32_T c4_i8;
  real_T c4_b;
  real_T c4_a;
  real_T c4_b_b;
  real_T c4_y;
  real_T c4_c_b;
  real_T c4_b_a;
  real_T c4_d_b;
  real_T c4_b_y;
  real_T c4_e_b;
  real_T c4_c_a;
  real_T c4_f_b;
  real_T c4_c_y;
  real_T c4_g_b;
  real_T c4_d_a;
  real_T c4_h_b;
  real_T c4_d_y;
  real_T c4_i_b;
  real_T c4_e_a;
  real_T c4_j_b;
  real_T c4_e_y;
  real_T c4_k_b;
  real_T c4_f_a;
  real_T c4_l_b;
  real_T c4_f_y;
  real_T c4_m_b;
  real_T c4_g_a;
  real_T c4_n_b;
  real_T c4_g_y;
  real_T c4_o_b;
  real_T c4_h_a;
  real_T c4_p_b;
  real_T c4_h_y;
  real_T c4_q_b;
  real_T c4_i_a;
  real_T c4_r_b;
  real_T c4_i_y;
  real_T c4_s_b;
  real_T c4_j_a;
  real_T c4_t_b;
  real_T c4_j_y;
  real_T c4_u_b;
  real_T c4_k_a;
  real_T c4_v_b;
  real_T c4_k_y;
  real_T c4_w_b;
  real_T c4_l_a;
  real_T c4_x_b;
  real_T c4_l_y;
  real_T c4_d0;
  real_T c4_d1;
  real_T c4_d2;
  int32_T c4_i9;
  real_T c4_m_a[9];
  int32_T c4_i10;
  real_T c4_y_b[3];
  int32_T c4_i11;
  real_T c4_A[9];
  int32_T c4_i12;
  real_T c4_B[3];
  int32_T c4_i13;
  int32_T c4_i14;
  real_T c4_b_A[9];
  int32_T c4_i15;
  real_T c4_b_B[3];
  int32_T c4_i16;
  real_T c4_c_A[9];
  int32_T c4_i17;
  real_T c4_c_B[3];
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  real_T c4_d_A[3];
  int32_T c4_i22;
  real_T c4_n_a[3];
  int32_T c4_i23;
  real_T c4_ab_b[3];
  int32_T c4_i24;
  real_T c4_o_a[3];
  int32_T c4_i25;
  real_T c4_bb_b[3];
  int32_T c4_i26;
  real_T c4_b_x[3];
  int32_T c4_i27;
  real_T c4_m_y[3];
  int32_T c4_i28;
  real_T c4_c_x[3];
  int32_T c4_i29;
  real_T c4_n_y[3];
  int32_T c4_i30;
  real_T c4_d_x[3];
  int32_T c4_i31;
  real_T c4_o_y[3];
  int32_T c4_i32;
  real_T c4_e_x[3];
  int32_T c4_i33;
  real_T c4_p_y[3];
  real_T c4_f_x;
  real_T c4_d_B;
  real_T c4_g_x;
  int32_T c4_i34;
  real_T c4_h_x[3];
  real_T c4_q_y;
  int32_T c4_i35;
  real_T c4_i_x[3];
  real_T c4_r_y;
  int32_T c4_i36;
  real_T c4_j_x[3];
  real_T c4_s_y;
  int32_T c4_i37;
  int32_T c4_i38;
  real_T (*c4_b_v_B)[3];
  real_T (*c4_b_v_I)[3];
  real_T (*c4_k_x)[7];
  c4_b_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c4_k_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c4_b_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  for (c4_i6 = 0; c4_i6 < 7; c4_i6 = c4_i6 + 1) {
    c4_x[c4_i6] = (*c4_k_x)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 3; c4_i7 = c4_i7 + 1) {
    c4_v_I[c4_i7] = (*c4_b_v_I)[c4_i7];
  }

  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("TBI", &c4_TBI, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("q3", &c4_q3, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("q2", &c4_q2, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("q1", &c4_q1, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("q0", &c4_q0, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("q", &c4_q, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("v_B", &c4_v_B, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("v_I", &c4_v_I, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c4_x, c4_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  for (c4_i8 = 0; c4_i8 < 4; c4_i8 = c4_i8 + 1) {
    c4_q[c4_i8] = c4_x[c4_i8];
  }

  _SFD_EML_CALL(0,7);
  c4_q0 = c4_q[3];
  _SFD_EML_CALL(0,7);
  c4_q1 = c4_q[0];
  _SFD_EML_CALL(0,7);
  c4_q2 = c4_q[1];
  _SFD_EML_CALL(0,7);
  c4_q3 = c4_q[2];
  _SFD_EML_CALL(0,9);
  c4_b = c4_q0;
  c4_a = 2.0 * c4_b;
  c4_b_b = c4_q1;
  c4_y = c4_a * c4_b_b;
  c4_c_b = c4_q2;
  c4_b_a = 2.0 * c4_c_b;
  c4_d_b = c4_q3;
  c4_b_y = c4_b_a * c4_d_b;
  c4_e_b = c4_q1;
  c4_c_a = 2.0 * c4_e_b;
  c4_f_b = c4_q3;
  c4_c_y = c4_c_a * c4_f_b;
  c4_g_b = c4_q0;
  c4_d_a = 2.0 * c4_g_b;
  c4_h_b = c4_q2;
  c4_d_y = c4_d_a * c4_h_b;
  c4_i_b = c4_q2;
  c4_e_a = 2.0 * c4_i_b;
  c4_j_b = c4_q3;
  c4_e_y = c4_e_a * c4_j_b;
  c4_k_b = c4_q0;
  c4_f_a = 2.0 * c4_k_b;
  c4_l_b = c4_q1;
  c4_f_y = c4_f_a * c4_l_b;
  c4_m_b = c4_q0;
  c4_g_a = 2.0 * c4_m_b;
  c4_n_b = c4_q3;
  c4_g_y = c4_g_a * c4_n_b;
  c4_o_b = c4_q1;
  c4_h_a = 2.0 * c4_o_b;
  c4_p_b = c4_q2;
  c4_h_y = c4_h_a * c4_p_b;
  c4_q_b = c4_q0;
  c4_i_a = 2.0 * c4_q_b;
  c4_r_b = c4_q2;
  c4_i_y = c4_i_a * c4_r_b;
  c4_s_b = c4_q1;
  c4_j_a = 2.0 * c4_s_b;
  c4_t_b = c4_q3;
  c4_j_y = c4_j_a * c4_t_b;
  c4_u_b = c4_q1;
  c4_k_a = 2.0 * c4_u_b;
  c4_v_b = c4_q2;
  c4_k_y = c4_k_a * c4_v_b;
  c4_w_b = c4_q0;
  c4_l_a = 2.0 * c4_w_b;
  c4_x_b = c4_q3;
  c4_l_y = c4_l_a * c4_x_b;
  c4_d0 = ((c4_mpower(c4_q0) + c4_mpower(c4_q1)) - c4_mpower(c4_q2)) - c4_mpower
    (c4_q3);
  c4_d1 = ((c4_mpower(c4_q0) - c4_mpower(c4_q1)) + c4_mpower(c4_q2)) - c4_mpower
    (c4_q3);
  c4_d2 = ((c4_mpower(c4_q0) - c4_mpower(c4_q1)) - c4_mpower(c4_q2)) + c4_mpower
    (c4_q3);
  c4_TBI[0] = c4_d0;
  c4_TBI[3] = c4_l_y + c4_k_y;
  c4_TBI[6] = c4_j_y - c4_i_y;
  c4_TBI[1] = c4_h_y - c4_g_y;
  c4_TBI[4] = c4_d1;
  c4_TBI[7] = c4_f_y + c4_e_y;
  c4_TBI[2] = c4_d_y + c4_c_y;
  c4_TBI[5] = c4_b_y - c4_y;
  c4_TBI[8] = c4_d2;
  _SFD_EML_CALL(0,13);
  for (c4_i9 = 0; c4_i9 < 9; c4_i9 = c4_i9 + 1) {
    c4_m_a[c4_i9] = c4_TBI[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10 = c4_i10 + 1) {
    c4_y_b[c4_i10] = c4_v_I[c4_i10];
  }

  c4_b_eml_scalar_eg();
  c4_b_eml_scalar_eg();
  for (c4_i11 = 0; c4_i11 < 9; c4_i11 = c4_i11 + 1) {
    c4_A[c4_i11] = c4_m_a[c4_i11];
  }

  for (c4_i12 = 0; c4_i12 < 3; c4_i12 = c4_i12 + 1) {
    c4_B[c4_i12] = c4_y_b[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13 = c4_i13 + 1) {
    c4_v_B[c4_i13] = 0.0;
  }

  for (c4_i14 = 0; c4_i14 < 9; c4_i14 = c4_i14 + 1) {
    c4_b_A[c4_i14] = c4_A[c4_i14];
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15 = c4_i15 + 1) {
    c4_b_B[c4_i15] = c4_B[c4_i15];
  }

  for (c4_i16 = 0; c4_i16 < 9; c4_i16 = c4_i16 + 1) {
    c4_c_A[c4_i16] = c4_b_A[c4_i16];
  }

  for (c4_i17 = 0; c4_i17 < 3; c4_i17 = c4_i17 + 1) {
    c4_c_B[c4_i17] = c4_b_B[c4_i17];
  }

  for (c4_i18 = 0; c4_i18 < 3; c4_i18 = c4_i18 + 1) {
    c4_v_B[c4_i18] = 0.0;
    c4_i19 = 0;
    for (c4_i20 = 0; c4_i20 < 3; c4_i20 = c4_i20 + 1) {
      c4_v_B[c4_i18] = c4_v_B[c4_i18] + c4_c_A[c4_i19 + c4_i18] * c4_c_B[c4_i20];
      c4_i19 = c4_i19 + 3;
    }
  }

  _SFD_EML_CALL(0,14);
  for (c4_i21 = 0; c4_i21 < 3; c4_i21 = c4_i21 + 1) {
    c4_d_A[c4_i21] = c4_v_B[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 3; c4_i22 = c4_i22 + 1) {
    c4_n_a[c4_i22] = c4_v_B[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 3; c4_i23 = c4_i23 + 1) {
    c4_ab_b[c4_i23] = c4_v_B[c4_i23];
  }

  c4_c_eml_scalar_eg();
  for (c4_i24 = 0; c4_i24 < 3; c4_i24 = c4_i24 + 1) {
    c4_o_a[c4_i24] = c4_n_a[c4_i24];
  }

  for (c4_i25 = 0; c4_i25 < 3; c4_i25 = c4_i25 + 1) {
    c4_bb_b[c4_i25] = c4_ab_b[c4_i25];
  }

  for (c4_i26 = 0; c4_i26 < 3; c4_i26 = c4_i26 + 1) {
    c4_b_x[c4_i26] = c4_o_a[c4_i26];
  }

  for (c4_i27 = 0; c4_i27 < 3; c4_i27 = c4_i27 + 1) {
    c4_m_y[c4_i27] = c4_bb_b[c4_i27];
  }

  for (c4_i28 = 0; c4_i28 < 3; c4_i28 = c4_i28 + 1) {
    c4_c_x[c4_i28] = c4_b_x[c4_i28];
  }

  for (c4_i29 = 0; c4_i29 < 3; c4_i29 = c4_i29 + 1) {
    c4_n_y[c4_i29] = c4_m_y[c4_i29];
  }

  for (c4_i30 = 0; c4_i30 < 3; c4_i30 = c4_i30 + 1) {
    c4_d_x[c4_i30] = c4_c_x[c4_i30];
  }

  for (c4_i31 = 0; c4_i31 < 3; c4_i31 = c4_i31 + 1) {
    c4_o_y[c4_i31] = c4_n_y[c4_i31];
  }

  for (c4_i32 = 0; c4_i32 < 3; c4_i32 = c4_i32 + 1) {
    c4_e_x[c4_i32] = c4_d_x[c4_i32];
  }

  for (c4_i33 = 0; c4_i33 < 3; c4_i33 = c4_i33 + 1) {
    c4_p_y[c4_i33] = c4_o_y[c4_i33];
  }

  c4_f_x = c4_ceval_xdot(3, c4_e_x, 1, 1, c4_p_y, 1, 1);
  c4_d_B = c4_f_x;
  if (c4_d_B < 0.0) {
    c4_eml_error();
  }

  c4_g_x = c4_d_B;
  c4_d_B = c4_g_x;
  c4_d_B = muDoubleScalarSqrt(c4_d_B);
  for (c4_i34 = 0; c4_i34 < 3; c4_i34 = c4_i34 + 1) {
    c4_h_x[c4_i34] = c4_d_A[c4_i34];
  }

  c4_q_y = c4_d_B;
  if (c4_q_y == 0.0) {
    c4_eml_warning();
  }

  for (c4_i35 = 0; c4_i35 < 3; c4_i35 = c4_i35 + 1) {
    c4_i_x[c4_i35] = c4_h_x[c4_i35];
  }

  c4_r_y = c4_q_y;
  for (c4_i36 = 0; c4_i36 < 3; c4_i36 = c4_i36 + 1) {
    c4_j_x[c4_i36] = c4_i_x[c4_i36];
  }

  c4_s_y = c4_r_y;
  for (c4_i37 = 0; c4_i37 < 3; c4_i37 = c4_i37 + 1) {
    c4_v_B[c4_i37] = c4_j_x[c4_i37] / c4_s_y;
  }

  _SFD_EML_CALL(0,-14);
  sf_debug_symbol_scope_pop();
  for (c4_i38 = 0; c4_i38 < 3; c4_i38 = c4_i38 + 1) {
    (*c4_b_v_B)[c4_i38] = c4_v_B[c4_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static real_T c4_mpower(real_T c4_a)
{
  real_T c4_b_a;
  real_T c4_ak;
  c4_b_a = c4_a;
  c4_eml_scalar_eg();
  c4_ak = c4_b_a;
  return muDoubleScalarPower(c4_ak, 2.0);
}

static void c4_eml_scalar_eg(void)
{
}

static void c4_b_eml_scalar_eg(void)
{
}

static void c4_c_eml_scalar_eg(void)
{
}

static real_T c4_ceval_xdot(int32_T c4_n, real_T c4_x[3], int32_T c4_ix0,
  int32_T c4_incx, real_T c4_y[3], int32_T c4_iy0, int32_T
  c4_incy)
{
  real_T c4_d;
  c4_d = 0.0;
  if ((real_T)c4_n > 0.0) {
    return ddot32(&c4_n, &c4_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c4_ix0), 1, 3, 1, 0) - 1], &
                  c4_incx, &c4_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c4_iy0), 1, 3, 1, 0) - 1], &c4_incy);
  }

  return c4_d;
}

static void c4_eml_error(void)
{
  int32_T c4_i39;
  static char_T c4_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c4_u[77];
  const mxArray *c4_y = NULL;
  int32_T c4_i40;
  static char_T c4_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c4_b_u[31];
  const mxArray *c4_b_y = NULL;
  for (c4_i39 = 0; c4_i39 < 77; c4_i39 = c4_i39 + 1) {
    c4_u[c4_i39] = c4_cv0[c4_i39];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c4_i40 = 0; c4_i40 < 31; c4_i40 = c4_i40 + 1) {
    c4_b_u[c4_i40] = c4_cv1[c4_i40];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c4_b_y, 14, c4_y);
}

static void c4_eml_warning(void)
{
  int32_T c4_i41;
  static char_T c4_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c4_u[15];
  const mxArray *c4_y = NULL;
  int32_T c4_i42;
  static char_T c4_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c4_b_u[19];
  const mxArray *c4_b_y = NULL;
  for (c4_i41 = 0; c4_i41 < 15; c4_i41 = c4_i41 + 1) {
    c4_u[c4_i41] = c4_cv2[c4_i41];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c4_i42 = 0; c4_i42 < 19; c4_i42 = c4_i42 + 1) {
    c4_b_u[c4_i42] = c4_cv3[c4_i42];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c4_b_y, 14, c4_y);
}

static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i43;
  real_T c4_b_u[7];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i43 = 0; c4_i43 < 7; c4_i43 = c4_i43 + 1) {
    c4_b_u[c4_i43] = (*((real_T (*)[7])c4_u))[c4_i43];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i44;
  real_T c4_b_u[3];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i44 = 0; c4_i44 < 3; c4_i44 = c4_i44 + 1) {
    c4_b_u[c4_i44] = (*((real_T (*)[3])c4_u))[c4_i44];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_c_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i45;
  real_T c4_b_u[4];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i45 = 0; c4_i45 < 4; c4_i45 = c4_i45 + 1) {
    c4_b_u[c4_i45] = (*((real_T (*)[4])c4_u))[c4_i45];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_d_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_e_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  real_T c4_b_u[9];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_i46 = 0;
  for (c4_i47 = 0; c4_i47 < 3; c4_i47 = c4_i47 + 1) {
    for (c4_i48 = 0; c4_i48 < 3; c4_i48 = c4_i48 + 1) {
      c4_b_u[c4_i48 + c4_i46] = (*((real_T (*)[9])c4_u))[c4_i48 + c4_i46];
    }

    c4_i46 = c4_i46 + 3;
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[62];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i49;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 62));
  for (c4_i49 = 0; c4_i49 < 62; c4_i49 = c4_i49 + 1) {
    c4_r0 = &c4_info[c4_i49];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i49);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i49);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i49);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i49);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i49);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i49
                    );
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i49
                    );
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[62])
{
  c4_info[0].context = "";
  c4_info[0].name = "mpower";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[0].fileLength = 3710U;
  c4_info[0].fileTime1 = 1238421690U;
  c4_info[0].fileTime2 = 0U;
  c4_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[1].name = "nargin";
  c4_info[1].dominantType = "";
  c4_info[1].resolved = "[B]nargin";
  c4_info[1].fileLength = 0U;
  c4_info[1].fileTime1 = 0U;
  c4_info[1].fileTime2 = 0U;
  c4_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[2].name = "gt";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[B]gt";
  c4_info[2].fileLength = 0U;
  c4_info[2].fileTime1 = 0U;
  c4_info[2].fileTime2 = 0U;
  c4_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[3].name = "isa";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved = "[B]isa";
  c4_info[3].fileLength = 0U;
  c4_info[3].fileTime1 = 0U;
  c4_info[3].fileTime2 = 0U;
  c4_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[4].name = "isinteger";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved = "[B]isinteger";
  c4_info[4].fileLength = 0U;
  c4_info[4].fileTime1 = 0U;
  c4_info[4].fileTime2 = 0U;
  c4_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[5].name = "isscalar";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved = "[B]isscalar";
  c4_info[5].fileLength = 0U;
  c4_info[5].fileTime1 = 0U;
  c4_info[5].fileTime2 = 0U;
  c4_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[6].name = "ndims";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[B]ndims";
  c4_info[6].fileLength = 0U;
  c4_info[6].fileTime1 = 0U;
  c4_info[6].fileTime2 = 0U;
  c4_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[7].name = "eq";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved = "[B]eq";
  c4_info[7].fileLength = 0U;
  c4_info[7].fileTime1 = 0U;
  c4_info[7].fileTime2 = 0U;
  c4_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[8].name = "size";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[B]size";
  c4_info[8].fileLength = 0U;
  c4_info[8].fileTime1 = 0U;
  c4_info[8].fileTime2 = 0U;
  c4_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[9].name = "power";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[9].fileLength = 5380U;
  c4_info[9].fileTime1 = 1228077698U;
  c4_info[9].fileTime2 = 0U;
  c4_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[10].name = "eml_scalar_eg";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[10].fileLength = 3068U;
  c4_info[10].fileTime1 = 1240249410U;
  c4_info[10].fileTime2 = 0U;
  c4_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c4_info[11].name = "false";
  c4_info[11].dominantType = "";
  c4_info[11].resolved = "[B]false";
  c4_info[11].fileLength = 0U;
  c4_info[11].fileTime1 = 0U;
  c4_info[11].fileTime2 = 0U;
  c4_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[12].name = "isstruct";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved = "[B]isstruct";
  c4_info[12].fileLength = 0U;
  c4_info[12].fileTime1 = 0U;
  c4_info[12].fileTime2 = 0U;
  c4_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c4_info[13].name = "class";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved = "[B]class";
  c4_info[13].fileLength = 0U;
  c4_info[13].fileTime1 = 0U;
  c4_info[13].fileTime2 = 0U;
  c4_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c4_info[14].name = "cast";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved = "[B]cast";
  c4_info[14].fileLength = 0U;
  c4_info[14].fileTime1 = 0U;
  c4_info[14].fileTime2 = 0U;
  c4_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c4_info[15].name = "plus";
  c4_info[15].dominantType = "double";
  c4_info[15].resolved = "[B]plus";
  c4_info[15].fileLength = 0U;
  c4_info[15].fileTime1 = 0U;
  c4_info[15].fileTime2 = 0U;
  c4_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c4_info[16].name = "isreal";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved = "[B]isreal";
  c4_info[16].fileLength = 0U;
  c4_info[16].fileTime1 = 0U;
  c4_info[16].fileTime2 = 0U;
  c4_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[17].name = "eml_scalexp_alloc";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[17].fileLength = 808U;
  c4_info[17].fileTime1 = 1230478500U;
  c4_info[17].fileTime2 = 0U;
  c4_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[18].name = "minus";
  c4_info[18].dominantType = "double";
  c4_info[18].resolved = "[B]minus";
  c4_info[18].fileLength = 0U;
  c4_info[18].fileTime1 = 0U;
  c4_info[18].fileTime2 = 0U;
  c4_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[19].name = "not";
  c4_info[19].dominantType = "logical";
  c4_info[19].resolved = "[B]not";
  c4_info[19].fileLength = 0U;
  c4_info[19].fileTime1 = 0U;
  c4_info[19].fileTime2 = 0U;
  c4_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[20].name = "lt";
  c4_info[20].dominantType = "double";
  c4_info[20].resolved = "[B]lt";
  c4_info[20].fileLength = 0U;
  c4_info[20].fileTime1 = 0U;
  c4_info[20].fileTime2 = 0U;
  c4_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[21].name = "eml_scalar_floor";
  c4_info[21].dominantType = "double";
  c4_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[21].fileLength = 260U;
  c4_info[21].fileTime1 = 1209318190U;
  c4_info[21].fileTime2 = 0U;
  c4_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[22].name = "ne";
  c4_info[22].dominantType = "double";
  c4_info[22].resolved = "[B]ne";
  c4_info[22].fileLength = 0U;
  c4_info[22].fileTime1 = 0U;
  c4_info[22].fileTime2 = 0U;
  c4_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[23].name = "eml_error";
  c4_info[23].dominantType = "char";
  c4_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[23].fileLength = 315U;
  c4_info[23].fileTime1 = 1213914146U;
  c4_info[23].fileTime2 = 0U;
  c4_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[24].name = "strcmp";
  c4_info[24].dominantType = "char";
  c4_info[24].resolved = "[B]strcmp";
  c4_info[24].fileLength = 0U;
  c4_info[24].fileTime1 = 0U;
  c4_info[24].fileTime2 = 0U;
  c4_info[25].context = "";
  c4_info[25].name = "mtimes";
  c4_info[25].dominantType = "double";
  c4_info[25].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[25].fileLength = 3302U;
  c4_info[25].fileTime1 = 1242738294U;
  c4_info[25].fileTime2 = 0U;
  c4_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[26].name = "le";
  c4_info[26].dominantType = "double";
  c4_info[26].resolved = "[B]le";
  c4_info[26].fileLength = 0U;
  c4_info[26].fileTime1 = 0U;
  c4_info[26].fileTime2 = 0U;
  c4_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[27].name = "eml_index_class";
  c4_info[27].dominantType = "";
  c4_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[27].fileLength = 909U;
  c4_info[27].fileTime1 = 1192454182U;
  c4_info[27].fileTime2 = 0U;
  c4_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[28].name = "ones";
  c4_info[28].dominantType = "char";
  c4_info[28].resolved = "[B]ones";
  c4_info[28].fileLength = 0U;
  c4_info[28].fileTime1 = 0U;
  c4_info[28].fileTime2 = 0U;
  c4_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[29].name = "isempty";
  c4_info[29].dominantType = "double";
  c4_info[29].resolved = "[B]isempty";
  c4_info[29].fileLength = 0U;
  c4_info[29].fileTime1 = 0U;
  c4_info[29].fileTime2 = 0U;
  c4_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[30].name = "eml_xgemm";
  c4_info[30].dominantType = "int32";
  c4_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[30].fileLength = 3184U;
  c4_info[30].fileTime1 = 1209318252U;
  c4_info[30].fileTime2 = 0U;
  c4_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c4_info[31].name = "length";
  c4_info[31].dominantType = "double";
  c4_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c4_info[31].fileLength = 326U;
  c4_info[31].fileTime1 = 1226561076U;
  c4_info[31].fileTime2 = 0U;
  c4_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c4_info[32].name = "min";
  c4_info[32].dominantType = "double";
  c4_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[32].fileLength = 308U;
  c4_info[32].fileTime1 = 1192454034U;
  c4_info[32].fileTime2 = 0U;
  c4_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[33].name = "nargout";
  c4_info[33].dominantType = "";
  c4_info[33].resolved = "[B]nargout";
  c4_info[33].fileLength = 0U;
  c4_info[33].fileTime1 = 0U;
  c4_info[33].fileTime2 = 0U;
  c4_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[34].name = "eml_min_or_max";
  c4_info[34].dominantType = "char";
  c4_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[34].fileLength = 9969U;
  c4_info[34].fileTime1 = 1240249408U;
  c4_info[34].fileTime2 = 0U;
  c4_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[35].name = "ischar";
  c4_info[35].dominantType = "char";
  c4_info[35].resolved = "[B]ischar";
  c4_info[35].fileLength = 0U;
  c4_info[35].fileTime1 = 0U;
  c4_info[35].fileTime2 = 0U;
  c4_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[36].name = "isnumeric";
  c4_info[36].dominantType = "double";
  c4_info[36].resolved = "[B]isnumeric";
  c4_info[36].fileLength = 0U;
  c4_info[36].fileTime1 = 0U;
  c4_info[36].fileTime2 = 0U;
  c4_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c4_info[37].name = "islogical";
  c4_info[37].dominantType = "double";
  c4_info[37].resolved = "[B]islogical";
  c4_info[37].fileLength = 0U;
  c4_info[37].fileTime1 = 0U;
  c4_info[37].fileTime2 = 0U;
  c4_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[38].name = "eml_refblas_xgemm";
  c4_info[38].dominantType = "int32";
  c4_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[38].fileLength = 5748U;
  c4_info[38].fileTime1 = 1228077674U;
  c4_info[38].fileTime2 = 0U;
  c4_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[39].name = "eml_index_minus";
  c4_info[39].dominantType = "int32";
  c4_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c4_info[39].fileLength = 277U;
  c4_info[39].fileTime1 = 1192454184U;
  c4_info[39].fileTime2 = 0U;
  c4_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[40].name = "eml_index_times";
  c4_info[40].dominantType = "int32";
  c4_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c4_info[40].fileLength = 280U;
  c4_info[40].fileTime1 = 1192454188U;
  c4_info[40].fileTime2 = 0U;
  c4_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[41].name = "eml_index_plus";
  c4_info[41].dominantType = "int32";
  c4_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c4_info[41].fileLength = 272U;
  c4_info[41].fileTime1 = 1192454186U;
  c4_info[41].fileTime2 = 0U;
  c4_info[42].context = "";
  c4_info[42].name = "dot";
  c4_info[42].dominantType = "double";
  c4_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c4_info[42].fileLength = 2812U;
  c4_info[42].fileTime1 = 1236241088U;
  c4_info[42].fileTime2 = 0U;
  c4_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c4_info[43].name = "isequal";
  c4_info[43].dominantType = "double";
  c4_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[43].fileLength = 180U;
  c4_info[43].fileTime1 = 1226561072U;
  c4_info[43].fileTime2 = 0U;
  c4_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[44].name = "eml_isequal_core";
  c4_info[44].dominantType = "double";
  c4_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[44].fileLength = 3981U;
  c4_info[44].fileTime1 = 1236241072U;
  c4_info[44].fileTime2 = 0U;
  c4_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[45].name = "ge";
  c4_info[45].dominantType = "double";
  c4_info[45].resolved = "[B]ge";
  c4_info[45].fileLength = 0U;
  c4_info[45].fileTime1 = 0U;
  c4_info[45].fileTime2 = 0U;
  c4_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c4_info[46].name = "true";
  c4_info[46].dominantType = "";
  c4_info[46].resolved = "[B]true";
  c4_info[46].fileLength = 0U;
  c4_info[46].fileTime1 = 0U;
  c4_info[46].fileTime2 = 0U;
  c4_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c4_info[47].name = "isnan";
  c4_info[47].dominantType = "double";
  c4_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c4_info[47].fileLength = 506U;
  c4_info[47].fileTime1 = 1228077610U;
  c4_info[47].fileTime2 = 0U;
  c4_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c4_info[48].name = "isfloat";
  c4_info[48].dominantType = "double";
  c4_info[48].resolved = "[B]isfloat";
  c4_info[48].fileLength = 0U;
  c4_info[48].fileTime1 = 0U;
  c4_info[48].fileTime2 = 0U;
  c4_info[49].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c4_info[49].name = "isvector";
  c4_info[49].dominantType = "double";
  c4_info[49].resolved = "[B]isvector";
  c4_info[49].fileLength = 0U;
  c4_info[49].fileTime1 = 0U;
  c4_info[49].fileTime2 = 0U;
  c4_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c4_info[50].name = "eml_xdotc";
  c4_info[50].dominantType = "int32";
  c4_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c4_info[50].fileLength = 1453U;
  c4_info[50].fileTime1 = 1209318250U;
  c4_info[50].fileTime2 = 0U;
  c4_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c4_info[51].name = "eml_xdot";
  c4_info[51].dominantType = "int32";
  c4_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c4_info[51].fileLength = 1330U;
  c4_info[51].fileTime1 = 1209318250U;
  c4_info[51].fileTime2 = 0U;
  c4_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c4_info[52].name = "eml_refblas_xdot";
  c4_info[52].dominantType = "int32";
  c4_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c4_info[52].fileLength = 343U;
  c4_info[52].fileTime1 = 1211203444U;
  c4_info[52].fileTime2 = 0U;
  c4_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c4_info[53].name = "eml_refblas_xdotx";
  c4_info[53].dominantType = "int32";
  c4_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[53].fileLength = 1605U;
  c4_info[53].fileTime1 = 1236241080U;
  c4_info[53].fileTime2 = 0U;
  c4_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[54].name = "times";
  c4_info[54].dominantType = "double";
  c4_info[54].resolved = "[B]times";
  c4_info[54].fileLength = 0U;
  c4_info[54].fileTime1 = 0U;
  c4_info[54].fileTime2 = 0U;
  c4_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[55].name = "uminus";
  c4_info[55].dominantType = "int32";
  c4_info[55].resolved = "[B]uminus";
  c4_info[55].fileLength = 0U;
  c4_info[55].fileTime1 = 0U;
  c4_info[55].fileTime2 = 0U;
  c4_info[56].context = "";
  c4_info[56].name = "sqrt";
  c4_info[56].dominantType = "double";
  c4_info[56].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[56].fileLength = 572U;
  c4_info[56].fileTime1 = 1203431846U;
  c4_info[56].fileTime2 = 0U;
  c4_info[57].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[57].name = "eml_scalar_sqrt";
  c4_info[57].dominantType = "double";
  c4_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[57].fileLength = 664U;
  c4_info[57].fileTime1 = 1209318194U;
  c4_info[57].fileTime2 = 0U;
  c4_info[58].context = "";
  c4_info[58].name = "mrdivide";
  c4_info[58].dominantType = "double";
  c4_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[58].fileLength = 800U;
  c4_info[58].fileTime1 = 1238421692U;
  c4_info[58].fileTime2 = 0U;
  c4_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[59].name = "rdivide";
  c4_info[59].dominantType = "double";
  c4_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[59].fileLength = 620U;
  c4_info[59].fileTime1 = 1213914166U;
  c4_info[59].fileTime2 = 0U;
  c4_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[60].name = "eml_warning";
  c4_info[60].dominantType = "char";
  c4_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c4_info[60].fileLength = 262U;
  c4_info[60].fileTime1 = 1236241078U;
  c4_info[60].fileTime2 = 0U;
  c4_info[61].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[61].name = "eml_div";
  c4_info[61].dominantType = "double";
  c4_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[61].fileLength = 4269U;
  c4_info[61].fileTime1 = 1228077626U;
  c4_info[61].fileTime2 = 0U;
}

static const mxArray *c4_f_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  boolean_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((boolean_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_adcs_v15_integral_Power_nom_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1386441009U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(327784955U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1369775399U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(628863522U);
}

mxArray *sf_c4_adcs_v15_integral_Power_nom_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3405708854U);
    pr[1] = (double)(644242882U);
    pr[2] = (double)(2246312254U);
    pr[3] = (double)(266222024U);
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

static mxArray *sf_get_sim_state_info_c4_adcs_v15_integral_Power_nom(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v_B\",},{M[8],M[0],T\"is_active_c4_adcs_v15_integral_Power_nom\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_adcs_v15_integral_Power_nom_get_check_sum(&mxChecksum);
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
           4,
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
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x",0,(MexFcnForType)c4_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_B",0,(MexFcnForType)c4_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_I",0,(MexFcnForType)c4_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,474);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c4_x)[7];
          real_T (*c4_v_B)[3];
          real_T (*c4_v_I)[3];
          c4_v_B = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c4_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
          c4_v_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_v_B);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_v_I);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_nomMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_adcs_v15_integral_Power_nom();
  initialize_c4_adcs_v15_integral_Power_nom();
}

static void sf_opaque_enable_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  enable_c4_adcs_v15_integral_Power_nom();
}

static void sf_opaque_disable_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  disable_c4_adcs_v15_integral_Power_nom();
}

static void sf_opaque_gateway_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  sf_c4_adcs_v15_integral_Power_nom();
}

static void sf_opaque_ext_mode_exec_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  ext_mode_exec_c4_adcs_v15_integral_Power_nom();
}

static mxArray* sf_opaque_get_sim_state_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c4_adcs_v15_integral_Power_nom();
  return st;
}

static void sf_opaque_set_sim_state_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c4_adcs_v15_integral_Power_nom(sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c4_adcs_v15_integral_Power_nom();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_adcs_v15_integral_Power_nom(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_adcs_v15_integral_Power_nom();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c4_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_nom",
                "adcs_v15_integral_Power_nom",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom","adcs_v15_integral_Power_nom",4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",4,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",4,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom",
                          "adcs_v15_integral_Power_nom",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1957628564U));
  ssSetChecksum1(S,(3672849055U));
  ssSetChecksum2(S,(3827974951U));
  ssSetChecksum3(S,(2843323359U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_adcs_v15_integral_Power_nom(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c4_adcs_v15_integral_Power_nom;
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

void c4_adcs_v15_integral_Power_nom_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_adcs_v15_integral_Power_nom(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_adcs_v15_integral_Power_nom_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
