#ifndef Replay_H_
#define Replay_H_

#include "../../lib/Naval_batlle/Naval_battle.hpp"


class Replay {
private:
    std::ifstream log_input;     //variablie per la lettura dei log dal file
    std::ofstream log_output;
    bool file_output; //variabile per definire se vi é un output su file o no

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
    Replay(std::string type);

    void setup();
    void turno();
    int winner(); //se ritorna 1 vince giocatore 1, se ritorna 2 vince giocatore 2
    void fine();

};

#endif // Replay_H_
