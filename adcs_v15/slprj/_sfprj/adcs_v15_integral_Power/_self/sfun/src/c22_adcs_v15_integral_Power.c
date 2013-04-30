/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c22_adcs_v15_integral_Power.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c22_IN_NO_ACTIVE_CHILD         (0)
#define c22_b_s_SS_MAX_ANGLE           (85.0)
#define c22_b_Snum                     (6.0)

/* Variable Declarations */

/* Variable Definitions */
static SFc22_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c22_adcs_v15_integral_Power(void);
static void initialize_params_c22_adcs_v15_integral_Power(void);
static void enable_c22_adcs_v15_integral_Power(void);
static void disable_c22_adcs_v15_integral_Power(void);
static void c22_update_debugger_state_c22_adcs_v15_integral_Power(void);
static void ext_mode_exec_c22_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c22_adcs_v15_integral_Power(void);
static void set_sim_state_c22_adcs_v15_integral_Power(const mxArray *c22_st);
static void finalize_c22_adcs_v15_integral_Power(void);
static void sf_c22_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber);
static const mxArray *c22_sf_marshall(void *c22_chartInstance, void *c22_u);
static const mxArray *c22_b_sf_marshall(void *c22_chartInstance, void *c22_u);
static const mxArray *c22_c_sf_marshall(void *c22_chartInstance, void *c22_u);
static const mxArray *c22_d_sf_marshall(void *c22_chartInstance, void *c22_u);
static const mxArray *c22_e_sf_marshall(void *c22_chartInstance, void *c22_u);
static void c22_info_helper(c22_ResolvedFunctionInfo c22_info[24]);
static const mxArray *c22_f_sf_marshall(void *c22_chartInstance, void *c22_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c22_adcs_v15_integral_Power(void)
{
  uint8_T *c22_is_active_c22_adcs_v15_integral_Power;
  c22_is_active_c22_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c22_is_active_c22_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c22_adcs_v15_integral_Power(void)
{
  real_T c22_d0;
  real_T c22_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Snum' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c22_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c22_Snum = c22_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_SS_MAX_ANGLE' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c22_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c22_s_SS_MAX_ANGLE = c22_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c22_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c22_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c22_update_debugger_state_c22_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c22_adcs_v15_integral_Power(void)
{
  c22_update_debugger_state_c22_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c22_adcs_v15_integral_Power(void)
{
  const mxArray *c22_st = NULL;
  const mxArray *c22_y = NULL;
  int32_T c22_i0;
  real_T c22_u[30];
  const mxArray *c22_b_y = NULL;
  int32_T c22_i1;
  real_T c22_b_u[6];
  const mxArray *c22_c_y = NULL;
  uint8_T c22_c_u;
  const mxArray *c22_d_y = NULL;
  uint8_T *c22_is_active_c22_adcs_v15_integral_Power;
  real_T (*c22_values)[6];
  real_T (*c22_m_SUN)[30];
  c22_values = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 2);
  c22_is_active_c22_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c22_m_SUN = (real_T (*)[30])ssGetOutputPortSignal(chartInstance.S, 1);
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellarray(3));
  for (c22_i0 = 0; c22_i0 < 30; c22_i0 = c22_i0 + 1) {
    c22_u[c22_i0] = (*c22_m_SUN)[c22_i0];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_u, 0, 0U, 1U, 0U, 2, 5, 6));
  sf_mex_setcell(c22_y, 0, c22_b_y);
  for (c22_i1 = 0; c22_i1 < 6; c22_i1 = c22_i1 + 1) {
    c22_b_u[c22_i1] = (*c22_values)[c22_i1];
  }

  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c22_y, 1, c22_c_y);
  c22_c_u = *c22_is_active_c22_adcs_v15_integral_Power;
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 2, c22_d_y);
  sf_mex_assign(&c22_st, c22_y);
  return c22_st;
}

static void set_sim_state_c22_adcs_v15_integral_Power(const mxArray *c22_st)
{
  const mxArray *c22_u;
  const mxArray *c22_m_SUN;
  real_T c22_dv0[30];
  int32_T c22_i2;
  real_T c22_y[30];
  int32_T c22_i3;
  const mxArray *c22_values;
  real_T c22_dv1[6];
  int32_T c22_i4;
  real_T c22_b_y[6];
  int32_T c22_i5;
  const mxArray *c22_is_active_c22_adcs_v15_integral_Power;
  uint8_T c22_u0;
  uint8_T c22_c_y;
  boolean_T *c22_doneDoubleBufferReInit;
  uint8_T *c22_b_is_active_c22_adcs_v15_integral_Power;
  real_T (*c22_b_m_SUN)[30];
  real_T (*c22_b_values)[6];
  c22_b_values = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 2);
  c22_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c22_b_is_active_c22_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c22_b_m_SUN = (real_T (*)[30])ssGetOutputPortSignal(chartInstance.S, 1);
  *c22_doneDoubleBufferReInit = true;
  c22_u = sf_mex_dup(c22_st);
  c22_m_SUN = sf_mex_dup(sf_mex_getcell(c22_u, 0));
  sf_mex_import("m_SUN", sf_mex_dup(c22_m_SUN), &c22_dv0, 1, 0, 0U, 1, 0U, 2, 5,
                6);
  for (c22_i2 = 0; c22_i2 < 30; c22_i2 = c22_i2 + 1) {
    c22_y[c22_i2] = c22_dv0[c22_i2];
  }

  sf_mex_destroy(&c22_m_SUN);
  for (c22_i3 = 0; c22_i3 < 30; c22_i3 = c22_i3 + 1) {
    (*c22_b_m_SUN)[c22_i3] = c22_y[c22_i3];
  }

  c22_values = sf_mex_dup(sf_mex_getcell(c22_u, 1));
  sf_mex_import("values", sf_mex_dup(c22_values), &c22_dv1, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c22_i4 = 0; c22_i4 < 6; c22_i4 = c22_i4 + 1) {
    c22_b_y[c22_i4] = c22_dv1[c22_i4];
  }

  sf_mex_destroy(&c22_values);
  for (c22_i5 = 0; c22_i5 < 6; c22_i5 = c22_i5 + 1) {
    (*c22_b_values)[c22_i5] = c22_b_y[c22_i5];
  }

  c22_is_active_c22_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c22_u, 2));
  sf_mex_import("is_active_c22_adcs_v15_integral_Power", sf_mex_dup
                (c22_is_active_c22_adcs_v15_integral_Power), &c22_u0, 1, 3, 0U,
                0,
                0U, 0);
  c22_c_y = c22_u0;
  sf_mex_destroy(&c22_is_active_c22_adcs_v15_integral_Power);
  *c22_b_is_active_c22_adcs_v15_integral_Power = c22_c_y;
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_adcs_v15_integral_Power();
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_adcs_v15_integral_Power(void)
{
}

static void sf_c22_adcs_v15_integral_Power(void)
{
  int32_T c22_i6;
  int32_T c22_i7;
  int32_T c22_i8;
  int32_T c22_i9;
  int32_T c22_i10;
  int32_T c22_i11;
  int32_T c22_i12;
  int32_T c22_i13;
  int32_T c22_previousEvent;
  int32_T c22_i14;
  real_T c22_v_S1[3];
  real_T c22_s_S1;
  int32_T c22_i15;
  real_T c22_v_S2[3];
  real_T c22_s_S2;
  int32_T c22_i16;
  real_T c22_v_S3[3];
  real_T c22_s_S3;
  int32_T c22_i17;
  real_T c22_v_S4[3];
  real_T c22_s_S4;
  int32_T c22_i18;
  real_T c22_v_S5[3];
  real_T c22_s_S5;
  int32_T c22_i19;
  real_T c22_v_S6[3];
  real_T c22_s_S6;
  real_T c22_nargout = 2.0;
  real_T c22_nargin = 14.0;
  real_T c22_c_s_SS_MAX_ANGLE = c22_b_s_SS_MAX_ANGLE;
  real_T c22_c_Snum = c22_b_Snum;
  real_T c22_m_SUNtot[30];
  real_T c22_t_S[6];
  real_T c22_a;
  real_T c22_values[6];
  real_T c22_m_SUN[30];
  int32_T c22_i20;
  int32_T c22_i21;
  int32_T c22_i22;
  int32_T c22_i23;
  int32_T c22_i24;
  int32_T c22_i25;
  int32_T c22_i26;
  int32_T c22_i27;
  int32_T c22_i28;
  int32_T c22_i29;
  int32_T c22_i30;
  boolean_T c22_b[6];
  int32_T c22_i31;
  real_T c22_y[6];
  int32_T c22_i32;
  int32_T c22_i33;
  int32_T c22_i34;
  int32_T c22_i35;
  int32_T c22_i36;
  int32_T c22_i37;
  int32_T c22_i38;
  real_T *c22_b_s_S1;
  real_T *c22_b_s_S2;
  real_T *c22_b_s_S3;
  real_T *c22_b_s_S4;
  real_T *c22_b_s_S5;
  real_T *c22_b_s_S6;
  real_T (*c22_b_m_SUN)[30];
  real_T (*c22_b_values)[6];
  real_T (*c22_b_v_S6)[3];
  real_T (*c22_b_v_S5)[3];
  real_T (*c22_b_v_S4)[3];
  real_T (*c22_b_v_S3)[3];
  real_T (*c22_b_v_S2)[3];
  real_T (*c22_b_v_S1)[3];
  c22_b_s_S5 = (real_T *)ssGetInputPortSignal(chartInstance.S, 9);
  c22_b_s_S2 = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c22_b_values = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 2);
  c22_b_v_S6 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 10);
  c22_b_v_S1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c22_b_v_S2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c22_b_s_S4 = (real_T *)ssGetInputPortSignal(chartInstance.S, 7);
  c22_b_v_S5 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 8);
  c22_b_s_S6 = (real_T *)ssGetInputPortSignal(chartInstance.S, 11);
  c22_b_s_S3 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c22_b_s_S1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c22_b_v_S3 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
  c22_b_m_SUN = (real_T (*)[30])ssGetOutputPortSignal(chartInstance.S, 1);
  c22_b_v_S4 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 6);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,15);
  for (c22_i6 = 0; c22_i6 < 3; c22_i6 = c22_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_v_S1)[c22_i6], 0U);
  }

  for (c22_i7 = 0; c22_i7 < 30; c22_i7 = c22_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_m_SUN)[c22_i7], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_b_s_S1, 2U);
  for (c22_i8 = 0; c22_i8 < 3; c22_i8 = c22_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_v_S2)[c22_i8], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_b_s_S2, 4U);
  for (c22_i9 = 0; c22_i9 < 3; c22_i9 = c22_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_v_S3)[c22_i9], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_b_s_S3, 6U);
  for (c22_i10 = 0; c22_i10 < 3; c22_i10 = c22_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_v_S4)[c22_i10], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_b_s_S4, 8U);
  for (c22_i11 = 0; c22_i11 < 3; c22_i11 = c22_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_v_S5)[c22_i11], 9U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_b_s_S5, 10U);
  for (c22_i12 = 0; c22_i12 < 3; c22_i12 = c22_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_v_S6)[c22_i12], 11U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_b_s_S6, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c22_Snum, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c22_s_SS_MAX_ANGLE, 14U);
  for (c22_i13 = 0; c22_i13 < 6; c22_i13 = c22_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_b_values)[c22_i13], 15U);
  }

  c22_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,15);
  for (c22_i14 = 0; c22_i14 < 3; c22_i14 = c22_i14 + 1) {
    c22_v_S1[c22_i14] = (*c22_b_v_S1)[c22_i14];
  }

  c22_s_S1 = *c22_b_s_S1;
  for (c22_i15 = 0; c22_i15 < 3; c22_i15 = c22_i15 + 1) {
    c22_v_S2[c22_i15] = (*c22_b_v_S2)[c22_i15];
  }

  c22_s_S2 = *c22_b_s_S2;
  for (c22_i16 = 0; c22_i16 < 3; c22_i16 = c22_i16 + 1) {
    c22_v_S3[c22_i16] = (*c22_b_v_S3)[c22_i16];
  }

  c22_s_S3 = *c22_b_s_S3;
  for (c22_i17 = 0; c22_i17 < 3; c22_i17 = c22_i17 + 1) {
    c22_v_S4[c22_i17] = (*c22_b_v_S4)[c22_i17];
  }

  c22_s_S4 = *c22_b_s_S4;
  for (c22_i18 = 0; c22_i18 < 3; c22_i18 = c22_i18 + 1) {
    c22_v_S5[c22_i18] = (*c22_b_v_S5)[c22_i18];
  }

  c22_s_S5 = *c22_b_s_S5;
  for (c22_i19 = 0; c22_i19 < 3; c22_i19 = c22_i19 + 1) {
    c22_v_S6[c22_i19] = (*c22_b_v_S6)[c22_i19];
  }

  c22_s_S6 = *c22_b_s_S6;
  sf_debug_symbol_scope_push(21U, 0U);
  sf_debug_symbol_scope_add("nargout", &c22_nargout, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c22_nargin, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("s_SS_MAX_ANGLE", &c22_c_s_SS_MAX_ANGLE,
    c22_b_sf_marshall);
  sf_debug_symbol_scope_add("Snum", &c22_c_Snum, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("m_SUNtot", &c22_m_SUNtot, c22_c_sf_marshall);
  sf_debug_symbol_scope_add("t_S", &c22_t_S, c22_e_sf_marshall);
  sf_debug_symbol_scope_add("a", &c22_a, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("values", &c22_values, c22_d_sf_marshall);
  sf_debug_symbol_scope_add("m_SUN", &c22_m_SUN, c22_c_sf_marshall);
  sf_debug_symbol_scope_add("s_S6", &c22_s_S6, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("v_S6", &c22_v_S6, c22_sf_marshall);
  sf_debug_symbol_scope_add("s_S5", &c22_s_S5, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("v_S5", &c22_v_S5, c22_sf_marshall);
  sf_debug_symbol_scope_add("s_S4", &c22_s_S4, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("v_S4", &c22_v_S4, c22_sf_marshall);
  sf_debug_symbol_scope_add("s_S3", &c22_s_S3, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("v_S3", &c22_v_S3, c22_sf_marshall);
  sf_debug_symbol_scope_add("s_S2", &c22_s_S2, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("v_S2", &c22_v_S2, c22_sf_marshall);
  sf_debug_symbol_scope_add("s_S1", &c22_s_S1, c22_b_sf_marshall);
  sf_debug_symbol_scope_add("v_S1", &c22_v_S1, c22_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c22_a = 8.7155742747658138E-002;
  _SFD_EML_CALL(0,4);
  for (c22_i20 = 0; c22_i20 < 6; c22_i20 = c22_i20 + 1) {
    c22_t_S[c22_i20] = 8.7155742747658138E-002;
  }

  /*  SS vectors */
  /*  flags */
  _SFD_EML_CALL(0,6);
  for (c22_i21 = 0; c22_i21 < 3; c22_i21 = c22_i21 + 1) {
    c22_m_SUNtot[c22_i21] = c22_v_S1[c22_i21];
  }

  for (c22_i22 = 0; c22_i22 < 3; c22_i22 = c22_i22 + 1) {
    c22_m_SUNtot[c22_i22 + 5] = c22_v_S2[c22_i22];
  }

  for (c22_i23 = 0; c22_i23 < 3; c22_i23 = c22_i23 + 1) {
    c22_m_SUNtot[c22_i23 + 10] = c22_v_S3[c22_i23];
  }

  for (c22_i24 = 0; c22_i24 < 3; c22_i24 = c22_i24 + 1) {
    c22_m_SUNtot[c22_i24 + 15] = c22_v_S4[c22_i24];
  }

  for (c22_i25 = 0; c22_i25 < 3; c22_i25 = c22_i25 + 1) {
    c22_m_SUNtot[c22_i25 + 20] = c22_v_S5[c22_i25];
  }

  for (c22_i26 = 0; c22_i26 < 3; c22_i26 = c22_i26 + 1) {
    c22_m_SUNtot[c22_i26 + 25] = c22_v_S6[c22_i26];
  }

  c22_i27 = 0;
  for (c22_i28 = 0; c22_i28 < 6; c22_i28 = c22_i28 + 1) {
    c22_m_SUNtot[c22_i27 + 3] = 0.0;
    c22_i27 = c22_i27 + 5;
  }

  c22_m_SUNtot[4] = c22_s_S1;
  c22_m_SUNtot[9] = c22_s_S2;
  c22_m_SUNtot[14] = c22_s_S3;
  c22_m_SUNtot[19] = c22_s_S4;
  c22_m_SUNtot[24] = c22_s_S5;
  c22_m_SUNtot[29] = c22_s_S6;

  /*  values */
  _SFD_EML_CALL(0,10);
  c22_i29 = 0;
  for (c22_i30 = 0; c22_i30 < 6; c22_i30 = c22_i30 + 1) {
    c22_b[c22_i30] = (c22_m_SUNtot[c22_i29 + 4] > c22_t_S[c22_i30]);
    c22_i29 = c22_i29 + 5;
  }

  for (c22_i31 = 0; c22_i31 < 6; c22_i31 = c22_i31 + 1) {
    c22_y[c22_i31] = (real_T)c22_b[c22_i31];
  }

  c22_i32 = 0;
  for (c22_i33 = 0; c22_i33 < 6; c22_i33 = c22_i33 + 1) {
    c22_m_SUNtot[c22_i32 + 3] = c22_y[c22_i33];
    c22_i32 = c22_i32 + 5;
  }

  _SFD_EML_CALL(0,12);
  for (c22_i34 = 0; c22_i34 < 30; c22_i34 = c22_i34 + 1) {
    c22_m_SUN[c22_i34] = c22_m_SUNtot[c22_i34];
  }

  _SFD_EML_CALL(0,13);
  c22_i35 = 0;
  for (c22_i36 = 0; c22_i36 < 6; c22_i36 = c22_i36 + 1) {
    c22_values[c22_i36] = c22_m_SUN[c22_i35 + 4];
    c22_i35 = c22_i35 + 5;
  }

  _SFD_EML_CALL(0,-13);
  sf_debug_symbol_scope_pop();
  for (c22_i37 = 0; c22_i37 < 30; c22_i37 = c22_i37 + 1) {
    (*c22_b_m_SUN)[c22_i37] = c22_m_SUN[c22_i37];
  }

  for (c22_i38 = 0; c22_i38 < 6; c22_i38 = c22_i38 + 1) {
    (*c22_b_values)[c22_i38] = c22_values[c22_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
  _sfEvent_ = c22_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber)
{
}

static const mxArray *c22_sf_marshall(void *c22_chartInstance, void *c22_u)
{
  const mxArray *c22_y = NULL;
  int32_T c22_i39;
  real_T c22_b_u[3];
  const mxArray *c22_b_y = NULL;
  c22_y = NULL;
  for (c22_i39 = 0; c22_i39 < 3; c22_i39 = c22_i39 + 1) {
    c22_b_u[c22_i39] = (*((real_T (*)[3])c22_u))[c22_i39];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static const mxArray *c22_b_sf_marshall(void *c22_chartInstance, void *c22_u)
{
  const mxArray *c22_y = NULL;
  real_T c22_b_u;
  const mxArray *c22_b_y = NULL;
  c22_y = NULL;
  c22_b_u = *((real_T *)c22_u);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static const mxArray *c22_c_sf_marshall(void *c22_chartInstance, void *c22_u)
{
  const mxArray *c22_y = NULL;
  int32_T c22_i40;
  int32_T c22_i41;
  int32_T c22_i42;
  real_T c22_b_u[30];
  const mxArray *c22_b_y = NULL;
  c22_y = NULL;
  c22_i40 = 0;
  for (c22_i41 = 0; c22_i41 < 6; c22_i41 = c22_i41 + 1) {
    for (c22_i42 = 0; c22_i42 < 5; c22_i42 = c22_i42 + 1) {
      c22_b_u[c22_i42 + c22_i40] = (*((real_T (*)[30])c22_u))[c22_i42 + c22_i40];
    }

    c22_i40 = c22_i40 + 5;
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 2, 5, 6));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static const mxArray *c22_d_sf_marshall(void *c22_chartInstance, void *c22_u)
{
  const mxArray *c22_y = NULL;
  int32_T c22_i43;
  real_T c22_b_u[6];
  const mxArray *c22_b_y = NULL;
  c22_y = NULL;
  for (c22_i43 = 0; c22_i43 < 6; c22_i43 = c22_i43 + 1) {
    c22_b_u[c22_i43] = (*((real_T (*)[6])c22_u))[c22_i43];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static const mxArray *c22_e_sf_marshall(void *c22_chartInstance, void *c22_u)
{
  const mxArray *c22_y = NULL;
  int32_T c22_i44;
  real_T c22_b_u[6];
  const mxArray *c22_b_y = NULL;
  c22_y = NULL;
  for (c22_i44 = 0; c22_i44 < 6; c22_i44 = c22_i44 + 1) {
    c22_b_u[c22_i44] = (*((real_T (*)[6])c22_u))[c22_i44];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

const mxArray *sf_c22_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_ResolvedFunctionInfo c22_info[24];
  const mxArray *c22_m0 = NULL;
  int32_T c22_i45;
  c22_ResolvedFunctionInfo *c22_r0;
  c22_nameCaptureInfo = NULL;
  c22_info_helper(c22_info);
  sf_mex_assign(&c22_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24));
  for (c22_i45 = 0; c22_i45 < 24; c22_i45 = c22_i45 + 1) {
    c22_r0 = &c22_info[c22_i45];
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c22_r0->context)), "context"
                    , "nameCaptureInfo", c22_i45);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c22_r0->name)), "name",
                    "nameCaptureInfo", c22_i45);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo",
      c22_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c22_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c22_i45);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c22_r0->resolved)),
                    "resolved", "nameCaptureInfo", c22_i45);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c22_i45);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c22_i45);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c22_i45);
  }

  sf_mex_assign(&c22_nameCaptureInfo, c22_m0);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(c22_ResolvedFunctionInfo c22_info[24])
{
  c22_info[0].context = "";
  c22_info[0].name = "pi";
  c22_info[0].dominantType = "";
  c22_info[0].resolved = "[B]pi";
  c22_info[0].fileLength = 0U;
  c22_info[0].fileTime1 = 0U;
  c22_info[0].fileTime2 = 0U;
  c22_info[1].context = "";
  c22_info[1].name = "mtimes";
  c22_info[1].dominantType = "double";
  c22_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[1].fileLength = 3302U;
  c22_info[1].fileTime1 = 1242738294U;
  c22_info[1].fileTime2 = 0U;
  c22_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[2].name = "nargin";
  c22_info[2].dominantType = "";
  c22_info[2].resolved = "[B]nargin";
  c22_info[2].fileLength = 0U;
  c22_info[2].fileTime1 = 0U;
  c22_info[2].fileTime2 = 0U;
  c22_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[3].name = "gt";
  c22_info[3].dominantType = "double";
  c22_info[3].resolved = "[B]gt";
  c22_info[3].fileLength = 0U;
  c22_info[3].fileTime1 = 0U;
  c22_info[3].fileTime2 = 0U;
  c22_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[4].name = "isa";
  c22_info[4].dominantType = "double";
  c22_info[4].resolved = "[B]isa";
  c22_info[4].fileLength = 0U;
  c22_info[4].fileTime1 = 0U;
  c22_info[4].fileTime2 = 0U;
  c22_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[5].name = "isinteger";
  c22_info[5].dominantType = "double";
  c22_info[5].resolved = "[B]isinteger";
  c22_info[5].fileLength = 0U;
  c22_info[5].fileTime1 = 0U;
  c22_info[5].fileTime2 = 0U;
  c22_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[6].name = "isscalar";
  c22_info[6].dominantType = "double";
  c22_info[6].resolved = "[B]isscalar";
  c22_info[6].fileLength = 0U;
  c22_info[6].fileTime1 = 0U;
  c22_info[6].fileTime2 = 0U;
  c22_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[7].name = "strcmp";
  c22_info[7].dominantType = "char";
  c22_info[7].resolved = "[B]strcmp";
  c22_info[7].fileLength = 0U;
  c22_info[7].fileTime1 = 0U;
  c22_info[7].fileTime2 = 0U;
  c22_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[8].name = "size";
  c22_info[8].dominantType = "double";
  c22_info[8].resolved = "[B]size";
  c22_info[8].fileLength = 0U;
  c22_info[8].fileTime1 = 0U;
  c22_info[8].fileTime2 = 0U;
  c22_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[9].name = "eq";
  c22_info[9].dominantType = "double";
  c22_info[9].resolved = "[B]eq";
  c22_info[9].fileLength = 0U;
  c22_info[9].fileTime1 = 0U;
  c22_info[9].fileTime2 = 0U;
  c22_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[10].name = "class";
  c22_info[10].dominantType = "double";
  c22_info[10].resolved = "[B]class";
  c22_info[10].fileLength = 0U;
  c22_info[10].fileTime1 = 0U;
  c22_info[10].fileTime2 = 0U;
  c22_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[11].name = "not";
  c22_info[11].dominantType = "logical";
  c22_info[11].resolved = "[B]not";
  c22_info[11].fileLength = 0U;
  c22_info[11].fileTime1 = 0U;
  c22_info[11].fileTime2 = 0U;
  c22_info[12].context = "";
  c22_info[12].name = "mrdivide";
  c22_info[12].dominantType = "double";
  c22_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c22_info[12].fileLength = 800U;
  c22_info[12].fileTime1 = 1238421692U;
  c22_info[12].fileTime2 = 0U;
  c22_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c22_info[13].name = "ge";
  c22_info[13].dominantType = "double";
  c22_info[13].resolved = "[B]ge";
  c22_info[13].fileLength = 0U;
  c22_info[13].fileTime1 = 0U;
  c22_info[13].fileTime2 = 0U;
  c22_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c22_info[14].name = "rdivide";
  c22_info[14].dominantType = "double";
  c22_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c22_info[14].fileLength = 620U;
  c22_info[14].fileTime1 = 1213914166U;
  c22_info[14].fileTime2 = 0U;
  c22_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c22_info[15].name = "isempty";
  c22_info[15].dominantType = "double";
  c22_info[15].resolved = "[B]isempty";
  c22_info[15].fileLength = 0U;
  c22_info[15].fileTime1 = 0U;
  c22_info[15].fileTime2 = 0U;
  c22_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c22_info[16].name = "eml_warning";
  c22_info[16].dominantType = "char";
  c22_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c22_info[16].fileLength = 262U;
  c22_info[16].fileTime1 = 1236241078U;
  c22_info[16].fileTime2 = 0U;
  c22_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c22_info[17].name = "eml_div";
  c22_info[17].dominantType = "double";
  c22_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c22_info[17].fileLength = 4269U;
  c22_info[17].fileTime1 = 1228077626U;
  c22_info[17].fileTime2 = 0U;
  c22_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c22_info[18].name = "isreal";
  c22_info[18].dominantType = "double";
  c22_info[18].resolved = "[B]isreal";
  c22_info[18].fileLength = 0U;
  c22_info[18].fileTime1 = 0U;
  c22_info[18].fileTime2 = 0U;
  c22_info[19].context = "";
  c22_info[19].name = "cos";
  c22_info[19].dominantType = "double";
  c22_info[19].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c22_info[19].fileLength = 324U;
  c22_info[19].fileTime1 = 1203431752U;
  c22_info[19].fileTime2 = 0U;
  c22_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c22_info[20].name = "eml_scalar_cos";
  c22_info[20].dominantType = "double";
  c22_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c22_info[20].fileLength = 602U;
  c22_info[20].fileTime1 = 1209318188U;
  c22_info[20].fileTime2 = 0U;
  c22_info[21].context = "";
  c22_info[21].name = "ones";
  c22_info[21].dominantType = "double";
  c22_info[21].resolved = "[B]ones";
  c22_info[21].fileLength = 0U;
  c22_info[21].fileTime1 = 0U;
  c22_info[21].fileTime2 = 0U;
  c22_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[22].name = "islogical";
  c22_info[22].dominantType = "logical";
  c22_info[22].resolved = "[B]islogical";
  c22_info[22].fileLength = 0U;
  c22_info[22].fileTime1 = 0U;
  c22_info[22].fileTime2 = 0U;
  c22_info[23].context = "";
  c22_info[23].name = "ctranspose";
  c22_info[23].dominantType = "double";
  c22_info[23].resolved = "[B]ctranspose";
  c22_info[23].fileLength = 0U;
  c22_info[23].fileTime1 = 0U;
  c22_info[23].fileTime2 = 0U;
}

static const mxArray *c22_f_sf_marshall(void *c22_chartInstance, void *c22_u)
{
  const mxArray *c22_y = NULL;
  boolean_T c22_b_u;
  const mxArray *c22_b_y = NULL;
  c22_y = NULL;
  c22_b_u = *((boolean_T *)c22_u);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c22_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4107692234U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4023775496U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1528981895U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(559812784U);
}

mxArray *sf_c22_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(220036720U);
    pr[1] = (double)(2170103373U);
    pr[2] = (double)(680503838U);
    pr[3] = (double)(3093059502U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(5);
      pr[1] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c22_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"m_SUN\",},{M[1],M[31],T\"values\",},{M[8],M[0],T\"is_active_c22_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           22,
           1,
           1,
           16,
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
                                1.0,0,"v_S1",0,(MexFcnForType)c22_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 5;
            dimVector[1]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_SUN",0,(MexFcnForType)c22_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"s_S1",0,
                              (MexFcnForType)c22_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_S2",0,(MexFcnForType)c22_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"s_S2",0,
                              (MexFcnForType)c22_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_S3",0,(MexFcnForType)c22_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"s_S3",0,
                              (MexFcnForType)c22_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_S4",0,(MexFcnForType)c22_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"s_S4",0,
                              (MexFcnForType)c22_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_S5",0,(MexFcnForType)c22_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"s_S5",0,
                              (MexFcnForType)c22_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_S6",0,(MexFcnForType)c22_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(12,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"s_S6",0,
                              (MexFcnForType)c22_b_sf_marshall);
          _SFD_SET_DATA_PROPS(13,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Snum",
                              0,(MexFcnForType)c22_b_sf_marshall);
          _SFD_SET_DATA_PROPS(14,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_SS_MAX_ANGLE",0,(MexFcnForType)
                              c22_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(15,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"values",0,(MexFcnForType)
                                c22_d_sf_marshall);
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
          real_T (*c22_v_S1)[3];
          real_T (*c22_m_SUN)[30];
          real_T *c22_s_S1;
          real_T (*c22_v_S2)[3];
          real_T *c22_s_S2;
          real_T (*c22_v_S3)[3];
          real_T *c22_s_S3;
          real_T (*c22_v_S4)[3];
          real_T *c22_s_S4;
          real_T (*c22_v_S5)[3];
          real_T *c22_s_S5;
          real_T (*c22_v_S6)[3];
          real_T *c22_s_S6;
          real_T (*c22_values)[6];
          c22_s_S5 = (real_T *)ssGetInputPortSignal(chartInstance.S, 9);
          c22_s_S2 = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c22_values = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 2);
          c22_v_S6 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 10);
          c22_v_S1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c22_v_S2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
          c22_s_S4 = (real_T *)ssGetInputPortSignal(chartInstance.S, 7);
          c22_v_S5 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 8);
          c22_s_S6 = (real_T *)ssGetInputPortSignal(chartInstance.S, 11);
          c22_s_S3 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c22_s_S1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c22_v_S3 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
          c22_m_SUN = (real_T (*)[30])ssGetOutputPortSignal(chartInstance.S, 1);
          c22_v_S4 = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 6);
          _SFD_SET_DATA_VALUE_PTR(0U, c22_v_S1);
          _SFD_SET_DATA_VALUE_PTR(1U, c22_m_SUN);
          _SFD_SET_DATA_VALUE_PTR(2U, c22_s_S1);
          _SFD_SET_DATA_VALUE_PTR(3U, c22_v_S2);
          _SFD_SET_DATA_VALUE_PTR(4U, c22_s_S2);
          _SFD_SET_DATA_VALUE_PTR(5U, c22_v_S3);
          _SFD_SET_DATA_VALUE_PTR(6U, c22_s_S3);
          _SFD_SET_DATA_VALUE_PTR(7U, c22_v_S4);
          _SFD_SET_DATA_VALUE_PTR(8U, c22_s_S4);
          _SFD_SET_DATA_VALUE_PTR(9U, c22_v_S5);
          _SFD_SET_DATA_VALUE_PTR(10U, c22_s_S5);
          _SFD_SET_DATA_VALUE_PTR(11U, c22_v_S6);
          _SFD_SET_DATA_VALUE_PTR(12U, c22_s_S6);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance.c22_Snum);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance.c22_s_SS_MAX_ANGLE);
          _SFD_SET_DATA_VALUE_PTR(15U, c22_values);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c22_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c22_adcs_v15_integral_Power();
  initialize_c22_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c22_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c22_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c22_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c22_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c22_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c22_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c22_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c22_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c22_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c22_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c22_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c22_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c22_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c22_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c22_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c22_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     Snum s_SS_MAX_ANGLE
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Snum*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for s_SS_MAX_ANGLE*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",22,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",22,12);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",22,2);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1197378079U));
  ssSetChecksum1(S,(1991616097U));
  ssSetChecksum2(S,(340865891U));
  ssSetChecksum3(S,(2595119196U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c22_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",22);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c22_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c22_adcs_v15_integral_Power;
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

void c22_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
