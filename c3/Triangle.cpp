#include "Triangle.h"
#include "Color.h"
#include "Vector.h"
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
void Triangle3D::calculateBarycentricCoordinates(Vector4 p, float &lambda1, float &lambda2, float &lambda3) {
  lambda1 = ((determinant((v2 - v3), (p - v3))) / (determinant((v2 - v3), (v1 - v3))));
  lambda2 = ((determinant((p - v3), (v1 - v3))) / (determinant((v2 - v3), (v1 - v3))));
  lambda3 = 1.0 - lambda1 - lambda2;
}

Triangle2D::Triangle2D(Triangle3D t) {
  this->v1 = Vector2(t.v1.x,t.v1.y); 
  this->v2 = Vector2(t.v2.x,t.v2.y); 
  this->v3 = Vector2(t.v3.x,t.v3.y);  
  this->c1 = t.c1; 
  this->c2 = t.c2; 
  this->c3 = t.c3; 
}

Triangle3D::Triangle3D() {
  v1 = Vector4(0, 0, 0, 1);
  v2 = Vector4(0, 0, 0, 1);
  v3 = Vector4(0, 0, 0, 1);
  c1 = White;
  c2 = White;
  c3 = White;
}

Triangle3D::Triangle3D(Vector4 pv1, Vector4 pv2, Vector4 pv3, Color pc1, Color pc2, Color pc3) {
  v1 = pv1;
  v2 = pv2;
  v3 = pv3;
  c1 = pc1;
  c2 = pc2;
  c3 = pc3;
}

void Triangle3D::transform(Matrix m) {
  v1 = m * this->v1;
  v2 = m * this->v2;
  v3 = m * this->v3;
}

void Triangle3D::print() {
  v1.print();
  v2.print();
  v3.print();
}