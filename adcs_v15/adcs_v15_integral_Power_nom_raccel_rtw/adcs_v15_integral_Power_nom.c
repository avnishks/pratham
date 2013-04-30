#include <math.h>
#include "adcs_v15_integral_Power_nom.h"
#include "adcs_v15_integral_Power_nom_private.h"
#include "adcs_v15_integral_Power_nom_dt.h"

const int_T gblNumToFiles = 5;
const int_T gblNumFrFiles = 7;
const int_T gblNumFrWksBlocks = 0;

#ifdef RSIM_WITH_SOLVER_MULTITASKING

const boolean_T gbl_raccel_isMultitasking = 1;

#else

const boolean_T gbl_raccel_isMultitasking = 0;

#endif

const boolean_T gbl_raccel_tid01eq = 1;
const int_T gbl_raccel_NumST = 5;
const char_T *gbl_raccel_Version = "7.4  (R2009b)  29-Jun-2009";
void raccel_setup_MMIStateLog(SimStruct* S)
{

#ifdef UseMMIDataLogging

  rt_FillStateSigInfoFromMMI(ssGetRTWLogInfo(S),&ssGetErrorStatus(S));

#endif

}

const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

FrFInfo adcs_v15_integral_Power_nom_gblFrFInfo[7];

#include "simstruc.h"
#include "fixedpoint.h"

#define adcs_v15_integral_Power_nom_Snum (6.0)
#define adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT (0.9)

#define adcs_v15_integral_Power_nom_check_time (10000.0)
#define adcs_v15_integral_Power_nom_tol_q4 (0.85)
#define adcs_v15_integral_Power_nom_tol_w (0.004)
#define adcs_v15_integral_Power_nom_tolw_n2d (0.01)

#define adcs_v15_integral_Power_nom_s_FRAME_SIZE (2.0)

BlockIO rtB;
ContinuousStates rtX;
D_Work rtDWork;
static SimStruct model_S;
SimStruct *const rtS = &model_S;
static real_T adcs_v15_integral_Power_nom_norm(const real_T eml_x[3]);
static real_T adcs_v15_integral_Power_nom_dot(const real_T eml_a[3], const
  real_T eml_b[3]);
static real_T adcs_v15_integral_Power_nom_norm_k(const real_T eml_x[3]);
static void adcs_v15_integral_Power_nom_c11_adcs_v15_integral_Power_nom(void);
static real_T adcs_v15_integral_Power_nom_dot_b(const real_T eml_a[3], const
  real_T eml_b[3]);
static real_T adcs_v15_integral_Power_nom_dot_l(const real_T eml_a[3], const
  real_T eml_b[3]);
static real_T adcs_v15_integral_Power_nom_dot_o(const real_T eml_a[3], const
  real_T eml_b[3]);
static real_T adcs_v15_integral_Power_nom_dot_g(const real_T eml_a[3], const
  real_T eml_b[3]);
static real_T adcs_v15_integral_Power_nom_norm_l(const real_T eml_x[3]);
static real_T adcs_v15_integral_Power_nom_norm_j(const real_T eml_x[3]);
static real_T adcs_v15_integral_Power_nom_isro_battery(real_T eml_x, real_T
  eml_current, real_T eml_internal_resistance);
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}

static real_T adcs_v15_integral_Power_nom_norm(const real_T eml_x[3])
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_xk;
  real_T eml_t;
  eml_y = 0.0;
  eml_scale = 0.0;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0) {
    eml_scale = muDoubleScalarAbs(eml_x[0]);
    eml_y = 1.0;
    eml_firstNonZero = false;
  }

  if (eml_x[1] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
      eml_firstNonZero = false;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  if (eml_x[2] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[2]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  return eml_scale * muDoubleScalarSqrt(eml_y);
}

static real_T adcs_v15_integral_Power_nom_dot(const real_T eml_a[3], const
  real_T eml_b[3])
{
  return (eml_a[0] * eml_b[0] + eml_a[1] * eml_b[1]) + eml_a[2] * eml_b[2];
}

static real_T adcs_v15_integral_Power_nom_norm_k(const real_T eml_x[3])
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_xk;
  real_T eml_t;
  eml_y = 0.0;
  eml_scale = 0.0;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0) {
    eml_scale = muDoubleScalarAbs(eml_x[0]);
    eml_y = 1.0;
    eml_firstNonZero = false;
  }

  if (eml_x[1] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
      eml_firstNonZero = false;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  if (eml_x[2] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[2]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  return eml_scale * muDoubleScalarSqrt(eml_y);
}

static void adcs_v15_integral_Power_nom_c11_adcs_v15_integral_Power_nom(void)
{
  real_T eml_m_SUN[30];
  real_T eml_values[6];
  real_T eml_ssvectors[9];
  real_T eml_ssvalues[3];
  real_T eml_b[3];
  real_T eml_r[3];
  real_T eml_nu;
  real_T eml_k_q_triad;
  int32_T eml_i;
  real_T eml_a;
  real_T eml_b_0;
  int32_T eml_b_r;
  real_T eml_maxval;
  int32_T eml_rtemp;
  int8_T eml_iidx[6];
  int8_T eml_idx[6];
  int32_T eml_b_i;
  int32_T eml_i_0;
  int32_T eml_p;
  int32_T eml_qEnd;
  int32_T eml_kEnd;
  boolean_T eml_b_p;
  real_T eml_b_1[3];
  real_T tmp[3];
  real_T eml_b_2[3];
  real_T tmp_0[3];
  real_T eml_m_SUN_0[3];
  real_T eml_m_SUN_1[3];
  real_T eml_m_SUN_2[3];
  int32_T eml_i_1;
  memcpy((void *)&eml_m_SUN[0], (void *)&rtB.TmpRTBAtQuESTInport2[0], 30U *
         sizeof(real_T));
  eml_b_0 = muDoubleScalarCos(rtP.SFunction_p4_g * 3.1415926535897931E+000 /
    180.0);
  for (eml_b_i = 0; eml_b_i < 6; eml_b_i++) {
    eml_m_SUN[3 + 5 * eml_b_i] = (real_T)(rtB.TmpRTBAtQuESTInport2[5 * eml_b_i +
      4] > eml_b_0);
  }

  for (eml_b_i = 0; eml_b_i < 6; eml_b_i++) {
    eml_values[eml_b_i] = eml_m_SUN[5 * eml_b_i + 4];
  }

  eml_b_0 = 0.0;
  for (eml_i = 1; eml_i <= (int32_T)adcs_v15_integral_Power_nom_Snum; eml_i++) {
    if (eml_values[eml_i - 1] < 2.5) {
      eml_b_0++;
    }
  }

  if (eml_b_0 == adcs_v15_integral_Power_nom_Snum) {
    eml_i = 0;
  } else {
    eml_i = 1;
  }

  rtB.light_est = (real_T)eml_i;
  if (eml_i == 1) {
    memset((void *)&eml_ssvectors[0], (int32_T)0.0, 9U * sizeof(real_T));
    eml_ssvalues[0] = 0.0;
    eml_ssvalues[1] = 0.0;
    eml_ssvalues[2] = 0.0;
    for (eml_b_i = 0; eml_b_i < 6; eml_b_i++) {
      eml_values[eml_b_i] = eml_m_SUN[5 * eml_b_i + 4];
      eml_idx[eml_b_i] = 1;
      eml_iidx[eml_b_i] = (int8_T)(1 + eml_b_i);
    }

    if ((eml_values[0] <= eml_values[1]) || rtIsNaN(eml_values[1])) {
      eml_b_p = true;
    } else {
      eml_b_p = false;
    }

    if (!eml_b_p) {
      eml_iidx[0] = 2;
      eml_iidx[1] = 1;
    }

    if ((eml_values[2] <= eml_values[3]) || rtIsNaN(eml_values[3])) {
      eml_b_p = true;
    } else {
      eml_b_p = false;
    }

    if (!eml_b_p) {
      eml_iidx[2] = 4;
      eml_iidx[3] = 3;
    }

    if ((eml_values[4] <= eml_values[5]) || rtIsNaN(eml_values[5])) {
      eml_b_p = true;
    } else {
      eml_b_p = false;
    }

    if (!eml_b_p) {
      eml_iidx[4] = 6;
      eml_iidx[5] = 5;
    }

    for (eml_b_i = 2; eml_b_i <= 6; eml_b_i = eml_i_0) {
      eml_i_0 = eml_b_i << 1;
      eml_i = 1;
      for (eml_i_1 = 1 + eml_b_i; eml_i_1 < 7; eml_i_1 = eml_qEnd + eml_b_i) {
        eml_p = eml_i;
        eml_b_r = eml_i_1;
        eml_qEnd = eml_i + eml_i_0;
        if (eml_qEnd > 7) {
          eml_qEnd = 7;
        }

        eml_rtemp = 1;
        eml_kEnd = eml_qEnd - eml_i;
        while (eml_rtemp <= eml_kEnd) {
          eml_b_0 = eml_values[eml_iidx[eml_b_r - 1] - 1];
          if ((eml_values[eml_iidx[eml_p - 1] - 1] <= eml_b_0) || rtIsNaN
              (eml_b_0)) {
            eml_b_p = true;
          } else {
            eml_b_p = false;
          }

          if (eml_b_p) {
            eml_idx[eml_rtemp - 1] = eml_iidx[eml_p - 1];
            eml_p++;
            if (eml_p == eml_i_1) {
              while (eml_b_r < eml_qEnd) {
                eml_rtemp++;
                eml_idx[eml_rtemp - 1] = eml_iidx[eml_b_r - 1];
                eml_b_r++;
              }
            }
          } else {
            eml_idx[eml_rtemp - 1] = eml_iidx[eml_b_r - 1];
            eml_b_r++;
            if (eml_b_r == eml_qEnd) {
              while (eml_p < eml_i_1) {
                eml_rtemp++;
                eml_idx[eml_rtemp - 1] = eml_iidx[eml_p - 1];
                eml_p++;
              }
            }
          }

          eml_rtemp++;
        }

        eml_p = eml_i - 1;
        for (eml_i = 1; eml_i <= eml_kEnd; eml_i++) {
          eml_iidx[(eml_p + eml_i) - 1] = eml_idx[eml_i - 1];
        }

        eml_i = eml_qEnd;
      }
    }

    for (eml_b_i = 0; eml_b_i < 6; eml_b_i++) {
      eml_idx[eml_b_i] = eml_iidx[eml_b_i];
    }

    eml_b_i = eml_idx[5] - 1;
    eml_ssvectors[0] = eml_m_SUN[5 * eml_b_i];
    eml_ssvectors[3] = eml_m_SUN[5 * eml_b_i + 1];
    eml_ssvectors[6] = eml_m_SUN[5 * eml_b_i + 2];
    eml_ssvalues[0] = eml_m_SUN[(eml_idx[5] - 1) * 5 + 4];
    eml_b_0 = 1.0;
    eml_i = (int32_T)eml_idx[4];
    while (1) {
      eml_b_i = eml_i - 1;
      eml_m_SUN_2[0] = eml_m_SUN[5 * eml_b_i] + eml_ssvectors[0];
      eml_m_SUN_2[1] = eml_m_SUN[5 * eml_b_i + 1] + eml_ssvectors[3];
      eml_m_SUN_2[2] = eml_m_SUN[5 * eml_b_i + 2] + eml_ssvectors[6];
      if (!(adcs_v15_integral_Power_nom_norm(eml_m_SUN_2) == 0.0)) {
        break;
      }

      eml_b_0++;
      eml_i = (int32_T)eml_idx[(int32_T)(adcs_v15_integral_Power_nom_Snum -
        eml_b_0) - 1];
    }

    eml_b_i = eml_i - 1;
    eml_ssvectors[1] = eml_m_SUN[5 * eml_b_i];
    eml_ssvectors[4] = eml_m_SUN[5 * eml_b_i + 1];
    eml_ssvectors[7] = eml_m_SUN[5 * eml_b_i + 2];
    eml_ssvalues[1] = eml_m_SUN[(eml_i - 1) * 5 + 4];
    eml_b_0++;
    eml_i = (int32_T)eml_idx[(int32_T)(adcs_v15_integral_Power_nom_Snum -
      eml_b_0) - 1];
    while (1) {
      eml_b_i = eml_i - 1;
      eml_i_1 = eml_i - 1;
      eml_m_SUN_0[0] = eml_m_SUN[5 * eml_b_i] + eml_ssvectors[0];
      eml_m_SUN_1[0] = eml_m_SUN[5 * eml_i_1] + eml_ssvectors[1];
      eml_m_SUN_0[1] = eml_m_SUN[5 * eml_b_i + 1] + eml_ssvectors[3];
      eml_m_SUN_1[1] = eml_m_SUN[5 * eml_i_1 + 1] + eml_ssvectors[4];
      eml_m_SUN_0[2] = eml_m_SUN[5 * eml_b_i + 2] + eml_ssvectors[6];
      eml_m_SUN_1[2] = eml_m_SUN[5 * eml_i_1 + 2] + eml_ssvectors[7];
      if (!((adcs_v15_integral_Power_nom_norm(eml_m_SUN_0) == 0.0) ||
            (adcs_v15_integral_Power_nom_norm(eml_m_SUN_1) == 0.0))) {
        break;
      }

      eml_b_0++;
      eml_i = (int32_T)eml_idx[(int32_T)(adcs_v15_integral_Power_nom_Snum -
        eml_b_0) - 1];
    }

    eml_b_i = eml_i - 1;
    eml_ssvectors[2] = eml_m_SUN[5 * eml_b_i];
    eml_ssvectors[5] = eml_m_SUN[5 * eml_b_i + 1];
    eml_ssvectors[8] = eml_m_SUN[5 * eml_b_i + 2];
    eml_ssvalues[2] = eml_m_SUN[(eml_i - 1) * 5 + 4];
    eml_i = 1;
    eml_i_1 = 2;
    eml_b_r = 3;
    eml_maxval = muDoubleScalarAbs(eml_ssvectors[0]);
    eml_b_0 = muDoubleScalarAbs(eml_ssvectors[1]);
    if (eml_b_0 > eml_maxval) {
      eml_maxval = eml_b_0;
      eml_i = 2;
      eml_i_1 = 1;
    }

    if (muDoubleScalarAbs(eml_ssvectors[2]) > eml_maxval) {
      eml_i = 3;
      eml_i_1 = 2;
      eml_b_r = 1;
    }

    eml_ssvectors[eml_i_1 - 1] /= eml_ssvectors[eml_i - 1];
    eml_ssvectors[eml_b_r - 1] /= eml_ssvectors[eml_i - 1];
    eml_ssvectors[eml_i_1 + 2] -= eml_ssvectors[eml_i_1 - 1] *
      eml_ssvectors[eml_i + 2];
    eml_ssvectors[eml_b_r + 2] -= eml_ssvectors[eml_b_r - 1] *
      eml_ssvectors[eml_i + 2];
    eml_ssvectors[eml_i_1 + 5] -= eml_ssvectors[eml_i_1 - 1] *
      eml_ssvectors[eml_i + 5];
    eml_ssvectors[eml_b_r + 5] -= eml_ssvectors[eml_b_r - 1] *
      eml_ssvectors[eml_i + 5];
    if (muDoubleScalarAbs(eml_ssvectors[eml_b_r + 2]) > muDoubleScalarAbs
        (eml_ssvectors[eml_i_1 + 2])) {
      eml_rtemp = eml_i_1;
      eml_i_1 = eml_b_r;
      eml_b_r = eml_rtemp;
    }

    eml_ssvectors[eml_b_r + 2] /= eml_ssvectors[eml_i_1 + 2];
    eml_ssvectors[eml_b_r + 5] -= eml_ssvectors[eml_b_r + 2] *
      eml_ssvectors[eml_i_1 + 5];
    rtB.v_Sun1[0] = eml_ssvalues[eml_i - 1];
    rtB.v_Sun1[1] = eml_ssvalues[eml_i_1 - 1] - eml_ssvectors[eml_i_1 - 1] *
      rtB.v_Sun1[0];
    rtB.v_Sun1[2] = (eml_ssvalues[eml_b_r - 1] - eml_ssvectors[eml_b_r - 1] *
                     rtB.v_Sun1[0]) - eml_ssvectors[eml_b_r + 2] * rtB.v_Sun1[1];
    rtB.v_Sun1[2] = rtB.v_Sun1[2] / eml_ssvectors[eml_b_r + 5];
    rtB.v_Sun1[0] = rtB.v_Sun1[0] - eml_ssvectors[eml_i + 5] * rtB.v_Sun1[2];
    rtB.v_Sun1[1] = rtB.v_Sun1[1] - eml_ssvectors[eml_i_1 + 5] * rtB.v_Sun1[2];
    rtB.v_Sun1[1] = rtB.v_Sun1[1] / eml_ssvectors[eml_i_1 + 2];
    rtB.v_Sun1[0] = rtB.v_Sun1[0] - eml_ssvectors[eml_i + 2] * rtB.v_Sun1[1];
    rtB.v_Sun1[0] = rtB.v_Sun1[0] / eml_ssvectors[eml_i - 1];
    eml_b_0 = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot(&rtB.v_Sun1[0],
      &rtB.v_Sun1[0]));
    rtB.v_Sun1[0] = rtB.v_Sun1[0] / eml_b_0;
    rtB.v_Sun1[1] = rtB.v_Sun1[1] / eml_b_0;
    rtB.v_Sun1[2] = rtB.v_Sun1[2] / eml_b_0;
    eml_b_0 = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot(&rtB.v_Sun1[0],
      &rtB.v_Sun1[0]));
    eml_ssvalues[0] = rtB.v_Sun1[0] / eml_b_0;
    eml_ssvalues[1] = rtB.v_Sun1[1] / eml_b_0;
    eml_ssvalues[2] = rtB.v_Sun1[2] / eml_b_0;
    eml_b[0] = rtB.TmpRTBAtQuESTInport1[1] * eml_ssvalues[2] -
      rtB.TmpRTBAtQuESTInport1[2] * eml_ssvalues[1];
    eml_b[1] = rtB.TmpRTBAtQuESTInport1[2] * eml_ssvalues[0] -
      rtB.TmpRTBAtQuESTInport1[0] * eml_ssvalues[2];
    eml_b[2] = rtB.TmpRTBAtQuESTInport1[0] * eml_ssvalues[1] -
      rtB.TmpRTBAtQuESTInport1[1] * eml_ssvalues[0];
    eml_b_0 = adcs_v15_integral_Power_nom_norm_k(eml_b);
    eml_b[0] /= eml_b_0;
    eml_b[1] /= eml_b_0;
    eml_b[2] /= eml_b_0;
    eml_r[0] = rtB.v_O_k[1] * rtB.v_O[2] - rtB.v_O_k[2] * rtB.v_O[1];
    eml_r[1] = rtB.v_O_k[2] * rtB.v_O[0] - rtB.v_O_k[0] * rtB.v_O[2];
    eml_r[2] = rtB.v_O_k[0] * rtB.v_O[1] - rtB.v_O_k[1] * rtB.v_O[0];
    eml_b_0 = adcs_v15_integral_Power_nom_norm_k(eml_r);
    eml_r[0] /= eml_b_0;
    eml_r[1] /= eml_b_0;
    eml_r[2] /= eml_b_0;
    eml_b_2[0] = eml_b[1] * eml_r[2] - eml_b[2] * eml_r[1];
    eml_b_2[1] = eml_b[2] * eml_r[0] - eml_b[0] * eml_r[2];
    eml_b_2[2] = eml_b[0] * eml_r[1] - eml_b[1] * eml_r[0];
    tmp_0[0] = (rtB.TmpRTBAtQuESTInport1[1] * rtB.v_O_k[2] -
                rtB.TmpRTBAtQuESTInport1[2] * rtB.v_O_k[1]) *
      adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT + (eml_ssvalues[1] *
      rtB.v_O[2] - eml_ssvalues[2] * rtB.v_O[1]) * 9.9999999999999978E-002;
    eml_b_1[0] = eml_b[0] + eml_r[0];
    tmp_0[1] = (rtB.TmpRTBAtQuESTInport1[2] * rtB.v_O_k[0] -
                rtB.TmpRTBAtQuESTInport1[0] * rtB.v_O_k[2]) *
      adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT + (eml_ssvalues[2] *
      rtB.v_O[0] - eml_ssvalues[0] * rtB.v_O[2]) * 9.9999999999999978E-002;
    eml_b_1[1] = eml_b[1] + eml_r[1];
    tmp_0[2] = (rtB.TmpRTBAtQuESTInport1[0] * rtB.v_O_k[1] -
                rtB.TmpRTBAtQuESTInport1[1] * rtB.v_O_k[0]) *
      adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT + (eml_ssvalues[0] *
      rtB.v_O[1] - eml_ssvalues[1] * rtB.v_O[0]) * 9.9999999999999978E-002;
    eml_b_1[2] = eml_b[2] + eml_r[2];
    eml_b_0 = (0.9 * adcs_v15_integral_Power_nom_dot(&rtB.TmpRTBAtQuESTInport1[0],
                &rtB.v_O_k[0]) + 9.9999999999999978E-002 *
               adcs_v15_integral_Power_nom_dot(eml_ssvalues, &rtB.v_O[0])) *
      (1.0 + adcs_v15_integral_Power_nom_dot(eml_b, eml_r)) +
      adcs_v15_integral_Power_nom_dot(eml_b_2, tmp_0);
    tmp[0] = (rtB.TmpRTBAtQuESTInport1[1] * rtB.v_O_k[2] -
              rtB.TmpRTBAtQuESTInport1[2] * rtB.v_O_k[1]) *
      adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT + (eml_ssvalues[1] *
      rtB.v_O[2] - eml_ssvalues[2] * rtB.v_O[1]) * 9.9999999999999978E-002;
    tmp[1] = (rtB.TmpRTBAtQuESTInport1[2] * rtB.v_O_k[0] -
              rtB.TmpRTBAtQuESTInport1[0] * rtB.v_O_k[2]) *
      adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT + (eml_ssvalues[2] *
      rtB.v_O[0] - eml_ssvalues[0] * rtB.v_O[2]) * 9.9999999999999978E-002;
    tmp[2] = (rtB.TmpRTBAtQuESTInport1[0] * rtB.v_O_k[1] -
              rtB.TmpRTBAtQuESTInport1[1] * rtB.v_O_k[0]) *
      adcs_v15_integral_Power_nom_s_MAGMETER_WEIGHT + (eml_ssvalues[0] *
      rtB.v_O[1] - eml_ssvalues[1] * rtB.v_O[0]) * 9.9999999999999978E-002;
    eml_nu = adcs_v15_integral_Power_nom_dot(eml_b_1, tmp);
    eml_maxval = muDoubleScalarSqrt(eml_b_0 * eml_b_0 + eml_nu * eml_nu);
    if (eml_b_0 > 0.0) {
      eml_k_q_triad = 1.0 / (muDoubleScalarSqrt((eml_maxval + eml_b_0) *
        eml_maxval * (1.0 + adcs_v15_integral_Power_nom_dot(eml_b, eml_r))) *
        2.0);
      eml_a = eml_maxval + eml_b_0;
      rtB.q_BO_est[0] = ((eml_b[1] * eml_r[2] - eml_b[2] * eml_r[1]) * eml_a +
                         (eml_b[0] + eml_r[0]) * eml_nu) * eml_k_q_triad;
      rtB.q_BO_est[1] = ((eml_b[2] * eml_r[0] - eml_b[0] * eml_r[2]) * eml_a +
                         (eml_b[1] + eml_r[1]) * eml_nu) * eml_k_q_triad;
      rtB.q_BO_est[2] = ((eml_b[0] * eml_r[1] - eml_b[1] * eml_r[0]) * eml_a +
                         (eml_b[2] + eml_r[2]) * eml_nu) * eml_k_q_triad;
      rtB.q_BO_est[3] = (eml_maxval + eml_b_0) * (1.0 +
        adcs_v15_integral_Power_nom_dot(eml_b, eml_r)) * eml_k_q_triad;
    } else {
      eml_k_q_triad = 1.0 / (muDoubleScalarSqrt((eml_maxval - eml_b_0) *
        eml_maxval * (1.0 + adcs_v15_integral_Power_nom_dot(eml_b, eml_r))) *
        2.0);
      eml_b_0 = eml_maxval - eml_b_0;
      rtB.q_BO_est[0] = ((eml_b[1] * eml_r[2] - eml_b[2] * eml_r[1]) * eml_nu +
                         (eml_b[0] + eml_r[0]) * eml_b_0) * eml_k_q_triad;
      rtB.q_BO_est[1] = ((eml_b[2] * eml_r[0] - eml_b[0] * eml_r[2]) * eml_nu +
                         (eml_b[1] + eml_r[1]) * eml_b_0) * eml_k_q_triad;
      rtB.q_BO_est[2] = ((eml_b[0] * eml_r[1] - eml_b[1] * eml_r[0]) * eml_nu +
                         (eml_b[2] + eml_r[2]) * eml_b_0) * eml_k_q_triad;
      rtB.q_BO_est[3] = (1.0 + adcs_v15_integral_Power_nom_dot(eml_b, eml_r)) *
        eml_nu * eml_k_q_triad;
    }

    eml_b_0 = muDoubleScalarSqrt(((rtB.q_BO_est[0] * rtB.q_BO_est[0] +
      rtB.q_BO_est[1] * rtB.q_BO_est[1]) + rtB.q_BO_est[2] * rtB.q_BO_est[2]) +
      rtB.q_BO_est[3] * rtB.q_BO_est[3]);
    rtB.q_BO_est[0] = rtB.q_BO_est[0] / eml_b_0;
    rtB.q_BO_est[1] = rtB.q_BO_est[1] / eml_b_0;
    rtB.q_BO_est[2] = rtB.q_BO_est[2] / eml_b_0;
    rtB.q_BO_est[3] = rtB.q_BO_est[3] / eml_b_0;
  } else {
    rtB.v_Sun1[0] = 1.0;
    rtB.v_Sun1[1] = 0.0;
    rtB.v_Sun1[2] = 0.0;
    rtB.q_BO_est[0] = 0.0;
    rtB.q_BO_est[1] = 0.0;
    rtB.q_BO_est[2] = 0.0;
    rtB.q_BO_est[3] = 1.0;
  }
}

void adcs_v15_integral_Power_nom_QuEST_Init(void)
{
  rtDWork.is_active_c11_adcs_v15_integral_Power_nom = 0U;
}

void adcs_v15_integral_Power_nom_QuEST(void)
{
  adcs_v15_integral_Power_nom_c11_adcs_v15_integral_Power_nom();
}

static real_T adcs_v15_integral_Power_nom_dot_b(const real_T eml_a[3], const
  real_T eml_b[3])
{
  return (eml_a[0] * eml_b[0] + eml_a[1] * eml_b[1]) + eml_a[2] * eml_b[2];
}

static real_T adcs_v15_integral_Power_nom_dot_l(const real_T eml_a[3], const
  real_T eml_b[3])
{
  return (eml_a[0] * eml_b[0] + eml_a[1] * eml_b[1]) + eml_a[2] * eml_b[2];
}

static real_T adcs_v15_integral_Power_nom_dot_o(const real_T eml_a[3], const
  real_T eml_b[3])
{
  return (eml_a[0] * eml_b[0] + eml_a[1] * eml_b[1]) + eml_a[2] * eml_b[2];
}

static real_T adcs_v15_integral_Power_nom_dot_g(const real_T eml_a[3], const
  real_T eml_b[3])
{
  return (eml_a[0] * eml_b[0] + eml_a[1] * eml_b[1]) + eml_a[2] * eml_b[2];
}

static real_T adcs_v15_integral_Power_nom_norm_l(const real_T eml_x[3])
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_xk;
  real_T eml_t;
  eml_y = 0.0;
  eml_scale = 0.0;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0) {
    eml_scale = muDoubleScalarAbs(eml_x[0]);
    eml_y = 1.0;
    eml_firstNonZero = false;
  }

  if (eml_x[1] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
      eml_firstNonZero = false;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  if (eml_x[2] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[2]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  return eml_scale * muDoubleScalarSqrt(eml_y);
}

static real_T adcs_v15_integral_Power_nom_norm_j(const real_T eml_x[3])
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_xk;
  real_T eml_t;
  eml_y = 0.0;
  eml_scale = 0.0;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0) {
    eml_scale = muDoubleScalarAbs(eml_x[0]);
    eml_y = 1.0;
    eml_firstNonZero = false;
  }

  if (eml_x[1] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
      eml_firstNonZero = false;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  if (eml_x[2] != 0.0) {
    eml_xk = muDoubleScalarAbs(eml_x[2]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  return eml_scale * muDoubleScalarSqrt(eml_y);
}

static real_T adcs_v15_integral_Power_nom_isro_battery(real_T eml_x, real_T
  eml_current, real_T eml_internal_resistance)
{
  if (eml_x >= 0.0) {
    return (((((((((((-1.9617E-030 * muDoubleScalarPower(eml_x, 10.0) +
                      2.0777E-026 * muDoubleScalarPower(eml_x, 9.0)) -
                     9.3448E-023 * muDoubleScalarPower(eml_x, 8.0)) +
                    2.3253E-019 * muDoubleScalarPower(eml_x, 7.0)) - 3.4941E-016
                   * muDoubleScalarPower(eml_x, 6.0)) + 3.2457E-013 *
                  muDoubleScalarPower(eml_x, 5.0)) - 1.8299E-010 *
                 muDoubleScalarPower(eml_x, 4.0)) + 5.871E-008 *
                muDoubleScalarPower(eml_x, 3.0)) - 9.0949E-006 *
               muDoubleScalarPower(eml_x, 2.0)) - 7.2522E-005 * eml_x) + 4.0607)
            + 0.17712) + eml_current * eml_internal_resistance;
  } else {
    return ((0.0 - eml_x) * 2.5000000000003909E-004 + 4.238) + eml_current *
      eml_internal_resistance;
  }
}

void MdlInitialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      rtX.Integrator_CSTATE[i] = rtP.Integrator_IC[i];
    }

    rtDWork.is_active_c7_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c29_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c5_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c4_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c22_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c25_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c12_adcs_v15_integral_Power_nom = 0U;
    adcs_v15_integral_Power_nom_QuEST_Init();
    rtDWork.IntegerDelay1_X_d[0] = rtP.IntegerDelay1_InitialCondition_f[0];
    rtDWork.IntegerDelay1_X_d[1] = rtP.IntegerDelay1_InitialCondition_f[1];
    rtDWork.IntegerDelay1_X_d[2] = rtP.IntegerDelay1_InitialCondition_f[2];
    rtDWork.IntegerDelay_X_l[0] = rtP.IntegerDelay_InitialCondition_d;
    rtDWork.IntegerDelay_X_l[1] = rtP.IntegerDelay_InitialCondition_d;
    rtDWork.IntegerDelay_X_l[2] = rtP.IntegerDelay_InitialCondition_d;
    rtDWork.IntegerDelay_X_l[3] = rtP.IntegerDelay_InitialCondition_d;
    rtDWork.is_active_c27_adcs_v15_integral_Power_nom = 0U;
    for (i = 0; i < 300; i++) {
      rtDWork.IntegerDelay_X_e[i] = rtP.IntegerDelay_InitialCondition_e;
    }

    rtDWork.is_active_c6_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c10_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c23_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c13_adcs_v15_integral_Power_nom = 0U;
    rtDWork.UnitDelay1_DSTATE_c = rtP.UnitDelay1_X0_h;
    rtDWork.UnitDelay_DSTATE = rtP.UnitDelay_X0;
    rtDWork.is_active_c24_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c1_adcs_v15_integral_Power_nom = 0U;
    rtDWork.IntegerDelay_X_i[0] = rtP.IntegerDelay_InitialCondition_g;
    rtDWork.UnitDelay1_DSTATE[0] = rtP.UnitDelay1_X0[0];
    rtDWork.TmpRTBAtProductInport2_Buffer0[0] = rtP.TmpRTBAtProductInport2_X0;
    rtDWork.IntegerDelay_X_i[1] = rtP.IntegerDelay_InitialCondition_g;
    rtDWork.UnitDelay1_DSTATE[1] = rtP.UnitDelay1_X0[1];
    rtDWork.TmpRTBAtProductInport2_Buffer0[1] = rtP.TmpRTBAtProductInport2_X0;
    rtDWork.IntegerDelay_X_i[2] = rtP.IntegerDelay_InitialCondition_g;
    rtDWork.UnitDelay1_DSTATE[2] = rtP.UnitDelay1_X0[2];
    rtDWork.TmpRTBAtProductInport2_Buffer0[2] = rtP.TmpRTBAtProductInport2_X0;
    rtDWork.is_active_c9_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c20_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c16_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c8_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c2_adcs_v15_integral_Power_nom = 0U;
    rtDWork.IntegerDelay_X = rtP.IntegerDelay_InitialCondition;
    rtDWork.TmpRTBAtAddingPowerConsumedInport3_Buffer0 =
      rtP.TmpRTBAtAddingPowerConsumedInport3_X0;
    rtDWork.is_active_c30_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c28_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c19_adcs_v15_integral_Power_nom = 0U;
    rtDWork.is_active_c31_adcs_v15_integral_Power_nom = 0U;
    rtDWork.IntegerDelay3_X = rtP.IntegerDelay3_InitialCondition;
    rtDWork.IntegerDelay2_X = rtP.IntegerDelay2_InitialCondition;
    rtDWork.IntegerDelay1_X = rtP.IntegerDelay1_InitialCondition;
    rtDWork.IntegerDelay4_X = rtP.IntegerDelay4_InitialCondition;
    rtDWork.is_active_c26_adcs_v15_integral_Power_nom = 0U;
    rtX.Integrator_CSTATE_d = rtP.Integrator_IC_n;
  }
}

void MdlStart(void)
{
  {
    uint32_T tseed;
    int32_T r;
    uint32_T t;
    real_T tmp;

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("SGP_120k.mat",7,
            &adcs_v15_integral_Power_nom_gblFrFInfo[0])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile_PWORK.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[0].tuDataMatrix;
    }

    if (rtIsNaN(rtP.RandomNumber_Seed) || rtIsInf(rtP.RandomNumber_Seed)) {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed = tseed;
    rtDWork.NextOutput = rt_NormalRand(&rtDWork.RandSeed) *
      rtP.RandomNumber_StdDev + rtP.RandomNumber_Mean;

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("Bi_120k.mat",4,
            &adcs_v15_integral_Power_nom_gblFrFInfo[1])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile1_PWORK.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[1].tuDataMatrix;
    }

    rtB.Constant_j[0] = rtP.Constant_Value_e[0];
    rtB.Constant_j[1] = rtP.Constant_Value_e[1];
    rtB.Constant_j[2] = rtP.Constant_Value_e[2];

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("Si_120k.mat",4,
            &adcs_v15_integral_Power_nom_gblFrFInfo[2])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile_PWORK_n.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[2].tuDataMatrix;
    }

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("light_120k.mat",2,
            &adcs_v15_integral_Power_nom_gblFrFInfo[3])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile2_PWORK.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[3].tuDataMatrix;
    }

    if (rtIsNaN(rtP.RandomNumber_Seed_f) || rtIsInf(rtP.RandomNumber_Seed_f)) {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed_f),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed_b = tseed;
    rtDWork.NextOutput_f = rt_NormalRand(&rtDWork.RandSeed_b) *
      rtP.RandomNumber_StdDev_j + rtP.RandomNumber_Mean_o;
    rtB.Constant_f[0] = rtP.Constant_Value_p[0];
    rtB.Constant_f[1] = rtP.Constant_Value_p[1];
    rtB.Constant_f[2] = rtP.Constant_Value_p[2];
    if (rtIsNaN(rtP.RandomNumber_Seed_g) || rtIsInf(rtP.RandomNumber_Seed_g)) {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed_g),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed_e = tseed;
    rtDWork.NextOutput_h = rt_NormalRand(&rtDWork.RandSeed_e) *
      rtP.RandomNumber_StdDev_o + rtP.RandomNumber_Mean_j;
    rtB.Constant_k[0] = rtP.Constant_Value_m[0];
    rtB.Constant_k[1] = rtP.Constant_Value_m[1];
    rtB.Constant_k[2] = rtP.Constant_Value_m[2];
    if (rtIsNaN(rtP.RandomNumber_Seed_c) || rtIsInf(rtP.RandomNumber_Seed_c)) {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed_c),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed_g = tseed;
    rtDWork.NextOutput_a = rt_NormalRand(&rtDWork.RandSeed_g) *
      rtP.RandomNumber_StdDev_jg + rtP.RandomNumber_Mean_jb;
    rtB.Constant_l[0] = rtP.Constant_Value_h[0];
    rtB.Constant_l[1] = rtP.Constant_Value_h[1];
    rtB.Constant_l[2] = rtP.Constant_Value_h[2];
    if (rtIsNaN(rtP.RandomNumber_Seed_h) || rtIsInf(rtP.RandomNumber_Seed_h)) {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed_h),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed_br = tseed;
    rtDWork.NextOutput_g = rt_NormalRand(&rtDWork.RandSeed_br) *
      rtP.RandomNumber_StdDev_m + rtP.RandomNumber_Mean_k;
    rtB.Constant_e[0] = rtP.Constant_Value_k[0];
    rtB.Constant_e[1] = rtP.Constant_Value_k[1];
    rtB.Constant_e[2] = rtP.Constant_Value_k[2];
    if (rtIsNaN(rtP.RandomNumber_Seed_o) || rtIsInf(rtP.RandomNumber_Seed_o)) {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed_o),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed_ef = tseed;
    rtDWork.NextOutput_o = rt_NormalRand(&rtDWork.RandSeed_ef) *
      rtP.RandomNumber_StdDev_op + rtP.RandomNumber_Mean_n;
    rtB.Constant_ei[0] = rtP.Constant_Value_i[0];
    rtB.Constant_ei[1] = rtP.Constant_Value_i[1];
    rtB.Constant_ei[2] = rtP.Constant_Value_i[2];
    if (rtIsNaN(rtP.RandomNumber_Seed_fb) || rtIsInf(rtP.RandomNumber_Seed_fb))
    {
      tmp = 0.0;
    } else {
      tmp = muDoubleScalarRem(muDoubleScalarFloor(rtP.RandomNumber_Seed_fb),
        4.294967296E+009);
    }

    tseed = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    rtDWork.RandSeed_brc = tseed;
    rtDWork.NextOutput_gv = rt_NormalRand(&rtDWork.RandSeed_brc) *
      rtP.RandomNumber_StdDev_i + rtP.RandomNumber_Mean_oj;

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("Si_120k.mat",4,
            &adcs_v15_integral_Power_nom_gblFrFInfo[4])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile_PWORK_l.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[4].tuDataMatrix;
    }

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("SGP_est_120k.mat",7,
            &adcs_v15_integral_Power_nom_gblFrFInfo[5])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile2_PWORK_l.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[5].tuDataMatrix;
    }

    {
      const char *result;
      if ((result=rt_ReadFromfileMatFile("Bi8_est_120k.mat",4,
            &adcs_v15_integral_Power_nom_gblFrFInfo[6])) != (NULL)) {
        ssSetErrorStatus(rtS, result);
        return;
      }

      rtDWork.FromFile3_PWORK.PrevTimePtr = (void *)
        adcs_v15_integral_Power_nom_gblFrFInfo[6].tuDataMatrix;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "w_BOB_real",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace1_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace10_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_sun_est",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace10_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace11_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_sun_real",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace11_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace12_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_Bb_real",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace12_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace13_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_Bb_m",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace13_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace14_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "w_BIB_real",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace14_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace16_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_Sun_o_calc",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace16_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 4 };

      rtDWork.ToWorkspace17_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "q_BO_est",
        SS_DOUBLE,
        0,
        0,
        0,
        4,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace17_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 1 };

      rtDWork.ToWorkspace18_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "light",
        SS_DOUBLE,
        0,
        0,
        0,
        1,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace18_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace19_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "w_BOB_est",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace19_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 1 };

      rtDWork.ToWorkspace2_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "N_save",
        SS_DOUBLE,
        0,
        0,
        0,
        1,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace2_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace20_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_Sun_i",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace20_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace3_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "eu_ctrl",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace3_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace4_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "current",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace4_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace5_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "euler",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace5_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 4 };

      rtDWork.ToWorkspace6_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "q_BO_real",
        SS_DOUBLE,
        0,
        0,
        0,
        4,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace6_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace7_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "m_desired",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace7_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace8_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "v_Bo",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace8_PWORK.LoggedData == (NULL))
        return;
    }

    rtB.TmpRTBAtProductInport2[0] = rtP.TmpRTBAtProductInport2_X0;
    rtB.TmpRTBAtProductInport2[1] = rtP.TmpRTBAtProductInport2_X0;
    rtB.TmpRTBAtProductInport2[2] = rtP.TmpRTBAtProductInport2_X0;

    {
      int_T dimensions[1] = { 3 };

      rtDWork.ToWorkspace9_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "u_control",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace9_PWORK.LoggedData == (NULL))
        return;
    }

    {
      int_T dimensions[1] = { 1 };

      rtDWork.ToWorkspace15_PWORK.LoggedData = rt_CreateLogVar(
        ssGetRTWLogInfo(rtS),
        ssGetTFinal(rtS),
        0.0,
        (&ssGetErrorStatus(rtS)),
        "t",
        SS_DOUBLE,
        0,
        0,
        0,
        1,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        0,
        1,
        6.0,
        1);
      if (rtDWork.ToWorkspace15_PWORK.LoggedData == (NULL))
        return;
    }

    rtB.TmpRTBAtAddingPowerConsumedInport3 =
      rtP.TmpRTBAtAddingPowerConsumedInport3_X0;

    {
      const char *fileName = "Latitude.mat";
      FILE *fp;
      rt_RAccelAddToFileSuffix(&fileName);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error creating .mat file Latitude.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing mat file header to file Latitude.mat");
        return;
      }

      rtDWork.ToFile_IWORK.Count = 0;
      rtDWork.ToFile_IWORK.Decimation = -1;
      rtDWork.ToFile_PWORK.FilePtr = fp;
    }

    {
      const char *fileName = "Longitude.mat";
      FILE *fp;
      rt_RAccelAddToFileSuffix(&fileName);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error creating .mat file Longitude.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing mat file header to file Longitude.mat");
        return;
      }

      rtDWork.ToFile1_IWORK.Count = 0;
      rtDWork.ToFile1_IWORK.Decimation = -1;
      rtDWork.ToFile1_PWORK.FilePtr = fp;
    }

    {
      const char *fileName = "flag_downlink.mat";
      FILE *fp;
      rt_RAccelAddToFileSuffix(&fileName);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error creating .mat file flag_downlink.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing mat file header to file flag_downlink.mat");
        return;
      }

      rtDWork.ToFile2_IWORK.Count = 0;
      rtDWork.ToFile2_IWORK.Decimation = -1;
      rtDWork.ToFile2_PWORK.FilePtr = fp;
    }

    {
      const char *fileName = "flag_france.mat";
      FILE *fp;
      rt_RAccelAddToFileSuffix(&fileName);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error creating .mat file flag_france.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing mat file header to file flag_france.mat");
        return;
      }

      rtDWork.ToFile3_IWORK.Count = 0;
      rtDWork.ToFile3_IWORK.Decimation = -1;
      rtDWork.ToFile3_PWORK.FilePtr = fp;
    }

    {
      const char *fileName = "flag_india.mat";
      FILE *fp;
      rt_RAccelAddToFileSuffix(&fileName);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error creating .mat file flag_india.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing mat file header to file flag_india.mat");
        return;
      }

      rtDWork.ToFile4_IWORK.Count = 0;
      rtDWork.ToFile4_IWORK.Decimation = -1;
      rtDWork.ToFile4_PWORK.FilePtr = fp;
    }
  }

  MdlInitialize();
}

void MdlOutputs(int_T tid)
{
  real_T rtb_Product[3];
  real_T rtb_jxi;
  real_T rtb_Abs[3];

  {
    real_T eml_x;
    real_T eml_r[3];
    real_T eml_v[3];
    real_T eml_oy[3];
    real_T eml_norm;
    real_T eml_B;
    real_T eml_r_B[3];
    real_T eml_b[3];
    real_T eml_b_0[18];
    real_T eml_b_1[3];
    boolean_T eml_b_2;
    real_T rtb_Gain;
    real_T rtb_Gain_d;
    real_T rtb_Gain_e;
    real_T rtb_Gain_a;
    real_T rtb_Gain_p;
    real_T rtb_Gain_g;
    int32_T i;
    real_T eml_b_3[3];
    real_T eml_q_BI[16];
    int8_T tmp[6];
    real_T eml_v_0[9];
    real_T eml_e[9];
    real_T tmp_0[9];
    int32_T tmp_1;
    real_T tmp_2[16];
    real_T tmp_3[4];
    real_T eml_q_idx;
    real_T eml_q_idx_0;
    real_T eml_TIO_idx;
    real_T eml_TIO_idx_0;
    real_T rtb_PowerSaturation_idx;
    real_T rtb_PowerSaturation_idx_0;
    real_T rtb_PowerSaturation_idx_1;
    static int8_T tmp_4[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static real_T tmp_5[9] = { 4.5140285315801179E-004, -1.8853220227652746E-006,
      -1.5883539876530823E-006, -1.8853220227652746E-006,
      4.5544946416101032E-004, -6.3802623834070427E-006,
      -1.5883539876530823E-006, -6.3802623834070427E-006,
      4.2090941916178554E-004 };

    static real_T tmp_6[9] = { 5.8799513739451559E+000, 2.4655987494540597E-002,
      2.2562469379899763E-002, 2.4655987494540597E-002, 5.8288691151065288E+000,
      8.8448666373664678E-002, 2.2562469379899763E-002, 8.8448666373664692E-002,
      6.3071638385728717E+000 };

    static real_T tmp_7[9] = { 1.7007470856000001E-001, -0.00071033134,
      -0.00059844292, -0.00071033134, 0.1715993471, -0.00240388659,
      -0.00059844292, -0.00240388659, 0.1585857207 };

    static real_T tmp_8[9] = { 2.3197473299597561E-007, -9.6886200382370103E-010,
      -8.1625091558723402E-010, -9.6886200382370103E-010,
      2.3405427569357250E-007, -3.2787999731960629E-009,
      -8.1625091558723402E-010, -3.2787999731960629E-009,
      2.1630423787190323E-007 };

    static int32_T tmp_9[9] = { -40000, 0, 0, 0, -40000, 0, 0, 0, -40000 };

    if (ssIsContinuousTask(rtS, tid)) {
      for (i = 0; i < 7; i++) {
        rtB.Integrator[i] = rtX.Integrator_CSTATE[i];
      }

      eml_x = ((rtB.Integrator[0] * rtB.Integrator[0] + rtB.Integrator[1] *
                rtB.Integrator[1]) + rtB.Integrator[2] * rtB.Integrator[2]) +
        rtB.Integrator[3] * rtB.Integrator[3];
      eml_x = muDoubleScalarSqrt(eml_x);
      rtB.xN[0] = rtB.Integrator[0] / eml_x;
      rtB.xN[1] = rtB.Integrator[1] / eml_x;
      rtB.xN[2] = rtB.Integrator[2] / eml_x;
      rtB.xN[3] = rtB.Integrator[3] / eml_x;
      rtB.xN[4] = rtB.Integrator[4];
      rtB.xN[5] = rtB.Integrator[5];
      rtB.xN[6] = rtB.Integrator[6];

      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *) rtDWork.FromFile_PWORK.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile_PWORK.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[0].nptsPerSignal == 1) {
          {
            int_T i1;
            real_T *y0 = rtB.FromFile;
            for (i1=0; i1 < 6; i1++) {
              y0[i1] = pT[i1 + 1];
            }
          }
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[0].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile_PWORK.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[0].nptsPerSignal;
          if (pT[0] == pT[1]) {
            {
              int_T i1;
              real_T *y0 = rtB.FromFile;
              for (i1=0; i1 < 6; i1++) {
                y0[i1] = pU[ (time < pT[0]) ? 0 : 1 ];
                pU += adcs_v15_integral_Power_nom_gblFrFInfo[0].nptsPerSignal;
              }
            }
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);

            {
              int_T i1;
              real_T *y0 = rtB.FromFile;
              for (i1=0; i1 < 6; i1++) {
                if (pU[0] == pU[1]) {
                  y0[i1] = pU[0];
                } else {
                  y0[i1] = f*pU[0]+(1.0-f)*pU[1];
                }

                pU += adcs_v15_integral_Power_nom_gblFrFInfo[0].nptsPerSignal;
              }
            }
          }
        }
      }

      eml_r[0] = rtB.FromFile[0];
      eml_v[0] = rtB.FromFile[3];
      eml_r[1] = rtB.FromFile[1];
      eml_v[1] = rtB.FromFile[4];
      eml_r[2] = rtB.FromFile[2];
      eml_v[2] = rtB.FromFile[5];
      eml_oy[0] = eml_v[1] * eml_r[2] - eml_v[2] * eml_r[1];
      eml_oy[1] = eml_v[2] * eml_r[0] - eml_v[0] * eml_r[2];
      eml_oy[2] = eml_v[0] * eml_r[1] - eml_v[1] * eml_r[0];
      eml_B = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_b(eml_oy,
        eml_oy));
      eml_oy[0] /= eml_B;
      eml_oy[1] /= eml_B;
      eml_oy[2] /= eml_B;
      eml_B = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_b(eml_r, eml_r));
      eml_r[0] = (-eml_r[0]) / eml_B;
      eml_r[1] = (-eml_r[1]) / eml_B;
      eml_r[2] = (-eml_r[2]) / eml_B;
      eml_v[0] = eml_oy[1] * eml_r[2] - eml_oy[2] * eml_r[1];
      eml_v[1] = eml_oy[2] * eml_r[0] - eml_oy[0] * eml_r[2];
      eml_v[2] = eml_oy[0] * eml_r[1] - eml_oy[1] * eml_r[0];
      eml_B = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_b(eml_v, eml_v));
      eml_q_idx_0 = eml_v[0] / eml_B;
      eml_TIO_idx_0 = eml_q_idx_0;
      eml_v[0] = eml_q_idx_0;
      eml_q_idx_0 = eml_v[1] / eml_B;
      eml_TIO_idx = eml_q_idx_0;
      eml_v[1] = eml_q_idx_0;
      eml_q_idx_0 = eml_v[2] / eml_B;
      eml_v[2] = eml_q_idx_0;
      if ((eml_TIO_idx_0 + eml_oy[1]) + eml_r[2] == -1.0) {
        if ((eml_oy[0] == 0.0) && (eml_r[0] == 0.0)) {
          eml_q_idx = 1.0;
          eml_TIO_idx_0 = 0.0;
          eml_q_idx_0 = 0.0;
          eml_B = 0.0;
        } else if ((eml_oy[0] == 0.0) && (eml_r[1] == 0.0)) {
          eml_q_idx = 0.0;
          eml_TIO_idx_0 = 1.0;
          eml_q_idx_0 = 0.0;
          eml_B = 0.0;
        } else if ((eml_r[0] == 0.0) && (eml_r[1] == 0.0)) {
          eml_q_idx = 0.0;
          eml_TIO_idx_0 = 0.0;
          eml_q_idx_0 = 1.0;
          eml_B = 0.0;
        } else {
          eml_B = eml_oy[0] * eml_r[0];
          eml_TIO_idx = eml_oy[0] * eml_r[1];
          eml_x = eml_r[0] * eml_r[1];
          eml_norm = muDoubleScalarSqrt((eml_B * eml_B + eml_TIO_idx *
            eml_TIO_idx) + eml_x * eml_x);
          eml_q_idx = eml_B / eml_norm;
          eml_TIO_idx_0 = eml_TIO_idx / eml_norm;
          eml_q_idx_0 = eml_x / eml_norm;
          eml_B = 0.0 / eml_norm;
        }
      } else {
        eml_B = muDoubleScalarSqrt(((eml_TIO_idx_0 + eml_oy[1]) + eml_r[2]) +
          1.0) * 0.5;
        eml_q_idx = (-(eml_oy[2] - eml_r[1])) / (4.0 * eml_B);
        eml_TIO_idx_0 = (-(eml_r[0] - eml_q_idx_0)) / (4.0 * eml_B);
        eml_q_idx_0 = (-(eml_TIO_idx - eml_oy[0])) / (4.0 * eml_B);
      }

      eml_q_BI[0] = rtB.xN[3];
      eml_q_BI[4] = rtB.xN[2];
      eml_q_BI[8] = -rtB.xN[1];
      eml_q_BI[12] = rtB.xN[0];
      eml_q_BI[1] = -rtB.xN[2];
      eml_q_BI[5] = rtB.xN[3];
      eml_q_BI[9] = rtB.xN[0];
      eml_q_BI[13] = rtB.xN[1];
      eml_q_BI[2] = rtB.xN[1];
      eml_q_BI[6] = -rtB.xN[0];
      eml_q_BI[10] = rtB.xN[3];
      eml_q_BI[14] = rtB.xN[2];
      eml_q_BI[3] = -rtB.xN[0];
      eml_q_BI[7] = -rtB.xN[1];
      eml_q_BI[11] = -rtB.xN[2];
      eml_q_BI[15] = rtB.xN[3];
      for (i = 0; i < 4; i++) {
        rtB.q_BO[i] = 0.0;
        rtB.q_BO[i] = eml_q_BI[i] * eml_q_idx + rtB.q_BO[i];
        rtB.q_BO[i] = eml_q_BI[i + 4] * eml_TIO_idx_0 + rtB.q_BO[i];
        rtB.q_BO[i] = eml_q_BI[i + 8] * eml_q_idx_0 + rtB.q_BO[i];
        rtB.q_BO[i] = eml_q_BI[i + 12] * eml_B + rtB.q_BO[i];
      }

      rtB.euler[0] = muDoubleScalarAtan2((rtB.q_BO[3] * rtB.q_BO[0] - rtB.q_BO[1]
        * rtB.q_BO[2]) * 2.0, 1.0 - (muDoubleScalarPower(rtB.q_BO[0], 2.0) +
        muDoubleScalarPower(rtB.q_BO[1], 2.0)) * 2.0) * 5.7295779513082323E+001;
      rtB.euler[1] = muDoubleScalarAsin((rtB.q_BO[3] * rtB.q_BO[1] + rtB.q_BO[2]
        * rtB.q_BO[0]) * 2.0) * 5.7295779513082323E+001;
      rtB.euler[2] = muDoubleScalarAtan2((rtB.q_BO[3] * rtB.q_BO[2] - rtB.q_BO[0]
        * rtB.q_BO[1]) * 2.0, 1.0 - (muDoubleScalarPower(rtB.q_BO[1], 2.0) +
        muDoubleScalarPower(rtB.q_BO[2], 2.0)) * 2.0) * 5.7295779513082323E+001;
      rtB.w_BIB[0] = rtB.xN[4];
      rtB.w_BIB[1] = rtB.xN[5];
      rtB.w_BIB[2] = rtB.xN[6];
      eml_v_0[0] = ((muDoubleScalarPower(rtB.q_BO[3], 2.0) + muDoubleScalarPower
                     (rtB.q_BO[0], 2.0)) - muDoubleScalarPower(rtB.q_BO[1], 2.0))
        - muDoubleScalarPower(rtB.q_BO[2], 2.0);
      eml_v_0[3] = 2.0 * rtB.q_BO[3] * rtB.q_BO[2] + 2.0 * rtB.q_BO[0] *
        rtB.q_BO[1];
      eml_v_0[6] = 2.0 * rtB.q_BO[0] * rtB.q_BO[2] - 2.0 * rtB.q_BO[3] *
        rtB.q_BO[1];
      eml_v_0[1] = 2.0 * rtB.q_BO[0] * rtB.q_BO[1] - 2.0 * rtB.q_BO[3] *
        rtB.q_BO[2];
      eml_v_0[4] = ((muDoubleScalarPower(rtB.q_BO[3], 2.0) - muDoubleScalarPower
                     (rtB.q_BO[0], 2.0)) + muDoubleScalarPower(rtB.q_BO[1], 2.0))
        - muDoubleScalarPower(rtB.q_BO[2], 2.0);
      eml_v_0[7] = 2.0 * rtB.q_BO[3] * rtB.q_BO[0] + 2.0 * rtB.q_BO[1] *
        rtB.q_BO[2];
      eml_v_0[2] = 2.0 * rtB.q_BO[3] * rtB.q_BO[1] + 2.0 * rtB.q_BO[0] *
        rtB.q_BO[2];
      eml_v_0[5] = 2.0 * rtB.q_BO[1] * rtB.q_BO[2] - 2.0 * rtB.q_BO[3] *
        rtB.q_BO[0];
      eml_v_0[8] = ((muDoubleScalarPower(rtB.q_BO[3], 2.0) - muDoubleScalarPower
                     (rtB.q_BO[0], 2.0)) - muDoubleScalarPower(rtB.q_BO[1], 2.0))
        + muDoubleScalarPower(rtB.q_BO[2], 2.0);
      for (i = 0; i < 3; i++) {
        rtB.w_BOB[i] = rtB.w_BIB[i] - ((eml_v_0[i + 3] *
          -1.0345212007894661E-003 + eml_v_0[i] * 0.0) + eml_v_0[i + 6] * 0.0);
      }

      rtB.modw = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_b
        (&rtB.w_BOB[0], &rtB.w_BOB[0]));
      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        rtB.TmpRTBAtScope1Inport1[0] = rtB.q_BO[0];
        rtB.TmpRTBAtScope1Inport1[1] = rtB.q_BO[1];
        rtB.TmpRTBAtScope1Inport1[2] = rtB.q_BO[2];
        rtB.TmpRTBAtScope1Inport1[3] = rtB.q_BO[3];
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum = rtP.MatrixGain_Gain * rtDWork.NextOutput + rtP.Constant_Value;

      {
        rtB.Buffer = rtB.Sum;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *) rtDWork.FromFile1_PWORK.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile1_PWORK.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal == 1) {
          rtb_Product[0] = pT[1];
          rtb_Product[1] = pT[2];
          rtb_Product[2] = pT[3];
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile1_PWORK.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal;
          if (pT[0] == pT[1]) {
            rtb_Product[0] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal;
            rtb_Product[1] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal;
            rtb_Product[2] = pU[ (time < pT[0]) ? 0 : 1 ];
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);
            if (pU[0] == pU[1]) {
              rtb_Product[0] = pU[0];
            } else {
              rtb_Product[0] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtb_Product[1] = pU[0];
            } else {
              rtb_Product[1] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[1].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtb_Product[2] = pU[0];
            } else {
              rtb_Product[2] = f*pU[0]+(1.0-f)*pU[1];
            }
          }
        }
      }

      rtB.Gain[0] = rtP.Gain_Gain * rtb_Product[0];
      rtB.Gain[1] = rtP.Gain_Gain * rtb_Product[1];
      rtB.Gain[2] = rtP.Gain_Gain * rtb_Product[2];
      eml_v_0[0] = ((muDoubleScalarPower(rtB.xN[3], 2.0) + muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[3] = 2.0 * rtB.xN[3] * rtB.xN[2] + 2.0 * rtB.xN[0] * rtB.xN[1];
      eml_v_0[6] = 2.0 * rtB.xN[0] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[1];
      eml_v_0[1] = 2.0 * rtB.xN[0] * rtB.xN[1] - 2.0 * rtB.xN[3] * rtB.xN[2];
      eml_v_0[4] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) + muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[7] = 2.0 * rtB.xN[3] * rtB.xN[0] + 2.0 * rtB.xN[1] * rtB.xN[2];
      eml_v_0[2] = 2.0 * rtB.xN[3] * rtB.xN[1] + 2.0 * rtB.xN[0] * rtB.xN[2];
      eml_v_0[5] = 2.0 * rtB.xN[1] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[0];
      eml_v_0[8] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) +
        muDoubleScalarPower(rtB.xN[2], 2.0);
      for (i = 0; i < 3; i++) {
        rtB.v_B_b[i] = 0.0;
        rtB.v_B_b[i] = eml_v_0[i] * rtB.Gain[0] + rtB.v_B_b[i];
        rtB.v_B_b[i] = eml_v_0[i + 3] * rtB.Gain[1] + rtB.v_B_b[i];
        rtB.v_B_b[i] = eml_v_0[i + 6] * rtB.Gain[2] + rtB.v_B_b[i];
      }
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant = rtP.Constant_Value_g;
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Sum1[0] = (rtB.Buffer + rtB.v_B_b[0]) + rtB.Constant;
      rtB.Sum1[1] = (rtB.Buffer + rtB.v_B_b[1]) + rtB.Constant;
      rtB.Sum1[2] = (rtB.Buffer + rtB.v_B_b[2]) + rtB.Constant;
      if (ssIsSpecialSampleHit(rtS,2,0,tid)) {
        rtB.TmpRTBAtQuESTInport1[0] = rtB.Sum1[0];
        rtB.TmpRTBAtQuESTInport1[1] = rtB.Sum1[1];
        rtB.TmpRTBAtQuESTInport1[2] = rtB.Sum1[2];
      }
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_j[0] = rtP.Constant_Value_e[0];
      rtB.Constant_j[1] = rtP.Constant_Value_e[1];
      rtB.Constant_j[2] = rtP.Constant_Value_e[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *) rtDWork.FromFile_PWORK_n.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile_PWORK_n.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal == 1) {
          rtB.FromFile_e[0] = pT[1];
          rtB.FromFile_e[1] = pT[2];
          rtB.FromFile_e[2] = pT[3];
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile_PWORK_n.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal;
          if (pT[0] == pT[1]) {
            rtB.FromFile_e[0] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal;
            rtB.FromFile_e[1] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal;
            rtB.FromFile_e[2] = pU[ (time < pT[0]) ? 0 : 1 ];
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);
            if (pU[0] == pU[1]) {
              rtB.FromFile_e[0] = pU[0];
            } else {
              rtB.FromFile_e[0] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtB.FromFile_e[1] = pU[0];
            } else {
              rtB.FromFile_e[1] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[2].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtB.FromFile_e[2] = pU[0];
            } else {
              rtB.FromFile_e[2] = f*pU[0]+(1.0-f)*pU[1];
            }
          }
        }
      }

      eml_v_0[0] = ((muDoubleScalarPower(rtB.xN[3], 2.0) + muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[3] = 2.0 * rtB.xN[3] * rtB.xN[2] + 2.0 * rtB.xN[0] * rtB.xN[1];
      eml_v_0[6] = 2.0 * rtB.xN[0] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[1];
      eml_v_0[1] = 2.0 * rtB.xN[0] * rtB.xN[1] - 2.0 * rtB.xN[3] * rtB.xN[2];
      eml_v_0[4] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) + muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[7] = 2.0 * rtB.xN[3] * rtB.xN[0] + 2.0 * rtB.xN[1] * rtB.xN[2];
      eml_v_0[2] = 2.0 * rtB.xN[3] * rtB.xN[1] + 2.0 * rtB.xN[0] * rtB.xN[2];
      eml_v_0[5] = 2.0 * rtB.xN[1] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[0];
      eml_v_0[8] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) +
        muDoubleScalarPower(rtB.xN[2], 2.0);
      for (i = 0; i < 3; i++) {
        rtB.v_B[i] = 0.0;
        rtB.v_B[i] = eml_v_0[i] * rtB.FromFile_e[0] + rtB.v_B[i];
        rtB.v_B[i] = eml_v_0[i + 3] * rtB.FromFile_e[1] + rtB.v_B[i];
        rtB.v_B[i] = eml_v_0[i + 6] * rtB.FromFile_e[2] + rtB.v_B[i];
      }

      eml_TIO_idx = (rtB.v_B[0] * rtB.v_B[0] + rtB.v_B[1] * rtB.v_B[1]) +
        rtB.v_B[2] * rtB.v_B[2];
      eml_TIO_idx = muDoubleScalarSqrt(eml_TIO_idx);
      rtB.v_B[0] = rtB.v_B[0] / eml_TIO_idx;
      rtB.v_B[1] = rtB.v_B[1] / eml_TIO_idx;
      rtB.v_B[2] = rtB.v_B[2] / eml_TIO_idx;
      rtb_jxi = (rtB.Constant_j[0] * rtB.v_B[0] + rtB.Constant_j[1] * rtB.v_B[1])
        + rtB.Constant_j[2] * rtB.v_B[2];

      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *) rtDWork.FromFile2_PWORK.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile2_PWORK.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[3].nptsPerSignal == 1) {
          rtB.FromFile2 = pT[1];
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[3].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile2_PWORK.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[3].nptsPerSignal;
          if (pT[0] == pT[1]) {
            rtB.FromFile2 = pU[ (time < pT[0]) ? 0 : 1 ];
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);
            if (pU[0] == pU[1]) {
              rtB.FromFile2 = pU[0];
            } else {
              rtB.FromFile2 = f*pU[0]+(1.0-f)*pU[1];
            }
          }
        }
      }

      rtb_jxi *= rtB.FromFile2;
      rtb_Gain = rtP.Gain_Gain_l * rt_SATURATE(rtb_jxi, rtP.Saturation_LowerSat,
        rtP.Saturation_UpperSat);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum_d = rtP.MatrixGain_Gain_g * rtDWork.NextOutput_f +
        rtP.Constant_Value_e5;

      {
        rtB.Buffer_e = rtB.Sum_d;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = rtb_Gain + rtB.Buffer_e;
      rtB.ADC = rtP.ADC_Interval * muDoubleScalarRound((rtb_jxi/
        (rtP.ADC_Interval)));
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_f[0] = rtP.Constant_Value_p[0];
      rtB.Constant_f[1] = rtP.Constant_Value_p[1];
      rtB.Constant_f[2] = rtP.Constant_Value_p[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = (rtB.Constant_f[0] * rtB.v_B[0] + rtB.Constant_f[1] * rtB.v_B[1])
        + rtB.Constant_f[2] * rtB.v_B[2];
      rtb_jxi *= rtB.FromFile2;
      rtb_Gain_d = rtP.Gain_Gain_p * rt_SATURATE(rtb_jxi,
        rtP.Saturation_LowerSat_m, rtP.Saturation_UpperSat_m);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum_l = rtP.MatrixGain_Gain_i * rtDWork.NextOutput_h +
        rtP.Constant_Value_l;

      {
        rtB.Buffer_c = rtB.Sum_l;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = rtb_Gain_d + rtB.Buffer_c;
      rtB.ADC_d = rtP.ADC_Interval_c * muDoubleScalarRound((rtb_jxi/
        (rtP.ADC_Interval_c)));
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_k[0] = rtP.Constant_Value_m[0];
      rtB.Constant_k[1] = rtP.Constant_Value_m[1];
      rtB.Constant_k[2] = rtP.Constant_Value_m[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = (rtB.Constant_k[0] * rtB.v_B[0] + rtB.Constant_k[1] * rtB.v_B[1])
        + rtB.Constant_k[2] * rtB.v_B[2];
      rtb_jxi *= rtB.FromFile2;
      rtb_Gain_e = rtP.Gain_Gain_i * rt_SATURATE(rtb_jxi,
        rtP.Saturation_LowerSat_a, rtP.Saturation_UpperSat_mv);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum_f = rtP.MatrixGain_Gain_n * rtDWork.NextOutput_a +
        rtP.Constant_Value_n;

      {
        rtB.Buffer_cr = rtB.Sum_f;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = rtb_Gain_e + rtB.Buffer_cr;
      rtB.ADC_o = rtP.ADC_Interval_b * muDoubleScalarRound((rtb_jxi/
        (rtP.ADC_Interval_b)));
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_l[0] = rtP.Constant_Value_h[0];
      rtB.Constant_l[1] = rtP.Constant_Value_h[1];
      rtB.Constant_l[2] = rtP.Constant_Value_h[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = (rtB.Constant_l[0] * rtB.v_B[0] + rtB.Constant_l[1] * rtB.v_B[1])
        + rtB.Constant_l[2] * rtB.v_B[2];
      rtb_jxi *= rtB.FromFile2;
      rtb_Gain_a = rtP.Gain_Gain_n * rt_SATURATE(rtb_jxi,
        rtP.Saturation_LowerSat_c, rtP.Saturation_UpperSat_j);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum_o = rtP.MatrixGain_Gain_o * rtDWork.NextOutput_g +
        rtP.Constant_Value_mz;

      {
        rtB.Buffer_p = rtB.Sum_o;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = rtb_Gain_a + rtB.Buffer_p;
      rtB.ADC_b = rtP.ADC_Interval_k * muDoubleScalarRound((rtb_jxi/
        (rtP.ADC_Interval_k)));
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_e[0] = rtP.Constant_Value_k[0];
      rtB.Constant_e[1] = rtP.Constant_Value_k[1];
      rtB.Constant_e[2] = rtP.Constant_Value_k[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = (rtB.Constant_e[0] * rtB.v_B[0] + rtB.Constant_e[1] * rtB.v_B[1])
        + rtB.Constant_e[2] * rtB.v_B[2];
      rtb_jxi *= rtB.FromFile2;
      rtb_Gain_p = rtP.Gain_Gain_g * rt_SATURATE(rtb_jxi,
        rtP.Saturation_LowerSat_n, rtP.Saturation_UpperSat_b);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum_h = rtP.MatrixGain_Gain_d * rtDWork.NextOutput_o +
        rtP.Constant_Value_b;

      {
        rtB.Buffer_o = rtB.Sum_h;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = rtb_Gain_p + rtB.Buffer_o;
      rtB.ADC_m = rtP.ADC_Interval_j * muDoubleScalarRound((rtb_jxi/
        (rtP.ADC_Interval_j)));
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_ei[0] = rtP.Constant_Value_i[0];
      rtB.Constant_ei[1] = rtP.Constant_Value_i[1];
      rtB.Constant_ei[2] = rtP.Constant_Value_i[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = (rtB.Constant_ei[0] * rtB.v_B[0] + rtB.Constant_ei[1] * rtB.v_B
                 [1]) + rtB.Constant_ei[2] * rtB.v_B[2];
      rtb_jxi *= rtB.FromFile2;
      rtb_Gain_g = rtP.Gain_Gain_e * rt_SATURATE(rtb_jxi,
        rtP.Saturation_LowerSat_o, rtP.Saturation_UpperSat_l);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Sum_m = rtP.MatrixGain_Gain_l * rtDWork.NextOutput_gv +
        rtP.Constant_Value_i3;

      {
        rtB.Buffer_p3 = rtB.Sum_m;
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtb_jxi = rtb_Gain_g + rtB.Buffer_p3;
      rtB.ADC_l = rtP.ADC_Interval_jq * muDoubleScalarRound((rtb_jxi/
        (rtP.ADC_Interval_jq)));
      rtB.m_SUN[0] = rtB.Constant_j[0];
      rtB.m_SUN[1] = rtB.Constant_j[1];
      rtB.m_SUN[2] = rtB.Constant_j[2];
      rtB.m_SUN[5] = rtB.Constant_f[0];
      rtB.m_SUN[6] = rtB.Constant_f[1];
      rtB.m_SUN[7] = rtB.Constant_f[2];
      rtB.m_SUN[10] = rtB.Constant_k[0];
      rtB.m_SUN[11] = rtB.Constant_k[1];
      rtB.m_SUN[12] = rtB.Constant_k[2];
      rtB.m_SUN[15] = rtB.Constant_l[0];
      rtB.m_SUN[16] = rtB.Constant_l[1];
      rtB.m_SUN[17] = rtB.Constant_l[2];
      rtB.m_SUN[20] = rtB.Constant_e[0];
      rtB.m_SUN[21] = rtB.Constant_e[1];
      rtB.m_SUN[22] = rtB.Constant_e[2];
      rtB.m_SUN[25] = rtB.Constant_ei[0];
      rtB.m_SUN[26] = rtB.Constant_ei[1];
      rtB.m_SUN[27] = rtB.Constant_ei[2];
      for (i = 0; i < 6; i++) {
        rtB.m_SUN[3 + 5 * i] = 0.0;
      }

      rtB.m_SUN[4] = rtB.ADC;
      rtB.m_SUN[9] = rtB.ADC_d;
      rtB.m_SUN[14] = rtB.ADC_o;
      rtB.m_SUN[19] = rtB.ADC_b;
      rtB.m_SUN[24] = rtB.ADC_m;
      rtB.m_SUN[29] = rtB.ADC_l;
      for (i = 0; i < 6; i++) {
        tmp[i] = (rtB.m_SUN[5 * i + 4] > 8.7155742747658138E-002);
      }

      for (i = 0; i < 6; i++) {
        rtB.m_SUN[3 + 5 * i] = (real_T)tmp[i];
      }

      for (i = 0; i < 6; i++) {
        rtB.values[i] = rtB.m_SUN[5 * i + 4];
      }

      if (ssIsSpecialSampleHit(rtS,2,0,tid)) {
        memcpy((void *)(&rtB.TmpRTBAtQuESTInport2[0]), (void *)(&rtB.m_SUN[0]),
               30U * sizeof(real_T));
      }
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *) rtDWork.FromFile_PWORK_l.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile_PWORK_l.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal == 1) {
          rtB.FromFile_f[0] = pT[1];
          rtB.FromFile_f[1] = pT[2];
          rtB.FromFile_f[2] = pT[3];
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile_PWORK_l.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal;
          if (pT[0] == pT[1]) {
            rtB.FromFile_f[0] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal;
            rtB.FromFile_f[1] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal;
            rtB.FromFile_f[2] = pU[ (time < pT[0]) ? 0 : 1 ];
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);
            if (pU[0] == pU[1]) {
              rtB.FromFile_f[0] = pU[0];
            } else {
              rtB.FromFile_f[0] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtB.FromFile_f[1] = pU[0];
            } else {
              rtB.FromFile_f[1] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[4].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtB.FromFile_f[2] = pU[0];
            } else {
              rtB.FromFile_f[2] = f*pU[0]+(1.0-f)*pU[1];
            }
          }
        }
      }

      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *)
          rtDWork.FromFile2_PWORK_l.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile2_PWORK_l.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[5].nptsPerSignal == 1) {
          {
            int_T i1;
            real_T *y0 = rtB.FromFile2_g;
            for (i1=0; i1 < 6; i1++) {
              y0[i1] = pT[i1 + 1];
            }
          }
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[5].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile2_PWORK_l.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[5].nptsPerSignal;
          if (pT[0] == pT[1]) {
            {
              int_T i1;
              real_T *y0 = rtB.FromFile2_g;
              for (i1=0; i1 < 6; i1++) {
                y0[i1] = pU[ (time < pT[0]) ? 0 : 1 ];
                pU += adcs_v15_integral_Power_nom_gblFrFInfo[5].nptsPerSignal;
              }
            }
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);

            {
              int_T i1;
              real_T *y0 = rtB.FromFile2_g;
              for (i1=0; i1 < 6; i1++) {
                if (pU[0] == pU[1]) {
                  y0[i1] = pU[0];
                } else {
                  y0[i1] = f*pU[0]+(1.0-f)*pU[1];
                }

                pU += adcs_v15_integral_Power_nom_gblFrFInfo[5].nptsPerSignal;
              }
            }
          }
        }
      }

      {
        static const real_T *pStart = (NULL);
        static boolean_T initBasePtr = TRUE;
        real_T time = ssGetTaskTime(rtS,tid);
        const real_T *pU = (NULL);
        const real_T *pT = (const real_T *) rtDWork.FromFile3_PWORK.PrevTimePtr;
        if (initBasePtr == TRUE) {
          pStart = (real_T *) rtDWork.FromFile3_PWORK.PrevTimePtr;
          initBasePtr = FALSE;
        }

        if (adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal == 1) {
          rtB.FromFile3[0] = pT[1];
          rtB.FromFile3[1] = pT[2];
          rtB.FromFile3[2] = pT[3];
        } else {
          pU = pStart + adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal
            - 2;
          if (time <= pStart[0]) {
            pT = pStart;
          } else if (time >= pU[0]) {
            pT = pU;
          } else {
            if (time < pT[0]) {
              while (time < pT[0]) {
                pT--;
              }
            } else {
              while (time >= pT[1]) {
                pT++;
              }
            }
          }

          rtDWork.FromFile3_PWORK.PrevTimePtr = (void *) pT;
          pU = pT + adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal;
          if (pT[0] == pT[1]) {
            rtB.FromFile3[0] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal;
            rtB.FromFile3[1] = pU[ (time < pT[0]) ? 0 : 1 ];
            pU += adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal;
            rtB.FromFile3[2] = pU[ (time < pT[0]) ? 0 : 1 ];
          } else {
            real_T f = (pT[1]-time)/(pT[1]-pT[0]);
            if (pU[0] == pU[1]) {
              rtB.FromFile3[0] = pU[0];
            } else {
              rtB.FromFile3[0] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtB.FromFile3[1] = pU[0];
            } else {
              rtB.FromFile3[1] = f*pU[0]+(1.0-f)*pU[1];
            }

            pU += adcs_v15_integral_Power_nom_gblFrFInfo[6].nptsPerSignal;
            if (pU[0] == pU[1]) {
              rtB.FromFile3[2] = pU[0];
            } else {
              rtB.FromFile3[2] = f*pU[0]+(1.0-f)*pU[1];
            }
          }
        }
      }

      eml_r[0] = rtB.FromFile2_g[0];
      eml_v[0] = rtB.FromFile2_g[3];
      eml_r[1] = rtB.FromFile2_g[1];
      eml_v[1] = rtB.FromFile2_g[4];
      eml_r[2] = rtB.FromFile2_g[2];
      eml_v[2] = rtB.FromFile2_g[5];
      eml_oy[0] = eml_v[1] * eml_r[2] - eml_v[2] * eml_r[1];
      eml_oy[1] = eml_v[2] * eml_r[0] - eml_v[0] * eml_r[2];
      eml_oy[2] = eml_v[0] * eml_r[1] - eml_v[1] * eml_r[0];
      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_l(eml_oy,
        eml_oy));
      eml_oy[0] /= eml_TIO_idx;
      eml_oy[1] /= eml_TIO_idx;
      eml_oy[2] /= eml_TIO_idx;
      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_l(eml_r,
        eml_r));
      eml_r[0] = (-eml_r[0]) / eml_TIO_idx;
      eml_r[1] = (-eml_r[1]) / eml_TIO_idx;
      eml_r[2] = (-eml_r[2]) / eml_TIO_idx;
      eml_v[0] = eml_oy[1] * eml_r[2] - eml_oy[2] * eml_r[1];
      eml_v[1] = eml_oy[2] * eml_r[0] - eml_oy[0] * eml_r[2];
      eml_v[2] = eml_oy[0] * eml_r[1] - eml_oy[1] * eml_r[0];
      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_l(eml_v,
        eml_v));
      eml_v[0] /= eml_TIO_idx;
      eml_v[1] /= eml_TIO_idx;
      eml_v[2] /= eml_TIO_idx;
      eml_v_0[0] = eml_v[0];
      eml_v_0[3] = eml_v[1];
      eml_v_0[6] = eml_v[2];
      eml_v_0[1] = eml_oy[0];
      eml_v_0[4] = eml_oy[1];
      eml_v_0[7] = eml_oy[2];
      eml_v_0[2] = eml_r[0];
      eml_v_0[5] = eml_r[1];
      eml_v_0[8] = eml_r[2];
      for (i = 0; i < 3; i++) {
        rtB.v_O_k[i] = 0.0;
        rtB.v_O_k[i] = eml_v_0[i] * rtB.FromFile3[0] + rtB.v_O_k[i];
        rtB.v_O_k[i] = eml_v_0[i + 3] * rtB.FromFile3[1] + rtB.v_O_k[i];
        rtB.v_O_k[i] = eml_v_0[i + 6] * rtB.FromFile3[2] + rtB.v_O_k[i];
        eml_r[i] = rtB.FromFile2_g[i];
        eml_v[i] = rtB.FromFile2_g[i + 3];
      }

      eml_oy[0] = eml_v[1] * eml_r[2] - eml_v[2] * eml_r[1];
      eml_oy[1] = eml_v[2] * eml_r[0] - eml_v[0] * eml_r[2];
      eml_oy[2] = eml_v[0] * eml_r[1] - eml_v[1] * eml_r[0];
      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_o(eml_oy,
        eml_oy));
      eml_oy[0] /= eml_TIO_idx;
      eml_oy[1] /= eml_TIO_idx;
      eml_oy[2] /= eml_TIO_idx;
      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_o(eml_r,
        eml_r));
      eml_r[0] = (-eml_r[0]) / eml_TIO_idx;
      eml_r[1] = (-eml_r[1]) / eml_TIO_idx;
      eml_r[2] = (-eml_r[2]) / eml_TIO_idx;
      eml_v[0] = eml_oy[1] * eml_r[2] - eml_oy[2] * eml_r[1];
      eml_v[1] = eml_oy[2] * eml_r[0] - eml_oy[0] * eml_r[2];
      eml_v[2] = eml_oy[0] * eml_r[1] - eml_oy[1] * eml_r[0];
      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_o(eml_v,
        eml_v));
      eml_v[0] /= eml_TIO_idx;
      eml_v[1] /= eml_TIO_idx;
      eml_v[2] /= eml_TIO_idx;
      eml_v_0[0] = eml_v[0];
      eml_v_0[3] = eml_v[1];
      eml_v_0[6] = eml_v[2];
      eml_v_0[1] = eml_oy[0];
      eml_v_0[4] = eml_oy[1];
      eml_v_0[7] = eml_oy[2];
      eml_v_0[2] = eml_r[0];
      eml_v_0[5] = eml_r[1];
      eml_v_0[8] = eml_r[2];
      for (i = 0; i < 3; i++) {
        rtB.v_O[i] = 0.0;
        rtB.v_O[i] = eml_v_0[i] * rtB.FromFile_f[0] + rtB.v_O[i];
        rtB.v_O[i] = eml_v_0[i + 3] * rtB.FromFile_f[1] + rtB.v_O[i];
        rtB.v_O[i] = eml_v_0[i + 6] * rtB.FromFile_f[2] + rtB.v_O[i];
      }

      adcs_v15_integral_Power_nom_QuEST();
      if (ssIsSpecialSampleHit(rtS,4,2,tid)) {
        rtB.TmpRTBAtScope10Inport1 = rtB.light_est;
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope2Inport1[0] = rtB.euler[0];
      rtB.TmpRTBAtScope2Inport1[1] = rtB.euler[1];
      rtB.TmpRTBAtScope2Inport1[2] = rtB.euler[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope3Inport1[0] = rtB.w_BOB[0];
      rtB.TmpRTBAtScope3Inport1[1] = rtB.w_BOB[1];
      rtB.TmpRTBAtScope3Inport1[2] = rtB.w_BOB[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope4Inport1 = rtB.modw;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope5Inport1[0] = rtB.w_BIB[0];
      rtB.TmpRTBAtScope5Inport1[1] = rtB.w_BIB[1];
      rtB.TmpRTBAtScope5Inport1[2] = rtB.w_BIB[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,2,0,tid)) {
      rtB.TmpRTBAtControlLawInport1[0] = rtB.Sum1[0];
      rtB.TmpRTBAtControlLawInport1[1] = rtB.Sum1[1];
      rtB.TmpRTBAtControlLawInport1[2] = rtB.Sum1[2];
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtB.IntegerDelay1_k[0] = rtDWork.IntegerDelay1_X_d[0];
      rtB.IntegerDelay1_k[1] = rtDWork.IntegerDelay1_X_d[1];
      rtB.IntegerDelay1_k[2] = rtDWork.IntegerDelay1_X_d[2];
      rtB.IntegerDelay_n[0] = rtDWork.IntegerDelay_X_l[0];
      eml_q_idx = (rtB.q_BO_est[0] + rtB.IntegerDelay_n[0]) / 2.0;
      rtB.IntegerDelay_n[1] = rtDWork.IntegerDelay_X_l[1];
      eml_TIO_idx_0 = (rtB.q_BO_est[1] + rtB.IntegerDelay_n[1]) / 2.0;
      rtB.IntegerDelay_n[2] = rtDWork.IntegerDelay_X_l[2];
      eml_q_idx_0 = (rtB.q_BO_est[2] + rtB.IntegerDelay_n[2]) / 2.0;
      rtB.IntegerDelay_n[3] = rtDWork.IntegerDelay_X_l[3];
      eml_B = (rtB.q_BO_est[3] + rtB.IntegerDelay_n[3]) / 2.0;
      eml_r[0] = eml_q_idx;
      eml_r[1] = eml_TIO_idx_0;
      eml_r[2] = eml_q_idx_0;
      eml_TIO_idx = eml_B * eml_B;
      eml_v_0[0] = 0.0;
      eml_v_0[3] = -eml_r[2];
      eml_v_0[6] = eml_r[1];
      eml_v_0[1] = eml_r[2];
      eml_v_0[4] = 0.0;
      eml_v_0[7] = -eml_r[0];
      eml_v_0[2] = -eml_r[1];
      eml_v_0[5] = eml_r[0];
      eml_v_0[8] = 0.0;
      for (i = 0; i < 3; i++) {
        eml_e[i] = (eml_TIO_idx * (real_T)tmp_4[i] - eml_B * eml_v_0[i]) +
          eml_r[i] * eml_r[0];
        eml_e[i + 3] = ((real_T)tmp_4[i + 3] * eml_TIO_idx - eml_v_0[i + 3] *
                        eml_B) + eml_r[i] * eml_r[1];
        eml_e[i + 6] = ((real_T)tmp_4[i + 6] * eml_TIO_idx - eml_v_0[i + 6] *
                        eml_B) + eml_r[i] * eml_r[2];
      }

      eml_q_idx_0 = (rtB.q_BO_est[0] - rtB.IntegerDelay_n[0]) /
        adcs_v15_integral_Power_nom_s_FRAME_SIZE;
      eml_TIO_idx = (rtB.q_BO_est[1] - rtB.IntegerDelay_n[1]) /
        adcs_v15_integral_Power_nom_s_FRAME_SIZE;
      eml_x = (rtB.q_BO_est[2] - rtB.IntegerDelay_n[2]) /
        adcs_v15_integral_Power_nom_s_FRAME_SIZE;
      for (i = 0; i < 3; i++) {
        eml_v_0[3 * i] = eml_e[3 * i] * 2.0;
        eml_v_0[1 + 3 * i] = eml_e[3 * i + 1] * 2.0;
        eml_v_0[2 + 3 * i] = eml_e[3 * i + 2] * 2.0;
      }

      for (i = 0; i < 3; i++) {
        rtB.w[i] = ((eml_v_0[i + 3] * eml_TIO_idx + eml_v_0[i] * eml_q_idx_0) +
                    eml_v_0[i + 6] * eml_x) / eml_B;
      }

      eml_x = 2.0 / (adcs_v15_integral_Power_nom_s_FRAME_SIZE +
                     rtP.SFunction_p2_n);
      eml_TIO_idx = 1.0 - eml_x;
      rtB.w_l[0] = eml_x * rtB.w[0] + eml_TIO_idx * rtB.IntegerDelay1_k[0];
      rtB.w_l[1] = eml_x * rtB.w[1] + eml_TIO_idx * rtB.IntegerDelay1_k[1];
      rtB.w_l[2] = eml_x * rtB.w[2] + eml_TIO_idx * rtB.IntegerDelay1_k[2];
      rtB.IntegerDelay_f = rtDWork.IntegerDelay_X_e[0];
      rtB.y = (1.0 - rtB.light_est) + rtB.IntegerDelay_f;
      if (rtB.y > 1.0) {
        rtB.y = 1.0;
      }

      rtB.Product[0] = rtB.w_l[0] * rtB.light_est * rtB.y;
      rtB.Product[1] = rtB.w_l[1] * rtB.light_est * rtB.y;
      rtB.Product[2] = rtB.w_l[2] * rtB.light_est * rtB.y;
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Clock1 = ssGetT(rtS);
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      eml_q_idx_0 = (rtB.Product[0] * rtB.Product[0] + rtB.Product[1] *
                     rtB.Product[1]) + rtB.Product[2] * rtB.Product[2];
      if (eml_q_idx_0 < 0.0) {
        rtB.Fcn = -muDoubleScalarSqrt(-eml_q_idx_0);
      } else {
        rtB.Fcn = muDoubleScalarSqrt(eml_q_idx_0);
      }

      rtB.IntegerDelay_l[0] = rtDWork.IntegerDelay_X_i[0];
      rtB.dB[0] = (rtB.TmpRTBAtControlLawInport1[0] - rtB.IntegerDelay_l[0]) /
        adcs_v15_integral_Power_nom_s_FRAME_SIZE;
      rtB.B[0] = (rtB.TmpRTBAtControlLawInport1[0] + rtB.IntegerDelay_l[0]) /
        2.0;
      rtB.IntegerDelay_l[1] = rtDWork.IntegerDelay_X_i[1];
      rtB.dB[1] = (rtB.TmpRTBAtControlLawInport1[1] - rtB.IntegerDelay_l[1]) /
        adcs_v15_integral_Power_nom_s_FRAME_SIZE;
      rtB.B[1] = (rtB.TmpRTBAtControlLawInport1[1] + rtB.IntegerDelay_l[1]) /
        2.0;
      rtB.IntegerDelay_l[2] = rtDWork.IntegerDelay_X_i[2];
      rtB.dB[2] = (rtB.TmpRTBAtControlLawInport1[2] - rtB.IntegerDelay_l[2]) /
        adcs_v15_integral_Power_nom_s_FRAME_SIZE;
      rtB.B[2] = (rtB.TmpRTBAtControlLawInport1[2] + rtB.IntegerDelay_l[2]) /
        2.0;
      eml_TIO_idx = (rtB.B[0] * rtB.B[0] + rtB.B[1] * rtB.B[1]) + rtB.B[2] *
        rtB.B[2];
      eml_TIO_idx = 2.5E-005 / muDoubleScalarSqrt(eml_TIO_idx);
      for (i = 0; i < 3; i++) {
        rtB.m_D[i] = ((real_T)tmp_9[i + 6] * rtB.dB[2] + ((real_T)tmp_9[i + 3] *
          rtB.dB[1] + (real_T)tmp_9[i] * rtB.dB[0])) * eml_TIO_idx;
      }

      rtB.UnitDelay1[0] = rtDWork.UnitDelay1_DSTATE[0];
      rtB.UnitDelay1[1] = rtDWork.UnitDelay1_DSTATE[1];
      rtB.UnitDelay1[2] = rtDWork.UnitDelay1_DSTATE[2];
      eml_TIO_idx = (rtB.TmpRTBAtControlLawInport1[0] *
                     rtB.TmpRTBAtControlLawInport1[0] +
                     rtB.TmpRTBAtControlLawInport1[1] *
                     rtB.TmpRTBAtControlLawInport1[1]) +
        rtB.TmpRTBAtControlLawInport1[2] * rtB.TmpRTBAtControlLawInport1[2];
      eml_x = ((rtB.q_BO_est[0] * rtB.q_BO_est[0] + rtB.q_BO_est[1] *
                rtB.q_BO_est[1]) + rtB.q_BO_est[2] * rtB.q_BO_est[2]) +
        rtB.q_BO_est[3] * rtB.q_BO_est[3];
      eml_x = muDoubleScalarSqrt(eml_x);
      eml_B = rtB.q_BO_est[3] / eml_x;
      rtB.eu[0] = rtB.q_BO_est[0] / eml_x * 2.0 * eml_B;
      rtB.ieu[0] = rtB.eu[0] * rtP.SFunction_p4 + rtB.UnitDelay1[0];
      rtB.eu[1] = rtB.q_BO_est[1] / eml_x * 2.0 * eml_B;
      rtB.ieu[1] = rtB.eu[1] * rtP.SFunction_p4 + rtB.UnitDelay1[1];
      rtB.eu[2] = rtB.q_BO_est[2] / eml_x * 2.0 * eml_B;
      rtB.ieu[2] = rtB.eu[2] * rtP.SFunction_p4 + rtB.UnitDelay1[2];
      eml_x = muDoubleScalarPower(muDoubleScalarSqrt(eml_TIO_idx), 2.0);
      for (i = 0; i < 3; i++) {
        rtB.m[i] = (((tmp_5[i + 3] * rtB.Product[1] + tmp_5[i] * rtB.Product[0])
                     + tmp_5[i + 6] * rtB.Product[2]) + ((tmp_8[i + 6] * rtB.eu
          [2] + (tmp_8[i + 3] * rtB.eu[1] + tmp_8[i] * rtB.eu[0])) +
          (rtP.SFunction_p2[i + 6] * rtB.ieu[2] + (rtP.SFunction_p2[i + 3] *
          rtB.ieu[1] + rtP.SFunction_p2[i] * rtB.ieu[0])))) / eml_x;
      }

      rtB.m_N[0] = (rtB.m[1] * rtB.TmpRTBAtControlLawInport1[2] - rtB.m[2] *
                    rtB.TmpRTBAtControlLawInport1[1]) * rtB.light_est;
      rtB.m_N[1] = (rtB.m[2] * rtB.TmpRTBAtControlLawInport1[0] - rtB.m[0] *
                    rtB.TmpRTBAtControlLawInport1[2]) * rtB.light_est;
      rtB.m_N[2] = (rtB.m[0] * rtB.TmpRTBAtControlLawInport1[1] - rtB.m[1] *
                    rtB.TmpRTBAtControlLawInport1[0]) * rtB.light_est;
      rtb_PowerSaturation_idx_1 = rtP.Gain1_Gain_a * rt_SATURATE(rtB.m_N[0],
        rtP.MomentSaturation_LowerSat, rtP.MomentSaturation_UpperSat);
      rtb_PowerSaturation_idx_1 = rt_SATURATE(rtb_PowerSaturation_idx_1,
        rtP.PowerSaturation_LowerSat, rtP.PowerSaturation_UpperSat);
      rtb_PowerSaturation_idx = rtb_PowerSaturation_idx_1;
      rtb_PowerSaturation_idx_1 = rtP.Gain1_Gain_a * rt_SATURATE(rtB.m_N[1],
        rtP.MomentSaturation_LowerSat, rtP.MomentSaturation_UpperSat);
      rtb_PowerSaturation_idx_1 = rt_SATURATE(rtb_PowerSaturation_idx_1,
        rtP.PowerSaturation_LowerSat, rtP.PowerSaturation_UpperSat);
      rtb_PowerSaturation_idx_0 = rtb_PowerSaturation_idx_1;
      rtb_PowerSaturation_idx_1 = rtP.Gain1_Gain_a * rt_SATURATE(rtB.m_N[2],
        rtP.MomentSaturation_LowerSat, rtP.MomentSaturation_UpperSat);
      rtb_PowerSaturation_idx_1 = rt_SATURATE(rtb_PowerSaturation_idx_1,
        rtP.PowerSaturation_LowerSat, rtP.PowerSaturation_UpperSat);
      rtB.UnitDelay1_l = rtDWork.UnitDelay1_DSTATE_c;
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,2,0,tid)) {
      rtB.TmpRTBAtgatepulseInport4 = rtB.Clock1;
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtB.UnitDelay = rtDWork.UnitDelay_DSTATE;
      eml_TIO_idx = (rtB.Product[0] * rtB.Product[0] + rtB.Product[1] *
                     rtB.Product[1]) + rtB.Product[2] * rtB.Product[2];
      eml_TIO_idx = muDoubleScalarSqrt(eml_TIO_idx);
      if ((eml_TIO_idx < adcs_v15_integral_Power_nom_tol_w) && (rtB.light_est *
           rtB.y == 1.0)) {
        eml_b_2 = true;
      } else {
        eml_b_2 = false;
      }

      rtB.P[0] = (real_T)(muDoubleScalarAbs(rtB.q_BO_est[3]) >
                          adcs_v15_integral_Power_nom_tol_q4) + 0.1;
      rtB.P[1] = (real_T)(eml_TIO_idx < adcs_v15_integral_Power_nom_tol_w);
      rtB.P[2] = (real_T)(rtB.light_est * rtB.y == 1.0) + 0.3;
      rtB.N = rtB.UnitDelay1_l;
      rtB.t_now = rtB.UnitDelay;
      if (rtB.TmpRTBAtgatepulseInport4 < 2000.0) {
        rtB.N = 0.0;
        rtB.t_now = 0.0;
      }

      if ((eml_b_2 == 1) && (rtB.UnitDelay1_l == 0.0)) {
        rtB.N = 1.0;
        rtB.t_now = rtB.TmpRTBAtgatepulseInport4;
      }

      if (((eml_TIO_idx > adcs_v15_integral_Power_nom_tolw_n2d) == 1) &&
          (rtB.UnitDelay1_l == 1.0) && (rtB.TmpRTBAtgatepulseInport4 >
           rtB.UnitDelay + adcs_v15_integral_Power_nom_check_time)) {
        rtB.N = 0.0;
        rtB.t_now = rtB.TmpRTBAtgatepulseInport4;
      }

      if (ssIsSpecialSampleHit(rtS,4,2,tid)) {
        rtB.TmpRTBAteuInport1[0] = rtB.eu[0];
        rtB.TmpRTBAteuInport1[1] = rtB.eu[1];
        rtB.TmpRTBAteuInport1[2] = rtB.eu[2];
      }

      if (ssIsSpecialSampleHit(rtS,4,2,tid)) {
        rtB.TmpRTBAtmInport1[0] = rtB.m[0];
        rtB.TmpRTBAtmInport1[1] = rtB.m[1];
        rtB.TmpRTBAtmInport1[2] = rtB.m[2];
      }

      rtB.TorquerCurrentSaturation[0] = rt_SATURATE(rtb_PowerSaturation_idx,
        rtP.TorquerCurrentSaturation_LowerSat,
        rtP.TorquerCurrentSaturation_UpperSat);
      rtB.TorquerCurrentSaturation[1] = rt_SATURATE(rtb_PowerSaturation_idx_0,
        rtP.TorquerCurrentSaturation_LowerSat,
        rtP.TorquerCurrentSaturation_UpperSat);
      rtB.TorquerCurrentSaturation[2] = rt_SATURATE(rtb_PowerSaturation_idx_1,
        rtP.TorquerCurrentSaturation_LowerSat,
        rtP.TorquerCurrentSaturation_UpperSat);
      if (ssIsSpecialSampleHit(rtS,4,2,tid)) {
        rtB.TmpRTBAtScope6Inport1 = rtB.N;
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtScope9Inport1[0] = rtB.TorquerCurrentSaturation[0];
      rtB.TmpRTBAtScope9Inport1[1] = rtB.TorquerCurrentSaturation[1];
      rtB.TmpRTBAtScope9Inport1[2] = rtB.TorquerCurrentSaturation[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace1_PWORK.LoggedData),
                        rtB.TmpRTBAtScope3Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace10Inport1[0] = rtB.v_Sun1[0];
      rtB.TmpRTBAtToWorkspace10Inport1[1] = rtB.v_Sun1[1];
      rtB.TmpRTBAtToWorkspace10Inport1[2] = rtB.v_Sun1[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace10_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace10Inport1, 0);
      }
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtToWorkspace11Inport1[0] = rtB.v_B[0];
      rtB.TmpRTBAtToWorkspace11Inport1[1] = rtB.v_B[1];
      rtB.TmpRTBAtToWorkspace11Inport1[2] = rtB.v_B[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace11_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace11Inport1, 0);
      }
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtToWorkspace12Inport1[0] = rtB.v_B_b[0];
      rtB.TmpRTBAtToWorkspace12Inport1[1] = rtB.v_B_b[1];
      rtB.TmpRTBAtToWorkspace12Inport1[2] = rtB.v_B_b[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace12_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace12Inport1, 0);
      }
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtToWorkspace13Inport1[0] = rtB.Sum1[0];
      rtB.TmpRTBAtToWorkspace13Inport1[1] = rtB.Sum1[1];
      rtB.TmpRTBAtToWorkspace13Inport1[2] = rtB.Sum1[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace13_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace13Inport1, 0);
      }

      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace14_PWORK.LoggedData),
                        rtB.TmpRTBAtScope5Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace16Inport1[0] = rtB.v_O[0];
      rtB.TmpRTBAtToWorkspace16Inport1[1] = rtB.v_O[1];
      rtB.TmpRTBAtToWorkspace16Inport1[2] = rtB.v_O[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace16_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace16Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace17Inport1[0] = rtB.q_BO_est[0];
      rtB.TmpRTBAtToWorkspace17Inport1[1] = rtB.q_BO_est[1];
      rtB.TmpRTBAtToWorkspace17Inport1[2] = rtB.q_BO_est[2];
      rtB.TmpRTBAtToWorkspace17Inport1[3] = rtB.q_BO_est[3];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace17_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace17Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace18Inport1 = rtB.light_est;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace18_PWORK.LoggedData),
                        &rtB.TmpRTBAtToWorkspace18Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace19Inport1[0] = rtB.Product[0];
      rtB.TmpRTBAtToWorkspace19Inport1[1] = rtB.Product[1];
      rtB.TmpRTBAtToWorkspace19Inport1[2] = rtB.Product[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace19_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace19Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace2Inport1 = rtB.N;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace2_PWORK.LoggedData),
                        &rtB.TmpRTBAtToWorkspace2Inport1, 0);
      }
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtToWorkspace20Inport1[0] = rtB.FromFile_e[0];
      rtB.TmpRTBAtToWorkspace20Inport1[1] = rtB.FromFile_e[1];
      rtB.TmpRTBAtToWorkspace20Inport1[2] = rtB.FromFile_e[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace20_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace20Inport1, 0);
      }

      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace3_PWORK.LoggedData),
                        rtB.TmpRTBAteuInport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace4Inport1[0] = rtB.TorquerCurrentSaturation[0];
      rtB.TmpRTBAtToWorkspace4Inport1[1] = rtB.TorquerCurrentSaturation[1];
      rtB.TmpRTBAtToWorkspace4Inport1[2] = rtB.TorquerCurrentSaturation[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace4_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace4Inport1, 0);
      }

      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace5_PWORK.LoggedData),
                        rtB.TmpRTBAtScope2Inport1, 0);
      }

      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace6_PWORK.LoggedData),
                        rtB.TmpRTBAtScope1Inport1, 0);
      }

      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace7_PWORK.LoggedData),
                        rtB.TmpRTBAtmInport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 2, tid) && ssIsSpecialSampleHit(rtS,4,2,tid)) {
      rtB.TmpRTBAtToWorkspace8Inport1[0] = rtB.v_O_k[0];
      rtB.TmpRTBAtToWorkspace8Inport1[1] = rtB.v_O_k[1];
      rtB.TmpRTBAtToWorkspace8Inport1[2] = rtB.v_O_k[2];
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace8_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace8Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Gain_k[0] = rtP.Gain_Gain_f * rtP.Constant_Value_a[0];
      rtB.Gain_k[1] = rtP.Gain_Gain_f * rtP.Constant_Value_a[1];
      rtB.Gain_k[2] = rtP.Gain_Gain_f * rtP.Constant_Value_a[2];
      eml_v_0[0] = muDoubleScalarCos(rtB.Gain_k[2]);
      eml_v_0[3] = muDoubleScalarSin(rtB.Gain_k[2]);
      eml_v_0[6] = 0.0;
      eml_v_0[1] = -muDoubleScalarSin(rtB.Gain_k[2]);
      eml_v_0[4] = muDoubleScalarCos(rtB.Gain_k[2]);
      eml_v_0[7] = 0.0;
      eml_v_0[2] = 0.0;
      eml_v_0[5] = 0.0;
      eml_v_0[8] = 1.0;
      eml_e[0] = muDoubleScalarCos(rtB.Gain_k[1]);
      eml_e[3] = 0.0;
      eml_e[6] = -muDoubleScalarSin(rtB.Gain_k[1]);
      eml_e[1] = 0.0;
      eml_e[4] = 1.0;
      eml_e[7] = 0.0;
      eml_e[2] = muDoubleScalarSin(rtB.Gain_k[1]);
      eml_e[5] = 0.0;
      eml_e[8] = muDoubleScalarCos(rtB.Gain_k[1]);
      for (i = 0; i < 3; i++) {
        for (tmp_1 = 0; tmp_1 < 3; tmp_1++) {
          tmp_0[i + 3 * tmp_1] = 0.0;
          tmp_0[i + 3 * tmp_1] = tmp_0[3 * tmp_1 + i] + eml_e[3 * tmp_1] *
            eml_v_0[i];
          tmp_0[i + 3 * tmp_1] = eml_e[3 * tmp_1 + 1] * eml_v_0[i + 3] + tmp_0[3
            * tmp_1 + i];
          tmp_0[i + 3 * tmp_1] = eml_e[3 * tmp_1 + 2] * eml_v_0[i + 6] + tmp_0[3
            * tmp_1 + i];
        }
      }

      eml_v_0[0] = 1.0;
      eml_v_0[3] = 0.0;
      eml_v_0[6] = 0.0;
      eml_v_0[1] = 0.0;
      eml_v_0[4] = muDoubleScalarCos(rtB.Gain_k[0]);
      eml_v_0[7] = muDoubleScalarSin(rtB.Gain_k[0]);
      eml_v_0[2] = 0.0;
      eml_v_0[5] = -muDoubleScalarSin(rtB.Gain_k[0]);
      eml_v_0[8] = muDoubleScalarCos(rtB.Gain_k[0]);
      for (i = 0; i < 3; i++) {
        for (tmp_1 = 0; tmp_1 < 3; tmp_1++) {
          rtB.DCM[i + 3 * tmp_1] = 0.0;
          rtB.DCM[i + 3 * tmp_1] = rtB.DCM[3 * tmp_1 + i] + eml_v_0[3 * tmp_1] *
            tmp_0[i];
          rtB.DCM[i + 3 * tmp_1] = eml_v_0[3 * tmp_1 + 1] * tmp_0[i + 3] +
            rtB.DCM[3 * tmp_1 + i];
          rtB.DCM[i + 3 * tmp_1] = eml_v_0[3 * tmp_1 + 2] * tmp_0[i + 6] +
            rtB.DCM[3 * tmp_1 + i];
        }
      }

      if (ssIsSpecialSampleHit(rtS,2,1,tid)) {
        rtB.TmpRTBAtProductInport2[0] = rtDWork.TmpRTBAtProductInport2_Buffer0[0];
        rtB.TmpRTBAtProductInport2[1] = rtDWork.TmpRTBAtProductInport2_Buffer0[1];
        rtB.TmpRTBAtProductInport2[2] = rtDWork.TmpRTBAtProductInport2_Buffer0[2];
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      for (i = 0; i < 3; i++) {
        rtb_Product[i] = 0.0;
        rtb_Product[i] += rtB.DCM[i] * rtB.TmpRTBAtProductInport2[0];
        rtb_Product[i] += rtB.DCM[i + 3] * rtB.TmpRTBAtProductInport2[1];
        rtb_Product[i] += rtB.DCM[i + 6] * rtB.TmpRTBAtProductInport2[2];
      }

      rtb_jxi = rtb_Product[1] * rtB.v_B_b[2];
      rtB.Sum_n[0] = rtb_jxi - rtb_Product[2] * rtB.v_B_b[1];
      rtB.Sum_n[1] = rtb_Product[2] * rtB.v_B_b[0] - rtb_Product[0] * rtB.v_B_b
        [2];
      rtB.Sum_n[2] = rtb_Product[0] * rtB.v_B_b[1] - rtb_Product[1] * rtB.v_B_b
        [0];
      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        rtB.TmpRTBAtToWorkspace9Inport1[0] = rtB.Sum_n[0];
        rtB.TmpRTBAtToWorkspace9Inport1[1] = rtB.Sum_n[1];
        rtB.TmpRTBAtToWorkspace9Inport1[2] = rtB.Sum_n[2];
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace9_PWORK.LoggedData),
                        rtB.TmpRTBAtToWorkspace9Inport1, 0);
      }
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_v_0[0] = ((muDoubleScalarPower(rtB.xN[3], 2.0) + muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[3] = 2.0 * rtB.xN[3] * rtB.xN[2] + 2.0 * rtB.xN[0] * rtB.xN[1];
      eml_v_0[6] = 2.0 * rtB.xN[0] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[1];
      eml_v_0[1] = 2.0 * rtB.xN[0] * rtB.xN[1] - 2.0 * rtB.xN[3] * rtB.xN[2];
      eml_v_0[4] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) + muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[7] = 2.0 * rtB.xN[3] * rtB.xN[0] + 2.0 * rtB.xN[1] * rtB.xN[2];
      eml_v_0[2] = 2.0 * rtB.xN[3] * rtB.xN[1] + 2.0 * rtB.xN[0] * rtB.xN[2];
      eml_v_0[5] = 2.0 * rtB.xN[1] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[0];
      eml_v_0[8] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) +
        muDoubleScalarPower(rtB.xN[2], 2.0);
      for (i = 0; i < 3; i++) {
        eml_r_B[i] = eml_v_0[i + 6] * rtB.FromFile[2] + (eml_v_0[i + 3] *
          rtB.FromFile[1] + eml_v_0[i] * rtB.FromFile[0]);
      }

      eml_TIO_idx = (eml_r_B[0] * eml_r_B[0] + eml_r_B[1] * eml_r_B[1]) +
        eml_r_B[2] * eml_r_B[2];
      for (i = 0; i < 3; i++) {
        eml_b[i] = tmp_7[i + 6] * eml_r_B[2] + (tmp_7[i + 3] * eml_r_B[1] +
          tmp_7[i] * eml_r_B[0]);
      }

      eml_TIO_idx = muDoubleScalarPower(muDoubleScalarSqrt(eml_TIO_idx), 5.0);
      rtB.tau[0] = (eml_r_B[1] * eml_b[2] - eml_r_B[2] * eml_b[1]) *
        1.195975098E+015 / eml_TIO_idx;
      rtB.tau[1] = (eml_r_B[2] * eml_b[0] - eml_r_B[0] * eml_b[2]) *
        1.195975098E+015 / eml_TIO_idx;
      rtB.tau[2] = (eml_r_B[0] * eml_b[1] - eml_r_B[1] * eml_b[0]) *
        1.195975098E+015 / eml_TIO_idx;
      eml_v_0[0] = ((muDoubleScalarPower(rtB.xN[3], 2.0) + muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[3] = 2.0 * rtB.xN[3] * rtB.xN[2] + 2.0 * rtB.xN[0] * rtB.xN[1];
      eml_v_0[6] = 2.0 * rtB.xN[0] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[1];
      eml_v_0[1] = 2.0 * rtB.xN[0] * rtB.xN[1] - 2.0 * rtB.xN[3] * rtB.xN[2];
      eml_v_0[4] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) + muDoubleScalarPower(rtB.xN[1], 2.0)) -
        muDoubleScalarPower(rtB.xN[2], 2.0);
      eml_v_0[7] = 2.0 * rtB.xN[3] * rtB.xN[0] + 2.0 * rtB.xN[1] * rtB.xN[2];
      eml_v_0[2] = 2.0 * rtB.xN[3] * rtB.xN[1] + 2.0 * rtB.xN[0] * rtB.xN[2];
      eml_v_0[5] = 2.0 * rtB.xN[1] * rtB.xN[2] - 2.0 * rtB.xN[3] * rtB.xN[0];
      eml_v_0[8] = ((muDoubleScalarPower(rtB.xN[3], 2.0) - muDoubleScalarPower
                     (rtB.xN[0], 2.0)) - muDoubleScalarPower(rtB.xN[1], 2.0)) +
        muDoubleScalarPower(rtB.xN[2], 2.0);
      for (i = 0; i < 3; i++) {
        rtB.v_B_d[i] = 0.0;
        rtB.v_B_d[i] = eml_v_0[i] * rtB.FromFile[3] + rtB.v_B_d[i];
        rtB.v_B_d[i] = eml_v_0[i + 3] * rtB.FromFile[4] + rtB.v_B_d[i];
        rtB.v_B_d[i] = eml_v_0[i + 6] * rtB.FromFile[5] + rtB.v_B_d[i];
      }

      eml_TIO_idx = muDoubleScalarSqrt(adcs_v15_integral_Power_nom_dot_g
        (&rtB.v_B_d[0], &rtB.v_B_d[0]));
      eml_r[0] = rtB.v_B_d[0] / eml_TIO_idx;
      eml_r[1] = rtB.v_B_d[1] / eml_TIO_idx;
      eml_r[2] = rtB.v_B_d[2] / eml_TIO_idx;
      eml_x = 0.0;
      memset((void *)&eml_b_0[0], (int32_T)0.0, 18U * sizeof(real_T));
      eml_b_0[0] = 6.7600000000000007E-002;
      eml_b_0[1] = 0.0;
      eml_b_0[2] = 0.0;
      eml_b_0[3] = 0.0;
      eml_b_0[4] = 6.7600000000000007E-002;
      eml_b_0[5] = 0.0;
      eml_b_0[6] = 0.0;
      eml_b_0[7] = 0.0;
      eml_b_0[8] = 6.7600000000000007E-002;
      eml_b_0[9] = -6.7600000000000007E-002;
      eml_b_0[10] = 0.0;
      eml_b_0[11] = 0.0;
      eml_b_0[12] = 0.0;
      eml_b_0[13] = -6.7600000000000007E-002;
      eml_b_0[14] = 0.0;
      eml_b_0[15] = 0.0;
      eml_b_0[16] = 0.0;
      eml_b_0[17] = -6.7600000000000007E-002;
      for (i = 0; i < 6; i++) {
        eml_b_3[0] = eml_b_0[3 * i];
        eml_b_3[1] = eml_b_0[3 * i + 1];
        eml_b_3[2] = eml_b_0[3 * i + 2];
        eml_B = adcs_v15_integral_Power_nom_dot_g(eml_b_3, eml_r);
        if (eml_B > 0.0) {
          eml_x += eml_B;
        }
      }

      eml_TIO_idx = -0.5 * rtP.SFunction_p1 * 0.0 * eml_x * muDoubleScalarPower
        (eml_TIO_idx, 2.0);
      eml_r[0] *= eml_TIO_idx;
      eml_r[1] *= eml_TIO_idx;
      eml_r[2] *= eml_TIO_idx;
      rtB.u_aero[0] = 0.0175 * eml_r[2] - 0.002 * eml_r[1];
      rtB.u_aero[1] = 0.002 * eml_r[0] - 0.002 * eml_r[2];
      rtB.u_aero[2] = 0.002 * eml_r[1] - 0.0175 * eml_r[0];
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[0] =
        rtP.VectorfromCoMtoCoP_inBodyframeyettobefinalized2_Value[0];
      rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[1] =
        rtP.VectorfromCoMtoCoP_inBodyframeyettobefinalized2_Value[1];
      rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[2] =
        rtP.VectorfromCoMtoCoP_inBodyframeyettobefinalized2_Value[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      if (adcs_v15_integral_Power_nom_norm_l(&rtB.v_B[0]) == 0.0) {
        rtB.solar_drag[0] = 1.0;
        rtB.solar_drag[1] = 0.0;
        rtB.solar_drag[2] = 0.0;
      } else {
        eml_TIO_idx = adcs_v15_integral_Power_nom_norm_l(&rtB.v_B[0]);
        rtB.solar_drag[0] = rtB.v_B[0] / eml_TIO_idx;
        rtB.solar_drag[1] = rtB.v_B[1] / eml_TIO_idx;
        rtB.solar_drag[2] = rtB.v_B[2] / eml_TIO_idx;
      }

      eml_TIO_idx = 0.0;
      memset((void *)&eml_b_0[0], (int32_T)0.0, 18U * sizeof(real_T));
      eml_b_0[0] = 6.7600000000000007E-002;
      eml_b_0[1] = 0.0;
      eml_b_0[2] = 0.0;
      eml_b_0[3] = 0.0;
      eml_b_0[4] = 6.7600000000000007E-002;
      eml_b_0[5] = 0.0;
      eml_b_0[6] = 0.0;
      eml_b_0[7] = 0.0;
      eml_b_0[8] = 6.7600000000000007E-002;
      eml_b_0[9] = -6.7600000000000007E-002;
      eml_b_0[10] = 0.0;
      eml_b_0[11] = 0.0;
      eml_b_0[12] = 0.0;
      eml_b_0[13] = -6.7600000000000007E-002;
      eml_b_0[14] = 0.0;
      eml_b_0[15] = 0.0;
      eml_b_0[16] = 0.0;
      eml_b_0[17] = -6.7600000000000007E-002;
      for (i = 0; i < 6; i++) {
        eml_r[0] = eml_b_0[3 * i];
        eml_r[1] = eml_b_0[3 * i + 1];
        eml_r[2] = eml_b_0[3 * i + 2];
        eml_x = (eml_r[0] * rtB.solar_drag[0] + eml_r[1] * rtB.solar_drag[1]) +
          eml_r[2] * rtB.solar_drag[2];
        if (eml_x > 0.0) {
          eml_TIO_idx += eml_x;
        }
      }

      eml_TIO_idx = (-eml_TIO_idx) * 1.4 * 4.4E-006;
      rtB.solar_drag[0] = eml_TIO_idx * rtB.solar_drag[0] * rtB.FromFile2;
      rtB.solar_drag[1] = eml_TIO_idx * rtB.solar_drag[1] * rtB.FromFile2;
      rtB.solar_drag[2] = eml_TIO_idx * rtB.solar_drag[2] * rtB.FromFile2;
      rtb_jxi = rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[1] *
        rtB.solar_drag[0];
      rtB.Sum_i[0] = rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[1] *
        rtB.solar_drag[2] - rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2
        [2] * rtB.solar_drag[1];
      rtB.Sum_i[1] = rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[2] *
        rtB.solar_drag[0] - rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2
        [0] * rtB.solar_drag[2];
      rtB.Sum_i[2] = rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2[0] *
        rtB.solar_drag[1] - rtb_jxi;
      rtB.Sum_lf[0] = (rtB.tau[0] + rtB.u_aero[0]) + rtB.Sum_i[0];
      rtB.Sum_og[0] = rtB.Sum_lf[0] + rtB.Sum_n[0];
      eml_r[0] = rtB.xN[4];
      rtB.Sum_lf[1] = (rtB.tau[1] + rtB.u_aero[1]) + rtB.Sum_i[1];
      rtB.Sum_og[1] = rtB.Sum_lf[1] + rtB.Sum_n[1];
      eml_r[1] = rtB.xN[5];
      rtB.Sum_lf[2] = (rtB.tau[2] + rtB.u_aero[2]) + rtB.Sum_i[2];
      rtB.Sum_og[2] = rtB.Sum_lf[2] + rtB.Sum_n[2];
      eml_r[2] = rtB.xN[6];
      for (i = 0; i < 3; i++) {
        eml_b_1[i] = tmp_7[i + 6] * eml_r[2] + (tmp_7[i + 3] * eml_r[1] +
          tmp_7[i] * eml_r[0]);
      }

      eml_q_BI[0] = 0.0;
      eml_q_BI[4] = eml_r[2];
      eml_q_BI[8] = -eml_r[1];
      eml_q_BI[12] = eml_r[0];
      eml_q_BI[1] = -eml_r[2];
      eml_q_BI[5] = 0.0;
      eml_q_BI[9] = eml_r[0];
      eml_q_BI[13] = eml_r[1];
      eml_q_BI[2] = eml_r[1];
      eml_q_BI[6] = -eml_r[0];
      eml_q_BI[10] = 0.0;
      eml_q_BI[14] = eml_r[2];
      eml_q_BI[3] = -eml_r[0];
      eml_q_BI[7] = -eml_r[1];
      eml_q_BI[11] = -eml_r[2];
      eml_q_BI[15] = 0.0;
      for (i = 0; i < 4; i++) {
        tmp_2[i << 2] = eml_q_BI[i << 2] * 0.5;
        tmp_2[1 + (i << 2)] = eml_q_BI[(i << 2) + 1] * 0.5;
        tmp_2[2 + (i << 2)] = eml_q_BI[(i << 2) + 2] * 0.5;
        tmp_2[3 + (i << 2)] = eml_q_BI[(i << 2) + 3] * 0.5;
      }

      eml_q_idx_0 = rtB.Sum_og[0] - (eml_r[1] * eml_b_1[2] - eml_r[2] * eml_b_1
        [1]);
      eml_TIO_idx = rtB.Sum_og[1] - (eml_r[2] * eml_b_1[0] - eml_r[0] * eml_b_1
        [2]);
      eml_x = rtB.Sum_og[2] - (eml_r[0] * eml_b_1[1] - eml_r[1] * eml_b_1[0]);
      for (i = 0; i < 4; i++) {
        eml_TIO_idx_0 = tmp_2[i + 12] * rtB.xN[3] + (tmp_2[i + 8] * rtB.xN[2] +
          (tmp_2[i + 4] * rtB.xN[1] + tmp_2[i] * rtB.xN[0]));
        tmp_3[i] = eml_TIO_idx_0;
      }

      for (i = 0; i < 3; i++) {
        eml_r[i] = tmp_6[i + 6] * eml_x + (tmp_6[i + 3] * eml_TIO_idx + tmp_6[i]
          * eml_q_idx_0);
      }

      rtB.xdot[0] = tmp_3[0];
      rtB.xdot[1] = tmp_3[1];
      rtB.xdot[2] = tmp_3[2];
      rtB.xdot[3] = tmp_3[3];
      rtB.xdot[4] = eml_r[0];
      rtB.xdot[5] = eml_r[1];
      rtB.xdot[6] = eml_r[2];
      if (ssIsSpecialSampleHit(rtS,3,0,tid)) {
        rtB.TmpRTBAtw_real1Inport1[0] = rtB.tau[0];
        rtB.TmpRTBAtw_real1Inport1[1] = rtB.tau[1];
        rtB.TmpRTBAtw_real1Inport1[2] = rtB.tau[2];
      }
    }

    if (ssIsSampleHit(rtS, 3, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,3,0,tid)) {
      rtB.TmpRTBAtw_real2Inport1[0] = rtB.Sum_lf[0];
      rtB.TmpRTBAtw_real2Inport1[1] = rtB.Sum_lf[1];
      rtB.TmpRTBAtw_real2Inport1[2] = rtB.Sum_lf[2];
    }

    if (ssIsSampleHit(rtS, 3, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,3,0,tid)) {
      rtB.TmpRTBAtw_real3Inport1[0] = rtB.u_aero[0];
      rtB.TmpRTBAtw_real3Inport1[1] = rtB.u_aero[1];
      rtB.TmpRTBAtw_real3Inport1[2] = rtB.u_aero[2];
    }

    if (ssIsSampleHit(rtS, 3, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,3,0,tid)) {
      rtB.TmpRTBAtw_real4Inport1[0] = rtB.Sum_i[0];
      rtB.TmpRTBAtw_real4Inport1[1] = rtB.Sum_i[1];
      rtB.TmpRTBAtw_real4Inport1[2] = rtB.Sum_i[2];
    }

    if (ssIsSampleHit(rtS, 3, tid)) {
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtb_Abs[0] = rtP.PWM_Interval * muDoubleScalarRound
        ((rtB.TorquerCurrentSaturation[0]/(rtP.PWM_Interval)));
      rtb_Abs[1] = rtP.PWM_Interval * muDoubleScalarRound
        ((rtB.TorquerCurrentSaturation[1]/(rtP.PWM_Interval)));
      rtb_Abs[2] = rtP.PWM_Interval * muDoubleScalarRound
        ((rtB.TorquerCurrentSaturation[2]/(rtP.PWM_Interval)));
      rtB.Gain2[0] = rtP.Gain2_Gain * rtb_Abs[0];
      rtB.Gain2[1] = rtP.Gain2_Gain * rtb_Abs[1];
      rtB.Gain2[2] = rtP.Gain2_Gain * rtb_Abs[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Clock = ssGetT(rtS);
      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        rtB.TmpRTBAtToWorkspace15Inport1 = rtB.Clock;
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
      if (ssGetLogOutput(rtS)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (rtDWork.ToWorkspace15_PWORK.LoggedData),
                        &rtB.TmpRTBAtToWorkspace15Inport1, 0);
      }
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_l4[0] = rtP.Constant_Value_gt[0];
      rtB.Constant_l4[1] = rtP.Constant_Value_gt[1];
      rtB.Constant_l4[2] = rtP.Constant_Value_gt[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_TIO_idx = ((rtB.Constant_l4[0] * rtB.v_B[0] + rtB.Constant_l4[1] *
                      rtB.v_B[1]) + rtB.Constant_l4[2] * rtB.v_B[2]) *
        rtB.FromFile2;
      rtB.Gain_f = rtP.Gain1_Gain * rt_SATURATE(eml_TIO_idx,
        rtP.Saturation_LowerSat_c1, rtP.Saturation_UpperSat_k) * rtP.Gain_Gain_j;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_n[0] = rtP.Constant_Value_mt[0];
      rtB.Constant_n[1] = rtP.Constant_Value_mt[1];
      rtB.Constant_n[2] = rtP.Constant_Value_mt[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_TIO_idx = ((rtB.Constant_n[0] * rtB.v_B[0] + rtB.Constant_n[1] *
                      rtB.v_B[1]) + rtB.Constant_n[2] * rtB.v_B[2]) *
        rtB.FromFile2;
      rtB.Gain_p = rtP.Gain1_Gain_c * rt_SATURATE(eml_TIO_idx,
        rtP.Saturation_LowerSat_p, rtP.Saturation_UpperSat_ku) *
        rtP.Gain_Gain_es;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_jb[0] = rtP.Constant_Value_kt[0];
      rtB.Constant_jb[1] = rtP.Constant_Value_kt[1];
      rtB.Constant_jb[2] = rtP.Constant_Value_kt[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_TIO_idx = ((rtB.Constant_jb[0] * rtB.v_B[0] + rtB.Constant_jb[1] *
                      rtB.v_B[1]) + rtB.Constant_jb[2] * rtB.v_B[2]) *
        rtB.FromFile2;
      rtB.Gain_d = rtP.Gain1_Gain_j * rt_SATURATE(eml_TIO_idx,
        rtP.Saturation_LowerSat_k, rtP.Saturation_UpperSat_i) * rtP.Gain_Gain_lw;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_m[0] = rtP.Constant_Value_b2[0];
      rtB.Constant_m[1] = rtP.Constant_Value_b2[1];
      rtB.Constant_m[2] = rtP.Constant_Value_b2[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_TIO_idx = ((rtB.Constant_m[0] * rtB.v_B[0] + rtB.Constant_m[1] *
                      rtB.v_B[1]) + rtB.Constant_m[2] * rtB.v_B[2]) *
        rtB.FromFile2;
      rtB.Gain_l = rtP.Gain1_Gain_f * rt_SATURATE(eml_TIO_idx,
        rtP.Saturation_LowerSat_aj, rtP.Saturation_UpperSat_c) *
        rtP.Gain_Gain_pc;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_a[0] = rtP.Constant_Value_f[0];
      rtB.Constant_a[1] = rtP.Constant_Value_f[1];
      rtB.Constant_a[2] = rtP.Constant_Value_f[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_TIO_idx = ((rtB.Constant_a[0] * rtB.v_B[0] + rtB.Constant_a[1] *
                      rtB.v_B[1]) + rtB.Constant_a[2] * rtB.v_B[2]) *
        rtB.FromFile2;
      rtB.Gain_b = rtP.Gain1_Gain_h * rt_SATURATE(eml_TIO_idx,
        rtP.Saturation_LowerSat_p3, rtP.Saturation_UpperSat_bn) *
        rtP.Gain_Gain_in;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.Constant_f2[0] = rtP.Constant_Value_h2[0];
      rtB.Constant_f2[1] = rtP.Constant_Value_h2[1];
      rtB.Constant_f2[2] = rtP.Constant_Value_h2[2];
    }

    if (ssIsContinuousTask(rtS, tid)) {
      eml_TIO_idx = ((rtB.Constant_f2[0] * rtB.v_B[0] + rtB.Constant_f2[1] *
                      rtB.v_B[1]) + rtB.Constant_f2[2] * rtB.v_B[2]) *
        rtB.FromFile2;
      rtB.Gain_m = rtP.Gain1_Gain_hl * rt_SATURATE(eml_TIO_idx,
        rtP.Saturation_LowerSat_nl, rtP.Saturation_UpperSat_d) *
        rtP.Gain_Gain_f2;
      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        rtB.TmpRTBAtScope11Inport1[0] = rtB.Gain_f;
        rtB.TmpRTBAtScope11Inport1[1] = rtB.Gain_p;
        rtB.TmpRTBAtScope11Inport1[2] = rtB.Gain_d;
        rtB.TmpRTBAtScope11Inport1[3] = rtB.Gain_l;
        rtB.TmpRTBAtScope11Inport1[4] = rtB.Gain_b;
        rtB.TmpRTBAtScope11Inport1[5] = rtB.Gain_m;
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Gain1[0] = rtP.Gain1_Gain_g * rtB.Gain_f;
      rtB.Gain1[1] = rtP.Gain1_Gain_g * rtB.Gain_p;
      rtB.Gain1[2] = rtP.Gain1_Gain_g * rtB.Gain_d;
      rtB.Gain1[3] = rtP.Gain1_Gain_g * rtB.Gain_l;
      rtB.Gain1[4] = rtP.Gain1_Gain_g * rtB.Gain_b;
      rtB.Gain1[5] = rtP.Gain1_Gain_g * rtB.Gain_m;
      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        for (i = 0; i < 6; i++) {
          rtB.TmpRTBAtScope12Inport1[i] = rtB.Gain1[i];
        }
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.AddingSolarPower = ((((rtB.Gain1[0] + rtB.Gain1[1]) + rtB.Gain1[2]) +
        rtB.Gain1[3]) + rtB.Gain1[4]) + rtB.Gain1[5];
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.IntegerDelay = rtDWork.IntegerDelay_X;
      rtB.PowerDistributionLosses = rtP.PowerDistributionLosses_Value;
      rtB.Magnetometer = rtP.Magnetometer_Value;
      if (ssIsSpecialSampleHit(rtS,2,1,tid)) {
        rtB.TmpRTBAtAddingPowerConsumedInport3 =
          rtDWork.TmpRTBAtAddingPowerConsumedInport3_Buffer0;
      }

      rtB.Uplink = rtP.Uplink_Value;
      rtB.Beaconandamplifier = rtP.Beaconandamplifier_Value;
      rtB.OBC = rtP.OBC_Value;
      rtB.SunSensor = rtP.SunSensor_Value;
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Clock2 = ssGetT(rtS);
      eml_TIO_idx = (1.8225E+007 + rtB.Clock2) * 1.0027379093500000E+000 *
        7.2940705438520400E-005;
      eml_v_0[0] = muDoubleScalarCos(eml_TIO_idx);
      eml_v_0[3] = muDoubleScalarSin(eml_TIO_idx);
      eml_v_0[6] = 0.0;
      eml_v_0[1] = -muDoubleScalarSin(eml_TIO_idx);
      eml_v_0[4] = muDoubleScalarCos(eml_TIO_idx);
      eml_v_0[7] = 0.0;
      eml_v_0[2] = 0.0;
      eml_v_0[5] = 0.0;
      eml_v_0[8] = 1.0;
      for (i = 0; i < 3; i++) {
        rtB.r_ECEF[i] = 0.0;
        rtB.r_ECEF[i] = eml_v_0[i] * rtB.FromFile[0] + rtB.r_ECEF[i];
        rtB.r_ECEF[i] = eml_v_0[i + 3] * rtB.FromFile[1] + rtB.r_ECEF[i];
        rtB.r_ECEF[i] = eml_v_0[i + 6] * rtB.FromFile[2] + rtB.r_ECEF[i];
      }

      eml_TIO_idx = adcs_v15_integral_Power_nom_norm_j(&rtB.r_ECEF[0]);
      eml_x = muDoubleScalarAtan2(rtB.r_ECEF[1], rtB.r_ECEF[0]);
      if (eml_x < 0.0) {
        eml_x += 6.2831853071795862E+000;
      }

      rtB.Latitutde = muDoubleScalarAsin(rtB.r_ECEF[2] / eml_TIO_idx) * 180.0 /
        3.1415926535897931E+000;
      rtB.Longitude = eml_x * 180.0 / 3.1415926535897931E+000;
      rtB.Altitude = eml_TIO_idx - 6.371E+006;
      rtB.flag_france = 0.0;
      rtB.flag_india = 0.0;
      if (muDoubleScalarCos(rtB.Latitutde * 3.1415926535897931E+000 / 180.0) *
          muDoubleScalarPower(rtB.Longitude - 82.7666, 2.0) +
          muDoubleScalarPower(rtB.Latitutde - 22.5833, 2.0) < 625.0) {
        i = 1;
        rtB.flag_india = 1.0;
      } else if (muDoubleScalarCos(rtB.Latitutde * 3.1415926535897931E+000 /
                  180.0) * muDoubleScalarPower(rtB.Longitude - 2.33, 2.0) +
                 muDoubleScalarPower(rtB.Latitutde - 48.8, 2.0) < 100.0) {
        i = 1;
        rtB.flag_france = 1.0;
      } else {
        i = 0;
      }

      rtB.Downlink_power = (real_T)i * 2.6;
      rtB.flag_downlink = (real_T)i;
      rtB.AddingPowerConsumed = ((((((rtB.PowerDistributionLosses +
        rtB.Magnetometer) + rtB.TmpRTBAtAddingPowerConsumedInport3) + rtB.Uplink)
        + rtB.Beaconandamplifier) + rtB.OBC) + rtB.SunSensor) +
        rtB.Downlink_power;
      if (rtB.IntegerDelay > 3.0) {
        i = 1;
      } else {
        i = 0;
      }

      if (i == 1) {
        rtB.pow_drawn = rtB.AddingPowerConsumed;
      } else {
        rtB.pow_drawn = 0.0;
      }

      rtB.AddingSolarPower1 = rtB.AddingSolarPower - rtB.pow_drawn;
      rtB.Gain2_c = rtP.Gain2_Gain_p * rtB.AddingSolarPower1;
      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        rtB.TmpRTBAtScope13Inport1 = rtB.Gain2_c;
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope14Inport1 = rtB.flag_downlink;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Clock_k = ssGetT(rtS);
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtB.IntegerDelay3 = rtDWork.IntegerDelay3_X;
      rtB.IntegerDelay2 = rtDWork.IntegerDelay2_X;
      rtB.IntegerDelay1 = rtDWork.IntegerDelay1_X;
      rtB.IntegerDelay4 = rtDWork.IntegerDelay4_X;
    }

    if (ssIsContinuousTask(rtS, tid)) {
      if (rtB.Clock_k < 0.15) {
        rtB.Batt_cap = 2000.0;
        rtB.current = 0.0;
        rtB.VBat = adcs_v15_integral_Power_nom_isro_battery(200.0, 0.0, 0.08);
      } else if (rtB.Gain2_c < 0.0) {
        rtB.current = rtB.Gain2_c / (rtP.SFunction_p1_i * 2.0 *
          rtB.IntegerDelay4);
        rtB.Batt_cap = rtB.Gain2_c / (21.6 * rtB.IntegerDelay4) +
          rtB.IntegerDelay3;
        rtB.VBat = adcs_v15_integral_Power_nom_isro_battery(2200.0 -
          rtB.Batt_cap, rtB.current, 0.08);
      } else if (rtB.IntegerDelay2 == 1.0) {
        rtB.current = rtB.Gain2_c / (rtP.SFunction_p1_i * 2.0 *
          rtB.IntegerDelay4);
        rtB.Batt_cap = rtB.Gain2_c / (21.6 * rtB.IntegerDelay4) +
          rtB.IntegerDelay3;
        rtB.VBat = adcs_v15_integral_Power_nom_isro_battery(2200.0 -
          rtB.Batt_cap, rtB.current, 0.08);
      } else {
        rtB.current = 0.0;
        rtB.Batt_cap = rtB.IntegerDelay3;
        rtB.VBat = adcs_v15_integral_Power_nom_isro_battery(2200.0 -
          rtB.IntegerDelay3, 0.0, 0.08);
      }

      if (rtB.VBat < 3.95) {
        rtB.Flag_charge = 1.0;
      } else if (rtB.VBat > 4.25) {
        rtB.Flag_charge = -2.0;
      } else {
        rtB.Flag_charge = rtB.IntegerDelay2;
      }

      rtB.frac_Batt_cap = rtB.Batt_cap / 2199.0;
      if (rtB.VBat < 3.5) {
        rtB.Flag_discharge = 1.0;
      } else {
        rtB.Flag_discharge = 0.0;
      }

      if (ssIsSpecialSampleHit(rtS,4,0,tid)) {
        rtB.TmpRTBAtScope15Inport1 = rtB.VBat;
      }
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope16Inport1 = rtB.frac_Batt_cap;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope17Inport1 = rtB.Flag_charge;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope18Inport1 = rtB.flag_france;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope19Inport1 = rtB.flag_india;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid) && ssIsSpecialSampleHit(rtS,4,0,tid)) {
      rtB.TmpRTBAtScope20Inport1 = rtB.Batt_cap;
    }

    if (ssIsSampleHit(rtS, 4, tid)) {
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      if (ssGetLogOutput(rtS) && !(++rtDWork.ToFile_IWORK.Decimation % 1) &&
          (rtDWork.ToFile_IWORK.Count*2)+1 < 100000000 ) {
        real_T u[2];
        FILE *fp = (FILE *) rtDWork.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          rtDWork.ToFile_IWORK.Decimation = 0;
          u[0] = ssGetTaskTime(rtS,tid);
          u[1] = rtB.Latitutde;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            ssSetErrorStatus(rtS, "Error writing to MAT-file Latitude.mat");
            return;
          }

          if (((++rtDWork.ToFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Latitude.mat.\n");
          }
        }
      }

      if (ssGetLogOutput(rtS) && !(++rtDWork.ToFile1_IWORK.Decimation % 1) &&
          (rtDWork.ToFile1_IWORK.Count*2)+1 < 100000000 ) {
        real_T u[2];
        FILE *fp = (FILE *) rtDWork.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          rtDWork.ToFile1_IWORK.Decimation = 0;
          u[0] = ssGetTaskTime(rtS,tid);
          u[1] = rtB.Longitude;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            ssSetErrorStatus(rtS, "Error writing to MAT-file Longitude.mat");
            return;
          }

          if (((++rtDWork.ToFile1_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Longitude.mat.\n");
          }
        }
      }

      if (ssGetLogOutput(rtS) && !(++rtDWork.ToFile2_IWORK.Decimation % 1) &&
          (rtDWork.ToFile2_IWORK.Count*2)+1 < 100000000 ) {
        real_T u[2];
        FILE *fp = (FILE *) rtDWork.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          rtDWork.ToFile2_IWORK.Decimation = 0;
          u[0] = ssGetTaskTime(rtS,tid);
          u[1] = rtB.flag_downlink;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            ssSetErrorStatus(rtS, "Error writing to MAT-file flag_downlink.mat");
            return;
          }

          if (((++rtDWork.ToFile2_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file flag_downlink.mat.\n");
          }
        }
      }

      if (ssGetLogOutput(rtS) && !(++rtDWork.ToFile3_IWORK.Decimation % 1) &&
          (rtDWork.ToFile3_IWORK.Count*2)+1 < 100000000 ) {
        real_T u[2];
        FILE *fp = (FILE *) rtDWork.ToFile3_PWORK.FilePtr;
        if (fp != (NULL)) {
          rtDWork.ToFile3_IWORK.Decimation = 0;
          u[0] = ssGetTaskTime(rtS,tid);
          u[1] = rtB.flag_france;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            ssSetErrorStatus(rtS, "Error writing to MAT-file flag_france.mat");
            return;
          }

          if (((++rtDWork.ToFile3_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file flag_france.mat.\n");
          }
        }
      }

      if (ssGetLogOutput(rtS) && !(++rtDWork.ToFile4_IWORK.Decimation % 1) &&
          (rtDWork.ToFile4_IWORK.Count*2)+1 < 100000000 ) {
        real_T u[2];
        FILE *fp = (FILE *) rtDWork.ToFile4_PWORK.FilePtr;
        if (fp != (NULL)) {
          rtDWork.ToFile4_IWORK.Decimation = 0;
          u[0] = ssGetTaskTime(rtS,tid);
          u[1] = rtB.flag_india;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            ssSetErrorStatus(rtS, "Error writing to MAT-file flag_india.mat");
            return;
          }

          if (((++rtDWork.ToFile4_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file flag_india.mat.\n");
          }
        }
      }
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtb_Abs[0] = muDoubleScalarAbs(rtB.TorquerCurrentSaturation[0]);
      rtb_Abs[1] = muDoubleScalarAbs(rtB.TorquerCurrentSaturation[1]);
      rtb_Abs[2] = muDoubleScalarAbs(rtB.TorquerCurrentSaturation[2]);
      rtB.VoltageofMagnetorquer = ((rtb_Abs[0] + rtb_Abs[1]) + rtb_Abs[2]) *
        rtP.VoltageofMagnetorquer_Gain;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
    }

    if (ssIsContinuousTask(rtS, tid)) {
      rtB.Integrator_i = rtX.Integrator_CSTATE_d;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
    }
  }
}

void MdlUpdate(int_T tid)
{
  {
    int32_T loopVar_i;
    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput = rt_NormalRand(&rtDWork.RandSeed) *
        rtP.RandomNumber_StdDev + rtP.RandomNumber_Mean;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput_f = rt_NormalRand(&rtDWork.RandSeed_b) *
        rtP.RandomNumber_StdDev_j + rtP.RandomNumber_Mean_o;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput_h = rt_NormalRand(&rtDWork.RandSeed_e) *
        rtP.RandomNumber_StdDev_o + rtP.RandomNumber_Mean_j;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput_a = rt_NormalRand(&rtDWork.RandSeed_g) *
        rtP.RandomNumber_StdDev_jg + rtP.RandomNumber_Mean_jb;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput_g = rt_NormalRand(&rtDWork.RandSeed_br) *
        rtP.RandomNumber_StdDev_m + rtP.RandomNumber_Mean_k;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput_o = rt_NormalRand(&rtDWork.RandSeed_ef) *
        rtP.RandomNumber_StdDev_op + rtP.RandomNumber_Mean_n;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.NextOutput_gv = rt_NormalRand(&rtDWork.RandSeed_brc) *
        rtP.RandomNumber_StdDev_i + rtP.RandomNumber_Mean_oj;
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtDWork.IntegerDelay1_X_d[0] = rtB.w_l[0];
      rtDWork.IntegerDelay1_X_d[1] = rtB.w_l[1];
      rtDWork.IntegerDelay1_X_d[2] = rtB.w_l[2];
      rtDWork.IntegerDelay_X_l[0] = rtB.q_BO_est[0];
      rtDWork.IntegerDelay_X_l[1] = rtB.q_BO_est[1];
      rtDWork.IntegerDelay_X_l[2] = rtB.q_BO_est[2];
      rtDWork.IntegerDelay_X_l[3] = rtB.q_BO_est[3];
      for (loopVar_i = 0; loopVar_i < 299; loopVar_i++) {
        rtDWork.IntegerDelay_X_e[loopVar_i] = rtDWork.IntegerDelay_X_e[loopVar_i
          + 1];
      }

      rtDWork.IntegerDelay_X_e[299] = rtB.light_est;
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtDWork.UnitDelay1_DSTATE_c = rtB.N;
      rtDWork.UnitDelay_DSTATE = rtB.t_now;
      rtDWork.IntegerDelay_X_i[0] = rtB.TmpRTBAtControlLawInport1[0];
      rtDWork.UnitDelay1_DSTATE[0] = rtB.ieu[0];
      rtDWork.TmpRTBAtProductInport2_Buffer0[0] = rtB.Gain2[0];
      rtDWork.IntegerDelay_X_i[1] = rtB.TmpRTBAtControlLawInport1[1];
      rtDWork.UnitDelay1_DSTATE[1] = rtB.ieu[1];
      rtDWork.TmpRTBAtProductInport2_Buffer0[1] = rtB.Gain2[1];
      rtDWork.IntegerDelay_X_i[2] = rtB.TmpRTBAtControlLawInport1[2];
      rtDWork.UnitDelay1_DSTATE[2] = rtB.ieu[2];
      rtDWork.TmpRTBAtProductInport2_Buffer0[2] = rtB.Gain2[2];
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.IntegerDelay_X = rtB.VBat;
    }

    if (ssIsSampleHit(rtS, 2, tid)) {
      rtDWork.TmpRTBAtAddingPowerConsumedInport3_Buffer0 =
        rtB.VoltageofMagnetorquer;
    }

    if (ssIsSampleHit(rtS, 1, tid)) {
      rtDWork.IntegerDelay3_X = rtB.Batt_cap;
      rtDWork.IntegerDelay2_X = rtB.Flag_charge;
      rtDWork.IntegerDelay1_X = rtB.Flag_discharge;
      rtDWork.IntegerDelay4_X = rtB.VBat;
    }
  }
}

void MdlDerivatives(void)
{
  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE[i] = rtB.xdot[i];
    }

    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_d = rtB.current;
  }
}

void MdlProjection(void)
{
}

void MdlInitSystemMatrices(void)
{
}

void MdlTerminate(void)
{
  if (adcs_v15_integral_Power_nom_gblFrFInfo[0].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[0].tuDataMatrix);
  }

  if (adcs_v15_integral_Power_nom_gblFrFInfo[1].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[1].tuDataMatrix);
  }

  if (adcs_v15_integral_Power_nom_gblFrFInfo[2].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[2].tuDataMatrix);
  }

  if (adcs_v15_integral_Power_nom_gblFrFInfo[3].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[3].tuDataMatrix);
  }

  if (adcs_v15_integral_Power_nom_gblFrFInfo[4].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[4].tuDataMatrix);
  }

  if (adcs_v15_integral_Power_nom_gblFrFInfo[5].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[5].tuDataMatrix);
  }

  if (adcs_v15_integral_Power_nom_gblFrFInfo[6].tuDataMatrix != (NULL)) {
    rt_FREE(adcs_v15_integral_Power_nom_gblFrFInfo[6].tuDataMatrix);
  }

  {
    FILE *fp = (FILE *) rtDWork.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "Latitude.mat";
      rt_RAccelAddToFileSuffix(&fileName);
      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file Latitude.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error reopening MAT-file Latitude.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, rtDWork.ToFile_IWORK.Count, "ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing header for ans to MAT-file Latitude.mat");
      }

      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file Latitude.mat");
        return;
      }

      rtDWork.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  {
    FILE *fp = (FILE *) rtDWork.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "Longitude.mat";
      rt_RAccelAddToFileSuffix(&fileName);
      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file Longitude.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error reopening MAT-file Longitude.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, rtDWork.ToFile1_IWORK.Count, "ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing header for ans to MAT-file Longitude.mat");
      }

      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file Longitude.mat");
        return;
      }

      rtDWork.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  {
    FILE *fp = (FILE *) rtDWork.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "flag_downlink.mat";
      rt_RAccelAddToFileSuffix(&fileName);
      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file flag_downlink.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error reopening MAT-file flag_downlink.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, rtDWork.ToFile2_IWORK.Count, "ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing header for ans to MAT-file flag_downlink.mat");
      }

      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file flag_downlink.mat");
        return;
      }

      rtDWork.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  {
    FILE *fp = (FILE *) rtDWork.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "flag_france.mat";
      rt_RAccelAddToFileSuffix(&fileName);
      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file flag_france.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error reopening MAT-file flag_france.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, rtDWork.ToFile3_IWORK.Count, "ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing header for ans to MAT-file flag_france.mat");
      }

      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file flag_france.mat");
        return;
      }

      rtDWork.ToFile3_PWORK.FilePtr = (NULL);
    }
  }

  {
    FILE *fp = (FILE *) rtDWork.ToFile4_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "flag_india.mat";
      rt_RAccelAddToFileSuffix(&fileName);
      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file flag_india.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        ssSetErrorStatus(rtS, "Error reopening MAT-file flag_india.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, rtDWork.ToFile4_IWORK.Count, "ans")) {
        ssSetErrorStatus(rtS,
                         "Error writing header for ans to MAT-file flag_india.mat");
      }

      if (fclose(fp) == EOF) {
        ssSetErrorStatus(rtS, "Error closing MAT-file flag_india.mat");
        return;
      }

      rtDWork.ToFile4_PWORK.FilePtr = (NULL);
    }
  }
}

void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 8);
  ssSetNumY(rtS, 0);
  ssSetNumU(rtS, 0);
  ssSetDirectFeedThrough(rtS, 0);
  ssSetNumSampleTimes(rtS, 5);
  ssSetNumBlocks(rtS, 345);
  ssSetNumBlockIO(rtS, 180);
  ssSetNumBlockParams(rtS, 186);
}

void MdlInitializeSampleTimes(void)
{
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.1);
  ssSetSampleTime(rtS, 2, 2.0);
  ssSetSampleTime(rtS, 3, 5.0);
  ssSetSampleTime(rtS, 4, 6.0);
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
  ssSetOffsetTime(rtS, 2, 0.0);
  ssSetOffsetTime(rtS, 3, 0.0);
  ssSetOffsetTime(rtS, 4, 0.0);
}

void raccel_set_checksum(SimStruct *rtS)
{
  ssSetChecksumVal(rtS, 0, 3628094623U);
  ssSetChecksumVal(rtS, 1, 1092416540U);
  ssSetChecksumVal(rtS, 2, 2863338279U);
  ssSetChecksumVal(rtS, 3, 316320258U);
}

SimStruct * raccel_register_model(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS,0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo,0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
      }
    }

    mdlSampleHits[0] = 1;
    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  {
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    (void) memset((void *)&mdlPerTaskSampleHits[0],0,
                  5 * 5 * sizeof(int_T));
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_MULTITASKING);

  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB),0,
                  sizeof(BlockIO));
  }

  ssSetDefaultParam(rtS, (real_T *) &rtP);

  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates));
  }

  {
    void *dwork = (void *) &rtDWork;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(D_Work));
  }

  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];
    dtInfo.B = &rtBTransTable;
    dtInfo.P = &rtPTransTable;
  }

  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "adcs_v15_integral_Power_nom");
  ssSetPath(rtS, "adcs_v15_integral_Power_nom");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 1.2E+005);
  ssSetStepSize(rtS, 0.1);
  ssSetFixedStepSize(rtS, 0.1);

  {
    static RTWLogInfo rt_DataLoggingInfo;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  {
    {
      static int_T rt_LoggedStateWidths[] = {
        7,
        1,
        1,
        1,
        1,
        1,
        1,
        3,
        4,
        300,
        3,
        3,
        1,
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        7,
        1,
        1,
        1,
        1,
        1,
        1,
        3,
        4,
        300,
        3,
        3,
        1,
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "CSTATE",
        "CSTATE",
        "X",
        "X",
        "X",
        "X",
        "X",
        "X",
        "X",
        "X",
        "X",
        "DSTATE",
        "DSTATE",
        "DSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "adcs_v15_integral_Power_nom/Integrator",
        "adcs_v15_integral_Power_nom/PowerD0D/battery_DOD/Integrator",
        "adcs_v15_integral_Power_nom/PowerD0D/Integer Delay",
        "adcs_v15_integral_Power_nom/PowerD0D/Integer Delay3",
        "adcs_v15_integral_Power_nom/PowerD0D/Integer Delay2",
        "adcs_v15_integral_Power_nom/PowerD0D/Integer Delay1",
        "adcs_v15_integral_Power_nom/PowerD0D/Integer Delay4",
        "adcs_v15_integral_Power_nom/q -> w/Integer Delay1",
        "adcs_v15_integral_Power_nom/q -> w/Integer Delay",
        "adcs_v15_integral_Power_nom/q -> w/Subsystem6/Integer Delay",
        "adcs_v15_integral_Power_nom/Control Law/Integer Delay",
        "adcs_v15_integral_Power_nom/Control Law/Unit Delay1",
        "adcs_v15_integral_Power_nom/Control Law/Switching Algorithm/Unit Delay1",
        "adcs_v15_integral_Power_nom/Control Law/Switching Algorithm/Unit Delay"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        14,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[14];
      rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)&rtX.Integrator_CSTATE[0];
      rt_LoggedStateSignalPtrs[1] = (void*)&rtX.Integrator_CSTATE_d;
      rt_LoggedStateSignalPtrs[2] = (void*)&rtDWork.IntegerDelay_X;
      rt_LoggedStateSignalPtrs[3] = (void*)&rtDWork.IntegerDelay3_X;
      rt_LoggedStateSignalPtrs[4] = (void*)&rtDWork.IntegerDelay2_X;
      rt_LoggedStateSignalPtrs[5] = (void*)&rtDWork.IntegerDelay1_X;
      rt_LoggedStateSignalPtrs[6] = (void*)&rtDWork.IntegerDelay4_X;
      rt_LoggedStateSignalPtrs[7] = (void*)&rtDWork.IntegerDelay1_X_d[0];
      rt_LoggedStateSignalPtrs[8] = (void*)&rtDWork.IntegerDelay_X_l[0];
      rt_LoggedStateSignalPtrs[9] = (void*)&rtDWork.IntegerDelay_X_e[0];
      rt_LoggedStateSignalPtrs[10] = (void*)&rtDWork.IntegerDelay_X_i[0];
      rt_LoggedStateSignalPtrs[11] = (void*)&rtDWork.UnitDelay1_DSTATE[0];
      rt_LoggedStateSignalPtrs[12] = (void*)&rtDWork.UnitDelay1_DSTATE_c;
      rt_LoggedStateSignalPtrs[13] = (void*)&rtDWork.UnitDelay_DSTATE;
    }

    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "tmp_raccel_xout");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "xFinal");
    rtliSetSigLog(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "none");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 1000);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[8];
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "ode4");
    ssSetVariableStepSolver(rtS, 0);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
    ssSetContStateDisabled(rtS, contStatesDisabled);
  }

  ssSetChecksumVal(rtS, 0, 3628094623U);
  ssSetChecksumVal(rtS, 1, 1092416540U);
  ssSetChecksumVal(rtS, 2, 2863338279U);
  ssSetChecksumVal(rtS, 3, 316320258U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[29];
    ssSetRTWExtModeInfo(rtS, &rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ssGetRTWExtModeInfo(rtS), &ssGetModelMappingInfo
      (rtS));
    rteiSetChecksumsPtr(ssGetRTWExtModeInfo(rtS), ssGetChecksums(rtS));
    rteiSetTPtr(ssGetRTWExtModeInfo(rtS), ssGetTPtr(rtS));
  }

  rtP.Saturation_UpperSat = rtInf;
  rtP.Saturation_UpperSat_m = rtInf;
  rtP.Saturation_UpperSat_mv = rtInf;
  rtP.Saturation_UpperSat_j = rtInf;
  rtP.Saturation_UpperSat_b = rtInf;
  rtP.Saturation_UpperSat_l = rtInf;
  return rtS;
}
