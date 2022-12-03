#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "Matrix.h"

using namespace std;


vector<double> split_to_int(string s, char c){
    stringstream ss(s);
    string tmp;
    vector<double> res;
    while (getline(ss, tmp, c)){
       res.push_back(stod(tmp));
    }
    return res;
}


int main(){
    ifstream file("input.txt");
    string line;
    Matrix m;
    while(getline(file, line)){
        vector<double> vec = split_to_int(line, ' ');
        m.AddVector(vec);
    }
    file.close();
    m.Output();
    m.GramSchmidt();
    m.Output();
    return 0;
}