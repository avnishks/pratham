/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_sfun.h"
#include "c30_adcs_v15_integral_Power_nom.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c30_IN_NO_ACTIVE_CHILD         (0)
#define c30_b_today                    (734429.4375)
#define c30_b_equinox                  (734218.5)

/* Variable Declarations */

/* Variable Definitions */
static SFc30_adcs_v15_integral_Power_nomInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c30_adcs_v15_integral_Power_nom(void);
static void initialize_params_c30_adcs_v15_integral_Power_nom(void);
static void enable_c30_adcs_v15_integral_Power_nom(void);
static void disable_c30_adcs_v15_integral_Power_nom(void);
static void c30_update_debugger_state_c30_adcs_v15_integral_Power_nom(void);
static void ext_mode_exec_c30_adcs_v15_integral_Power_nom(void);
static const mxArray *get_sim_state_c30_adcs_v15_integral_Power_nom(void);
static void set_sim_state_c30_adcs_v15_integral_Power_nom(const mxArray *c30_st);
static void finalize_c30_adcs_v15_integral_Power_nom(void);
static void sf_c30_adcs_v15_integral_Power_nom(void);
static void c30_c30_adcs_v15_integral_Power_nom(void);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber);
static void c30_eml_scalar_eg(void);
static const mxArray *c30_sf_marshall(void *c30_chartInstance, void *c30_u);
static const mxArray *c30_b_sf_marshall(void *c30_chartInstance, void *c30_u);
static const mxArray *c30_c_sf_marshall(void *c30_chartInstance, void *c30_u);
static void c30_info_helper(c30_ResolvedFunctionInfo c30_info[49]);
static const mxArray *c30_d_sf_marshall(void *c30_chartInstance, void *c30_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c30_adcs_v15_integral_Power_nom(void)
{
  uint8_T *c30_is_active_c30_adcs_v15_integral_Power_nom;
  c30_is_active_c30_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c30_is_active_c30_adcs_v15_integral_Power_nom = 0U;
}

static void initialize_params_c30_adcs_v15_integral_Power_nom(void)
{
  real_T c30_d0;
  real_T c30_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'today' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c30_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c30_today = c30_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'equinox' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c30_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c30_equinox = c30_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c30_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c30_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c30_update_debugger_state_c30_adcs_v15_integral_Power_nom(void)
{
}

static void ext_mode_exec_c30_adcs_v15_integral_Power_nom(void)
{
  c30_update_debugger_state_c30_adcs_v15_integral_Power_nom();
}

static const mxArray *get_sim_state_c30_adcs_v15_integral_Power_nom(void)
{
  const mxArray *c30_st = NULL;
  const mxArray *c30_y = NULL;
  int32_T c30_i0;
  real_T c30_u[3];
  const mxArray *c30_b_y = NULL;
  uint8_T c30_b_u;
  const mxArray *c30_c_y = NULL;
  uint8_T *c30_is_active_c30_adcs_v15_integral_Power_nom;
  real_T (*c30_r_ECEF)[3];
  c30_is_active_c30_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c30_r_ECEF = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellarray(2));
  for (c30_i0 = 0; c30_i0 < 3; c30_i0 = c30_i0 + 1) {
    c30_u[c30_i0] = (*c30_r_ECEF)[c30_i0];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_b_u = *c30_is_active_c30_adcs_v15_integral_Power_nom;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c30_y, 1, c30_c_y);
  sf_mex_assign(&c30_st, c30_y);
  return c30_st;
}

static void set_sim_state_c30_adcs_v15_integral_Power_nom(const mxArray *c30_st)
{
  const mxArray *c30_u;
  const mxArray *c30_r_ECEF;
  real_T c30_dv0[3];
  int32_T c30_i1;
  real_T c30_y[3];
  int32_T c30_i2;
  const mxArray *c30_is_active_c30_adcs_v15_integral_Power_nom;
  uint8_T c30_u0;
  uint8_T c30_b_y;
  boolean_T *c30_doneDoubleBufferReInit;
  uint8_T *c30_b_is_active_c30_adcs_v15_integral_Power_nom;
  real_T (*c30_b_r_ECEF)[3];
  c30_b_is_active_c30_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c30_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c30_b_r_ECEF = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  *c30_doneDoubleBufferReInit = true;
  c30_u = sf_mex_dup(c30_st);
  c30_r_ECEF = sf_mex_dup(sf_mex_getcell(c30_u, 0));
  sf_mex_import("r_ECEF", sf_mex_dup(c30_r_ECEF), &c30_dv0, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c30_i1 = 0; c30_i1 < 3; c30_i1 = c30_i1 + 1) {
    c30_y[c30_i1] = c30_dv0[c30_i1];
  }

  sf_mex_destroy(&c30_r_ECEF);
  for (c30_i2 = 0; c30_i2 < 3; c30_i2 = c30_i2 + 1) {
    (*c30_b_r_ECEF)[c30_i2] = c30_y[c30_i2];
  }

  c30_is_active_c30_adcs_v15_integral_Power_nom = sf_mex_dup(sf_mex_getcell
    (c30_u, 1));
  sf_mex_import("is_active_c30_adcs_v15_integral_Power_nom", sf_mex_dup
                (c30_is_active_c30_adcs_v15_integral_Power_nom), &c30_u0, 1, 3
                , 0U, 0, 0U, 0);
  c30_b_y = c30_u0;
  sf_mex_destroy(&c30_is_active_c30_adcs_v15_integral_Power_nom);
  *c30_b_is_active_c30_adcs_v15_integral_Power_nom = c30_b_y;
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_adcs_v15_integral_Power_nom();
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_adcs_v15_integral_Power_nom(void)
{
}

static void sf_c30_adcs_v15_integral_Power_nom(void)
{
  int32_T c30_i3;
  int32_T c30_i4;
  int32_T c30_previousEvent;
  real_T *c30_t;
  real_T (*c30_r_I)[3];
  real_T (*c30_r_ECEF)[3];
  c30_r_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c30_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c30_r_ECEF = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,23);
  _SFD_DATA_RANGE_CHECK(chartInstance.c30_today, 0U);
  for (c30_i3 = 0; c30_i3 < 3; c30_i3 = c30_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c30_r_ECEF)[c30_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c30_equinox, 2U);
  for (c30_i4 = 0; c30_i4 < 3; c30_i4 = c30_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c30_r_I)[c30_i4], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c30_t, 4U);
  c30_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c30_c30_adcs_v15_integral_Power_nom();
  _sfEvent_ = c30_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nomMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c30_c30_adcs_v15_integral_Power_nom(void)
{
  int32_T c30_i5;
  real_T c30_r_I[3];
  real_T c30_t;
  real_T c30_nargout = 1.0;
  real_T c30_nargin = 4.0;
  real_T c30_c_equinox = c30_b_equinox;
  real_T c30_c_today = c30_b_today;
  real_T c30_TEI[9];
  real_T c30_phi;
  real_T c30_st_sec;
  real_T c30_ut_sec;
  real_T c30_W_EARTH_ROT;
  real_T c30_stperut;
  real_T c30_r_ECEF[3];
  real_T c30_b;
  real_T c30_a;
  real_T c30_x;
  real_T c30_b_x;
  real_T c30_c_x;
  real_T c30_d_x;
  real_T c30_e_x;
  real_T c30_f_x;
  real_T c30_g_x;
  real_T c30_h_x;
  real_T c30_i_x;
  real_T c30_j_x;
  real_T c30_k_x;
  real_T c30_l_x;
  int32_T c30_i6;
  int32_T c30_i7;
  static real_T c30_dv1[3] = { 0.0, 0.0, 1.0 };

  int32_T c30_i8;
  real_T c30_b_a[9];
  int32_T c30_i9;
  real_T c30_b_b[3];
  int32_T c30_i10;
  real_T c30_A[9];
  int32_T c30_i11;
  real_T c30_B[3];
  int32_T c30_i12;
  int32_T c30_i13;
  real_T c30_b_A[9];
  int32_T c30_i14;
  real_T c30_b_B[3];
  int32_T c30_i15;
  real_T c30_c_A[9];
  int32_T c30_i16;
  real_T c30_c_B[3];
  int32_T c30_i17;
  int32_T c30_i18;
  int32_T c30_i19;
  int32_T c30_i20;
  real_T *c30_b_t;
  real_T (*c30_b_r_ECEF)[3];
  real_T (*c30_b_r_I)[3];
  c30_b_r_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c30_b_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c30_b_r_ECEF = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,23);
  for (c30_i5 = 0; c30_i5 < 3; c30_i5 = c30_i5 + 1) {
    c30_r_I[c30_i5] = (*c30_b_r_I)[c30_i5];
  }

  c30_t = *c30_b_t;
  sf_debug_symbol_scope_push(13U, 0U);
  sf_debug_symbol_scope_add("nargout", &c30_nargout, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c30_nargin, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("equinox", &c30_c_equinox, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("today", &c30_c_today, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("TEI", &c30_TEI, c30_c_sf_marshall);
  sf_debug_symbol_scope_add("phi", &c30_phi, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("st_sec", &c30_st_sec, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("ut_sec", &c30_ut_sec, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("W_EARTH_ROT", &c30_W_EARTH_ROT, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("stperut", &c30_stperut, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("r_ECEF", &c30_r_ECEF, c30_sf_marshall);
  sf_debug_symbol_scope_add("t", &c30_t, c30_b_sf_marshall);
  sf_debug_symbol_scope_add("r_I", &c30_r_I, c30_sf_marshall);
  CV_EML_FCN(0, 0);

  /* u: position vector in ECI (in m) */
  /* y: position vector in ECEF (in m) */
  _SFD_EML_CALL(0,5);
  c30_stperut = 1.0027379093500000E+000;

  /*  siderial time = stperut * universal time */
  _SFD_EML_CALL(0,6);
  c30_W_EARTH_ROT = 7.2940705438520400E-005;

  /*  sidereal rotation angular velocity of earth, SI */
  _SFD_EML_CALL(0,8);
  c30_ut_sec = 1.8225E+007 + c30_t;

  /*  universal time vector in sec */
  _SFD_EML_CALL(0,9);
  c30_b = c30_ut_sec;
  c30_st_sec = 1.0027379093500000E+000 * c30_b;

  /*  sidereal time vector in sec */
  _SFD_EML_CALL(0,11);
  c30_a = c30_st_sec;
  c30_phi = c30_a * 7.2940705438520400E-005;

  /*  sidereal time vector in rad */
  _SFD_EML_CALL(0,13);
  c30_x = c30_phi;
  c30_b_x = c30_x;
  c30_c_x = c30_b_x;
  c30_b_x = c30_c_x;
  c30_b_x = muDoubleScalarCos(c30_b_x);
  c30_d_x = c30_phi;
  c30_e_x = c30_d_x;
  c30_f_x = c30_e_x;
  c30_e_x = c30_f_x;
  c30_e_x = muDoubleScalarSin(c30_e_x);
  c30_g_x = c30_phi;
  c30_h_x = c30_g_x;
  c30_i_x = c30_h_x;
  c30_h_x = c30_i_x;
  c30_h_x = muDoubleScalarSin(c30_h_x);
  c30_j_x = c30_phi;
  c30_k_x = c30_j_x;
  c30_l_x = c30_k_x;
  c30_k_x = c30_l_x;
  c30_k_x = muDoubleScalarCos(c30_k_x);
  c30_TEI[0] = c30_k_x;
  c30_TEI[3] = c30_h_x;
  c30_TEI[6] = 0.0;
  c30_TEI[1] = -c30_e_x;
  c30_TEI[4] = c30_b_x;
  c30_TEI[7] = 0.0;
  c30_i6 = 0;
  for (c30_i7 = 0; c30_i7 < 3; c30_i7 = c30_i7 + 1) {
    c30_TEI[c30_i6 + 2] = c30_dv1[c30_i7];
    c30_i6 = c30_i6 + 3;
  }

  _SFD_EML_CALL(0,17);
  for (c30_i8 = 0; c30_i8 < 9; c30_i8 = c30_i8 + 1) {
    c30_b_a[c30_i8] = c30_TEI[c30_i8];
  }

  for (c30_i9 = 0; c30_i9 < 3; c30_i9 = c30_i9 + 1) {
    c30_b_b[c30_i9] = c30_r_I[c30_i9];
  }

  c30_eml_scalar_eg();
  c30_eml_scalar_eg();
  for (c30_i10 = 0; c30_i10 < 9; c30_i10 = c30_i10 + 1) {
    c30_A[c30_i10] = c30_b_a[c30_i10];
  }

  for (c30_i11 = 0; c30_i11 < 3; c30_i11 = c30_i11 + 1) {
    c30_B[c30_i11] = c30_b_b[c30_i11];
  }

  for (c30_i12 = 0; c30_i12 < 3; c30_i12 = c30_i12 + 1) {
    c30_r_ECEF[c30_i12] = 0.0;
  }

  for (c30_i13 = 0; c30_i13 < 9; c30_i13 = c30_i13 + 1) {
    c30_b_A[c30_i13] = c30_A[c30_i13];
  }

  for (c30_i14 = 0; c30_i14 < 3; c30_i14 = c30_i14 + 1) {
    c30_b_B[c30_i14] = c30_B[c30_i14];
  }

  for (c30_i15 = 0; c30_i15 < 9; c30_i15 = c30_i15 + 1) {
    c30_c_A[c30_i15] = c30_b_A[c30_i15];
  }

  for (c30_i16 = 0; c30_i16 < 3; c30_i16 = c30_i16 + 1) {
    c30_c_B[c30_i16] = c30_b_B[c30_i16];
  }

  for (c30_i17 = 0; c30_i17 < 3; c30_i17 = c30_i17 + 1) {
    c30_r_ECEF[c30_i17] = 0.0;
    c30_i18 = 0;
    for (c30_i19 = 0; c30_i19 < 3; c30_i19 = c30_i19 + 1) {
      c30_r_ECEF[c30_i17] = c30_r_ECEF[c30_i17] + c30_c_A[c30_i18 + c30_i17] *
        c30_c_B[c30_i19];
      c30_i18 = c30_i18 + 3;
    }
  }

  _SFD_EML_CALL(0,-17);
  sf_debug_symbol_scope_pop();
  for (c30_i20 = 0; c30_i20 < 3; c30_i20 = c30_i20 + 1) {
    (*c30_b_r_ECEF)[c30_i20] = c30_r_ECEF[c30_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,23);
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber)
{
}

static void c30_eml_scalar_eg(void)
{
}

static const mxArray *c30_sf_marshall(void *c30_chartInstance, void *c30_u)
{
  const mxArray *c30_y = NULL;
  int32_T c30_i21;
  real_T c30_b_u[3];
  const mxArray *c30_b_y = NULL;
  c30_y = NULL;
  for (c30_i21 = 0; c30_i21 < 3; c30_i21 = c30_i21 + 1) {
    c30_b_u[c30_i21] = (*((real_T (*)[3])c30_u))[c30_i21];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c30_y, c30_b_y);
  return c30_y;
}

static const mxArray *c30_b_sf_marshall(void *c30_chartInstance, void *c30_u)
{
  const mxArray *c30_y = NULL;
  real_T c30_b_u;
  const mxArray *c30_b_y = NULL;
  c30_y = NULL;
  c30_b_u = *((real_T *)c30_u);
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c30_y, c30_b_y);
  return c30_y;
}

static const mxArray *c30_c_sf_marshall(void *c30_chartInstance, void *c30_u)
{
  const mxArray *c30_y = NULL;
  int32_T c30_i22;
  int32_T c30_i23;
  int32_T c30_i24;
  real_T c30_b_u[9];
  const mxArray *c30_b_y = NULL;
  c30_y = NULL;
  c30_i22 = 0;
  for (c30_i23 = 0; c30_i23 < 3; c30_i23 = c30_i23 + 1) {
    for (c30_i24 = 0; c30_i24 < 3; c30_i24 = c30_i24 + 1) {
      c30_b_u[c30_i24 + c30_i22] = (*((real_T (*)[9])c30_u))[c30_i24 + c30_i22];
    }

    c30_i22 = c30_i22 + 3;
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c30_y, c30_b_y);
  return c30_y;
}

const mxArray
  *sf_c30_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_ResolvedFunctionInfo c30_info[49];
  const mxArray *c30_m0 = NULL;
  int32_T c30_i25;
  c30_ResolvedFunctionInfo *c30_r0;
  c30_nameCaptureInfo = NULL;
  c30_info_helper(c30_info);
  sf_mex_assign(&c30_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for (c30_i25 = 0; c30_i25 < 49; c30_i25 = c30_i25 + 1) {
    c30_r0 = &c30_info[c30_i25];
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", c30_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c30_r0->context)), "context"
                    , "nameCaptureInfo", c30_i25);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", c30_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c30_r0->name)), "name",
                    "nameCaptureInfo", c30_i25);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo",
      c30_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c30_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c30_i25);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", c30_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c30_r0->resolved)),
                    "resolved", "nameCaptureInfo", c30_i25);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c30_i25);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c30_i25);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c30_i25);
  }

  sf_mex_assign(&c30_nameCaptureInfo, c30_m0);
  return c30_nameCaptureInfo;
}

static void c30_info_helper(c30_ResolvedFunctionInfo c30_info[49])
{
  c30_info[0].context = "";
  c30_info[0].name = "pi";
  c30_info[0].dominantType = "";
  c30_info[0].resolved = "[B]pi";
  c30_info[0].fileLength = 0U;
  c30_info[0].fileTime1 = 0U;
  c30_info[0].fileTime2 = 0U;
  c30_info[1].context = "";
  c30_info[1].name = "mtimes";
  c30_info[1].dominantType = "double";
  c30_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[1].fileLength = 3302U;
  c30_info[1].fileTime1 = 1242738294U;
  c30_info[1].fileTime2 = 0U;
  c30_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[2].name = "nargin";
  c30_info[2].dominantType = "";
  c30_info[2].resolved = "[B]nargin";
  c30_info[2].fileLength = 0U;
  c30_info[2].fileTime1 = 0U;
  c30_info[2].fileTime2 = 0U;
  c30_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[3].name = "gt";
  c30_info[3].dominantType = "double";
  c30_info[3].resolved = "[B]gt";
  c30_info[3].fileLength = 0U;
  c30_info[3].fileTime1 = 0U;
  c30_info[3].fileTime2 = 0U;
  c30_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[4].name = "isa";
  c30_info[4].dominantType = "double";
  c30_info[4].resolved = "[B]isa";
  c30_info[4].fileLength = 0U;
  c30_info[4].fileTime1 = 0U;
  c30_info[4].fileTime2 = 0U;
  c30_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[5].name = "isinteger";
  c30_info[5].dominantType = "double";
  c30_info[5].resolved = "[B]isinteger";
  c30_info[5].fileLength = 0U;
  c30_info[5].fileTime1 = 0U;
  c30_info[5].fileTime2 = 0U;
  c30_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[6].name = "isscalar";
  c30_info[6].dominantType = "double";
  c30_info[6].resolved = "[B]isscalar";
  c30_info[6].fileLength = 0U;
  c30_info[6].fileTime1 = 0U;
  c30_info[6].fileTime2 = 0U;
  c30_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[7].name = "strcmp";
  c30_info[7].dominantType = "char";
  c30_info[7].resolved = "[B]strcmp";
  c30_info[7].fileLength = 0U;
  c30_info[7].fileTime1 = 0U;
  c30_info[7].fileTime2 = 0U;
  c30_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[8].name = "size";
  c30_info[8].dominantType = "double";
  c30_info[8].resolved = "[B]size";
  c30_info[8].fileLength = 0U;
  c30_info[8].fileTime1 = 0U;
  c30_info[8].fileTime2 = 0U;
  c30_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[9].name = "eq";
  c30_info[9].dominantType = "double";
  c30_info[9].resolved = "[B]eq";
  c30_info[9].fileLength = 0U;
  c30_info[9].fileTime1 = 0U;
  c30_info[9].fileTime2 = 0U;
  c30_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[10].name = "class";
  c30_info[10].dominantType = "double";
  c30_info[10].resolved = "[B]class";
  c30_info[10].fileLength = 0U;
  c30_info[10].fileTime1 = 0U;
  c30_info[10].fileTime2 = 0U;
  c30_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[11].name = "not";
  c30_info[11].dominantType = "logical";
  c30_info[11].resolved = "[B]not";
  c30_info[11].fileLength = 0U;
  c30_info[11].fileTime1 = 0U;
  c30_info[11].fileTime2 = 0U;
  c30_info[12].context = "";
  c30_info[12].name = "mrdivide";
  c30_info[12].dominantType = "double";
  c30_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c30_info[12].fileLength = 800U;
  c30_info[12].fileTime1 = 1238421692U;
  c30_info[12].fileTime2 = 0U;
  c30_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c30_info[13].name = "ge";
  c30_info[13].dominantType = "double";
  c30_info[13].resolved = "[B]ge";
  c30_info[13].fileLength = 0U;
  c30_info[13].fileTime1 = 0U;
  c30_info[13].fileTime2 = 0U;
  c30_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c30_info[14].name = "rdivide";
  c30_info[14].dominantType = "double";
  c30_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c30_info[14].fileLength = 620U;
  c30_info[14].fileTime1 = 1213914166U;
  c30_info[14].fileTime2 = 0U;
  c30_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c30_info[15].name = "isempty";
  c30_info[15].dominantType = "double";
  c30_info[15].resolved = "[B]isempty";
  c30_info[15].fileLength = 0U;
  c30_info[15].fileTime1 = 0U;
  c30_info[15].fileTime2 = 0U;
  c30_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c30_info[16].name = "eml_warning";
  c30_info[16].dominantType = "char";
  c30_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c30_info[16].fileLength = 262U;
  c30_info[16].fileTime1 = 1236241078U;
  c30_info[16].fileTime2 = 0U;
  c30_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c30_info[17].name = "eml_div";
  c30_info[17].dominantType = "double";
  c30_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c30_info[17].fileLength = 4269U;
  c30_info[17].fileTime1 = 1228077626U;
  c30_info[17].fileTime2 = 0U;
  c30_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c30_info[18].name = "isreal";
  c30_info[18].dominantType = "double";
  c30_info[18].resolved = "[B]isreal";
  c30_info[18].fileLength = 0U;
  c30_info[18].fileTime1 = 0U;
  c30_info[18].fileTime2 = 0U;
  c30_info[19].context = "";
  c30_info[19].name = "minus";
  c30_info[19].dominantType = "double";
  c30_info[19].resolved = "[B]minus";
  c30_info[19].fileLength = 0U;
  c30_info[19].fileTime1 = 0U;
  c30_info[19].fileTime2 = 0U;
  c30_info[20].context = "";
  c30_info[20].name = "plus";
  c30_info[20].dominantType = "double";
  c30_info[20].resolved = "[B]plus";
  c30_info[20].fileLength = 0U;
  c30_info[20].fileTime1 = 0U;
  c30_info[20].fileTime2 = 0U;
  c30_info[21].context = "";
  c30_info[21].name = "cos";
  c30_info[21].dominantType = "double";
  c30_info[21].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c30_info[21].fileLength = 324U;
  c30_info[21].fileTime1 = 1203431752U;
  c30_info[21].fileTime2 = 0U;
  c30_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c30_info[22].name = "eml_scalar_cos";
  c30_info[22].dominantType = "double";
  c30_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c30_info[22].fileLength = 602U;
  c30_info[22].fileTime1 = 1209318188U;
  c30_info[22].fileTime2 = 0U;
  c30_info[23].context = "";
  c30_info[23].name = "sin";
  c30_info[23].dominantType = "double";
  c30_info[23].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c30_info[23].fileLength = 324U;
  c30_info[23].fileTime1 = 1203431842U;
  c30_info[23].fileTime2 = 0U;
  c30_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c30_info[24].name = "eml_scalar_sin";
  c30_info[24].dominantType = "double";
  c30_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c30_info[24].fileLength = 601U;
  c30_info[24].fileTime1 = 1209318192U;
  c30_info[24].fileTime2 = 0U;
  c30_info[25].context = "";
  c30_info[25].name = "uminus";
  c30_info[25].dominantType = "double";
  c30_info[25].resolved = "[B]uminus";
  c30_info[25].fileLength = 0U;
  c30_info[25].fileTime1 = 0U;
  c30_info[25].fileTime2 = 0U;
  c30_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[26].name = "ndims";
  c30_info[26].dominantType = "double";
  c30_info[26].resolved = "[B]ndims";
  c30_info[26].fileLength = 0U;
  c30_info[26].fileTime1 = 0U;
  c30_info[26].fileTime2 = 0U;
  c30_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[27].name = "le";
  c30_info[27].dominantType = "double";
  c30_info[27].resolved = "[B]le";
  c30_info[27].fileLength = 0U;
  c30_info[27].fileTime1 = 0U;
  c30_info[27].fileTime2 = 0U;
  c30_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[28].name = "ne";
  c30_info[28].dominantType = "logical";
  c30_info[28].resolved = "[B]ne";
  c30_info[28].fileLength = 0U;
  c30_info[28].fileTime1 = 0U;
  c30_info[28].fileTime2 = 0U;
  c30_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[29].name = "eml_index_class";
  c30_info[29].dominantType = "";
  c30_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c30_info[29].fileLength = 909U;
  c30_info[29].fileTime1 = 1192454182U;
  c30_info[29].fileTime2 = 0U;
  c30_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[30].name = "ones";
  c30_info[30].dominantType = "char";
  c30_info[30].resolved = "[B]ones";
  c30_info[30].fileLength = 0U;
  c30_info[30].fileTime1 = 0U;
  c30_info[30].fileTime2 = 0U;
  c30_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[31].name = "cast";
  c30_info[31].dominantType = "double";
  c30_info[31].resolved = "[B]cast";
  c30_info[31].fileLength = 0U;
  c30_info[31].fileTime1 = 0U;
  c30_info[31].fileTime2 = 0U;
  c30_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[32].name = "eml_scalar_eg";
  c30_info[32].dominantType = "double";
  c30_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c30_info[32].fileLength = 3068U;
  c30_info[32].fileTime1 = 1240249410U;
  c30_info[32].fileTime2 = 0U;
  c30_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c30_info[33].name = "false";
  c30_info[33].dominantType = "";
  c30_info[33].resolved = "[B]false";
  c30_info[33].fileLength = 0U;
  c30_info[33].fileTime1 = 0U;
  c30_info[33].fileTime2 = 0U;
  c30_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c30_info[34].name = "isstruct";
  c30_info[34].dominantType = "double";
  c30_info[34].resolved = "[B]isstruct";
  c30_info[34].fileLength = 0U;
  c30_info[34].fileTime1 = 0U;
  c30_info[34].fileTime2 = 0U;
  c30_info[35].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c30_info[35].name = "eml_xgemm";
  c30_info[35].dominantType = "int32";
  c30_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c30_info[35].fileLength = 3184U;
  c30_info[35].fileTime1 = 1209318252U;
  c30_info[35].fileTime2 = 0U;
  c30_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c30_info[36].name = "lt";
  c30_info[36].dominantType = "int32";
  c30_info[36].resolved = "[B]lt";
  c30_info[36].fileLength = 0U;
  c30_info[36].fileTime1 = 0U;
  c30_info[36].fileTime2 = 0U;
  c30_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c30_info[37].name = "length";
  c30_info[37].dominantType = "double";
  c30_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c30_info[37].fileLength = 326U;
  c30_info[37].fileTime1 = 1226561076U;
  c30_info[37].fileTime2 = 0U;
  c30_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c30_info[38].name = "min";
  c30_info[38].dominantType = "double";
  c30_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c30_info[38].fileLength = 308U;
  c30_info[38].fileTime1 = 1192454034U;
  c30_info[38].fileTime2 = 0U;
  c30_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c30_info[39].name = "nargout";
  c30_info[39].dominantType = "";
  c30_info[39].resolved = "[B]nargout";
  c30_info[39].fileLength = 0U;
  c30_info[39].fileTime1 = 0U;
  c30_info[39].fileTime2 = 0U;
  c30_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c30_info[40].name = "eml_min_or_max";
  c30_info[40].dominantType = "char";
  c30_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c30_info[40].fileLength = 9969U;
  c30_info[40].fileTime1 = 1240249408U;
  c30_info[40].fileTime2 = 0U;
  c30_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c30_info[41].name = "ischar";
  c30_info[41].dominantType = "char";
  c30_info[41].resolved = "[B]ischar";
  c30_info[41].fileLength = 0U;
  c30_info[41].fileTime1 = 0U;
  c30_info[41].fileTime2 = 0U;
  c30_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c30_info[42].name = "isnumeric";
  c30_info[42].dominantType = "double";
  c30_info[42].resolved = "[B]isnumeric";
  c30_info[42].fileLength = 0U;
  c30_info[42].fileTime1 = 0U;
  c30_info[42].fileTime2 = 0U;
  c30_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c30_info[43].name = "islogical";
  c30_info[43].dominantType = "double";
  c30_info[43].resolved = "[B]islogical";
  c30_info[43].fileLength = 0U;
  c30_info[43].fileTime1 = 0U;
  c30_info[43].fileTime2 = 0U;
  c30_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c30_info[44].name = "eml_scalexp_alloc";
  c30_info[44].dominantType = "double";
  c30_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c30_info[44].fileLength = 808U;
  c30_info[44].fileTime1 = 1230478500U;
  c30_info[44].fileTime2 = 0U;
  c30_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c30_info[45].name = "eml_refblas_xgemm";
  c30_info[45].dominantType = "int32";
  c30_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c30_info[45].fileLength = 5748U;
  c30_info[45].fileTime1 = 1228077674U;
  c30_info[45].fileTime2 = 0U;
  c30_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c30_info[46].name = "eml_index_minus";
  c30_info[46].dominantType = "int32";
  c30_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c30_info[46].fileLength = 277U;
  c30_info[46].fileTime1 = 1192454184U;
  c30_info[46].fileTime2 = 0U;
  c30_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c30_info[47].name = "eml_index_times";
  c30_info[47].dominantType = "int32";
  c30_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c30_info[47].fileLength = 280U;
  c30_info[47].fileTime1 = 1192454188U;
  c30_info[47].fileTime2 = 0U;
  c30_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c30_info[48].name = "eml_index_plus";
  c30_info[48].dominantType = "int32";
  c30_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c30_info[48].fileLength = 272U;
  c30_info[48].fileTime1 = 1192454186U;
  c30_info[48].fileTime2 = 0U;
}

static const mxArray *c30_d_sf_marshall(void *c30_chartInstance, void *c30_u)
{
  const mxArray *c30_y = NULL;
  boolean_T c30_b_u;
  const mxArray *c30_b_y = NULL;
  c30_y = NULL;
  c30_b_u = *((boolean_T *)c30_u);
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c30_y, c30_b_y);
  return c30_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c30_adcs_v15_integral_Power_nom_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3713026880U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2253519336U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1372889161U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1111974474U);
}

mxArray *sf_c30_adcs_v15_integral_Power_nom_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(652849726U);
    pr[1] = (double)(1577147080U);
    pr[2] = (double)(2382466030U);
    pr[3] = (double)(3496792216U);
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

static mxArray *sf_get_sim_state_info_c30_adcs_v15_integral_Power_nom(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"r_ECEF\",},{M[8],M[0],T\"is_active_c30_adcs_v15_integral_Power_nom\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_adcs_v15_integral_Power_nom_get_check_sum(&mxChecksum);
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
           30,
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
          _SFD_SET_DATA_PROPS(0,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"today",
                              0,(MexFcnForType)c30_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"r_ECEF",0,(MexFcnForType)c30_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "equinox",0,(MexFcnForType)c30_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"r_I",0,(MexFcnForType)c30_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t",0,
                              (MexFcnForType)c30_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,568);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c30_r_ECEF)[3];
          real_T (*c30_r_I)[3];
          real_T *c30_t;
          c30_r_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c30_t = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c30_r_ECEF = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance.c30_today);
          _SFD_SET_DATA_VALUE_PTR(1U, c30_r_ECEF);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance.c30_equinox);
          _SFD_SET_DATA_VALUE_PTR(3U, c30_r_I);
          _SFD_SET_DATA_VALUE_PTR(4U, c30_t);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_nomMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c30_adcs_v15_integral_Power_nom();
  initialize_c30_adcs_v15_integral_Power_nom();
}

static void sf_opaque_enable_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  enable_c30_adcs_v15_integral_Power_nom();
}

static void sf_opaque_disable_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  disable_c30_adcs_v15_integral_Power_nom();
}

static void sf_opaque_gateway_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  sf_c30_adcs_v15_integral_Power_nom();
}

static void sf_opaque_ext_mode_exec_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  ext_mode_exec_c30_adcs_v15_integral_Power_nom();
}

static mxArray* sf_opaque_get_sim_state_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c30_adcs_v15_integral_Power_nom();
  return st;
}

static void sf_opaque_set_sim_state_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c30_adcs_v15_integral_Power_nom(sf_mex_dup(st));
}

static void sf_opaque_terminate_c30_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c30_adcs_v15_integral_Power_nom();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_adcs_v15_integral_Power_nom(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c30_adcs_v15_integral_Power_nom();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c30_adcs_v15_integral_Power_nom(SimStruct *S)
{
  /* Actual parameters from chart:
     equinox today
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for equinox*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for today*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_nom",
                "adcs_v15_integral_Power_nom",30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom","adcs_v15_integral_Power_nom",30,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",30,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",30,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom",
                          "adcs_v15_integral_Power_nom",30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3353404613U));
  ssSetChecksum1(S,(2985191647U));
  ssSetChecksum2(S,(1313161485U));
  ssSetChecksum3(S,(2667465632U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c30_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",30);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_adcs_v15_integral_Power_nom(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlStart = mdlStart_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c30_adcs_v15_integral_Power_nom;
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

void c30_adcs_v15_integral_Power_nom_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_adcs_v15_integral_Power_nom(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_adcs_v15_integral_Power_nom_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
