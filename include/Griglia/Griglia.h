#ifndef Griglia_H_
#define Griglia_H_

using namespace srd;

class Griglia{
protected:
    string matrix[12][12]; //matrice che rappresenta la griglia [y][x]
public:
    Griglia();

    //funzioni utili
    void set(string toSet, string location);
    void clear();
    void remove(string location);
    string retrive(string location);

    //overload operatori
    friend ostream& operator<<(ostream& os, const Griglia to_print);
};

#include "../../lib/Griglia/Griglia.hpp"

#endif // Griglia_H_
