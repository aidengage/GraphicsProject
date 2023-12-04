#include <iostream>
#include <fstream>
#include "Color.h"
#include "Raster.h"
#include "Model.h"
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits>

using namespace std;

//default constructor
Raster::Raster() {
  height = 0;
  width = 0;
  pixels = NULL;
  // check 4
  depths = NULL;
}

//3-parameter constructor
Raster::Raster(int pWidth, int pHeight, Color pFillColor) {
  width = pWidth;
  height = pHeight;
  pixels = new Color[width * height];
  depths = new float[width * height];
  for(int i = 0; i < width*height; i++) {
    pixels[i] = pFillColor;
  }
  // check 4
  for (int i = 0; i < width*height; i++) {
    depths[i] = numeric_limits<float>::max();
  }
}

//destructor
Raster::~Raster() {
  delete[] pixels;
  delete[] depths;
}

//copies info to a PPM file that can be externally used and observed
void Raster::writeToPPM() {
  ofstream rasterFile("FRAME_BUFFER.ppm");
  rasterFile << "P3" << endl;
  rasterFile << width << " " << height << endl;
  rasterFile << "255" << endl;
  for (int y = height -1; y >= 0; y--) {
  // ^^^ our height needed to be drawn from bottom to top, we had the other way around
    for (int x = 0; x < width; x++) {
      rasterFile << int(getColorPixel(x, y).red * 255) << " " << int(getColorPixel(x, y).green * 255) << " " << int(getColorPixel(x, y).blue * 255) << " ";
      // ^^^ we had our x and y values swapped, and i changed them from j and i to x and y
      // also type cast colors to int values to allow for other colors to actually work
    }
    rasterFile << endl;
  }
  rasterFile.close();
}

//returns width
int Raster::getWidth() {
  return width;
}

//returns height
int Raster::getHeight() {
  return height;
}

//returns a color pixel
Color Raster::getColorPixel(int x, int y) {
  return pixels[(x * height) + y];
}

// check 4
float Raster::getDepthPixel(int x, int y) {
  return depths[(x * height) + y];
}

//takes three inputs and sets a single pixel to the color
void Raster::setColorPixel(int x, int y, Color pFillColor) {
  if ((y >= 0 && y < height) && (x >= 0 && x < width)) {
    pixels[(x * height) + y] = pFillColor;
  }
}

// check 4
void Raster::setDepthPixel(int x, int y, float depth) {
  if ((y >= 0 && y < height) && (x >= 0 && x < width)) {
    depths[(x * height) + y] = depth;
  }
}

//resets the raster to a single color
void Raster::clear(Color pFillColor) {
  for(int i = 0; i < width*height; i++) {
    pixels[i] = pFillColor;
  }
}

// sets the entire z depth to a number
void Raster::clear(float depth) {
  for (int i = 0; i < width*height; i++) {
    depths[i] = depth;
  }
}

//Takes five parameters and draws a line segment
void Raster::drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor) {
  float increments = 0;

  //determines if rise is greater than run in order to find which axis to increment on
  if ((abs(y2 - y1) > abs(x2 - x1))) {
    increments = abs(y2 - y1);
  }
  else {
    increments = abs(x2 - x1);
  }

  //finds the amount to step on the x and y axis
  float stepx = (x2 - x1) / increments;
  float stepy = (y2 - y1) / increments;

  //temporary variables to increment with
  float tempx = x1;
  float tempy = y1;

  //sets the color pixels that sit along the increments
  for (int i = 0; i < increments; i++) {
    setColorPixel(tempx, tempy, fillColor);
    tempx+=stepx;
    tempy+=stepy;
  }
}

// draws an interpolated line with 2 colors
void Raster::drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2) {
  float increments = 0.0;

  //determines if rise is greater than run in order to find which axis to increment on
  if ((abs(y2 - y1) > abs(x2 - x1))) {
    increments = abs(y2 - y1);
  }
  else {
    increments = abs(x2 - x1);
  }

  //finds the amount to step on the x and y axis
  float stepx = (x2 - x1) / increments;
  float stepy = (y2 - y1) / increments;

  //temporary variables to increment with
  float tempx = x1;
  float tempy = y1;

  float lengthRatio;

  //sets the color pixels that sit along the increments
  for (float i = 0.0; i <= increments; i++) {
    lengthRatio = (i / increments);
    setColorPixel(tempx, tempy, (color2) * (lengthRatio) + (color1) * (1.0f - lengthRatio));
    tempx+=stepx;
    tempy+=stepy;
  }
}

// draws a 2d triangles with dot product
void Raster::drawTriangle2D_DotProduct(Triangle2D t) {
  float result1;
  float result2;
  float result3;

  float minX;
  float maxX;
  float minY;
  float maxY;

  // gets smallest x
  if (t.v1.x <= t.v2.x && t.v1.x <= t.v3.x) {
    minX = t.v1.x;
  } else if (t.v2.x <= t.v1.x && t.v2.x <= t.v3.x) {
    minX = t.v2.x;
  } else {
    minX = t.v3.x;
  }
  // gets largest x
  if (t.v1.x >= t.v2.x && t.v1.x >= t.v3.x) {
    maxX = t.v1.x;
  } else if (t.v2.x >= t.v1.x && t.v2.x >= t.v3.x) {
    maxX = t.v2.x;
  } else {
    maxX = t.v3.x;
  }
  //gets smallest y
  if (t.v1.y <= t.v2.y && t.v1.y <= t.v3.y) {
    minY = t.v1.y;
  } else if (t.v2.y <= t.v1.y && t.v2.y <= t.v3.y) {
    minY = t.v2.y;
  } else {
    minY = t.v3.y;
  }
  // gets largest y
  if (t.v1.y >= t.v2.y && t.v1.y >= t.v3.y) {
    maxY = t.v1.y;
  } else if (t.v2.y >= t.v1.y && t.v2.y >= t.v3.y) {
    maxY = t.v2.y;
  } else {
    maxY = t.v3.y;
  }

  // Vector2 p;
  for(int x = minX ; x <= maxX; x++){
    for(int y = minY ; y <= maxY; y++){
      Vector2 p(x, y);
      Vector2 edge1 = t.v2 - t.v1;
      Vector2 edge1perp = edge1.perpendicular();
      Vector2 g1 = p - t.v1;
      result1 = edge1perp.dot(g1);

      Vector2 edge2 = t.v3 - t.v2;
      Vector2 edge2perp = edge2.perpendicular();
      Vector2 g2 = p - t.v2;
      result2 = edge2perp.dot(g2);

      Vector2 edge3 = t.v1 - t.v3;
      Vector2 edge3perp = edge3.perpendicular();
      Vector2 g3 = p - t.v3;
      result3 = edge3perp.dot(g3);

      if ((result1 >= 0.0) && (result2 >= 0.0) && (result3 >= 0.0)){
        setColorPixel(x, y, t.c1);
      }
    }
  }
}

// draws 3d triangles with barycentric
void Raster::drawTriangle3D_Barycentric(Triangle3D t) {
  // cout << "in draw triangle 3d" << endl;
  if (t.shouldDraw) {
    float minX = min(t.v1.x, min(t.v2.x, t.v3.x));
    float maxX = max(t.v1.x, max(t.v2.x, t.v3.x));
    float minY = min(t.v1.y, min(t.v2.y, t.v3.y));
    float maxY = max(t.v1.y, max(t.v2.y, t.v3.y));

    for (int x = minX; x <= maxX; x++) {
      for (int y = minY; y <= maxY; y++) {

        float lambda1;
        float lambda2;
        float lambda3;
        t.calculateBarycentricCoordinates(Vector4((x), (y), 0, 0), lambda1, lambda2, lambda3);
        if ((lambda1 >= 0 && lambda2 >= 0 && lambda3 >= 0 && x >= 0) && (getDepthPixel(x, y) > (t.v1.z*lambda1 + t.v2.z*lambda2 + t.v3.z*lambda3))) {
          setColorPixel(x, y, Color(t.c1*lambda1 + t.c2*lambda2 + t.c3*lambda3));
          setDepthPixel(x, y, (t.v1.z*lambda1 + t.v2.z*lambda2 + t.v3.z*lambda3));
        }
      }
    }
  }
}

// draws model
void Raster::drawModel(Model m) {
  // cout << "outside draw for loop" << endl;
  for (int i = 0; i < m.numTriangles(); i++) {
    drawTriangle3D_Barycentric(m[i]);
  }
}