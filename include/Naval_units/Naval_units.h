#include <string>
#include "Griglia.h"

#ifndef Naval_units_H_
#define Naval_units_H_

class Naval_units{
protected:
    int vita;
    std::string inizio;
    std::string fine;
    std::string centro;

public:
    bool isAlive(Griglia& g_difesa) { if (vita == 0) { return false; } return true; }
    std::string get_centro() { return centro; }
    virtual void set(std::string inizio, std::string fine, Griglia& g_difesa) {}
    virtual void azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa) {}
};

#endif // Naval_units_H_
