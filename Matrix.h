#pragma once

#include <vector>
#include <iostream>
#include <cmath>

#include "Vector.h"

using namespace std;


class Matrix{
private:
    vector<Vector> vectors;

public:
    Matrix();
    ~Matrix();
    void T();
    void GramSchmidt();
    void ModGramSchmidt();
    void OldGramSchmidt();
    Matrix I();
    Vector Solve(Vector b, Matrix J);
    void AddVector(vector<double> vec);
    void Append(Matrix b);
    void Output();
    Matrix operator*(const Matrix b);

};
