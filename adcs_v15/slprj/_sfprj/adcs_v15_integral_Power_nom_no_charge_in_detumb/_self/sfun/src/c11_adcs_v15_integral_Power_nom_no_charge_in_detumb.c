/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun.h"
#include "c11_adcs_v15_integral_Power_nom_no_charge_in_detumb.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c11_IN_NO_ACTIVE_CHILD         (0)
#define c11_b_Snum                     (6.0)
#define c11_b_s_SS_ADC_gain            (5.0)
#define c11_b_s_MAGMETER_WEIGHT        (0.9)

/* Variable Declarations */

/* Variable Definitions */
static SFc11_adcs_v15_integral_Power_nom_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void
  initialize_params_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void enable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void disable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c11_update_debugger_state_c11_adcs_v15_integral_Power_nom_no_ch(void);
static void ext_mode_exec_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void);
static const mxArray
  *get_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void set_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c11_st);
static void finalize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void c11_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static real_T c11_mrdivide(real_T c11_A, real_T c11_B);
static void c11_eml_warning(void);
static void c11_sort(real_T c11_x[6], real_T c11_b_x[6], real_T c11_idx[6]);
static void c11_eml_sort_idx(real_T c11_x[6], int32_T c11_idx[6]);
static real_T c11_power(real_T c11_a, real_T c11_b);
static void c11_eml_error(void);
static real_T c11_norm(real_T c11_x[3]);
static real_T c11_genpnorm(real_T c11_x[3], real_T c11_p);
static real_T c11_eml_xnrm2(real_T c11_x[3]);
static real_T c11_ceval_xnrm2(int32_T c11_n, real_T c11_x[3], real_T c11_ix0,
  int32_T c11_incx);
static void c11_mldivide(real_T c11_A[9], real_T c11_B[3], real_T c11_Y[3]);
static void c11_b_eml_warning(void);
static real_T c11_dot(real_T c11_a[3], real_T c11_b[3]);
static void c11_eml_scalar_eg(void);
static real_T c11_ceval_xdot(int32_T c11_n, real_T c11_x[3], int32_T c11_ix0,
  int32_T c11_incx, real_T c11_y[3], int32_T c11_iy0, int32_T c11_incy);
static real_T c11_sqrt(real_T c11_x);
static void c11_b_eml_error(void);
static void c11_b_mrdivide(real_T c11_A[3], real_T c11_B, real_T c11_y[3]);
static void c11_cross(real_T c11_a[3], real_T c11_b[3], real_T c11_c[3]);
static real_T c11_b_norm(real_T c11_x[3]);
static real_T c11_b_genpnorm(real_T c11_x[3], real_T c11_p);
static real_T c11_b_eml_xnrm2(real_T c11_x[3]);
static real_T c11_b_ceval_xnrm2(int32_T c11_n, real_T c11_x[3], real_T c11_ix0,
  int32_T c11_incx);
static void c11_b_eml_scalar_eg(void);
static real_T c11_b_ceval_xdot(int32_T c11_n, real_T c11_x[4], int32_T c11_ix0,
  int32_T c11_incx, real_T c11_y[4], int32_T c11_iy0, int32_T c11_incy);
static const mxArray *c11_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_b_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_c_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_d_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_e_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_f_sf_marshall(void *c11_chartInstance, void *c11_u);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[93]);
static void c11_b_info_helper(c11_ResolvedFunctionInfo c11_info[93]);
static const mxArray *c11_g_sf_marshall(void *c11_chartInstance, void *c11_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  uint8_T *c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu;
  c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu = 0U;
}

static void
  initialize_params_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  real_T c11_d0;
  real_T c11_d1;
  real_T c11_d2;
  real_T c11_d3;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_SS_ADC_gain' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    2, 0), &c11_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c11_s_SS_ADC_gain = c11_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Snum' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c11_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c11_Snum = c11_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_MAGMETER_WEIGHT' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c11_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c11_s_MAGMETER_WEIGHT = c11_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_SS_MAX_ANGLE' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    3, 0), &c11_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c11_s_SS_MAX_ANGLE = c11_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c11_update_debugger_state_c11_adcs_v15_integral_Power_nom_no_ch(void)
{
}

static void ext_mode_exec_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  c11_update_debugger_state_c11_adcs_v15_integral_Power_nom_no_ch();
}

static const mxArray
  *get_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  const mxArray *c11_st = NULL;
  const mxArray *c11_y = NULL;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  int32_T c11_i0;
  real_T c11_b_u[4];
  const mxArray *c11_c_y = NULL;
  int32_T c11_i1;
  real_T c11_c_u[3];
  const mxArray *c11_d_y = NULL;
  uint8_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  real_T *c11_light_est;
  uint8_T *c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu;
  real_T (*c11_v_Sun1)[3];
  real_T (*c11_q_BO_est)[4];
  c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c11_v_Sun1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c11_q_BO_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 1);
  c11_light_est = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(4));
  c11_u = *c11_light_est;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i0 = 0; c11_i0 < 4; c11_i0 = c11_i0 + 1) {
    c11_b_u[c11_i0] = (*c11_q_BO_est)[c11_i0];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c11_y, 1, c11_c_y);
  for (c11_i1 = 0; c11_i1 < 3; c11_i1 = c11_i1 + 1) {
    c11_c_u[c11_i1] = (*c11_v_Sun1)[c11_i1];
  }

  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_d_u = *c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 3, c11_e_y);
  sf_mex_assign(&c11_st, c11_y);
  return c11_st;
}

static void set_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(
  const mxArray *c11_st)
{
  const mxArray *c11_u;
  const mxArray *c11_light_est;
  real_T c11_d4;
  real_T c11_y;
  const mxArray *c11_q_BO_est;
  real_T c11_dv0[4];
  int32_T c11_i2;
  real_T c11_b_y[4];
  int32_T c11_i3;
  const mxArray *c11_v_Sun1;
  real_T c11_dv1[3];
  int32_T c11_i4;
  real_T c11_c_y[3];
  int32_T c11_i5;
  const mxArray *c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu;
  uint8_T c11_u0;
  uint8_T c11_d_y;
  boolean_T *c11_doneDoubleBufferReInit;
  real_T *c11_b_light_est;
  uint8_T *c11_b_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_de;
  real_T (*c11_b_q_BO_est)[4];
  real_T (*c11_b_v_Sun1)[3];
  c11_b_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_de = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c11_b_v_Sun1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c11_b_q_BO_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 1);
  c11_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c11_b_light_est = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  *c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  c11_light_est = sf_mex_dup(sf_mex_getcell(c11_u, 0));
  sf_mex_import("light_est", sf_mex_dup(c11_light_est), &c11_d4, 1, 0, 0U, 0, 0U,
                0);
  c11_y = c11_d4;
  sf_mex_destroy(&c11_light_est);
  *c11_b_light_est = c11_y;
  c11_q_BO_est = sf_mex_dup(sf_mex_getcell(c11_u, 1));
  sf_mex_import("q_BO_est", sf_mex_dup(c11_q_BO_est), &c11_dv0, 1, 0, 0U, 1, 0U,
                1, 4);
  for (c11_i2 = 0; c11_i2 < 4; c11_i2 = c11_i2 + 1) {
    c11_b_y[c11_i2] = c11_dv0[c11_i2];
  }

  sf_mex_destroy(&c11_q_BO_est);
  for (c11_i3 = 0; c11_i3 < 4; c11_i3 = c11_i3 + 1) {
    (*c11_b_q_BO_est)[c11_i3] = c11_b_y[c11_i3];
  }

  c11_v_Sun1 = sf_mex_dup(sf_mex_getcell(c11_u, 2));
  sf_mex_import("v_Sun1", sf_mex_dup(c11_v_Sun1), &c11_dv1, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c11_i4 = 0; c11_i4 < 3; c11_i4 = c11_i4 + 1) {
    c11_c_y[c11_i4] = c11_dv1[c11_i4];
  }

  sf_mex_destroy(&c11_v_Sun1);
  for (c11_i5 = 0; c11_i5 < 3; c11_i5 = c11_i5 + 1) {
    (*c11_b_v_Sun1)[c11_i5] = c11_c_y[c11_i5];
  }

  c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu = sf_mex_dup
    (sf_mex_getcell(c11_u, 3));
  sf_mex_import("is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb",
                sf_mex_dup(
    c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu), &c11_u0, 1,
                3, 0U, 0, 0U, 0);
  c11_d_y = c11_u0;
  sf_mex_destroy
    (&c11_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detu);
  *c11_b_is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_de = c11_d_y;
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_adcs_v15_integral_Power_nom_no_ch();
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
}

static void sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_previousEvent;
  real_T *c11_light_est;
  real_T (*c11_v_Sun1)[3];
  real_T (*c11_v_So_c)[3];
  real_T (*c11_v_Bo_c)[3];
  real_T (*c11_q_BO_est)[4];
  real_T (*c11_m_SUN)[30];
  real_T (*c11_v_Bb_m)[3];
  c11_v_So_c = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 3);
  c11_v_Bb_m = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c11_v_Sun1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c11_q_BO_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 1);
  c11_v_Bo_c = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c11_m_SUN = (real_T (*)[30])ssGetInputPortSignal(chartInstance.S, 1);
  c11_light_est = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,9);
  for (c11_i6 = 0; c11_i6 < 3; c11_i6 = c11_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_v_Bb_m)[c11_i6], 0U);
  }

  for (c11_i7 = 0; c11_i7 < 30; c11_i7 = c11_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_m_SUN)[c11_i7], 1U);
  }

  for (c11_i8 = 0; c11_i8 < 4; c11_i8 = c11_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_q_BO_est)[c11_i8], 2U);
  }

  for (c11_i9 = 0; c11_i9 < 3; c11_i9 = c11_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_v_Bo_c)[c11_i9], 3U);
  }

  for (c11_i10 = 0; c11_i10 < 3; c11_i10 = c11_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_v_So_c)[c11_i10], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c11_s_SS_ADC_gain, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c11_Snum, 6U);
  _SFD_DATA_RANGE_CHECK(*c11_light_est, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c11_s_MAGMETER_WEIGHT, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c11_s_SS_MAX_ANGLE, 9U);
  for (c11_i11 = 0; c11_i11 < 3; c11_i11 = c11_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_v_Sun1)[c11_i11], 10U);
  }

  c11_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c11_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  _sfEvent_ = c11_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nom_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c11_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void)
{
  int32_T c11_i12;
  real_T c11_v_Bb_m[3];
  int32_T c11_i13;
  real_T c11_m_SUN[30];
  int32_T c11_i14;
  real_T c11_v_Bo_c[3];
  int32_T c11_i15;
  real_T c11_v_So_c[3];
  real_T c11_b_s_SS_MAX_ANGLE;
  real_T c11_nargout = 3.0;
  real_T c11_nargin = 8.0;
  real_T c11_c_s_MAGMETER_WEIGHT = c11_b_s_MAGMETER_WEIGHT;
  real_T c11_c_Snum = c11_b_Snum;
  real_T c11_c_s_SS_ADC_gain = c11_b_s_SS_ADC_gain;
  real_T c11_flag_sum;
  real_T c11_q_triad[4];
  real_T c11_s_q_triad;
  real_T c11_v_q_triad[3];
  real_T c11_k_q_triad;
  real_T c11_rho;
  real_T c11_nu;
  real_T c11_mu;
  real_T c11_r3[3];
  real_T c11_b3[3];
  real_T c11_a2;
  real_T c11_a1;
  real_T c11_r2[3];
  real_T c11_r1[3];
  real_T c11_b2[3];
  real_T c11_b1[3];
  real_T c11_v_Sb_m[3];
  real_T c11_p;
  real_T c11_z;
  real_T c11_unusedU0;
  real_T c11_b_unusedU0[6];
  real_T c11_index[6];
  real_T c11_ssflags[3];
  real_T c11_ssvalues[3];
  real_T c11_ssvectors[9];
  real_T c11_light;
  real_T c11_i;
  real_T c11_n_SS;
  real_T c11_values[6];
  real_T c11_t_S[6];
  real_T c11_v_Sun1[3];
  real_T c11_light_est;
  real_T c11_q_BO_est[4];
  real_T c11_a;
  real_T c11_y;
  real_T c11_x;
  real_T c11_b;
  real_T c11_b_x;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  boolean_T c11_b_b[6];
  int32_T c11_i19;
  real_T c11_b_y[6];
  int32_T c11_i20;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  real_T c11_b_i;
  int32_T c11_i24;
  int32_T c11_i25;
  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  real_T c11_b_m_SUN[6];
  real_T c11_b_index[6];
  real_T c11_c_unusedU0[6];
  int32_T c11_i29;
  int32_T c11_i30;
  int32_T c11_b_z;
  int32_T c11_i31;
  int32_T c11_c_z;
  int32_T c11_i32;
  real_T c11_c_m_SUN[3];
  int32_T c11_d_z;
  int32_T c11_i33;
  int32_T c11_e_z;
  int32_T c11_i34;
  real_T c11_d_m_SUN[3];
  int32_T c11_f_z;
  int32_T c11_i35;
  real_T c11_e_m_SUN[3];
  int32_T c11_g_z;
  int32_T c11_i36;
  int32_T c11_i37;
  real_T c11_b_ssvectors[9];
  int32_T c11_i38;
  real_T c11_b_ssvalues[3];
  real_T c11_dv2[3];
  int32_T c11_i39;
  int32_T c11_i40;
  real_T c11_b_v_Sun1[3];
  int32_T c11_i41;
  real_T c11_c_v_Sun1[3];
  int32_T c11_i42;
  real_T c11_d_v_Sun1[3];
  real_T c11_dv3[3];
  int32_T c11_i43;
  int32_T c11_i44;
  real_T c11_e_v_Sun1[3];
  int32_T c11_i45;
  real_T c11_f_v_Sun1[3];
  int32_T c11_i46;
  real_T c11_g_v_Sun1[3];
  real_T c11_dv4[3];
  int32_T c11_i47;
  int32_T c11_i48;
  int32_T c11_i49;
  int32_T c11_i50;
  int32_T c11_i51;
  int32_T c11_i52;
  real_T c11_b_b1[3];
  int32_T c11_i53;
  real_T c11_b_b2[3];
  real_T c11_dv5[3];
  int32_T c11_i54;
  int32_T c11_i55;
  real_T c11_b_b3[3];
  int32_T c11_i56;
  real_T c11_c_b3[3];
  real_T c11_dv6[3];
  int32_T c11_i57;
  int32_T c11_i58;
  real_T c11_b_r1[3];
  int32_T c11_i59;
  real_T c11_b_r2[3];
  real_T c11_dv7[3];
  int32_T c11_i60;
  int32_T c11_i61;
  real_T c11_b_r3[3];
  int32_T c11_i62;
  real_T c11_c_r3[3];
  real_T c11_dv8[3];
  int32_T c11_i63;
  int32_T c11_i64;
  real_T c11_d_b3[3];
  int32_T c11_i65;
  real_T c11_d_r3[3];
  real_T c11_b_a;
  int32_T c11_i66;
  real_T c11_c_b2[3];
  int32_T c11_i67;
  real_T c11_c_r2[3];
  real_T c11_c_b;
  real_T c11_c_y;
  int32_T c11_i68;
  real_T c11_c_b1[3];
  int32_T c11_i69;
  real_T c11_c_r1[3];
  real_T c11_d_b;
  real_T c11_d_y;
  real_T c11_e_b;
  int32_T c11_i70;
  real_T c11_d_b2[3];
  int32_T c11_i71;
  real_T c11_d_r2[3];
  real_T c11_f_b[3];
  int32_T c11_i72;
  real_T c11_e_y[3];
  int32_T c11_i73;
  real_T c11_d_b1[3];
  int32_T c11_i74;
  real_T c11_d_r1[3];
  real_T c11_g_b[3];
  int32_T c11_i75;
  real_T c11_f_y[3];
  int32_T c11_i76;
  real_T c11_e_b3[3];
  int32_T c11_i77;
  real_T c11_e_r3[3];
  real_T c11_dv9[3];
  int32_T c11_i78;
  real_T c11_dv10[3];
  int32_T c11_i79;
  real_T c11_g_y[3];
  int32_T c11_i80;
  real_T c11_e_b2[3];
  int32_T c11_i81;
  real_T c11_e_r2[3];
  real_T c11_h_b[3];
  int32_T c11_i82;
  real_T c11_h_y[3];
  int32_T c11_i83;
  real_T c11_e_b1[3];
  int32_T c11_i84;
  real_T c11_e_r1[3];
  real_T c11_i_b[3];
  int32_T c11_i85;
  real_T c11_i_y[3];
  int32_T c11_i86;
  real_T c11_f_b3[3];
  int32_T c11_i87;
  real_T c11_j_y[3];
  real_T c11_c_a;
  real_T c11_j_b;
  real_T c11_k_y;
  real_T c11_d_a;
  real_T c11_k_b;
  real_T c11_l_y;
  real_T c11_e_a;
  real_T c11_l_b;
  real_T c11_f_a;
  int32_T c11_i88;
  real_T c11_g_b3[3];
  int32_T c11_i89;
  real_T c11_f_r3[3];
  real_T c11_m_b;
  real_T c11_m_y;
  real_T c11_n_b;
  real_T c11_n_y;
  real_T c11_g_a;
  int32_T c11_i90;
  real_T c11_o_b[3];
  int32_T c11_i91;
  real_T c11_o_y[3];
  real_T c11_h_a;
  int32_T c11_i92;
  real_T c11_h_b3[3];
  int32_T c11_i93;
  real_T c11_g_r3[3];
  real_T c11_p_b[3];
  int32_T c11_i94;
  real_T c11_p_y[3];
  int32_T c11_i95;
  real_T c11_i_a;
  int32_T c11_i96;
  real_T c11_i_b3[3];
  int32_T c11_i97;
  real_T c11_h_r3[3];
  real_T c11_q_b;
  int32_T c11_i98;
  real_T c11_j_a;
  int32_T c11_i99;
  real_T c11_r_b[4];
  int32_T c11_i100;
  real_T c11_k_a;
  real_T c11_s_b;
  real_T c11_l_a;
  int32_T c11_i101;
  real_T c11_j_b3[3];
  int32_T c11_i102;
  real_T c11_i_r3[3];
  real_T c11_t_b;
  real_T c11_q_y;
  real_T c11_u_b;
  real_T c11_r_y;
  real_T c11_m_a;
  int32_T c11_i103;
  real_T c11_v_b[3];
  int32_T c11_i104;
  real_T c11_s_y[3];
  real_T c11_n_a;
  int32_T c11_i105;
  real_T c11_k_b3[3];
  int32_T c11_i106;
  real_T c11_j_r3[3];
  real_T c11_w_b[3];
  int32_T c11_i107;
  real_T c11_t_y[3];
  int32_T c11_i108;
  real_T c11_o_a;
  int32_T c11_i109;
  real_T c11_l_b3[3];
  int32_T c11_i110;
  real_T c11_k_r3[3];
  real_T c11_x_b;
  int32_T c11_i111;
  real_T c11_p_a;
  int32_T c11_i112;
  real_T c11_y_b[4];
  int32_T c11_i113;
  int32_T c11_i114;
  real_T c11_A[4];
  int32_T c11_i115;
  real_T c11_q_a[4];
  int32_T c11_i116;
  real_T c11_ab_b[4];
  int32_T c11_i117;
  real_T c11_r_a[4];
  int32_T c11_i118;
  real_T c11_bb_b[4];
  int32_T c11_i119;
  real_T c11_c_x[4];
  int32_T c11_i120;
  real_T c11_u_y[4];
  int32_T c11_i121;
  real_T c11_d_x[4];
  int32_T c11_i122;
  real_T c11_v_y[4];
  int32_T c11_i123;
  real_T c11_e_x[4];
  int32_T c11_i124;
  real_T c11_w_y[4];
  int32_T c11_i125;
  real_T c11_f_x[4];
  int32_T c11_i126;
  real_T c11_x_y[4];
  real_T c11_g_x;
  real_T c11_B;
  real_T c11_h_x;
  int32_T c11_i127;
  real_T c11_i_x[4];
  real_T c11_y_y;
  int32_T c11_i128;
  real_T c11_j_x[4];
  real_T c11_ab_y;
  int32_T c11_i129;
  real_T c11_k_x[4];
  real_T c11_bb_y;
  int32_T c11_i130;
  int32_T c11_i131;
  int32_T c11_i132;
  static real_T c11_dv11[3] = { 1.0, 0.0, 0.0 };

  int32_T c11_i133;
  static real_T c11_dv12[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c11_i134;
  int32_T c11_i135;
  real_T *c11_b_light_est;
  real_T (*c11_b_q_BO_est)[4];
  real_T (*c11_h_v_Sun1)[3];
  real_T (*c11_b_v_So_c)[3];
  real_T (*c11_b_v_Bo_c)[3];
  real_T (*c11_f_m_SUN)[30];
  real_T (*c11_b_v_Bb_m)[3];
  c11_b_v_So_c = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 3);
  c11_b_v_Bb_m = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c11_h_v_Sun1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c11_b_q_BO_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 1);
  c11_b_v_Bo_c = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c11_f_m_SUN = (real_T (*)[30])ssGetInputPortSignal(chartInstance.S, 1);
  c11_b_light_est = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,9);
  for (c11_i12 = 0; c11_i12 < 3; c11_i12 = c11_i12 + 1) {
    c11_v_Bb_m[c11_i12] = (*c11_b_v_Bb_m)[c11_i12];
  }

  for (c11_i13 = 0; c11_i13 < 30; c11_i13 = c11_i13 + 1) {
    c11_m_SUN[c11_i13] = (*c11_f_m_SUN)[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 3; c11_i14 = c11_i14 + 1) {
    c11_v_Bo_c[c11_i14] = (*c11_b_v_Bo_c)[c11_i14];
  }

  for (c11_i15 = 0; c11_i15 < 3; c11_i15 = c11_i15 + 1) {
    c11_v_So_c[c11_i15] = (*c11_b_v_So_c)[c11_i15];
  }

  c11_b_s_SS_MAX_ANGLE = chartInstance.c11_s_SS_MAX_ANGLE;
  sf_debug_symbol_scope_push(43U, 0U);
  sf_debug_symbol_scope_add("nargout", &c11_nargout, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c11_nargin, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("s_MAGMETER_WEIGHT", &c11_c_s_MAGMETER_WEIGHT,
    c11_c_sf_marshall);
  sf_debug_symbol_scope_add("Snum", &c11_c_Snum, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("s_SS_ADC_gain", &c11_c_s_SS_ADC_gain,
    c11_c_sf_marshall);
  sf_debug_symbol_scope_add("flag_sum", &c11_flag_sum, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("q_triad", &c11_q_triad, c11_d_sf_marshall);
  sf_debug_symbol_scope_add("s_q_triad", &c11_s_q_triad, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("v_q_triad", &c11_v_q_triad, c11_sf_marshall);
  sf_debug_symbol_scope_add("k_q_triad", &c11_k_q_triad, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("rho", &c11_rho, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("nu", &c11_nu, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("mu", &c11_mu, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("r3", &c11_r3, c11_sf_marshall);
  sf_debug_symbol_scope_add("b3", &c11_b3, c11_sf_marshall);
  sf_debug_symbol_scope_add("a2", &c11_a2, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("a1", &c11_a1, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("r2", &c11_r2, c11_sf_marshall);
  sf_debug_symbol_scope_add("r1", &c11_r1, c11_sf_marshall);
  sf_debug_symbol_scope_add("b2", &c11_b2, c11_sf_marshall);
  sf_debug_symbol_scope_add("b1", &c11_b1, c11_sf_marshall);
  sf_debug_symbol_scope_add("v_Sb_m", &c11_v_Sb_m, c11_sf_marshall);
  sf_debug_symbol_scope_add("p", &c11_p, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("z", &c11_z, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("unusedU0", &c11_unusedU0, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("unusedU0", &c11_b_unusedU0, c11_e_sf_marshall);
  sf_debug_symbol_scope_add("index", &c11_index, c11_e_sf_marshall);
  sf_debug_symbol_scope_add("ssflags", &c11_ssflags, c11_sf_marshall);
  sf_debug_symbol_scope_add("ssvalues", &c11_ssvalues, c11_sf_marshall);
  sf_debug_symbol_scope_add("ssvectors", &c11_ssvectors, c11_f_sf_marshall);
  sf_debug_symbol_scope_add("light", &c11_light, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("i", &c11_i, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("n_SS", &c11_n_SS, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("values", &c11_values, c11_e_sf_marshall);
  sf_debug_symbol_scope_add("t_S", &c11_t_S, c11_e_sf_marshall);
  sf_debug_symbol_scope_add("v_Sun1", &c11_v_Sun1, c11_sf_marshall);
  sf_debug_symbol_scope_add("light_est", &c11_light_est, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("q_BO_est", &c11_q_BO_est, c11_d_sf_marshall);
  sf_debug_symbol_scope_add("s_SS_MAX_ANGLE", &c11_b_s_SS_MAX_ANGLE,
    c11_c_sf_marshall);
  sf_debug_symbol_scope_add("v_So_c", &c11_v_So_c, c11_sf_marshall);
  sf_debug_symbol_scope_add("v_Bo_c", &c11_v_Bo_c, c11_sf_marshall);
  sf_debug_symbol_scope_add("m_SUN", &c11_m_SUN, c11_b_sf_marshall);
  sf_debug_symbol_scope_add("v_Bb_m", &c11_v_Bb_m, c11_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  Help */
  /*  q_triad = Estimated quaternion */
  /*  b1,b2 = the 2 measurement vectors in body frames */
  /*  r1,r2 = the 2 measurement vectors in reference frames (orbit/inertial; orbit used) */
  /*  b1 is the measurement with very high accurace as compared to b2 */
  /*  I am not sure how r1 and r2 will be determined */
  /*  a1 and a2 are Relative weights of b1 and b2 */
  /* %%%% calculate v_Sb_m from m_SUN %%%% */
  _SFD_EML_CALL(0,13);
  c11_a = c11_b_s_SS_MAX_ANGLE;
  c11_y = c11_a * 3.1415926535897931E+000;
  c11_x = c11_mrdivide(c11_y, 180.0);
  c11_b = c11_x;
  c11_b_x = c11_b;
  c11_b = c11_b_x;
  c11_b = muDoubleScalarCos(c11_b);
  for (c11_i16 = 0; c11_i16 < 6; c11_i16 = c11_i16 + 1) {
    c11_t_S[c11_i16] = c11_b;
  }

  _SFD_EML_CALL(0,14);
  c11_i17 = 0;
  for (c11_i18 = 0; c11_i18 < 6; c11_i18 = c11_i18 + 1) {
    c11_b_b[c11_i18] = (c11_m_SUN[c11_i17 + 4] > c11_t_S[c11_i18]);
    c11_i17 = c11_i17 + 5;
  }

  for (c11_i19 = 0; c11_i19 < 6; c11_i19 = c11_i19 + 1) {
    c11_b_y[c11_i19] = (real_T)c11_b_b[c11_i19];
  }

  c11_i20 = 0;
  for (c11_i21 = 0; c11_i21 < 6; c11_i21 = c11_i21 + 1) {
    c11_m_SUN[c11_i20 + 3] = c11_b_y[c11_i21];
    c11_i20 = c11_i20 + 5;
  }

  /*  set flags from measured voltages */
  _SFD_EML_CALL(0,16);
  c11_i22 = 0;
  for (c11_i23 = 0; c11_i23 < 6; c11_i23 = c11_i23 + 1) {
    c11_values[c11_i23] = c11_m_SUN[c11_i22 + 4];
    c11_i22 = c11_i22 + 5;
  }

  _SFD_EML_CALL(0,18);
  c11_n_SS = 0.0;
  c11_i = 1.0;
  c11_b_i = 1.0;
  while (c11_b_i <= c11_b_Snum) {
    c11_i = c11_b_i;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0,20);
    if (CV_EML_IF(0, 0, c11_values[_SFD_EML_ARRAY_BOUNDS_CHECK("values",
          (int32_T)_SFD_INTEGER_CHECK("i", c11_i), 1, 6, 1, 0) - 1] < 2.5)) {
      _SFD_EML_CALL(0,21);
      c11_n_SS = c11_n_SS + 1.0;
    }

    c11_b_i = c11_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_EML_FOR(0, 0, 0);
  _SFD_EML_CALL(0,25);
  if (CV_EML_IF(0, 1, c11_n_SS == c11_b_Snum)) {
    _SFD_EML_CALL(0,26);
    c11_light = 0.0;
  } else {
    _SFD_EML_CALL(0,28);
    c11_light = 1.0;
  }

  _SFD_EML_CALL(0,31);
  c11_light_est = c11_light;

  /* v_Sun1 = [1;0;0]; */
  _SFD_EML_CALL(0,34);
  if (CV_EML_IF(0, 2, c11_light == 1.0)) {
    /* %% CALCULATE SUN VECTOR %%% */
    _SFD_EML_CALL(0,38);
    for (c11_i24 = 0; c11_i24 < 9; c11_i24 = c11_i24 + 1) {
      c11_ssvectors[c11_i24] = 0.0;
    }

    _SFD_EML_CALL(0,38);
    for (c11_i25 = 0; c11_i25 < 3; c11_i25 = c11_i25 + 1) {
      c11_ssvalues[c11_i25] = 0.0;
    }

    _SFD_EML_CALL(0,38);
    for (c11_i26 = 0; c11_i26 < 3; c11_i26 = c11_i26 + 1) {
      c11_ssflags[c11_i26] = 0.0;
    }

    /*  flags = m_SUN(4,:)'; */
    /*      for i=1:3 */
    /*          [~, index] = sort(m_SUN(5,:));  % sort values in ascending order */
    /*          z = index(Snum); */
    /*          ssvectors(i,1:3) = m_SUN(1:3,z)'; */
    /*          ssflags(i) = m_SUN(4,z); */
    /*          ssvalues(i) = m_SUN(5,z); */
    /*          m_SUN(5,z) = -100 ; */
    /*          for j= 1:Snum */
    /*              if( norm(ssvectors(i,1:3)+m_SUN(1:3,j)') == 0 ) */
    /*                  m_SUN(5,j) = -100; */
    /*              end */
    /*          end */
    /*      end */
    _SFD_EML_CALL(0,54);
    c11_i27 = 0;
    for (c11_i28 = 0; c11_i28 < 6; c11_i28 = c11_i28 + 1) {
      c11_b_m_SUN[c11_i28] = c11_m_SUN[c11_i27 + 4];
      c11_i27 = c11_i27 + 5;
    }

    c11_sort(c11_b_m_SUN, c11_c_unusedU0, c11_b_index);
    for (c11_i29 = 0; c11_i29 < 6; c11_i29 = c11_i29 + 1) {
      c11_b_unusedU0[c11_i29] = c11_c_unusedU0[c11_i29];
    }

    for (c11_i30 = 0; c11_i30 < 6; c11_i30 = c11_i30 + 1) {
      c11_index[c11_i30] = c11_b_index[c11_i30];
    }

    _SFD_EML_CALL(0,54);
    c11_unusedU0 = 0.0;

    /*  sort values in ascending order */
    _SFD_EML_CALL(0,55);
    c11_z = c11_index[5];
    _SFD_EML_CALL(0,55);
    c11_p = 0.0;

    /*  first vector */
    _SFD_EML_CALL(0,56);
    c11_b_z = _SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN", (int32_T)_SFD_INTEGER_CHECK(
      "z", c11_z), 1, 6, 2, 0) - 1;
    for (c11_i31 = 0; c11_i31 < 3; c11_i31 = c11_i31 + 1) {
      c11_ssvectors[3 * c11_i31] = c11_m_SUN[c11_i31 + 5 * c11_b_z];
    }

    _SFD_EML_CALL(0,57);
    c11_ssvalues[0] = c11_m_SUN[4 + 5 * (_SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN",
      (int32_T)_SFD_INTEGER_CHECK("z", c11_z), 1, 6, 2, 0) - 1)];
    _SFD_EML_CALL(0,58);
    c11_p = 1.0;
    _SFD_EML_CALL(0,60);
    c11_z = c11_index[4];

    /*  second vector */
    while (1) {
      c11_c_z = _SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN", (int32_T)_SFD_INTEGER_CHECK
        ("z", c11_z), 1, 6, 2, 0) - 1;
      for (c11_i32 = 0; c11_i32 < 3; c11_i32 = c11_i32 + 1) {
        c11_c_m_SUN[c11_i32] = c11_m_SUN[c11_i32 + 5 * c11_c_z] + c11_ssvectors
          [3 * c11_i32];
      }

      if (!CV_EML_WHILE(0, 0, c11_norm(c11_c_m_SUN) == 0.0)) {
        break;
      }

      _SFD_EML_CALL(0,62);
      c11_p = c11_p + 1.0;
      _SFD_EML_CALL(0,63);
      c11_z = c11_index[_SFD_EML_ARRAY_BOUNDS_CHECK("index", (int32_T)
        _SFD_INTEGER_CHECK("", c11_b_Snum - c11_p), 1, 6, 1, 0) - 1];
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }

    _SFD_EML_CALL(0,65);
    c11_d_z = _SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN", (int32_T)_SFD_INTEGER_CHECK(
      "z", c11_z), 1, 6, 2, 0) - 1;
    for (c11_i33 = 0; c11_i33 < 3; c11_i33 = c11_i33 + 1) {
      c11_ssvectors[1 + 3 * c11_i33] = c11_m_SUN[c11_i33 + 5 * c11_d_z];
    }

    _SFD_EML_CALL(0,66);
    c11_ssvalues[1] = c11_m_SUN[4 + 5 * (_SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN",
      (int32_T)_SFD_INTEGER_CHECK("z", c11_z), 1, 6, 2, 0) - 1)];
    _SFD_EML_CALL(0,67);
    c11_p = c11_p + 1.0;
    _SFD_EML_CALL(0,69);
    c11_z = c11_index[_SFD_EML_ARRAY_BOUNDS_CHECK("index", (int32_T)
      _SFD_INTEGER_CHECK("", c11_b_Snum - c11_p), 1, 6, 1, 0) - 1];

    /*  3rd vector */
   label_2:
    ;
    c11_e_z = _SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN", (int32_T)_SFD_INTEGER_CHECK(
      "z", c11_z), 1, 6, 2, 0) - 1;
    for (c11_i34 = 0; c11_i34 < 3; c11_i34 = c11_i34 + 1) {
      c11_d_m_SUN[c11_i34] = c11_m_SUN[c11_i34 + 5 * c11_e_z] + c11_ssvectors[3 *
        c11_i34];
    }

    goto label_1;
   label_3:
    ;
    CV_EML_WHILE(0, 1, true);
    _SFD_EML_CALL(0,71);
    c11_p = c11_p + 1.0;
    _SFD_EML_CALL(0,72);
    c11_z = c11_index[_SFD_EML_ARRAY_BOUNDS_CHECK("index", (int32_T)
      _SFD_INTEGER_CHECK("", c11_b_Snum - c11_p), 1, 6, 1, 0) - 1];
    sf_mex_listen_for_ctrl_c(chartInstance.S);
    goto label_2;
   label_1:
    ;
    if (c11_norm(c11_d_m_SUN) == 0.0) {
      goto label_3;
    } else {
      c11_f_z = _SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN", (int32_T)_SFD_INTEGER_CHECK
        ("z", c11_z), 1, 6, 2, 0) - 1;
      for (c11_i35 = 0; c11_i35 < 3; c11_i35 = c11_i35 + 1) {
        c11_e_m_SUN[c11_i35] = c11_m_SUN[c11_i35 + 5 * c11_f_z] + c11_ssvectors
          [1 + 3 * c11_i35];
      }

      if (c11_norm(c11_e_m_SUN) == 0.0) {
        goto label_3;
      }
    }

    CV_EML_WHILE(0, 1, false);
    _SFD_EML_CALL(0,74);
    c11_g_z = _SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN", (int32_T)_SFD_INTEGER_CHECK(
      "z", c11_z), 1, 6, 2, 0) - 1;
    for (c11_i36 = 0; c11_i36 < 3; c11_i36 = c11_i36 + 1) {
      c11_ssvectors[2 + 3 * c11_i36] = c11_m_SUN[c11_i36 + 5 * c11_g_z];
    }

    _SFD_EML_CALL(0,75);
    c11_ssvalues[2] = c11_m_SUN[4 + 5 * (_SFD_EML_ARRAY_BOUNDS_CHECK("m_SUN",
      (int32_T)_SFD_INTEGER_CHECK("z", c11_z), 1, 6, 2, 0) - 1)];

    /*      p = p+1; */
    /*  v_Sun1 = inv(ssvectors)*ssvalues; */
    _SFD_EML_CALL(0,79);
    for (c11_i37 = 0; c11_i37 < 9; c11_i37 = c11_i37 + 1) {
      c11_b_ssvectors[c11_i37] = c11_ssvectors[c11_i37];
    }

    for (c11_i38 = 0; c11_i38 < 3; c11_i38 = c11_i38 + 1) {
      c11_b_ssvalues[c11_i38] = c11_ssvalues[c11_i38];
    }

    c11_mldivide(c11_b_ssvectors, c11_b_ssvalues, c11_dv2);
    for (c11_i39 = 0; c11_i39 < 3; c11_i39 = c11_i39 + 1) {
      c11_v_Sun1[c11_i39] = c11_dv2[c11_i39];
    }

    _SFD_EML_CALL(0,80);
    for (c11_i40 = 0; c11_i40 < 3; c11_i40 = c11_i40 + 1) {
      c11_b_v_Sun1[c11_i40] = c11_v_Sun1[c11_i40];
    }

    for (c11_i41 = 0; c11_i41 < 3; c11_i41 = c11_i41 + 1) {
      c11_c_v_Sun1[c11_i41] = c11_v_Sun1[c11_i41];
    }

    for (c11_i42 = 0; c11_i42 < 3; c11_i42 = c11_i42 + 1) {
      c11_d_v_Sun1[c11_i42] = c11_v_Sun1[c11_i42];
    }

    c11_b_mrdivide(c11_d_v_Sun1, c11_sqrt(c11_dot(c11_b_v_Sun1, c11_c_v_Sun1)),
                   c11_dv3);
    for (c11_i43 = 0; c11_i43 < 3; c11_i43 = c11_i43 + 1) {
      c11_v_Sun1[c11_i43] = c11_dv3[c11_i43];
    }

    _SFD_EML_CALL(0,81);
    for (c11_i44 = 0; c11_i44 < 3; c11_i44 = c11_i44 + 1) {
      c11_e_v_Sun1[c11_i44] = c11_v_Sun1[c11_i44];
    }

    for (c11_i45 = 0; c11_i45 < 3; c11_i45 = c11_i45 + 1) {
      c11_f_v_Sun1[c11_i45] = c11_v_Sun1[c11_i45];
    }

    for (c11_i46 = 0; c11_i46 < 3; c11_i46 = c11_i46 + 1) {
      c11_g_v_Sun1[c11_i46] = c11_v_Sun1[c11_i46];
    }

    c11_b_mrdivide(c11_g_v_Sun1, c11_sqrt(c11_dot(c11_e_v_Sun1, c11_f_v_Sun1)),
                   c11_dv4);
    for (c11_i47 = 0; c11_i47 < 3; c11_i47 = c11_i47 + 1) {
      c11_v_Sb_m[c11_i47] = c11_dv4[c11_i47];
    }

    /* %%% start TRIAD %%%% */
    _SFD_EML_CALL(0,85);
    for (c11_i48 = 0; c11_i48 < 3; c11_i48 = c11_i48 + 1) {
      c11_b1[c11_i48] = c11_v_Bb_m[c11_i48];
    }

    _SFD_EML_CALL(0,86);
    for (c11_i49 = 0; c11_i49 < 3; c11_i49 = c11_i49 + 1) {
      c11_b2[c11_i49] = c11_v_Sb_m[c11_i49];
    }

    _SFD_EML_CALL(0,87);
    for (c11_i50 = 0; c11_i50 < 3; c11_i50 = c11_i50 + 1) {
      c11_r1[c11_i50] = c11_v_Bo_c[c11_i50];
    }

    _SFD_EML_CALL(0,88);
    for (c11_i51 = 0; c11_i51 < 3; c11_i51 = c11_i51 + 1) {
      c11_r2[c11_i51] = c11_v_So_c[c11_i51];
    }

    _SFD_EML_CALL(0,90);
    c11_a1 = c11_b_s_MAGMETER_WEIGHT;
    _SFD_EML_CALL(0,91);
    c11_a2 = 9.9999999999999978E-002;

    /* b3 */
    _SFD_EML_CALL(0,94);
    for (c11_i52 = 0; c11_i52 < 3; c11_i52 = c11_i52 + 1) {
      c11_b_b1[c11_i52] = c11_b1[c11_i52];
    }

    for (c11_i53 = 0; c11_i53 < 3; c11_i53 = c11_i53 + 1) {
      c11_b_b2[c11_i53] = c11_b2[c11_i53];
    }

    c11_cross(c11_b_b1, c11_b_b2, c11_dv5);
    for (c11_i54 = 0; c11_i54 < 3; c11_i54 = c11_i54 + 1) {
      c11_b3[c11_i54] = c11_dv5[c11_i54];
    }

    _SFD_EML_CALL(0,95);
    for (c11_i55 = 0; c11_i55 < 3; c11_i55 = c11_i55 + 1) {
      c11_b_b3[c11_i55] = c11_b3[c11_i55];
    }

    for (c11_i56 = 0; c11_i56 < 3; c11_i56 = c11_i56 + 1) {
      c11_c_b3[c11_i56] = c11_b3[c11_i56];
    }

    c11_b_mrdivide(c11_c_b3, c11_b_norm(c11_b_b3), c11_dv6);
    for (c11_i57 = 0; c11_i57 < 3; c11_i57 = c11_i57 + 1) {
      c11_b3[c11_i57] = c11_dv6[c11_i57];
    }

    /* r3 */
    _SFD_EML_CALL(0,97);
    for (c11_i58 = 0; c11_i58 < 3; c11_i58 = c11_i58 + 1) {
      c11_b_r1[c11_i58] = c11_r1[c11_i58];
    }

    for (c11_i59 = 0; c11_i59 < 3; c11_i59 = c11_i59 + 1) {
      c11_b_r2[c11_i59] = c11_r2[c11_i59];
    }

    c11_cross(c11_b_r1, c11_b_r2, c11_dv7);
    for (c11_i60 = 0; c11_i60 < 3; c11_i60 = c11_i60 + 1) {
      c11_r3[c11_i60] = c11_dv7[c11_i60];
    }

    _SFD_EML_CALL(0,98);
    for (c11_i61 = 0; c11_i61 < 3; c11_i61 = c11_i61 + 1) {
      c11_b_r3[c11_i61] = c11_r3[c11_i61];
    }

    for (c11_i62 = 0; c11_i62 < 3; c11_i62 = c11_i62 + 1) {
      c11_c_r3[c11_i62] = c11_r3[c11_i62];
    }

    c11_b_mrdivide(c11_c_r3, c11_b_norm(c11_b_r3), c11_dv8);
    for (c11_i63 = 0; c11_i63 < 3; c11_i63 = c11_i63 + 1) {
      c11_r3[c11_i63] = c11_dv8[c11_i63];
    }

    /* mu */
    _SFD_EML_CALL(0,101);
    for (c11_i64 = 0; c11_i64 < 3; c11_i64 = c11_i64 + 1) {
      c11_d_b3[c11_i64] = c11_b3[c11_i64];
    }

    for (c11_i65 = 0; c11_i65 < 3; c11_i65 = c11_i65 + 1) {
      c11_d_r3[c11_i65] = c11_r3[c11_i65];
    }

    c11_b_a = 1.0 + c11_dot(c11_d_b3, c11_d_r3);
    for (c11_i66 = 0; c11_i66 < 3; c11_i66 = c11_i66 + 1) {
      c11_c_b2[c11_i66] = c11_b2[c11_i66];
    }

    for (c11_i67 = 0; c11_i67 < 3; c11_i67 = c11_i67 + 1) {
      c11_c_r2[c11_i67] = c11_r2[c11_i67];
    }

    c11_c_b = c11_dot(c11_c_b2, c11_c_r2);
    c11_c_y = 9.9999999999999978E-002 * c11_c_b;
    for (c11_i68 = 0; c11_i68 < 3; c11_i68 = c11_i68 + 1) {
      c11_c_b1[c11_i68] = c11_b1[c11_i68];
    }

    for (c11_i69 = 0; c11_i69 < 3; c11_i69 = c11_i69 + 1) {
      c11_c_r1[c11_i69] = c11_r1[c11_i69];
    }

    c11_d_b = c11_dot(c11_c_b1, c11_c_r1);
    c11_d_y = 0.9 * c11_d_b;
    c11_e_b = c11_d_y + c11_c_y;
    c11_mu = c11_b_a * c11_e_b;
    _SFD_EML_CALL(0,102);
    for (c11_i70 = 0; c11_i70 < 3; c11_i70 = c11_i70 + 1) {
      c11_d_b2[c11_i70] = c11_b2[c11_i70];
    }

    for (c11_i71 = 0; c11_i71 < 3; c11_i71 = c11_i71 + 1) {
      c11_d_r2[c11_i71] = c11_r2[c11_i71];
    }

    c11_cross(c11_d_b2, c11_d_r2, c11_f_b);
    for (c11_i72 = 0; c11_i72 < 3; c11_i72 = c11_i72 + 1) {
      c11_e_y[c11_i72] = 9.9999999999999978E-002 * c11_f_b[c11_i72];
    }

    for (c11_i73 = 0; c11_i73 < 3; c11_i73 = c11_i73 + 1) {
      c11_d_b1[c11_i73] = c11_b1[c11_i73];
    }

    for (c11_i74 = 0; c11_i74 < 3; c11_i74 = c11_i74 + 1) {
      c11_d_r1[c11_i74] = c11_r1[c11_i74];
    }

    c11_cross(c11_d_b1, c11_d_r1, c11_g_b);
    for (c11_i75 = 0; c11_i75 < 3; c11_i75 = c11_i75 + 1) {
      c11_f_y[c11_i75] = c11_b_s_MAGMETER_WEIGHT * c11_g_b[c11_i75];
    }

    for (c11_i76 = 0; c11_i76 < 3; c11_i76 = c11_i76 + 1) {
      c11_e_b3[c11_i76] = c11_b3[c11_i76];
    }

    for (c11_i77 = 0; c11_i77 < 3; c11_i77 = c11_i77 + 1) {
      c11_e_r3[c11_i77] = c11_r3[c11_i77];
    }

    c11_cross(c11_e_b3, c11_e_r3, c11_dv9);
    for (c11_i78 = 0; c11_i78 < 3; c11_i78 = c11_i78 + 1) {
      c11_dv10[c11_i78] = c11_dv9[c11_i78];
    }

    for (c11_i79 = 0; c11_i79 < 3; c11_i79 = c11_i79 + 1) {
      c11_g_y[c11_i79] = c11_f_y[c11_i79] + c11_e_y[c11_i79];
    }

    c11_mu = c11_mu + c11_dot(c11_dv10, c11_g_y);

    /* nu */
    _SFD_EML_CALL(0,105);
    for (c11_i80 = 0; c11_i80 < 3; c11_i80 = c11_i80 + 1) {
      c11_e_b2[c11_i80] = c11_b2[c11_i80];
    }

    for (c11_i81 = 0; c11_i81 < 3; c11_i81 = c11_i81 + 1) {
      c11_e_r2[c11_i81] = c11_r2[c11_i81];
    }

    c11_cross(c11_e_b2, c11_e_r2, c11_h_b);
    for (c11_i82 = 0; c11_i82 < 3; c11_i82 = c11_i82 + 1) {
      c11_h_y[c11_i82] = 9.9999999999999978E-002 * c11_h_b[c11_i82];
    }

    for (c11_i83 = 0; c11_i83 < 3; c11_i83 = c11_i83 + 1) {
      c11_e_b1[c11_i83] = c11_b1[c11_i83];
    }

    for (c11_i84 = 0; c11_i84 < 3; c11_i84 = c11_i84 + 1) {
      c11_e_r1[c11_i84] = c11_r1[c11_i84];
    }

    c11_cross(c11_e_b1, c11_e_r1, c11_i_b);
    for (c11_i85 = 0; c11_i85 < 3; c11_i85 = c11_i85 + 1) {
      c11_i_y[c11_i85] = c11_b_s_MAGMETER_WEIGHT * c11_i_b[c11_i85];
    }

    for (c11_i86 = 0; c11_i86 < 3; c11_i86 = c11_i86 + 1) {
      c11_f_b3[c11_i86] = c11_b3[c11_i86] + c11_r3[c11_i86];
    }

    for (c11_i87 = 0; c11_i87 < 3; c11_i87 = c11_i87 + 1) {
      c11_j_y[c11_i87] = c11_i_y[c11_i87] + c11_h_y[c11_i87];
    }

    c11_nu = c11_dot(c11_f_b3, c11_j_y);

    /* rho */
    _SFD_EML_CALL(0,108);
    c11_c_a = c11_nu;
    c11_j_b = c11_nu;
    c11_k_y = c11_c_a * c11_j_b;
    c11_d_a = c11_mu;
    c11_k_b = c11_mu;
    c11_l_y = c11_d_a * c11_k_b;
    c11_rho = c11_sqrt(c11_l_y + c11_k_y);

    /* q */
    _SFD_EML_CALL(0,111);
    if (CV_EML_IF(0, 3, c11_mu > 0.0)) {
      _SFD_EML_CALL(0,112);
      c11_e_a = c11_rho;
      c11_l_b = c11_rho + c11_mu;
      c11_f_a = c11_e_a * c11_l_b;
      for (c11_i88 = 0; c11_i88 < 3; c11_i88 = c11_i88 + 1) {
        c11_g_b3[c11_i88] = c11_b3[c11_i88];
      }

      for (c11_i89 = 0; c11_i89 < 3; c11_i89 = c11_i89 + 1) {
        c11_f_r3[c11_i89] = c11_r3[c11_i89];
      }

      c11_m_b = 1.0 + c11_dot(c11_g_b3, c11_f_r3);
      c11_m_y = c11_f_a * c11_m_b;
      c11_n_b = c11_sqrt(c11_m_y);
      c11_n_y = 2.0 * c11_n_b;
      c11_k_q_triad = c11_mrdivide(1.0, c11_n_y);
      _SFD_EML_CALL(0,113);
      c11_g_a = c11_nu;
      for (c11_i90 = 0; c11_i90 < 3; c11_i90 = c11_i90 + 1) {
        c11_o_b[c11_i90] = c11_b3[c11_i90] + c11_r3[c11_i90];
      }

      for (c11_i91 = 0; c11_i91 < 3; c11_i91 = c11_i91 + 1) {
        c11_o_y[c11_i91] = c11_g_a * c11_o_b[c11_i91];
      }

      c11_h_a = c11_rho + c11_mu;
      for (c11_i92 = 0; c11_i92 < 3; c11_i92 = c11_i92 + 1) {
        c11_h_b3[c11_i92] = c11_b3[c11_i92];
      }

      for (c11_i93 = 0; c11_i93 < 3; c11_i93 = c11_i93 + 1) {
        c11_g_r3[c11_i93] = c11_r3[c11_i93];
      }

      c11_cross(c11_h_b3, c11_g_r3, c11_p_b);
      for (c11_i94 = 0; c11_i94 < 3; c11_i94 = c11_i94 + 1) {
        c11_p_y[c11_i94] = c11_h_a * c11_p_b[c11_i94];
      }

      for (c11_i95 = 0; c11_i95 < 3; c11_i95 = c11_i95 + 1) {
        c11_v_q_triad[c11_i95] = c11_p_y[c11_i95] + c11_o_y[c11_i95];
      }

      _SFD_EML_CALL(0,114);
      c11_i_a = c11_rho + c11_mu;
      for (c11_i96 = 0; c11_i96 < 3; c11_i96 = c11_i96 + 1) {
        c11_i_b3[c11_i96] = c11_b3[c11_i96];
      }

      for (c11_i97 = 0; c11_i97 < 3; c11_i97 = c11_i97 + 1) {
        c11_h_r3[c11_i97] = c11_r3[c11_i97];
      }

      c11_q_b = 1.0 + c11_dot(c11_i_b3, c11_h_r3);
      c11_s_q_triad = c11_i_a * c11_q_b;
      _SFD_EML_CALL(0,115);
      for (c11_i98 = 0; c11_i98 < 3; c11_i98 = c11_i98 + 1) {
        c11_q_triad[c11_i98] = c11_v_q_triad[c11_i98];
      }

      c11_q_triad[3] = c11_s_q_triad;
      _SFD_EML_CALL(0,116);
      c11_j_a = c11_k_q_triad;
      for (c11_i99 = 0; c11_i99 < 4; c11_i99 = c11_i99 + 1) {
        c11_r_b[c11_i99] = c11_q_triad[c11_i99];
      }

      for (c11_i100 = 0; c11_i100 < 4; c11_i100 = c11_i100 + 1) {
        c11_q_triad[c11_i100] = c11_j_a * c11_r_b[c11_i100];
      }
    } else {
      _SFD_EML_CALL(0,118);
      c11_k_a = c11_rho;
      c11_s_b = c11_rho - c11_mu;
      c11_l_a = c11_k_a * c11_s_b;
      for (c11_i101 = 0; c11_i101 < 3; c11_i101 = c11_i101 + 1) {
        c11_j_b3[c11_i101] = c11_b3[c11_i101];
      }

      for (c11_i102 = 0; c11_i102 < 3; c11_i102 = c11_i102 + 1) {
        c11_i_r3[c11_i102] = c11_r3[c11_i102];
      }

      c11_t_b = 1.0 + c11_dot(c11_j_b3, c11_i_r3);
      c11_q_y = c11_l_a * c11_t_b;
      c11_u_b = c11_sqrt(c11_q_y);
      c11_r_y = 2.0 * c11_u_b;
      c11_k_q_triad = c11_mrdivide(1.0, c11_r_y);
      _SFD_EML_CALL(0,119);
      c11_m_a = c11_rho - c11_mu;
      for (c11_i103 = 0; c11_i103 < 3; c11_i103 = c11_i103 + 1) {
        c11_v_b[c11_i103] = c11_b3[c11_i103] + c11_r3[c11_i103];
      }

      for (c11_i104 = 0; c11_i104 < 3; c11_i104 = c11_i104 + 1) {
        c11_s_y[c11_i104] = c11_m_a * c11_v_b[c11_i104];
      }

      c11_n_a = c11_nu;
      for (c11_i105 = 0; c11_i105 < 3; c11_i105 = c11_i105 + 1) {
        c11_k_b3[c11_i105] = c11_b3[c11_i105];
      }

      for (c11_i106 = 0; c11_i106 < 3; c11_i106 = c11_i106 + 1) {
        c11_j_r3[c11_i106] = c11_r3[c11_i106];
      }

      c11_cross(c11_k_b3, c11_j_r3, c11_w_b);
      for (c11_i107 = 0; c11_i107 < 3; c11_i107 = c11_i107 + 1) {
        c11_t_y[c11_i107] = c11_n_a * c11_w_b[c11_i107];
      }

      for (c11_i108 = 0; c11_i108 < 3; c11_i108 = c11_i108 + 1) {
        c11_v_q_triad[c11_i108] = c11_t_y[c11_i108] + c11_s_y[c11_i108];
      }

      _SFD_EML_CALL(0,120);
      c11_o_a = c11_nu;
      for (c11_i109 = 0; c11_i109 < 3; c11_i109 = c11_i109 + 1) {
        c11_l_b3[c11_i109] = c11_b3[c11_i109];
      }

      for (c11_i110 = 0; c11_i110 < 3; c11_i110 = c11_i110 + 1) {
        c11_k_r3[c11_i110] = c11_r3[c11_i110];
      }

      c11_x_b = 1.0 + c11_dot(c11_l_b3, c11_k_r3);
      c11_s_q_triad = c11_o_a * c11_x_b;
      _SFD_EML_CALL(0,121);
      for (c11_i111 = 0; c11_i111 < 3; c11_i111 = c11_i111 + 1) {
        c11_q_triad[c11_i111] = c11_v_q_triad[c11_i111];
      }

      c11_q_triad[3] = c11_s_q_triad;
      _SFD_EML_CALL(0,122);
      c11_p_a = c11_k_q_triad;
      for (c11_i112 = 0; c11_i112 < 4; c11_i112 = c11_i112 + 1) {
        c11_y_b[c11_i112] = c11_q_triad[c11_i112];
      }

      for (c11_i113 = 0; c11_i113 < 4; c11_i113 = c11_i113 + 1) {
        c11_q_triad[c11_i113] = c11_p_a * c11_y_b[c11_i113];
      }
    }

    _SFD_EML_CALL(0,125);
    for (c11_i114 = 0; c11_i114 < 4; c11_i114 = c11_i114 + 1) {
      c11_A[c11_i114] = c11_q_triad[c11_i114];
    }

    for (c11_i115 = 0; c11_i115 < 4; c11_i115 = c11_i115 + 1) {
      c11_q_a[c11_i115] = c11_q_triad[c11_i115];
    }

    for (c11_i116 = 0; c11_i116 < 4; c11_i116 = c11_i116 + 1) {
      c11_ab_b[c11_i116] = c11_q_triad[c11_i116];
    }

    c11_b_eml_scalar_eg();
    for (c11_i117 = 0; c11_i117 < 4; c11_i117 = c11_i117 + 1) {
      c11_r_a[c11_i117] = c11_q_a[c11_i117];
    }

    for (c11_i118 = 0; c11_i118 < 4; c11_i118 = c11_i118 + 1) {
      c11_bb_b[c11_i118] = c11_ab_b[c11_i118];
    }

    for (c11_i119 = 0; c11_i119 < 4; c11_i119 = c11_i119 + 1) {
      c11_c_x[c11_i119] = c11_r_a[c11_i119];
    }

    for (c11_i120 = 0; c11_i120 < 4; c11_i120 = c11_i120 + 1) {
      c11_u_y[c11_i120] = c11_bb_b[c11_i120];
    }

    for (c11_i121 = 0; c11_i121 < 4; c11_i121 = c11_i121 + 1) {
      c11_d_x[c11_i121] = c11_c_x[c11_i121];
    }

    for (c11_i122 = 0; c11_i122 < 4; c11_i122 = c11_i122 + 1) {
      c11_v_y[c11_i122] = c11_u_y[c11_i122];
    }

    for (c11_i123 = 0; c11_i123 < 4; c11_i123 = c11_i123 + 1) {
      c11_e_x[c11_i123] = c11_d_x[c11_i123];
    }

    for (c11_i124 = 0; c11_i124 < 4; c11_i124 = c11_i124 + 1) {
      c11_w_y[c11_i124] = c11_v_y[c11_i124];
    }

    for (c11_i125 = 0; c11_i125 < 4; c11_i125 = c11_i125 + 1) {
      c11_f_x[c11_i125] = c11_e_x[c11_i125];
    }

    for (c11_i126 = 0; c11_i126 < 4; c11_i126 = c11_i126 + 1) {
      c11_x_y[c11_i126] = c11_w_y[c11_i126];
    }

    c11_g_x = c11_b_ceval_xdot(4, c11_f_x, 1, 1, c11_x_y, 1, 1);
    c11_B = c11_g_x;
    if (c11_B < 0.0) {
      c11_b_eml_error();
    }

    c11_h_x = c11_B;
    c11_B = c11_h_x;
    c11_B = muDoubleScalarSqrt(c11_B);
    for (c11_i127 = 0; c11_i127 < 4; c11_i127 = c11_i127 + 1) {
      c11_i_x[c11_i127] = c11_A[c11_i127];
    }

    c11_y_y = c11_B;
    if (c11_y_y == 0.0) {
      c11_eml_warning();
    }

    for (c11_i128 = 0; c11_i128 < 4; c11_i128 = c11_i128 + 1) {
      c11_j_x[c11_i128] = c11_i_x[c11_i128];
    }

    c11_ab_y = c11_y_y;
    for (c11_i129 = 0; c11_i129 < 4; c11_i129 = c11_i129 + 1) {
      c11_k_x[c11_i129] = c11_j_x[c11_i129];
    }

    c11_bb_y = c11_ab_y;
    for (c11_i130 = 0; c11_i130 < 4; c11_i130 = c11_i130 + 1) {
      c11_q_triad[c11_i130] = c11_k_x[c11_i130] / c11_bb_y;
    }

    _SFD_EML_CALL(0,126);
    for (c11_i131 = 0; c11_i131 < 4; c11_i131 = c11_i131 + 1) {
      c11_q_BO_est[c11_i131] = c11_q_triad[c11_i131];
    }
  } else {
    _SFD_EML_CALL(0,128);
    for (c11_i132 = 0; c11_i132 < 3; c11_i132 = c11_i132 + 1) {
      c11_v_Sun1[c11_i132] = c11_dv11[c11_i132];
    }

    _SFD_EML_CALL(0,129);
    for (c11_i133 = 0; c11_i133 < 4; c11_i133 = c11_i133 + 1) {
      c11_q_BO_est[c11_i133] = c11_dv12[c11_i133];
    }

    _SFD_EML_CALL(0,130);
    c11_flag_sum = 0.0;
  }

  _SFD_EML_CALL(0,-130);
  sf_debug_symbol_scope_pop();
  for (c11_i134 = 0; c11_i134 < 4; c11_i134 = c11_i134 + 1) {
    (*c11_b_q_BO_est)[c11_i134] = c11_q_BO_est[c11_i134];
  }

  *c11_b_light_est = c11_light_est;
  for (c11_i135 = 0; c11_i135 < 3; c11_i135 = c11_i135 + 1) {
    (*c11_h_v_Sun1)[c11_i135] = c11_v_Sun1[c11_i135];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static real_T c11_mrdivide(real_T c11_A, real_T c11_B)
{
  real_T c11_x;
  real_T c11_b_y;
  real_T c11_b_x;
  real_T c11_c_y;
  real_T c11_c_x;
  real_T c11_d_y;
  c11_x = c11_A;
  c11_b_y = c11_B;
  if (c11_b_y == 0.0) {
    c11_eml_warning();
  }

  c11_b_x = c11_x;
  c11_c_y = c11_b_y;
  c11_c_x = c11_b_x;
  c11_d_y = c11_c_y;
  return c11_c_x / c11_d_y;
}

static void c11_eml_warning(void)
{
  int32_T c11_i136;
  static char_T c11_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c11_u[15];
  const mxArray *c11_y = NULL;
  int32_T c11_i137;
  static char_T c11_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c11_b_u[19];
  const mxArray *c11_b_y = NULL;
  for (c11_i136 = 0; c11_i136 < 15; c11_i136 = c11_i136 + 1) {
    c11_u[c11_i136] = c11_cv0[c11_i136];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c11_i137 = 0; c11_i137 < 19; c11_i137 = c11_i137 + 1) {
    c11_b_u[c11_i137] = c11_cv1[c11_i137];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c11_b_y, 14, c11_y);
}

static void c11_sort(real_T c11_x[6], real_T c11_b_x[6], real_T c11_idx[6])
{
  int32_T c11_i138;
  int32_T c11_i139;
  real_T c11_c_x[6];
  int32_T c11_i140;
  real_T c11_d_x[6];
  int32_T c11_i141;
  real_T c11_e_x[6];
  int32_T c11_iidx[6];
  int32_T c11_i142;
  real_T c11_b_idx[6];
  int32_T c11_i143;
  real_T c11_f_x[6];
  int32_T c11_i144;
  int32_T c11_i145;
  int32_T c11_i146;
  for (c11_i138 = 0; c11_i138 < 6; c11_i138 = c11_i138 + 1) {
    c11_b_x[c11_i138] = c11_x[c11_i138];
  }

  for (c11_i139 = 0; c11_i139 < 6; c11_i139 = c11_i139 + 1) {
    c11_c_x[c11_i139] = c11_b_x[c11_i139];
  }

  for (c11_i140 = 0; c11_i140 < 6; c11_i140 = c11_i140 + 1) {
    c11_d_x[c11_i140] = c11_c_x[c11_i140];
  }

  for (c11_i141 = 0; c11_i141 < 6; c11_i141 = c11_i141 + 1) {
    c11_e_x[c11_i141] = c11_d_x[c11_i141];
  }

  c11_eml_sort_idx(c11_e_x, c11_iidx);
  for (c11_i142 = 0; c11_i142 < 6; c11_i142 = c11_i142 + 1) {
    c11_b_idx[c11_i142] = (real_T)c11_iidx[c11_i142];
  }

  for (c11_i143 = 0; c11_i143 < 6; c11_i143 = c11_i143 + 1) {
    c11_f_x[c11_i143] = c11_d_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c11_iidx[c11_i143]), 1, 6, 1, 0
      ) - 1];
  }

  for (c11_i144 = 0; c11_i144 < 6; c11_i144 = c11_i144 + 1) {
    c11_d_x[c11_i144] = c11_f_x[c11_i144];
  }

  for (c11_i145 = 0; c11_i145 < 6; c11_i145 = c11_i145 + 1) {
    c11_b_x[c11_i145] = c11_d_x[c11_i145];
  }

  for (c11_i146 = 0; c11_i146 < 6; c11_i146 = c11_i146 + 1) {
    c11_idx[c11_i146] = c11_b_idx[c11_i146];
  }
}

static void c11_eml_sort_idx(real_T c11_x[6], int32_T c11_idx[6])
{
  int32_T c11_i147;
  int32_T c11_idx0[6];
  int32_T c11_i148;
  int32_T c11_k;
  int32_T c11_b_k;
  int32_T c11_i149;
  real_T c11_v[6];
  int32_T c11_irow1;
  int32_T c11_a;
  int32_T c11_irow2;
  real_T c11_b_a;
  real_T c11_b;
  real_T c11_b_x;
  boolean_T c11_b_b;
  boolean_T c11_b0;
  boolean_T c11_p;
  int32_T c11_c_a;
  int32_T c11_c;
  int32_T c11_d_a;
  int32_T c11_b_c;
  int32_T c11_i;
  int32_T c11_e_a;
  int32_T c11_i2;
  int32_T c11_j;
  int32_T c11_c_b;
  int32_T c11_pEnd;
  int32_T c11_b_p;
  int32_T c11_q;
  int32_T c11_f_a;
  int32_T c11_d_b;
  int32_T c11_qEnd;
  int32_T c11_g_a;
  int32_T c11_e_b;
  int32_T c11_kEnd;
  int32_T c11_i150;
  real_T c11_b_v[6];
  int32_T c11_b_irow1;
  int32_T c11_b_irow2;
  real_T c11_h_a;
  real_T c11_f_b;
  real_T c11_c_x;
  boolean_T c11_g_b;
  boolean_T c11_b1;
  boolean_T c11_c_p;
  int32_T c11_i_a;
  int32_T c11_j_a;
  int32_T c11_k_a;
  int32_T c11_l_a;
  int32_T c11_m_a;
  int32_T c11_n_a;
  int32_T c11_o_a;
  int32_T c11_p_a;
  int32_T c11_c_k;
  int32_T c11_q_a;
  int32_T c11_h_b;
  int32_T c11_c_c;
  int32_T c11_r_a;
  int32_T c11_i_b;
  for (c11_i147 = 0; c11_i147 < 6; c11_i147 = c11_i147 + 1) {
    c11_idx0[c11_i147] = 1;
  }

  for (c11_i148 = 0; c11_i148 < 6; c11_i148 = c11_i148 + 1) {
    c11_idx[c11_i148] = 1 + c11_i148;
  }

  for (c11_k = 1; c11_k < 6; c11_k = c11_k + 2) {
    c11_b_k = c11_k;
    for (c11_i149 = 0; c11_i149 < 6; c11_i149 = c11_i149 + 1) {
      c11_v[c11_i149] = c11_x[c11_i149];
    }

    c11_irow1 = c11_b_k;
    c11_a = c11_b_k;
    c11_irow2 = c11_a + 1;
    c11_b_a = c11_v[_SFD_EML_ARRAY_BOUNDS_CHECK("v", (int32_T)_SFD_INTEGER_CHECK
      ("irow1", (real_T)c11_irow1), 1, 6, 1, 0) - 1];
    c11_b = c11_v[_SFD_EML_ARRAY_BOUNDS_CHECK("v", (int32_T)_SFD_INTEGER_CHECK(
      "irow2", (real_T)c11_irow2), 1, 6, 1, 0) - 1];
    if (c11_b_a <= c11_b) {
    } else {
      c11_b_x = c11_b;
      c11_b_b = rtIsNaN(c11_b_x);
      if (c11_b_b) {
      } else {
        c11_b0 = false;
        goto label_1;
      }
    }

    c11_b0 = true;
   label_1:
    ;
    c11_p = c11_b0;
    if (c11_p) {
    } else {
      c11_c_a = c11_b_k;
      c11_c = c11_c_a + 1;
      c11_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK("k",
        (real_T)c11_b_k), 1, 6, 1, 0) - 1] = c11_c;
      c11_d_a = c11_b_k;
      c11_b_c = c11_d_a + 1;
      c11_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c11_b_c), 1, 6, 1, 0) - 1] = c11_b_k;
    }
  }

  for (c11_i = 2; c11_i <= 6; c11_i = c11_i2) {
    c11_e_a = c11_i;
    c11_i2 = c11_e_a << 1;
    c11_j = 1;
    c11_c_b = c11_i;
    for (c11_pEnd = 1 + c11_c_b; c11_pEnd < 7; c11_pEnd = c11_r_a + c11_i_b) {
      c11_b_p = c11_j;
      c11_q = c11_pEnd;
      c11_f_a = c11_j;
      c11_d_b = c11_i2;
      c11_qEnd = c11_f_a + c11_d_b;
      if (c11_qEnd > 7) {
        c11_qEnd = 7;
      }

      c11_b_k = 1;
      c11_g_a = c11_qEnd;
      c11_e_b = c11_j;
      c11_kEnd = c11_g_a - c11_e_b;
      while (c11_b_k <= c11_kEnd) {
        for (c11_i150 = 0; c11_i150 < 6; c11_i150 = c11_i150 + 1) {
          c11_b_v[c11_i150] = c11_x[c11_i150];
        }

        c11_b_irow1 = c11_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)
          _SFD_INTEGER_CHECK("p", (real_T)c11_b_p), 1, 6, 1, 0) - 1];
        c11_b_irow2 = c11_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)
          _SFD_INTEGER_CHECK("q", (real_T)c11_q), 1, 6, 1, 0) - 1];
        c11_h_a = c11_b_v[_SFD_EML_ARRAY_BOUNDS_CHECK("v", (int32_T)
          _SFD_INTEGER_CHECK("irow1", (real_T)c11_b_irow1), 1, 6, 1, 0) - 1];
        c11_f_b = c11_b_v[_SFD_EML_ARRAY_BOUNDS_CHECK("v", (int32_T)
          _SFD_INTEGER_CHECK("irow2", (real_T)c11_b_irow2), 1, 6, 1, 0) - 1];
        if (c11_h_a <= c11_f_b) {
        } else {
          c11_c_x = c11_f_b;
          c11_g_b = rtIsNaN(c11_c_x);
          if (c11_g_b) {
          } else {
            c11_b1 = false;
            goto label_2;
          }
        }

        c11_b1 = true;
       label_2:
        ;
        c11_c_p = c11_b1;
        if (c11_c_p) {
          c11_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("idx0", (int32_T)
            _SFD_INTEGER_CHECK("k", (real_T)c11_b_k), 1, 6, 1, 0) - 1] =
            c11_idx[
            _SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK("p",
            (real_T)c11_b_p), 1, 6, 1, 0) - 1];
          c11_i_a = c11_b_p;
          c11_b_p = c11_i_a + 1;
          if (c11_b_p == c11_pEnd) {
            while (c11_q < c11_qEnd) {
              c11_j_a = c11_b_k;
              c11_b_k = c11_j_a + 1;
              c11_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("idx0", (int32_T)
                _SFD_INTEGER_CHECK("k", (real_T)c11_b_k), 1, 6, 1, 0) - 1] =
                c11_idx[
                _SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK(
                "q", (real_T)c11_q), 1, 6, 1, 0) - 1];
              c11_k_a = c11_q;
              c11_q = c11_k_a + 1;
            }
          }
        } else {
          c11_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("idx0", (int32_T)
            _SFD_INTEGER_CHECK("k", (real_T)c11_b_k), 1, 6, 1, 0) - 1] =
            c11_idx[
            _SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK("q",
            (real_T)c11_q), 1, 6, 1, 0) - 1];
          c11_l_a = c11_q;
          c11_q = c11_l_a + 1;
          if (c11_q == c11_qEnd) {
            while (c11_b_p < c11_pEnd) {
              c11_m_a = c11_b_k;
              c11_b_k = c11_m_a + 1;
              c11_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("idx0", (int32_T)
                _SFD_INTEGER_CHECK("k", (real_T)c11_b_k), 1, 6, 1, 0) - 1] =
                c11_idx[
                _SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK(
                "p", (real_T)c11_b_p), 1, 6, 1, 0) - 1];
              c11_n_a = c11_b_p;
              c11_b_p = c11_n_a + 1;
            }
          }
        }

        c11_o_a = c11_b_k;
        c11_b_k = c11_o_a + 1;
      }

      c11_p_a = c11_j;
      c11_b_p = c11_p_a - 1;
      for (c11_c_k = 1; c11_c_k <= c11_kEnd; c11_c_k = c11_c_k + 1) {
        c11_b_k = c11_c_k;
        c11_q_a = c11_b_p;
        c11_h_b = c11_b_k;
        c11_c_c = c11_q_a + c11_h_b;
        c11_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("idx", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c11_c_c), 1, 6, 1, 0) - 1] = c11_idx0[
          _SFD_EML_ARRAY_BOUNDS_CHECK("idx0", (int32_T)_SFD_INTEGER_CHECK("k",
          (real_T)c11_b_k), 1, 6, 1, 0) - 1];
      }

      c11_j = c11_qEnd;
      c11_r_a = c11_j;
      c11_i_b = c11_i;
    }
  }
}

static real_T c11_power(real_T c11_a, real_T c11_b)
{
  real_T c11_ak;
  real_T c11_bk;
  real_T c11_x;
  real_T c11_b_x;
  c11_ak = c11_a;
  c11_bk = c11_b;
  if (c11_ak < 0.0) {
    c11_x = c11_bk;
    c11_b_x = c11_x;
    c11_b_x = muDoubleScalarFloor(c11_b_x);
    if (c11_b_x != c11_bk) {
      c11_eml_error();
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c11_ak, c11_bk);
}

static void c11_eml_error(void)
{
  int32_T c11_i151;
  static char_T c11_cv2[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
    'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c11_u[102];
  const mxArray *c11_y = NULL;
  int32_T c11_i152;
  static char_T c11_cv3[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c11_b_u[32];
  const mxArray *c11_b_y = NULL;
  for (c11_i151 = 0; c11_i151 < 102; c11_i151 = c11_i151 + 1) {
    c11_u[c11_i151] = c11_cv2[c11_i151];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c11_i152 = 0; c11_i152 < 32; c11_i152 = c11_i152 + 1) {
    c11_b_u[c11_i152] = c11_cv3[c11_i152];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c11_b_y, 14, c11_y);
}

static real_T c11_norm(real_T c11_x[3])
{
  int32_T c11_i153;
  real_T c11_b_x[3];
  for (c11_i153 = 0; c11_i153 < 3; c11_i153 = c11_i153 + 1) {
    c11_b_x[c11_i153] = c11_x[c11_i153];
  }

  return c11_genpnorm(c11_b_x, 2.0);
}

static real_T c11_genpnorm(real_T c11_x[3], real_T c11_p)
{
  real_T c11_y;
  int32_T c11_i154;
  real_T c11_b_x[3];
  real_T c11_k;
  real_T c11_b_k;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_absx;
  real_T c11_e_x;
  boolean_T c11_b;
  real_T c11_c_k;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_b_y;
  real_T c11_d_k;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  boolean_T c11_b_b;
  int32_T c11_i155;
  real_T c11_k_x[3];
  real_T c11_b_p;
  real_T c11_scale;
  real_T c11_e_k;
  real_T c11_f_k;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_b_absx;
  real_T c11_n_x;
  boolean_T c11_c_b;
  real_T c11_o_x;
  boolean_T c11_d_b;
  real_T c11_d5;
  real_T c11_j;
  real_T c11_b_j;
  real_T c11_p_x;
  boolean_T c11_e_b;
  real_T c11_a;
  real_T c11_f_b;
  real_T c11_c_y;
  real_T c11_q_x;
  boolean_T c11_g_b;
  real_T c11_b_a;
  real_T c11_h_b;
  int32_T c11_i156;
  real_T c11_r_x[3];
  real_T c11_c_p;
  real_T c11_b_scale;
  real_T c11_g_k;
  real_T c11_h_k;
  real_T c11_s_x;
  real_T c11_t_x;
  real_T c11_c_absx;
  real_T c11_u_x;
  boolean_T c11_i_b;
  real_T c11_d6;
  real_T c11_c_j;
  real_T c11_d_j;
  real_T c11_v_x;
  boolean_T c11_j_b;
  real_T c11_c_a;
  real_T c11_k_b;
  real_T c11_d_y;
  real_T c11_w_x;
  boolean_T c11_l_b;
  real_T c11_x_x;
  boolean_T c11_m_b;
  real_T c11_d_a;
  real_T c11_e_a;
  real_T c11_n_b;
  real_T c11_o_b;
  if (c11_p == 2.0) {
    for (c11_i154 = 0; c11_i154 < 3; c11_i154 = c11_i154 + 1) {
      c11_b_x[c11_i154] = c11_x[c11_i154];
    }

    return c11_eml_xnrm2(c11_b_x);
  } else if (c11_p == rtInf) {
    c11_y = 0.0;
    c11_k = 1.0;
   label_1:
    ;
    if (c11_k <= 3.0) {
      c11_b_k = c11_k;
      c11_c_x = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_b_k), 1, 3, 1, 0) - 1];
      c11_d_x = c11_c_x;
      c11_absx = muDoubleScalarAbs(c11_d_x);
      c11_e_x = c11_absx;
      c11_b = rtIsNaN(c11_e_x);
      if (c11_b) {
        return rtNaN;
      } else {
        if (c11_absx > c11_y) {
          c11_y = c11_absx;
        }

        c11_k = c11_k + 1.0;
        goto label_1;
      }
    }
  } else if (c11_p == 1.0) {
    c11_y = 0.0;
    for (c11_c_k = 1.0; c11_c_k <= 3.0; c11_c_k = c11_c_k + 1.0) {
      c11_b_k = c11_c_k;
      c11_f_x = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_b_k), 1, 3, 1, 0) - 1];
      c11_g_x = c11_f_x;
      c11_b_y = muDoubleScalarAbs(c11_g_x);
      c11_y = c11_y + c11_b_y;
    }
  } else if (c11_p == rtMinusInf) {
    c11_y = rtInf;
    c11_d_k = 1.0;
   label_2:
    ;
    if (c11_d_k <= 3.0) {
      c11_b_k = c11_d_k;
      c11_h_x = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_b_k), 1, 3, 1, 0) - 1];
      c11_i_x = c11_h_x;
      c11_absx = muDoubleScalarAbs(c11_i_x);
      c11_j_x = c11_absx;
      c11_b_b = rtIsNaN(c11_j_x);
      if (c11_b_b) {
        return rtNaN;
      } else {
        if (c11_absx < c11_y) {
          c11_y = c11_absx;
        }

        c11_d_k = c11_d_k + 1.0;
        goto label_2;
      }
    }
  } else if (c11_p > 0.0) {
    for (c11_i155 = 0; c11_i155 < 3; c11_i155 = c11_i155 + 1) {
      c11_k_x[c11_i155] = c11_x[c11_i155];
    }

    c11_b_p = c11_p;
    c11_y = 0.0;
    c11_scale = 0.0;
    c11_e_k = 1.0;
   label_3:
    ;
    if (c11_e_k <= 3.0) {
      c11_f_k = c11_e_k;
      c11_l_x = c11_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_f_k), 1, 3, 1, 0) - 1];
      c11_m_x = c11_l_x;
      c11_b_absx = muDoubleScalarAbs(c11_m_x);
      c11_n_x = c11_b_absx;
      c11_c_b = rtIsNaN(c11_n_x);
      if (c11_c_b) {
        return rtNaN;
      } else {
        c11_o_x = c11_b_absx;
        c11_d_b = rtIsInf(c11_o_x);
        if (c11_d_b) {
          c11_y = rtInf;
          c11_d5 = c11_f_k + 1.0;
          c11_j = c11_d5;
        } else {
          if (c11_b_absx > 0.0) {
            if (c11_scale < c11_b_absx) {
              c11_a = c11_y;
              c11_f_b = c11_power(c11_scale / c11_b_absx, c11_b_p);
              c11_c_y = c11_a * c11_f_b;
              c11_y = 1.0 + c11_c_y;
              c11_scale = c11_b_absx;
            } else {
              c11_y = c11_y + c11_power(c11_b_absx / c11_scale, c11_b_p);
            }
          }

          c11_e_k = c11_e_k + 1.0;
          goto label_3;
        }
      }
    } else {
      if (c11_y > 0.0) {
        c11_q_x = c11_y;
        c11_g_b = rtIsInf(c11_q_x);
        if (!c11_g_b) {
          c11_b_a = c11_scale;
          c11_h_b = c11_power(c11_y, 1.0 / c11_b_p);
          return c11_b_a * c11_h_b;
        }
      }

      return c11_y;
    }

   label_4:
    ;
    if (c11_j <= 3.0) {
      c11_b_j = c11_j;
      c11_p_x = c11_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c11_b_j), 1, 3, 1, 0) - 1];
      c11_e_b = rtIsNaN(c11_p_x);
      if (c11_e_b) {
        return rtNaN;
      } else {
        c11_j = c11_j + 1.0;
        goto label_4;
      }
    }
  } else if (c11_p < 0.0) {
    for (c11_i156 = 0; c11_i156 < 3; c11_i156 = c11_i156 + 1) {
      c11_r_x[c11_i156] = c11_x[c11_i156];
    }

    c11_c_p = c11_p;
    c11_y = 0.0;
    c11_b_scale = rtInf;
    c11_g_k = 1.0;
   label_5:
    ;
    if (c11_g_k <= 3.0) {
      c11_h_k = c11_g_k;
      c11_s_x = c11_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_h_k), 1, 3, 1, 0) - 1];
      c11_t_x = c11_s_x;
      c11_c_absx = muDoubleScalarAbs(c11_t_x);
      c11_u_x = c11_c_absx;
      c11_i_b = rtIsNaN(c11_u_x);
      if (c11_i_b) {
        return rtNaN;
      } else if (c11_c_absx == 0.0) {
        c11_y = 0.0;
        c11_d6 = c11_h_k + 1.0;
        c11_c_j = c11_d6;
      } else {
        if (c11_c_absx < c11_b_scale) {
          c11_c_a = c11_y;
          c11_k_b = c11_power(c11_b_scale / c11_c_absx, c11_c_p);
          c11_d_y = c11_c_a * c11_k_b;
          c11_y = 1.0 + c11_d_y;
          c11_b_scale = c11_c_absx;
        } else {
          c11_w_x = c11_c_absx;
          c11_l_b = rtIsInf(c11_w_x);
          if (!c11_l_b) {
            c11_y = c11_y + c11_power(c11_c_absx / c11_b_scale, c11_c_p);
          }
        }

        c11_g_k = c11_g_k + 1.0;
        goto label_5;
      }
    } else {
      if (c11_y > 0.0) {
        c11_x_x = c11_y;
        c11_m_b = rtIsInf(c11_x_x);
        if (!c11_m_b) {
          c11_d_a = c11_b_scale;
          c11_e_a = c11_y;
          c11_n_b = 1.0 / c11_c_p;
          c11_o_b = c11_power(c11_e_a, c11_n_b);
          return c11_d_a * c11_o_b;
        }
      }

      return c11_y;
    }

   label_6:
    ;
    if (c11_c_j <= 3.0) {
      c11_d_j = c11_c_j;
      c11_v_x = c11_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c11_d_j), 1, 3, 1, 0) - 1];
      c11_j_b = rtIsNaN(c11_v_x);
      if (c11_j_b) {
        return rtNaN;
      } else {
        c11_c_j = c11_c_j + 1.0;
        goto label_6;
      }
    }
  } else if (c11_p == 0.0) {
    return rtInf;
  } else {
    return rtNaN;
  }

  return c11_y;
}

static real_T c11_eml_xnrm2(real_T c11_x[3])
{
  int32_T c11_i157;
  real_T c11_b_x[3];
  int32_T c11_i158;
  real_T c11_c_x[3];
  for (c11_i157 = 0; c11_i157 < 3; c11_i157 = c11_i157 + 1) {
    c11_b_x[c11_i157] = c11_x[c11_i157];
  }

  for (c11_i158 = 0; c11_i158 < 3; c11_i158 = c11_i158 + 1) {
    c11_c_x[c11_i158] = c11_b_x[c11_i158];
  }

  return c11_ceval_xnrm2(3, c11_c_x, 1.0, 1);
}

static real_T c11_ceval_xnrm2(int32_T c11_n, real_T c11_x[3], real_T c11_ix0,
  int32_T c11_incx)
{
  return dnrm232(&c11_n, &c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
    _SFD_INTEGER_CHECK("ix0", c11_ix0), 1, 3, 1, 0) - 1], &
                 c11_incx);
}

static void c11_mldivide(real_T c11_A[9], real_T c11_B[3], real_T c11_Y[3])
{
  int32_T c11_i159;
  real_T c11_b_A[9];
  int32_T c11_i160;
  real_T c11_b_B[3];
  int32_T c11_i161;
  real_T c11_c_A[9];
  int32_T c11_i162;
  real_T c11_c_B[3];
  int32_T c11_r1;
  int32_T c11_r2;
  int32_T c11_r3;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_y;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_b_y;
  real_T c11_maxval;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_c_y;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_d_y;
  real_T c11_a21;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_e_y;
  real_T c11_n_x;
  real_T c11_o_x;
  real_T c11_f_y;
  real_T c11_d;
  real_T c11_p_x;
  real_T c11_g_y;
  real_T c11_q_x;
  real_T c11_h_y;
  real_T c11_z;
  real_T c11_r_x;
  real_T c11_i_y;
  real_T c11_s_x;
  real_T c11_j_y;
  real_T c11_b_z;
  real_T c11_a;
  real_T c11_b;
  real_T c11_k_y;
  real_T c11_b_a;
  real_T c11_b_b;
  real_T c11_l_y;
  real_T c11_c_a;
  real_T c11_c_b;
  real_T c11_m_y;
  real_T c11_d_a;
  real_T c11_d_b;
  real_T c11_n_y;
  real_T c11_t_x;
  real_T c11_u_x;
  real_T c11_v_x;
  real_T c11_o_y;
  real_T c11_w_x;
  real_T c11_x_x;
  real_T c11_p_y;
  real_T c11_b_d;
  real_T c11_y_x;
  real_T c11_ab_x;
  real_T c11_bb_x;
  real_T c11_q_y;
  real_T c11_cb_x;
  real_T c11_db_x;
  real_T c11_r_y;
  real_T c11_c_d;
  int32_T c11_rtemp;
  real_T c11_eb_x;
  real_T c11_s_y;
  real_T c11_fb_x;
  real_T c11_t_y;
  real_T c11_c_z;
  real_T c11_e_a;
  real_T c11_e_b;
  real_T c11_u_y;
  real_T c11_f_a;
  real_T c11_f_b;
  real_T c11_v_y;
  real_T c11_g_a;
  real_T c11_g_b;
  real_T c11_w_y;
  real_T c11_h_a;
  real_T c11_h_b;
  real_T c11_x_y;
  real_T c11_gb_x;
  real_T c11_y_y;
  real_T c11_hb_x;
  real_T c11_ab_y;
  real_T c11_d_z;
  real_T c11_i_a;
  real_T c11_i_b;
  real_T c11_bb_y;
  real_T c11_j_a;
  real_T c11_j_b;
  real_T c11_cb_y;
  real_T c11_ib_x;
  real_T c11_db_y;
  real_T c11_jb_x;
  real_T c11_eb_y;
  real_T c11_e_z;
  real_T c11_k_a;
  real_T c11_k_b;
  real_T c11_fb_y;
  real_T c11_kb_x;
  real_T c11_gb_y;
  real_T c11_lb_x;
  real_T c11_hb_y;
  real_T c11_f_z;
  for (c11_i159 = 0; c11_i159 < 9; c11_i159 = c11_i159 + 1) {
    c11_b_A[c11_i159] = c11_A[c11_i159];
  }

  for (c11_i160 = 0; c11_i160 < 3; c11_i160 = c11_i160 + 1) {
    c11_b_B[c11_i160] = c11_B[c11_i160];
  }

  for (c11_i161 = 0; c11_i161 < 9; c11_i161 = c11_i161 + 1) {
    c11_c_A[c11_i161] = c11_b_A[c11_i161];
  }

  for (c11_i162 = 0; c11_i162 < 3; c11_i162 = c11_i162 + 1) {
    c11_c_B[c11_i162] = c11_b_B[c11_i162];
  }

  c11_r1 = 1;
  c11_r2 = 2;
  c11_r3 = 3;
  c11_x = c11_c_A[0];
  c11_b_x = 0.0;
  c11_c_x = c11_b_x;
  c11_y = muDoubleScalarAbs(c11_c_x);
  c11_d_x = c11_x;
  c11_e_x = c11_d_x;
  c11_b_y = muDoubleScalarAbs(c11_e_x);
  c11_maxval = c11_b_y + c11_y;
  c11_f_x = c11_c_A[1];
  c11_g_x = 0.0;
  c11_h_x = c11_g_x;
  c11_c_y = muDoubleScalarAbs(c11_h_x);
  c11_i_x = c11_f_x;
  c11_j_x = c11_i_x;
  c11_d_y = muDoubleScalarAbs(c11_j_x);
  c11_a21 = c11_d_y + c11_c_y;
  if (c11_a21 > c11_maxval) {
    c11_maxval = c11_a21;
    c11_r1 = 2;
    c11_r2 = 1;
  }

  c11_k_x = c11_c_A[2];
  c11_l_x = 0.0;
  c11_m_x = c11_l_x;
  c11_e_y = muDoubleScalarAbs(c11_m_x);
  c11_n_x = c11_k_x;
  c11_o_x = c11_n_x;
  c11_f_y = muDoubleScalarAbs(c11_o_x);
  c11_d = c11_f_y + c11_e_y;
  if (c11_d > c11_maxval) {
    c11_r1 = 3;
    c11_r2 = 2;
    c11_r3 = 1;
  }

  c11_p_x = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) - 1];
  c11_g_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) - 1];
  c11_q_x = c11_p_x;
  c11_h_y = c11_g_y;
  c11_z = c11_q_x / c11_h_y;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2",
    (real_T)c11_r2), 1, 3, 1, 0) - 1] = c11_z;
  c11_r_x = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) - 1];
  c11_i_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) - 1];
  c11_s_x = c11_r_x;
  c11_j_y = c11_i_y;
  c11_b_z = c11_s_x / c11_j_y;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c11_r3), 1, 3, 1, 0) - 1] = c11_b_z;
  c11_a = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c11_r2), 1, 3, 1, 0) - 1];
  c11_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c11_r1), 1, 3, 1, 0) + 2];
  c11_k_y = c11_a * c11_b;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2",
    (real_T)c11_r2), 1, 3, 1, 0) + 2] = c11_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2", (real_T)
    c11_r2), 1, 3, 1, 0) + 2] - c11_k_y;
  c11_b_a = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) - 1];
  c11_b_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) + 2];
  c11_l_y = c11_b_a * c11_b_b;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c11_r3), 1, 3, 1, 0) + 2] = c11_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3", (real_T)
    c11_r3), 1, 3, 1, 0) + 2] - c11_l_y;
  c11_c_a = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) - 1];
  c11_c_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) + 5];
  c11_m_y = c11_c_a * c11_c_b;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2",
    (real_T)c11_r2), 1, 3, 1, 0) + 5] = c11_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2", (real_T)
    c11_r2), 1, 3, 1, 0) + 5] - c11_m_y;
  c11_d_a = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) - 1];
  c11_d_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) + 5];
  c11_n_y = c11_d_a * c11_d_b;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c11_r3), 1, 3, 1, 0) + 5] = c11_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3", (real_T)
    c11_r3), 1, 3, 1, 0) + 5] - c11_n_y;
  c11_t_x = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) + 2];
  c11_u_x = 0.0;
  c11_v_x = c11_u_x;
  c11_o_y = muDoubleScalarAbs(c11_v_x);
  c11_w_x = c11_t_x;
  c11_x_x = c11_w_x;
  c11_p_y = muDoubleScalarAbs(c11_x_x);
  c11_b_d = c11_p_y + c11_o_y;
  c11_y_x = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) + 2];
  c11_ab_x = 0.0;
  c11_bb_x = c11_ab_x;
  c11_q_y = muDoubleScalarAbs(c11_bb_x);
  c11_cb_x = c11_y_x;
  c11_db_x = c11_cb_x;
  c11_r_y = muDoubleScalarAbs(c11_db_x);
  c11_c_d = c11_r_y + c11_q_y;
  if (c11_c_d > c11_b_d) {
    c11_rtemp = c11_r2;
    c11_r2 = c11_r3;
    c11_r3 = c11_rtemp;
  }

  c11_eb_x = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
    _SFD_INTEGER_CHECK("r3", (real_T)c11_r3), 1, 3, 1, 0) + 2];
  c11_s_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) + 2];
  c11_fb_x = c11_eb_x;
  c11_t_y = c11_s_y;
  c11_c_z = c11_fb_x / c11_t_y;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c11_r3), 1, 3, 1, 0) + 2] = c11_c_z;
  c11_e_a = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) + 2];
  c11_e_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) + 5];
  c11_u_y = c11_e_a * c11_e_b;
  c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c11_r3), 1, 3, 1, 0) + 5] = c11_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3", (real_T)
    c11_r3), 1, 3, 1, 0) + 5] - c11_u_y;
  if (c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r1",
        (real_T)c11_r1), 1, 3, 1, 0) - 1] == 0.0) {
  } else if (c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
              _SFD_INTEGER_CHECK("r2", (real_T)c11_r2), 1, 3, 1, 0) + 2] == 0.0)
  {
  } else if (c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
              _SFD_INTEGER_CHECK("r3", (real_T)c11_r3), 1, 3, 1, 0) + 5] == 0.0)
  {
    goto label_1;
  } else {
    goto label_2;
  }

 label_1:
  ;
  c11_b_eml_warning();
 label_2:
  ;
  c11_Y[0] = c11_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
    _SFD_INTEGER_CHECK("r1", (real_T)c11_r1), 1, 3, 1, 0) - 1];
  c11_f_a = c11_Y[0];
  c11_f_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) - 1];
  c11_v_y = c11_f_a * c11_f_b;
  c11_Y[1] = c11_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
    _SFD_INTEGER_CHECK("r2", (real_T)c11_r2), 1, 3, 1, 0) - 1] - c11_v_y;
  c11_g_a = c11_Y[1];
  c11_g_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) + 2];
  c11_w_y = c11_g_a * c11_g_b;
  c11_h_a = c11_Y[0];
  c11_h_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) - 1];
  c11_x_y = c11_h_a * c11_h_b;
  c11_Y[2] = (c11_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
    _SFD_INTEGER_CHECK("r3", (real_T)c11_r3), 1, 3, 1, 0) - 1] - c11_x_y)
    - c11_w_y;
  c11_gb_x = c11_Y[2];
  c11_y_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r3", (real_T)c11_r3), 1, 3, 1, 0) + 5];
  c11_hb_x = c11_gb_x;
  c11_ab_y = c11_y_y;
  c11_d_z = c11_hb_x / c11_ab_y;
  c11_Y[2] = c11_d_z;
  c11_i_a = c11_Y[2];
  c11_i_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) + 5];
  c11_bb_y = c11_i_a * c11_i_b;
  c11_Y[0] = c11_Y[0] - c11_bb_y;
  c11_j_a = c11_Y[2];
  c11_j_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r2", (real_T)c11_r2), 1, 3, 1, 0) + 5];
  c11_cb_y = c11_j_a * c11_j_b;
  c11_Y[1] = c11_Y[1] - c11_cb_y;
  c11_ib_x = c11_Y[1];
  c11_db_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
    _SFD_INTEGER_CHECK("r2", (real_T)c11_r2), 1, 3, 1, 0) + 2];
  c11_jb_x = c11_ib_x;
  c11_eb_y = c11_db_y;
  c11_e_z = c11_jb_x / c11_eb_y;
  c11_Y[1] = c11_e_z;
  c11_k_a = c11_Y[1];
  c11_k_b = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
    ("r1", (real_T)c11_r1), 1, 3, 1, 0) + 2];
  c11_fb_y = c11_k_a * c11_k_b;
  c11_Y[0] = c11_Y[0] - c11_fb_y;
  c11_kb_x = c11_Y[0];
  c11_gb_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
    _SFD_INTEGER_CHECK("r1", (real_T)c11_r1), 1, 3, 1, 0) - 1];
  c11_lb_x = c11_kb_x;
  c11_hb_y = c11_gb_y;
  c11_f_z = c11_lb_x / c11_hb_y;
  c11_Y[0] = c11_f_z;
}

static void c11_b_eml_warning(void)
{
  int32_T c11_i163;
  static char_T c11_cv4[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't',
    'o', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i',
    's', 'i', 'o', 'n', '.' };

  char_T c11_u[40];
  const mxArray *c11_y = NULL;
  int32_T c11_i164;
  static char_T c11_cv5[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i',
    'x' };

  char_T c11_b_u[21];
  const mxArray *c11_b_y = NULL;
  for (c11_i163 = 0; c11_i163 < 40; c11_i163 = c11_i163 + 1) {
    c11_u[c11_i163] = c11_cv4[c11_i163];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 1U, 0U, 2, 1, 40));
  for (c11_i164 = 0; c11_i164 < 21; c11_i164 = c11_i164 + 1) {
    c11_b_u[c11_i164] = c11_cv5[c11_i164];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 10, 0U, 1U, 0U, 2, 1, 21));
  sf_mex_call_debug("warning", 0U, 2U, 14, c11_b_y, 14, c11_y);
}

static real_T c11_dot(real_T c11_a[3], real_T c11_b[3])
{
  int32_T c11_i165;
  real_T c11_b_a[3];
  int32_T c11_i166;
  real_T c11_b_b[3];
  int32_T c11_i167;
  real_T c11_x[3];
  int32_T c11_i168;
  real_T c11_y[3];
  int32_T c11_i169;
  real_T c11_b_x[3];
  int32_T c11_i170;
  real_T c11_b_y[3];
  int32_T c11_i171;
  real_T c11_c_x[3];
  int32_T c11_i172;
  real_T c11_c_y[3];
  int32_T c11_i173;
  real_T c11_d_x[3];
  int32_T c11_i174;
  real_T c11_d_y[3];
  c11_eml_scalar_eg();
  for (c11_i165 = 0; c11_i165 < 3; c11_i165 = c11_i165 + 1) {
    c11_b_a[c11_i165] = c11_a[c11_i165];
  }

  for (c11_i166 = 0; c11_i166 < 3; c11_i166 = c11_i166 + 1) {
    c11_b_b[c11_i166] = c11_b[c11_i166];
  }

  for (c11_i167 = 0; c11_i167 < 3; c11_i167 = c11_i167 + 1) {
    c11_x[c11_i167] = c11_b_a[c11_i167];
  }

  for (c11_i168 = 0; c11_i168 < 3; c11_i168 = c11_i168 + 1) {
    c11_y[c11_i168] = c11_b_b[c11_i168];
  }

  for (c11_i169 = 0; c11_i169 < 3; c11_i169 = c11_i169 + 1) {
    c11_b_x[c11_i169] = c11_x[c11_i169];
  }

  for (c11_i170 = 0; c11_i170 < 3; c11_i170 = c11_i170 + 1) {
    c11_b_y[c11_i170] = c11_y[c11_i170];
  }

  for (c11_i171 = 0; c11_i171 < 3; c11_i171 = c11_i171 + 1) {
    c11_c_x[c11_i171] = c11_b_x[c11_i171];
  }

  for (c11_i172 = 0; c11_i172 < 3; c11_i172 = c11_i172 + 1) {
    c11_c_y[c11_i172] = c11_b_y[c11_i172];
  }

  for (c11_i173 = 0; c11_i173 < 3; c11_i173 = c11_i173 + 1) {
    c11_d_x[c11_i173] = c11_c_x[c11_i173];
  }

  for (c11_i174 = 0; c11_i174 < 3; c11_i174 = c11_i174 + 1) {
    c11_d_y[c11_i174] = c11_c_y[c11_i174];
  }

  return c11_ceval_xdot(3, c11_d_x, 1, 1, c11_d_y, 1, 1);
}

static void c11_eml_scalar_eg(void)
{
}

static real_T c11_ceval_xdot(int32_T c11_n, real_T c11_x[3], int32_T c11_ix0,
  int32_T c11_incx, real_T c11_y[3], int32_T c11_iy0,
  int32_T c11_incy)
{
  real_T c11_d;
  c11_d = 0.0;
  if ((real_T)c11_n > 0.0) {
    return ddot32(&c11_n, &c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c11_ix0), 1, 3, 1, 0) - 1]
                  , &c11_incx, &c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c11_iy0), 1, 3, 1, 0) - 1], &
                  c11_incy);
  }

  return c11_d;
}

static real_T c11_sqrt(real_T c11_x)
{
  real_T c11_b_x;
  real_T c11_c_x;
  c11_b_x = c11_x;
  if (c11_b_x < 0.0) {
    c11_b_eml_error();
  }

  c11_c_x = c11_b_x;
  c11_b_x = c11_c_x;
  return muDoubleScalarSqrt(c11_b_x);
}

static void c11_b_eml_error(void)
{
  int32_T c11_i175;
  static char_T c11_cv6[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c11_u[77];
  const mxArray *c11_y = NULL;
  int32_T c11_i176;
  static char_T c11_cv7[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c11_b_u[31];
  const mxArray *c11_b_y = NULL;
  for (c11_i175 = 0; c11_i175 < 77; c11_i175 = c11_i175 + 1) {
    c11_u[c11_i175] = c11_cv6[c11_i175];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c11_i176 = 0; c11_i176 < 31; c11_i176 = c11_i176 + 1) {
    c11_b_u[c11_i176] = c11_cv7[c11_i176];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c11_b_y, 14, c11_y);
}

static void c11_b_mrdivide(real_T c11_A[3], real_T c11_B, real_T c11_y[3])
{
  int32_T c11_i177;
  real_T c11_x[3];
  real_T c11_b_y;
  int32_T c11_i178;
  real_T c11_b_x[3];
  real_T c11_c_y;
  int32_T c11_i179;
  real_T c11_c_x[3];
  real_T c11_d_y;
  int32_T c11_i180;
  for (c11_i177 = 0; c11_i177 < 3; c11_i177 = c11_i177 + 1) {
    c11_x[c11_i177] = c11_A[c11_i177];
  }

  c11_b_y = c11_B;
  if (c11_b_y == 0.0) {
    c11_eml_warning();
  }

  for (c11_i178 = 0; c11_i178 < 3; c11_i178 = c11_i178 + 1) {
    c11_b_x[c11_i178] = c11_x[c11_i178];
  }

  c11_c_y = c11_b_y;
  for (c11_i179 = 0; c11_i179 < 3; c11_i179 = c11_i179 + 1) {
    c11_c_x[c11_i179] = c11_b_x[c11_i179];
  }

  c11_d_y = c11_c_y;
  for (c11_i180 = 0; c11_i180 < 3; c11_i180 = c11_i180 + 1) {
    c11_y[c11_i180] = c11_c_x[c11_i180] / c11_d_y;
  }
}

static void c11_cross(real_T c11_a[3], real_T c11_b[3], real_T c11_c[3])
{
  real_T c11_b_a;
  real_T c11_b_b;
  real_T c11_y;
  real_T c11_c_a;
  real_T c11_c_b;
  real_T c11_b_y;
  real_T c11_c1;
  real_T c11_d_a;
  real_T c11_d_b;
  real_T c11_c_y;
  real_T c11_e_a;
  real_T c11_e_b;
  real_T c11_d_y;
  real_T c11_c2;
  real_T c11_f_a;
  real_T c11_f_b;
  real_T c11_e_y;
  real_T c11_g_a;
  real_T c11_g_b;
  real_T c11_f_y;
  real_T c11_c3;
  c11_b_a = c11_a[2];
  c11_b_b = c11_b[1];
  c11_y = c11_b_a * c11_b_b;
  c11_c_a = c11_a[1];
  c11_c_b = c11_b[2];
  c11_b_y = c11_c_a * c11_c_b;
  c11_c1 = c11_b_y - c11_y;
  c11_d_a = c11_a[0];
  c11_d_b = c11_b[2];
  c11_c_y = c11_d_a * c11_d_b;
  c11_e_a = c11_a[2];
  c11_e_b = c11_b[0];
  c11_d_y = c11_e_a * c11_e_b;
  c11_c2 = c11_d_y - c11_c_y;
  c11_f_a = c11_a[1];
  c11_f_b = c11_b[0];
  c11_e_y = c11_f_a * c11_f_b;
  c11_g_a = c11_a[0];
  c11_g_b = c11_b[1];
  c11_f_y = c11_g_a * c11_g_b;
  c11_c3 = c11_f_y - c11_e_y;
  c11_c[0] = c11_c1;
  c11_c[1] = c11_c2;
  c11_c[2] = c11_c3;
}

static real_T c11_b_norm(real_T c11_x[3])
{
  int32_T c11_i181;
  real_T c11_b_x[3];
  for (c11_i181 = 0; c11_i181 < 3; c11_i181 = c11_i181 + 1) {
    c11_b_x[c11_i181] = c11_x[c11_i181];
  }

  return c11_b_genpnorm(c11_b_x, 2.0);
}

static real_T c11_b_genpnorm(real_T c11_x[3], real_T c11_p)
{
  real_T c11_y;
  int32_T c11_i182;
  real_T c11_b_x[3];
  real_T c11_k;
  real_T c11_b_k;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_absx;
  real_T c11_e_x;
  boolean_T c11_b;
  real_T c11_c_k;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_b_y;
  real_T c11_d_k;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  boolean_T c11_b_b;
  int32_T c11_i183;
  real_T c11_k_x[3];
  real_T c11_b_p;
  real_T c11_scale;
  real_T c11_e_k;
  real_T c11_f_k;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_b_absx;
  real_T c11_n_x;
  boolean_T c11_c_b;
  real_T c11_o_x;
  boolean_T c11_d_b;
  real_T c11_d7;
  real_T c11_j;
  real_T c11_b_j;
  real_T c11_p_x;
  boolean_T c11_e_b;
  real_T c11_a;
  real_T c11_f_b;
  real_T c11_c_y;
  real_T c11_q_x;
  boolean_T c11_g_b;
  real_T c11_b_a;
  real_T c11_h_b;
  int32_T c11_i184;
  real_T c11_r_x[3];
  real_T c11_c_p;
  real_T c11_b_scale;
  real_T c11_g_k;
  real_T c11_h_k;
  real_T c11_s_x;
  real_T c11_t_x;
  real_T c11_c_absx;
  real_T c11_u_x;
  boolean_T c11_i_b;
  real_T c11_d8;
  real_T c11_c_j;
  real_T c11_d_j;
  real_T c11_v_x;
  boolean_T c11_j_b;
  real_T c11_c_a;
  real_T c11_k_b;
  real_T c11_d_y;
  real_T c11_w_x;
  boolean_T c11_l_b;
  real_T c11_x_x;
  boolean_T c11_m_b;
  real_T c11_d_a;
  real_T c11_e_a;
  real_T c11_n_b;
  real_T c11_o_b;
  if (c11_p == 2.0) {
    for (c11_i182 = 0; c11_i182 < 3; c11_i182 = c11_i182 + 1) {
      c11_b_x[c11_i182] = c11_x[c11_i182];
    }

    return c11_b_eml_xnrm2(c11_b_x);
  } else if (c11_p == rtInf) {
    c11_y = 0.0;
    c11_k = 1.0;
   label_1:
    ;
    if (c11_k <= 3.0) {
      c11_b_k = c11_k;
      c11_c_x = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_b_k), 1, 3, 1, 0) - 1];
      c11_d_x = c11_c_x;
      c11_absx = muDoubleScalarAbs(c11_d_x);
      c11_e_x = c11_absx;
      c11_b = rtIsNaN(c11_e_x);
      if (c11_b) {
        return rtNaN;
      } else {
        if (c11_absx > c11_y) {
          c11_y = c11_absx;
        }

        c11_k = c11_k + 1.0;
        goto label_1;
      }
    }
  } else if (c11_p == 1.0) {
    c11_y = 0.0;
    for (c11_c_k = 1.0; c11_c_k <= 3.0; c11_c_k = c11_c_k + 1.0) {
      c11_b_k = c11_c_k;
      c11_f_x = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_b_k), 1, 3, 1, 0) - 1];
      c11_g_x = c11_f_x;
      c11_b_y = muDoubleScalarAbs(c11_g_x);
      c11_y = c11_y + c11_b_y;
    }
  } else if (c11_p == rtMinusInf) {
    c11_y = rtInf;
    c11_d_k = 1.0;
   label_2:
    ;
    if (c11_d_k <= 3.0) {
      c11_b_k = c11_d_k;
      c11_h_x = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_b_k), 1, 3, 1, 0) - 1];
      c11_i_x = c11_h_x;
      c11_absx = muDoubleScalarAbs(c11_i_x);
      c11_j_x = c11_absx;
      c11_b_b = rtIsNaN(c11_j_x);
      if (c11_b_b) {
        return rtNaN;
      } else {
        if (c11_absx < c11_y) {
          c11_y = c11_absx;
        }

        c11_d_k = c11_d_k + 1.0;
        goto label_2;
      }
    }
  } else if (c11_p > 0.0) {
    for (c11_i183 = 0; c11_i183 < 3; c11_i183 = c11_i183 + 1) {
      c11_k_x[c11_i183] = c11_x[c11_i183];
    }

    c11_b_p = c11_p;
    c11_y = 0.0;
    c11_scale = 0.0;
    c11_e_k = 1.0;
   label_3:
    ;
    if (c11_e_k <= 3.0) {
      c11_f_k = c11_e_k;
      c11_l_x = c11_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_f_k), 1, 3, 1, 0) - 1];
      c11_m_x = c11_l_x;
      c11_b_absx = muDoubleScalarAbs(c11_m_x);
      c11_n_x = c11_b_absx;
      c11_c_b = rtIsNaN(c11_n_x);
      if (c11_c_b) {
        return rtNaN;
      } else {
        c11_o_x = c11_b_absx;
        c11_d_b = rtIsInf(c11_o_x);
        if (c11_d_b) {
          c11_y = rtInf;
          c11_d7 = c11_f_k + 1.0;
          c11_j = c11_d7;
        } else {
          if (c11_b_absx > 0.0) {
            if (c11_scale < c11_b_absx) {
              c11_a = c11_y;
              c11_f_b = c11_power(c11_scale / c11_b_absx, c11_b_p);
              c11_c_y = c11_a * c11_f_b;
              c11_y = 1.0 + c11_c_y;
              c11_scale = c11_b_absx;
            } else {
              c11_y = c11_y + c11_power(c11_b_absx / c11_scale, c11_b_p);
            }
          }

          c11_e_k = c11_e_k + 1.0;
          goto label_3;
        }
      }
    } else {
      if (c11_y > 0.0) {
        c11_q_x = c11_y;
        c11_g_b = rtIsInf(c11_q_x);
        if (!c11_g_b) {
          c11_b_a = c11_scale;
          c11_h_b = c11_power(c11_y, 1.0 / c11_b_p);
          return c11_b_a * c11_h_b;
        }
      }

      return c11_y;
    }

   label_4:
    ;
    if (c11_j <= 3.0) {
      c11_b_j = c11_j;
      c11_p_x = c11_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c11_b_j), 1, 3, 1, 0) - 1];
      c11_e_b = rtIsNaN(c11_p_x);
      if (c11_e_b) {
        return rtNaN;
      } else {
        c11_j = c11_j + 1.0;
        goto label_4;
      }
    }
  } else if (c11_p < 0.0) {
    for (c11_i184 = 0; c11_i184 < 3; c11_i184 = c11_i184 + 1) {
      c11_r_x[c11_i184] = c11_x[c11_i184];
    }

    c11_c_p = c11_p;
    c11_y = 0.0;
    c11_b_scale = rtInf;
    c11_g_k = 1.0;
   label_5:
    ;
    if (c11_g_k <= 3.0) {
      c11_h_k = c11_g_k;
      c11_s_x = c11_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_h_k), 1, 3, 1, 0) - 1];
      c11_t_x = c11_s_x;
      c11_c_absx = muDoubleScalarAbs(c11_t_x);
      c11_u_x = c11_c_absx;
      c11_i_b = rtIsNaN(c11_u_x);
      if (c11_i_b) {
        return rtNaN;
      } else if (c11_c_absx == 0.0) {
        c11_y = 0.0;
        c11_d8 = c11_h_k + 1.0;
        c11_c_j = c11_d8;
      } else {
        if (c11_c_absx < c11_b_scale) {
          c11_c_a = c11_y;
          c11_k_b = c11_power(c11_b_scale / c11_c_absx, c11_c_p);
          c11_d_y = c11_c_a * c11_k_b;
          c11_y = 1.0 + c11_d_y;
          c11_b_scale = c11_c_absx;
        } else {
          c11_w_x = c11_c_absx;
          c11_l_b = rtIsInf(c11_w_x);
          if (!c11_l_b) {
            c11_y = c11_y + c11_power(c11_c_absx / c11_b_scale, c11_c_p);
          }
        }

        c11_g_k = c11_g_k + 1.0;
        goto label_5;
      }
    } else {
      if (c11_y > 0.0) {
        c11_x_x = c11_y;
        c11_m_b = rtIsInf(c11_x_x);
        if (!c11_m_b) {
          c11_d_a = c11_b_scale;
          c11_e_a = c11_y;
          c11_n_b = 1.0 / c11_c_p;
          c11_o_b = c11_power(c11_e_a, c11_n_b);
          return c11_d_a * c11_o_b;
        }
      }

      return c11_y;
    }

   label_6:
    ;
    if (c11_c_j <= 3.0) {
      c11_d_j = c11_c_j;
      c11_v_x = c11_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c11_d_j), 1, 3, 1, 0) - 1];
      c11_j_b = rtIsNaN(c11_v_x);
      if (c11_j_b) {
        return rtNaN;
      } else {
        c11_c_j = c11_c_j + 1.0;
        goto label_6;
      }
    }
  } else if (c11_p == 0.0) {
    return rtInf;
  } else {
    return rtNaN;
  }

  return c11_y;
}

static real_T c11_b_eml_xnrm2(real_T c11_x[3])
{
  int32_T c11_i185;
  real_T c11_b_x[3];
  int32_T c11_i186;
  real_T c11_c_x[3];
  for (c11_i185 = 0; c11_i185 < 3; c11_i185 = c11_i185 + 1) {
    c11_b_x[c11_i185] = c11_x[c11_i185];
  }

  for (c11_i186 = 0; c11_i186 < 3; c11_i186 = c11_i186 + 1) {
    c11_c_x[c11_i186] = c11_b_x[c11_i186];
  }

  return c11_b_ceval_xnrm2(3, c11_c_x, 1.0, 1);
}

static real_T c11_b_ceval_xnrm2(int32_T c11_n, real_T c11_x[3], real_T c11_ix0,
  int32_T c11_incx)
{
  return dnrm232(&c11_n, &c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
    _SFD_INTEGER_CHECK("ix0", c11_ix0), 1, 3, 1, 0) - 1], &
                 c11_incx);
}

static void c11_b_eml_scalar_eg(void)
{
}

static real_T c11_b_ceval_xdot(int32_T c11_n, real_T c11_x[4], int32_T c11_ix0,
  int32_T c11_incx, real_T c11_y[4], int32_T c11_iy0,
  int32_T c11_incy)
{
  real_T c11_d;
  c11_d = 0.0;
  if ((real_T)c11_n > 0.0) {
    return ddot32(&c11_n, &c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c11_ix0), 1, 4, 1, 0) - 1]
                  , &c11_incx, &c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c11_iy0), 1, 4, 1, 0) - 1], &
                  c11_incy);
  }

  return c11_d;
}

static const mxArray *c11_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i187;
  real_T c11_b_u[3];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  for (c11_i187 = 0; c11_i187 < 3; c11_i187 = c11_i187 + 1) {
    c11_b_u[c11_i187] = (*((real_T (*)[3])c11_u))[c11_i187];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_b_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i188;
  int32_T c11_i189;
  int32_T c11_i190;
  real_T c11_b_u[30];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  c11_i188 = 0;
  for (c11_i189 = 0; c11_i189 < 6; c11_i189 = c11_i189 + 1) {
    for (c11_i190 = 0; c11_i190 < 5; c11_i190 = c11_i190 + 1) {
      c11_b_u[c11_i190 + c11_i188] = (*((real_T (*)[30])c11_u))[c11_i190 +
        c11_i188];
    }

    c11_i188 = c11_i188 + 5;
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 2, 5, 6));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_c_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  c11_b_u = *((real_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_d_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i191;
  real_T c11_b_u[4];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  for (c11_i191 = 0; c11_i191 < 4; c11_i191 = c11_i191 + 1) {
    c11_b_u[c11_i191] = (*((real_T (*)[4])c11_u))[c11_i191];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_e_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i192;
  real_T c11_b_u[6];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  for (c11_i192 = 0; c11_i192 < 6; c11_i192 = c11_i192 + 1) {
    c11_b_u[c11_i192] = (*((real_T (*)[6])c11_u))[c11_i192];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_f_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i193;
  int32_T c11_i194;
  int32_T c11_i195;
  real_T c11_b_u[9];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  c11_i193 = 0;
  for (c11_i194 = 0; c11_i194 < 3; c11_i194 = c11_i194 + 1) {
    for (c11_i195 = 0; c11_i195 < 3; c11_i195 = c11_i195 + 1) {
      c11_b_u[c11_i195 + c11_i193] = (*((real_T (*)[9])c11_u))[c11_i195 +
        c11_i193];
    }

    c11_i193 = c11_i193 + 3;
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

const mxArray
  *sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_ResolvedFunctionInfo c11_info[93];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i196;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  c11_b_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 93));
  for (c11_i196 = 0; c11_i196 < 93; c11_i196 = c11_i196 + 1) {
    c11_r0 = &c11_info[c11_i196];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context"
                    , "nameCaptureInfo", c11_i196);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name",
                    "nameCaptureInfo", c11_i196);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i196);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)),
                    "resolved", "nameCaptureInfo", c11_i196);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c11_i196);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c11_i196);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c11_i196);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[93])
{
  c11_info[0].context = "";
  c11_info[0].name = "ones";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved = "[B]ones";
  c11_info[0].fileLength = 0U;
  c11_info[0].fileTime1 = 0U;
  c11_info[0].fileTime2 = 0U;
  c11_info[1].context = "";
  c11_info[1].name = "pi";
  c11_info[1].dominantType = "";
  c11_info[1].resolved = "[B]pi";
  c11_info[1].fileLength = 0U;
  c11_info[1].fileTime1 = 0U;
  c11_info[1].fileTime2 = 0U;
  c11_info[2].context = "";
  c11_info[2].name = "mtimes";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[2].fileLength = 3302U;
  c11_info[2].fileTime1 = 1242738294U;
  c11_info[2].fileTime2 = 0U;
  c11_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[3].name = "nargin";
  c11_info[3].dominantType = "";
  c11_info[3].resolved = "[B]nargin";
  c11_info[3].fileLength = 0U;
  c11_info[3].fileTime1 = 0U;
  c11_info[3].fileTime2 = 0U;
  c11_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[4].name = "gt";
  c11_info[4].dominantType = "double";
  c11_info[4].resolved = "[B]gt";
  c11_info[4].fileLength = 0U;
  c11_info[4].fileTime1 = 0U;
  c11_info[4].fileTime2 = 0U;
  c11_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[5].name = "isa";
  c11_info[5].dominantType = "double";
  c11_info[5].resolved = "[B]isa";
  c11_info[5].fileLength = 0U;
  c11_info[5].fileTime1 = 0U;
  c11_info[5].fileTime2 = 0U;
  c11_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[6].name = "isinteger";
  c11_info[6].dominantType = "double";
  c11_info[6].resolved = "[B]isinteger";
  c11_info[6].fileLength = 0U;
  c11_info[6].fileTime1 = 0U;
  c11_info[6].fileTime2 = 0U;
  c11_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[7].name = "isscalar";
  c11_info[7].dominantType = "double";
  c11_info[7].resolved = "[B]isscalar";
  c11_info[7].fileLength = 0U;
  c11_info[7].fileTime1 = 0U;
  c11_info[7].fileTime2 = 0U;
  c11_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[8].name = "strcmp";
  c11_info[8].dominantType = "char";
  c11_info[8].resolved = "[B]strcmp";
  c11_info[8].fileLength = 0U;
  c11_info[8].fileTime1 = 0U;
  c11_info[8].fileTime2 = 0U;
  c11_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[9].name = "size";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved = "[B]size";
  c11_info[9].fileLength = 0U;
  c11_info[9].fileTime1 = 0U;
  c11_info[9].fileTime2 = 0U;
  c11_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[10].name = "eq";
  c11_info[10].dominantType = "double";
  c11_info[10].resolved = "[B]eq";
  c11_info[10].fileLength = 0U;
  c11_info[10].fileTime1 = 0U;
  c11_info[10].fileTime2 = 0U;
  c11_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[11].name = "class";
  c11_info[11].dominantType = "double";
  c11_info[11].resolved = "[B]class";
  c11_info[11].fileLength = 0U;
  c11_info[11].fileTime1 = 0U;
  c11_info[11].fileTime2 = 0U;
  c11_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[12].name = "not";
  c11_info[12].dominantType = "logical";
  c11_info[12].resolved = "[B]not";
  c11_info[12].fileLength = 0U;
  c11_info[12].fileTime1 = 0U;
  c11_info[12].fileTime2 = 0U;
  c11_info[13].context = "";
  c11_info[13].name = "mrdivide";
  c11_info[13].dominantType = "double";
  c11_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[13].fileLength = 800U;
  c11_info[13].fileTime1 = 1238421692U;
  c11_info[13].fileTime2 = 0U;
  c11_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[14].name = "ge";
  c11_info[14].dominantType = "double";
  c11_info[14].resolved = "[B]ge";
  c11_info[14].fileLength = 0U;
  c11_info[14].fileTime1 = 0U;
  c11_info[14].fileTime2 = 0U;
  c11_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[15].name = "rdivide";
  c11_info[15].dominantType = "double";
  c11_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[15].fileLength = 620U;
  c11_info[15].fileTime1 = 1213914166U;
  c11_info[15].fileTime2 = 0U;
  c11_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[16].name = "isempty";
  c11_info[16].dominantType = "double";
  c11_info[16].resolved = "[B]isempty";
  c11_info[16].fileLength = 0U;
  c11_info[16].fileTime1 = 0U;
  c11_info[16].fileTime2 = 0U;
  c11_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[17].name = "eml_warning";
  c11_info[17].dominantType = "char";
  c11_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c11_info[17].fileLength = 262U;
  c11_info[17].fileTime1 = 1236241078U;
  c11_info[17].fileTime2 = 0U;
  c11_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[18].name = "eml_div";
  c11_info[18].dominantType = "double";
  c11_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[18].fileLength = 4269U;
  c11_info[18].fileTime1 = 1228077626U;
  c11_info[18].fileTime2 = 0U;
  c11_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c11_info[19].name = "isreal";
  c11_info[19].dominantType = "double";
  c11_info[19].resolved = "[B]isreal";
  c11_info[19].fileLength = 0U;
  c11_info[19].fileTime1 = 0U;
  c11_info[19].fileTime2 = 0U;
  c11_info[20].context = "";
  c11_info[20].name = "cos";
  c11_info[20].dominantType = "double";
  c11_info[20].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[20].fileLength = 324U;
  c11_info[20].fileTime1 = 1203431752U;
  c11_info[20].fileTime2 = 0U;
  c11_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[21].name = "eml_scalar_cos";
  c11_info[21].dominantType = "double";
  c11_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c11_info[21].fileLength = 602U;
  c11_info[21].fileTime1 = 1209318188U;
  c11_info[21].fileTime2 = 0U;
  c11_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[22].name = "islogical";
  c11_info[22].dominantType = "logical";
  c11_info[22].resolved = "[B]islogical";
  c11_info[22].fileLength = 0U;
  c11_info[22].fileTime1 = 0U;
  c11_info[22].fileTime2 = 0U;
  c11_info[23].context = "";
  c11_info[23].name = "lt";
  c11_info[23].dominantType = "double";
  c11_info[23].resolved = "[B]lt";
  c11_info[23].fileLength = 0U;
  c11_info[23].fileTime1 = 0U;
  c11_info[23].fileTime2 = 0U;
  c11_info[24].context = "";
  c11_info[24].name = "plus";
  c11_info[24].dominantType = "double";
  c11_info[24].resolved = "[B]plus";
  c11_info[24].fileLength = 0U;
  c11_info[24].fileTime1 = 0U;
  c11_info[24].fileTime2 = 0U;
  c11_info[25].context = "";
  c11_info[25].name = "zeros";
  c11_info[25].dominantType = "double";
  c11_info[25].resolved = "[B]zeros";
  c11_info[25].fileLength = 0U;
  c11_info[25].fileTime1 = 0U;
  c11_info[25].fileTime2 = 0U;
  c11_info[26].context = "";
  c11_info[26].name = "sort";
  c11_info[26].dominantType = "double";
  c11_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m";
  c11_info[26].fileLength = 749U;
  c11_info[26].fileTime1 = 1226561060U;
  c11_info[26].fileTime2 = 0U;
  c11_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m";
  c11_info[27].name = "le";
  c11_info[27].dominantType = "double";
  c11_info[27].resolved = "[B]le";
  c11_info[27].fileLength = 0U;
  c11_info[27].fileTime1 = 0U;
  c11_info[27].fileTime2 = 0U;
  c11_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m";
  c11_info[28].name = "nargout";
  c11_info[28].dominantType = "";
  c11_info[28].resolved = "[B]nargout";
  c11_info[28].fileLength = 0U;
  c11_info[28].fileTime1 = 0U;
  c11_info[28].fileTime2 = 0U;
  c11_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m";
  c11_info[29].name = "eml_sort";
  c11_info[29].dominantType = "double";
  c11_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  c11_info[29].fileLength = 2788U;
  c11_info[29].fileTime1 = 1240249412U;
  c11_info[29].fileTime2 = 0U;
  c11_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  c11_info[30].name = "eml_nonsingleton_dim";
  c11_info[30].dominantType = "double";
  c11_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c11_info[30].fileLength = 405U;
  c11_info[30].fileTime1 = 1240249410U;
  c11_info[30].fileTime2 = 0U;
  c11_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c11_info[31].name = "ne";
  c11_info[31].dominantType = "double";
  c11_info[31].resolved = "[B]ne";
  c11_info[31].fileLength = 0U;
  c11_info[31].fileTime1 = 0U;
  c11_info[31].fileTime2 = 0U;
  c11_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  c11_info[32].name = "eml_assert_valid_dim";
  c11_info[32].dominantType = "double";
  c11_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c11_info[32].fileLength = 909U;
  c11_info[32].fileTime1 = 1240249402U;
  c11_info[32].fileTime2 = 0U;
  c11_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c11_info[33].name = "eml_scalar_floor";
  c11_info[33].dominantType = "double";
  c11_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c11_info[33].fileLength = 260U;
  c11_info[33].fileTime1 = 1209318190U;
  c11_info[33].fileTime2 = 0U;
  c11_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c11_info[34].name = "eml_index_class";
  c11_info[34].dominantType = "";
  c11_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[34].fileLength = 909U;
  c11_info[34].fileTime1 = 1192454182U;
  c11_info[34].fileTime2 = 0U;
  c11_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c11_info[35].name = "intmax";
  c11_info[35].dominantType = "char";
  c11_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[35].fileLength = 1535U;
  c11_info[35].fileTime1 = 1192454128U;
  c11_info[35].fileTime2 = 0U;
  c11_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[36].name = "ischar";
  c11_info[36].dominantType = "char";
  c11_info[36].resolved = "[B]ischar";
  c11_info[36].fileLength = 0U;
  c11_info[36].fileTime1 = 0U;
  c11_info[36].fileTime2 = 0U;
  c11_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[37].name = "int32";
  c11_info[37].dominantType = "double";
  c11_info[37].resolved = "[B]int32";
  c11_info[37].fileLength = 0U;
  c11_info[37].fileTime1 = 0U;
  c11_info[37].fileTime2 = 0U;
  c11_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  c11_info[38].name = "eml_scalar_eg";
  c11_info[38].dominantType = "double";
  c11_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[38].fileLength = 3068U;
  c11_info[38].fileTime1 = 1240249410U;
  c11_info[38].fileTime2 = 0U;
  c11_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c11_info[39].name = "false";
  c11_info[39].dominantType = "";
  c11_info[39].resolved = "[B]false";
  c11_info[39].fileLength = 0U;
  c11_info[39].fileTime1 = 0U;
  c11_info[39].fileTime2 = 0U;
  c11_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[40].name = "isstruct";
  c11_info[40].dominantType = "double";
  c11_info[40].resolved = "[B]isstruct";
  c11_info[40].fileLength = 0U;
  c11_info[40].fileTime1 = 0U;
  c11_info[40].fileTime2 = 0U;
  c11_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c11_info[41].name = "cast";
  c11_info[41].dominantType = "double";
  c11_info[41].resolved = "[B]cast";
  c11_info[41].fileLength = 0U;
  c11_info[41].fileTime1 = 0U;
  c11_info[41].fileTime2 = 0U;
  c11_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  c11_info[42].name = "isvector";
  c11_info[42].dominantType = "double";
  c11_info[42].resolved = "[B]isvector";
  c11_info[42].fileLength = 0U;
  c11_info[42].fileTime1 = 0U;
  c11_info[42].fileTime2 = 0U;
  c11_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  c11_info[43].name = "eml_sort_idx";
  c11_info[43].dominantType = "double";
  c11_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c11_info[43].fileLength = 2402U;
  c11_info[43].fileTime1 = 1226561092U;
  c11_info[43].fileTime2 = 0U;
  c11_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c11_info[44].name = "eml_index_plus";
  c11_info[44].dominantType = "int32";
  c11_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[44].fileLength = 272U;
  c11_info[44].fileTime1 = 1192454186U;
  c11_info[44].fileTime2 = 0U;
  c11_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c11_info[45].name = "colon";
  c11_info[45].dominantType = "int32";
  c11_info[45].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c11_info[45].fileLength = 8271U;
  c11_info[45].fileTime1 = 1228077692U;
  c11_info[45].fileTime2 = 0U;
  c11_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c11_info[46].name = "floor";
  c11_info[46].dominantType = "double";
  c11_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c11_info[46].fileLength = 332U;
  c11_info[46].fileTime1 = 1203431824U;
  c11_info[46].fileTime2 = 0U;
  c11_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c11_info[47].name = "intmin";
  c11_info[47].dominantType = "char";
  c11_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c11_info[47].fileLength = 1505U;
  c11_info[47].fileTime1 = 1192454130U;
  c11_info[47].fileTime2 = 0U;
  c11_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c11_info[48].name = "uminus";
  c11_info[48].dominantType = "double";
  c11_info[48].resolved = "[B]uminus";
  c11_info[48].fileLength = 0U;
  c11_info[48].fileTime1 = 0U;
  c11_info[48].fileTime2 = 0U;
  c11_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c11_info[49].name = "double";
  c11_info[49].dominantType = "int32";
  c11_info[49].resolved = "[B]double";
  c11_info[49].fileLength = 0U;
  c11_info[49].fileTime1 = 0U;
  c11_info[49].fileTime2 = 0U;
  c11_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c11_info[50].name = "isnan";
  c11_info[50].dominantType = "double";
  c11_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c11_info[50].fileLength = 506U;
  c11_info[50].fileTime1 = 1228077610U;
  c11_info[50].fileTime2 = 0U;
  c11_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c11_info[51].name = "isinf";
  c11_info[51].dominantType = "double";
  c11_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c11_info[51].fileLength = 506U;
  c11_info[51].fileTime1 = 1228077610U;
  c11_info[51].fileTime2 = 0U;
  c11_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c11_info[52].name = "minus";
  c11_info[52].dominantType = "double";
  c11_info[52].resolved = "[B]minus";
  c11_info[52].fileLength = 0U;
  c11_info[52].fileTime1 = 0U;
  c11_info[52].fileTime2 = 0U;
  c11_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c11_info[53].name = "realmax";
  c11_info[53].dominantType = "";
  c11_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c11_info[53].fileLength = 771U;
  c11_info[53].fileTime1 = 1226561078U;
  c11_info[53].fileTime2 = 0U;
  c11_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c11_info[54].name = "mpower";
  c11_info[54].dominantType = "double";
  c11_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[54].fileLength = 3710U;
  c11_info[54].fileTime1 = 1238421690U;
  c11_info[54].fileTime2 = 0U;
  c11_info[55].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[55].name = "ndims";
  c11_info[55].dominantType = "double";
  c11_info[55].resolved = "[B]ndims";
  c11_info[55].fileLength = 0U;
  c11_info[55].fileTime1 = 0U;
  c11_info[55].fileTime2 = 0U;
  c11_info[56].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[56].name = "power";
  c11_info[56].dominantType = "double";
  c11_info[56].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[56].fileLength = 5380U;
  c11_info[56].fileTime1 = 1228077698U;
  c11_info[56].fileTime2 = 0U;
  c11_info[57].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[57].name = "eml_scalexp_alloc";
  c11_info[57].dominantType = "double";
  c11_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c11_info[57].fileLength = 808U;
  c11_info[57].fileTime1 = 1230478500U;
  c11_info[57].fileTime2 = 0U;
  c11_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[58].name = "eml_error";
  c11_info[58].dominantType = "char";
  c11_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c11_info[58].fileLength = 315U;
  c11_info[58].fileTime1 = 1213914146U;
  c11_info[58].fileTime2 = 0U;
  c11_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c11_info[59].name = "transpose";
  c11_info[59].dominantType = "int32";
  c11_info[59].resolved = "[B]transpose";
  c11_info[59].fileLength = 0U;
  c11_info[59].fileTime1 = 0U;
  c11_info[59].fileTime2 = 0U;
  c11_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c11_info[60].name = "eml_index_minus";
  c11_info[60].dominantType = "int32";
  c11_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c11_info[60].fileLength = 277U;
  c11_info[60].fileTime1 = 1192454184U;
  c11_info[60].fileTime2 = 0U;
  c11_info[61].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c11_info[61].name = "eml_sort_le";
  c11_info[61].dominantType = "int32";
  c11_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m";
  c11_info[61].fileLength = 2301U;
  c11_info[61].fileTime1 = 1226561092U;
  c11_info[61].fileTime2 = 0U;
  c11_info[62].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c11_info[62].name = "eml_index_times";
  c11_info[62].dominantType = "int32";
  c11_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c11_info[62].fileLength = 280U;
  c11_info[62].fileTime1 = 1192454188U;
  c11_info[62].fileTime2 = 0U;
  c11_info[63].context = "";
  c11_info[63].name = "ctranspose";
  c11_info[63].dominantType = "double";
  c11_info[63].resolved = "[B]ctranspose";
  c11_info[63].fileLength = 0U;
  c11_info[63].fileTime1 = 0U;
  c11_info[63].fileTime2 = 0U;
}

static void c11_b_info_helper(c11_ResolvedFunctionInfo c11_info[93])
{
  c11_info[64].context = "";
  c11_info[64].name = "norm";
  c11_info[64].dominantType = "double";
  c11_info[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c11_info[64].fileLength = 5186U;
  c11_info[64].fileTime1 = 1240249448U;
  c11_info[64].fileTime2 = 0U;
  c11_info[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c11_info[65].name = "eml_xnrm2";
  c11_info[65].dominantType = "double";
  c11_info[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c11_info[65].fileLength = 718U;
  c11_info[65].fileTime1 = 1209318258U;
  c11_info[65].fileTime2 = 0U;
  c11_info[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c11_info[66].name = "eml_refblas_xnrm2";
  c11_info[66].dominantType = "int32";
  c11_info[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[66].fileLength = 1433U;
  c11_info[66].fileTime1 = 1240249444U;
  c11_info[66].fileTime2 = 0U;
  c11_info[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[67].name = "true";
  c11_info[67].dominantType = "";
  c11_info[67].resolved = "[B]true";
  c11_info[67].fileLength = 0U;
  c11_info[67].fileTime1 = 0U;
  c11_info[67].fileTime2 = 0U;
  c11_info[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[68].name = "real";
  c11_info[68].dominantType = "double";
  c11_info[68].resolved = "[B]real";
  c11_info[68].fileLength = 0U;
  c11_info[68].fileTime1 = 0U;
  c11_info[68].fileTime2 = 0U;
  c11_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[69].name = "abs";
  c11_info[69].dominantType = "double";
  c11_info[69].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[69].fileLength = 566U;
  c11_info[69].fileTime1 = 1221254534U;
  c11_info[69].fileTime2 = 0U;
  c11_info[70].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[70].name = "eml_scalar_abs";
  c11_info[70].dominantType = "double";
  c11_info[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c11_info[70].fileLength = 461U;
  c11_info[70].fileTime1 = 1203431760U;
  c11_info[70].fileTime2 = 0U;
  c11_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[71].name = "times";
  c11_info[71].dominantType = "double";
  c11_info[71].resolved = "[B]times";
  c11_info[71].fileLength = 0U;
  c11_info[71].fileTime1 = 0U;
  c11_info[71].fileTime2 = 0U;
  c11_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[72].name = "imag";
  c11_info[72].dominantType = "double";
  c11_info[72].resolved = "[B]imag";
  c11_info[72].fileLength = 0U;
  c11_info[72].fileTime1 = 0U;
  c11_info[72].fileTime2 = 0U;
  c11_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c11_info[73].name = "inf";
  c11_info[73].dominantType = "";
  c11_info[73].resolved = "[B]inf";
  c11_info[73].fileLength = 0U;
  c11_info[73].fileTime1 = 0U;
  c11_info[73].fileTime2 = 0U;
  c11_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c11_info[74].name = "eml_guarded_nan";
  c11_info[74].dominantType = "char";
  c11_info[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[74].fileLength = 485U;
  c11_info[74].fileTime1 = 1192454180U;
  c11_info[74].fileTime2 = 0U;
  c11_info[75].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[75].name = "eml_is_float_class";
  c11_info[75].dominantType = "char";
  c11_info[75].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c11_info[75].fileLength = 226U;
  c11_info[75].fileTime1 = 1197834242U;
  c11_info[75].fileTime2 = 0U;
  c11_info[76].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[76].name = "nan";
  c11_info[76].dominantType = "char";
  c11_info[76].resolved = "[B]nan";
  c11_info[76].fileLength = 0U;
  c11_info[76].fileTime1 = 0U;
  c11_info[76].fileTime2 = 0U;
  c11_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c11_info[77].name = "eml_guarded_inf";
  c11_info[77].dominantType = "char";
  c11_info[77].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  c11_info[77].fileLength = 495U;
  c11_info[77].fileTime1 = 1192454178U;
  c11_info[77].fileTime2 = 0U;
  c11_info[78].context = "";
  c11_info[78].name = "mldivide";
  c11_info[78].dominantType = "double";
  c11_info[78].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c11_info[78].fileLength = 998U;
  c11_info[78].fileTime1 = 1238421688U;
  c11_info[78].fileTime2 = 0U;
  c11_info[79].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c11_info[79].name = "eml_lusolve";
  c11_info[79].dominantType = "double";
  c11_info[79].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c11_info[79].fileLength = 4120U;
  c11_info[79].fileTime1 = 1228077632U;
  c11_info[79].fileTime2 = 0U;
  c11_info[80].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c11_info[80].name = "eml_xcabs1";
  c11_info[80].dominantType = "double";
  c11_info[80].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c11_info[80].fileLength = 419U;
  c11_info[80].fileTime1 = 1209318248U;
  c11_info[80].fileTime2 = 0U;
  c11_info[81].context = "";
  c11_info[81].name = "dot";
  c11_info[81].dominantType = "double";
  c11_info[81].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c11_info[81].fileLength = 2812U;
  c11_info[81].fileTime1 = 1236241088U;
  c11_info[81].fileTime2 = 0U;
  c11_info[82].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c11_info[82].name = "isequal";
  c11_info[82].dominantType = "double";
  c11_info[82].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c11_info[82].fileLength = 180U;
  c11_info[82].fileTime1 = 1226561072U;
  c11_info[82].fileTime2 = 0U;
  c11_info[83].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c11_info[83].name = "eml_isequal_core";
  c11_info[83].dominantType = "double";
  c11_info[83].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c11_info[83].fileLength = 3981U;
  c11_info[83].fileTime1 = 1236241072U;
  c11_info[83].fileTime2 = 0U;
  c11_info[84].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c11_info[84].name = "isnumeric";
  c11_info[84].dominantType = "double";
  c11_info[84].resolved = "[B]isnumeric";
  c11_info[84].fileLength = 0U;
  c11_info[84].fileTime1 = 0U;
  c11_info[84].fileTime2 = 0U;
  c11_info[85].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c11_info[85].name = "isfloat";
  c11_info[85].dominantType = "double";
  c11_info[85].resolved = "[B]isfloat";
  c11_info[85].fileLength = 0U;
  c11_info[85].fileTime1 = 0U;
  c11_info[85].fileTime2 = 0U;
  c11_info[86].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m/vdot";
  c11_info[86].name = "eml_xdotc";
  c11_info[86].dominantType = "int32";
  c11_info[86].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c11_info[86].fileLength = 1453U;
  c11_info[86].fileTime1 = 1209318250U;
  c11_info[86].fileTime2 = 0U;
  c11_info[87].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c11_info[87].name = "eml_xdot";
  c11_info[87].dominantType = "int32";
  c11_info[87].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c11_info[87].fileLength = 1330U;
  c11_info[87].fileTime1 = 1209318250U;
  c11_info[87].fileTime2 = 0U;
  c11_info[88].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c11_info[88].name = "eml_refblas_xdot";
  c11_info[88].dominantType = "int32";
  c11_info[88].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c11_info[88].fileLength = 343U;
  c11_info[88].fileTime1 = 1211203444U;
  c11_info[88].fileTime2 = 0U;
  c11_info[89].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c11_info[89].name = "eml_refblas_xdotx";
  c11_info[89].dominantType = "int32";
  c11_info[89].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[89].fileLength = 1605U;
  c11_info[89].fileTime1 = 1236241080U;
  c11_info[89].fileTime2 = 0U;
  c11_info[90].context = "";
  c11_info[90].name = "sqrt";
  c11_info[90].dominantType = "double";
  c11_info[90].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c11_info[90].fileLength = 572U;
  c11_info[90].fileTime1 = 1203431846U;
  c11_info[90].fileTime2 = 0U;
  c11_info[91].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c11_info[91].name = "eml_scalar_sqrt";
  c11_info[91].dominantType = "double";
  c11_info[91].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c11_info[91].fileLength = 664U;
  c11_info[91].fileTime1 = 1209318194U;
  c11_info[91].fileTime2 = 0U;
  c11_info[92].context = "";
  c11_info[92].name = "cross";
  c11_info[92].dominantType = "double";
  c11_info[92].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[92].fileLength = 3157U;
  c11_info[92].fileTime1 = 1240249462U;
  c11_info[92].fileTime2 = 0U;
}

static const mxArray *c11_g_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  boolean_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  c11_b_u = *((boolean_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
  (mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2006480571U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3093919252U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1338317835U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3394262632U);
}

mxArray
  *sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4053997535U);
    pr[1] = (double)(3539863858U);
    pr[2] = (double)(3916254509U);
    pr[3] = (double)(1455197968U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(5);
      pr[1] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[14],T\"light_est\",},{M[1],M[5],T\"q_BO_est\",},{M[1],M[17],T\"v_Sun1\",},{M[8],M[0],T\"is_active_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb_get_check_sum
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
           11,
           1,
           1,
           11,
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
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_Bb_m",0,(MexFcnForType)c11_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 5;
            dimVector[1]= 6;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_SUN",0,(MexFcnForType)c11_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_BO_est",0,(MexFcnForType)
                                c11_d_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_Bo_c",0,(MexFcnForType)c11_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_So_c",0,(MexFcnForType)c11_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(5,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_SS_ADC_gain",0,(MexFcnForType)c11_c_sf_marshall);
          _SFD_SET_DATA_PROPS(6,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Snum",0,
                              (MexFcnForType)c11_c_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "light_est",0,(MexFcnForType)c11_c_sf_marshall);
          _SFD_SET_DATA_PROPS(8,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_MAGMETER_WEIGHT",0,(MexFcnForType)
                              c11_c_sf_marshall);
          _SFD_SET_DATA_PROPS(9,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_SS_MAX_ANGLE",0,(MexFcnForType)
                              c11_c_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(10,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_Sun1",0,(MexFcnForType)c11_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,4,0,1,2,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3642);
        _SFD_CV_INIT_EML_IF(0,0,710,742,-1,775);
        _SFD_CV_INIT_EML_IF(0,1,781,798,815,838);
        _SFD_CV_INIT_EML_IF(0,2,879,894,3560,3638);
        _SFD_CV_INIT_EML_IF(0,3,2897,2908,3190,3481);
        _SFD_CV_INIT_EML_FOR(0,0,693,706,779);
        _SFD_CV_INIT_EML_WHILE(0,0,1716,1766,1819);
        _SFD_CV_INIT_EML_WHILE(0,1,1947,2048,2101);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c11_v_Bb_m)[3];
          real_T (*c11_m_SUN)[30];
          real_T (*c11_q_BO_est)[4];
          real_T (*c11_v_Bo_c)[3];
          real_T (*c11_v_So_c)[3];
          real_T *c11_light_est;
          real_T (*c11_v_Sun1)[3];
          c11_v_So_c = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 3);
          c11_v_Bb_m = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c11_v_Sun1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
          c11_q_BO_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance.S, 1);
          c11_v_Bo_c = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
          c11_m_SUN = (real_T (*)[30])ssGetInputPortSignal(chartInstance.S, 1);
          c11_light_est = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_v_Bb_m);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_m_SUN);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_q_BO_est);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_v_Bo_c);
          _SFD_SET_DATA_VALUE_PTR(4U, c11_v_So_c);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance.c11_s_SS_ADC_gain);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c11_Snum);
          _SFD_SET_DATA_VALUE_PTR(7U, c11_light_est);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance.c11_s_MAGMETER_WEIGHT);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance.c11_s_SS_MAX_ANGLE);
          _SFD_SET_DATA_VALUE_PTR(10U, c11_v_Sun1);
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
  sf_opaque_initialize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void *
  chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  initialize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void sf_opaque_enable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_disable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  disable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_gateway_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  sf_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  ext_mode_exec_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (void *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(sf_mex_dup
    (st));
}

static void
  sf_opaque_terminate_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  /* Actual parameters from chart:
     Snum s_MAGMETER_WEIGHT s_SS_ADC_gain s_SS_MAX_ANGLE
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Snum*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for s_MAGMETER_WEIGHT*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for s_SS_ADC_gain*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for s_SS_MAX_ANGLE*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",
                "adcs_v15_integral_Power_nom_no_charge_in_detumb",11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",11,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",11,4);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",
        "adcs_v15_integral_Power_nom_no_charge_in_detumb",11,3);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom_no_charge_in_detumb",
                          "adcs_v15_integral_Power_nom_no_charge_in_detumb",11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(774238783U));
  ssSetChecksum1(S,(555326597U));
  ssSetChecksum2(S,(2788862863U));
  ssSetChecksum3(S,(3843734962U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom_no_charge_in_detumb",
      "adcs_v15_integral_Power_nom_no_charge_in_detumb",11);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb
  (SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb;
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

void c11_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_adcs_v15_integral_Power_nom_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_adcs_v15_integral_Power_nom_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
