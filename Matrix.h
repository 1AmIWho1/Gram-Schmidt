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
    void Transpose();
    void GramSchmidt();
    void AddVector(vector<double> vec);
    void Output();
};
