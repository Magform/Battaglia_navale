#ifndef Naval_units_H_
#define Naval_units_H_

class Naval_units{
protected:
    int vita;
    std::string inizio;
    std::string fine;
    std::string centro;

public:
    bool isAlive() { if (vita != 0) { return true; } return false; }
    virtual set(string inizio, :string fine, Griglia g_difesa) {};
    virtual azione(std::string obiettivo, Griglia g1_difesa, Griglia g1_attacco, Griglia g2_difesa) {};
};

#include "../../lib/Naval_units/Naval_units.hpp"

#endif // Naval_units_H_
