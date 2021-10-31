#include "camera.h"
#include <iostream>

// Initialize Camera
Camera::Camera(int x, int y)
{
    consoleX = x;
    consoleY = y;
}

#define RAYSTEPS 200
#define TOLERANCE 0.001

// TODO: make faster by threading
// Draw a frame of the scene
void Camera::draw_frame(char **frame, long time)
{
    // Make a box
    BoxFrame box = BoxFrame(vec3(0.6, 0.5, 0.6), 0.05);

    // Calculate ray origin and target
    float phi = 0.0005 * time;
    float theta = 0.0015 * time;
    vec3 rayOrigin = vec3(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta)) * 1.2;
    vec3 target = vec3(0.0, 0.0, 0.0);

    // Calculate lookAt matrix for ray directions
    mat4 lookMat = mat4().lookAt(rayOrigin, target);

    // Raytrace each pixel
    for (int row = 0; row < consoleY; row++)
        for (int col = 0; col < consoleX; col++)
        {
            // Calculate inital point
            vec3 p = vec3(0, 0, 1);
            p.x = ((2.0 * col - consoleX) / consoleY);
            p.y = ((2.0 * row - consoleY) / consoleY);

            // Calcuate ray direction
            vec3 rayDirection = lookMat * p;

            // Cast rays
            const float tmax = 5.0;
            float t = 0.0;
            for (int i = 0; i < RAYSTEPS; i++)
            {
                vec3 pos = rayOrigin + rayDirection * t;
                float dist = box.intersectBox(pos);
                if (dist < TOLERANCE || t > tmax)
                    break;
                t += dist;
            }

            // Set char
            frame[row][col] = (t < tmax) ? '#' : ' ';
        }
}
