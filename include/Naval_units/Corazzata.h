#ifndef Corazzata_H_
#define Corazzata_H_

#include "../../lib/Naval_units/Corazzata.hpp"

class Corazzata : public Naval_units{
private:
    int vita = 5;
public:
    void set(string inizio, string fine, Griglia& g_difesa);
    void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);

};

#endif // Corazzata_H_
