#include "matrix.h"

// Create an empty 4x4 matrix
double** createMatrix() {
    double **matrix = (double**)malloc(sizeof(double*) * 4);
    for (int i = 0; i < 4; i++) {
        matrix[i] = (double*)calloc(sizeof(double*), 4);
    }
    return matrix;
}

// Free a 4x4 matrix
void destroyMatrix(double **matrix) {
    for (int i = 0; i < 4; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Returns a 4x4 rotation matrix for input values (from empty matrix)
double** rotationMatrix(double **matrix, double yaw, double pitch, double roll) {
    double sinVals[] = {sin(yaw), sin(pitch), sin(roll)};
    double cosVals[] = {cos(yaw), cos(pitch), cos(roll)};

    matrix[0][0] = cosVals[0] * cosVals[1];
    matrix[0][1] = cosVals[0] * sinVals[1] * sinVals[2] - sinVals[0] * cosVals[2];
    matrix[0][2] = cosVals[0] * sinVals[1] * cosVals[2] + sinVals[0] * sinVals[2];

    matrix[1][0] = sinVals[0] * cosVals[1];
    matrix[1][1] = sinVals[0] * sinVals[1] * sinVals[2] + cosVals[0] * cosVals[2];
    matrix[1][2] = sinVals[0] * sinVals[1] * cosVals[2] - cosVals[0] * sinVals[2];

    matrix[2][0] = -sinVals[1];
    matrix[2][1] = cosVals[1] * sinVals[2];
    matrix[2][2] = cosVals[1] * cosVals[2];

    matrix[3][3] = 1;

    return matrix;
}

// Return the vector obtained from multiplying a vec3 by a mat4 (last row ignored)
double* mulVec3Mat4(double *vec3, double **mat4) {
    double inVec[4] = {vec3[0], vec3[1], vec3[2], 1};
    double *outVec = (double*)malloc(sizeof(double) * 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            outVec[i] += inVec[j] * mat4[i][j];
        }        
    }

    return outVec;
}