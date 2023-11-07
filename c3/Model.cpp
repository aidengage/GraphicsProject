#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Model.h"
#include "Triangle.h"
#include <vector>

using namespace std;

Model::Model() {}

int Model::numTriangles() {
    return triangles.size();
}

void Model::transform(Matrix m) {
    for (int i = 0; i < numTriangles(); i++) {
        this->triangles[i].transform(m);
    }
}

void Model::printFile(string filepath) {
    // string line = "this is a line with words in it";
    // istringstream s(line);
    // string myWord;
    // while (getline(s, myWord, ' ')) {
    //     cout << "this is a word" << endl;
    // }
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
            // else if (line[0] == 'f') {
            //     cout << "in f" << endl;
            // }
            // cout << line << endl;
            // while(getline(s, myWord, ' ')) {
            //     cout << s << endl;
            //     cout << "in loop" << endl;
            // }
        }
        myFile.close();
    }
}

Triangle3D Model::operator[](int i) {
    return triangles[i];
}

/*void Model::readFromOBJFile(string filepath, Color pFillColor) {
    vector<Vector4> vertices;
    vector<float> refv;
    vector<int> reff;
    ifstream myFile(filepath);

    if (myFile.is_open()) {
        cout << "file opened" << endl;
        string line;
        string myWord;

        while (getline(myFile, line)) {
            istringstream s(line);
            // cout << "I'm here!" << endl;
            if (line[0] == 'v') {
                // cout << "im in v look at me" << endl;
                while (getline(s, myWord, ' ')) {
                    // cout << "in while loop" << endl;
                    if (myWord != "v") {
                        refv.push_back(atof(myWord.c_str()));
                    }
                }
                vertices.push_back(Vector4(refv[0], refv[1], refv[2], 1));
                cout << refv[0] << " " << refv[1] << " " << refv[2] << endl;
                refv.clear();

            } else if (line[0] == 'f') {
                // cout << "now im in f" << endl;
                while (getline(s, myWord, ' ')) {
                    if (myWord != "f") {
                        reff.push_back((atoi(myWord.c_str())) - 1);
                    }
                }
                // for (int i = 0; i < reff.size(); i++) {
                //     cout << reff[i] << " ";
                // }
                // cout << endl;
                if (reff.size() == 3) {
                    triangles.push_back(Triangle3D(vertices[reff[0]], vertices[reff[1]], vertices[reff[2]], pFillColor, pFillColor, pFillColor));
                } else {
                    triangles.push_back(Triangle3D(vertices[reff[0]], vertices[reff[1]], vertices[reff[2]], pFillColor, pFillColor, pFillColor));
                    triangles.push_back(Triangle3D(vertices[reff[1]], vertices[reff[2]], vertices[reff[3]], pFillColor, pFillColor, pFillColor));
                }
                reff.clear();
            }
        }
        myFile.close();
        cout << "file closed" << endl;
    }*/

    void Model::readFromOBJFile(string filepath, Color pFillColor) {
    vector<Vector4> vertices;
    vector<float> refv;
    vector<int> reff;
    ifstream myFile(filepath);

    if (myFile.is_open()) {
        cout << "file opened" << endl;
        string line;
        string myWord;

        while (getline(myFile, line)) {
            istringstream s(line);
            // cout << "I'm here!" << endl;=

            switch (line[0]) {
                case '#':
                    break;
                case 'v':
                    while (getline(s, myWord, ' ')) {
                    // cout << "in while loop" << endl;
                        if (myWord != "v") {
                            refv.push_back(atof(myWord.c_str()));
                        }
                    }
                    vertices.push_back(Vector4(refv[0], refv[1], refv[2], 1));
                    // cout << refv[0] << " " << refv[1] << " " << refv[2] << endl;
                    refv.clear();
                    break;
                case 'f':
                    while (getline(s, myWord, ' ')) {
                        if (myWord != "f") {
                            reff.push_back((atoi(myWord.c_str())) - 1);
                        }
                    }
                    if (reff.size() == 3) {
                        triangles.push_back(Triangle3D(vertices[reff[0]], vertices[reff[1]], vertices[reff[2]], pFillColor, pFillColor, pFillColor));
                    } else {
                        triangles.push_back(Triangle3D(vertices[reff[0]], vertices[reff[1]], vertices[reff[2]], pFillColor, pFillColor, pFillColor));
                        triangles.push_back(Triangle3D(vertices[reff[1]], vertices[reff[2]], vertices[reff[3]], pFillColor, pFillColor, pFillColor));
                    }
                    reff.clear();
                    }
                }
                myFile.close();
                cout << "file closed" << endl;
                // for (int i = 0; i < reff.size(); i++) {
                //     cout << reff[i] << " ";
                // }
                // cout << endl;
                
            
        }
       
    }
    // for (int i = 0; i < triangles.size(); i++) {
    //     triangles[i].v1.print();
    // }
// }