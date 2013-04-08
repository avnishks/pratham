/**
 *@file  propagator.c
 *@brief Implements SGP Propagator model
*/

#include<math.h>
#include<inttypes.h>
#include "mathutil.h"
#include "frame.h"
#include "propagator.h"
#include "igrf.h"

static vector v_r;
static vector v_v;

void copy_gps_reading(void)
{
  static vector v_r_ecef, v_v_ecef;
  
  v_r_ecef[0] = (float)1 / 1000;
  v_r_ecef[1] = (float)1 / 1000;
  v_r_ecef[2] = (float)1 / 1000;
  
  v_v_ecef[0] = (float)1 / 1000;
  v_v_ecef[1] = (float)1 / 1000;
  v_v_ecef[2] = (float)1 / 1000;
  
  get_seconds_since_equinox();
  
  ecef2eci(v_r_ecef, v_r); 
  ecef2eci(v_v_ecef, v_v); 
  v_r[0] = -7178521.3196791;
  v_r[1] = -525365.237135614;
  v_r[2] = -14623.7085998278;
  
  v_v[0] = -89.2053675056426;
  v_v[1] = 1118.96667576478;
  v_v[2] = 7357.30907922713;
}

void sgp_get_acceleration(vector v_g)
{
  vector v_r_ecef, v_g_ecef;
  float R, R2, R3, R4;
  
  eci2ecef(v_r, v_r_ecef);
  
  v_g_ecef[2] = pow(v_g_ecef[2], 2);
  
  R = vector_norm(v_r_ecef);
  R2 = pow(R, 2);
  R2 = (3 * J2 * R_E2) / R2;
  
  R3 = pow(R, 3);
  
  R4 = pow(R, 4);
  R4 = (7.5 * J2 * v_r_ecef[2] * R_E2) / R4;
  
  v_g_ecef[0] = (-1 * GM * v_r_ecef[0] * (1 + R2 + R4)) / R3;
  v_g_ecef[1] = (-1 * GM * v_r_ecef[1] * (1 + R2 + R4)) / R3;
  v_g_ecef[2] = (-1 * GM * v_r_ecef[2] * (1 + 3 * R2 + R4)) / R3;
  
  ecef2eci(v_g_ecef, v_g);
}

void sgp_orbit_propagator(void)
{
  vector v_g;
  vector v_v_old;
  float delta_t = ((float)FRAME_TIME) / 10;
  uint8_t i, j;
  
  for(i = 0; i < 10; i++)
  {
    sgp_get_acceleration(v_g);
    
    copy_vector(v_v, v_v_old);
    
    for(j = 0; j < 3; j++)
      v_v[j] += v_g[j] * delta_t;
    
    for(j = 0; j < 3; j++)
      v_r[j] += ((v_v[j] + v_v_old[j]) / 2) * delta_t;
  }

}

void sun_vector_estimator(vector v_sun_o)
{
  float time_in_days = (float)seconds_since_equinox / 86400;
  float lambda = (2 * M_PI * time_in_days) / 365.256363;
  float delta, alpha;
  vector v_sun_eci;
  
  delta = asin(sin(EPSILON) * sin(lambda));
  alpha = atan2(cos(EPSILON) * sin(lambda), cos(lambda));
  
  v_sun_eci[0] = cos(delta) * cos(alpha);
  v_sun_eci[1] = cos(delta) * sin(alpha);
  v_sun_eci[2] = sin(delta);
  
  eci2orbit(v_r, v_v, v_sun_eci, v_sun_o);
}

void magnetic_field_estimator(vector v_B_o)
{
  float time_in_years = 2010 + (float)seconds_since_pivot / SECONDS_IN_YEAR;
  vector v_temp, v_r_lla, v_B_ned, v_B_eci;
  
  eci2ecef(v_r, v_temp);
  ecef2lla(v_temp, v_r_lla);
  
  igrf(v_r_lla, time_in_years, 8, v_B_ned);
  
  ned2ecef(v_B_ned, v_r_lla, v_temp);
  ecef2eci(v_temp, v_B_eci);
  eci2orbit(v_r, v_v, v_B_eci, v_B_o);
  
  scalar_into_vector(v_B_o, 1e-9);
  
}
