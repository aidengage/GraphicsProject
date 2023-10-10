#include "Color.h"
#ifndef RASTER_H
#define RASTER_H

class Raster {

  private:
    int height;
    int width;
    Color * pixels;
  public:
    Raster();
    Raster(int pWidth, int pHeight, Color pFillColor);
    ~Raster();
    int getWidth();
    int getHeight();
    Color getColorPixel(int x, int y);
    void setColorPixel(int x, int y, Color pFillColor);
    void writeToPPM();
    void clear(Color pFillColor);
    void drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor);
};

#endif