#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <cmath>

using namespace std;

Matrix::Matrix(float pix, float pjx, float pkx, float pox,
               float piy, float pjy, float pky, float poy,
               float piz, float pjz, float pkz, float poz,
               float piw, float pjw, float pkw, float pow) {
    ix = pix;
    jx = pjx;
    kx = pkx;
    ox = pox;
    iy = piy;
    jy = pjy;
    ky = pky;
    oy = poy; 
    iz = piz;
    jz = pjz;
    kz = pkz;
    oz = poz;
    iw = piw;
    jw = pjw;
    kw = pkw;
    ow = pow;
}

Matrix::Matrix() {
    ix = 1.0f;
    jx = 0.0f;
    kx = 0.0f;
    ox = 0.0f;
    iy = 0.0f;
    jy = 1.0f;
    ky = 0.0f;
    oy = 0.0f;
    iz = 0.0f;
    jz = 0.0f;
    kz = 1.0f;
    oz = 0.0f;
    iw = 0.0f;
    jw = 0.0f;
    kw = 0.0f;
    ow = 1.0f;
}

Vector4 Matrix::operator*(const Vector4 v) {
    return Vector4
           ((this->ix * v.x) + (this->jx * v.y) + (this->kx * v.z) + (this->ox * v.w), 
            (this->iy * v.x) + (this->jy * v.y) + (this->ky * v.z) + (this->oy * v.w), 
            (this->iz * v.x) + (this->jz * v.y) + (this->kz * v.z) + (this->oz * v.w), 
            (this->iw * v.x) + (this->jw * v.y) + (this->kw * v.z) + (this->ow * v.w));
}

// thorough check of multiplication
Matrix Matrix::operator*(const Matrix m) {
    return Matrix 
       ((m.ix * this->ix) + (m.iy * this->jx) + (m.iz * this->kx) + (m.iw * this->ox),
        (m.jx * this->ix) + (m.jy * this->jx) + (m.jz * this->kx) + (m.jw * this->ox),
        (m.kx * this->ix) + (m.ky * this->jx) + (m.kz * this->kx) + (m.kw * this->ox),
        (m.ox * this->ix) + (m.oy * this->jx) + (m.oz * this->kx) + (m.ow * this->ox),
        
        (m.ix * this->iy) + (m.iy * this->jy) + (m.iz * this->ky) + (m.iw * this->oy),
        (m.jx * this->iy) + (m.jy * this->jy) + (m.jz * this->ky) + (m.jw * this->oy),
        (m.kx * this->iy) + (m.ky * this->jy) + (m.kz * this->ky) + (m.kw * this->oy),
        (m.ox * this->iy) + (m.oy * this->jy) + (m.oz * this->ky) + (m.ow * this->oy),
        
        (m.ix * this->iz) + (m.iy * this->jz) + (m.iz * this->kz) + (m.iw * this->oz),
        (m.jx * this->iz) + (m.jy * this->jz) + (m.jz * this->kz) + (m.jw * this->oz),
        (m.kx * this->iz) + (m.ky * this->jz) + (m.kz * this->kz) + (m.kw * this->oz),
        (m.ox * this->iz) + (m.oy * this->jz) + (m.oz * this->kz) + (m.ow * this->oz),
        
        (m.ix * this->iw) + (m.iy * this->jw) + (m.iz * this->kw) + (m.iw * this->ow),
        (m.jx * this->iw) + (m.jy * this->jw) + (m.jz * this->kw) + (m.jw * this->ow),
        (m.kx * this->iw) + (m.ky * this->jw) + (m.kz * this->kw) + (m.kw * this->ow),
        (m.ox * this->iw) + (m.oy * this->jw) + (m.oz * this->kw) + (m.ow * this->ow));
}

void Matrix::print() {
    cout << this->ix << "\t" << this->jx << "\t" << this->kx << "\t" << this->ox << endl;
    cout << this->iy << "\t" << this->jy << "\t" << this->ky << "\t" << this->oy << endl;
    cout << this->iz << "\t" << this->jz << "\t" << this->kz << "\t" << this->oz << endl;
    cout << this->iw << "\t" << this->jw << "\t" << this->kw << "\t" << this->ow << endl;
}

Matrix Translate3D(float tX, float tY, float tZ) {
    Matrix m (1.0f, 0.0f, 0.0f, tX,
              0.0f, 1.0f, 0.0f, tY,
              0.0f, 0.0f, 1.0f, tZ,
              0.0f, 0.0f, 0.0f, 1.0f);
    return m;
}

Matrix Scale3D(float sX, float sY, float sZ) {
    Matrix m (sX, 0.0f, 0.0f, 0.0f,
              0.0f, sY, 0.0f, 0.0f,
              0.0f, 0.0f, sZ, 0.0f,
              0.0f, 0.0f, 0.0f, 1.0f);
    return m;
}

Matrix RotateX3D(float degree) {
    float radians = (degree * M_PI) / 180.0;
    Matrix rotate (1.0f, 0.0f, 0.0f, 0.0f,
                   0.0f, cosf(radians), sinf(radians), 0.0f,
                   0.0f, -sinf(radians), cosf(radians), 0.0f,
                   0.0f, 0.0f, 0.0f, 1.0f);
    return rotate;
}

Matrix RotateY3D(float degree) {
    float radians = (degree * M_PI) / 180.0;
    Matrix rotate (cosf(radians), 0.0f, -sinf(radians), 0.0f,
                   0.0f, 1.0f, 0.0f, 0.0f,
                   sinf(radians), 0.0f, cosf(radians), 0.0f,
                   0.0f, 0.0f, 0.0f, 1.0f);
    return rotate;
}

Matrix RotateZ3D(float degree) {
    float radians = (degree * M_PI) / 180.0;
    Matrix rotate (cosf(radians), sinf(radians), 0.0f, 0.0f,
                   -sinf(radians), cosf(radians), 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f,
                   0.0f, 0.0f, 0.0f, 1.0f);
    return rotate;
}

Matrix Rotate3D (float degreeX, float degreeY, float degreeZ) {
    return RotateX3D(degreeX) * RotateY3D(degreeY) * RotateZ3D(degreeZ);
}

Matrix Rotate3D(float degrees, Vector4 vec) {
    float alpha = atanf(vec.x / vec.z);
    float beta = acosf(vec.y / vec.magnitude());

    alpha = alpha * (180.0 / M_PI);
    beta = beta * (180.0 / M_PI);

    return RotateY3D(alpha) * RotateX3D(beta) * RotateY3D(degrees) * RotateX3D(-beta) * RotateY3D(-alpha);
}

// Matrix Rotate3D (float degree, Vector4 vec) {
//     float radians = degree * M_PI / 180.0;
//     Vector4 temp = vec.normalize();

//     float x = temp.x;
//     float y = temp.y;
//     float z = temp.z;

//    float cosTheta = cos(radians);
//    float sinTheta = sin(radians);
//    float minusCosTheta = 1.0 - cosTheta;
//    Matrix rotationMatrix;
//    (cosTheta + x * x * minusCosTheta, x * y * minusCosTheta - z * sinTheta ,  x * z * minusCosTheta + y * sinTheta,  0.0,
//     0, 0, 0, 0,
//     0, 0, 0, 0,
//     0, 0, 0, 1);

// Matrix Rotate3D (float degree, Vector4 vec){

// }



// }