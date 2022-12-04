#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "Matrix.h"
#include "Vector.h"

using namespace std;


vector<double> split_to_double(string s, char c){
    stringstream ss(s);
    string tmp;
    vector<double> res;
    while(getline(ss, tmp, c)){
       res.push_back(stod(tmp));
    }
    return res;
}


Matrix input_Matrix(string file_name){ // input should be transposed
    ifstream file(file_name);
    string line;
    Matrix m;
    while(getline(file, line)){
        vector<double> vec = split_to_double(line, ' ');
        m.AddVector(vec);
    }
    file.close();
    return m;
}

Vector input_Vector(string file_name){ // input should be transposed
    ifstream file(file_name);
    string line;
    getline(file, line);
    Vector v = Vector(split_to_double(line, ' '));
    file.close();
    return v;
}


int main(){
    Matrix A = input_Matrix("A.txt");
    A.Output();
    Vector b = input_Vector("b.txt");
    b.output();
    Vector x = A.Solve(b);
    cout << endl;
    x.output();
    return 0;
}