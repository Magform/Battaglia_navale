#ifndef Naval_battle_H_
#define Naval_battle_H_

#include "../../lib/Naval_battle/Naval_battle.hpp"

class Naval_battle{
private:
    bool botBattle;

    Grigila giocatore1_attacco;
    Grigila_difesa giocatore1_difesa;
    Grigila giocatore2_attacco;
    Grigila_difesa giocatore2_difesa;

public:
    Naval_battle(std::string battletype);

    bool getBotBattle() { return botBattle };
    void place_unit();
    void accept_command();
    bool end_battle();

}

#endif // Naval_battle_H_
