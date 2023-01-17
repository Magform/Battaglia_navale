#include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <chrono>
#include <thread>

#include "Naval_battle.h"

using namespace std;

int main(int argc, char ** argv) {
	try {
		int massimo_turni = 100;	//attenzioe se la si cambia qua bisonga cambiarla anche su replay
		Naval_battle battaglia(argv[1], true);
		int turni = 1;
		srand(time(NULL));
		int start = rand() % 2;  //si decide in maniera casuale chi inizia
		if (start == 0) {
			cout << "Il giocatore che inizia la partita è il \"giocatore 1\"" << "\n";
		}
		else {
			cout << "Il giocatore che inizia la partita è il \"giocatore 2\"" << "\n";
		}

		battaglia.setup(start + 1);

		while (battaglia.winner() == 0 && turni <= massimo_turni) {
			battaglia.command(start + 1);
			turni++;
		}
		cout << "Battaglia terminata" << endl;
		if (turni = massimo_turni + 1 && battaglia.winner() == 0) {
			cout << "Numero massimo di turni raggiunto, non vi e' un vincitore e la partita termina in pareggio" << endl;
		}
		else {
			cout << "Il vincitore e' il giocatore " << battaglia.winner() << endl;
		}
	}
	catch (const logic_error ex) {
		cout << "Inserire come argomento il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	}
}
