#ifndef MATRIX_H
#define MATRIX_H
#include "Vector.h"

struct Matrix{
    float ix, jx, kx, ox, iy, jy, ky, oy, iz, jz, kz, oz, iw, jw, kw, ow;

    Matrix();
    Matrix(float ix, float jx, float kx, float ox,
           float iy, float jy, float ky, float oy,
           float iz, float jz, float kz, float oz,
           float iw, float jw, float kw, float ow);
    Vector4 operator*(const Vector4 v);
    Matrix operator*(const Matrix v);
    void print();
};

Matrix Translate3D(float tX, float tY, float tZ);
Matrix Scale3D(float sX, float sY, float sZ);
Matrix RotateX3D(float degree);
Matrix RotateY3D(float degree);
Matrix RotateZ3D(float degree);
Matrix Rotate3D(float degreeX, float degreeY, float degreeZ);
Matrix Rotate3D(float degree, Vector4 vec);
Matrix LookAt(Vector4 eye, Vector4 spot, Vector4 up);
Matrix Orthgraphic(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
Matrix Perspective(float fovY, float aspect, float nearZ, float farZ);
Matrix Viewport(float x, float y, float width, float height);

#endif