#ifndef Sottomarino_H_
#define Sottomarino_H_

class Sottomarino : public Naval_units{
    void set(std::string inizio, std::string fine);
    void azione(std::string centro, std::string obiettivo);
};

#include "../../lib/Naval_units/Sottomarino.hpp"

#endif // Sottomarino_H_

