 #include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <chrono>
#include <thread>

#include "Replay.h"

using namespace std;

int main(int argc, char ** argv) {
	string loadtype{}, log_in{}, log_out{};
	bool accepted = false;
	int turni=0;
	int massimo_turni = 100; //attenzine se la si cambia qua bisonga cambiarla anche su battaglia_navale
	while (!accepted) {
		try {
			Replay battaglia;
			
			if (string(argv[1]) == "v") {
				battaglia.setup(string(argv[1]), string(argv[2]), "");
			}
			else if (string(argv[1]) == "f") {
				battaglia.setup(string(argv[1]), string(argv[2]), string(argv[3]));
			}
			else{
				cout << "Argomento non valido: " << endl;
				cout << " Inserire il tipo di replay che si desidera effettuare: " << endl;
				cout << "v [nome_file_log] -> stampa a video il replay del file di log indicato" << endl;
				cout << "f [nome_file_log] [nome_file_output_replay] -> scrive su file il replay del file di log indicato" << endl;
			}

			while (turni <= massimo_turni) {
				battaglia.turno();
				turni++;
			}
			battaglia.fine();
			cout << "Esecuzione terminata " << endl;

		}
		catch (const invalid_argument ex) {
			cout << "Il file non contiene una battaglia navale valida o il file selezionato non e' valido" << endl;
			return 0;
		}
		catch (const out_of_range ex) {
			cout << "Errore nella lettura degli argomenti" << endl;
			return 0;
		}
		catch (const logic_error ex) {
			cout << " Inserire il tipo di replay che si desidera effettuare: " << endl;
			cout << "v [nome_file_log] -> stampa a video il replay del file di log indicato" << endl;
			cout << "f [nome_file_log] [nome_file_output_replay] -> scrive su file il replay del file di log indicato" << endl;
			return 0;
		}
	}
}
