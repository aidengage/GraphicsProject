#include "Color.h"
#include "Triangle.h"
#include "Model.h"
#ifndef RASTER_H
#define RASTER_H

class Raster {

  private:
    int height;
    int width;
    Color * pixels;
    float * depths;
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
    void drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2);
    void drawTriangle2D_DotProduct(Triangle2D t);
    void drawTriangle3D_Barycentric(Triangle3D t);
    void drawModel(Model m);
    float getDepthPixel(int x, int y);
    void setDepthPixel(int x, int y, float depth);
    void clear(float depth);
};

#endif