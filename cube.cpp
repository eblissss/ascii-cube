#include "cube.h"

// Render an ascii cube on a w x h sized frame
void renderCube(char **frame, double **cubeCoords, int w, int h) {
    // Clear frame
    for (int i = 0; i < h; i++) {
        memset(frame[i], ' ', sizeof(char) * w);
    }

    int center[2] = {w/2, h/2};

    // Normalize points - sqrt(3) is distance from origin for all points
    double normPts[8][2];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            normPts[i][j] = cubeCoords[i][j] / sqrt(3.5);
        }
    }

    // Allocate frame coordinate array
    int **frameCoords = (int**)malloc(sizeof(int*) * 8);
    for (int i = 0; i < 8; i++) {
        frameCoords[i] = (int*)malloc(sizeof(int) * 2);
    }

    // Convert points to frame coordinates
    for (int i = 0; i < 8; i++) {
        frameCoords[i][0] = (int)((1 + normPts[i][0]) * center[0]);
        frameCoords[i][1] = (int)((1 + normPts[i][1]) * center[1]);
        frame[frameCoords[i][1]][frameCoords[i][0]] = '*';
    }

    // Connect vertices (Orderings - 12341234, 12123434, 11223344)
    for (int i = 0; i < 4; i++) {
        connectPoints(frame, frameCoords, i, i+4);
        connectPoints(frame, frameCoords, (i+4)%6, ((i+4)%6)+2);
        connectPoints(frame, frameCoords, i*2, i*2+1);
    }
}

// Draw the line segment between two coordinates on a frame
void connectPoints(char **frame, int **frameCoords, int coordA, int coordB) {
    double diffX = frameCoords[coordA][0] - frameCoords[coordB][0];
    double diffY = frameCoords[coordA][1] - frameCoords[coordB][1];
    int steps = abs(diffX) + abs(diffY);

    int newCoord[2];
    for (int j = 1; j < steps; j++) {
        newCoord[0] = frameCoords[coordA][0] - (int)(diffX * j / steps);
        newCoord[1] = frameCoords[coordA][1] - (int)(diffY * j / steps);
        frame[newCoord[1]][newCoord[0]] = '*';
    }
}

// Create a cube with each corner at (+-1, +-1, +-1), output is [8][3] array
double** generateCube() {
    // Allocate cube coordinate array
    double** cubeCoords = (double**)malloc(sizeof(double*) * 8);
    for (int i = 0; i < 8; i++) {
        cubeCoords[i] = (double*)malloc(sizeof(double) * 3);
    }

    double negative[3];
    int isNeg;

    // Set +/- position
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            isNeg = (i >> j) % 2;
            negative[j] = (isNeg) ? -1.0 : 1.0;
        }

        memcpy(cubeCoords[i], negative, sizeof(negative));
    }

    return cubeCoords;
}

// Free an 8x3 cube coordinate array
void destroyCube(double** cube) {
    for (int i = 0; i < 8; i++) {
        free(cube[i]);
    }
    free(cube);
}