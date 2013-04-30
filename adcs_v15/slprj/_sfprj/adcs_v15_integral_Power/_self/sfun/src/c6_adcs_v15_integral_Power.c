/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_sfun.h"
#include "c6_adcs_v15_integral_Power.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc6_adcs_v15_integral_PowerInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c6_adcs_v15_integral_Power(void);
static void initialize_params_c6_adcs_v15_integral_Power(void);
static void enable_c6_adcs_v15_integral_Power(void);
static void disable_c6_adcs_v15_integral_Power(void);
static void c6_update_debugger_state_c6_adcs_v15_integral_Power(void);
static void ext_mode_exec_c6_adcs_v15_integral_Power(void);
static const mxArray *get_sim_state_c6_adcs_v15_integral_Power(void);
static void set_sim_state_c6_adcs_v15_integral_Power(const mxArray *c6_st);
static void finalize_c6_adcs_v15_integral_Power(void);
static void sf_c6_adcs_v15_integral_Power(void);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_b_sf_marshall(void *c6_chartInstance, void *c6_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c6_adcs_v15_integral_Power(void)
{
  uint8_T *c6_is_active_c6_adcs_v15_integral_Power;
  c6_is_active_c6_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c6_is_active_c6_adcs_v15_integral_Power = 0U;
}

static void initialize_params_c6_adcs_v15_integral_Power(void)
{
}

static void enable_c6_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c6_adcs_v15_integral_Power(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c6_update_debugger_state_c6_adcs_v15_integral_Power(void)
{
}

static void ext_mode_exec_c6_adcs_v15_integral_Power(void)
{
  c6_update_debugger_state_c6_adcs_v15_integral_Power();
}

static const mxArray *get_sim_state_c6_adcs_v15_integral_Power(void)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T *c6_d_y;
  uint8_T *c6_is_active_c6_adcs_v15_integral_Power;
  c6_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_is_active_c6_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  c6_u = *c6_d_y;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_u = *c6_is_active_c6_adcs_v15_integral_Power;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_adcs_v15_integral_Power(const mxArray *c6_st)
{
  const mxArray *c6_u;
  const mxArray *c6_y;
  real_T c6_d0;
  real_T c6_b_y;
  const mxArray *c6_is_active_c6_adcs_v15_integral_Power;
  uint8_T c6_u0;
  uint8_T c6_c_y;
  boolean_T *c6_doneDoubleBufferReInit;
  real_T *c6_d_y;
  uint8_T *c6_b_is_active_c6_adcs_v15_integral_Power;
  c6_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c6_b_is_active_c6_adcs_v15_integral_Power = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_y = sf_mex_dup(sf_mex_getcell(c6_u, 0));
  sf_mex_import("y", sf_mex_dup(c6_y), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_b_y = c6_d0;
  sf_mex_destroy(&c6_y);
  *c6_d_y = c6_b_y;
  c6_is_active_c6_adcs_v15_integral_Power = sf_mex_dup(sf_mex_getcell(c6_u, 1));
  sf_mex_import("is_active_c6_adcs_v15_integral_Power", sf_mex_dup
                (c6_is_active_c6_adcs_v15_integral_Power), &c6_u0, 1, 3, 0U, 0,
                0U,
                0);
  c6_c_y = c6_u0;
  sf_mex_destroy(&c6_is_active_c6_adcs_v15_integral_Power);
  *c6_b_is_active_c6_adcs_v15_integral_Power = c6_c_y;
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_adcs_v15_integral_Power();
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_adcs_v15_integral_Power(void)
{
}

static void sf_c6_adcs_v15_integral_Power(void)
{
  int32_T c6_previousEvent;
  real_T c6_a;
  real_T c6_b;
  real_T c6_nargout = 1.0;
  real_T c6_nargin = 2.0;
  real_T c6_c;
  real_T c6_y;
  real_T *c6_b_a;
  real_T *c6_b_y;
  real_T *c6_b_b;
  c6_b_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_b_b = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c6_b_a = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,4);
  _SFD_DATA_RANGE_CHECK(*c6_b_a, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_b_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_b_b, 2U);
  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,4);
  c6_a = *c6_b_a;
  c6_b = *c6_b_b;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add("nargout", &c6_nargout, c6_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c6_nargin, c6_sf_marshall);
  sf_debug_symbol_scope_add("c", &c6_c, c6_sf_marshall);
  sf_debug_symbol_scope_add("y", &c6_y, c6_sf_marshall);
  sf_debug_symbol_scope_add("b", &c6_b, c6_sf_marshall);
  sf_debug_symbol_scope_add("a", &c6_a, c6_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  c6_c = 1.0 - c6_a;
  _SFD_EML_CALL(0,6);
  c6_y = c6_c + c6_b;
  _SFD_EML_CALL(0,7);
  if (CV_EML_IF(0, 0, c6_y > 1.0)) {
    _SFD_EML_CALL(0,8);
    c6_y = 1.0;
  }

  _SFD_EML_CALL(0,-8);
  sf_debug_symbol_scope_pop();
  *c6_b_y = c6_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency(_adcs_v15_integral_PowerMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_b_u = *((real_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray *sf_c6_adcs_v15_integral_Power_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[3];
  c6_ResolvedFunctionInfo (*c6_b_info)[3];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i0;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[3])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "minus";
  (*c6_b_info)[0].dominantType = "double";
  (*c6_b_info)[0].resolved = "[B]minus";
  (*c6_b_info)[0].fileLength = 0U;
  (*c6_b_info)[0].fileTime1 = 0U;
  (*c6_b_info)[0].fileTime2 = 0U;
  (*c6_b_info)[1].context = "";
  (*c6_b_info)[1].name = "plus";
  (*c6_b_info)[1].dominantType = "double";
  (*c6_b_info)[1].resolved = "[B]plus";
  (*c6_b_info)[1].fileLength = 0U;
  (*c6_b_info)[1].fileTime1 = 0U;
  (*c6_b_info)[1].fileTime2 = 0U;
  (*c6_b_info)[2].context = "";
  (*c6_b_info)[2].name = "gt";
  (*c6_b_info)[2].dominantType = "double";
  (*c6_b_info)[2].resolved = "[B]gt";
  (*c6_b_info)[2].fileLength = 0U;
  (*c6_b_info)[2].fileTime1 = 0U;
  (*c6_b_info)[2].fileTime2 = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3));
  for (c6_i0 = 0; c6_i0 < 3; c6_i0 = c6_i0 + 1) {
    c6_r0 = &c6_info[c6_i0];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i0);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_b_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  boolean_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_b_u = *((boolean_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c6_adcs_v15_integral_Power_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2256430103U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3995483714U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2638429323U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3223913794U);
}

mxArray *sf_c6_adcs_v15_integral_Power_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4056341171U);
    pr[1] = (double)(2989400536U);
    pr[2] = (double)(907661753U);
    pr[3] = (double)(3344013699U);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c6_adcs_v15_integral_Power(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c6_adcs_v15_integral_Power\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_adcs_v15_integral_Power_get_check_sum(&mxChecksum);
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
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"b",0,
                              (MexFcnForType)c6_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,67);
        _SFD_CV_INIT_EML_IF(0,0,48,54,-1,67);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c6_a;
          real_T *c6_y;
          real_T *c6_b;
          c6_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c6_b = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c6_a = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_a);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_b);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_PowerMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c6_adcs_v15_integral_Power();
  initialize_c6_adcs_v15_integral_Power();
}

static void sf_opaque_enable_c6_adcs_v15_integral_Power(void *chartInstanceVar)
{
  enable_c6_adcs_v15_integral_Power();
}

static void sf_opaque_disable_c6_adcs_v15_integral_Power(void *chartInstanceVar)
{
  disable_c6_adcs_v15_integral_Power();
}

static void sf_opaque_gateway_c6_adcs_v15_integral_Power(void *chartInstanceVar)
{
  sf_c6_adcs_v15_integral_Power();
}

static void sf_opaque_ext_mode_exec_c6_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  ext_mode_exec_c6_adcs_v15_integral_Power();
}

static mxArray* sf_opaque_get_sim_state_c6_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c6_adcs_v15_integral_Power();
  return st;
}

static void sf_opaque_set_sim_state_c6_adcs_v15_integral_Power(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c6_adcs_v15_integral_Power(sf_mex_dup(st));
}

static void sf_opaque_terminate_c6_adcs_v15_integral_Power(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c6_adcs_v15_integral_Power();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_adcs_v15_integral_Power(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_adcs_v15_integral_Power();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c6_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
                "adcs_v15_integral_Power",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power",
      "adcs_v15_integral_Power",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",6,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power",
        "adcs_v15_integral_Power",6,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power","adcs_v15_integral_Power",
                          6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(4069801750U));
  ssSetChecksum1(S,(112203930U));
  ssSetChecksum2(S,(3391032831U));
  ssSetChecksum3(S,(3739258198U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_adcs_v15_integral_Power(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power",
      "adcs_v15_integral_Power",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_adcs_v15_integral_Power(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlStart = mdlStart_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_adcs_v15_integral_Power;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c6_adcs_v15_integral_Power;
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

void c6_adcs_v15_integral_Power_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_adcs_v15_integral_Power(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_adcs_v15_integral_Power(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_adcs_v15_integral_Power_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
