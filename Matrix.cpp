#include "Matrix.h"

Matrix::Matrix(){
}

Matrix::~Matrix(){
}

void Matrix::GramSchmidt(){
    vector<Vector> Q;
    for(size_t i = 0; i < vectors.size(); ++i){
        Vector a_qk = vectors.at(i);
        for(size_t j = 0; j < i; ++j)
            a_qk -= Q.at(j) * (vectors.at(i) * Q.at(j));
        Q.push_back(a_qk / a_qk.norm());
    }
    vectors = Q;
}

void Matrix::ModGramSchmidt(){
    vector<Vector> Q;
    for(size_t i = 0; i < vectors.size(); ++i){
        Vector qk = vectors.at(i);
        for(size_t j = 0; j < i; ++j){
            double alpha = qk * Q.at(j);
            qk -= Q.at(j) * alpha;
        }
        Q.push_back(qk / qk.norm());
    }
    vectors = Q;
}

Vector projection(Vector a, Vector b){
    double dot_product_ab = a * b;
    double dot_product_bb = b * b;
    return b * (dot_product_ab / dot_product_bb);
}

void Matrix::OldGramSchmidt(){
    vector<Vector> b;
    vector<Vector> Q;
    for(size_t i = 0; i < vectors.size(); ++i){
        Vector q = vectors.at(i);
        for(size_t j = 0; j < i; ++j)
            q -= projection(vectors.at(i), b.at(j));
        b.push_back(q);
        Q.push_back(q / q.norm());
    }
    //vectors = b;
    //Output();
    vectors = Q;
}

Vector Matrix::Solve(Vector b){
    vectors.push_back(b);
    for(size_t i = 0; i < vectors.size() - 1; ++i){
        vectors.at(i).push_back(0);
    }
    vectors.at(vectors.size() - 1).push_back(1);
    //Output();
    T();
    //Output();
    GramSchmidt();
    //Output();
    Vector x;
    size_t n = vectors.size() - 1;
    for(size_t i = 0; i < n; ++i){
        x.push_back(vectors.at(n).at(i) / vectors.at(n).at(n));
    }
    return x * (-1);
}

Vector Matrix::SolveMod(Vector b){
    vectors.push_back(b);
    for(size_t i = 0; i < vectors.size() - 1; ++i){
        vectors.at(i).push_back(0);
    }
    vectors.at(vectors.size() - 1).push_back(1);
    //Output();
    T();
    //Output();
    ModGramSchmidt();
    //Output();
    Vector x;
    size_t n = vectors.size() - 1;
    for(size_t i = 0; i < n; ++i){
        x.push_back(vectors.at(n).at(i) / vectors.at(n).at(n));
    }
    return x * (-1);
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
