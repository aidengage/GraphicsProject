#include <iostream>
#include "Raster.h"
#include "Color.h"
using namespace std;

int main() {
  cout << "test1 ";
  Raster* r1 = new Raster(20, 20, Blue);
  cout << "test";
  // r1->drawLine_DDA(1, 8, 9, 5, Red); //x1, y1, x2, y2
  // r1->drawLine_DDA(10, 1, 10, 10, Green); //x1, y1, x2, y2
  // r1->drawLine_DDA(1, 10, 10, 10, Green); //x1, y1, x2, y2
  // r1->drawLine_DDA(0, 0, 1, 1, White); //x1, y1, x2, y2
  // r1->drawLine_DDA(19, 19, 20, 20, Black);
  // r1->drawLine_DDA(10, 10, 5, 5, White);
  // cout << r1->getWidth() << endl;
  // cout << r1->getHeight() << endl;
  // r1->getColorPixel(10, 10);
  // r1->setColorPixel(10, 10, Green);
  // r1->getColorPixel(10, 10);
  // r1->writeToPPM();
  r1->drawLine_DDA(0, 0, 10, 20, White);
  r1->drawLine_DDA(5, 0, 10, 10, Red);
  r1->drawLine_DDA(0, 17, 3, 2, Green);
  r1->drawLine_DDA(20, 20, 8, 3, Color(0.2f, 0.5f, 0.0f));
  r1->writeToPPM();
}