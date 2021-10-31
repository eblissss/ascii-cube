#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "vec3.h"

class mat4
{
public:
    float a11, a12, a13, a14,
        a21, a22, a23, a24,
        a31, a32, a33, a34,
        a41, a42, a43, a44;

    // Create a 4x4 empty matrix
    mat4();

    // Returns a 4x4 rotation matrix given an empty matrix (or previous rotation matrix) and input rotations
    mat4 rotationMatrix(float yaw, float pitch, float roll);

    // Create a translation matrix
    mat4 translationMatrix(vec3 t);

    // Multiply a vec3 by a mat4 and return a vec3, ignoring the last row
    vec3 operator*(const vec3 &v);
};

#endif