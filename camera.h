#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include "matrix.h"
#include "vec3.h"
#include "objects.h"

class Camera
{
public:
    // Width and height of console
    int consoleX, consoleY;

    // Generate a new camera with a given output size
    Camera(int x, int y);

    // Draw a frame of the scene at given time
    void draw_frame(char **frame, long time);
};

#endif