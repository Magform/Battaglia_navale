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
		int massimo_turni = 100;	//WARNING: se la si cambia qua bisonga cambiarla anche su replay, rappresenta il numero massimo di turni giocati
		if (argc > 2) {
			cout << "Sono stati inseriti troppi argomenti, solo il primo verra' considerato" << endl;
		}
		Naval_battle battaglia(argv[1], true);

		int turni = 1;
		srand(time(NULL));
		int start = (rand() % 2) + 1;  //si decide in maniera casuale chi inizia
		if (start == 1) {
			cout << "Il giocatore che inizia la partita è il \"giocatore 1\"" << "\n";
		}
		else {
			cout << "Il giocatore che inizia la partita è il \"giocatore 2\"" << "\n";
		}
		cout << "Fase posizionamento navi" << endl;
		battaglia.setup(start);

		while (battaglia.winner() == 0 && turni <= massimo_turni) {
			cout << "Turno " << turni << endl;
			battaglia.command(start);
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
	catch (const invalid_argument ex) {				//cattura eccezione lanciata dal costruttore
		cout << "Argomento non valido, inserire come argomento il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	}
	catch (const logic_error ex) {					//cattura eccezione lanciata se non si inseriscono argomenti
		cout << "Inserire come argomento il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	}
}
