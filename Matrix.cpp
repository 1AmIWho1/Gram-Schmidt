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

void Matrix::T(){
    vector<Vector> new_vectors;
    for(size_t i = 0; i < vectors.at(0).size(); ++i){
        Vector vec;
        for(size_t j = 0; j < vectors.size(); ++j){
            vec.push_back(vectors.at(j).at(i));
        }
        new_vectors.push_back(vec);
    }
    vectors = new_vectors;
}

void Matrix::AddVector(vector<double> vec){
    vectors.push_back(vec);
}

void Matrix::Output(){
    cout << "Matrix:" << endl;
    for(size_t i = 0; i < vectors.at(0).size(); ++i){
        Vector vec;
        for(size_t j = 0; j < vectors.size(); ++j){
            cout << vectors.at(j).at(i) << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator*(const Matrix b){
    Matrix res;
    for(size_t i = 0; i < b.vectors.size(); ++i){
        Vector tmp;
        for(size_t j = 0; j < vectors.at(0).size(); ++j){
            double element = 0;
            for(size_t k = 0; k < vectors.size(); ++k){
                element += vectors.at(k).at(j) * b.vectors.at(i).at(k);
            }
            tmp.push_back(element);
        }
        res.vectors.push_back(tmp);
    }
    return res;
}
