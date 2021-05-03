#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>

template<typename T, unsigned int dime>
class Matrix {
public:

    T value[dime][dime];               // Wartosci macierzy

    Matrix();

    Matrix(T [dime][dime]);            // Konstruktor klasy

    Vector<T, dime> operator * (Vector<T, dime> tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    T  &operator () (unsigned int row, unsigned int column);

    const T &operator () (unsigned int row, unsigned int column) const;
};

template<typename T, unsigned int dime>
std::istream &operator>>(std::istream &in, Matrix<T, dime> &mat);

template<typename T, unsigned int dime>
std::ostream &operator<<(std::ostream &out, Matrix<T, dime> const &mat);

template<typename T, unsigned int dime>
T GaussMethod(Matrix<T, dime>);
