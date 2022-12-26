#ifndef Supporto_H_
#define Supporto_H_

class Supporto : public Naval_units{
    void set(std::string inizio, std::string fine);
    void azione(std::string centro);
};

#include "../../lib/Naval_units/Supporto.hpp"

#endif // Supporto_H_
