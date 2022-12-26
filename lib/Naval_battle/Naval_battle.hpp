#include "../../include/Naval_battle/Naval_battle.h"


Naval_battle::Naval_battle(std::string battletype) {
	if (battletype == "pc") {
		botBattle = false;
		giocatore1_difesa.setup()
		giocatore2_difesa.botsetup()
	}
	if (battletype == "cc") {
		botBattle = true;
		giocatore1_difesa.bot_setup()
		giocatore2_difesa.bot_setup()

	}
	throw std::invalid_argument("Argomento non valido");
}