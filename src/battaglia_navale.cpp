#include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>

#include "../include/Naval_battle/Naval_battle.h"

using namespace std;

int main() {
	string battletype;
	cout << "Inserire il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	cin >> battletype;
	Naval_battle battaglia(battletype, true);
	battaglia.setup();
	int turni = 1;
	while (battaglia.winner()==0 && turni<=100) {
		if (!battaglia.is_botBattle()) {
			battaglia.accept_command();
		}
		battaglia.bot_command();
		turni++;
	}
	cout << "Il vincitore é il giocatore " << battaglia.winner() << endl;

}
