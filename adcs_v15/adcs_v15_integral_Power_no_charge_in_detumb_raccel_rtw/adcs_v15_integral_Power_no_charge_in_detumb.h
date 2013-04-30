#ifndef RTW_HEADER_adcs_v15_integral_Power_no_charge_in_detumb_h_
#define RTW_HEADER_adcs_v15_integral_Power_no_charge_in_detumb_h_
#ifndef adcs_v15_integral_Power_no_charge_in_detumb_COMMON_INCLUDES_
# define adcs_v15_integral_Power_no_charge_in_detumb_COMMON_INCLUDES_
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

#include "adcs_v15_integral_Power_no_charge_in_detumb_types.h"
#define MODEL_NAME                     adcs_v15_integral_Power_no_charge_in_detumb
#define NSAMPLE_TIMES                  (5)
#define NINPUTS                        (0)
#define NOUTPUTS                       (0)
#define NBLOCKIO                       (184)
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
  real_T Constant_p[3];
  real_T FromFile_p[3];
  real_T FromFile2;
  real_T Sum_k;
  real_T Buffer_j;
  real_T ADC;
  real_T Constant_pv[3];
  real_T Sum_a;
  real_T Buffer_f;
  real_T ADC_p;
  real_T Constant_b[3];
  real_T Sum_h;
  real_T Buffer_o;
  real_T ADC_pc;
  real_T Constant_h[3];
  real_T Sum_o;
  real_T Buffer_g;
  real_T ADC_i;
  real_T Constant_l[3];
  real_T Sum_n;
  real_T Buffer_fu;
  real_T ADC_l;
  real_T Constant_e[3];
  real_T Sum_g;
  real_T Buffer_p;
  real_T ADC_f;
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
  real_T Gain_e[3];
  real_T TmpRTBAtProductInport2[3];
  real_T Sum_c[3];
  real_T TmpRTBAtToWorkspace9Inport1[3];
  real_T Constant_j;
  real_T VectorfromCoMtoCoP_inBodyframeyettobefinalized2[3];
  real_T Sum_f[3];
  real_T Sum_fb[3];
  real_T Sum_b[3];
  real_T TmpRTBAtw_real1Inport1[3];
  real_T TmpRTBAtw_real2Inport1[3];
  real_T TmpRTBAtw_real3Inport1[3];
  real_T TmpRTBAtw_real4Inport1[3];
  real_T Gain2[3];
  real_T Clock;
  real_T TmpRTBAtToWorkspace15Inport1;
  real_T Constant_jw[3];
  real_T Gain_c;
  real_T Constant_g[3];
  real_T Gain_m;
  real_T Constant_m[3];
  real_T Gain_d;
  real_T Constant_bd[3];
  real_T Gain_f;
  real_T Constant_a[3];
  real_T Gain_ck;
  real_T Constant_bw[3];
  real_T Gain_n;
  real_T TmpRTBAtScope11Inport1[6];
  real_T Gain1[6];
  real_T TmpRTBAtScope12Inport1[6];
  real_T AddingSolarPower;
  real_T TmpRTBAtProductInport2_l;
  real_T IntegerDelay;
  real_T PowerDistributionLosses;
  real_T Magnetometer;
  real_T TmpRTBAtAddingPowerConsumedInport3;
  real_T Uplink;
  real_T Beaconandamplifier;
  real_T OBC;
  real_T SunSensor;
  real_T TmpRTBAtProduct1Inport1;
  real_T Clock2;
  real_T AddingPowerConsumed;
  real_T AddingSolarPower1;
  real_T Gain2_i;
  real_T TmpRTBAtScope13Inport1;
  real_T TmpRTBAtScope14Inport1;
  real_T Clock_m;
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
  real_T Gain_ca;
  real_T VoltageofMagnetorquer;
  real_T Integrator_h;
  real_T xN[7];
  real_T IntegerDelay1_k[3];
  real_T IntegerDelay_l[4];
  real_T IntegerDelay_e;
  real_T Product[3];
  real_T w_l[3];
  real_T w[3];
  real_T y;
  real_T DCM[9];
  real_T v_B[3];
  real_T m_SUN[30];
  real_T values[6];
  real_T FromFile_k[3];
  real_T FromFile2_b[6];
  real_T FromFile3[3];
  real_T v_O[3];
  real_T v_O_b[3];
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
  real_T v_B_o[3];
  real_T solar_drag[3];
  real_T tau[3];
  real_T v_B_k[3];
  real_T u_aero[3];
  real_T euler[3];
  real_T q_BO[4];
  real_T w_BOB[3];
  real_T modw;
  real_T w_BIB[3];
  real_T xdot[7];
  real_T Fcn;
  real_T IntegerDelay_c[3];
  real_T UnitDelay1[3];
  real_T UnitDelay1_a;
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
  real_T IntegerDelay1_X_f[3];
  real_T IntegerDelay_X_k[4];
  real_T IntegerDelay_X_p[300];
  real_T IntegerDelay_X_o[3];
  real_T UnitDelay1_DSTATE[3];
  real_T UnitDelay1_DSTATE_m;
  real_T UnitDelay_DSTATE;
  real_T NextOutput;
  real_T NextOutput_i;
  real_T NextOutput_j;
  real_T NextOutput_b;
  real_T NextOutput_c;
  real_T NextOutput_h;
  real_T NextOutput_d;
  real_T TmpRTBAtProductInport2_Buffer0[3];
  real_T TmpRTBAtProductInport2_Buffer0_p;
  real_T TmpRTBAtAddingPowerConsumedInport3_Buffer0;
  real_T TmpRTBAtProduct1Inport1_Buffer0;
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
  } FromFile_PWORK_h;

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
  } ToWorkspace_PWORK;

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_c;

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_j;

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK_m;

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK_a;

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK_i;

  struct {
    void *LoggedData;
  } Scope_PWORK;

  struct {
    void *LoggedData;
  } Scope1_PWORK_b;

  struct {
    void *LoggedData;
  } Scope2_PWORK_d;

  struct {
    void *LoggedData;
  } Scope_PWORK_j;

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;

  struct {
    void *LoggedData;
  } Scope1_PWORK_n;

  struct {
    void *LoggedData;
  } Scope2_PWORK_a;

  struct {
    void *LoggedData;
  } Scope3_PWORK_a;

  struct {
    void *LoggedData;
  } Scope6_PWORK_f;

  struct {
    void *LoggedData;
  } Scope_PWORK_e;

  struct {
    void *LoggedData;
  } Scope1_PWORK_f;

  struct {
    void *LoggedData;
  } Scope2_PWORK_p;

  struct {
    void *PrevTimePtr;
  } FromFile_PWORK_o;

  struct {
    void *PrevTimePtr;
  } FromFile2_PWORK_b;

  struct {
    void *PrevTimePtr;
  } FromFile3_PWORK;

  struct {
    void *LoggedData;
  } Scope_PWORK_b;

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;

  uint32_T RandSeed;
  uint32_T RandSeed_k;
  uint32_T RandSeed_kh;
  uint32_T RandSeed_e;
  uint32_T RandSeed_b;
  uint32_T RandSeed_a;
  uint32_T RandSeed_m;
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

  uint8_T is_active_c7_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c27_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c6_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c1_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c4_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c22_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c12_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c25_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c11_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c30_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c28_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c26_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c31_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c19_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c5_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c8_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c9_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c20_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c16_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c29_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c2_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c10_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c24_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c13_adcs_v15_integral_Power_no_charge_in_detumb;
  uint8_T is_active_c23_adcs_v15_integral_Power_no_charge_in_detumb;
  boolean_T isStable;
  boolean_T doneDoubleBufferReInit;
  boolean_T isStable_d;
  boolean_T doneDoubleBufferReInit_n;
  boolean_T isStable_i;
  boolean_T doneDoubleBufferReInit_m;
  boolean_T isStable_o;
  boolean_T doneDoubleBufferReInit_l;
  boolean_T isStable_j;
  boolean_T doneDoubleBufferReInit_k;
  boolean_T isStable_m;
  boolean_T doneDoubleBufferReInit_h;
  boolean_T isStable_d5;
  boolean_T doneDoubleBufferReInit_i;
  boolean_T isStable_b;
  boolean_T doneDoubleBufferReInit_c;
  boolean_T isStable_p;
  boolean_T doneDoubleBufferReInit_b;
  boolean_T isStable_g;
  boolean_T doneDoubleBufferReInit_g;
  boolean_T isStable_iz;
  boolean_T doneDoubleBufferReInit_mj;
  boolean_T isStable_a;
  boolean_T doneDoubleBufferReInit_j;
  boolean_T isStable_jq;
  boolean_T doneDoubleBufferReInit_md;
  boolean_T isStable_k;
  boolean_T doneDoubleBufferReInit_h5;
  boolean_T isStable_mj;
  boolean_T doneDoubleBufferReInit_gk;
  boolean_T isStable_e;
  boolean_T doneDoubleBufferReInit_p;
  boolean_T isStable_b1;
  boolean_T doneDoubleBufferReInit_e;
  boolean_T isStable_bp;
  boolean_T doneDoubleBufferReInit_i4;
  boolean_T isStable_g3;
  boolean_T doneDoubleBufferReInit_a;
  boolean_T isStable_et;
  boolean_T doneDoubleBufferReInit_f;
  boolean_T isStable_f;
  boolean_T doneDoubleBufferReInit_jw;
  boolean_T isStable_h;
  boolean_T doneDoubleBufferReInit_k1;
  boolean_T isStable_n;
  boolean_T doneDoubleBufferReInit_km;
  boolean_T isStable_j4;
  boolean_T doneDoubleBufferReInit_bw;
  boolean_T isStable_el;
  boolean_T doneDoubleBufferReInit_l2;
} D_Work;

typedef struct {
  real_T Integrator_CSTATE[7];
  real_T Integrator_CSTATE_c;
} ContinuousStates;

typedef struct {
  real_T Integrator_CSTATE[7];
  real_T Integrator_CSTATE_c;
} StateDerivatives;

typedef struct {
  boolean_T Integrator_CSTATE[7];
  boolean_T Integrator_CSTATE_c;
} StateDisabled;

struct Parameters_ {
  real_T Integrator_IC[7];
  real_T RandomNumber_Mean;
  real_T RandomNumber_StdDev;
  real_T RandomNumber_Seed;
  real_T MatrixGain_Gain;
  real_T Constant_Value;
  real_T Gain_Gain;
  real_T Constant_Value_d;
  real_T Constant_Value_j[3];
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T Gain_Gain_o;
  real_T RandomNumber_Mean_e;
  real_T RandomNumber_StdDev_f;
  real_T RandomNumber_Seed_c;
  real_T MatrixGain_Gain_a;
  real_T Constant_Value_b;
  real_T ADC_Interval;
  real_T Constant_Value_g[3];
  real_T Saturation_UpperSat_l;
  real_T Saturation_LowerSat_k;
  real_T Gain_Gain_c;
  real_T RandomNumber_Mean_o;
  real_T RandomNumber_StdDev_p;
  real_T RandomNumber_Seed_o;
  real_T MatrixGain_Gain_o;
  real_T Constant_Value_js;
  real_T ADC_Interval_k;
  real_T Constant_Value_m[3];
  real_T Saturation_UpperSat_lo;
  real_T Saturation_LowerSat_i;
  real_T Gain_Gain_ce;
  real_T RandomNumber_Mean_om;
  real_T RandomNumber_StdDev_ff;
  real_T RandomNumber_Seed_h;
  real_T MatrixGain_Gain_p;
  real_T Constant_Value_bb;
  real_T ADC_Interval_a;
  real_T Constant_Value_h[3];
  real_T Saturation_UpperSat_g;
  real_T Saturation_LowerSat_d;
  real_T Gain_Gain_n;
  real_T RandomNumber_Mean_i;
  real_T RandomNumber_StdDev_j;
  real_T RandomNumber_Seed_n;
  real_T MatrixGain_Gain_m;
  real_T Constant_Value_n;
  real_T ADC_Interval_i;
  real_T Constant_Value_k[3];
  real_T Saturation_UpperSat_j;
  real_T Saturation_LowerSat_n;
  real_T Gain_Gain_d;
  real_T RandomNumber_Mean_c;
  real_T RandomNumber_StdDev_jw;
  real_T RandomNumber_Seed_p;
  real_T MatrixGain_Gain_ox;
  real_T Constant_Value_e;
  real_T ADC_Interval_ip;
  real_T Constant_Value_c[3];
  real_T Saturation_UpperSat_e;
  real_T Saturation_LowerSat_g;
  real_T Gain_Gain_a;
  real_T RandomNumber_Mean_g;
  real_T RandomNumber_StdDev_i;
  real_T RandomNumber_Seed_ne;
  real_T MatrixGain_Gain_ma;
  real_T Constant_Value_md;
  real_T ADC_Interval_ky;
  real_T Constant_Value_hq[3];
  real_T Gain_Gain_l;
  real_T TmpRTBAtProductInport2_X0;
  real_T Constant_Value_i;
  real_T VectorfromCoMtoCoP_inBodyframeyettobefinalized2_Value[3];
  real_T PWM_Interval;
  real_T Gain2_Gain;
  real_T Constant_Value_m0[3];
  real_T Saturation_UpperSat_p;
  real_T Saturation_LowerSat_f;
  real_T Gain1_Gain;
  real_T Gain_Gain_e;
  real_T Constant_Value_jc[3];
  real_T Saturation_UpperSat_jz;
  real_T Saturation_LowerSat_e;
  real_T Gain1_Gain_e;
  real_T Gain_Gain_m;
  real_T Constant_Value_l[3];
  real_T Saturation_UpperSat_m;
  real_T Saturation_LowerSat_m;
  real_T Gain1_Gain_b;
  real_T Gain_Gain_g;
  real_T Constant_Value_mv[3];
  real_T Saturation_UpperSat_g4;
  real_T Saturation_LowerSat_j;
  real_T Gain1_Gain_d;
  real_T Gain_Gain_j;
  real_T Constant_Value_gp[3];
  real_T Saturation_UpperSat_i;
  real_T Saturation_LowerSat_gk;
  real_T Gain1_Gain_be;
  real_T Gain_Gain_p;
  real_T Constant_Value_d1[3];
  real_T Saturation_UpperSat_a;
  real_T Saturation_LowerSat_mo;
  real_T Gain1_Gain_n;
  real_T Gain_Gain_h;
  real_T Gain1_Gain_p;
  real_T TmpRTBAtProductInport2_X0_p;
  real_T IntegerDelay_InitialCondition;
  real_T PowerDistributionLosses_Value;
  real_T Magnetometer_Value;
  real_T TmpRTBAtAddingPowerConsumedInport3_X0;
  real_T Uplink_Value;
  real_T Beaconandamplifier_Value;
  real_T OBC_Value;
  real_T SunSensor_Value;
  real_T TmpRTBAtProduct1Inport1_X0;
  real_T Gain2_Gain_a;
  real_T IntegerDelay3_InitialCondition;
  real_T IntegerDelay2_InitialCondition;
  real_T IntegerDelay1_InitialCondition;
  real_T IntegerDelay4_InitialCondition;
  real_T Gain_Gain_gr;
  real_T VoltageofMagnetorquer_Gain;
  real_T Integrator_IC_a;
  real_T SFunction_p2[9];
  real_T SFunction_p4;
  real_T IntegerDelay_InitialCondition_j;
  real_T UnitDelay1_X0[3];
  real_T UnitDelay1_X0_e;
  real_T UnitDelay_X0;
  real_T Switch_Threshold;
  real_T MomentSaturation_UpperSat;
  real_T MomentSaturation_LowerSat;
  real_T Gain1_Gain_g;
  real_T PowerSaturation_UpperSat;
  real_T PowerSaturation_LowerSat;
  real_T TorquerCurrentSaturation_UpperSat;
  real_T TorquerCurrentSaturation_LowerSat;
  real_T SFunction_p1;
  real_T SFunction_p1_c;
  real_T SFunction_p4_h;
  real_T SFunction_p2_l;
  real_T IntegerDelay1_InitialCondition_c[3];
  real_T IntegerDelay_InitialCondition_c;
  real_T IntegerDelay_InitialCondition_l;
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
