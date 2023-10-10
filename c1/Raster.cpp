#include <iostream>
#include <fstream>
#include "Color.h"
#include "Raster.h"
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

//default constructor
  Raster::Raster() {
    height = 0;
    width = 0;
    pixels = NULL;
  }

  //3-parameter constructor
  Raster::Raster(int pWidth, int pHeight, Color pFillColor) {
    width = pWidth;
    height = pHeight;
    pixels = new Color[width * height];
    for(int i = 0; i < width*height; i++) {
      pixels[i] = pFillColor;
    }
  }

//destructor
  Raster::~Raster() {
    delete[] pixels;
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

  //takes three inputs and sets a single pixel to the color
  void Raster::setColorPixel(int x, int y, Color pFillColor) {
    pixels[(x * height) + y] = pFillColor;
  }

  //resets the raster to a single color
  void Raster::clear(Color pFillColor) {
    for(int i = 0; i < width*height; i++) {
      pixels[i] = pFillColor;
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