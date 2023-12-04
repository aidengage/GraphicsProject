#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Model.h"
#include "Triangle.h"
#include <vector>

using namespace std;

Model::Model() {}

// gets number of triangles in the model
int Model::numTriangles() {
    return triangles.size();
}

// applies the transform method onto each triangle in the model
void Model::transform(Matrix m) {
    for (int i = 0; i < numTriangles(); i++) {
        if (triangles[i].shouldDraw) {
            // cout << i << endl;
            this->triangles[i].transform(m);
        }
    }
}

// performs second part of perspective matrix, homogenous divide
void Model::homogenize() {
    // cout << "in homogenize" << endl;
    for (int i = 0; i < numTriangles(); i++) {
        this->triangles[i].v1 = triangles[i].v1 * (1.0/triangles[i].v1.w);
        this->triangles[i].v2 = triangles[i].v2 * (1.0/triangles[i].v2.w);
        this->triangles[i].v3 = triangles[i].v3 * (1.0/triangles[i].v3.w);
    }
}

// performs backface culling on the model chosen
void Model::performBackfaceCulling(Vector4 eye, Vector4 spot){
    Vector4 look = (spot - eye).normalize();
    Vector4 edge1;
    Vector4 edge2;
    Vector4 temp;
    for (int i = 0; i < numTriangles(); i++) {
        edge1 = (triangles[i].v2-triangles[i].v1);
        edge2 = (triangles[i].v3-triangles[i].v1);
        temp = edge1.cross(edge2).normalize();
        if (temp.dot(look) > 0) {
            cout << "triangle culled" << endl;
            triangles[i].shouldDraw = false;
            // triangles[i].c1 = Green;
            // triangles[i].c2 = Green;
            // triangles[i].c3 = Green;
        }
    }
    // take v2-v1 = edge1
    // take v3-v1 = edge2
    // edge1 x edge2
}

// test print method
void Model::printFile(string filepath) {
    fstream myFile(filepath);
    if (myFile.is_open()) {
        string line;
        string myWord;
        while (getline(myFile, line)) {
            istringstream s(line);
            if (line[0] == 'v') {
                cout << "in v" << endl;
                while (getline(s, myWord, ' ')) {
                    cout << myWord << endl;
                }
            } 
        }
        myFile.close();
    }
}

// operator overload into triangles vector
Triangle3D Model::operator[](int i) {
    return triangles[i];
}

// reads obj file and creates the triangles vector
void Model::readFromOBJFile(string filepath, Color pFillColor) {
vector<Vector4> vertices;
vector<float> vectors;
vector<int> faces;
ifstream myFile(filepath);

    if (myFile.is_open()) {
        cout << "file opened" << endl;
        string line;
        string myWord;
        int skipLine = 0;

        while (getline(myFile, line)) {
            istringstream s(line);
            // cout << "I'm here!" << endl;

            switch (line[0]) {
                case '#':
                    break;
                case 'v':
                    while (getline(s, myWord, ' ')) {
                    // cout << "in while loop" << endl;
                        if (myWord != "v") {
                            vectors.push_back(atof(myWord.c_str()));
                        }
                    }
                    vertices.push_back(Vector4(vectors[0], vectors[1], vectors[2], 1));
                    // cout << vectors[0] << " " << vectors[1] << " " << vectors[2] << endl;
                    vectors.clear();
                    break;
                case 'f':
                    while (getline(s, myWord, ' ')) {
                        if (myWord != "f") {
                            faces.push_back((atoi(myWord.c_str())) - 1);
                        }
                    }
                    for (int i = 2; i < faces.size(); i++) {
                        triangles.push_back(Triangle3D(vertices[faces[i - 2]], vertices[faces[i - 1]], vertices[faces[i]], pFillColor, pFillColor, pFillColor));
                    }
                faces.clear();
            }
        }
        myFile.close();
        cout << "file closed" << endl;
    }
}