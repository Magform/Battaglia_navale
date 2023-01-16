#ifndef Corazzata_H_
#define Corazzata_H_

#include "Naval_units.h"

class Corazzata : public Naval_units{
private:
    int vita = 5;
    string begin;
    string end;
    string centro;
public:
    string get_centro(); 
    bool isAlive(Griglia& g_difesa);
    void set(string inizio, string fine, Griglia& g_difesa);
    void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);

};

#endif // Corazzata_H_
