#ifndef VECLIB3D_H
#define VECLIB3D_H

/**
 * Returns the dot product of two vectors:
 * P dot Q = P(x) * Q(x) + P(y) * Q(y) + P(z) * Q(z)
 *
 * PARAMETERS:
 *  vecA - one of the vectors to use in dot product
 *  vecB - other vector to use in dot product
 *
 *  RETURN:
 *  the dot product of vecA and vecB
 */
double vec_dot3(double *, double *);

/*
 * Scales a given vector by the given factor, and stores the resulting vector
 * in the given output vector.
 * aP = (P(X) * a, P(Y) * a, P(Z) * a)
 *
 * PARAMETERS:
 *  factor  - scalor value to multiply vector by
 *  input   - the vector to scale
 *  output  - where to store the resulting scaled vector
 */
void   vec_scale3(double, double *, double *);

/*
 * Returns the magnitude or length of the given vector.
 *  |P| = sqrt(P(x)^2 + P(Y)^2 + P(Z)^2)
 * 
 * PARAMETERS:
 *  vec - vector to find the magnitude of.
 *
 *  RETURN:
 *  the magnitude of vec
 */
double vec_length3(double *);

/*
 * Finds the difference between two given vectors and stores the resulting
 * vector at the given location.
 *
 * PARAMETERS:
 *  subtract - the vector to subtract (right side of operation)
 *  from     - the vector to subtract from
 *  output   - where to store the resulting vector
 */
void   vec_diff3(double *, double *, double *);

/**
 * Finds the sum of two given vectors and stores the resulting vector at the 
 * given location.
 *
 * PARAMETERS:
 *  vecA    - vector to sum
 *  vecB    - other vector to sum
 *  output  - where to store the resulting vector
 */
void   vec_sum3(double *, double *, double *);

/*
 * Convert a given vector into a unit vector and store the resulting vector in
 * the given location.
 * U = (1/||P||)P
 *
 * PARAMETERS:
 *  input   - vector to convert to a unit vector
 *  output  - where to store the resulting unit vector
 */
void   vec_unit3(double *, double *);

/*
 * Convert a given vector into a unit vector and store the resulting vector in
 * the given location.
 * U = (1/||P||)P
 *
 * PARAMETERS:
 *  input   - vector to convert to a unit vector
 *  output  - where to store the resulting unit vector
 */
void   vec_prn3(char *, double *);
#endif
