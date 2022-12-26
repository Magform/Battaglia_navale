#ifndef Corazzata_H_
#define Corazzata_H_

class Corazzata : public Naval_units{
    void set(std::string inizio, std::string fine);
    void azione(std::string centro);
};

#include "../../lib/Naval_units/Corazzata.hpp"

#endif // Corazzata_H_
