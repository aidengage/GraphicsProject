#include "Triangle2D.h"
#include "Color.h"
#include "Vector2.h"
#include "math.h"
using namespace std;

Triangle2D::Triangle2D() {
  v1 = Vector2();
  v2 = Vector2();
  v3 = Vector2();
  c1 = Color();
  c2 = Color();
  c3 = Color();
}

Triangle2D::Triangle2D(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3) {
  //v1 = pv1 if parameter is named pv1
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;
  this->c1 = c1;
  this->c2 = c2;
  this->c3 = c3;
}

  // calculates lambdas using determinant formula
void Triangle2D::calculateBarycentricCoordinates(Vector2 p, float &lambda1, float &lambda2, float &lambda3) {
  lambda1 = ((determinant((v2 - v3), (p - v3))) / (determinant((v2 - v3), (v1 - v3))));
  lambda2 = ((determinant((p - v3), (v1 - v3))) / (determinant((v2 - v3), (v1 - v3))));
  lambda3 = 1.0 - lambda1 - lambda2;
}