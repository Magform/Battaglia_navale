#ifndef Griglia_difesa_H_
#define Griglia_difesa_H_

class Griglia_difesa : public Griglia{
private:
    //le 3 CORAZZATE
    Corazzata corazzata1;
    Corazzata corazzata2;
    Corazzata corazzata3;
    //le 2 navi di SUPPORTO
    Supporto supporto1;
    Supporto supporto2;
    Supporto supporto3;
    //i 2 SOTTOMARINI
    Sottomarino sottomarino1;
    Sottomarino sottomarino2;

public:
    void setup();
};

#include "../../lib/Griglia/Griglia_difesa.hpp"

#endif // Griglia_difesa_H_
