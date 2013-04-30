#include "ext_types.h"

static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.Integrator[0]), 0, 0, 460 }
  ,

  { (char_T *)(&rtDWork.IntegerDelay_X), 0, 0, 331 },

  { (char_T *)(&rtDWork.FromFile_PWORK.PrevTimePtr), 11, 0, 72 },

  { (char_T *)(&rtDWork.RandSeed), 7, 0, 7 },

  { (char_T *)(&rtDWork.ToFile_IWORK.Count), 10, 0, 5 },

  { (char_T *)
    (&rtDWork.is_active_c7_adcs_v15_integral_Power_nom_no_charge_in_detumb), 3,
    0, 25 },

  { (char_T *)(&rtDWork.isStable), 8, 0, 50 }
};

static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&rtP.Integrator_IC[0]), 0, 0, 187 }
};

static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};
