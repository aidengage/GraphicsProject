#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Color.h"
#include "Vector.h"
#include "Matrix.h"

struct Triangle3D;
struct Triangle2D {
  Vector2 v1;
  Vector2 v2; 
  Vector2 v3;
  Color c1;
  Color c2;
  Color c3;

  Triangle2D();
  Triangle2D(Triangle3D t);
  Triangle2D(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3);
};

struct Triangle3D {
  Vector4 v1;
  Vector4 v2;
  Vector4 v3;
  Color c1;
  Color c2;
  Color c3;
  bool shouldDraw;

  Triangle3D();
  Triangle3D(Vector4 v1, Vector4 v2, Vector4 v3, Color c1, Color c2, Color c3);
  void transform(Matrix m);
  void calculateBarycentricCoordinates(Vector4 p, float &lambda1, float &lambda2, float &lambda3);
  void print();
};

#endif