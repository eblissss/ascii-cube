#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "matrix.h"

// Render a ascii cube onto frame of w x h using given cubeCoords
void renderCube(char **frame, double **cubeCoords, int w, int h);

// Connect two points on a frame together
void connectPoints(char **frame, int **frameCoords, int coordA, int coordB);

// Generate a basic cube with coordinates (+/-1, +/-1, +/-1)
double** generateCube();

// Destroy an 8x3 cubeCoord array
void destroyCube(double** cube);

#endif
