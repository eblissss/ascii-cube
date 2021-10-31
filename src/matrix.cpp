#include "matrix.h"

// Create an empty 4x4 matrix
mat4::mat4()
{
    a11 = 0, a12 = 0, a13 = 0, a14 = 0,
    a21 = 0, a22 = 0, a23 = 0, a24 = 0,
    a31 = 0, a32 = 0, a33 = 0, a34 = 0,
    a41 = 0, a42 = 0, a43 = 0, a44 = 0;
}

// Returns a 4x4 rotation matrix for input values (from empty matrix)
mat4 mat4::rotationMatrix(float yaw, float pitch, float roll)
{
    float sinVals[] = {sin(yaw), sin(pitch), sin(roll)};
    float cosVals[] = {cos(yaw), cos(pitch), cos(roll)};

    this->a11 = cosVals[0] * cosVals[1];
    this->a12 = cosVals[0] * sinVals[1] * sinVals[2] - sinVals[0] * cosVals[2];
    this->a13 = cosVals[0] * sinVals[1] * cosVals[2] + sinVals[0] * sinVals[2];

    this->a21 = sinVals[0] * cosVals[1];
    this->a22 = sinVals[0] * sinVals[1] * sinVals[2] + cosVals[0] * cosVals[2];
    this->a23 = sinVals[0] * sinVals[1] * cosVals[2] - cosVals[0] * sinVals[2];

    this->a31 = -sinVals[1];
    this->a32 = cosVals[1] * sinVals[2];
    this->a33 = cosVals[1] * cosVals[2];

    this->a44 = 1;

    return *this;
}

// Returns a 4x4 translation matrix for input values (from empty matrix)
mat4 mat4::translationMatrix(vec3 t)
{
    this->a11 = 1;
    this->a22 = 1;
    this->a33 = 1;
    this->a44 = 1;

    this->a14 = t.x;
    this->a24 = t.y;
    this->a34 = t.z;

    return *this;
}

// Returns a 4x4 matrix for looking at a point
mat4 mat4::lookAt(vec3 origin, vec3 point)
{
    vec3 zAxis = (point - origin).norm();
    vec3 xAxis = zAxis.cross(vec3(0, 1, 0)).norm();
    vec3 yAxis = xAxis.cross(zAxis);

    this->a11 = xAxis.x;
    this->a21 = xAxis.y;
    this->a31 = xAxis.z;

    this->a12 = yAxis.x;
    this->a22 = yAxis.y;
    this->a32 = yAxis.z;

    this->a13 = zAxis.x;
    this->a23 = zAxis.y;
    this->a33 = zAxis.z;

    this->a41 = -(xAxis.dot(origin));
    this->a42 = -(yAxis.dot(origin));
    this->a43 = -(zAxis.dot(origin));

    this->a14 = 0;
    this->a24 = 0;
    this->a34 = 0;
    this->a44 = 1;

    return *this;
}

// Return the vector obtained from multiplying a vec3 by a mat4 (last row ignored)
vec3 mat4::operator*(const vec3 &v)
{
    vec3 outVec = vec3(0, 0, 0);

    outVec.x += v.x * this->a11;
    outVec.x += v.y * this->a12;
    outVec.x += v.z * this->a13;
    outVec.x += 1 * this->a14;

    outVec.y += v.x * this->a21;
    outVec.y += v.y * this->a22;
    outVec.y += v.z * this->a23;
    outVec.y += 1 * this->a24;

    outVec.z += v.x * this->a31;
    outVec.z += v.y * this->a32;
    outVec.z += v.z * this->a33;
    outVec.z += 1 * this->a34;

    return outVec;
}