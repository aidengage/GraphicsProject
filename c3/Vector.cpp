#include <iostream>
#include "Vector.h"
#include <math.h>

using namespace std;

//determinant formula
// comment
float determinant(Vector2 a, Vector2 b) { 
  return (b.x * a.y) - (a.x * b.y);
}

float determinant(Vector4 a, Vector4 b) { 
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
  return sqrt((x * x) + (y * y));
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

Vector4::Vector4() {
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
  w = 0.0f;
}

Vector4::Vector4(float px, float py, float pz, float pw) {
  x = px;
  y = py;
  z = pz;
  w = pw;
}

// figure out how w coordinate works with addition and how to account for it
Vector4 Vector4::operator+(const Vector4 v){
  float sumx = this->x + v.x;
  float sumy = this->y + v.y;
  float sumz = this->z + v.z;
  float sumw = this->w + v.w;
  return Vector4(sumx, sumy, sumz, sumw);
}

// figure out how w coordinate works with subtraction and how to account for it
Vector4 Vector4::operator-(const Vector4 v) {
  float tempx = this->x - v.x;
  float tempy = this->y - v.y;
  float tempz = this->z - v.z;
  float tempw = this->w - v.w;
  return Vector4(tempx, tempy, tempz, tempw);
}

Vector4 Vector4::operator*(float scale) {
  float tempx = this->x * scale;
  float tempy = this->y * scale;
  float tempz = this->z * scale;
  // float tempw = this->w * scale;
  
  return Vector4(tempx, tempy, tempz, this->w);
}

float Vector4::magnitude() {
  return sqrt((x * x) + (y * y) + (z * z));
}

Vector4 Vector4::normalize() {
  float magnitude = sqrt((x * x) + (y * y) + (z * z));
  return Vector4(x / magnitude, y / magnitude, z / magnitude, w);
}

float Vector4::dot(Vector4 v) {
  return ((v.x * x) + (v.y * y) + (v.z * z));
}

void Vector4::print() {
  cout << this->x << " ";
  cout << this->y << " ";
  cout << this->z << " ";
  cout << this->w << endl;
}