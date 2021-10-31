#ifndef OBJECTS_HEADER
#define OBJECTS_HEADER

#include "vec3.h"

// Helper functions

// Return the min of two floats
float min(float a, float b);

// Return the min of each vector component versus a float
vec3 min(vec3 a, float b);

// Return the max of two floats
float max(float a, float b);

// Return the max of each vector component versus a float
vec3 max(vec3 a, float b);

// Formulas from Inigo Quilez
// https://iquilezles.org/www/articles/distfunctions/distfunctions.htm

class BoxFrame
{
public:
    vec3 s;
    float t;

    // Create a Box Frame
    BoxFrame(vec3 sideLengths, float thickness);

    // Find the distance to the closest point on the box
    float intersectBox(vec3 pos);
};

class Sphere
{
public:
    vec3 c;
    float s;

    // Create a new sphere SDF
    Sphere(vec3 center, float size);

    // Find the distance to the closest location on the sphere.
    float intersectSphere(vec3 pos);
};

#endif