#include <string>
#include "Griglia.h"

#ifndef Sottomarino_H_
#define Sottomarino_H_

#include "Naval_units.h"

class Sottomarino : public Naval_units{
private:
    int vita = 1;
    std::string begin;
    std::string end;
    std::string centro;
public:
    string get_centro(); 
    bool isAlive(Griglia& g_difesa);
    void set(string inizio, string fine, Griglia& g_difesa);
    void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);
};

#endif // Sottomarino_H_
