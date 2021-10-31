#include "vec3.h"

vec3::vec3() {}

vec3::vec3(float x1, float y1, float z1)
{
    x = x1;
    y = y1;
    z = z1;
}

// Normalize a vector
vec3 vec3::norm()
{
    float len = sqrt(x * x + y * y + z * z);
    x /= len;
    y /= len;
    z /= len;
    return vec3(x, y, z);
}

// Find the distance between two points
float vec3::dist(vec3 p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
}

// Find the dot product of two vectors
float vec3::dot(vec3 v2)
{
    return ((x * v2.x) + (y * v2.y) + (z * v2.z));
}

// Find the cross product of two vectors
vec3 vec3::cross(vec3 v2)
{
    return vec3(
        y * v2.z - z * v2.y,
        z * v2.x - x * v2.z,
        x * v2.y - y * v2.x);
}

// Get the absolute value of a vector
vec3 vec3::abs()
{
    return vec3(std::abs(x), std::abs(y), std::abs(z));
}

// Return the length of a vector
float vec3::length()
{
    return sqrt(x * x + y * y + z * z);
}

// Add two vectors
vec3 vec3::operator+(const vec3 &v2)
{
    vec3 newVec;
    newVec.x = x + v2.x;
    newVec.y = y + v2.y;
    newVec.z = z + v2.z;
    return newVec;
}

// Subtract two vectors
vec3 vec3::operator-(const vec3 &v2)
{
    vec3 newVec;
    newVec.x = x - v2.x;
    newVec.y = y - v2.y;
    newVec.z = z - v2.z;
    return newVec;
}

// Scale a vector
vec3 vec3::operator*(const float s)
{
    vec3 newVec;
    newVec.x = x * s;
    newVec.y = y * s;
    newVec.z = z * s;
    return newVec;
}