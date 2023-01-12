#include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>

#include "../include/Naval_battle/Naval_battle.h"

using namespace std;

int main() {

	int massimo_turni = 100;	//attenzioe se la si cambia qua bisonga cambiarla anche su replay

	string battletype;
	cout << "Inserire il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	cin >> battletype;
	Naval_battle battaglia(battletype, true);
	battaglia.setup();
	int turni = 1;
	while (battaglia.winner()==0 && turni<=massimo_turni) {
		if (!battaglia.is_botBattle()) {
			battaglia.accept_command();
		}
		battaglia.bot_command();
		turni++;
	}
	cout << "Battaglia terminata" endl;
	if (turni = massimo_turni + 1) {
		cout << "Numero massimo di turni raggiunto, non vi é un vincitore e la partita termina in pareggio" << endl;
	}
	else {
		cout << "Il vincitore é il giocatore " << battaglia.winner() << endl;
	}
}
