/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_no_charge_in_detumb_sfun.h"
#include "c28_adcs_v15_integral_Power_no_charge_in_detumb.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_no_charge_in_detumb_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c28_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc28_adcs_v15_integral_Power_no_charge_in_detumbInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void initialize_params_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void);
static void enable_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void disable_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void c28_update_debugger_state_c28_adcs_v15_integral_Power_no_charge(void);
static void ext_mode_exec_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static const mxArray
  *get_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void set_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(const
  mxArray *c28_st);
static void finalize_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void sf_c28_adcs_v15_integral_Power_no_charge_in_detumb(void);
static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber);
static real_T c28_genpnorm(real_T c28_x[3], real_T c28_p);
static real_T c28_eml_xnrm2(real_T c28_x[3]);
static real_T c28_ceval_xnrm2(int32_T c28_n, real_T c28_x[3], real_T c28_ix0,
  int32_T c28_incx);
static real_T c28_power(real_T c28_a, real_T c28_b);
static void c28_eml_scalar_eg(void);
static void c28_eml_error(void);
static void c28_eml_warning(void);
static void c28_b_eml_error(void);
static const mxArray *c28_sf_marshall(void *c28_chartInstance, void *c28_u);
static const mxArray *c28_b_sf_marshall(void *c28_chartInstance, void *c28_u);
static void c28_info_helper(c28_ResolvedFunctionInfo c28_info[64]);
static const mxArray *c28_c_sf_marshall(void *c28_chartInstance, void *c28_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  uint8_T *c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb = 0U;
}

static void initialize_params_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void)
{
}

static void enable_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c28_update_debugger_state_c28_adcs_v15_integral_Power_no_charge(void)
{
}

static void ext_mode_exec_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  c28_update_debugger_state_c28_adcs_v15_integral_Power_no_charge();
}

static const mxArray
  *get_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  const mxArray *c28_st = NULL;
  const mxArray *c28_y = NULL;
  real_T c28_u;
  const mxArray *c28_b_y = NULL;
  real_T c28_b_u;
  const mxArray *c28_c_y = NULL;
  real_T c28_c_u;
  const mxArray *c28_d_y = NULL;
  uint8_T c28_d_u;
  const mxArray *c28_e_y = NULL;
  real_T *c28_Altitude;
  real_T *c28_Latitutde;
  real_T *c28_Longitude;
  uint8_T *c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  c28_Altitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c28_Longitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c28_Latitutde = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellarray(4));
  c28_u = *c28_Altitude;
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_b_u = *c28_Latitutde;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c28_y, 1, c28_c_y);
  c28_c_u = *c28_Longitude;
  c28_d_y = NULL;
  sf_mex_assign(&c28_d_y, sf_mex_create("y", &c28_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c28_y, 2, c28_d_y);
  c28_d_u = *c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  c28_e_y = NULL;
  sf_mex_assign(&c28_e_y, sf_mex_create("y", &c28_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c28_y, 3, c28_e_y);
  sf_mex_assign(&c28_st, c28_y);
  return c28_st;
}

static void set_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(const
  mxArray *c28_st)
{
  const mxArray *c28_u;
  const mxArray *c28_Altitude;
  real_T c28_d0;
  real_T c28_y;
  const mxArray *c28_b_Altitude;
  real_T c28_d1;
  real_T c28_b_y;
  const mxArray *c28_c_Altitude;
  real_T c28_d2;
  real_T c28_c_y;
  const mxArray *c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T c28_u0;
  uint8_T c28_d_y;
  boolean_T *c28_doneDoubleBufferReInit;
  real_T *c28_d_Altitude;
  real_T *c28_Latitutde;
  real_T *c28_Longitude;
  uint8_T *c28_b_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  c28_d_Altitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c28_Longitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c28_Latitutde = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c28_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c28_b_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c28_doneDoubleBufferReInit = true;
  c28_u = sf_mex_dup(c28_st);
  c28_Altitude = sf_mex_dup(sf_mex_getcell(c28_u, 0));
  sf_mex_import("Altitude", sf_mex_dup(c28_Altitude), &c28_d0, 1, 0, 0U, 0, 0U,
                0);
  c28_y = c28_d0;
  sf_mex_destroy(&c28_Altitude);
  *c28_d_Altitude = c28_y;
  c28_b_Altitude = sf_mex_dup(sf_mex_getcell(c28_u, 1));
  sf_mex_import("Latitutde", sf_mex_dup(c28_b_Altitude), &c28_d1, 1, 0, 0U, 0,
                0U, 0);
  c28_b_y = c28_d1;
  sf_mex_destroy(&c28_b_Altitude);
  *c28_Latitutde = c28_b_y;
  c28_c_Altitude = sf_mex_dup(sf_mex_getcell(c28_u, 2));
  sf_mex_import("Longitude", sf_mex_dup(c28_c_Altitude), &c28_d2, 1, 0, 0U, 0,
                0U, 0);
  c28_c_y = c28_d2;
  sf_mex_destroy(&c28_c_Altitude);
  *c28_Longitude = c28_c_y;
  c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb = sf_mex_dup
    (sf_mex_getcell(c28_u, 3));
  sf_mex_import("is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb",
                sf_mex_dup(
    c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb), &c28_u0, 1,
                3, 0U, 0, 0U, 0);
  c28_d_y = c28_u0;
  sf_mex_destroy(&c28_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb);
  *c28_b_is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb = c28_d_y;
  sf_mex_destroy(&c28_u);
  c28_update_debugger_state_c28_adcs_v15_integral_Power_no_charge();
  sf_mex_destroy(&c28_st);
}

static void finalize_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
}

static void sf_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  int32_T c28_i0;
  int32_T c28_previousEvent;
  int32_T c28_i1;
  real_T c28_r_ECEF[3];
  real_T c28_nargout = 3.0;
  real_T c28_nargin = 1.0;
  real_T c28_h;
  real_T c28_long;
  real_T c28_lat;
  real_T c28_z;
  real_T c28_y;
  real_T c28_x;
  real_T c28_r;
  real_T c28_radius_earth;
  real_T c28_Altitude;
  real_T c28_Longitude;
  real_T c28_Latitutde;
  int32_T c28_i2;
  real_T c28_b_x[3];
  int32_T c28_i3;
  real_T c28_c_x[3];
  real_T c28_A;
  real_T c28_B;
  real_T c28_d_x;
  real_T c28_b_y;
  real_T c28_e_x;
  real_T c28_c_y;
  real_T c28_f_x;
  real_T c28_d_y;
  real_T c28_g_x;
  real_T c28_h_x;
  real_T c28_e_y;
  real_T c28_i_x;
  real_T c28_f_y;
  real_T c28_j_x;
  real_T c28_a;
  real_T c28_b_A;
  real_T c28_k_x;
  real_T c28_l_x;
  real_T c28_m_x;
  real_T c28_b_a;
  real_T c28_c_A;
  real_T c28_n_x;
  real_T c28_o_x;
  real_T c28_p_x;
  real_T *c28_b_Altitude;
  real_T *c28_b_Longitude;
  real_T *c28_b_Latitutde;
  real_T (*c28_b_r_ECEF)[3];
  c28_b_Altitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c28_b_Longitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c28_b_Latitutde = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c28_b_r_ECEF = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,21);
  for (c28_i0 = 0; c28_i0 < 3; c28_i0 = c28_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c28_b_r_ECEF)[c28_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c28_b_Latitutde, 1U);
  _SFD_DATA_RANGE_CHECK(*c28_b_Longitude, 2U);
  _SFD_DATA_RANGE_CHECK(*c28_b_Altitude, 3U);
  c28_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,21);
  for (c28_i1 = 0; c28_i1 < 3; c28_i1 = c28_i1 + 1) {
    c28_r_ECEF[c28_i1] = (*c28_b_r_ECEF)[c28_i1];
  }

  sf_debug_symbol_scope_push(14U, 0U);
  sf_debug_symbol_scope_add("nargout", &c28_nargout, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c28_nargin, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("h", &c28_h, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("long", &c28_long, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("lat", &c28_lat, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("z", &c28_z, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("y", &c28_y, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c28_x, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("r", &c28_r, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("radius_earth", &c28_radius_earth, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("Altitude", &c28_Altitude, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("Longitude", &c28_Longitude, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("Latitutde", &c28_Latitutde, c28_b_sf_marshall);
  sf_debug_symbol_scope_add("r_ECEF", &c28_r_ECEF, c28_sf_marshall);
  CV_EML_FCN(0, 0);

  /* r_ECEF: ECEF position vector (in m) */
  /* r_LLA: LLA postion vector (in rad, m) */
  _SFD_EML_CALL(0,5);
  c28_radius_earth = 6.371E+006;
  _SFD_EML_CALL(0,6);
  for (c28_i2 = 0; c28_i2 < 3; c28_i2 = c28_i2 + 1) {
    c28_b_x[c28_i2] = c28_r_ECEF[c28_i2];
  }

  for (c28_i3 = 0; c28_i3 < 3; c28_i3 = c28_i3 + 1) {
    c28_c_x[c28_i3] = c28_b_x[c28_i3];
  }

  c28_r = c28_genpnorm(c28_c_x, 2.0);
  _SFD_EML_CALL(0,7);
  c28_x = c28_r_ECEF[0];
  _SFD_EML_CALL(0,8);
  c28_y = c28_r_ECEF[1];
  _SFD_EML_CALL(0,9);
  c28_z = c28_r_ECEF[2];
  _SFD_EML_CALL(0,11);
  c28_A = c28_z;
  c28_B = c28_r;
  c28_d_x = c28_A;
  c28_b_y = c28_B;
  if (c28_b_y == 0.0) {
    c28_eml_warning();
  }

  c28_e_x = c28_d_x;
  c28_c_y = c28_b_y;
  c28_f_x = c28_e_x;
  c28_d_y = c28_c_y;
  c28_g_x = c28_f_x / c28_d_y;
  c28_lat = c28_g_x;
  if (c28_lat < -1.0) {
  } else if (1.0 < c28_lat) {
  } else {
    goto label_1;
  }

  c28_b_eml_error();
 label_1:
  ;
  c28_h_x = c28_lat;
  c28_lat = c28_h_x;
  c28_lat = muDoubleScalarAsin(c28_lat);
  _SFD_EML_CALL(0,12);
  c28_e_y = c28_y;
  c28_i_x = c28_x;
  c28_eml_scalar_eg();
  c28_f_y = c28_e_y;
  c28_j_x = c28_i_x;
  c28_long = muDoubleScalarAtan2(c28_f_y, c28_j_x);
  _SFD_EML_CALL(0,13);
  if (CV_EML_IF(0, 0, c28_long < 0.0)) {
    _SFD_EML_CALL(0,14);
    c28_long = c28_long + 6.2831853071795862E+000;
  }

  _SFD_EML_CALL(0,16);
  c28_h = c28_r - c28_radius_earth;
  _SFD_EML_CALL(0,18);
  c28_a = c28_lat;
  c28_b_A = c28_a * 180.0;
  c28_k_x = c28_b_A;
  c28_l_x = c28_k_x;
  c28_m_x = c28_l_x;
  c28_Latitutde = c28_m_x / 3.1415926535897931E+000;

  /* deg */
  _SFD_EML_CALL(0,19);
  c28_b_a = c28_long;
  c28_c_A = c28_b_a * 180.0;
  c28_n_x = c28_c_A;
  c28_o_x = c28_n_x;
  c28_p_x = c28_o_x;
  c28_Longitude = c28_p_x / 3.1415926535897931E+000;

  /* deg */
  _SFD_EML_CALL(0,20);
  c28_Altitude = c28_h;

  /* m */
  /* r_LLA = [lat;long;h]; */
  _SFD_EML_CALL(0,-20);
  sf_debug_symbol_scope_pop();
  *c28_b_Latitutde = c28_Latitutde;
  *c28_b_Longitude = c28_Longitude;
  *c28_b_Altitude = c28_Altitude;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,21);
  _sfEvent_ = c28_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber)
{
}

static real_T c28_genpnorm(real_T c28_x[3], real_T c28_p)
{
  real_T c28_y;
  int32_T c28_i4;
  real_T c28_b_x[3];
  real_T c28_k;
  real_T c28_b_k;
  real_T c28_c_x;
  real_T c28_d_x;
  real_T c28_absx;
  real_T c28_e_x;
  boolean_T c28_b;
  real_T c28_c_k;
  real_T c28_f_x;
  real_T c28_g_x;
  real_T c28_b_y;
  real_T c28_d_k;
  real_T c28_h_x;
  real_T c28_i_x;
  real_T c28_j_x;
  boolean_T c28_b_b;
  int32_T c28_i5;
  real_T c28_k_x[3];
  real_T c28_b_p;
  real_T c28_scale;
  real_T c28_e_k;
  real_T c28_f_k;
  real_T c28_l_x;
  real_T c28_m_x;
  real_T c28_b_absx;
  real_T c28_n_x;
  boolean_T c28_c_b;
  real_T c28_o_x;
  boolean_T c28_d_b;
  real_T c28_d3;
  real_T c28_j;
  real_T c28_b_j;
  real_T c28_p_x;
  boolean_T c28_e_b;
  real_T c28_a;
  real_T c28_f_b;
  real_T c28_c_y;
  real_T c28_q_x;
  boolean_T c28_g_b;
  real_T c28_b_a;
  real_T c28_h_b;
  int32_T c28_i6;
  real_T c28_r_x[3];
  real_T c28_c_p;
  real_T c28_b_scale;
  real_T c28_g_k;
  real_T c28_h_k;
  real_T c28_s_x;
  real_T c28_t_x;
  real_T c28_c_absx;
  real_T c28_u_x;
  boolean_T c28_i_b;
  real_T c28_d4;
  real_T c28_c_j;
  real_T c28_d_j;
  real_T c28_v_x;
  boolean_T c28_j_b;
  real_T c28_c_a;
  real_T c28_k_b;
  real_T c28_d_y;
  real_T c28_w_x;
  boolean_T c28_l_b;
  real_T c28_x_x;
  boolean_T c28_m_b;
  real_T c28_d_a;
  real_T c28_e_a;
  real_T c28_n_b;
  real_T c28_o_b;
  if (c28_p == 2.0) {
    for (c28_i4 = 0; c28_i4 < 3; c28_i4 = c28_i4 + 1) {
      c28_b_x[c28_i4] = c28_x[c28_i4];
    }

    return c28_eml_xnrm2(c28_b_x);
  } else if (c28_p == rtInf) {
    c28_y = 0.0;
    c28_k = 1.0;
   label_1:
    ;
    if (c28_k <= 3.0) {
      c28_b_k = c28_k;
      c28_c_x = c28_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c28_b_k), 1, 3, 1, 0) - 1];
      c28_d_x = c28_c_x;
      c28_absx = muDoubleScalarAbs(c28_d_x);
      c28_e_x = c28_absx;
      c28_b = rtIsNaN(c28_e_x);
      if (c28_b) {
        return rtNaN;
      } else {
        if (c28_absx > c28_y) {
          c28_y = c28_absx;
        }

        c28_k = c28_k + 1.0;
        goto label_1;
      }
    }
  } else if (c28_p == 1.0) {
    c28_y = 0.0;
    for (c28_c_k = 1.0; c28_c_k <= 3.0; c28_c_k = c28_c_k + 1.0) {
      c28_b_k = c28_c_k;
      c28_f_x = c28_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c28_b_k), 1, 3, 1, 0) - 1];
      c28_g_x = c28_f_x;
      c28_b_y = muDoubleScalarAbs(c28_g_x);
      c28_y = c28_y + c28_b_y;
    }
  } else if (c28_p == rtMinusInf) {
    c28_y = rtInf;
    c28_d_k = 1.0;
   label_2:
    ;
    if (c28_d_k <= 3.0) {
      c28_b_k = c28_d_k;
      c28_h_x = c28_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c28_b_k), 1, 3, 1, 0) - 1];
      c28_i_x = c28_h_x;
      c28_absx = muDoubleScalarAbs(c28_i_x);
      c28_j_x = c28_absx;
      c28_b_b = rtIsNaN(c28_j_x);
      if (c28_b_b) {
        return rtNaN;
      } else {
        if (c28_absx < c28_y) {
          c28_y = c28_absx;
        }

        c28_d_k = c28_d_k + 1.0;
        goto label_2;
      }
    }
  } else if (c28_p > 0.0) {
    for (c28_i5 = 0; c28_i5 < 3; c28_i5 = c28_i5 + 1) {
      c28_k_x[c28_i5] = c28_x[c28_i5];
    }

    c28_b_p = c28_p;
    c28_y = 0.0;
    c28_scale = 0.0;
    c28_e_k = 1.0;
   label_3:
    ;
    if (c28_e_k <= 3.0) {
      c28_f_k = c28_e_k;
      c28_l_x = c28_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c28_f_k), 1, 3, 1, 0) - 1];
      c28_m_x = c28_l_x;
      c28_b_absx = muDoubleScalarAbs(c28_m_x);
      c28_n_x = c28_b_absx;
      c28_c_b = rtIsNaN(c28_n_x);
      if (c28_c_b) {
        return rtNaN;
      } else {
        c28_o_x = c28_b_absx;
        c28_d_b = rtIsInf(c28_o_x);
        if (c28_d_b) {
          c28_y = rtInf;
          c28_d3 = c28_f_k + 1.0;
          c28_j = c28_d3;
        } else {
          if (c28_b_absx > 0.0) {
            if (c28_scale < c28_b_absx) {
              c28_a = c28_y;
              c28_f_b = c28_power(c28_scale / c28_b_absx, c28_b_p);
              c28_c_y = c28_a * c28_f_b;
              c28_y = 1.0 + c28_c_y;
              c28_scale = c28_b_absx;
            } else {
              c28_y = c28_y + c28_power(c28_b_absx / c28_scale, c28_b_p);
            }
          }

          c28_e_k = c28_e_k + 1.0;
          goto label_3;
        }
      }
    } else {
      if (c28_y > 0.0) {
        c28_q_x = c28_y;
        c28_g_b = rtIsInf(c28_q_x);
        if (!c28_g_b) {
          c28_b_a = c28_scale;
          c28_h_b = c28_power(c28_y, 1.0 / c28_b_p);
          return c28_b_a * c28_h_b;
        }
      }

      return c28_y;
    }

   label_4:
    ;
    if (c28_j <= 3.0) {
      c28_b_j = c28_j;
      c28_p_x = c28_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c28_b_j), 1, 3, 1, 0) - 1];
      c28_e_b = rtIsNaN(c28_p_x);
      if (c28_e_b) {
        return rtNaN;
      } else {
        c28_j = c28_j + 1.0;
        goto label_4;
      }
    }
  } else if (c28_p < 0.0) {
    for (c28_i6 = 0; c28_i6 < 3; c28_i6 = c28_i6 + 1) {
      c28_r_x[c28_i6] = c28_x[c28_i6];
    }

    c28_c_p = c28_p;
    c28_y = 0.0;
    c28_b_scale = rtInf;
    c28_g_k = 1.0;
   label_5:
    ;
    if (c28_g_k <= 3.0) {
      c28_h_k = c28_g_k;
      c28_s_x = c28_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c28_h_k), 1, 3, 1, 0) - 1];
      c28_t_x = c28_s_x;
      c28_c_absx = muDoubleScalarAbs(c28_t_x);
      c28_u_x = c28_c_absx;
      c28_i_b = rtIsNaN(c28_u_x);
      if (c28_i_b) {
        return rtNaN;
      } else if (c28_c_absx == 0.0) {
        c28_y = 0.0;
        c28_d4 = c28_h_k + 1.0;
        c28_c_j = c28_d4;
      } else {
        if (c28_c_absx < c28_b_scale) {
          c28_c_a = c28_y;
          c28_k_b = c28_power(c28_b_scale / c28_c_absx, c28_c_p);
          c28_d_y = c28_c_a * c28_k_b;
          c28_y = 1.0 + c28_d_y;
          c28_b_scale = c28_c_absx;
        } else {
          c28_w_x = c28_c_absx;
          c28_l_b = rtIsInf(c28_w_x);
          if (!c28_l_b) {
            c28_y = c28_y + c28_power(c28_c_absx / c28_b_scale, c28_c_p);
          }
        }

        c28_g_k = c28_g_k + 1.0;
        goto label_5;
      }
    } else {
      if (c28_y > 0.0) {
        c28_x_x = c28_y;
        c28_m_b = rtIsInf(c28_x_x);
        if (!c28_m_b) {
          c28_d_a = c28_b_scale;
          c28_e_a = c28_y;
          c28_n_b = 1.0 / c28_c_p;
          c28_o_b = c28_power(c28_e_a, c28_n_b);
          return c28_d_a * c28_o_b;
        }
      }

      return c28_y;
    }

   label_6:
    ;
    if (c28_c_j <= 3.0) {
      c28_d_j = c28_c_j;
      c28_v_x = c28_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c28_d_j), 1, 3, 1, 0) - 1];
      c28_j_b = rtIsNaN(c28_v_x);
      if (c28_j_b) {
        return rtNaN;
      } else {
        c28_c_j = c28_c_j + 1.0;
        goto label_6;
      }
    }
  } else if (c28_p == 0.0) {
    return rtInf;
  } else {
    return rtNaN;
  }

  return c28_y;
}

static real_T c28_eml_xnrm2(real_T c28_x[3])
{
  int32_T c28_i7;
  real_T c28_b_x[3];
  int32_T c28_i8;
  real_T c28_c_x[3];
  for (c28_i7 = 0; c28_i7 < 3; c28_i7 = c28_i7 + 1) {
    c28_b_x[c28_i7] = c28_x[c28_i7];
  }

  for (c28_i8 = 0; c28_i8 < 3; c28_i8 = c28_i8 + 1) {
    c28_c_x[c28_i8] = c28_b_x[c28_i8];
  }

  return c28_ceval_xnrm2(3, c28_c_x, 1.0, 1);
}

static real_T c28_ceval_xnrm2(int32_T c28_n, real_T c28_x[3], real_T c28_ix0,
  int32_T c28_incx)
{
  return dnrm232(&c28_n, &c28_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
    _SFD_INTEGER_CHECK("ix0", c28_ix0), 1, 3, 1, 0) - 1], &
                 c28_incx);
}

static real_T c28_power(real_T c28_a, real_T c28_b)
{
  real_T c28_ak;
  real_T c28_bk;
  real_T c28_x;
  real_T c28_b_x;
  c28_eml_scalar_eg();
  c28_ak = c28_a;
  c28_bk = c28_b;
  if (c28_ak < 0.0) {
    c28_x = c28_bk;
    c28_b_x = c28_x;
    c28_b_x = muDoubleScalarFloor(c28_b_x);
    if (c28_b_x != c28_bk) {
      c28_eml_error();
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c28_ak, c28_bk);
}

static void c28_eml_scalar_eg(void)
{
}

static void c28_eml_error(void)
{
  int32_T c28_i9;
  static char_T c28_cv0[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
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

  char_T c28_u[102];
  const mxArray *c28_y = NULL;
  int32_T c28_i10;
  static char_T c28_cv1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c28_b_u[32];
  const mxArray *c28_b_y = NULL;
  for (c28_i9 = 0; c28_i9 < 102; c28_i9 = c28_i9 + 1) {
    c28_u[c28_i9] = c28_cv0[c28_i9];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c28_i10 = 0; c28_i10 < 32; c28_i10 = c28_i10 + 1) {
    c28_b_u[c28_i10] = c28_cv1[c28_i10];
  }

  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c28_b_y, 14, c28_y);
}

static void c28_eml_warning(void)
{
  int32_T c28_i11;
  static char_T c28_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c28_u[15];
  const mxArray *c28_y = NULL;
  int32_T c28_i12;
  static char_T c28_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c28_b_u[19];
  const mxArray *c28_b_y = NULL;
  for (c28_i11 = 0; c28_i11 < 15; c28_i11 = c28_i11 + 1) {
    c28_u[c28_i11] = c28_cv2[c28_i11];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c28_i12 = 0; c28_i12 < 19; c28_i12 = c28_i12 + 1) {
    c28_b_u[c28_i12] = c28_cv3[c28_i12];
  }

  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c28_b_y, 14, c28_y);
}

static void c28_b_eml_error(void)
{
  int32_T c28_i13;
  static char_T c28_cv4[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 'a',
    's', 'i', 'n', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c28_u[77];
  const mxArray *c28_y = NULL;
  int32_T c28_i14;
  static char_T c28_cv5[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 's', 'i', 'n', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c28_b_u[31];
  const mxArray *c28_b_y = NULL;
  for (c28_i13 = 0; c28_i13 < 77; c28_i13 = c28_i13 + 1) {
    c28_u[c28_i13] = c28_cv4[c28_i13];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c28_i14 = 0; c28_i14 < 31; c28_i14 = c28_i14 + 1) {
    c28_b_u[c28_i14] = c28_cv5[c28_i14];
  }

  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c28_b_y, 14, c28_y);
}

static const mxArray *c28_sf_marshall(void *c28_chartInstance, void *c28_u)
{
  const mxArray *c28_y = NULL;
  int32_T c28_i15;
  real_T c28_b_u[3];
  const mxArray *c28_b_y = NULL;
  c28_y = NULL;
  for (c28_i15 = 0; c28_i15 < 3; c28_i15 = c28_i15 + 1) {
    c28_b_u[c28_i15] = (*((real_T (*)[3])c28_u))[c28_i15];
  }

  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c28_y, c28_b_y);
  return c28_y;
}

static const mxArray *c28_b_sf_marshall(void *c28_chartInstance, void *c28_u)
{
  const mxArray *c28_y = NULL;
  real_T c28_b_u;
  const mxArray *c28_b_y = NULL;
  c28_y = NULL;
  c28_b_u = *((real_T *)c28_u);
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c28_y, c28_b_y);
  return c28_y;
}

const mxArray
  *sf_c28_adcs_v15_integral_Power_no_charge_in_detumb_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c28_nameCaptureInfo = NULL;
  c28_ResolvedFunctionInfo c28_info[64];
  const mxArray *c28_m0 = NULL;
  int32_T c28_i16;
  c28_ResolvedFunctionInfo *c28_r0;
  c28_nameCaptureInfo = NULL;
  c28_info_helper(c28_info);
  sf_mex_assign(&c28_m0, sf_mex_createstruct("nameCaptureInfo", 1, 64));
  for (c28_i16 = 0; c28_i16 < 64; c28_i16 = c28_i16 + 1) {
    c28_r0 = &c28_info[c28_i16];
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c28_r0->context)), "context"
                    , "nameCaptureInfo", c28_i16);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c28_r0->name)), "name",
                    "nameCaptureInfo", c28_i16);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      c28_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c28_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c28_i16);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c28_r0->resolved)),
                    "resolved", "nameCaptureInfo", c28_i16);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c28_i16);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c28_i16);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c28_i16);
  }

  sf_mex_assign(&c28_nameCaptureInfo, c28_m0);
  return c28_nameCaptureInfo;
}

static void c28_info_helper(c28_ResolvedFunctionInfo c28_info[64])
{
  c28_info[0].context = "";
  c28_info[0].name = "norm";
  c28_info[0].dominantType = "double";
  c28_info[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[0].fileLength = 5186U;
  c28_info[0].fileTime1 = 1240249448U;
  c28_info[0].fileTime2 = 0U;
  c28_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[1].name = "nargin";
  c28_info[1].dominantType = "";
  c28_info[1].resolved = "[B]nargin";
  c28_info[1].fileLength = 0U;
  c28_info[1].fileTime1 = 0U;
  c28_info[1].fileTime2 = 0U;
  c28_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[2].name = "gt";
  c28_info[2].dominantType = "double";
  c28_info[2].resolved = "[B]gt";
  c28_info[2].fileLength = 0U;
  c28_info[2].fileTime1 = 0U;
  c28_info[2].fileTime2 = 0U;
  c28_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[3].name = "isa";
  c28_info[3].dominantType = "double";
  c28_info[3].resolved = "[B]isa";
  c28_info[3].fileLength = 0U;
  c28_info[3].fileTime1 = 0U;
  c28_info[3].fileTime2 = 0U;
  c28_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[4].name = "ndims";
  c28_info[4].dominantType = "double";
  c28_info[4].resolved = "[B]ndims";
  c28_info[4].fileLength = 0U;
  c28_info[4].fileTime1 = 0U;
  c28_info[4].fileTime2 = 0U;
  c28_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[5].name = "le";
  c28_info[5].dominantType = "double";
  c28_info[5].resolved = "[B]le";
  c28_info[5].fileLength = 0U;
  c28_info[5].fileTime1 = 0U;
  c28_info[5].fileTime2 = 0U;
  c28_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[6].name = "eq";
  c28_info[6].dominantType = "double";
  c28_info[6].resolved = "[B]eq";
  c28_info[6].fileLength = 0U;
  c28_info[6].fileTime1 = 0U;
  c28_info[6].fileTime2 = 0U;
  c28_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[7].name = "lt";
  c28_info[7].dominantType = "double";
  c28_info[7].resolved = "[B]lt";
  c28_info[7].fileLength = 0U;
  c28_info[7].fileTime1 = 0U;
  c28_info[7].fileTime2 = 0U;
  c28_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[8].name = "size";
  c28_info[8].dominantType = "double";
  c28_info[8].resolved = "[B]size";
  c28_info[8].fileLength = 0U;
  c28_info[8].fileTime1 = 0U;
  c28_info[8].fileTime2 = 0U;
  c28_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[9].name = "isempty";
  c28_info[9].dominantType = "double";
  c28_info[9].resolved = "[B]isempty";
  c28_info[9].fileLength = 0U;
  c28_info[9].fileTime1 = 0U;
  c28_info[9].fileTime2 = 0U;
  c28_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[10].name = "isscalar";
  c28_info[10].dominantType = "double";
  c28_info[10].resolved = "[B]isscalar";
  c28_info[10].fileLength = 0U;
  c28_info[10].fileTime1 = 0U;
  c28_info[10].fileTime2 = 0U;
  c28_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c28_info[11].name = "isvector";
  c28_info[11].dominantType = "double";
  c28_info[11].resolved = "[B]isvector";
  c28_info[11].fileLength = 0U;
  c28_info[11].fileTime1 = 0U;
  c28_info[11].fileTime2 = 0U;
  c28_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[12].name = "ischar";
  c28_info[12].dominantType = "double";
  c28_info[12].resolved = "[B]ischar";
  c28_info[12].fileLength = 0U;
  c28_info[12].fileTime1 = 0U;
  c28_info[12].fileTime2 = 0U;
  c28_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[13].name = "eml_xnrm2";
  c28_info[13].dominantType = "double";
  c28_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c28_info[13].fileLength = 718U;
  c28_info[13].fileTime1 = 1209318258U;
  c28_info[13].fileTime2 = 0U;
  c28_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c28_info[14].name = "strcmp";
  c28_info[14].dominantType = "char";
  c28_info[14].resolved = "[B]strcmp";
  c28_info[14].fileLength = 0U;
  c28_info[14].fileTime1 = 0U;
  c28_info[14].fileTime2 = 0U;
  c28_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c28_info[15].name = "cast";
  c28_info[15].dominantType = "double";
  c28_info[15].resolved = "[B]cast";
  c28_info[15].fileLength = 0U;
  c28_info[15].fileTime1 = 0U;
  c28_info[15].fileTime2 = 0U;
  c28_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c28_info[16].name = "eml_refblas_xnrm2";
  c28_info[16].dominantType = "int32";
  c28_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[16].fileLength = 1433U;
  c28_info[16].fileTime1 = 1240249444U;
  c28_info[16].fileTime2 = 0U;
  c28_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[17].name = "class";
  c28_info[17].dominantType = "double";
  c28_info[17].resolved = "[B]class";
  c28_info[17].fileLength = 0U;
  c28_info[17].fileTime1 = 0U;
  c28_info[17].fileTime2 = 0U;
  c28_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[18].name = "zeros";
  c28_info[18].dominantType = "char";
  c28_info[18].resolved = "[B]zeros";
  c28_info[18].fileLength = 0U;
  c28_info[18].fileTime1 = 0U;
  c28_info[18].fileTime2 = 0U;
  c28_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[19].name = "ones";
  c28_info[19].dominantType = "char";
  c28_info[19].resolved = "[B]ones";
  c28_info[19].fileLength = 0U;
  c28_info[19].fileTime1 = 0U;
  c28_info[19].fileTime2 = 0U;
  c28_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[20].name = "true";
  c28_info[20].dominantType = "";
  c28_info[20].resolved = "[B]true";
  c28_info[20].fileLength = 0U;
  c28_info[20].fileTime1 = 0U;
  c28_info[20].fileTime2 = 0U;
  c28_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[21].name = "eml_index_class";
  c28_info[21].dominantType = "";
  c28_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c28_info[21].fileLength = 909U;
  c28_info[21].fileTime1 = 1192454182U;
  c28_info[21].fileTime2 = 0U;
  c28_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[22].name = "eml_index_minus";
  c28_info[22].dominantType = "int32";
  c28_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c28_info[22].fileLength = 277U;
  c28_info[22].fileTime1 = 1192454184U;
  c28_info[22].fileTime2 = 0U;
  c28_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[23].name = "eml_index_times";
  c28_info[23].dominantType = "int32";
  c28_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c28_info[23].fileLength = 280U;
  c28_info[23].fileTime1 = 1192454188U;
  c28_info[23].fileTime2 = 0U;
  c28_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[24].name = "eml_index_plus";
  c28_info[24].dominantType = "int32";
  c28_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c28_info[24].fileLength = 272U;
  c28_info[24].fileTime1 = 1192454186U;
  c28_info[24].fileTime2 = 0U;
  c28_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[25].name = "real";
  c28_info[25].dominantType = "double";
  c28_info[25].resolved = "[B]real";
  c28_info[25].fileLength = 0U;
  c28_info[25].fileTime1 = 0U;
  c28_info[25].fileTime2 = 0U;
  c28_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[26].name = "ne";
  c28_info[26].dominantType = "double";
  c28_info[26].resolved = "[B]ne";
  c28_info[26].fileLength = 0U;
  c28_info[26].fileTime1 = 0U;
  c28_info[26].fileTime2 = 0U;
  c28_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[27].name = "abs";
  c28_info[27].dominantType = "double";
  c28_info[27].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c28_info[27].fileLength = 566U;
  c28_info[27].fileTime1 = 1221254534U;
  c28_info[27].fileTime2 = 0U;
  c28_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c28_info[28].name = "islogical";
  c28_info[28].dominantType = "double";
  c28_info[28].resolved = "[B]islogical";
  c28_info[28].fileLength = 0U;
  c28_info[28].fileTime1 = 0U;
  c28_info[28].fileTime2 = 0U;
  c28_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c28_info[29].name = "eml_scalar_abs";
  c28_info[29].dominantType = "double";
  c28_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c28_info[29].fileLength = 461U;
  c28_info[29].fileTime1 = 1203431760U;
  c28_info[29].fileTime2 = 0U;
  c28_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c28_info[30].name = "isinteger";
  c28_info[30].dominantType = "double";
  c28_info[30].resolved = "[B]isinteger";
  c28_info[30].fileLength = 0U;
  c28_info[30].fileTime1 = 0U;
  c28_info[30].fileTime2 = 0U;
  c28_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c28_info[31].name = "isreal";
  c28_info[31].dominantType = "double";
  c28_info[31].resolved = "[B]isreal";
  c28_info[31].fileLength = 0U;
  c28_info[31].fileTime1 = 0U;
  c28_info[31].fileTime2 = 0U;
  c28_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[32].name = "false";
  c28_info[32].dominantType = "";
  c28_info[32].resolved = "[B]false";
  c28_info[32].fileLength = 0U;
  c28_info[32].fileTime1 = 0U;
  c28_info[32].fileTime2 = 0U;
  c28_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[33].name = "times";
  c28_info[33].dominantType = "double";
  c28_info[33].resolved = "[B]times";
  c28_info[33].fileLength = 0U;
  c28_info[33].fileTime1 = 0U;
  c28_info[33].fileTime2 = 0U;
  c28_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[34].name = "plus";
  c28_info[34].dominantType = "double";
  c28_info[34].resolved = "[B]plus";
  c28_info[34].fileLength = 0U;
  c28_info[34].fileTime1 = 0U;
  c28_info[34].fileTime2 = 0U;
  c28_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c28_info[35].name = "imag";
  c28_info[35].dominantType = "double";
  c28_info[35].resolved = "[B]imag";
  c28_info[35].fileLength = 0U;
  c28_info[35].fileTime1 = 0U;
  c28_info[35].fileTime2 = 0U;
  c28_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[36].name = "inf";
  c28_info[36].dominantType = "";
  c28_info[36].resolved = "[B]inf";
  c28_info[36].fileLength = 0U;
  c28_info[36].fileTime1 = 0U;
  c28_info[36].fileTime2 = 0U;
  c28_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[37].name = "isnan";
  c28_info[37].dominantType = "double";
  c28_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c28_info[37].fileLength = 506U;
  c28_info[37].fileTime1 = 1228077610U;
  c28_info[37].fileTime2 = 0U;
  c28_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[38].name = "eml_guarded_nan";
  c28_info[38].dominantType = "char";
  c28_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c28_info[38].fileLength = 485U;
  c28_info[38].fileTime1 = 1192454180U;
  c28_info[38].fileTime2 = 0U;
  c28_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c28_info[39].name = "eml_is_float_class";
  c28_info[39].dominantType = "char";
  c28_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c28_info[39].fileLength = 226U;
  c28_info[39].fileTime1 = 1197834242U;
  c28_info[39].fileTime2 = 0U;
  c28_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c28_info[40].name = "nan";
  c28_info[40].dominantType = "char";
  c28_info[40].resolved = "[B]nan";
  c28_info[40].fileLength = 0U;
  c28_info[40].fileTime1 = 0U;
  c28_info[40].fileTime2 = 0U;
  c28_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[41].name = "uminus";
  c28_info[41].dominantType = "double";
  c28_info[41].resolved = "[B]uminus";
  c28_info[41].fileLength = 0U;
  c28_info[41].fileTime1 = 0U;
  c28_info[41].fileTime2 = 0U;
  c28_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c28_info[42].name = "eml_guarded_inf";
  c28_info[42].dominantType = "char";
  c28_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  c28_info[42].fileLength = 495U;
  c28_info[42].fileTime1 = 1192454178U;
  c28_info[42].fileTime2 = 0U;
  c28_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecpospnorm";
  c28_info[43].name = "isinf";
  c28_info[43].dominantType = "double";
  c28_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c28_info[43].fileLength = 506U;
  c28_info[43].fileTime1 = 1228077610U;
  c28_info[43].fileTime2 = 0U;
  c28_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecpospnorm";
  c28_info[44].name = "power";
  c28_info[44].dominantType = "double";
  c28_info[44].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c28_info[44].fileLength = 5380U;
  c28_info[44].fileTime1 = 1228077698U;
  c28_info[44].fileTime2 = 0U;
  c28_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c28_info[45].name = "eml_scalar_eg";
  c28_info[45].dominantType = "double";
  c28_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c28_info[45].fileLength = 3068U;
  c28_info[45].fileTime1 = 1240249410U;
  c28_info[45].fileTime2 = 0U;
  c28_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c28_info[46].name = "isstruct";
  c28_info[46].dominantType = "double";
  c28_info[46].resolved = "[B]isstruct";
  c28_info[46].fileLength = 0U;
  c28_info[46].fileTime1 = 0U;
  c28_info[46].fileTime2 = 0U;
  c28_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c28_info[47].name = "eml_scalexp_alloc";
  c28_info[47].dominantType = "double";
  c28_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c28_info[47].fileLength = 808U;
  c28_info[47].fileTime1 = 1230478500U;
  c28_info[47].fileTime2 = 0U;
  c28_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c28_info[48].name = "minus";
  c28_info[48].dominantType = "double";
  c28_info[48].resolved = "[B]minus";
  c28_info[48].fileLength = 0U;
  c28_info[48].fileTime1 = 0U;
  c28_info[48].fileTime2 = 0U;
  c28_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c28_info[49].name = "not";
  c28_info[49].dominantType = "logical";
  c28_info[49].resolved = "[B]not";
  c28_info[49].fileLength = 0U;
  c28_info[49].fileTime1 = 0U;
  c28_info[49].fileTime2 = 0U;
  c28_info[50].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c28_info[50].name = "eml_scalar_floor";
  c28_info[50].dominantType = "double";
  c28_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c28_info[50].fileLength = 260U;
  c28_info[50].fileTime1 = 1209318190U;
  c28_info[50].fileTime2 = 0U;
  c28_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c28_info[51].name = "eml_error";
  c28_info[51].dominantType = "char";
  c28_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c28_info[51].fileLength = 315U;
  c28_info[51].fileTime1 = 1213914146U;
  c28_info[51].fileTime2 = 0U;
  c28_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecpospnorm";
  c28_info[52].name = "mtimes";
  c28_info[52].dominantType = "double";
  c28_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c28_info[52].fileLength = 3302U;
  c28_info[52].fileTime1 = 1242738294U;
  c28_info[52].fileTime2 = 0U;
  c28_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/vecnegpnorm";
  c28_info[53].name = "mpower";
  c28_info[53].dominantType = "double";
  c28_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c28_info[53].fileLength = 3710U;
  c28_info[53].fileTime1 = 1238421690U;
  c28_info[53].fileTime2 = 0U;
  c28_info[54].context = "";
  c28_info[54].name = "mrdivide";
  c28_info[54].dominantType = "double";
  c28_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c28_info[54].fileLength = 800U;
  c28_info[54].fileTime1 = 1238421692U;
  c28_info[54].fileTime2 = 0U;
  c28_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c28_info[55].name = "ge";
  c28_info[55].dominantType = "double";
  c28_info[55].resolved = "[B]ge";
  c28_info[55].fileLength = 0U;
  c28_info[55].fileTime1 = 0U;
  c28_info[55].fileTime2 = 0U;
  c28_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c28_info[56].name = "rdivide";
  c28_info[56].dominantType = "double";
  c28_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c28_info[56].fileLength = 620U;
  c28_info[56].fileTime1 = 1213914166U;
  c28_info[56].fileTime2 = 0U;
  c28_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c28_info[57].name = "eml_warning";
  c28_info[57].dominantType = "char";
  c28_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c28_info[57].fileLength = 262U;
  c28_info[57].fileTime1 = 1236241078U;
  c28_info[57].fileTime2 = 0U;
  c28_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c28_info[58].name = "eml_div";
  c28_info[58].dominantType = "double";
  c28_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c28_info[58].fileLength = 4269U;
  c28_info[58].fileTime1 = 1228077626U;
  c28_info[58].fileTime2 = 0U;
  c28_info[59].context = "";
  c28_info[59].name = "asin";
  c28_info[59].dominantType = "double";
  c28_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c28_info[59].fileLength = 585U;
  c28_info[59].fileTime1 = 1203431744U;
  c28_info[59].fileTime2 = 0U;
  c28_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c28_info[60].name = "eml_scalar_asin";
  c28_info[60].dominantType = "double";
  c28_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  c28_info[60].fileLength = 588U;
  c28_info[60].fileTime1 = 1203431774U;
  c28_info[60].fileTime2 = 0U;
  c28_info[61].context = "";
  c28_info[61].name = "atan2";
  c28_info[61].dominantType = "double";
  c28_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c28_info[61].fileLength = 605U;
  c28_info[61].fileTime1 = 1236241054U;
  c28_info[61].fileTime2 = 0U;
  c28_info[62].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c28_info[62].name = "eml_scalar_atan2";
  c28_info[62].dominantType = "double";
  c28_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c28_info[62].fileLength = 964U;
  c28_info[62].fileTime1 = 1209318186U;
  c28_info[62].fileTime2 = 0U;
  c28_info[63].context = "";
  c28_info[63].name = "pi";
  c28_info[63].dominantType = "";
  c28_info[63].resolved = "[B]pi";
  c28_info[63].fileLength = 0U;
  c28_info[63].fileTime1 = 0U;
  c28_info[63].fileTime2 = 0U;
}

static const mxArray *c28_c_sf_marshall(void *c28_chartInstance, void *c28_u)
{
  const mxArray *c28_y = NULL;
  boolean_T c28_b_u;
  const mxArray *c28_b_y = NULL;
  c28_y = NULL;
  c28_b_u = *((boolean_T *)c28_u);
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c28_y, c28_b_y);
  return c28_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c28_adcs_v15_integral_Power_no_charge_in_detumb_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3345188015U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(208080349U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1231691753U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(541476543U);
}

mxArray
  *sf_c28_adcs_v15_integral_Power_no_charge_in_detumb_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1202929117U);
    pr[1] = (double)(1429957178U);
    pr[2] = (double)(1831006707U);
    pr[3] = (double)(3503619714U);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c28_adcs_v15_integral_Power_no_charge_in_detumb(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[7],T\"Altitude\",},{M[1],M[5],T\"Latitutde\",},{M[1],M[6],T\"Longitude\",},{M[8],M[0],T\"is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_adcs_v15_integral_Power_no_charge_in_detumb_get_check_sum(&mxChecksum);
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
           28,
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
                                1.0,0,"r_ECEF",0,(MexFcnForType)c28_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Latitutde",0,(MexFcnForType)c28_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Longitude",0,(MexFcnForType)c28_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Altitude",0,(MexFcnForType)c28_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,424);
        _SFD_CV_INIT_EML_IF(0,0,257,270,-1,298);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c28_r_ECEF)[3];
          real_T *c28_Latitutde;
          real_T *c28_Longitude;
          real_T *c28_Altitude;
          c28_Altitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c28_Longitude = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c28_Latitutde = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c28_r_ECEF = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c28_r_ECEF);
          _SFD_SET_DATA_VALUE_PTR(1U, c28_Latitutde);
          _SFD_SET_DATA_VALUE_PTR(2U, c28_Longitude);
          _SFD_SET_DATA_VALUE_PTR(3U, c28_Altitude);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_no_charge_in_detumbMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c28_adcs_v15_integral_Power_no_charge_in_detumb();
  initialize_c28_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_enable_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  enable_c28_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_disable_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  disable_c28_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void sf_opaque_gateway_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  sf_c28_adcs_v15_integral_Power_no_charge_in_detumb();
}

static void
  sf_opaque_ext_mode_exec_c28_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar)
{
  ext_mode_exec_c28_adcs_v15_integral_Power_no_charge_in_detumb();
}

static mxArray*
  sf_opaque_get_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb();
  return st;
}

static void
  sf_opaque_set_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb(sf_mex_dup(st));
}

static void sf_opaque_terminate_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c28_adcs_v15_integral_Power_no_charge_in_detumb();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c28_adcs_v15_integral_Power_no_charge_in_detumb();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c28_adcs_v15_integral_Power_no_charge_in_detumb
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",28);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "adcs_v15_integral_Power_no_charge_in_detumb",
                "adcs_v15_integral_Power_no_charge_in_detumb",28,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",28,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "adcs_v15_integral_Power_no_charge_in_detumb",
        "adcs_v15_integral_Power_no_charge_in_detumb",28,1);
      sf_mark_chart_reusable_outputs(S,
        "adcs_v15_integral_Power_no_charge_in_detumb",
        "adcs_v15_integral_Power_no_charge_in_detumb",28,3);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_no_charge_in_detumb",
                          "adcs_v15_integral_Power_no_charge_in_detumb",28);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1295344655U));
  ssSetChecksum1(S,(2313814526U));
  ssSetChecksum2(S,(855011050U));
  ssSetChecksum3(S,(1763463196U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c28_adcs_v15_integral_Power_no_charge_in_detumb(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_no_charge_in_detumb",
      "adcs_v15_integral_Power_no_charge_in_detumb",28);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c28_adcs_v15_integral_Power_no_charge_in_detumb(SimStruct
  *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c28_adcs_v15_integral_Power_no_charge_in_detumb;
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

void c28_adcs_v15_integral_Power_no_charge_in_detumb_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_adcs_v15_integral_Power_no_charge_in_detumb(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_adcs_v15_integral_Power_no_charge_in_detumb_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
