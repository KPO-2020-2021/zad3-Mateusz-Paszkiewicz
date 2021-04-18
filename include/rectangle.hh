#pragma once

#include "matrix.hh"

//    BUDOWA PROSTKATA :
//
//    rect[punkt][1]=x_punktu
//    rect[punkt][2]=y_punktu
//
//  1  *------------*  2
//     |            |
//     |            |
//     |            |
//  3  *------------*  4

class Rectangle {
  private:
    double rect[4][2];
  public:

    Rectangle();

    Rectangle(double [4][2]);

    Rectangle VectorTrans(Vector Vect);

    Rectangle AngleTrans(double Angle);

    const double &operator () (unsigned int point, unsigned int axis) const;

};

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

const double &Rectangle::operator () (unsigned int point, unsigned int axis) const{

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

std::ostream &operator<<(std::ostream &out, Rectangle const &Rectangle)
{
      for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 2; ++j) {
              out << Rectangle(i, j); //warto ustalic szerokosc wyswietlania dokladnosci liczb
          }
          std::cout << std::endl;
      }
      return out;
}