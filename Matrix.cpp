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
            double alfa = qk * Q.at(j);
            qk -= Q.at(j) * alfa;
        }
        Q.push_back(qk / qk.norm());
    }
    vectors = Q;
}

Vector Projection(Vector a, Vector b){
    double dot_product_ab = a * b;
    double dot_product_bb = b * b;
    if(isinf(dot_product_ab / dot_product_bb))
        throw("Division by zero in Projetcion!");
    return b * (dot_product_ab / dot_product_bb);
}

void Matrix::OldGramSchmidt(){
    vector<Vector> b;
    vector<Vector> Q;
    for(size_t i = 0; i < vectors.size(); ++i){
        Vector q = vectors.at(i);
        for(size_t j = 0; j < i; ++j)
            q -= Projection(vectors.at(i), b.at(j));
        b.push_back(q);
        Q.push_back(q / q.norm());
    }
    //vectors = b;
    //Output();
    vectors = Q;
}

Vector Matrix::Solve(Vector b, Matrix J){
    Vector x;
    for(size_t i = 0; i < vectors.size(); ++i)
        x.push_back(0);
    for(size_t i = 0; i < vectors.size(); ++i)
        x += J.vectors.at(i) * (b * vectors.at(i));
    return x;
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

void Matrix::Append(Matrix b){
    for(Vector vec : b.vectors)
        vectors.push_back(vec);
}

Matrix Matrix::I(){
    Matrix res;
    if(vectors.size() != vectors.at(0).size())
        return res;
    for(size_t i = 0; i < vectors.size(); ++i){
        Vector v;
        for(size_t j = 0; j < vectors.size(); ++j)
            if(j == i)
                v.push_back(1);
            else
                v.push_back(0);
        res.vectors.push_back(v);
    }
    return res;
}
