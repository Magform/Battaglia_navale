#ifndef Griglia_H_
#define Griglia_H_

using namespace std;

class Griglia{
protected:
    string matrix[12][12];      //matrice che rappresenta la griglia [y][x]
public:
    Griglia();

    //funzioni utili
    void set(string toSet, string location);    //setta "toSet" nalla posizione "location" 
    void clear();                               //cancella TUTTA la griglia
    void remove(string location);               //rimuove ciò che c'è nalla posizione "location"
    string retrive(string location);            //restituisce la stringa nalla posizione "location"

    //overload operatori
    friend ostream& operator<<(ostream& os, const Griglia to_print);
};

#include "../../lib/Griglia/Griglia.hpp"

#endif // Griglia_H_
