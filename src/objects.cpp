#include "objects.h"
#include "matrix.h"

// Helper functions

// Return the min of two floats
float min(float a, float b)
{
    return (a < b) ? a : b;
}

// Return the min of each vector component versus a float
vec3 min(vec3 a, float b)
{
    vec3 newVec;
    newVec.x = (a.x < b) ? a.x : b;
    newVec.y = (a.y < b) ? a.y : b;
    newVec.z = (a.z < b) ? a.z : b;
    return newVec;
}

// Return the max of two floats
float max(float a, float b)
{
    return (a > b) ? a : b;
}

// Return the max of each vector component versus a float
vec3 max(vec3 a, float b)
{
    vec3 newVec;
    newVec.x = (a.x > b) ? a.x : b;
    newVec.y = (a.y > b) ? a.y : b;
    newVec.z = (a.z > b) ? a.z : b;
    return newVec;
}

// Formulas from Inigo Quilez
// https://iquilezles.org/www/articles/distfunctions/distfunctions.htm

// Create a Box Frame
BoxFrame::BoxFrame(vec3 sideLengths, float thickness)
{
    s = sideLengths;
    t = thickness;
}

// Find the distance to the closest point on the box
float BoxFrame::intersectBox(vec3 pos)
{
    vec3 p = pos.abs() - s;

    vec3 q = (p + vec3(t, t, t)).abs() - vec3(t, t, t);

    return min(min(
                   max(vec3(p.x, q.y, q.z), 0.0).length() + min(max(p.x, max(q.y, q.z)), 0.0),
                   max(vec3(q.x, p.y, q.z), 0.0).length() + min(max(q.x, max(p.y, q.z)), 0.0)),
               max(vec3(q.x, q.y, p.z), 0.0).length() + min(max(q.x, max(q.y, p.z)), 0.0));
}

// Create a new sphere SDF
Sphere::Sphere(vec3 center, float size)
{
    c = center;
    s = size;
}

// Find the distance to the closest location on the sphere.
float Sphere::intersectSphere(vec3 pos)
{
    return pos.length() - s;
}