/* Include files */

#include "adcs_v15_integral_Power_nom_sfun.h"
#include "c1_adcs_v15_integral_Power_nom.h"
#include "c2_adcs_v15_integral_Power_nom.h"
#include "c4_adcs_v15_integral_Power_nom.h"
#include "c5_adcs_v15_integral_Power_nom.h"
#include "c6_adcs_v15_integral_Power_nom.h"
#include "c7_adcs_v15_integral_Power_nom.h"
#include "c8_adcs_v15_integral_Power_nom.h"
#include "c9_adcs_v15_integral_Power_nom.h"
#include "c10_adcs_v15_integral_Power_nom.h"
#include "c11_adcs_v15_integral_Power_nom.h"
#include "c12_adcs_v15_integral_Power_nom.h"
#include "c13_adcs_v15_integral_Power_nom.h"
#include "c16_adcs_v15_integral_Power_nom.h"
#include "c19_adcs_v15_integral_Power_nom.h"
#include "c20_adcs_v15_integral_Power_nom.h"
#include "c22_adcs_v15_integral_Power_nom.h"
#include "c23_adcs_v15_integral_Power_nom.h"
#include "c24_adcs_v15_integral_Power_nom.h"
#include "c25_adcs_v15_integral_Power_nom.h"
#include "c26_adcs_v15_integral_Power_nom.h"
#include "c27_adcs_v15_integral_Power_nom.h"
#include "c28_adcs_v15_integral_Power_nom.h"
#include "c29_adcs_v15_integral_Power_nom.h"
#include "c30_adcs_v15_integral_Power_nom.h"
#include "c31_adcs_v15_integral_Power_nom.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _adcs_v15_integral_Power_nomMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void adcs_v15_integral_Power_nom_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void adcs_v15_integral_Power_nom_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_adcs_v15_integral_Power_nom_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_adcs_v15_integral_Power_nom_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_adcs_v15_integral_Power_nom_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2252243061U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2117191946U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1599221736U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3750047145U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2457863733U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1394616720U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2967142384U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4067375986U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c1_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c2_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c4_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c5_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c6_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c7_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c8_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c9_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c10_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c11_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c12_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c13_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c16_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c19_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c20_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c22_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c23_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c24_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c25_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c26_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c27_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c28_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c29_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c30_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_adcs_v15_integral_Power_nom_get_check_sum(mxArray
            *plhs[]);
          sf_c31_adcs_v15_integral_Power_nom_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2364224360U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1521043920U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3255461816U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(789461005U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(539223591U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1071627355U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2943525570U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(433836998U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_adcs_v15_integral_Power_nom_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray
          *sf_c1_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c1_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray
          *sf_c2_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c2_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray
          *sf_c4_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c4_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray
          *sf_c5_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c5_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray
          *sf_c6_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c6_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray
          *sf_c7_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c7_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray
          *sf_c8_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c8_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray
          *sf_c9_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c9_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray
          *sf_c10_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c10_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray
          *sf_c11_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c11_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray
          *sf_c12_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c12_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray
          *sf_c13_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c13_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 16:
      {
        extern mxArray
          *sf_c16_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c16_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 19:
      {
        extern mxArray
          *sf_c19_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c19_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 20:
      {
        extern mxArray
          *sf_c20_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c20_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 22:
      {
        extern mxArray
          *sf_c22_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c22_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 23:
      {
        extern mxArray
          *sf_c23_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c23_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 24:
      {
        extern mxArray
          *sf_c24_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c24_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 25:
      {
        extern mxArray
          *sf_c25_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c25_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 26:
      {
        extern mxArray
          *sf_c26_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c26_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 27:
      {
        extern mxArray
          *sf_c27_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c27_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 28:
      {
        extern mxArray
          *sf_c28_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c28_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 29:
      {
        extern mxArray
          *sf_c29_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c29_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 30:
      {
        extern mxArray
          *sf_c30_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c30_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     case 31:
      {
        extern mxArray
          *sf_c31_adcs_v15_integral_Power_nom_get_autoinheritance_info(void);
        plhs[0] = sf_c31_adcs_v15_integral_Power_nom_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray
          *sf_c25_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray
          *sf_c28_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray
          *sf_c29_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_adcs_v15_integral_Power_nom_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void adcs_v15_integral_Power_nom_debug_initialize(void)
{
  _adcs_v15_integral_Power_nomMachineNumber_ = sf_debug_initialize_machine(
    "adcs_v15_integral_Power_nom","sfun",0,25,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_adcs_v15_integral_Power_nomMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_adcs_v15_integral_Power_nomMachineNumber_,0);
}

void adcs_v15_integral_Power_nom_register_exported_symbols(SimStruct* S)
{
}
