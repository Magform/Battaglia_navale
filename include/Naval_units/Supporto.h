#include <string>

#ifndef Supporto_H_
#define Supporto_H_

#include "Naval_units.h"

class Supporto : public Naval_units{
private:
    int vita = 3;
    std::string begin;
    std::string end;
    std::string centro;
public:
    std::string get_centro();
    bool isAlive();
    void set(std::string inizio, std::string fine, Griglia& g_difesa);
    void azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);
};

#endif // Supporto_H_
