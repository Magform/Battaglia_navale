#ifndef Corazzata_H_
#define Corazzata_H_

class Corazzata : public Naval_units{
private:
    int vita = 5;
public:
    void set(std::string inizio, std::string fine);
    void azione(std::string obiettivo);
};

#include "../../lib/Naval_units/Corazzata.hpp"

#endif // Corazzata_H_
