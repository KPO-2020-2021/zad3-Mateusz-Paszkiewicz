#pragma once

#include "matrix.hh"
#include <cmath>

//    BUDOWA PROSTKATA :
//
//    rect[punkt][1]=x_punktu
//    rect[punkt][2]=y_punktu
//
//  0  *------------*  1
//     |            |
//     |            |
//     |            |
//  3  *------------*  2

class Rectangle {

public:
    double rect[4][2];

    Rectangle();

    Rectangle(double [4][2]);

    Rectangle operator+ (Vector const &);

    Rectangle AngleTrans(double Angle);

    double &operator () (unsigned int point, unsigned int axis);

    Rectangle operator* (Vector const &);

};

std::istream &operator>>(std::istream &in, Rectangle &rect);

std::ostream &operator<<(std::ostream &out, Rectangle &rect);
