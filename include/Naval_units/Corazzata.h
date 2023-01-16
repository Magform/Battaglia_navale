#include <string>

#ifndef Corazzata_H_
#define Corazzata_H_

#include "Naval_units.h"

class Corazzata : public Naval_units{
private:
    int vita = 5;
    std::string begin;
    std::string end;
    std::string centro;
public:
    std::string get_centro();
    bool isAlive();
    void set(std::string inizio, std::string fine, Griglia& g_difesa);
    void azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);

};

#endif // Corazzata_H_
