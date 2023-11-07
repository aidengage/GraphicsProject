#ifndef VECTOR_H
#define VECTOR_H
// using namespace std;

struct Vector2 {
  float x;
  float y;

  Vector2();
  Vector2(float x, float y);
  Vector2 operator+(const Vector2 v);
  Vector2 operator-(const Vector2 v);
  Vector2 operator*(float x);

  float magnitude();
  float dot(Vector2);
  Vector2 normalize();
  Vector2 perpendicular();
};

struct Vector4 {
  float x;
  float y;
  float z;
  float w;

  Vector4();
  Vector4(float pX, float pY, float pZ, float pW);
  Vector4 operator+(const Vector4 v);
  Vector4 operator-(const Vector4 v);
  Vector4 operator*(float x);
  float magnitude();
  float dot(Vector4);
  Vector4 normalize();

  void print();
};

float determinant(Vector2 a, Vector2 b);
float determinant(Vector4 a, Vector4 b);




#endif