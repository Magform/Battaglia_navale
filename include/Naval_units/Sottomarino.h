#ifndef Sottomarino_H_
#define Sottomarino_H_

using namespace std;

class Sottomarino : public Naval_units{
private:
    int vita = 1;
    string begin;
    string end;
    string centro;
public:
    void set(string inizio, string fine, Griglia& g_difesa);
    void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);
};

#include "../../lib/Naval_units/Sottomarino.hpp"
#endif // Sottomarino_H_
