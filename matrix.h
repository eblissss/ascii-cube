#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <math.h>
#include <stdlib.h>
#include <string.h>

// Create a 4x4 empty matrix
double** createMatrix();

// Destroy a 4x4 matrix
void destroyMatrix(double **matrix);

// Returns a 4x4 rotation matrix given an empty matrix (or previous rotation matrix) and input rotations
double** rotationMatrix(double **matrix, double yaw, double pitch, double roll);

// Multiply a vec3 by a mat4 and return a vec3, ignoring the last row
double* mulVec3Mat4(double *vec3, double **mat4);

#endif