/**
 *@file  controller.c
 *@brief Implements the Control Law
*/
#include<math.h>
#include<stdio.h>
#include<inttypes.h>
#include "controller.h"
#include "mathutil.h"
#include "propagator.h"
#include "quest.h"

uint8_t Mode, first_GPS = 1, GPS_done = 0;
uint64_t Time, seconds_since_equinox, seconds_since_pivot;

static vector v_B;
static vector v_w = {0.0, 0.0, 0.0};
static quaternion q_o;
static uint8_t first_B = 1, light = 1, w_ctrl = 1;

static matrix m_Kp = { { 2.31974732995976e-07, -9.68862003823701e-10, -8.16250915587234e-10 },
                       { -9.68862003823701e-10, 2.34054275693572e-07, -3.27879997319606e-09 },
                       { -8.16250915587234e-10, -3.27879997319606e-09, 2.16304237871903e-07 } };
                         
static matrix m_Ki = { { 4.40842904803014e-12, -1.84121750934969e-14, -1.55119663261705e-14 },
                       { -1.84121750934969e-14, 4.44794850912104e-12, -6.23100492792408e-14 },
                       { -1.55119663261705e-14, -6.23100492792408e-14, 4.1106282271831e-12 } };
                         
static matrix m_Kd = { { 0.000451402853158012, -1.88532202276527e-06, -1.58835398765308e-06 },
                       { -1.88532202276527e-06, 0.00045544946416101, -6.38026238340704e-06 },
                       { -1.58835398765308e-06, -6.38026238340704e-06, 0.000420909419161786 } };

void detumbling(vector v_m_D)
{
  static vector v_B_old;
  if(first_B)
  {
    copy_vector(v_B, v_B_old);
    first_B = 0;
    return;
  }
  
  vector v_B_avg, v_dB;
  float factor;
  uint8_t i;
  
  for(i = 0; i < 3; i++)
  {
    v_dB[i] = (v_B[i] - v_B_old[i]) / FRAME_TIME;
    v_B_avg[i] = (v_B[i] + v_B_old[i]) / 2;
  }
  factor = (-1 * K_DETUMBLING * MAG_B) / vector_norm(v_B_avg);
  
  for(i = 0; i < 3; i++)
    v_m_D[i] = factor * v_dB[i];
  
  copy_vector(v_B, v_B_old);
}

void nominal(vector v_m_N)
{
  static vector v_ieu = { 0.0, 0.0, 0.0 };
  vector v_eu, v_m_temp;
  uint8_t i, j;
  float norm_B = vector_norm(v_B);
    
  for(i = 0; i < 3; i++)
  {
    v_eu[i] = 2 * q_o[i] * q_o[3];
    v_ieu[i] += v_eu[i] * FRAME_TIME;
  }
    
  for(i = 0; i < 3; i++)
  {
    v_m_temp[i] = 0;
    for(j = 0; j < 3; j++)
      v_m_temp[i] += v_eu[j] * m_Kp[i][j] + v_ieu[j] * m_Ki[i][j] + v_w[j] * m_Kd[i][j];
    v_m_temp[i] /= norm_B * norm_B;
  }
  
  printf("m_temp ");
  print_v(v_m_temp);
    
  vector_cross_product(v_m_temp, v_B, v_m_N);
  scalar_into_vector(v_m_N, light);
    
}

void apply_torque(vector v_m)
{
  uint8_t i;
  
  for(i = 0; i < 3; i++)
  {
    if(v_m[i] > M_MAX)
      v_m[i] = M_MAX;
  }
  
  scalar_into_vector(v_m, 1.0 / (N_TURNS * AREA));
  
  for(i = 0; i < 3; i++)
  {
    if(v_m[i] > I_MAX)
      v_m[i] = I_MAX;
  }
  
  /*Current_state.pwm.x = fabs((v_m[0] * PWM_RES) / I_MAX);
  Current_state.pwm.y = fabs((v_m[1] * PWM_RES) / I_MAX);
  Current_state.pwm.z = fabs((v_m[2] * PWM_RES) / I_MAX);
  
  if(v_m[0] < 0)
    Current_state.pwm.x_dir = 1;
  if(v_m[1] < 0)
    Current_state.pwm.y_dir = 1;
  if(v_m[2] < 0)
    Current_state.pwm.z_dir = 1;*/
}

void control(void){
  
  vector v_m_D, v_m_N, v_sun_o, v_B_o;
  static uint64_t nominal_end = 0;
  
  ///Watchdog enabled for the control law
  //watch_dog(T_CONTROL);
  
  /// Take B readings from Magnetometer
  //read_MM();
  /*v_B[0] = Current_state.mm.B_x;
  v_B[1] = Current_state.mm.B_y;
  v_B[2] = Current_state.mm.B_z;*/
  
  detumbling(v_m_D);
  
  /*if(((!first_GPS) && (Time % 600 == 0)) || (first_GPS && (!first_B) && (vector_norm(v_m_D) < 2 )))
    ///* Switch on the GPS First
    read_GPS();*/
  
  /// Check if in Nominal or Detumbling Mode
  if(!first_GPS)
  {
    if(GPS_done)
      copy_gps_reading();
      
    //read_SS();
    
    sgp_orbit_propagator();
    sun_vector_estimator(v_sun_o);
    magnetic_field_estimator(v_B_o);
    
    //light = quest(v_B_o, v_sun_o, q_o, &w_ctrl);
    
    omega_estimation(q_o, v_w);
    scalar_into_vector(v_w, light);
    
    convert_unit_quaternion(q_o);
    
    nominal(v_m_N);
    
    seconds_since_equinox += FRAME_TIME;
    seconds_since_pivot += FRAME_TIME;
    
    float norm_w = vector_norm(v_w);
    
    /*if((norm_w < TOLW_D2N) && (light == 1) && Mode == DETUMBLING && Time > D_TIME)
    {
      Mode = NOMINAL;
      nominal_end = Time + N2D_TIME;
    }
    else if((norm_w > TOLW_N2D) && Mode == NOMINAL && Time > nominal_end)
      Mode = DETUMBLING;*/
  }
  
  /*if(Mode == DETUMBLING)
    apply_torque(v_m_D);
  
  else if(Mode == NOMINAL)
    apply_torque(v_m_N);*/
    
}
int main()
{
  vector  n, n_c;
  int x, i;
  FILE *f1, *f2, *f3, *f4;
  //copy_gps_reading();
  f1 = fopen("data_Q.txt", "r");
  f2 = fopen("data_M.txt", "r");
  f3 = fopen("data_N.txt", "r");
  f4 = fopen("data_W.txt", "r");
  
  for(x = 0; x < 51; x++)
  {
    fscanf(f1, "%f %f %f %f ", &q_o[0],  &q_o[1],  &q_o[2],  &q_o[3]);
    fscanf(f2, "%f %f %f ", &v_B[0], &v_B[1], &v_B[2]);
    fscanf(f3, "%f %f %f ", &n[0], &n[1], &n[2]);
    fscanf(f4, "%f %f %f ", &v_w[0], &v_w[1], &v_w[2]);
    v_w[0] = 0;
    v_w[1] = 0;
    v_w[2] = 0;
    
    nominal(n_c);
    
    for(i=0;i<3;i++)
      printf("act %f ", n[i]);
    printf("\n");
    for(i=0;i<3;i++)
      printf("calc %f ", n_c[i]);
    printf("\n");
    printf("\n");
    
    /*sun_vector_estimator(v_sun_o);
    magnetic_field_estimator(v_B_o);
    
    light = quest(v_B_o, v_sun_o, q_o, &w_ctrl);
    
    omega_estimation(q_o, v_w);
    //print_v(v_w);
    scalar_into_vector(v_w, light * w_ctrl);
    
    for(i=0;i<4;i++)
      printf("%f ", q[i]);
    printf("\n");
    printf("\n");
    
    sgp_orbit_propagator();
    seconds_since_equinox += FRAME_TIME;
    seconds_since_pivot += FRAME_TIME;*/
    
  }
  return 0;
}
