// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>

#include "handling.hh"
#include "exampleConfig.h"
#include "vector.hh"
#include "matrix.hh"
#include "lacze_do_gnuplota.hh"
#include "rectangle.hh"


int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D

    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);


  Rectangle rect=Rectangle(); //constructor of class Rectangle
  CoordsReadFromFile("../datasets/prostokat.dat", rect);
  char option;

  std::cout<<"2D GNUPlot rectangle Translation program."<<std::endl;
  std::cout<<"Press h for help."<<std::endl;


  Menu:

  std::cout<<"Please select option:  ";

  std::cin>>option;
  std::cout<<std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

  switch (option) {
    case 'h':
    {
      std::cout<<"v - vector translation "<<std::endl;
      std::cout<<"a - isometric translation "<<std::endl;
      std::cout<<"d - display rectangle in GNUPlot "<<std::endl;
      std::cout<<"s - display points of the rectangle "<<std::endl;
      std::cout<<"q - exit "<<std::endl;

      goto Menu;
    }
    case 'v':
    {
      double input[2];

      std::cout<<"please pass the vector values [x,y]:"<<std::endl;

      std::cin>>input[0]; std::cin>>input[1];
      Vector<double,2> vec= Vector<double, 2>(input);

      rect=rect+vec;

      if (!SaveCoordsToFile("../datasets/prostokat.dat",rect))
        std::cerr<<"Err: Cannot save coords to file";
      else
      {
        std::cout<<std::endl;
        std::cout<<"Done!"<<std::endl<<std::endl;
      }

      goto Menu;
    }

    case 'a':
    {
      double angle;

      std::cout<<"Please pass the value of angle:";
      std::cin>>angle;

      rect.AngleTrans(angle*M_PI/180);

      if (!SaveCoordsToFile("../datasets/prostokat.dat",rect))
        std::cerr<<"Err: Cannot save coords to file";
      else
      {
        std::cout<<std::endl;
        std::cout<<"Done!"<<std::endl<<std::endl;
      }

      goto Menu;
    }

    case 'd':
    {
      std::cout<<std::endl;
      std::cout<<"Displaying..."<<std::endl<<std::endl;
      Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
      goto Menu;
    }
    case 's':
    {
      std::cout<<std::endl;
      std::cout<<"Displaying coords..."<<std::endl<<std::endl;
      CoordsToStream(std::cout, rect);

      goto Menu;
    }
    case 'q':
    {
      exit(0);
    }
    default:
    {
      std::cout<<"Option selected not recognized, please try again.";
      goto Menu;
    }
  }

}
