#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Vector{
private:
    vector<double> vec;

public:
    Vector();
    Vector(vector<double> vec);
    ~Vector();
    size_t size(void) const;
    const double at(size_t id) const;
    void push_back(double x);
    double norm() const;
    void output() const;
    Vector operator+(const Vector v);
    Vector operator-(const Vector v);
    double operator*(const Vector v); // scalar
    Vector operator*(const double x);
    Vector operator/(const double x);
    Vector& operator*=(const double x);
    Vector& operator/=(const double x);
    Vector& operator-=(const Vector v);
    Vector& operator+=(const Vector v);
    Vector& operator=(const Vector v);

    /*friend ostream& operator<<(ostream& os, const Vector& v){
        for(size_t i = 0; i < v.size(); ++i)
            os << v.at(i) << endl;
        return os;
    }*/

};
