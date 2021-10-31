#include "camera.h"
#include "matrix.h"
#include <iostream>

// Initialize Camera
Camera::Camera(int x, int y)
{
    consoleX = x;
    consoleY = y;
}

#define RAYSTEPS 200
#define TOLERANCE 0.0001

// TODO: make faster by threading
// Draw a frame of the scene
void Camera::draw_frame(char **frame, long time)
{
    // Make a box
    BoxFrame box = BoxFrame(vec3(0.6, 0.5, 0.6), 0.05);

    // Calculate spherical coordinates at time
    float an = 0.2 * time;
    vec3 ro = vec3(cos(an), 0.0, sin(an)) * 1.2;
    vec3 ta = vec3(0.0, 0.0, 0.0);

    // Calculate decomposed matrix for ray directions
    vec3 ww = (ta - ro).norm();
    vec3 uu = ww.cross(vec3(0.0, 1.0, 0.0)).norm();
    vec3 vv = uu.cross(ww).norm();

    // Create matrices to shift camera
    mat4 rotMatrix = mat4().rotationMatrix(0.5, 0.4, 0.3);
    mat4 tranMatrix = mat4().translationMatrix(vec3(-0.8, 0.3, -0.1));

    // Raytrace each pixel
    for (int row = 0; row < consoleY; row++)
        for (int col = 0; col < consoleX; col++)
        {
            // Calculate inital point
            vec3 p = vec3();
            p.x = ((2.0 * col - consoleX) / consoleY);
            p.y = ((2.0 * row - consoleY) / consoleY);
            p.z = 1.0;

            // Transform point
            p = rotMatrix * p;
            p = tranMatrix * p;

            // Calcuate ray direction
            vec3 rd = vec3(uu * p.x + vv * p.y + ww * p.z);

            const float tmax = 5.0;
            float t = 0.0;
            for (int i = 0; i < RAYSTEPS; i++)
            {
                vec3 pos = ro + rd * t;
                float dist = box.intersectBox(pos);
                if (dist < TOLERANCE || t > tmax)
                    break;
                t += dist;
            }

            frame[row][col] = (t < tmax) ? 'x' : ' ';
        }
}
