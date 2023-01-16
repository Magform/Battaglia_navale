#ifndef Supporto_H_
#define Supporto_H_

class Supporto : public Naval_units{
private:
    int vita = 3;
    string begin;
    string end;
    string centro;
public:
    string get_centro(); 
    bool isAlive();
    void set(string inizio, string fine, Griglia& g_difesa);
    void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa);
};

#endif // Supporto_H_
