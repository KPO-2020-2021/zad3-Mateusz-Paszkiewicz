#include<iostream>

#include"../include/handling.hh"

/*!
 * Funkcja odczytu zestawu punktow prostokata
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 *\param[in] Rect - objekt klasy rectangle do ktorego zapisane zostana dane
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
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

  fin >> Rect(0,0);   fin >> Rect(0,1);
  fin >> Rect(1,0);   fin >> Rect(1,1);
  fin >> Rect(2,0);   fin >> Rect(2,1);
  fin >> Rect(3,0);   fin >> Rect(3,1);
  fin >> Rect(0,0);   fin >> Rect(0,1);

  return true;
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow prostopadloscianu do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void CoordsToStream( std::ostream& StrmWy, Rectangle &Rect)
{

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
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool SaveCoordsToFile( const char *sNazwaPliku,  Rectangle &Rect)
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
