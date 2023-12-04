#ifndef COLOR_H
#define COLOR_H

#define Red Color(1.0f, 0.0f, 0.0f)
#define Green Color(0.0f, 1.0f, 0.0f)
#define Blue Color(0.0f, 0.0f, 1.0f)
#define Black Color(0.0f, 0.0f, 0.0f)
#define White Color(1.0f, 1.0f, 1.0f)

struct Color {
  float red;
  float green;
  float blue;

  Color();
  Color(float pRed, float pGreen, float pBlue);
  void clamp();
  Color operator+(const Color& c);
  Color operator-(const Color& c);
  Color operator*(const float x);
};

#endif