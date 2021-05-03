#include "../include/vector.hh"
#include <iostream>


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template<typename T, unsigned int dime>
Vector<T, dime>::Vector() {
    for (int i = 0; i < dime; ++i) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template<typename T, unsigned int dime>
Vector<T, dime>::Vector(T tmp[dime]) {
    for (int i = 0; i < dime; ++i) {
        size[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template<typename T, unsigned int dime>
Vector<T, dime> Vector<T, dime>::operator + (const Vector<T, dime> v) {
    Vector<T, dime> result;
    for (int i = 0; i < dime; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename T, unsigned int dime>
Vector<T, dime> Vector<T, dime>::operator - (const Vector<T, dime> v) {
    Vector<T, dime> result;
    for (int i = 0; i < dime; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename T, unsigned int dime>
Vector<T, dime> Vector<T, dime>::operator * (const T &tmp) {
    Vector<T, dime> result;
    for (int i = 0; i < dime; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template<typename T, unsigned int dime>
Vector<T, dime> Vector<T, dime>::operator / (const T &tmp) {
    Vector<T, dime> result;

    for (int i = 0; i < dime; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template<typename T, unsigned int dime>
const T &Vector<T, dime>::operator [] (int index) const {
    if (index < 0 || index >= dime) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template<typename T, unsigned int dime>
T &Vector<T, dime>::operator[](int index) {
    return const_cast<T &>(const_cast<const Vector *>(this)->operator[](index));
}


template<typename T, unsigned int dime>
bool Vector<T, dime>::operator == (const Vector<T, dime> v) const
  {
    bool equal=true;
    for(int i=0; i<dime; ++i)
    {
      if(abs((*this).size[i]-v.size[i])>0.0000001)
        equal=false;
    }

    return equal;
  }


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template<typename T, unsigned int dime>
std::ostream &operator << (std::ostream &out, Vector<T, dime> const &tmp) {
    for (int i = 0; i < dime; ++i) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template<typename T, unsigned int dime>
std::istream &operator >> (std::istream &in, Vector<T, dime> tmp) {
    for (int i = 0; i < dime; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
