#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "Matrix.h"

using namespace std;


vector<double> split_to_int(string s, char c){ // input should be transposed
    stringstream ss(s);
    string tmp;
    vector<double> res;
    while(getline(ss, tmp, c)){
       res.push_back(stod(tmp));
    }
    return res;
}


Matrix input_Matrix(string file_name){
    ifstream file(file_name);
    string line;
    Matrix m;
    while(getline(file, line)){
        vector<double> vec = split_to_int(line, ' ');
        m.AddVector(vec);
    }
    file.close();
    return m;
}


int main(){
    Matrix m = input_Matrix("input.txt");
    Matrix m1 = input_Matrix("input1.txt");
    m.Output();
    m1.Output();
    Matrix res = m * m1;
    res.Output();
    //m.GramSchmidt();
    //m.Output();
    return 0;
}