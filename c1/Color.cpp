#include <iostream>
#include "Color.h"
using namespace std;


//using define for preprocessor of each color

//struct Color {

  float red;
  float green;
  float blue;
//default constructor
  Color::Color() {
    red = 0.0;
    green = 0.0;
    blue = 0.0;
  }

//constructor with 3 color parameters 
  Color::Color(float pRed, float pGreen, float pBlue) {
    red = pRed;
    green = pGreen;
    blue = pBlue;
    clamp();
  }

//'clamps' the values of the colors from being entered as greater than or less than 1
  void Color::clamp() {
    if (red > 1.0) {
      red = 1.0;
    }
    if (green > 1.0) {
      green = 1.0;
    }
    if (blue > 1.0) {
      blue = 1.0;
    }
    if (red < 0.0) {
      red = 0.0;
    }
    if (green < 0.0) {
      green = 0.0;
    }
    if (blue < 0.0) {
      blue = 0.0;
    }
  }

//operator overload for the plus operator
  Color Color::operator+(const Color& c) {
    Color color;
    color.red = this->red + c.red;
    color.green = this->green + c.green;
    color.blue = this->blue + c.blue;
    color.clamp();
    return color;
  }

//operator overload for the minus operator
  Color Color::operator-(const Color& c) {
    Color color;
    color.red = this->red - c.red;
    color.green = this->green - c.green;
    color.blue = this->blue - c.blue;
    color.clamp();
    return color;
  }

//operator overload for the multiplication operator
  Color Color::operator*(const float x) {
    Color color;
    color.red = this->red * x;
    color.green = this->green * x;
    color.blue = this->blue * x;
    color.clamp();
    return color;
  }