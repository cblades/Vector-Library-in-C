/**
 * Test driver for veclib3d functions.
 *
 * Chris Blades
 * Feb. 18, 2010
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "veclib3d.h"

/**
 * Tests veclib3d by running tests against each method and checking the
 * result of the method calls against assertions.
 *
 * RETURN:
 *  Return success if all tests pass, exit with failure otherwise
 */
int main() {
    double v1[3] = {1, 2, 3};
    double v2[3] = {0, -5, 9};
    double v3[3];
    double v4;

    // test vec_prn3
    printf("Testing vectors:\n");
    vec_prn3("v1", v1);
    vec_prn3("v2", v2);

    // test vec_dot3
    printf("testing vec_dot3...\n");
    
    printf("\ttesting normal operation:  v1 dot v2:  ");
    v4 = vec_dot3(v1, v2);
    assert(v4 == 17);
    printf("good\n");

    printf("\ttesting aliasing: v1 dot v1:  ");
    v4 = vec_dot3(v1, v1);
    assert(v4 == 14);
    printf("good\n");

    // test vec_scale3
    printf("testing vec_scale3...\n");

    printf("\ttesting normal operation: 10 * v1 -> v3:  ");
    vec_scale3(10, v1, v3);
    assert(v3[0] == 10 && v3[1] == 20 && v3[2] == 30);
    printf("good\n");

    printf("\ttesting aliasing: 10 * v1 -> v1:  ");
    vec_scale3(10, v1, v1);
    assert(v1[0] == 10 && v1[1] == 20 && v1[2] == 30);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    printf("good\n");

    printf("\ttesting zero factor: 0 * v1 -> v3:  ");
    vec_scale3(0, v1, v3);
    assert(v3[0] == 0 && v3[1] == 0 && v3[2] == 0);
    printf("good\n");
    
    printf("\ttesting negative factor: -1 * v1 -> v3:  ");
    vec_scale3(-1, v1, v3);
    assert(v3[0] == (-1 * v1[0]) && 
           v3[1] == (-1 * v1[1]) &&
           v3[2] == (-1 * v1[2]));
    printf("good\n");

    // test vec_length3
    printf("testing vec_length3...\n");
    
    printf("\ttesting normal operation: ||v1||:  ");
    v4 = vec_length3(v1);
    assert(v4 == sqrt(14));
    printf("good\n");
    
    printf("\ttesting zero vector: ||{0, 0, 0}||:  ");
    v3[0] = v3[1] = v3[2] = 0;
    v4 = vec_length3(v3);
    assert(v4 == 0);
    printf("good\n");

    printf("\ttesting negative vector:  ||v2||:  ");
    v4 = vec_length3(v2);
    assert(v4 == sqrt(106));
    printf("good\n");
    
    // test vec_diff3
    printf("testing vec_diff3...\n");

    printf("\ttesting normal operation:  v1 - v2 -> v3:  ");
    vec_diff3(v2, v1, v3);
    assert(v3[0] == 1 && v3[1] == 7 && v3[2] == -6);
    printf("good\n");

    printf("\ttesting aliasing 1:  v1 - v2 -> v1:  ");
    vec_diff3(v2, v1, v1);
    assert(v1[0] == 1 && v1[1] == 7 && v1[2] == -6);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;  
    printf("good\n");
    
    printf("\ttesting aliasing 2: v1 - v2 -> v2:  ");
    vec_diff3(v2, v1, v2);
    assert(v2[0] == 1 && v2[1] == 7 && v2[2] == -6);
    v2[0] = 0;
    v2[1] = -5;
    v2[2] = 9;
    printf("good\n");
    
    // test vec_sum3
    printf("testing vec_sum3...\n");

    printf("\ttesting normal operation:  v1 + v2 -> v3:  ");
    vec_sum3(v2, v1, v3);
    assert(v3[0] == 1 && v3[1] == -3 && v3[2] == 12);
    printf("good\n");

    printf("\ttesting aliasing 1:  v1 + v2 -> v1:  ");
    vec_sum3(v2, v1, v1);
    assert(v1[0] == 1 && v1[1] == -3 && v1[2] == 12);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;  
    printf("good\n");
    
    printf("\ttesting aliasing 2: v1 + v2 -> v2:  ");
    vec_sum3(v2, v1, v2);
    
    assert(v2[0] == 1 && v2[1] == -3 && v2[2] == 12);
    v2[0] = 0;
    v2[1] = -5;
    v2[2] = 9;
    printf("good\n");
    
    // test vec_unit3
    printf("testing vec_unit3...\n");

    printf("\ttesting normal operation:  v1 -> v3:  ");
    vec_unit3(v1, v3);
    assert(vec_length3(v3) == 1);
    printf("good\n");

    printf("\ttesting aliasing: v1 -> v1:  ");
    vec_unit3(v1, v1);
    assert(vec_length3(v1) == 1);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    printf("good\n");

    printf("\ttesting zero vector:  {0, 0, 0} -> v3:  ");
    v3[0] = v3[1] = v3[2] = 0;
    vec_unit3(v3, v3);
    assert(vec_length3(v3) == 0);
    printf("good\n");
    return 0;   
}
