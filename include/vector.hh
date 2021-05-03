#pragma once

#include "size.hh"
#include <iostream>

template<typename T, unsigned int dime>
class Vector {

public:

    T size[dime];     //Tablica wektora

    Vector();

    Vector(T [dime]);

    Vector operator + (const Vector<T, dime> v);

    Vector operator - (const Vector<T, dime> v);

    Vector operator * (const T &tmp);

    Vector operator / (const T &tmp);

    const T &operator [] (int index) const;

    T &operator [] (int index);

    bool operator == (const Vector<T, dime> ) const;

};

template<typename T, unsigned int dime>
std::ostream &operator << (std::ostream &out, Vector<T, dime> const &tmp);

template<typename T, unsigned int dime>
std::istream &operator >> (std::istream &in, Vector<T, dime> &tmp);
