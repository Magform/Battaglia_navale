#ifndef Griglia_difesa_H_
#define Griglia_difesa_H_

class Griglia_difesa : public Griglia{
private:
    Corazzata corazzata1;
    Corazzata corazzata2;
    Corazzata corazzata3;
    Supporto supporto1;
    Supporto supporto2;
    Supporto supporto3;
    Sottomarino sottomarino1;
    Sottomarino sottomarino2;

public:
    void setup();

};

#include "../../lib/Griglia/Griglia_difesa.hpp"

#endif // Griglia_difesa_H_

