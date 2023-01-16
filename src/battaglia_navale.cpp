#include <stdexcept>
#include <string>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <chrono>
#include <thread>

#include "Naval_battle.h"

using namespace std;

int main() {

	int massimo_turni = 100;	//attenzioe se la si cambia qua bisonga cambiarla anche su replay

	string battletype;
	cout << "Inserire il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	cin >> battletype;
	Naval_battle battaglia(battletype, true);
	battaglia.setup();
	int turni = 1;
	srand(time(NULL));
    int start = rand()%2;  //si decide in maniera casuale chi inizia
	
	if(start==0 ){
		cout << "Il giocatore che inizia la partita è il \"giocatore 1\""<<"\n";
	}else{
		cout << "Il giocatore che inizia la partita è il \"giocatore 2\""<<"\n";
	}
	
	while (battaglia.winner()==0 && turni<=massimo_turni) {
		battaglia.command(start+1);
		turni++;
	}
	cout << "Battaglia terminata"<<endl;
	if (turni = massimo_turni + 1 && battaglia.winner()==0) {
		cout << "Numero massimo di turni raggiunto, non vi é un vincitore e la partita termina in pareggio" << endl;
	}
	else {
		cout << "Il vincitore é il giocatore " << battaglia.winner() << endl;
	}
}
