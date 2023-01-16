#ifndef Sottomarino_H_
#define Sottomarino_H_

#include "Naval_units.h"

class Sottomarino : public Naval_units{
private:
    int vita = 1;
    string begin;
    string end;
    string centro;
public:
    string get_centro(); 
    bool isAlive();
    void set(string inizio, string fine, Griglia& g_difesa);
    void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);
};

#endif // Sottomarino_H_
