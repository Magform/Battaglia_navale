#ifndef Naval_units_H_
#define Naval_units_H_

class NavalUnits{
protected:
    int vita;
    std::string inizio;
    std::string fine;
    std::string centro;

public:
    bool isAlive() { if (vita != 0) { return true; } return false; }
    virtual void set(std::string inizio, std::string fine) {};
    virtual void azione(std::string obiettivo) {};
};

#include "../../lib/Naval_units/Naval_units.hpp"

#endif // Naval_units_H_
