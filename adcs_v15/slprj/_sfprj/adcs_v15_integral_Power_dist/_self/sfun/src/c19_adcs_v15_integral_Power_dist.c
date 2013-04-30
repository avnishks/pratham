/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_dist_sfun.h"
#include "c19_adcs_v15_integral_Power_dist.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_dist_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c19_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc19_adcs_v15_integral_Power_distInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c19_adcs_v15_integral_Power_dist(void);
static void initialize_params_c19_adcs_v15_integral_Power_dist(void);
static void enable_c19_adcs_v15_integral_Power_dist(void);
static void disable_c19_adcs_v15_integral_Power_dist(void);
static void c19_update_debugger_state_c19_adcs_v15_integral_Power_dist(void);
static void ext_mode_exec_c19_adcs_v15_integral_Power_dist(void);
static const mxArray *get_sim_state_c19_adcs_v15_integral_Power_dist(void);
static void set_sim_state_c19_adcs_v15_integral_Power_dist(const mxArray *c19_st);
static void finalize_c19_adcs_v15_integral_Power_dist(void);
static void sf_c19_adcs_v15_integral_Power_dist(void);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static real_T c19_mpower(real_T c19_a);
static const mxArray *c19_sf_marshall(void *c19_chartInstance, void *c19_u);
static void c19_info_helper(c19_ResolvedFunctionInfo c19_info[35]);
static const mxArray *c19_b_sf_marshall(void *c19_chartInstance, void *c19_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c19_adcs_v15_integral_Power_dist(void)
{
  uint8_T *c19_is_active_c19_adcs_v15_integral_Power_dist;
  c19_is_active_c19_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c19_is_active_c19_adcs_v15_integral_Power_dist = 0U;
}

static void initialize_params_c19_adcs_v15_integral_Power_dist(void)
{
}

static void enable_c19_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c19_adcs_v15_integral_Power_dist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c19_update_debugger_state_c19_adcs_v15_integral_Power_dist(void)
{
}

static void ext_mode_exec_c19_adcs_v15_integral_Power_dist(void)
{
  c19_update_debugger_state_c19_adcs_v15_integral_Power_dist();
}

static const mxArray *get_sim_state_c19_adcs_v15_integral_Power_dist(void)
{
  const mxArray *c19_st = NULL;
  const mxArray *c19_y = NULL;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  real_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T c19_c_u;
  const mxArray *c19_d_y = NULL;
  real_T c19_d_u;
  const mxArray *c19_e_y = NULL;
  uint8_T c19_e_u;
  const mxArray *c19_f_y = NULL;
  real_T *c19_Downlink_power;
  real_T *c19_flag_downlink;
  real_T *c19_flag_france;
  real_T *c19_flag_india;
  uint8_T *c19_is_active_c19_adcs_v15_integral_Power_dist;
  c19_flag_france = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c19_flag_downlink = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c19_Downlink_power = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c19_is_active_c19_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c19_flag_india = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(5));
  c19_u = *c19_Downlink_power;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_u = *c19_flag_downlink;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 1, c19_c_y);
  c19_c_u = *c19_flag_france;
  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 2, c19_d_y);
  c19_d_u = *c19_flag_india;
  c19_e_y = NULL;
  sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 3, c19_e_y);
  c19_e_u = *c19_is_active_c19_adcs_v15_integral_Power_dist;
  c19_f_y = NULL;
  sf_mex_assign(&c19_f_y, sf_mex_create("y", &c19_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 4, c19_f_y);
  sf_mex_assign(&c19_st, c19_y);
  return c19_st;
}

static void set_sim_state_c19_adcs_v15_integral_Power_dist(const mxArray *c19_st)
{
  const mxArray *c19_u;
  const mxArray *c19_Downlink_power;
  real_T c19_d0;
  real_T c19_y;
  const mxArray *c19_b_Downlink_power;
  real_T c19_d1;
  real_T c19_b_y;
  const mxArray *c19_c_Downlink_power;
  real_T c19_d2;
  real_T c19_c_y;
  const mxArray *c19_d_Downlink_power;
  real_T c19_d3;
  real_T c19_d_y;
  const mxArray *c19_is_active_c19_adcs_v15_integral_Power_dist;
  uint8_T c19_u0;
  uint8_T c19_e_y;
  boolean_T *c19_doneDoubleBufferReInit;
  real_T *c19_e_Downlink_power;
  real_T *c19_flag_downlink;
  real_T *c19_flag_france;
  real_T *c19_flag_india;
  uint8_T *c19_b_is_active_c19_adcs_v15_integral_Power_dist;
  c19_flag_france = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c19_flag_downlink = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c19_e_Downlink_power = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c19_b_is_active_c19_adcs_v15_integral_Power_dist = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c19_flag_india = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c19_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  c19_Downlink_power = sf_mex_dup(sf_mex_getcell(c19_u, 0));
  sf_mex_import("Downlink_power", sf_mex_dup(c19_Downlink_power), &c19_d0, 1, 0,
                0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_Downlink_power);
  *c19_e_Downlink_power = c19_y;
  c19_b_Downlink_power = sf_mex_dup(sf_mex_getcell(c19_u, 1));
  sf_mex_import("flag_downlink", sf_mex_dup(c19_b_Downlink_power), &c19_d1, 1, 0,
                0U, 0, 0U, 0);
  c19_b_y = c19_d1;
  sf_mex_destroy(&c19_b_Downlink_power);
  *c19_flag_downlink = c19_b_y;
  c19_c_Downlink_power = sf_mex_dup(sf_mex_getcell(c19_u, 2));
  sf_mex_import("flag_france", sf_mex_dup(c19_c_Downlink_power), &c19_d2, 1, 0,
                0U, 0, 0U, 0);
  c19_c_y = c19_d2;
  sf_mex_destroy(&c19_c_Downlink_power);
  *c19_flag_france = c19_c_y;
  c19_d_Downlink_power = sf_mex_dup(sf_mex_getcell(c19_u, 3));
  sf_mex_import("flag_india", sf_mex_dup(c19_d_Downlink_power), &c19_d3, 1, 0,
                0U, 0, 0U, 0);
  c19_d_y = c19_d3;
  sf_mex_destroy(&c19_d_Downlink_power);
  *c19_flag_india = c19_d_y;
  c19_is_active_c19_adcs_v15_integral_Power_dist = sf_mex_dup(sf_mex_getcell
    (c19_u, 4));
  sf_mex_import("is_active_c19_adcs_v15_integral_Power_dist", sf_mex_dup
                (c19_is_active_c19_adcs_v15_integral_Power_dist), &c19_u0, 1,
                3, 0U, 0, 0U, 0);
  c19_e_y = c19_u0;
  sf_mex_destroy(&c19_is_active_c19_adcs_v15_integral_Power_dist);
  *c19_b_is_active_c19_adcs_v15_integral_Power_dist = c19_e_y;
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_adcs_v15_integral_Power_dist();
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_adcs_v15_integral_Power_dist(void)
{
}

static void sf_c19_adcs_v15_integral_Power_dist(void)
{
  int32_T c19_previousEvent;
  real_T c19_Latitude;
  real_T c19_Longitude;
  real_T c19_nargout = 4.0;
  real_T c19_nargin = 2.0;
  real_T c19_phi;
  real_T c19_flag_india;
  real_T c19_flag_france;
  real_T c19_flag_downlink;
  real_T c19_Downlink_power;
  real_T c19_a;
  real_T c19_A;
  real_T c19_x;
  real_T c19_b_x;
  real_T c19_c_x;
  real_T c19_d_x;
  real_T c19_b_a;
  real_T c19_e_x;
  real_T c19_b;
  real_T c19_y;
  real_T c19_c_a;
  real_T c19_b_A;
  real_T c19_f_x;
  real_T c19_g_x;
  real_T c19_h_x;
  real_T c19_i_x;
  real_T c19_d_a;
  real_T c19_j_x;
  real_T c19_b_b;
  real_T c19_b_y;
  real_T c19_e_a;
  real_T *c19_b_flag_india;
  real_T *c19_b_flag_france;
  real_T *c19_b_flag_downlink;
  real_T *c19_b_Downlink_power;
  real_T *c19_b_Longitude;
  real_T *c19_b_Latitude;
  c19_b_flag_france = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c19_b_flag_downlink = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c19_b_Downlink_power = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c19_b_Latitude = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c19_b_Longitude = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c19_b_flag_india = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,13);
  _SFD_DATA_RANGE_CHECK(*c19_b_Latitude, 0U);
  _SFD_DATA_RANGE_CHECK(*c19_b_Longitude, 1U);
  _SFD_DATA_RANGE_CHECK(*c19_b_Downlink_power, 2U);
  _SFD_DATA_RANGE_CHECK(*c19_b_flag_downlink, 3U);
  _SFD_DATA_RANGE_CHECK(*c19_b_flag_france, 4U);
  _SFD_DATA_RANGE_CHECK(*c19_b_flag_india, 5U);
  c19_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,13);
  c19_Latitude = *c19_b_Latitude;
  c19_Longitude = *c19_b_Longitude;
  sf_debug_symbol_scope_push(9U, 0U);
  sf_debug_symbol_scope_add("nargout", &c19_nargout, c19_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c19_nargin, c19_sf_marshall);
  sf_debug_symbol_scope_add("phi", &c19_phi, c19_sf_marshall);
  sf_debug_symbol_scope_add("flag_india", &c19_flag_india, c19_sf_marshall);
  sf_debug_symbol_scope_add("flag_france", &c19_flag_france, c19_sf_marshall);
  sf_debug_symbol_scope_add("flag_downlink", &c19_flag_downlink, c19_sf_marshall);
  sf_debug_symbol_scope_add("Downlink_power", &c19_Downlink_power,
    c19_sf_marshall);
  sf_debug_symbol_scope_add("Longitude", &c19_Longitude, c19_sf_marshall);
  sf_debug_symbol_scope_add("Latitude", &c19_Latitude, c19_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c19_phi = 10.0;
  _SFD_EML_CALL(0,4);
  c19_flag_france = 0.0;
  _SFD_EML_CALL(0,5);
  c19_flag_india = 0.0;
  _SFD_EML_CALL(0,6);
  c19_a = c19_Latitude;
  c19_A = c19_a * 3.1415926535897931E+000;
  c19_x = c19_A;
  c19_b_x = c19_x;
  c19_c_x = c19_b_x;
  c19_d_x = c19_c_x / 180.0;
  c19_b_a = c19_d_x;
  c19_e_x = c19_b_a;
  c19_b_a = c19_e_x;
  c19_b_a = muDoubleScalarCos(c19_b_a);
  c19_b = c19_mpower(c19_Longitude - 82.7666);
  c19_y = c19_b_a * c19_b;
  if (CV_EML_IF(0, 0, c19_mpower(c19_Latitude - 22.5833) + c19_y < c19_mpower
                (25.0))) {
    _SFD_EML_CALL(0,7);
    c19_flag_downlink = 1.0;
    _SFD_EML_CALL(0,8);
    c19_flag_india = 1.0;
  } else {
    _SFD_EML_CALL(0,9);
    c19_c_a = c19_Latitude;
    c19_b_A = c19_c_a * 3.1415926535897931E+000;
    c19_f_x = c19_b_A;
    c19_g_x = c19_f_x;
    c19_h_x = c19_g_x;
    c19_i_x = c19_h_x / 180.0;
    c19_d_a = c19_i_x;
    c19_j_x = c19_d_a;
    c19_d_a = c19_j_x;
    c19_d_a = muDoubleScalarCos(c19_d_a);
    c19_b_b = c19_mpower(c19_Longitude - 2.33);
    c19_b_y = c19_d_a * c19_b_b;
    if (CV_EML_IF(0, 1, c19_mpower(c19_Latitude - 48.8) + c19_b_y < c19_mpower
                  (10.0))) {
      _SFD_EML_CALL(0,10);
      c19_flag_downlink = 1.0;
      _SFD_EML_CALL(0,11);
      c19_flag_france = 1.0;
    } else {
      _SFD_EML_CALL(0,13);
      c19_flag_downlink = 0.0;
    }
  }

  _SFD_EML_CALL(0,16);
  c19_e_a = c19_flag_downlink;
  c19_Downlink_power = c19_e_a * 2.6;

  /* W */
  /*   */
  /*  y = u; */
  _SFD_EML_CALL(0,-16);
  sf_debug_symbol_scope_pop();
  *c19_b_Downlink_power = c19_Downlink_power;
  *c19_b_flag_downlink = c19_flag_downlink;
  *c19_b_flag_france = c19_flag_france;
  *c19_b_flag_india = c19_flag_india;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
  _sfEvent_ = c19_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_distMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

static real_T c19_mpower(real_T c19_a)
{
  real_T c19_b_a;
  real_T c19_ak;
  c19_b_a = c19_a;
  c19_ak = c19_b_a;
  return muDoubleScalarPower(c19_ak, 2.0);
}

static const mxArray *c19_sf_marshall(void *c19_chartInstance, void *c19_u)
{
  const mxArray *c19_y = NULL;
  real_T c19_b_u;
  const mxArray *c19_b_y = NULL;
  c19_y = NULL;
  c19_b_u = *((real_T *)c19_u);
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c19_y, c19_b_y);
  return c19_y;
}

const mxArray
  *sf_c19_adcs_v15_integral_Power_dist_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_ResolvedFunctionInfo c19_info[35];
  const mxArray *c19_m0 = NULL;
  int32_T c19_i0;
  c19_ResolvedFunctionInfo *c19_r0;
  c19_nameCaptureInfo = NULL;
  c19_info_helper(c19_info);
  sf_mex_assign(&c19_m0, sf_mex_createstruct("nameCaptureInfo", 1, 35));
  for (c19_i0 = 0; c19_i0 < 35; c19_i0 = c19_i0 + 1) {
    c19_r0 = &c19_info[c19_i0];
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->context)), "context"
                    , "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->name)), "name",
                    "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      c19_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->resolved)),
                    "resolved", "nameCaptureInfo", c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c19_i0);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c19_i0);
  }

  sf_mex_assign(&c19_nameCaptureInfo, c19_m0);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(c19_ResolvedFunctionInfo c19_info[35])
{
  c19_info[0].context = "";
  c19_info[0].name = "minus";
  c19_info[0].dominantType = "double";
  c19_info[0].resolved = "[B]minus";
  c19_info[0].fileLength = 0U;
  c19_info[0].fileTime1 = 0U;
  c19_info[0].fileTime2 = 0U;
  c19_info[1].context = "";
  c19_info[1].name = "mpower";
  c19_info[1].dominantType = "double";
  c19_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[1].fileLength = 3710U;
  c19_info[1].fileTime1 = 1238421690U;
  c19_info[1].fileTime2 = 0U;
  c19_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[2].name = "nargin";
  c19_info[2].dominantType = "";
  c19_info[2].resolved = "[B]nargin";
  c19_info[2].fileLength = 0U;
  c19_info[2].fileTime1 = 0U;
  c19_info[2].fileTime2 = 0U;
  c19_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[3].name = "gt";
  c19_info[3].dominantType = "double";
  c19_info[3].resolved = "[B]gt";
  c19_info[3].fileLength = 0U;
  c19_info[3].fileTime1 = 0U;
  c19_info[3].fileTime2 = 0U;
  c19_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[4].name = "isa";
  c19_info[4].dominantType = "double";
  c19_info[4].resolved = "[B]isa";
  c19_info[4].fileLength = 0U;
  c19_info[4].fileTime1 = 0U;
  c19_info[4].fileTime2 = 0U;
  c19_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[5].name = "isinteger";
  c19_info[5].dominantType = "double";
  c19_info[5].resolved = "[B]isinteger";
  c19_info[5].fileLength = 0U;
  c19_info[5].fileTime1 = 0U;
  c19_info[5].fileTime2 = 0U;
  c19_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[6].name = "isscalar";
  c19_info[6].dominantType = "double";
  c19_info[6].resolved = "[B]isscalar";
  c19_info[6].fileLength = 0U;
  c19_info[6].fileTime1 = 0U;
  c19_info[6].fileTime2 = 0U;
  c19_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[7].name = "ndims";
  c19_info[7].dominantType = "double";
  c19_info[7].resolved = "[B]ndims";
  c19_info[7].fileLength = 0U;
  c19_info[7].fileTime1 = 0U;
  c19_info[7].fileTime2 = 0U;
  c19_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[8].name = "eq";
  c19_info[8].dominantType = "double";
  c19_info[8].resolved = "[B]eq";
  c19_info[8].fileLength = 0U;
  c19_info[8].fileTime1 = 0U;
  c19_info[8].fileTime2 = 0U;
  c19_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[9].name = "size";
  c19_info[9].dominantType = "double";
  c19_info[9].resolved = "[B]size";
  c19_info[9].fileLength = 0U;
  c19_info[9].fileTime1 = 0U;
  c19_info[9].fileTime2 = 0U;
  c19_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[10].name = "power";
  c19_info[10].dominantType = "double";
  c19_info[10].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[10].fileLength = 5380U;
  c19_info[10].fileTime1 = 1228077698U;
  c19_info[10].fileTime2 = 0U;
  c19_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[11].name = "eml_scalar_eg";
  c19_info[11].dominantType = "double";
  c19_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c19_info[11].fileLength = 3068U;
  c19_info[11].fileTime1 = 1240249410U;
  c19_info[11].fileTime2 = 0U;
  c19_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c19_info[12].name = "false";
  c19_info[12].dominantType = "";
  c19_info[12].resolved = "[B]false";
  c19_info[12].fileLength = 0U;
  c19_info[12].fileTime1 = 0U;
  c19_info[12].fileTime2 = 0U;
  c19_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c19_info[13].name = "isstruct";
  c19_info[13].dominantType = "double";
  c19_info[13].resolved = "[B]isstruct";
  c19_info[13].fileLength = 0U;
  c19_info[13].fileTime1 = 0U;
  c19_info[13].fileTime2 = 0U;
  c19_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c19_info[14].name = "class";
  c19_info[14].dominantType = "double";
  c19_info[14].resolved = "[B]class";
  c19_info[14].fileLength = 0U;
  c19_info[14].fileTime1 = 0U;
  c19_info[14].fileTime2 = 0U;
  c19_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c19_info[15].name = "cast";
  c19_info[15].dominantType = "double";
  c19_info[15].resolved = "[B]cast";
  c19_info[15].fileLength = 0U;
  c19_info[15].fileTime1 = 0U;
  c19_info[15].fileTime2 = 0U;
  c19_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c19_info[16].name = "plus";
  c19_info[16].dominantType = "double";
  c19_info[16].resolved = "[B]plus";
  c19_info[16].fileLength = 0U;
  c19_info[16].fileTime1 = 0U;
  c19_info[16].fileTime2 = 0U;
  c19_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c19_info[17].name = "isreal";
  c19_info[17].dominantType = "double";
  c19_info[17].resolved = "[B]isreal";
  c19_info[17].fileLength = 0U;
  c19_info[17].fileTime1 = 0U;
  c19_info[17].fileTime2 = 0U;
  c19_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[18].name = "eml_scalexp_alloc";
  c19_info[18].dominantType = "double";
  c19_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[18].fileLength = 808U;
  c19_info[18].fileTime1 = 1230478500U;
  c19_info[18].fileTime2 = 0U;
  c19_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[19].name = "not";
  c19_info[19].dominantType = "logical";
  c19_info[19].resolved = "[B]not";
  c19_info[19].fileLength = 0U;
  c19_info[19].fileTime1 = 0U;
  c19_info[19].fileTime2 = 0U;
  c19_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[20].name = "lt";
  c19_info[20].dominantType = "double";
  c19_info[20].resolved = "[B]lt";
  c19_info[20].fileLength = 0U;
  c19_info[20].fileTime1 = 0U;
  c19_info[20].fileTime2 = 0U;
  c19_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[21].name = "eml_scalar_floor";
  c19_info[21].dominantType = "double";
  c19_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c19_info[21].fileLength = 260U;
  c19_info[21].fileTime1 = 1209318190U;
  c19_info[21].fileTime2 = 0U;
  c19_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[22].name = "ne";
  c19_info[22].dominantType = "double";
  c19_info[22].resolved = "[B]ne";
  c19_info[22].fileLength = 0U;
  c19_info[22].fileTime1 = 0U;
  c19_info[22].fileTime2 = 0U;
  c19_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[23].name = "eml_error";
  c19_info[23].dominantType = "char";
  c19_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c19_info[23].fileLength = 315U;
  c19_info[23].fileTime1 = 1213914146U;
  c19_info[23].fileTime2 = 0U;
  c19_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c19_info[24].name = "strcmp";
  c19_info[24].dominantType = "char";
  c19_info[24].resolved = "[B]strcmp";
  c19_info[24].fileLength = 0U;
  c19_info[24].fileTime1 = 0U;
  c19_info[24].fileTime2 = 0U;
  c19_info[25].context = "";
  c19_info[25].name = "pi";
  c19_info[25].dominantType = "";
  c19_info[25].resolved = "[B]pi";
  c19_info[25].fileLength = 0U;
  c19_info[25].fileTime1 = 0U;
  c19_info[25].fileTime2 = 0U;
  c19_info[26].context = "";
  c19_info[26].name = "mtimes";
  c19_info[26].dominantType = "double";
  c19_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[26].fileLength = 3302U;
  c19_info[26].fileTime1 = 1242738294U;
  c19_info[26].fileTime2 = 0U;
  c19_info[27].context = "";
  c19_info[27].name = "mrdivide";
  c19_info[27].dominantType = "double";
  c19_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c19_info[27].fileLength = 800U;
  c19_info[27].fileTime1 = 1238421692U;
  c19_info[27].fileTime2 = 0U;
  c19_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c19_info[28].name = "ge";
  c19_info[28].dominantType = "double";
  c19_info[28].resolved = "[B]ge";
  c19_info[28].fileLength = 0U;
  c19_info[28].fileTime1 = 0U;
  c19_info[28].fileTime2 = 0U;
  c19_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c19_info[29].name = "rdivide";
  c19_info[29].dominantType = "double";
  c19_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[29].fileLength = 620U;
  c19_info[29].fileTime1 = 1213914166U;
  c19_info[29].fileTime2 = 0U;
  c19_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[30].name = "isempty";
  c19_info[30].dominantType = "double";
  c19_info[30].resolved = "[B]isempty";
  c19_info[30].fileLength = 0U;
  c19_info[30].fileTime1 = 0U;
  c19_info[30].fileTime2 = 0U;
  c19_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[31].name = "eml_warning";
  c19_info[31].dominantType = "char";
  c19_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c19_info[31].fileLength = 262U;
  c19_info[31].fileTime1 = 1236241078U;
  c19_info[31].fileTime2 = 0U;
  c19_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[32].name = "eml_div";
  c19_info[32].dominantType = "double";
  c19_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c19_info[32].fileLength = 4269U;
  c19_info[32].fileTime1 = 1228077626U;
  c19_info[32].fileTime2 = 0U;
  c19_info[33].context = "";
  c19_info[33].name = "cos";
  c19_info[33].dominantType = "double";
  c19_info[33].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[33].fileLength = 324U;
  c19_info[33].fileTime1 = 1203431752U;
  c19_info[33].fileTime2 = 0U;
  c19_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[34].name = "eml_scalar_cos";
  c19_info[34].dominantType = "double";
  c19_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c19_info[34].fileLength = 602U;
  c19_info[34].fileTime1 = 1209318188U;
  c19_info[34].fileTime2 = 0U;
}

static const mxArray *c19_b_sf_marshall(void *c19_chartInstance, void *c19_u)
{
  const mxArray *c19_y = NULL;
  boolean_T c19_b_u;
  const mxArray *c19_b_y = NULL;
  c19_y = NULL;
  c19_b_u = *((boolean_T *)c19_u);
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c19_y, c19_b_y);
  return c19_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c19_adcs_v15_integral_Power_dist_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1656127838U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4111246121U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(739106941U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3705672589U);
}

mxArray *sf_c19_adcs_v15_integral_Power_dist_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3633074092U);
    pr[1] = (double)(2555006803U);
    pr[2] = (double)(1115852785U);
    pr[3] = (double)(2853424931U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c19_adcs_v15_integral_Power_dist(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[7],T\"Downlink_power\",},{M[1],M[8],T\"flag_downlink\",},{M[1],M[9],T\"flag_france\",},{M[1],M[10],T\"flag_india\",},{M[8],M[0],T\"is_active_c19_adcs_v15_integral_Power_dist\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_adcs_v15_integral_Power_dist_get_check_sum(&mxChecksum);
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
           19,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Latitude",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Longitude",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Downlink_power",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "flag_downlink",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "flag_france",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "flag_india",0,(MexFcnForType)c19_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,475);
        _SFD_CV_INIT_EML_IF(0,0,141,228,272,426);
        _SFD_CV_INIT_EML_IF(0,1,272,350,395,426);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c19_Latitude;
          real_T *c19_Longitude;
          real_T *c19_Downlink_power;
          real_T *c19_flag_downlink;
          real_T *c19_flag_france;
          real_T *c19_flag_india;
          c19_flag_france = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c19_flag_downlink = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c19_Downlink_power = (real_T *)ssGetOutputPortSignal(chartInstance.S,
            1);
          c19_Latitude = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c19_Longitude = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c19_flag_india = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_Latitude);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_Longitude);
          _SFD_SET_DATA_VALUE_PTR(2U, c19_Downlink_power);
          _SFD_SET_DATA_VALUE_PTR(3U, c19_flag_downlink);
          _SFD_SET_DATA_VALUE_PTR(4U, c19_flag_france);
          _SFD_SET_DATA_VALUE_PTR(5U, c19_flag_india);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_distMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c19_adcs_v15_integral_Power_dist();
  initialize_c19_adcs_v15_integral_Power_dist();
}

static void sf_opaque_enable_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  enable_c19_adcs_v15_integral_Power_dist();
}

static void sf_opaque_disable_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  disable_c19_adcs_v15_integral_Power_dist();
}

static void sf_opaque_gateway_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  sf_c19_adcs_v15_integral_Power_dist();
}

static void sf_opaque_ext_mode_exec_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  ext_mode_exec_c19_adcs_v15_integral_Power_dist();
}

static mxArray* sf_opaque_get_sim_state_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c19_adcs_v15_integral_Power_dist();
  return st;
}

static void sf_opaque_set_sim_state_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c19_adcs_v15_integral_Power_dist(sf_mex_dup(st));
}

static void sf_opaque_terminate_c19_adcs_v15_integral_Power_dist(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c19_adcs_v15_integral_Power_dist();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_adcs_v15_integral_Power_dist(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_adcs_v15_integral_Power_dist();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c19_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_dist",
                "adcs_v15_integral_Power_dist",19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_dist","adcs_v15_integral_Power_dist",19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",19,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_dist",
        "adcs_v15_integral_Power_dist",19,4);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_dist",
                          "adcs_v15_integral_Power_dist",19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2325183243U));
  ssSetChecksum1(S,(1124782313U));
  ssSetChecksum2(S,(3778958781U));
  ssSetChecksum3(S,(3844299426U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c19_adcs_v15_integral_Power_dist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_dist",
      "adcs_v15_integral_Power_dist",19);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_adcs_v15_integral_Power_dist(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlStart = mdlStart_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_adcs_v15_integral_Power_dist;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c19_adcs_v15_integral_Power_dist;
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

void c19_adcs_v15_integral_Power_dist_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_adcs_v15_integral_Power_dist(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_adcs_v15_integral_Power_dist(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_adcs_v15_integral_Power_dist_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
