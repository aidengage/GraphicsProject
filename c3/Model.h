#ifndef MODEL_H
#define MODEL_H
#include "Triangle.h"
#include <vector>

using namespace std;

class Model {
    private:
        vector<Triangle3D> triangles;
    public:
        Model();
        int numTriangles();
        Triangle3D operator[](int i);
        void transform(Matrix m);
        void readFromOBJFile(string filepath, Color pFillColor);
        void printFile(string filepath);
};

#endif