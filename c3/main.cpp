#include "Color.h"
#include "Model.h"
#include "Raster.h"
#include "Triangle.h"
#include "Matrix.h"
#include <iostream>
// #include <tim
using namespace std;

int main() {
  //cout << "test1 ";
  // Raster *r1 = new Raster(100, 100, White);
  // Raster *r1 = new Raster(20, 20, White);
  // r1->drawLine_DDA_Interpolated(4, 10, 4, 0, Blue, Red); // tested with raster size 20x20
  // r1->drawLine_DDA_Interpolated(0, 4, 20, 4, Red, Blue); // tested with raster size 20x20
  // r1->drawLine_DDA_Interpolated(20, 4, 0, 4, Red, Blue); // tested with raster size 20x20
  // r1->drawLine_DDA_Interpolated(0, 0, 19, 19, Blue, Red); // tested with raster size 20x20
  //cout << "test";
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
  // r1->drawTriangle2D_Barycentric(t1);

  // r1->writeToPPM();

  // Matrix A(1,2,3,4,
  //         5,6,7,8,
  //         9 , 10 , 11 , 12 ,
  //         13 , 14 , 15 , 16);
  // Matrix B(17 , 18 , 19 , 20 ,
  //           21 , 22 , 23 , 24 ,
  //         25 , 26 , 27 , 28 ,
  //         29 , 30 , 31 , 32);

  // Matrix C = A * B; 
  // C.print();

      

  // Vector4 D(1, 1, 1, 1);
  // Vector4 H = A * D;
  // H.print();

  Raster myRaster(100,100,White);
  // Triangle3D t(Vector4(10, 10, 0, 1), Vector4(40, 20, 0, 1), Vector4(50, 50, 20, 1), Red, Blue, Green);
  // teapot.printFile("./teapot.obj");

  Model teapot = Model();
  teapot.readFromOBJFile("./teapot.obj", Red);

  // translate3d does not work lmao, transform kind of works?
  // rotatez3d needs work
  // Matrix m = RotateY3D(-180.0) * Scale3D(0.5, 0.5, 0.5);//Translate3D(50, 50, 0) * RotateZ3D(-45.0) * Scale3D(0.5, 0.5, 0.5);
  Matrix m = Translate3D(50, 50, 0) * RotateZ3D(-45.0) * Scale3D(0.5, 0.5, 0.5);
  // Vector4 v2(4, 4, 1, 1);
  // Matrix m = Translate3D(50, 50, 0) * Rotate3D(-45.0, -45.0, -45.0) * Scale3D(0.5, 0.5, 0.5);
  // Matrix m = Translate3D(50, 50, 0);
  // m.print();
  // Matrix m = RotateY3D(45.0);
  // t.transform(m);
  // t.print();
  // Vector4 v(10, 10, 0, 1);
  // (m*v).print();
  // myRaster.drawTriangle3D_Barycentric(t);
  teapot.transform(m);
  // m.print();
  /**/
  cout << "going to draw model" << endl;
  // cout << "there are " << teapot.numTriangles() << " triangles" << endl;

  // cout << endl;
  // teapot[640].v1.print();
  // teapot[640].v2.print();
  // teapot[640].v3.print();

  myRaster.drawModel(teapot);
  
  cout << "model drawn" << endl;
  myRaster.writeToPPM();

}