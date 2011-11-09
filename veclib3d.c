/**
 * Definition of functions to perform various operations on 3d vectors.
 *
 * Chris Blades
 * Feb. 18, 2010
 */
#include <math.h>
#include <stdio.h>
#include "veclib3d.h"

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
double vec_dot3(double *vecA, double *vecB) {
    double product;

    product = ((*vecA) * (*vecB)) +
              (*(vecA + 1) * *(vecB + 1)) +
              (*(vecA + 2) * *(vecB + 2));

    return product;
}

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
void   vec_scale3(double factor, double *input, double *output) {
    double x;
    double y;
    double z;

    x = *input * factor;
    y = *(input + 1) * factor;
    z = *(input + 2) * factor;

    *output        = x;
    *(output + 1) = y;
    *(output + 2) = z;
}

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
double vec_length3(double *vec) {
    double length;
    double xSqr;
    double ySqr;
    double zSqr;

    // TODO: get rid of magic number 2
    xSqr = pow(*vec, 2);
    ySqr = pow(*(vec + 1), 2);
    zSqr = pow(*(vec + 2), 2);

    length = sqrt(xSqr + ySqr + zSqr);
    
    return length;
}

/*
 * Finds the difference between two given vectors and stores the resulting
 * vector at the given location.
 *
 * PARAMETERS:
 *  subtract - the vector to subtract (right side of operation)
 *  from     - the vector to subtract from
 *  output   - where to store the resulting vector
 */
void   vec_diff3(double *subtract, double *from, double *output) {
    double diffX;
    double diffY;
    double diffZ;

    diffX = *from - *subtract;
    diffY = *(from + 1) - *(subtract + 1);
    diffZ = *(from + 2) - *(subtract + 2);

    *output       = diffX;
    *(output + 1) = diffY;
    *(output + 2) = diffZ;
}

/**
 * Finds the sum of two given vectors and stores the resulting vector at the 
 * given location.
 *
 * PARAMETERS:
 *  vecA    - vector to sum
 *  vecB    - other vector to sum
 *  output  - where to store the resulting vector
 */
void   vec_sum3(double *vecA, double *vecB, double *output) {
    double sumX;
    double sumY;
    double sumZ;

    sumX = *vecA + *vecB;
    sumY = *(vecA + 1) + *(vecB + 1);
    sumZ = *(vecA + 2) + *(vecB + 2);

    *output       = sumX;
    *(output + 1) = sumY;
    *(output + 2) = sumZ;

}

/*
 * Convert a given vector into a unit vector and store the resulting vector in
 * the given location.
 * U = (1/||P||)P
 *
 * PARAMETERS:
 *  input   - vector to convert to a unit vector
 *  output  - where to store the resulting unit vector
 */
void   vec_unit3(double *input, double *output) {
    double length;

    length = vec_length3(input);
    
    // if the length of the input vector is 0, this operation is undefined, 
    // do nothing
    if (length == 0) {
        return;
    }

    vec_scale3((1/length), input, output);
}

/*
 * Print a vector with the given lable in format:
 *
 * <label> = (P(x), P(y), P(z))
 *
 * PARAMETERS:
 *  label   - label to print out with the vector
 *  vector  - the vector to print
 */
void   vec_prn3(char *label, double *vector) {
    printf("%s = (%f, %f, %f)\n", label, *vector, *(vector + 1), *(vector + 2));
}
