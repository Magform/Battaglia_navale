#ifndef Naval_battle_H_
#define Naval_battle_H_

#include "../../lib/Naval_battle/Naval_battle.hpp"
#include "../../include/Griglia/Griglia.h"
#include "../../include/Naval_units/Naval_units.h"
#include "../../include/Naval_units/Corazzata.h"
#include "../../include/Naval_units/Sottomarino.h"
#include "../../include/Naval_units/Supporto.h"


class Naval_battle {
private:
    bool botBattle;             //variabile che se é true dice che la battaglia non ha giocatori umani ma solo due bot
    bool log;                   //variabile che indica se é necessario o meno il logging su file
    std::ofstream log_file;     //variablie per la scrittura dei log su file (viene utilizzata solo se richiesto)

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

public:
    Naval_battle(std::string battletype, bool log_or_not);

    void setup();
    bool getBotBattle() { return botBattle; }
    void accept_command();
    void bot_command();
    int winner(); //se ritorna 1 vince giocatore 1, se ritorna 2 vince giocatore 2
    bool is_botBattle();

    int g1_corazzate(); //conta le corazzate attualmente in vita del giocatore 1.
    int g2_corazzate(); //conta le corazzate attualemente in vida del giocatore 2.

};

#endif // Naval_battle_H_