#ifndef Replay_H_
#define Replay_H_

#include "Griglia.h"
#include "Corazzata.h"
#include "Supporto.h"
#include "Sottomarino.h"

class Replay {
private:
    std::ifstream log_input;     //variabile per la lettura dei log dal file
    std::ofstream log_output;    //variabile per la scrittura dell'output su file 
    bool file_output;           //variabile per definire se vi é un output su file o no

    //tutti le variabili del giocatore1 
    Griglia g1_attacco;
    Griglia g1_difesa;
    Corazzata g1_corazzata1;
    Corazzata g1_corazzata2;
    Corazzata g1_corazzata3;
    Supporto g1_supporto1;
    Supporto g1_supporto2;
    Supporto g1_supporto3;
    Sottomarino g1_sottomarino1;
    Sottomarino g1_sottomarino2;

    //tutti le variabili del giocatore2
    Griglia g2_attacco;
    Griglia g2_difesa;
    Corazzata g2_corazzata1;
    Corazzata g2_corazzata2;
    Corazzata g2_corazzata3;
    Supporto g2_supporto1;
    Supporto g2_supporto2;
    Supporto g2_supporto3;
    Sottomarino g2_sottomarino1;
    Sottomarino g2_sottomarino2;

    void write(std::string toPrint);
    int g1_corazzate(); //conta le corazzate attualmente in vita del giocatore 1.
    int g2_corazzate(); //conta le corazzate attualemente in vida del giocatore 2.

public:
    Replay(std::string type, std::string log_in, std::string log_out = "");

    void setup();   //funzione che inizializza le variabile dei due giocatori
    void turno();   //funzione che gestisce l'esecuzione dei un singolo turno
    int winner();   //se ritorna 1 vince giocatore 1, se ritorna 2 vince giocatore 2
    void fine();    //funzione da chiamare quando termina la battaglia

};

#endif // Replay_H_
