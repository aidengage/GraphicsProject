#ifndef VECTOR2_H
#define VECTOR2_H
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

float determinant(Vector2 a, Vector2 b);

#endif