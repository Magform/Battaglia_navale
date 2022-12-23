#ifndef Naval_battle_H_
#define Naval_battle_H_

#include "../../lib/Naval_battle/Naval_battle.hpp"

class Naval_battle{
private:
    Grigila giocatore1_attacco;
    Grigila giocatore1_difesa;
    Grigila giocatore2_attacco;
    Grigila giocatore2_difesa;

public:
    void place_unit();
    void accept_command();
    bool end_battle();

}

#endif // Naval_battle_H_
