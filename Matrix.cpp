#include "Matrix.h"

Matrix::Matrix(){
}

Matrix::~Matrix(){
}

Vector Projection(Vector a, Vector b){
    double dot_product_ab = a * b;
    double dot_product_bb = b * b;
    if(isinf(dot_product_ab / dot_product_bb))
        throw("Division by zero in Projetcion!");
    return b * (dot_product_ab / dot_product_bb);
}


void Matrix::GramSchmidt(){
    vector<Vector> b;
    vector<Vector> e;
    for(size_t i = 0; i < vectors.size(); ++i){
        Vector tmp = vectors.at(i);
        for(size_t j = 0; j < i; ++j)
            tmp -= Projection(vectors.at(i), b.at(j));
        b.push_back(tmp);
        e.push_back(tmp / tmp.norm());
    }
    vectors = b;
    Output();
    vectors = e;
}

void Matrix::Transpose(){
}

void Matrix::AddVector(vector<double> vec){
    vectors.push_back(vec);
}

void Matrix::Output(){
    cout << "Matrix:" << endl;
    for(Vector vec : vectors)
        cout << vec << endl;
}


