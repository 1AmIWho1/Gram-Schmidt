#include "Vector.h"


Vector::Vector(){
}

Vector::Vector(vector<double> vec){
    this->vec = vector<double>(vec);
}

Vector::~Vector(){
}

size_t Vector::size() const{
    return vec.size();
}

void Vector::push_back(double x){
    vec.push_back(x);
}

const double Vector::at(size_t id) const{
    return vec.at(id);
}

double Vector::norm() const{
    double res = 0;
    for(double a : vec)
        res += a * a;
    return sqrt(res);
}

void Vector::output() const{
    for(double n : vec)
        cout << n << endl;
}

Vector Vector::operator+(const Vector v){
    Vector res;
    for(size_t i = 0; i < size(); ++i)
        res.push_back(v.at(i) + at(i));
    return res;
}

Vector Vector::operator-(const Vector v){
    Vector res;
    for(size_t i = 0; i < size(); ++i)
        res.push_back(at(i) + v.at(i));
    return res;
}

Vector Vector::operator*(const double x){
    Vector res;
    for(double a : vec)
        res.push_back(a * x);
    return res;
}

double Vector::operator*(const Vector v){
    double res = 0;
    for(size_t i = 0; i < size(); ++i)
        res += at(i) * v.at(i);
    return res;
}

Vector& Vector::operator*=(const double x){
    for(size_t i = 0; i < size(); ++i)
        vec[i] *= x;
    return *this;
}

Vector& Vector::operator/=(const double x){
    for(size_t i = 0; i < size(); ++i)
        vec[i] /= x;
    return *this;
}

Vector& Vector::operator-=(const Vector v){
    for(size_t i = 0; i < size(); ++i)
        vec[i] -= v.at(i);
    return *this;
}

Vector& Vector::operator+=(const Vector v){
    for(size_t i = 0; i < size(); ++i)
        vec[i] += v.at(i);
    return *this;
}

Vector Vector::operator/(const double x){
    if(isinf(1.0 / x))
        return *this;
    Vector res;
    for(double a : vec)
        res.push_back(a / x);
    return res;
}

Vector& Vector::operator=(const Vector v){
    if (this == &v) {
            return *this;
        }
    vec = vector<double>(v.vec);
    return *this;
}
