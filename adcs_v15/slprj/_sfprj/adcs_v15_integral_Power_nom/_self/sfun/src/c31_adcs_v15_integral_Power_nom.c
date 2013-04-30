/* Include files */

#include "blascompat32.h"
#include "adcs_v15_integral_Power_nom_sfun.h"
#include "c31_adcs_v15_integral_Power_nom.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "adcs_v15_integral_Power_nom_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c31_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc31_adcs_v15_integral_Power_nomInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c31_adcs_v15_integral_Power_nom(void);
static void initialize_params_c31_adcs_v15_integral_Power_nom(void);
static void enable_c31_adcs_v15_integral_Power_nom(void);
static void disable_c31_adcs_v15_integral_Power_nom(void);
static void c31_update_debugger_state_c31_adcs_v15_integral_Power_nom(void);
static void ext_mode_exec_c31_adcs_v15_integral_Power_nom(void);
static const mxArray *get_sim_state_c31_adcs_v15_integral_Power_nom(void);
static void set_sim_state_c31_adcs_v15_integral_Power_nom(const mxArray *c31_st);
static void finalize_c31_adcs_v15_integral_Power_nom(void);
static void sf_c31_adcs_v15_integral_Power_nom(void);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber);
static const mxArray *c31_sf_marshall(void *c31_chartInstance, void *c31_u);
static const mxArray *c31_b_sf_marshall(void *c31_chartInstance, void *c31_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c31_adcs_v15_integral_Power_nom(void)
{
  uint8_T *c31_is_active_c31_adcs_v15_integral_Power_nom;
  c31_is_active_c31_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c31_is_active_c31_adcs_v15_integral_Power_nom = 0U;
}

static void initialize_params_c31_adcs_v15_integral_Power_nom(void)
{
}

static void enable_c31_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c31_adcs_v15_integral_Power_nom(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c31_update_debugger_state_c31_adcs_v15_integral_Power_nom(void)
{
}

static void ext_mode_exec_c31_adcs_v15_integral_Power_nom(void)
{
  c31_update_debugger_state_c31_adcs_v15_integral_Power_nom();
}

static const mxArray *get_sim_state_c31_adcs_v15_integral_Power_nom(void)
{
  const mxArray *c31_st = NULL;
  const mxArray *c31_y = NULL;
  real_T c31_u;
  const mxArray *c31_b_y = NULL;
  uint8_T c31_b_u;
  const mxArray *c31_c_y = NULL;
  real_T *c31_pow_drawn;
  uint8_T *c31_is_active_c31_adcs_v15_integral_Power_nom;
  c31_is_active_c31_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c31_pow_drawn = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellarray(2));
  c31_u = *c31_pow_drawn;
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_b_u = *c31_is_active_c31_adcs_v15_integral_Power_nom;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c31_y, 1, c31_c_y);
  sf_mex_assign(&c31_st, c31_y);
  return c31_st;
}

static void set_sim_state_c31_adcs_v15_integral_Power_nom(const mxArray *c31_st)
{
  const mxArray *c31_u;
  const mxArray *c31_pow_drawn;
  real_T c31_d0;
  real_T c31_y;
  const mxArray *c31_is_active_c31_adcs_v15_integral_Power_nom;
  uint8_T c31_u0;
  uint8_T c31_b_y;
  boolean_T *c31_doneDoubleBufferReInit;
  real_T *c31_b_pow_drawn;
  uint8_T *c31_b_is_active_c31_adcs_v15_integral_Power_nom;
  c31_b_is_active_c31_adcs_v15_integral_Power_nom = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c31_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c31_b_pow_drawn = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  *c31_doneDoubleBufferReInit = true;
  c31_u = sf_mex_dup(c31_st);
  c31_pow_drawn = sf_mex_dup(sf_mex_getcell(c31_u, 0));
  sf_mex_import("pow_drawn", sf_mex_dup(c31_pow_drawn), &c31_d0, 1, 0, 0U, 0, 0U,
                0);
  c31_y = c31_d0;
  sf_mex_destroy(&c31_pow_drawn);
  *c31_b_pow_drawn = c31_y;
  c31_is_active_c31_adcs_v15_integral_Power_nom = sf_mex_dup(sf_mex_getcell
    (c31_u, 1));
  sf_mex_import("is_active_c31_adcs_v15_integral_Power_nom", sf_mex_dup
                (c31_is_active_c31_adcs_v15_integral_Power_nom), &c31_u0, 1, 3
                , 0U, 0, 0U, 0);
  c31_b_y = c31_u0;
  sf_mex_destroy(&c31_is_active_c31_adcs_v15_integral_Power_nom);
  *c31_b_is_active_c31_adcs_v15_integral_Power_nom = c31_b_y;
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_adcs_v15_integral_Power_nom();
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_adcs_v15_integral_Power_nom(void)
{
}

static void sf_c31_adcs_v15_integral_Power_nom(void)
{
  int32_T c31_previousEvent;
  real_T c31_Vbat;
  real_T c31_pow;
  real_T c31_nargout = 1.0;
  real_T c31_nargin = 2.0;
  real_T c31_battery;
  real_T c31_pow_drawn;
  real_T *c31_b_Vbat;
  real_T *c31_b_pow;
  real_T *c31_b_pow_drawn;
  c31_b_pow = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c31_b_Vbat = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c31_b_pow_drawn = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,24);
  _SFD_DATA_RANGE_CHECK(*c31_b_Vbat, 0U);
  _SFD_DATA_RANGE_CHECK(*c31_b_pow, 1U);
  _SFD_DATA_RANGE_CHECK(*c31_b_pow_drawn, 2U);
  c31_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,24);
  c31_Vbat = *c31_b_Vbat;
  c31_pow = *c31_b_pow;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add("nargout", &c31_nargout, c31_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c31_nargin, c31_sf_marshall);
  sf_debug_symbol_scope_add("battery", &c31_battery, c31_sf_marshall);
  sf_debug_symbol_scope_add("pow_drawn", &c31_pow_drawn, c31_sf_marshall);
  sf_debug_symbol_scope_add("pow", &c31_pow, c31_sf_marshall);
  sf_debug_symbol_scope_add("Vbat", &c31_Vbat, c31_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c31_battery = 0.0;
  _SFD_EML_CALL(0,7);
  if (CV_EML_IF(0, 0, c31_Vbat > 3.0)) {
    _SFD_EML_CALL(0,8);
    c31_battery = 1.0;
  } else {
    _SFD_EML_CALL(0,10);
    c31_battery = 0.0;
  }

  _SFD_EML_CALL(0,13);
  if (CV_EML_IF(0, 1, c31_battery == 1.0)) {
    _SFD_EML_CALL(0,14);
    c31_pow_drawn = c31_pow;
  } else {
    _SFD_EML_CALL(0,16);
    c31_pow_drawn = 0.0;
  }

  _SFD_EML_CALL(0,-16);
  sf_debug_symbol_scope_pop();
  *c31_b_pow_drawn = c31_pow_drawn;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
  _sfEvent_ = c31_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_adcs_v15_integral_Power_nomMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber)
{
}

static const mxArray *c31_sf_marshall(void *c31_chartInstance, void *c31_u)
{
  const mxArray *c31_y = NULL;
  real_T c31_b_u;
  const mxArray *c31_b_y = NULL;
  c31_y = NULL;
  c31_b_u = *((real_T *)c31_u);
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c31_y, c31_b_y);
  return c31_y;
}

const mxArray
  *sf_c31_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info(void)
{
  const mxArray *c31_nameCaptureInfo = NULL;
  c31_ResolvedFunctionInfo c31_info[2];
  c31_ResolvedFunctionInfo (*c31_b_info)[2];
  const mxArray *c31_m0 = NULL;
  int32_T c31_i0;
  c31_ResolvedFunctionInfo *c31_r0;
  c31_nameCaptureInfo = NULL;
  c31_b_info = (c31_ResolvedFunctionInfo (*)[2])c31_info;
  (*c31_b_info)[0].context = "";
  (*c31_b_info)[0].name = "gt";
  (*c31_b_info)[0].dominantType = "double";
  (*c31_b_info)[0].resolved = "[B]gt";
  (*c31_b_info)[0].fileLength = 0U;
  (*c31_b_info)[0].fileTime1 = 0U;
  (*c31_b_info)[0].fileTime2 = 0U;
  (*c31_b_info)[1].context = "";
  (*c31_b_info)[1].name = "eq";
  (*c31_b_info)[1].dominantType = "double";
  (*c31_b_info)[1].resolved = "[B]eq";
  (*c31_b_info)[1].fileLength = 0U;
  (*c31_b_info)[1].fileTime1 = 0U;
  (*c31_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c31_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for (c31_i0 = 0; c31_i0 < 2; c31_i0 = c31_i0 + 1) {
    c31_r0 = &c31_info[c31_i0];
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c31_r0->context)), "context"
                    , "nameCaptureInfo", c31_i0);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c31_r0->name)), "name",
                    "nameCaptureInfo", c31_i0);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      c31_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c31_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c31_i0);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c31_r0->resolved)),
                    "resolved", "nameCaptureInfo", c31_i0);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c31_i0);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c31_i0);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c31_i0);
  }

  sf_mex_assign(&c31_nameCaptureInfo, c31_m0);
  return c31_nameCaptureInfo;
}

static const mxArray *c31_b_sf_marshall(void *c31_chartInstance, void *c31_u)
{
  const mxArray *c31_y = NULL;
  boolean_T c31_b_u;
  const mxArray *c31_b_y = NULL;
  c31_y = NULL;
  c31_b_u = *((boolean_T *)c31_u);
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c31_y, c31_b_y);
  return c31_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c31_adcs_v15_integral_Power_nom_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1742647172U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3140223093U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1266903492U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(491566437U);
}

mxArray *sf_c31_adcs_v15_integral_Power_nom_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1182779610U);
    pr[1] = (double)(3336495085U);
    pr[2] = (double)(332585477U);
    pr[3] = (double)(187604071U);
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

static mxArray *sf_get_sim_state_info_c31_adcs_v15_integral_Power_nom(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"pow_drawn\",},{M[8],M[0],T\"is_active_c31_adcs_v15_integral_Power_nom\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_adcs_v15_integral_Power_nom_get_check_sum(&mxChecksum);
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
           31,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Vbat",0,
                              (MexFcnForType)c31_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"pow",0,
                              (MexFcnForType)c31_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "pow_drawn",0,(MexFcnForType)c31_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,254);
        _SFD_CV_INIT_EML_IF(0,0,134,145,163,188);
        _SFD_CV_INIT_EML_IF(0,1,190,205,227,254);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c31_Vbat;
          real_T *c31_pow;
          real_T *c31_pow_drawn;
          c31_pow = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c31_Vbat = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c31_pow_drawn = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c31_Vbat);
          _SFD_SET_DATA_VALUE_PTR(1U, c31_pow);
          _SFD_SET_DATA_VALUE_PTR(2U, c31_pow_drawn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_adcs_v15_integral_Power_nomMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c31_adcs_v15_integral_Power_nom();
  initialize_c31_adcs_v15_integral_Power_nom();
}

static void sf_opaque_enable_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  enable_c31_adcs_v15_integral_Power_nom();
}

static void sf_opaque_disable_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  disable_c31_adcs_v15_integral_Power_nom();
}

static void sf_opaque_gateway_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  sf_c31_adcs_v15_integral_Power_nom();
}

static void sf_opaque_ext_mode_exec_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  ext_mode_exec_c31_adcs_v15_integral_Power_nom();
}

static mxArray* sf_opaque_get_sim_state_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c31_adcs_v15_integral_Power_nom();
  return st;
}

static void sf_opaque_set_sim_state_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c31_adcs_v15_integral_Power_nom(sf_mex_dup(st));
}

static void sf_opaque_terminate_c31_adcs_v15_integral_Power_nom(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c31_adcs_v15_integral_Power_nom();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_adcs_v15_integral_Power_nom(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c31_adcs_v15_integral_Power_nom();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c31_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("adcs_v15_integral_Power_nom",
                "adcs_v15_integral_Power_nom",31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "adcs_v15_integral_Power_nom","adcs_v15_integral_Power_nom",31,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",31,2);
      sf_mark_chart_reusable_outputs(S,"adcs_v15_integral_Power_nom",
        "adcs_v15_integral_Power_nom",31,1);
    }

    sf_set_rtw_dwork_info(S,"adcs_v15_integral_Power_nom",
                          "adcs_v15_integral_Power_nom",31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(879351951U));
  ssSetChecksum1(S,(3790118364U));
  ssSetChecksum2(S,(4250711417U));
  ssSetChecksum3(S,(1688137038U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c31_adcs_v15_integral_Power_nom(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "adcs_v15_integral_Power_nom",
      "adcs_v15_integral_Power_nom",31);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_adcs_v15_integral_Power_nom(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlStart = mdlStart_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c31_adcs_v15_integral_Power_nom;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c31_adcs_v15_integral_Power_nom;
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

void c31_adcs_v15_integral_Power_nom_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_adcs_v15_integral_Power_nom(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_adcs_v15_integral_Power_nom(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_adcs_v15_integral_Power_nom_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
