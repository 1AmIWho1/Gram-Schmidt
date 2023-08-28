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
    Vector Solve(Vector b);
    Vector SolveMod(Vector b);
    void AddVector(vector<double> vec);
    void Output();
    Matrix operator*(const Matrix b);
    Vector operator*(const Vector b);
};
