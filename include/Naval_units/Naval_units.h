#ifndef Naval_units_H_
#define Naval_units_H_


using namespace std;

class Naval_units{
protected:
    int vita;
    string inizio;
    string fine;
    string centro;

public:
    bool isAlive() { if (vita != 0) { return true; } return false; }
    string get_centro() { return centro; }
    virtual void set(string inizio, string fine, Griglia& g_difesa) {};
    virtual void azione(string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa) {};
};

#endif // Naval_units_H_
