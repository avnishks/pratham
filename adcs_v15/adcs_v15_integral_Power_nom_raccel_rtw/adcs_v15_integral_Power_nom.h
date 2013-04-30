#ifndef RTW_HEADER_adcs_v15_integral_Power_nom_h_
#define RTW_HEADER_adcs_v15_integral_Power_nom_h_
#ifndef adcs_v15_integral_Power_nom_COMMON_INCLUDES_
# define adcs_v15_integral_Power_nom_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_nonfinite.h"
#include "rt_rand.h"
#endif

#include "adcs_v15_integral_Power_nom_types.h"
#define MODEL_NAME                     adcs_v15_integral_Power_nom
#define NSAMPLE_TIMES                  (5)
#define NINPUTS                        (0)
#define NOUTPUTS                       (0)
#define NBLOCKIO                       (180)
#define NUM_ZC_EVENTS                  (0)
#ifndef NCSTATES
# define NCSTATES                      (8)
#elif NCSTATES != 8
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

typedef struct {
  real_T Integrator[7];
  real_T FromFile[6];
  real_T TmpRTBAtScope1Inport1[4];
  real_T Sum;
  real_T Buffer;
  real_T Gain[3];
  real_T Constant;
  real_T Sum1[3];
  real_T TmpRTBAtQuESTInport1[3];
  real_T Constant_j[3];
  real_T FromFile_e[3];
  real_T FromFile2;
  real_T Sum_d;
  real_T Buffer_e;
  real_T ADC;
  real_T Constant_f[3];
  real_T Sum_l;
  real_T Buffer_c;
  real_T ADC_d;
  real_T Constant_k[3];
  real_T Sum_f;
  real_T Buffer_cr;
  real_T ADC_o;
  real_T Constant_l[3];
  real_T Sum_o;
  real_T Buffer_p;
  real_T ADC_b;
  real_T Constant_e[3];
  real_T Sum_h;
  real_T Buffer_o;
  real_T ADC_m;
  real_T Constant_ei[3];
  real_T Sum_m;
  real_T Buffer_p3;
  real_T ADC_l;
  real_T TmpRTBAtQuESTInport2[30];
  real_T TmpRTBAtScope10Inport1;
  real_T TmpRTBAtScope2Inport1[3];
  real_T TmpRTBAtScope3Inport1[3];
  real_T TmpRTBAtScope4Inport1;
  real_T TmpRTBAtScope5Inport1[3];
  real_T TmpRTBAtControlLawInport1[3];
  real_T Clock1;
  real_T TmpRTBAtScope6Inport1;
  real_T TmpRTBAtScope9Inport1[3];
  real_T TmpRTBAtToWorkspace10Inport1[3];
  real_T TmpRTBAtToWorkspace11Inport1[3];
  real_T TmpRTBAtToWorkspace12Inport1[3];
  real_T TmpRTBAtToWorkspace13Inport1[3];
  real_T TmpRTBAtToWorkspace16Inport1[3];
  real_T TmpRTBAtToWorkspace17Inport1[4];
  real_T TmpRTBAtToWorkspace18Inport1;
  real_T TmpRTBAtToWorkspace19Inport1[3];
  real_T TmpRTBAtToWorkspace2Inport1;
  real_T TmpRTBAtToWorkspace20Inport1[3];
  real_T TmpRTBAtToWorkspace4Inport1[3];
  real_T TmpRTBAtToWorkspace8Inport1[3];
  real_T Gain_k[3];
  real_T TmpRTBAtProductInport2[3];
  real_T Sum_n[3];
  real_T TmpRTBAtToWorkspace9Inport1[3];
  real_T VectorfromCoMtoCoP_inBodyframeyettobefinalized2[3];
  real_T Sum_i[3];
  real_T Sum_lf[3];
  real_T Sum_og[3];
  real_T TmpRTBAtw_real1Inport1[3];
  real_T TmpRTBAtw_real2Inport1[3];
  real_T TmpRTBAtw_real3Inport1[3];
  real_T TmpRTBAtw_real4Inport1[3];
  real_T Gain2[3];
  real_T Clock;
  real_T TmpRTBAtToWorkspace15Inport1;
  real_T Constant_l4[3];
  real_T Gain_f;
  real_T Constant_n[3];
  real_T Gain_p;
  real_T Constant_jb[3];
  real_T Gain_d;
  real_T Constant_m[3];
  real_T Gain_l;
  real_T Constant_a[3];
  real_T Gain_b;
  real_T Constant_f2[3];
  real_T Gain_m;
  real_T TmpRTBAtScope11Inport1[6];
  real_T Gain1[6];
  real_T TmpRTBAtScope12Inport1[6];
  real_T AddingSolarPower;
  real_T IntegerDelay;
  real_T PowerDistributionLosses;
  real_T Magnetometer;
  real_T TmpRTBAtAddingPowerConsumedInport3;
  real_T Uplink;
  real_T Beaconandamplifier;
  real_T OBC;
  real_T SunSensor;
  real_T Clock2;
  real_T AddingPowerConsumed;
  real_T AddingSolarPower1;
  real_T Gain2_c;
  real_T TmpRTBAtScope13Inport1;
  real_T TmpRTBAtScope14Inport1;
  real_T Clock_k;
  real_T IntegerDelay3;
  real_T IntegerDelay2;
  real_T IntegerDelay1;
  real_T IntegerDelay4;
  real_T TmpRTBAtScope15Inport1;
  real_T TmpRTBAtScope16Inport1;
  real_T TmpRTBAtScope17Inport1;
  real_T TmpRTBAtScope18Inport1;
  real_T TmpRTBAtScope19Inport1;
  real_T TmpRTBAtScope20Inport1;
  real_T VoltageofMagnetorquer;
  real_T Integrator_i;
  real_T xN[7];
  real_T IntegerDelay1_k[3];
  real_T IntegerDelay_n[4];
  real_T IntegerDelay_f;
  real_T Product[3];
  real_T w_l[3];
  real_T w[3];
  real_T y;
  real_T DCM[9];
  real_T v_B[3];
  real_T m_SUN[30];
  real_T values[6];
  real_T FromFile_f[3];
  real_T FromFile2_g[6];
  real_T FromFile3[3];
  real_T v_O[3];
  real_T v_O_k[3];
  real_T q_BO_est[4];
  real_T light_est;
  real_T v_Sun1[3];
  real_T r_ECEF[3];
  real_T Latitutde;
  real_T Longitude;
  real_T Altitude;
  real_T Batt_cap;
  real_T VBat;
  real_T Flag_charge;
  real_T frac_Batt_cap;
  real_T Flag_discharge;
  real_T current;
  real_T pow_drawn;
  real_T Downlink_power;
  real_T flag_downlink;
  real_T flag_france;
  real_T flag_india;
  real_T v_B_b[3];
  real_T solar_drag[3];
  real_T tau[3];
  real_T v_B_d[3];
  real_T u_aero[3];
  real_T euler[3];
  real_T q_BO[4];
  real_T w_BOB[3];
  real_T modw;
  real_T w_BIB[3];
  real_T xdot[7];
  real_T Fcn;
  real_T IntegerDelay_l[3];
  real_T UnitDelay1[3];
  real_T UnitDelay1_l;
  real_T TmpRTBAtgatepulseInport4;
  real_T UnitDelay;
  real_T TmpRTBAteuInport1[3];
  real_T TmpRTBAtmInport1[3];
  real_T TorquerCurrentSaturation[3];
  real_T B[3];
  real_T dB[3];
  real_T N;
  real_T P[3];
  real_T t_now;
  real_T ieu[3];
  real_T eu[3];
  real_T m[3];
  real_T m_N[3];
  real_T m_D[3];
} BlockIO;

typedef struct {
  real_T IntegerDelay_X;
  real_T IntegerDelay3_X;
  real_T IntegerDelay2_X;
  real_T IntegerDelay1_X;
  real_T IntegerDelay4_X;
  real_T IntegerDelay1_X_d[3];
  real_T IntegerDelay_X_l[4];
  real_T IntegerDelay_X_e[300];
  real_T IntegerDelay_X_i[3];
  real_T UnitDelay1_DSTATE[3];
  real_T UnitDelay1_DSTATE_c;
  real_T UnitDelay_DSTATE;
  real_T NextOutput;
  real_T NextOutput_f;
  real_T NextOutput_h;
  real_T NextOutput_a;
  real_T NextOutput_g;
  real_T NextOutput_o;
  real_T NextOutput_gv;
  real_T TmpRTBAtProductInport2_Buffer0[3];
  real_T TmpRTBAtAddingPowerConsumedInport3_Buffer0;
  struct {
    void *PrevTimePtr;
  } FromFile_PWORK;

  struct {
    void *LoggedData;
  } Scope1_PWORK;

  struct {
    void *PrevTimePtr;
  } FromFile1_PWORK;

  struct {
    void *PrevTimePtr;
  } FromFile_PWORK_n;

  struct {
    void *PrevTimePtr;
  } FromFile2_PWORK;

  struct {
    void *LoggedData;
  } Scope10_PWORK;

  struct {
    void *LoggedData;
  } Scope2_PWORK;

  struct {
    void *LoggedData;
  } Scope3_PWORK;

  struct {
    void *LoggedData;
  } Scope4_PWORK;

  struct {
    void *LoggedData;
  } Scope5_PWORK;

  struct {
    void *LoggedData;
  } Scope6_PWORK;

  struct {
    void *LoggedData;
  } Scope7_PWORK;

  struct {
    void *LoggedData;
  } Scope8_PWORK;

  struct {
    void *LoggedData;
  } Scope9_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace10_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace11_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace12_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace13_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace14_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace16_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace17_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace18_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace19_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace20_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace7_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace9_PWORK;

  struct {
    void *LoggedData;
  } w_real1_PWORK;

  struct {
    void *LoggedData;
  } w_real2_PWORK;

  struct {
    void *LoggedData;
  } w_real3_PWORK;

  struct {
    void *LoggedData;
  } w_real4_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace15_PWORK;

  struct {
    void *LoggedData;
  } Scope11_PWORK;

  struct {
    void *LoggedData;
  } Scope12_PWORK;

  struct {
    void *LoggedData;
  } Scope13_PWORK;

  struct {
    void *LoggedData;
  } Scope14_PWORK;

  struct {
    void *LoggedData;
  } Scope15_PWORK;

  struct {
    void *LoggedData;
  } Scope16_PWORK;

  struct {
    void *LoggedData;
  } Scope17_PWORK;

  struct {
    void *LoggedData;
  } Scope18_PWORK;

  struct {
    void *LoggedData;
  } Scope19_PWORK;

  struct {
    void *LoggedData;
  } Scope20_PWORK;

  struct {
    void *FilePtr;
    void *LogFilePtr;
  } ToFile_PWORK;

  struct {
    void *FilePtr;
    void *LogFilePtr;
  } ToFile1_PWORK;

  struct {
    void *FilePtr;
    void *LogFilePtr;
  } ToFile2_PWORK;

  struct {
    void *FilePtr;
    void *LogFilePtr;
  } ToFile3_PWORK;

  struct {
    void *FilePtr;
    void *LogFilePtr;
  } ToFile4_PWORK;

  struct {
    void *LoggedData;
  } Scope_PWORK;

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;

  struct {
    void *LoggedData;
  } Scope2_PWORK_b;

  struct {
    void *LoggedData;
  } Scope_PWORK_d;

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;

  struct {
    void *LoggedData;
  } Scope1_PWORK_j;

  struct {
    void *LoggedData;
  } Scope2_PWORK_c;

  struct {
    void *LoggedData;
  } Scope3_PWORK_i;

  struct {
    void *LoggedData;
  } Scope6_PWORK_e;

  struct {
    void *LoggedData;
  } Scope_PWORK_o;

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;

  struct {
    void *LoggedData;
  } Scope2_PWORK_g;

  struct {
    void *PrevTimePtr;
  } FromFile_PWORK_l;

  struct {
    void *PrevTimePtr;
  } FromFile2_PWORK_l;

  struct {
    void *PrevTimePtr;
  } FromFile3_PWORK;

  struct {
    void *LoggedData;
  } Scope_PWORK_f;

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;

  struct {
    void *LoggedData;
  } Scope1_PWORK_b;

  uint32_T RandSeed;
  uint32_T RandSeed_b;
  uint32_T RandSeed_e;
  uint32_T RandSeed_g;
  uint32_T RandSeed_br;
  uint32_T RandSeed_ef;
  uint32_T RandSeed_brc;
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile2_IWORK;

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile3_IWORK;

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile4_IWORK;

  uint8_T is_active_c7_adcs_v15_integral_Power_nom;
  uint8_T is_active_c27_adcs_v15_integral_Power_nom;
  uint8_T is_active_c6_adcs_v15_integral_Power_nom;
  uint8_T is_active_c1_adcs_v15_integral_Power_nom;
  uint8_T is_active_c4_adcs_v15_integral_Power_nom;
  uint8_T is_active_c22_adcs_v15_integral_Power_nom;
  uint8_T is_active_c12_adcs_v15_integral_Power_nom;
  uint8_T is_active_c25_adcs_v15_integral_Power_nom;
  uint8_T is_active_c11_adcs_v15_integral_Power_nom;
  uint8_T is_active_c30_adcs_v15_integral_Power_nom;
  uint8_T is_active_c28_adcs_v15_integral_Power_nom;
  uint8_T is_active_c26_adcs_v15_integral_Power_nom;
  uint8_T is_active_c31_adcs_v15_integral_Power_nom;
  uint8_T is_active_c19_adcs_v15_integral_Power_nom;
  uint8_T is_active_c5_adcs_v15_integral_Power_nom;
  uint8_T is_active_c8_adcs_v15_integral_Power_nom;
  uint8_T is_active_c9_adcs_v15_integral_Power_nom;
  uint8_T is_active_c20_adcs_v15_integral_Power_nom;
  uint8_T is_active_c16_adcs_v15_integral_Power_nom;
  uint8_T is_active_c29_adcs_v15_integral_Power_nom;
  uint8_T is_active_c2_adcs_v15_integral_Power_nom;
  uint8_T is_active_c10_adcs_v15_integral_Power_nom;
  uint8_T is_active_c24_adcs_v15_integral_Power_nom;
  uint8_T is_active_c13_adcs_v15_integral_Power_nom;
  uint8_T is_active_c23_adcs_v15_integral_Power_nom;
  boolean_T isStable;
  boolean_T doneDoubleBufferReInit;
  boolean_T isStable_c;
  boolean_T doneDoubleBufferReInit_o;
  boolean_T isStable_h;
  boolean_T doneDoubleBufferReInit_l;
  boolean_T isStable_m;
  boolean_T doneDoubleBufferReInit_n;
  boolean_T isStable_l;
  boolean_T doneDoubleBufferReInit_g;
  boolean_T isStable_cf;
  boolean_T doneDoubleBufferReInit_b;
  boolean_T isStable_e;
  boolean_T doneDoubleBufferReInit_m;
  boolean_T isStable_k;
  boolean_T doneDoubleBufferReInit_a;
  boolean_T isStable_ed;
  boolean_T doneDoubleBufferReInit_e;
  boolean_T isStable_ei;
  boolean_T doneDoubleBufferReInit_h;
  boolean_T isStable_hp;
  boolean_T doneDoubleBufferReInit_p;
  boolean_T isStable_d;
  boolean_T doneDoubleBufferReInit_c;
  boolean_T isStable_b;
  boolean_T doneDoubleBufferReInit_hv;
  boolean_T isStable_bn;
  boolean_T doneDoubleBufferReInit_g0;
  boolean_T isStable_hd;
  boolean_T doneDoubleBufferReInit_j;
  boolean_T isStable_em;
  boolean_T doneDoubleBufferReInit_d;
  boolean_T isStable_lx;
  boolean_T doneDoubleBufferReInit_jh;
  boolean_T isStable_p;
  boolean_T doneDoubleBufferReInit_ei;
  boolean_T isStable_dy;
  boolean_T doneDoubleBufferReInit_ab;
  boolean_T isStable_g;
  boolean_T doneDoubleBufferReInit_gf;
  boolean_T isStable_ej;
  boolean_T doneDoubleBufferReInit_dm;
  boolean_T isStable_o;
  boolean_T doneDoubleBufferReInit_jf;
  boolean_T isStable_mh;
  boolean_T doneDoubleBufferReInit_hm;
  boolean_T isStable_kn;
  boolean_T doneDoubleBufferReInit_cg;
  boolean_T isStable_hj;
  boolean_T doneDoubleBufferReInit_hk;
} D_Work;

typedef struct {
  real_T Integrator_CSTATE[7];
  real_T Integrator_CSTATE_d;
} ContinuousStates;

typedef struct {
  real_T Integrator_CSTATE[7];
  real_T Integrator_CSTATE_d;
} StateDerivatives;

typedef struct {
  boolean_T Integrator_CSTATE[7];
  boolean_T Integrator_CSTATE_d;
} StateDisabled;

struct Parameters_ {
  real_T Integrator_IC[7];
  real_T RandomNumber_Mean;
  real_T RandomNumber_StdDev;
  real_T RandomNumber_Seed;
  real_T MatrixGain_Gain;
  real_T Constant_Value;
  real_T Gain_Gain;
  real_T Constant_Value_g;
  real_T Constant_Value_e[3];
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T Gain_Gain_l;
  real_T RandomNumber_Mean_o;
  real_T RandomNumber_StdDev_j;
  real_T RandomNumber_Seed_f;
  real_T MatrixGain_Gain_g;
  real_T Constant_Value_e5;
  real_T ADC_Interval;
  real_T Constant_Value_p[3];
  real_T Saturation_UpperSat_m;
  real_T Saturation_LowerSat_m;
  real_T Gain_Gain_p;
  real_T RandomNumber_Mean_j;
  real_T RandomNumber_StdDev_o;
  real_T RandomNumber_Seed_g;
  real_T MatrixGain_Gain_i;
  real_T Constant_Value_l;
  real_T ADC_Interval_c;
  real_T Constant_Value_m[3];
  real_T Saturation_UpperSat_mv;
  real_T Saturation_LowerSat_a;
  real_T Gain_Gain_i;
  real_T RandomNumber_Mean_jb;
  real_T RandomNumber_StdDev_jg;
  real_T RandomNumber_Seed_c;
  real_T MatrixGain_Gain_n;
  real_T Constant_Value_n;
  real_T ADC_Interval_b;
  real_T Constant_Value_h[3];
  real_T Saturation_UpperSat_j;
  real_T Saturation_LowerSat_c;
  real_T Gain_Gain_n;
  real_T RandomNumber_Mean_k;
  real_T RandomNumber_StdDev_m;
  real_T RandomNumber_Seed_h;
  real_T MatrixGain_Gain_o;
  real_T Constant_Value_mz;
  real_T ADC_Interval_k;
  real_T Constant_Value_k[3];
  real_T Saturation_UpperSat_b;
  real_T Saturation_LowerSat_n;
  real_T Gain_Gain_g;
  real_T RandomNumber_Mean_n;
  real_T RandomNumber_StdDev_op;
  real_T RandomNumber_Seed_o;
  real_T MatrixGain_Gain_d;
  real_T Constant_Value_b;
  real_T ADC_Interval_j;
  real_T Constant_Value_i[3];
  real_T Saturation_UpperSat_l;
  real_T Saturation_LowerSat_o;
  real_T Gain_Gain_e;
  real_T RandomNumber_Mean_oj;
  real_T RandomNumber_StdDev_i;
  real_T RandomNumber_Seed_fb;
  real_T MatrixGain_Gain_l;
  real_T Constant_Value_i3;
  real_T ADC_Interval_jq;
  real_T Constant_Value_a[3];
  real_T Gain_Gain_f;
  real_T TmpRTBAtProductInport2_X0;
  real_T VectorfromCoMtoCoP_inBodyframeyettobefinalized2_Value[3];
  real_T PWM_Interval;
  real_T Gain2_Gain;
  real_T Constant_Value_gt[3];
  real_T Saturation_UpperSat_k;
  real_T Saturation_LowerSat_c1;
  real_T Gain1_Gain;
  real_T Gain_Gain_j;
  real_T Constant_Value_mt[3];
  real_T Saturation_UpperSat_ku;
  real_T Saturation_LowerSat_p;
  real_T Gain1_Gain_c;
  real_T Gain_Gain_es;
  real_T Constant_Value_kt[3];
  real_T Saturation_UpperSat_i;
  real_T Saturation_LowerSat_k;
  real_T Gain1_Gain_j;
  real_T Gain_Gain_lw;
  real_T Constant_Value_b2[3];
  real_T Saturation_UpperSat_c;
  real_T Saturation_LowerSat_aj;
  real_T Gain1_Gain_f;
  real_T Gain_Gain_pc;
  real_T Constant_Value_f[3];
  real_T Saturation_UpperSat_bn;
  real_T Saturation_LowerSat_p3;
  real_T Gain1_Gain_h;
  real_T Gain_Gain_in;
  real_T Constant_Value_h2[3];
  real_T Saturation_UpperSat_d;
  real_T Saturation_LowerSat_nl;
  real_T Gain1_Gain_hl;
  real_T Gain_Gain_f2;
  real_T Gain1_Gain_g;
  real_T IntegerDelay_InitialCondition;
  real_T PowerDistributionLosses_Value;
  real_T Magnetometer_Value;
  real_T TmpRTBAtAddingPowerConsumedInport3_X0;
  real_T Uplink_Value;
  real_T Beaconandamplifier_Value;
  real_T OBC_Value;
  real_T SunSensor_Value;
  real_T Gain2_Gain_p;
  real_T IntegerDelay3_InitialCondition;
  real_T IntegerDelay2_InitialCondition;
  real_T IntegerDelay1_InitialCondition;
  real_T IntegerDelay4_InitialCondition;
  real_T VoltageofMagnetorquer_Gain;
  real_T Integrator_IC_n;
  real_T SFunction_p2[9];
  real_T SFunction_p4;
  real_T IntegerDelay_InitialCondition_g;
  real_T UnitDelay1_X0[3];
  real_T MomentSaturation_UpperSat;
  real_T MomentSaturation_LowerSat;
  real_T Gain1_Gain_a;
  real_T PowerSaturation_UpperSat;
  real_T PowerSaturation_LowerSat;
  real_T UnitDelay1_X0_h;
  real_T UnitDelay_X0;
  real_T TorquerCurrentSaturation_UpperSat;
  real_T TorquerCurrentSaturation_LowerSat;
  real_T SFunction_p1;
  real_T SFunction_p1_i;
  real_T SFunction_p4_g;
  real_T SFunction_p2_n;
  real_T IntegerDelay1_InitialCondition_f[3];
  real_T IntegerDelay_InitialCondition_d;
  real_T IntegerDelay_InitialCondition_e;
};

extern Parameters rtP;
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern BlockIO rtB;
extern ContinuousStates rtX;
extern D_Work rtDWork;
extern SimStruct *const rtS;
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif
