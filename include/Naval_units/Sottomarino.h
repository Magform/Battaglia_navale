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
    std::string get_centro(); 
    bool isAlive();
    void set(std::string inizio, std::string fine, Griglia& g_difesa);
    void azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);
};

#endif // Sottomarino_H_
