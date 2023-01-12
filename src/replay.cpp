 #include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>
#include<dos.h>

#include "../include/Replay/Replay.h"

using namespace std;

int main() {
	string arg;
	bool accepted = false;

	int massimo_turni = 100; //attenzioe se la si cambia qua bisonga cambiarla anche su battaglia_navale

	while (!accepted) {
		try {
			cout << "Inserire il tipo di replay che si desidera effettuare: " << endl;
			cout << "v [nome_file_log] -> stampa a video il replay del file di log indicato" << endl;
			cout << "f [nome_file_log] [nome_file_output_replay] -> scrive su file il replay del file di log indicato" << endl;
			cin >> arg;
			Replay battaglia(arg);
			battaglia.setup();
			while (battaglia.winner() == 0 && turni <= massimo_turni) {
				battaglia.turno();
				turno++;
			}
			battaglia.fine();
			cout << "Esecuzione terminata " << endl;

		}
		catch (const invalid_argument ex) {
			cout << "Il file non contiene una battaglia navale valida" << endl;
		}
	}
}
