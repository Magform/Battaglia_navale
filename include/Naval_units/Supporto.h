#ifndef Supporto_H_
#define Supporto_H_

class Supporto : public Naval_units{
private:
    int vita = 5;
public:
    void set(string inizio, :string fine, Griglia g_difesa);
    void azione(std::string obiettivo, Griglia g1_difesa, Griglia g1_attacco, Griglia g2_difesa);
};

#include "../../lib/Naval_units/Supporto.hpp"

#endif // Supporto_H_
