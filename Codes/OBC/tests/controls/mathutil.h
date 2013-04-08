/**
 *@file  mathutil.h
 *@brief Contains the various constant/macro/struct definitions and functions for matrix/vector manipulation
*/

#ifndef MATHUTIL_H
#define MATHUTIL_H

typedef float vector[3];

typedef float quaternion[4];

typedef float matrix[3][3];

void copy_vector(vector v_src, vector v_dest);

void copy_quaternion(quaternion q_src, quaternion q_dest);

float vector_norm(vector v);

float vector_dot_product(vector v_a, vector v_b);

void add_vectors(vector v_a, vector v_b, vector v_res);

void vector_into_matrix(vector v, matrix m, vector v_res);

void vector_cross_product(vector v_a, vector v_b, vector v_res);

void scalar_into_vector(vector v, float s);

void scalar_into_quaternion(quaternion q, float s);

void convert_unit_vector(vector v);

void convert_unit_quaternion(quaternion v);
#define FRAME_TIME 2.0
extern uint64_t seconds_since_equinox, seconds_since_pivot, Time;

///Stores the Mode the Satellite is in
extern uint8_t Mode, first_GPS, GPS_done;
void print_v(vector v);
#endif
