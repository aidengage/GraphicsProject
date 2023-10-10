#ifndef TRIANGLE2D_H
#define TRIANGLE2D_H
#include "Color.h"
#include "Vector2.h"
// using namespace std;

struct Triangle2D {
  Vector2 v1;
  Vector2 v2; 
  Vector2 v3;
  Color c1;
  Color c2;
  Color c3;

  Triangle2D();
  Triangle2D(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3);
  void calculateBarycentricCoordinates(Vector2 p, float &lambda1, float &lambda2, float &lambda3);

};

#endif