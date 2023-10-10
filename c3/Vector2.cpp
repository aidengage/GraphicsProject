#include <iostream>
#include "Vector2.h"
#include <math.h>

using namespace std;

//determinant formula
float determinant(Vector2 a, Vector2 b) { 
  return (b.x * a.y) - (a.x * b.y);
}

//Vector2 default constructor
Vector2::Vector2() {
  x = 0.0;
  y = 0.0;
}

//Vector2 constructor with 2 parameters
Vector2::Vector2(float px, float py) {
  x = px;
  y = py;
}

//returns length of vector
float Vector2::magnitude() {
  return sqrt((x*x) + (y*y));
}

//returns dot product
float Vector2::dot(Vector2 v) {
  return ((v.x * x) + (v.y * y));
}

//Vector addition overload
Vector2 Vector2::operator+(const Vector2 v){
   
  float sumx = this->x + v.x;
  float sumy = this->y + v.y;
  return Vector2(sumx, sumy);
}

//Vector2 subtraction overload
Vector2 Vector2::operator-(Vector2 v) {
  float tempx = this->x - v.x;
  float tempy = this->y - v.y;
  return Vector2(tempx, tempy);
}

//Vector2 multiplication overload
Vector2 Vector2::operator*(float scale) {
  float tempx = this->x * scale;
  float tempy = this->y * scale;
  return Vector2(tempx, tempy);
}

//finds the magnitude and returns a new Vector 2 where the magnitude is 1
Vector2 Vector2::normalize() {
  float magnitude = sqrt((x * x) + (y * y));
  return Vector2(x / magnitude, y / magnitude);
}

//creates a new vector that is perpendicular to the vector the method was called on
Vector2 Vector2::perpendicular() {
  return Vector2(y * -1, x);
}