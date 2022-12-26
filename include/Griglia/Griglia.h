#ifndef Griglia_H_
#define Griglia_H_

class Griglia{
protected:
    std::string matrix[12][12]; //matrice che rappresenta la griglia [y][x]
public:
    Griglia();

    //funzioni utili
    void set(std::string toSet, std::string location);
    void clear();
    void remove(std::string location);
    std::string retrive(std::string location);

    //overload operatori
    friend std::ostream& operator<<(std::ostream& os, const Griglia to_print);
};

#include "../../lib/Griglia/Griglia.hpp"

#endif // Griglia_H_
