/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c26_adcs_v15_integral_Power.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c26_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc26_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c26_adcs_v15_integral_Power(void);
static void initialize_params_c26_adcs_v15_integral_Power(void);
static void enable_c26_adcs_v15_integral_Power(void);
static void disable_c26_adcs_v15_integral_Power(void);
static void c26_update_debugger_state_c26_adcs_v15_integral_Power(void);
static void ext_mode_exec_c26_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c26_adcs_v15_integral_Power(void);
static void set_sim_state_c26_adcs_v15_integral_Power(const mxArray *c26_st);
static void finalize_c26_adcs_v15_integral_Power(void);
static void sf_c26_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber);
static real_T c26_isro_battery(real_T c26_x, real_T c26_current, real_T
  c26_internal_resistance);
static real_T c26_power(real_T c26_a, real_T c26_b);
static void c26_eml_error(void);
static void c26_eml_warning(void);
static const mxArray *c26_sf_marshall(void *c26_chartInstance, void *c26_u);
static void c26_info_helper(c26_ResolvedFunctionInfo c26_info[34]);
static const mxArray *c26_b_sf_marshall(void *c26_chartInstance, void *c26_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c26_adcs_v15_integral_Power(void)
{
  uint8_T *c26_is_active_c26_adcs_v15_integral_Power;
  c26_is_active_c26_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c26_is_active_c26_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c26_adcs_v15_integral_Power(void)
{
  real_T c26_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 's_SIM_STEP_SIZE' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c26_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c26_s_SIM_STEP_SIZE = c26_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c26_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c26_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c26_update_debugger_state_c26_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c26_adcs_v15_integral_Power(void)
{
  c26_update_debugger_state_c26_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c26_adcs_v15_integral_Power(void)
{
  const mxArray *c26_st = NULL;
  const mxArray *c26_y = NULL;
  real_T c26_u;
  const mxArray *c26_b_y = NULL;
  real_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  real_T c26_c_u;
  const mxArray *c26_d_y = NULL;
  real_T c26_d_u;
  const mxArray *c26_e_y = NULL;
  real_T c26_e_u;
  const mxArray *c26_f_y = NULL;
  real_T c26_f_u;
  const mxArray *c26_g_y = NULL;
  uint8_T c26_g_u;
  const mxArray *c26_h_y = NULL;
  real_T *c26_Batt_cap;
  real_T *c26_Flag_charge;
  real_T *c26_Flag_discharge;
  real_T *c26_VBat;
  real_T *c26_current;
  real_T *c26_frac_Batt_cap;
  uint8_T *c26_is_active_c26_adcs_v15_integral_Power;
  c26_frac_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c26_current = (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c26_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c26_Flag_charge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c26_VBat = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c26_Flag_discharge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c26_is_active_c26_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellarray(7));
  c26_u = *c26_Batt_cap;
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_b_u = *c26_Flag_charge;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 1, c26_c_y);
  c26_c_u = *c26_Flag_discharge;
  c26_d_y = NULL;
  sf_mex_assign(&c26_d_y, sf_mex_create("y", &c26_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 2, c26_d_y);
  c26_d_u = *c26_VBat;
  c26_e_y = NULL;
  sf_mex_assign(&c26_e_y, sf_mex_create("y", &c26_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 3, c26_e_y);
  c26_e_u = *c26_current;
  c26_f_y = NULL;
  sf_mex_assign(&c26_f_y, sf_mex_create("y", &c26_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 4, c26_f_y);
  c26_f_u = *c26_frac_Batt_cap;
  c26_g_y = NULL;
  sf_mex_assign(&c26_g_y, sf_mex_create("y", &c26_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 5, c26_g_y);
  c26_g_u = *c26_is_active_c26_adcs_v15_integral_Power;
  c26_h_y = NULL;
  sf_mex_assign(&c26_h_y, sf_mex_create("y", &c26_g_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c26_y, 6, c26_h_y);
  sf_mex_assign(&c26_st, c26_y);
  return c26_st;
}

static void set_sim_state_c26_adcs_v15_integral_Power(const mxArray *c26_st)
{
  const mxArray *c26_u;
  const mxArray *c26_Batt_cap;
  real_T c26_d1;
  real_T c26_y;
  const mxArray *c26_b_Batt_cap;
  real_T c26_d2;
  real_T c26_b_y;
  const mxArray *c26_c_Batt_cap;
  real_T c26_d3;
  real_T c26_c_y;
  const mxArray *c26_d_Batt_cap;
  real_T c26_d4;
  real_T c26_d_y;
  const mxArray *c26_e_Batt_cap;
  real_T c26_d5;
  real_T c26_e_y;
  const mxArray *c26_f_Batt_cap;
  real_T c26_d6;
  real_T c26_f_y;
  const mxArray *c26_is_active_c26_adcs_v15_integral_Power;
  uint8_T c26_u0;
  uint8_T c26_g_y;
  boolean_T *c26_doneDoubleBufferReInit;
  real_T *c26_g_Batt_cap;
  real_T *c26_Flag_charge;
  real_T *c26_Flag_discharge;
  real_T *c26_VBat;
  real_T *c26_current;
  real_T *c26_frac_Batt_cap;
  uint8_T *c26_b_is_active_c26_adcs_v15_integral_Power;
  c26_frac_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c26_current = (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c26_g_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c26_Flag_charge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c26_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c26_VBat = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c26_Flag_discharge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c26_b_is_active_c26_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c26_doneDoubleBufferReInit = true;
  c26_u = sf_mex_dup(c26_st);
  c26_Batt_cap = sf_mex_dup(sf_mex_getcell(c26_u, 0));
  sf_mex_import("Batt_cap", sf_mex_dup(c26_Batt_cap), &c26_d1, 1, 0, 0U, 0, 0U,
                0);
  c26_y = c26_d1;
  sf_mex_destroy(&c26_Batt_cap);
  *c26_g_Batt_cap = c26_y;
  c26_b_Batt_cap = sf_mex_dup(sf_mex_getcell(c26_u, 1));
  sf_mex_import("Flag_charge", sf_mex_dup(c26_b_Batt_cap), &c26_d2, 1, 0, 0U, 0,
                0U, 0);
  c26_b_y = c26_d2;
  sf_mex_destroy(&c26_b_Batt_cap);
  *c26_Flag_charge = c26_b_y;
  c26_c_Batt_cap = sf_mex_dup(sf_mex_getcell(c26_u, 2));
  sf_mex_import("Flag_discharge", sf_mex_dup(c26_c_Batt_cap), &c26_d3, 1, 0, 0U,
                0, 0U, 0);
  c26_c_y = c26_d3;
  sf_mex_destroy(&c26_c_Batt_cap);
  *c26_Flag_discharge = c26_c_y;
  c26_d_Batt_cap = sf_mex_dup(sf_mex_getcell(c26_u, 3));
  sf_mex_import("VBat", sf_mex_dup(c26_d_Batt_cap), &c26_d4, 1, 0, 0U, 0, 0U, 0);
  c26_d_y = c26_d4;
  sf_mex_destroy(&c26_d_Batt_cap);
  *c26_VBat = c26_d_y;
  c26_e_Batt_cap = sf_mex_dup(sf_mex_getcell(c26_u, 4));
  sf_mex_import("current", sf_mex_dup(c26_e_Batt_cap), &c26_d5, 1, 0, 0U, 0, 0U,
                0);
  c26_e_y = c26_d5;
  sf_mex_destroy(&c26_e_Batt_cap);
  *c26_current = c26_e_y;
  c26_f_Batt_cap = sf_mex_dup(sf_mex_getcell(c26_u, 5));
  sf_mex_import("frac_Batt_cap", sf_mex_dup(c26_f_Batt_cap), &c26_d6, 1, 0, 0U,
                0, 0U, 0);
  c26_f_y = c26_d6;
  sf_mex_destroy(&c26_f_Batt_cap);
  *c26_frac_Batt_cap = c26_f_y;
  c26_is_active_c26_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c26_u, 6));
  sf_mex_import("is_active_c26_adcs_v15_integral_Power", sf_mex_dup
                (c26_is_active_c26_adcs_v15_integral_Power), &c26_u0, 1, 3, 0U,
                0,
                0U, 0);
  c26_g_y = c26_u0;
  sf_mex_destroy(&c26_is_active_c26_adcs_v15_integral_Power);
  *c26_b_is_active_c26_adcs_v15_integral_Power = c26_g_y;
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_adcs_v15_integral_Power();
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_adcs_v15_integral_Power(void)
{
}

static void sf_c26_adcs_v15_integral_Power(void)
{
  int32_T c26_previousEvent;
  real_T c26_clk;
  real_T c26_batt_cap;
  real_T c26_watts_time;
  real_T c26_flag_charge;
  real_T c26_flag_discharge;
  real_T c26_b_s_SIM_STEP_SIZE;
  real_T c26_vbat;
  real_T c26_nargout = 6.0;
  real_T c26_nargin = 7.0;
  real_T c26_internal_resistance;
  real_T c26_current;
  real_T c26_Flag_discharge;
  real_T c26_frac_Batt_cap;
  real_T c26_Flag_charge;
  real_T c26_VBat;
  real_T c26_Batt_cap;
  real_T c26_A;
  real_T c26_a;
  real_T c26_b_a;
  real_T c26_b;
  real_T c26_B;
  real_T c26_x;
  real_T c26_y;
  real_T c26_b_x;
  real_T c26_b_y;
  real_T c26_c_x;
  real_T c26_c_y;
  real_T c26_b_A;
  real_T c26_b_b;
  real_T c26_b_B;
  real_T c26_d_x;
  real_T c26_d_y;
  real_T c26_e_x;
  real_T c26_e_y;
  real_T c26_f_x;
  real_T c26_f_y;
  real_T c26_g_y;
  real_T c26_c_A;
  real_T c26_c_a;
  real_T c26_d_a;
  real_T c26_c_b;
  real_T c26_c_B;
  real_T c26_g_x;
  real_T c26_h_y;
  real_T c26_h_x;
  real_T c26_i_y;
  real_T c26_i_x;
  real_T c26_j_y;
  real_T c26_d_A;
  real_T c26_d_b;
  real_T c26_d_B;
  real_T c26_j_x;
  real_T c26_k_y;
  real_T c26_k_x;
  real_T c26_l_y;
  real_T c26_l_x;
  real_T c26_m_y;
  real_T c26_n_y;
  real_T c26_e_A;
  real_T c26_m_x;
  real_T c26_n_x;
  real_T c26_o_x;
  real_T *c26_b_current;
  real_T *c26_b_Flag_discharge;
  real_T *c26_b_frac_Batt_cap;
  real_T *c26_b_Flag_charge;
  real_T *c26_b_VBat;
  real_T *c26_b_Batt_cap;
  real_T *c26_b_vbat;
  real_T *c26_b_flag_discharge;
  real_T *c26_b_flag_charge;
  real_T *c26_b_watts_time;
  real_T *c26_b_batt_cap;
  real_T *c26_b_clk;
  c26_b_frac_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c26_b_watts_time = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c26_b_batt_cap = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c26_b_flag_charge = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c26_b_current = (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c26_b_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c26_b_flag_discharge = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c26_b_Flag_charge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c26_b_VBat = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c26_b_Flag_discharge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c26_b_clk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c26_b_vbat = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,19);
  _SFD_DATA_RANGE_CHECK(*c26_b_clk, 0U);
  _SFD_DATA_RANGE_CHECK(*c26_b_Batt_cap, 1U);
  _SFD_DATA_RANGE_CHECK(*c26_b_batt_cap, 2U);
  _SFD_DATA_RANGE_CHECK(*c26_b_watts_time, 3U);
  _SFD_DATA_RANGE_CHECK(*c26_b_VBat, 4U);
  _SFD_DATA_RANGE_CHECK(*c26_b_flag_charge, 5U);
  _SFD_DATA_RANGE_CHECK(*c26_b_Flag_charge, 6U);
  _SFD_DATA_RANGE_CHECK(*c26_b_frac_Batt_cap, 7U);
  _SFD_DATA_RANGE_CHECK(*c26_b_flag_discharge, 8U);
  _SFD_DATA_RANGE_CHECK(*c26_b_Flag_discharge, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c26_s_SIM_STEP_SIZE, 10U);
  _SFD_DATA_RANGE_CHECK(*c26_b_vbat, 11U);
  _SFD_DATA_RANGE_CHECK(*c26_b_current, 12U);
  c26_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,19);
  c26_clk = *c26_b_clk;
  c26_batt_cap = *c26_b_batt_cap;
  c26_watts_time = *c26_b_watts_time;
  c26_flag_charge = *c26_b_flag_charge;
  c26_flag_discharge = *c26_b_flag_discharge;
  c26_b_s_SIM_STEP_SIZE = chartInstance.c26_s_SIM_STEP_SIZE;
  c26_vbat = *c26_b_vbat;
  sf_debug_symbol_scope_push(16U, 0U);
  sf_debug_symbol_scope_add("nargout", &c26_nargout, c26_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c26_nargin, c26_sf_marshall);
  sf_debug_symbol_scope_add("internal_resistance", &c26_internal_resistance,
    c26_sf_marshall);
  sf_debug_symbol_scope_add("current", &c26_current, c26_sf_marshall);
  sf_debug_symbol_scope_add("Flag_discharge", &c26_Flag_discharge,
    c26_sf_marshall);
  sf_debug_symbol_scope_add("frac_Batt_cap", &c26_frac_Batt_cap, c26_sf_marshall);
  sf_debug_symbol_scope_add("Flag_charge", &c26_Flag_charge, c26_sf_marshall);
  sf_debug_symbol_scope_add("VBat", &c26_VBat, c26_sf_marshall);
  sf_debug_symbol_scope_add("Batt_cap", &c26_Batt_cap, c26_sf_marshall);
  sf_debug_symbol_scope_add("vbat", &c26_vbat, c26_sf_marshall);
  sf_debug_symbol_scope_add("s_SIM_STEP_SIZE", &c26_b_s_SIM_STEP_SIZE,
    c26_sf_marshall);
  sf_debug_symbol_scope_add("flag_discharge", &c26_flag_discharge,
    c26_sf_marshall);
  sf_debug_symbol_scope_add("flag_charge", &c26_flag_charge, c26_sf_marshall);
  sf_debug_symbol_scope_add("watts_time", &c26_watts_time, c26_sf_marshall);
  sf_debug_symbol_scope_add("batt_cap", &c26_batt_cap, c26_sf_marshall);
  sf_debug_symbol_scope_add("clk", &c26_clk, c26_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  E0 = 4.0085; R = 0.016818; K = 0.0094937; A = 0.31425; B = 27.7554; */
  /*  alp = 0.001; bet = 0.005; */
  /*  for i=1:1:sizex(2) */
  /*      y(i) = 0.45*exp(-alp*x(i)) + 3.75 - exp(bet*(x(i)-2200));  */
  /*  end */
  /*  current = -2.2; %Amps  graph internal resistant = 80mohms */
  _SFD_EML_CALL(0,9);
  c26_internal_resistance = 0.08;

  /* ohms */
  _SFD_EML_CALL(0,11);
  if (CV_EML_IF(0, 0, c26_clk < 0.15)) {
    _SFD_EML_CALL(0,12);
    c26_Batt_cap = 2000.0;

    /*  x 6 batteries (reduced battery capacity by 360 mAh assuming 1 mA consumption) */
    _SFD_EML_CALL(0,13);
    c26_current = 0.0;

    /* Amps */
    _SFD_EML_CALL(0,14);
    c26_VBat = c26_isro_battery(200.0, 0.0, 0.08);
    _SFD_EML_CALL(0,15);
    c26_Flag_charge = 0.0;
    _SFD_EML_CALL(0,16);
    c26_Flag_discharge = 0.0;
  } else {
    _SFD_EML_CALL(0,19);
    if (CV_EML_IF(0, 1, c26_watts_time < 0.0)) {
      _SFD_EML_CALL(0,20);
      c26_A = c26_watts_time;
      c26_a = c26_b_s_SIM_STEP_SIZE;
      c26_b_a = c26_a * 2.0;
      c26_b = c26_vbat;
      c26_B = c26_b_a * c26_b;
      c26_x = c26_A;
      c26_y = c26_B;
      if (c26_y == 0.0) {
        c26_eml_warning();
      }

      c26_b_x = c26_x;
      c26_b_y = c26_y;
      c26_c_x = c26_b_x;
      c26_c_y = c26_b_y;
      c26_current = c26_c_x / c26_c_y;
      _SFD_EML_CALL(0,21);
      c26_b_A = c26_watts_time;
      c26_b_b = c26_vbat;
      c26_b_B = 21.6 * c26_b_b;
      c26_d_x = c26_b_A;
      c26_d_y = c26_b_B;
      if (c26_d_y == 0.0) {
        c26_eml_warning();
      }

      c26_e_x = c26_d_x;
      c26_e_y = c26_d_y;
      c26_f_x = c26_e_x;
      c26_f_y = c26_e_y;
      c26_g_y = c26_f_x / c26_f_y;
      c26_Batt_cap = c26_batt_cap + c26_g_y;
      _SFD_EML_CALL(0,22);
      c26_VBat = c26_isro_battery(2200.0 - c26_Batt_cap, c26_current, 0.08);
    } else {
      _SFD_EML_CALL(0,24);
      if (CV_EML_IF(0, 2, c26_flag_charge == 1.0)) {
        _SFD_EML_CALL(0,25);
        c26_c_A = c26_watts_time;
        c26_c_a = c26_b_s_SIM_STEP_SIZE;
        c26_d_a = c26_c_a * 2.0;
        c26_c_b = c26_vbat;
        c26_c_B = c26_d_a * c26_c_b;
        c26_g_x = c26_c_A;
        c26_h_y = c26_c_B;
        if (c26_h_y == 0.0) {
          c26_eml_warning();
        }

        c26_h_x = c26_g_x;
        c26_i_y = c26_h_y;
        c26_i_x = c26_h_x;
        c26_j_y = c26_i_y;
        c26_current = c26_i_x / c26_j_y;
        _SFD_EML_CALL(0,26);
        c26_d_A = c26_watts_time;
        c26_d_b = c26_vbat;
        c26_d_B = 21.6 * c26_d_b;
        c26_j_x = c26_d_A;
        c26_k_y = c26_d_B;
        if (c26_k_y == 0.0) {
          c26_eml_warning();
        }

        c26_k_x = c26_j_x;
        c26_l_y = c26_k_y;
        c26_l_x = c26_k_x;
        c26_m_y = c26_l_y;
        c26_n_y = c26_l_x / c26_m_y;
        c26_Batt_cap = c26_batt_cap + c26_n_y;
        _SFD_EML_CALL(0,27);
        c26_VBat = c26_isro_battery(2200.0 - c26_Batt_cap, c26_current, 0.08);
      } else {
        _SFD_EML_CALL(0,29);
        c26_current = 0.0;
        _SFD_EML_CALL(0,30);
        c26_Batt_cap = c26_batt_cap;
        _SFD_EML_CALL(0,31);
        c26_VBat = c26_isro_battery(2200.0 - c26_Batt_cap, 0.0, 0.08);
      }
    }
  }

  _SFD_EML_CALL(0,36);
  if (CV_EML_IF(0, 3, c26_VBat < 3.95)) {
    _SFD_EML_CALL(0,37);
    c26_Flag_charge = 1.0;
  } else {
    _SFD_EML_CALL(0,39);
    if (CV_EML_IF(0, 4, c26_VBat > 4.25)) {
      _SFD_EML_CALL(0,40);
      c26_Flag_charge = -2.0;
    } else {
      _SFD_EML_CALL(0,42);
      c26_Flag_charge = c26_flag_charge;
    }
  }

  _SFD_EML_CALL(0,46);
  c26_e_A = c26_Batt_cap;
  c26_m_x = c26_e_A;
  c26_n_x = c26_m_x;
  c26_o_x = c26_n_x;
  c26_frac_Batt_cap = c26_o_x / 2199.0;
  _SFD_EML_CALL(0,48);
  if (CV_EML_IF(0, 5, c26_VBat < 3.5)) {
    _SFD_EML_CALL(0,49);
    c26_Flag_discharge = 1.0;
  } else {
    _SFD_EML_CALL(0,51);
    c26_Flag_discharge = 0.0;
  }

  _SFD_EML_CALL(0,-51);
  sf_debug_symbol_scope_pop();
  *c26_b_Batt_cap = c26_Batt_cap;
  *c26_b_VBat = c26_VBat;
  *c26_b_Flag_charge = c26_Flag_charge;
  *c26_b_frac_Batt_cap = c26_frac_Batt_cap;
  *c26_b_Flag_discharge = c26_Flag_discharge;
  *c26_b_current = c26_current;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,19);
  _sfEvent_ = c26_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c26_chartNumber, 0U, sf_debug_get_script_id(
    "E:/adcs_v15_BackUp/isro_battery.m"));
}

static real_T c26_isro_battery(real_T c26_x, real_T c26_current, real_T
  c26_internal_resistance)
{
  real_T c26_y;
  real_T c26_nargout = 1.0;
  real_T c26_nargin = 3.0;
  real_T c26_slope;
  real_T c26_a;
  real_T c26_b;
  real_T c26_b_y;
  real_T c26_b_b;
  real_T c26_c_y;
  real_T c26_b_a;
  real_T c26_c_b;
  real_T c26_d_y;
  real_T c26_c_a;
  real_T c26_d_b;
  real_T c26_e_y;
  real_T c26_d_a;
  real_T c26_e_b;
  real_T c26_f_y;
  real_T c26_e_a;
  real_T c26_f_b;
  real_T c26_g_y;
  real_T c26_f_a;
  real_T c26_g_b;
  real_T c26_h_y;
  real_T c26_g_a;
  real_T c26_h_b;
  real_T c26_i_y;
  real_T c26_h_a;
  real_T c26_i_b;
  real_T c26_j_y;
  real_T c26_i_a;
  real_T c26_j_b;
  real_T c26_k_y;
  real_T c26_j_a;
  real_T c26_k_b;
  real_T c26_l_y;
  real_T c26_k_a;
  real_T c26_l_b;
  real_T c26_m_y;
  real_T c26_m_b;
  real_T c26_n_y;
  sf_debug_symbol_scope_push(7U, 0U);
  sf_debug_symbol_scope_add("nargout", &c26_nargout, c26_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c26_nargin, c26_sf_marshall);
  sf_debug_symbol_scope_add("slope", &c26_slope, c26_sf_marshall);
  sf_debug_symbol_scope_add("y", &c26_y, c26_sf_marshall);
  sf_debug_symbol_scope_add("internal_resistance", &c26_internal_resistance,
    c26_sf_marshall);
  sf_debug_symbol_scope_add("current", &c26_current, c26_sf_marshall);
  sf_debug_symbol_scope_add("x", &c26_x, c26_sf_marshall);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0,3);
  if (CV_SCRIPT_IF(0, 0, c26_x >= 0.0)) {
    _SFD_SCRIPT_CALL(0,4);
    c26_a = c26_current;
    c26_b = c26_internal_resistance;
    c26_b_y = c26_a * c26_b;
    c26_b_b = c26_x;
    c26_c_y = 7.2522E-005 * c26_b_b;
    c26_b_a = c26_x;
    c26_c_b = c26_power(c26_b_a, 2.0);
    c26_d_y = 9.0949E-006 * c26_c_b;
    c26_c_a = c26_x;
    c26_d_b = c26_power(c26_c_a, 3.0);
    c26_e_y = 5.871E-008 * c26_d_b;
    c26_d_a = c26_x;
    c26_e_b = c26_power(c26_d_a, 4.0);
    c26_f_y = 1.8299E-010 * c26_e_b;
    c26_e_a = c26_x;
    c26_f_b = c26_power(c26_e_a, 5.0);
    c26_g_y = 3.2457E-013 * c26_f_b;
    c26_f_a = c26_x;
    c26_g_b = c26_power(c26_f_a, 6.0);
    c26_h_y = 3.4941E-016 * c26_g_b;
    c26_g_a = c26_x;
    c26_h_b = c26_power(c26_g_a, 7.0);
    c26_i_y = 2.3253E-019 * c26_h_b;
    c26_h_a = c26_x;
    c26_i_b = c26_power(c26_h_a, 8.0);
    c26_j_y = 9.3448E-023 * c26_i_b;
    c26_i_a = c26_x;
    c26_j_b = c26_power(c26_i_a, 9.0);
    c26_k_y = 2.0777E-026 * c26_j_b;
    c26_j_a = c26_x;
    c26_k_b = c26_power(c26_j_a, 10.0);
    c26_l_y = -1.9617E-030 * c26_k_b;
    c26_y = (((((((((((c26_l_y + c26_k_y) - c26_j_y) + c26_i_y) - c26_h_y) +
                   c26_g_y) - c26_f_y) + c26_e_y) - c26_d_y) - c26_c_y) +
              4.0607) + 0.17712) + c26_b_y;
  } else {
    _SFD_SCRIPT_CALL(0,6);
    c26_slope = 2.5000000000003909E-004;
    _SFD_SCRIPT_CALL(0,7);
    c26_k_a = c26_current;
    c26_l_b = c26_internal_resistance;
    c26_m_y = c26_k_a * c26_l_b;
    c26_m_b = 0.0 - c26_x;
    c26_n_y = 2.5000000000003909E-004 * c26_m_b;
    c26_y = (4.238 + c26_n_y) + c26_m_y;
  }

  _SFD_SCRIPT_CALL(0,-7);
  sf_debug_symbol_scope_pop();
  return c26_y;
}

static real_T c26_power(real_T c26_a, real_T c26_b)
{
  real_T c26_ak;
  real_T c26_bk;
  real_T c26_x;
  real_T c26_b_x;
  c26_ak = c26_a;
  c26_bk = c26_b;
  if (c26_ak < 0.0) {
    c26_x = c26_bk;
    c26_b_x = c26_x;
    c26_b_x = muDoubleScalarFloor(c26_b_x);
    if (c26_b_x != c26_bk) {
      c26_eml_error();
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c26_ak, c26_bk);
}

static void c26_eml_error(void)
{
  int32_T c26_i0;
  static char_T c26_cv0[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
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

  char_T c26_u[102];
  const mxArray *c26_y = NULL;
  int32_T c26_i1;
  static char_T c26_cv1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c26_b_u[32];
  const mxArray *c26_b_y = NULL;
  for (c26_i0 = 0; c26_i0 < 102; c26_i0 = c26_i0 + 1) {
    c26_u[c26_i0] = c26_cv0[c26_i0];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c26_i1 = 0; c26_i1 < 32; c26_i1 = c26_i1 + 1) {
    c26_b_u[c26_i1] = c26_cv1[c26_i1];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c26_b_y, 14, c26_y);
}

static void c26_eml_warning(void)
{
  int32_T c26_i2;
  static char_T c26_cv2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c26_u[15];
  const mxArray *c26_y = NULL;
  int32_T c26_i3;
  static char_T c26_cv3[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c26_b_u[19];
  const mxArray *c26_b_y = NULL;
  for (c26_i2 = 0; c26_i2 < 15; c26_i2 = c26_i2 + 1) {
    c26_u[c26_i2] = c26_cv2[c26_i2];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c26_i3 = 0; c26_i3 < 19; c26_i3 = c26_i3 + 1) {
    c26_b_u[c26_i3] = c26_cv3[c26_i3];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c26_b_y, 14, c26_y);
}

static const mxArray *c26_sf_marshall(void *c26_chartInstance, void *c26_u)
{
  const mxArray *c26_y = NULL;
  real_T c26_b_u;
  const mxArray *c26_b_y = NULL;
  c26_y = NULL;
  c26_b_u = *((real_T *)c26_u);
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c26_y, c26_b_y);
  return c26_y;
}

const mxArray *sf_c26_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c26_nameCaptureInfo = NULL;
  c26_ResolvedFunctionInfo c26_info[34];
  const mxArray *c26_m0 = NULL;
  int32_T c26_i4;
  c26_ResolvedFunctionInfo *c26_r0;
  c26_nameCaptureInfo = NULL;
  c26_info_helper(c26_info);
  sf_mex_assign(&c26_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34));
  for (c26_i4 = 0; c26_i4 < 34; c26_i4 = c26_i4 + 1) {
    c26_r0 = &c26_info[c26_i4];
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c26_r0->context)), "context"
                    , "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c26_r0->name)), "name",
                    "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      c26_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c26_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c26_r0->resolved)),
                    "resolved", "nameCaptureInfo", c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c26_i4);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c26_i4);
  }

  sf_mex_assign(&c26_nameCaptureInfo, c26_m0);
  return c26_nameCaptureInfo;
}

static void c26_info_helper(c26_ResolvedFunctionInfo c26_info[34])
{
  c26_info[0].context = "";
  c26_info[0].name = "lt";
  c26_info[0].dominantType = "double";
  c26_info[0].resolved = "[B]lt";
  c26_info[0].fileLength = 0U;
  c26_info[0].fileTime1 = 0U;
  c26_info[0].fileTime2 = 0U;
  c26_info[1].context = "";
  c26_info[1].name = "minus";
  c26_info[1].dominantType = "double";
  c26_info[1].resolved = "[B]minus";
  c26_info[1].fileLength = 0U;
  c26_info[1].fileTime1 = 0U;
  c26_info[1].fileTime2 = 0U;
  c26_info[2].context = "";
  c26_info[2].name = "isro_battery";
  c26_info[2].dominantType = "double";
  c26_info[2].resolved = "[]E:/adcs_v15_BackUp/isro_battery.m";
  c26_info[2].fileLength = 424U;
  c26_info[2].fileTime1 = 1337023449U;
  c26_info[2].fileTime2 = 0U;
  c26_info[3].context = "[]E:/adcs_v15_BackUp/isro_battery.m";
  c26_info[3].name = "ge";
  c26_info[3].dominantType = "double";
  c26_info[3].resolved = "[B]ge";
  c26_info[3].fileLength = 0U;
  c26_info[3].fileTime1 = 0U;
  c26_info[3].fileTime2 = 0U;
  c26_info[4].context = "[]E:/adcs_v15_BackUp/isro_battery.m";
  c26_info[4].name = "uminus";
  c26_info[4].dominantType = "double";
  c26_info[4].resolved = "[B]uminus";
  c26_info[4].fileLength = 0U;
  c26_info[4].fileTime1 = 0U;
  c26_info[4].fileTime2 = 0U;
  c26_info[5].context = "[]E:/adcs_v15_BackUp/isro_battery.m";
  c26_info[5].name = "mpower";
  c26_info[5].dominantType = "double";
  c26_info[5].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[5].fileLength = 3710U;
  c26_info[5].fileTime1 = 1238421690U;
  c26_info[5].fileTime2 = 0U;
  c26_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[6].name = "nargin";
  c26_info[6].dominantType = "";
  c26_info[6].resolved = "[B]nargin";
  c26_info[6].fileLength = 0U;
  c26_info[6].fileTime1 = 0U;
  c26_info[6].fileTime2 = 0U;
  c26_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[7].name = "gt";
  c26_info[7].dominantType = "double";
  c26_info[7].resolved = "[B]gt";
  c26_info[7].fileLength = 0U;
  c26_info[7].fileTime1 = 0U;
  c26_info[7].fileTime2 = 0U;
  c26_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[8].name = "isa";
  c26_info[8].dominantType = "double";
  c26_info[8].resolved = "[B]isa";
  c26_info[8].fileLength = 0U;
  c26_info[8].fileTime1 = 0U;
  c26_info[8].fileTime2 = 0U;
  c26_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[9].name = "isinteger";
  c26_info[9].dominantType = "double";
  c26_info[9].resolved = "[B]isinteger";
  c26_info[9].fileLength = 0U;
  c26_info[9].fileTime1 = 0U;
  c26_info[9].fileTime2 = 0U;
  c26_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[10].name = "isscalar";
  c26_info[10].dominantType = "double";
  c26_info[10].resolved = "[B]isscalar";
  c26_info[10].fileLength = 0U;
  c26_info[10].fileTime1 = 0U;
  c26_info[10].fileTime2 = 0U;
  c26_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[11].name = "ndims";
  c26_info[11].dominantType = "double";
  c26_info[11].resolved = "[B]ndims";
  c26_info[11].fileLength = 0U;
  c26_info[11].fileTime1 = 0U;
  c26_info[11].fileTime2 = 0U;
  c26_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[12].name = "eq";
  c26_info[12].dominantType = "double";
  c26_info[12].resolved = "[B]eq";
  c26_info[12].fileLength = 0U;
  c26_info[12].fileTime1 = 0U;
  c26_info[12].fileTime2 = 0U;
  c26_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[13].name = "size";
  c26_info[13].dominantType = "double";
  c26_info[13].resolved = "[B]size";
  c26_info[13].fileLength = 0U;
  c26_info[13].fileTime1 = 0U;
  c26_info[13].fileTime2 = 0U;
  c26_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c26_info[14].name = "power";
  c26_info[14].dominantType = "double";
  c26_info[14].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c26_info[14].fileLength = 5380U;
  c26_info[14].fileTime1 = 1228077698U;
  c26_info[14].fileTime2 = 0U;
  c26_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c26_info[15].name = "eml_scalar_eg";
  c26_info[15].dominantType = "double";
  c26_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c26_info[15].fileLength = 3068U;
  c26_info[15].fileTime1 = 1240249410U;
  c26_info[15].fileTime2 = 0U;
  c26_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c26_info[16].name = "false";
  c26_info[16].dominantType = "";
  c26_info[16].resolved = "[B]false";
  c26_info[16].fileLength = 0U;
  c26_info[16].fileTime1 = 0U;
  c26_info[16].fileTime2 = 0U;
  c26_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c26_info[17].name = "isstruct";
  c26_info[17].dominantType = "double";
  c26_info[17].resolved = "[B]isstruct";
  c26_info[17].fileLength = 0U;
  c26_info[17].fileTime1 = 0U;
  c26_info[17].fileTime2 = 0U;
  c26_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c26_info[18].name = "class";
  c26_info[18].dominantType = "double";
  c26_info[18].resolved = "[B]class";
  c26_info[18].fileLength = 0U;
  c26_info[18].fileTime1 = 0U;
  c26_info[18].fileTime2 = 0U;
  c26_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c26_info[19].name = "cast";
  c26_info[19].dominantType = "double";
  c26_info[19].resolved = "[B]cast";
  c26_info[19].fileLength = 0U;
  c26_info[19].fileTime1 = 0U;
  c26_info[19].fileTime2 = 0U;
  c26_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c26_info[20].name = "plus";
  c26_info[20].dominantType = "double";
  c26_info[20].resolved = "[B]plus";
  c26_info[20].fileLength = 0U;
  c26_info[20].fileTime1 = 0U;
  c26_info[20].fileTime2 = 0U;
  c26_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c26_info[21].name = "isreal";
  c26_info[21].dominantType = "double";
  c26_info[21].resolved = "[B]isreal";
  c26_info[21].fileLength = 0U;
  c26_info[21].fileTime1 = 0U;
  c26_info[21].fileTime2 = 0U;
  c26_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c26_info[22].name = "eml_scalexp_alloc";
  c26_info[22].dominantType = "double";
  c26_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c26_info[22].fileLength = 808U;
  c26_info[22].fileTime1 = 1230478500U;
  c26_info[22].fileTime2 = 0U;
  c26_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c26_info[23].name = "not";
  c26_info[23].dominantType = "logical";
  c26_info[23].resolved = "[B]not";
  c26_info[23].fileLength = 0U;
  c26_info[23].fileTime1 = 0U;
  c26_info[23].fileTime2 = 0U;
  c26_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c26_info[24].name = "eml_scalar_floor";
  c26_info[24].dominantType = "double";
  c26_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c26_info[24].fileLength = 260U;
  c26_info[24].fileTime1 = 1209318190U;
  c26_info[24].fileTime2 = 0U;
  c26_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c26_info[25].name = "ne";
  c26_info[25].dominantType = "double";
  c26_info[25].resolved = "[B]ne";
  c26_info[25].fileLength = 0U;
  c26_info[25].fileTime1 = 0U;
  c26_info[25].fileTime2 = 0U;
  c26_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c26_info[26].name = "eml_error";
  c26_info[26].dominantType = "char";
  c26_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c26_info[26].fileLength = 315U;
  c26_info[26].fileTime1 = 1213914146U;
  c26_info[26].fileTime2 = 0U;
  c26_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c26_info[27].name = "strcmp";
  c26_info[27].dominantType = "char";
  c26_info[27].resolved = "[B]strcmp";
  c26_info[27].fileLength = 0U;
  c26_info[27].fileTime1 = 0U;
  c26_info[27].fileTime2 = 0U;
  c26_info[28].context = "[]E:/adcs_v15_BackUp/isro_battery.m";
  c26_info[28].name = "mtimes";
  c26_info[28].dominantType = "double";
  c26_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c26_info[28].fileLength = 3302U;
  c26_info[28].fileTime1 = 1242738294U;
  c26_info[28].fileTime2 = 0U;
  c26_info[29].context = "[]E:/adcs_v15_BackUp/isro_battery.m";
  c26_info[29].name = "mrdivide";
  c26_info[29].dominantType = "double";
  c26_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c26_info[29].fileLength = 800U;
  c26_info[29].fileTime1 = 1238421692U;
  c26_info[29].fileTime2 = 0U;
  c26_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c26_info[30].name = "rdivide";
  c26_info[30].dominantType = "double";
  c26_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c26_info[30].fileLength = 620U;
  c26_info[30].fileTime1 = 1213914166U;
  c26_info[30].fileTime2 = 0U;
  c26_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c26_info[31].name = "isempty";
  c26_info[31].dominantType = "double";
  c26_info[31].resolved = "[B]isempty";
  c26_info[31].fileLength = 0U;
  c26_info[31].fileTime1 = 0U;
  c26_info[31].fileTime2 = 0U;
  c26_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c26_info[32].name = "eml_warning";
  c26_info[32].dominantType = "char";
  c26_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c26_info[32].fileLength = 262U;
  c26_info[32].fileTime1 = 1236241078U;
  c26_info[32].fileTime2 = 0U;
  c26_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c26_info[33].name = "eml_div";
  c26_info[33].dominantType = "double";
  c26_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c26_info[33].fileLength = 4269U;
  c26_info[33].fileTime1 = 1228077626U;
  c26_info[33].fileTime2 = 0U;
}

static const mxArray *c26_b_sf_marshall(void *c26_chartInstance, void *c26_u)
{
  const mxArray *c26_y = NULL;
  boolean_T c26_b_u;
  const mxArray *c26_b_y = NULL;
  c26_y = NULL;
  c26_b_u = *((boolean_T *)c26_u);
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c26_y, c26_b_y);
  return c26_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c26_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1874558440U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2503281057U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(40088522U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1284005514U);
}

mxArray *sf_c26_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4070429779U);
    pr[1] = (double)(2504664987U);
    pr[2] = (double)(3620808499U);
    pr[3] = (double)(1361253395U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c26_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"Batt_cap\",},{M[1],M[10],T\"Flag_charge\",},{M[1],M[13],T\"Flag_discharge\",},{M[1],M[8],T\"VBat\",},{M[1],M[16],T\"current\",},{M[1],M[11],T\"frac_Batt_cap\",},{M[8],M[0],T\"is_active_c26_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           26,
           1,
           1,
           13,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"clk",0,
                              (MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Batt_cap",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "batt_cap",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "watts_time",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"VBat",0,
                              (MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "flag_charge",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Flag_charge",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "frac_Batt_cap",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "flag_discharge",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(9,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Flag_discharge",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(10,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "s_SIM_STEP_SIZE",0,(MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"vbat",0,
                              (MexFcnForType)c26_sf_marshall);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "current",0,(MexFcnForType)c26_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,6,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1681);
        _SFD_CV_INIT_EML_IF(0,0,454,467,711,1348);
        _SFD_CV_INIT_EML_IF(0,1,728,745,939,1344);
        _SFD_CV_INIT_EML_IF(0,2,952,971,1180,1336);
        _SFD_CV_INIT_EML_IF(0,3,1350,1364,1387,1493);
        _SFD_CV_INIT_EML_IF(0,4,1396,1410,1442,1489);
        _SFD_CV_INIT_EML_IF(0,5,1533,1546,1571,1604);
        _SFD_CV_INIT_SCRIPT(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"isro_battery",0,-1,415);
        _SFD_CV_INIT_SCRIPT_IF(0,0,68,77,316,413);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c26_clk;
          real_T *c26_Batt_cap;
          real_T *c26_batt_cap;
          real_T *c26_watts_time;
          real_T *c26_VBat;
          real_T *c26_flag_charge;
          real_T *c26_Flag_charge;
          real_T *c26_frac_Batt_cap;
          real_T *c26_flag_discharge;
          real_T *c26_Flag_discharge;
          real_T *c26_vbat;
          real_T *c26_current;
          c26_frac_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c26_watts_time = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c26_batt_cap = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c26_flag_charge = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c26_current = (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
          c26_Batt_cap = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c26_flag_discharge = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c26_Flag_charge = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c26_VBat = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c26_Flag_discharge = (real_T *)ssGetOutputPortSignal(chartInstance.S,
            5);
          c26_clk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c26_vbat = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          _SFD_SET_DATA_VALUE_PTR(0U, c26_clk);
          _SFD_SET_DATA_VALUE_PTR(1U, c26_Batt_cap);
          _SFD_SET_DATA_VALUE_PTR(2U, c26_batt_cap);
          _SFD_SET_DATA_VALUE_PTR(3U, c26_watts_time);
          _SFD_SET_DATA_VALUE_PTR(4U, c26_VBat);
          _SFD_SET_DATA_VALUE_PTR(5U, c26_flag_charge);
          _SFD_SET_DATA_VALUE_PTR(6U, c26_Flag_charge);
          _SFD_SET_DATA_VALUE_PTR(7U, c26_frac_Batt_cap);
          _SFD_SET_DATA_VALUE_PTR(8U, c26_flag_discharge);
          _SFD_SET_DATA_VALUE_PTR(9U, c26_Flag_discharge);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance.c26_s_SIM_STEP_SIZE);
          _SFD_SET_DATA_VALUE_PTR(11U, c26_vbat);
          _SFD_SET_DATA_VALUE_PTR(12U, c26_current);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c26_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c26_adcs_v15_integral_Power();
  initialize_c26_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c26_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c26_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c26_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c26_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c26_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c26_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c26_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c26_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c26_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c26_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c26_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c26_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c26_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c26_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c26_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c26_adcs_v15_integral_Power(SimStruct *S)
{
  /* Actual parameters from chart:
     s_SIM_STEP_SIZE
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for s_SIM_STEP_SIZE*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",26,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",26,6);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",26,6);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(167798810U));
  ssSetChecksum1(S,(3938468578U));
  ssSetChecksum2(S,(288338262U));
  ssSetChecksum3(S,(879978855U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c26_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",26);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c26_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c26_adcs_v15_integral_Power;
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

void c26_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
