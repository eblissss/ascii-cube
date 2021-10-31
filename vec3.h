#ifndef VEC3_HEADER
#define VEC3_HEADER

#include <math.h>

class vec3
{
public:
    float x, y, z;

    // Create a new vector
    vec3();
    vec3(float x1, float y1, float z1);

    // Normalize a vector
    vec3 norm();

    // Calculate the distance between two points
    float dist(vec3 p);

    // Calculate the dot product
    float dot(vec3 v2);

    // Calculate the cross product
    vec3 cross(vec3 v2);

    // Return the absoule value of a vector
    vec3 abs();

    // Return the length of the vector
    float length();

    // Add two vectors
    vec3 operator+(const vec3 &v2);

    // Sub two vectors
    vec3 operator-(const vec3 &v2);

    // Multiply a vector by a scalar
    vec3 operator*(const float s);
};

#endif