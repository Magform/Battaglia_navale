#ifndef Supporto_H_
#define Supporto_H_

class Supporto : public Naval_units{
private:
    int vita = 5;
public:
    void set(std::string inizio, std::string fine);
    void azione(std::string obiettivo);
};

#include "../../lib/Naval_units/Supporto.hpp"

#endif // Supporto_H_
