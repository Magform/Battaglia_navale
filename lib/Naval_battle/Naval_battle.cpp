#include "Naval_battle.h"

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

//namespace utilizzati
using namespace std;
using namespace this_thread;
using namespace chrono;

//funzioni utili.
std::string location_to_string(int X, int Y);         //funzione che trasforma coordinate numeriche in coordinate valide per la griglia (del tipo LetteraNumero)                                                
void create_corazzata(Corazzata& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);		//funzione utilizzata dal bot per creare la corazzata in maniera casuale
void create_supporto(Supporto& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);		    //funzione utilizzata dal bot per creare la nave di supporto in maniera casuale
void create_sottomarino(Sottomarino& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);	//funzione utilizzata dal bot per creare il sottomarino in maniera casuale
void print_command();   //funzione che stampa tutti i comandi possibile per il giocatore


//costruttore di Naval_battle, richiede la conosceza del tipo di battaglia e se é necessario o meno creare i log in output
//in caso i log vengono impostati crea (se non presente) e apre il file log.txt che gestirá i log della partita
//Se si inserisce un battletype non valido lancia un invalid_argument
Naval_battle::Naval_battle(std::string battletype, bool log_or_not) {
	if (battletype == "pc") {
		botBattle = false;
	}else if (battletype == "cc") {
		botBattle = true;
    }
    else {
        	throw std::invalid_argument("Battletype non valido");
   	}
   	log = log_or_not;
   	if (log) {
   	    log_file.open("log.txt");
    }
}


//funzione che crea le corazzate per i due giocatore (sia umani che bot), e scrive le coordinate nel file di log, richiede che venga specificato il primo giocatore
//In caso sia presente un giocatore umano ed esso inserica delle cordinate non valide l'eccezione é giá catturata e gestita
//Lancia eccezione se il giocatore iniziale non é valido (ossia non é 1 o 2)
void Naval_battle::setup(int giocatore_primo) {

    if (giocatore_primo == 1) {
        if (botBattle == false) {
            std::string inizio, fine;

            bool accepted = false;
            while (!accepted) {
                try {
                    std::cout << "Coordinate della corazzata 1: " << endl;
                    std::cin >> inizio >> fine;
                    g1_corazzata1.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della corazzata 2: " << endl;
                    std::cin >> inizio >> fine;
                    g1_corazzata2.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della corazzata 3: " << endl;
                    std::cin >> inizio >> fine;
                    g1_corazzata3.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della nave di supporto 1: " << endl;
                    std::cin >> inizio >> fine;
                    g1_supporto1.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della nave di supporto 2: " << endl;
                    std::cin >> inizio >> fine;
                    g1_supporto2.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della nave di supporto 3: " << endl;
                    std::cin >> inizio >> fine;
                    g1_supporto3.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate del sottomarino 1: " << endl;
                    std::cin >> inizio >> fine;
                    g1_sottomarino1.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate del sottomarino 2: " << endl;
                    std::cin >> inizio >> fine;
                    g1_sottomarino2.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;
        }
        else {
            create_corazzata(g1_corazzata1, g1_difesa, log_file, log);
            create_corazzata(g1_corazzata2, g1_difesa, log_file, log);
            create_corazzata(g1_corazzata3, g1_difesa, log_file, log);
            create_supporto(g1_supporto1, g1_difesa, log_file, log);
            create_supporto(g1_supporto2, g1_difesa, log_file, log);
            create_supporto(g1_supporto3, g1_difesa, log_file, log);
            create_sottomarino(g1_sottomarino1, g1_difesa, log_file, log);
            create_sottomarino(g1_sottomarino2, g1_difesa, log_file, log);
        }
        create_corazzata(g2_corazzata1, g2_difesa, log_file, log);
        create_corazzata(g2_corazzata2, g2_difesa, log_file, log);
        create_corazzata(g2_corazzata3, g2_difesa, log_file, log);
        create_supporto(g2_supporto1, g2_difesa, log_file, log);
        create_supporto(g2_supporto2, g2_difesa, log_file, log);
        create_supporto(g2_supporto3, g2_difesa, log_file, log);
        create_sottomarino(g2_sottomarino1, g2_difesa, log_file, log);
        create_sottomarino(g2_sottomarino2, g2_difesa, log_file, log);
    }
    else if (giocatore_primo == 2) {
        create_corazzata(g2_corazzata1, g2_difesa, log_file, log);
        create_corazzata(g2_corazzata2, g2_difesa, log_file, log);
        create_corazzata(g2_corazzata3, g2_difesa, log_file, log);
        create_supporto(g2_supporto1, g2_difesa, log_file, log);
        create_supporto(g2_supporto2, g2_difesa, log_file, log);
        create_supporto(g2_supporto3, g2_difesa, log_file, log);
        create_sottomarino(g2_sottomarino1, g2_difesa, log_file, log);
        create_sottomarino(g2_sottomarino2, g2_difesa, log_file, log);
        if (botBattle == false) {
            std::string inizio, fine;

            bool accepted = false;
            while (!accepted) {
                try {
                    std::cout << "Coordinate della corazzata 1: " << endl;
                    std::cin >> inizio >> fine;
                    g1_corazzata1.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della corazzata 2: " << endl;
                    std::cin >> inizio >> fine;
                    g1_corazzata2.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della corazzata 3: " << endl;
                    std::cin >> inizio >> fine;
                    g1_corazzata3.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della nave di supporto 1: " << endl;
                    std::cin >> inizio >> fine;
                    g1_supporto1.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della nave di supporto 2: " << endl;
                    std::cin >> inizio >> fine;
                    g1_supporto2.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate della nave di supporto 3: " << endl;
                    std::cin >> inizio >> fine;
                    g1_supporto3.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate del sottomarino 1: " << endl;
                    std::cin >> inizio >> fine;
                    g1_sottomarino1.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;

            while (!accepted) {
                try {
                    std::cout << "Coordinate del sottomarino 2: " << endl;
                    std::cin >> inizio >> fine;
                    g1_sottomarino2.set(inizio, fine, g1_difesa);
                    if (log) { log_file << inizio << " " << fine << endl; }
                    accepted = true;
                }
                catch (const invalid_argument ex) {
                    cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
                }
            }
            accepted = false;
        }
        else {
            create_corazzata(g1_corazzata1, g1_difesa, log_file, log);
            create_corazzata(g1_corazzata2, g1_difesa, log_file, log);
            create_corazzata(g1_corazzata3, g1_difesa, log_file, log);
            create_supporto(g1_supporto1, g1_difesa, log_file, log);
            create_supporto(g1_supporto2, g1_difesa, log_file, log);
            create_supporto(g1_supporto3, g1_difesa, log_file, log);
            create_sottomarino(g1_sottomarino1, g1_difesa, log_file, log);
            create_sottomarino(g1_sottomarino2, g1_difesa, log_file, log);
        }
    }
    else {
        throw invalid_argument("Giocatore inziale non valido");
    }
}


//funzione che gestisce i comandi del giocatore e, se validi gli scrive anche nel file di log
void Naval_battle::accept_command(){
    cout << "Inserire comando (HH HH per mostrare tutti i comandi possibili) \n";
    std::string origin, target;
    cin >> origin >> target;
    if (origin == "HH" && target == "HH") {
        print_command();
        accept_command();
    }
    else if(origin=="AA" && target=="AA"){
        g1_attacco.remove_all("Y");
        accept_command();
    }
    else if (origin == "XX" && target == "XX"){
	cout << "-----GRIGLIA DI DIFESA-----" << endl;
        cout << g1_difesa << "\n";
	cout << "-----GRIGLIA DI ATTACCO-----" << endl;
        cout << g1_attacco << "\n";
        accept_command();
    }
    else if (origin == "BB" && target == "BB") {
        g1_attacco.remove_all("X");
        accept_command();
    }
    else if (origin == "CC" && target == "CC") {
        g1_attacco.remove_all("O");
        accept_command();
    }
    else if (origin == g1_corazzata1.get_centro()) {
        try {
            g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_corazzata2.get_centro()) {
        try {
            g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_corazzata3.get_centro()) {
        try {
            g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_supporto1.get_centro()) {
        try {
            g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_supporto2.get_centro()) {
        try {
            g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_supporto3.get_centro()) {
        try {
            g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_sottomarino1.get_centro()) {
        try {
            g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_sottomarino2.get_centro()) {
        try {
            g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << " " << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else {
        cout << "Nessuna nave ha il centro nella casella di origine dell'attacco! Inserire una nuova azione." << endl;
        accept_command();
    }

}

//funzione che gestisce tutti i comandi che la battaglia possiede (inseriti dall'utente ed automatici dei bot)
//in caso il primo giocatore non sia valido (non sia 1 o 2) lancia un eccezione invalid_argument
void Naval_battle::command(int giocatore_primo) {
    if (giocatore_primo==2) {
        bot_command(giocatore_primo);
        if (!botBattle) {
            accept_command();
        }
    }
    else if(giocatore_primo==1){
        if (!botBattle) {
            accept_command();
        }
        bot_command(giocatore_primo);
    }
    else {
        throw invalid_argument("Primo giocatore non valido");
    }

}

//funzione che gestisce i comandi di entrambi i giocatori bot
//in caso il primo giocatore non sia valido (non sia 1 o 2) lancia un eccezione invalid_argument
void Naval_battle::bot_command(int giocatore_primo) {
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    if (giocatore_primo == 1) {
        if (botBattle) {
            bot_g1_command();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        bot_g2_command();
    }
    else if (giocatore_primo == 2) {
        bot_g2_command();
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        if (botBattle) {
            bot_g1_command();
        }
    }
    else {
        throw invalid_argument("Primo giocatore non valido");
    }
}


//Gestisce in modo casuale i comandi del bot del giocatore1
//Cattura e gestisce autonomamente tutte le eccezioni delle funzioni che utilizza
void Naval_battle::bot_g1_command(){
    string old_centro;
    bool command_accepted = false;
    while (!command_accepted) {
        srand(time(NULL));
        int attaccante = rand() % 8 + 0;
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 1;
        string target = location_to_string(locationX, locationY);
        switch (attaccante) {
        case 0:
            try {
                old_centro = g1_corazzata1.get_centro();
                g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_corazzata1" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 1:
            try {
                old_centro = g1_corazzata2.get_centro();
                g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_corazzata2" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 2:
            try {
                old_centro = g1_corazzata3.get_centro();
                g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_corazzata3" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 3:
            try {
                old_centro = g1_supporto1.get_centro();
                g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_supporto1" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 4:
            try {
                old_centro = g1_supporto2.get_centro();
                g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_supporto2" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 5:
            try {
                old_centro = g1_supporto3.get_centro();
                g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_supporto3" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 6:
            try {
                old_centro = g1_sottomarino1.get_centro();
                g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_sottomarino1" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 7:
            try {
                old_centro = g1_sottomarino2.get_centro();
                g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g1_sottomarino2" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        }
    }
}


//Gestisce in modo casuale i comandi del bot del giocatore2
//Cattura e gestisce autonomamente tutte le eccezioni delle funzioni che utilizza
void Naval_battle::bot_g2_command() {
    string old_centro;
    bool command_accepted = false;
    while (!command_accepted) {
        srand(time(NULL));
        int attaccante = rand() % 8 + 0;
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 1;
        string target = location_to_string(locationX, locationY);
        switch (attaccante) {
        case 0:
            try {
                old_centro = g2_corazzata1.get_centro();
                g2_corazzata1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_corazzata1" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 1:
            try {
                old_centro = g2_corazzata2.get_centro();
                g2_corazzata2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << "" << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_corazzata2" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 2:
            try {
                old_centro = g2_corazzata3.get_centro();
                g2_corazzata3.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_corazzata3" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 3:
            try {
                old_centro = g2_supporto1.get_centro();
                g2_supporto1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_supporto1" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 4:
            try {
                old_centro = g2_supporto2.get_centro();
                g2_supporto2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_supporto2" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 5:
            try {
                old_centro = g2_supporto3.get_centro();
                g2_supporto3.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_supporto3" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 6:
            try {
                old_centro = g2_sottomarino1.get_centro();
                g2_sottomarino1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_sottomarino1" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        case 7:
            try {
                old_centro = g2_sottomarino2.get_centro();
                g2_sottomarino2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
                cout << "g2_sottomarino2" << endl;
            }
            catch (const invalid_argument ex) {}
            break;
        }
    }
}



//Funzione che conta le navi del giocatore1
int Naval_battle::g1_navi() {
    int toReturn{ 0 };
    if (g1_corazzata1.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_corazzata2.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_corazzata3.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_supporto1.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_supporto2.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_supporto3.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_sottomarino1.isAlive(g1_difesa)) {
        toReturn++;
    }
    if (g1_sottomarino2.isAlive(g1_difesa)) {
        toReturn++;
    }
    return toReturn;
}


//funzione che conta le navi del giocatore2
int Naval_battle::g2_navi() {
    int toReturn{ 0 };
    if (g2_corazzata1.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_corazzata2.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_corazzata3.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_supporto1.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_supporto2.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_supporto3.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_sottomarino1.isAlive(g2_difesa)) {
        toReturn++;
    }
    if (g2_sottomarino2.isAlive(g2_difesa)) {
        toReturn++;
    }
    return toReturn;
}


//funzione che ritorna true se la battaglia é senza un giocatore umano
bool Naval_battle::is_botBattle() {
    return botBattle;
}


//funzione che ritorna 1 se ha vinto il giocatore 1, 2 se ha vinto il giocatore 2, 0 se la battaglia ancora non é terminata
int Naval_battle::winner() {
    if (g1_navi() == 0) {
        log_file.close();
        return 1;
    }
    if (g2_navi() == 0) {
        log_file.close();
        return 2;
    }
    return 0;
}


//funzione che si occupa di inizializzare una corazzata in modo casuale (utilizzata dal bot)
void create_corazzata(Corazzata& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log){
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string inizio = location_to_string(locationX, locationY);

	
        int direzione = rand() % 4 + 0;
        string fine{};
	
        try {
            //switch per decidere la posizione in cui il bot andrà a mettere la propria corazzata
            switch (direzione) {
            case 0:
                if (locationX - 4 < 0)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX - 4, locationY);
                break;
            case 1:
                if (locationX + 4 > 12)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX + 4, locationY);
                break;
            case 2:
                if (locationY - 4 < 0)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX, locationY - 4);
                break;
            case 3:
                if (locationY + 4 > 12)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX, locationY + 4);
                break;
            }

            unita.set(inizio, fine, griglia_difesa);	//chiamo il set della corazzata per "crearla"
            if (log) { log_file << inizio << " " << fine << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {
            isGood = false;
        }
    }
}


//funzione che si occupa di inizializzare una supporto in modo casuale (utilizzata dal bot)
void create_supporto(Supporto& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log) {
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string inizio = location_to_string(locationX, locationY);

        int direzione = rand() % 4 + 0;
        string fine{};
	   
        try {
            //switch per decidere la posizione in cui il bot andrà a mettere la propria nave di supporto
            switch (direzione) {
            case 0:
                if (locationX - 2 < 0)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX - 2, locationY);
                break;
            case 1:
                if (locationX + 2 > 12)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX + 2, locationY);
                break;
            case 2:
                if (locationY - 2 < 0)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX, locationY - 2);
                break;
            case 3:
                if (locationY + 2 > 12)throw invalid_argument("Numero non valido");
                fine = location_to_string(locationX, locationY + 2);
                break;
            }

            unita.set(inizio, fine, griglia_difesa);	//chiamo il set del supporto per "crearla"
            if (log) { log_file << inizio << " " << fine << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {
            isGood = false;
        }
    }

}


//funzione che si occupa di inizializzare un sottomarino in modo casuale (utilizzata dal bot)
void create_sottomarino(Sottomarino& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log) {
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string inizio = location_to_string(locationX, locationY);
        try {
            unita.set(inizio, inizio, griglia_difesa);	  //chiamo il set del sottomarino per "crearlo"
            if (log) { log_file << inizio << " " << inizio << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {
            isGood = false;
        }
    }
}

//funzione che trasforma coordinate numeriche in coordinate valide per la griglia (del tipo LetteraNumero)
std::string location_to_string(int X, int Y) {
    string output{};
    switch (X) {
    case 0:
        output = output + "A";
        break;
    case 1:
        output = output + "B";
        break;
    case 2:
        output = output + "C";
        break;
    case 3:
        output = output + "D";
        break;
    case 4:
        output = output + "E";
        break;
    case 5:
        output = output + "F";
        break;
    case 6:
        output = output + "G";
        break;
    case 7:
        output = output + "H";
        break;
    case 8:
        output = output + "I";
        break;
    case 9:
        output = output + "L";
        break;
    case 10:
        output = output + "M";
        break;
    case 11:
        output = output + "N";
        break;
    default:
        output = output + "A"; //se il valore non é valido, invece di lanciare un eccezione, ho deciso di impostare la colonna A di default.
    }
    output = output + to_string(Y);
    return output;
}


//Funzione che stampa tutti i comandi possibili
void print_command() {
    std::cout << "Lista dei comandi possibili:" << std::endl;
    std::cout << "HH HH -> mostra questa lista di comandi" << std::endl;
    std::cout << "XYOrigin XYTarget -> esegue l'azione della nave centrata in XYOrigin verso la casella XYtarget" << std::endl;
    std::cout << "YY YY -> rimuove tutti gli avvistamenti sonar dalla griglia di attacco (carattere Y)" << std::endl;
    std::cout << "XX XX -> mostra la griglia di attacco e la griglia di difesa" << std::endl;
    std::cout << "BB BB -> rimuove tutti i caratteri relativi ai colpi andati a segno dalla griglia di attacco (carattere X)" << std::endl;
    std::cout << "CC CC -> rimuove tutti i caratteri relativi ai colpi andati a vuoto dalla griglia di attacco (carattere O)" << std::endl;

}
