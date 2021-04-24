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

std::ostream &operator<<(std::ostream &out, Rectangle const &rect);

Rectangle::Rectangle() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            rect[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Rectangle.                                |
 |  Argumenty:                                                                |
 |      Tablica 4 na 2 zawierajaca wspolrzedne prostokata.                    |
 |  Zwraca:                                                                   |
 |      Zestaw wspolrzednych prostokata w objekcie typu Rectangle.            |
 */
Rectangle::Rectangle(double tmp[4][2]) {
  for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 2; ++j) {
        rect[i][j]=tmp[i][j];
    }
  }
}

double &Rectangle::operator () (unsigned int point, unsigned int axis){

    if (point > 4) {
        std::cout << "Error: Wrong parameter. Only 4 points in a rectangle";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (axis > 2) {
        std::cout << "Error: Wrong parameter. Only 2 axis in a plane";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return rect[point][axis];
}

std::istream &operator>>(std::istream &in, Rectangle &rect) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            in >> rect(i, j);
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, Rectangle &Rectangle)
{
      for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 2; ++j) {
              out << Rectangle(i, j) << "   "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
          }
          std::cout << std::endl;
      }
      return out;
}





Rectangle Rectangle::operator+ (Vector const &Vect)
{
  for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 2; ++j) {
        rect[i][j]=rect[i][j]+Vect[j];
    }
  }
  return (*this);
}


Rectangle Rectangle::AngleTrans(double Angle)
{
  double Punkt_0[SIZE]={rect[0][0], rect[0][1]};
  Vector p_0=Vector(Punkt_0);
  double Punkt_1[SIZE]={rect[1][0], rect[1][1]};
  Vector p_1=Vector(Punkt_1);
  double Punkt_2[SIZE]={rect[2][0], rect[2][1]};
  Vector p_2=Vector(Punkt_2);
  double Punkt_3[SIZE]={rect[3][0], rect[3][1]};
  Vector p_3=Vector(Punkt_3);

  double Translation[][2]={{cos(Angle),-1*sin(Angle)},{sin(Angle),cos(Angle)}};
  Matrix Trans=Matrix(Translation);

  p_0=Trans*p_0;
  p_1=Trans*p_1;
  p_2=Trans*p_2;
  p_3=Trans*p_3;

  rect[0][0]=p_0[0]; rect[0][1]=p_0[1];
  rect[1][0]=p_1[0]; rect[1][1]=p_1[1];
  rect[2][0]=p_2[0]; rect[2][1]=p_2[1];
  rect[3][0]=p_3[0]; rect[3][1]=p_3[1];

  return (*this);

}
