#pragma once

#include "size.hh"
#include <iostream>

class Vector {

public:

    double size[SIZE];     //Tablica wektora

    Vector();

    Vector(double [SIZE]);

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    bool operator == (const Vector&) const;

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);
