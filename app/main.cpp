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

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"
#include "rectangle.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 *
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */


bool CoordsReadFromFile(const char *sNazwaPliku, Rectangle &Rect)
{
    std::ifstream  fin;

  fin.open(sNazwaPliku);
  if (!fin.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
   << ":(  nie powiodla sie." << std::endl;
    return false;
    }

  fin >> Rect(0,0);
  fin >> Rect(0,1);
  fin >> Rect(1,0);
  fin >> Rect(1,1);
  fin >> Rect(2,0);
  fin >> Rect(2,1);
  fin >> Rect(3,0);
  fin >> Rect(3,1);
  fin >> Rect(0,0);
  fin >> Rect(0,1);

  return true;
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void CoordsToStream( std::ostream& StrmWy, Rectangle &Rect)
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych
   // zmiennych do reprezentowania wspolrzednych!
   //


  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(1,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(1,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(2,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(2,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(3,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(3,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,1) << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char *sNazwaPliku,  Rectangle &Rect)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  CoordsToStream(StrmPlikowy, Rect);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


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

  Rectangle rect=Rectangle();
  CoordsReadFromFile("../datasets/prostokat.dat", rect);
  CoordsToStream(std::cout,rect);
  if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",rect)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');
   //----------------------------------------------------------
   // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
   //
  CoordsToStream(std::cout,rect);
  if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",rect)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');

  // Z bazy projektu-wydmuszki Boiler Plate C++:
  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
