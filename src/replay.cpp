 #include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <chrono>
#include <thread>

#include "Replay.h"

using namespace std;

int main() {
	string loadtype{}, log_in{}, log_out{};
	bool accepted = false;
	int turni=0;
	int massimo_turni = 100; //attenzioe se la si cambia qua bisonga cambiarla anche su battaglia_navale

	while (!accepted) {
		try {
			cout << "Inserire il tipo di replay che si desidera effettuare: " << endl;
			cout << "v [nome_file_log] -> stampa a video il replay del file di log indicato" << endl;
			cout << "f [nome_file_log] [nome_file_output_replay] -> scrive su file il replay del file di log indicato" << endl;
			cin >> loadtype;
			if (arg == "v") {
				cin >> log_in;
			}else if (arg == "f") {
				cin >> log_in >> log_out;
			}
			else {
				cout << "Tipo di replay non valido";
				return 0;
			}
			Replay battaglia(loadtype, log_in, log_out);
			battaglia.setup();
			while (battaglia.winner() == 0 && turni <= massimo_turni) {
				battaglia.turno();
				turni++;
			}
			battaglia.fine();
			cout << "Esecuzione terminata " << endl;

		}
		catch (const invalid_argument ex) {
			cout << "Il file non contiene una battaglia navale valida" << endl;
		}
	}
}
