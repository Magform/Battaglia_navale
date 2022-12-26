#include <stdexcept>
#include <string>
#include <iostream>


int main() {
	string battletype;
	cout << "Inserire il tipo di partita ('pc' => giocatore vs computer; 'cc' => computer vs computer)" << endl;
	cin >> battletype;
	Naval_battle battaglia(battletype);
	
}
