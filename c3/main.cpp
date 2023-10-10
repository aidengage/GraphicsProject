#include "Color.h"
#include "Raster.h"
#include "Triangle2D.h"
#include <iostream>
using namespace std;

int main() {
  cout << "test1 ";
  // Raster *r1 = new Raster(100, 100, White);
  Raster *r1 = new Raster(20, 20, White);
  r1->drawLine_DDA_Interpolated(4, 10, 4, 0, Blue, Red); // tested with raster size 20x20
  r1->drawLine_DDA_Interpolated(0, 4, 20, 4, Red, Blue); // tested with raster size 20x20
  // r1->drawLine_DDA_Interpolated(20, 4, 0, 4, Red, Blue); // tested with raster size 20x20
  // r1->drawLine_DDA_Interpolated(0, 0, 19, 19, Blue, Red); // tested with raster size 20x20
  cout << "test";
  // r1->drawLine_DDA(1, 8, 9, 5, Red);      // x1, y1, x2, y2
  // r1->drawLine_DDA(10, 1, 10, 10, Green); // x1, y1, x2, y2
  // r1->drawLine_DDA(1, 10, 10, 10, Green); // x1, y1, x2, y2
  // r1->drawLine_DDA(0, 0, 1, 1, White);    // x1, y1, x2, y2
  // r1->drawLine_DDA(19, 19, 20, 20, Black);
  // r1->drawLine_DDA(10, 10, 5, 5, White);
  // cout << r1->getWidth() << endl;
  // cout << r1->getHeight() << endl;
  // r1->getColorPixel(10, 10);
  // r1->setColorPixel(10, 10, Green);
  // r1->getColorPixel(10, 10);
  // r1->drawLine_DDA(20, 20, 8, 3, Color(0.2f, 0.5f, 0.0f));
  // Vector2 v1(2, 2);
  // Vector2 v2(4, 18);
  // Vector2 v3(17, 17);
  // cout << endl;
  // cout << (((v1-v3).perpendicular())-v3).x << " " << (((v1-v3).perpendicular())-v3).y; 
  // Triangle2D t1(Vector2(20, 10), Vector2(90, 80), Vector2(12, 60), Blue, Red, Green);
  // r1->drawTriangle2D_DotProduct(t1);
  // r1->drawTriangle_Barycentric(t1);

  r1->writeToPPM();
}