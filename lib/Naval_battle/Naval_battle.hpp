#include "../../include/Naval_battle/Naval_battle.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace this_thread;
using namespace chrono;

//funzioni utili.
std::string location_to_string(int X, int Y);
void create_corazzata(Corazzata& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);		//funzione utilizzata dal bot per creare la corazzata "in maniera casuale" (=messa casualmente in orizzontale o verticale)
void create_supporto(Supporto& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);		//funzione utilizzata dal bot per creare la nave di supporto "in maniera casuale" (=messa casualmente in orizzontale o verticale)
void create_sottomarino(Sottomarino& unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);	//funzione utilizzata dal bot per creare il sottomarino "in maniera casuale" (=messa casualmente in orizzontale o verticale)
void print_command();


//costruttore di Naval_battle, richiede la conosceza del tipo di battaglia e se é necessario o meno creare i log in output (Cosi posso andare ad utilizzare la medesima classe anche per il Replay)
Naval_battle::Naval_battle(std::string battletype, bool log_or_not) {
	if (battletype == "pc") {
		botBattle = false;
	}else if (battletype == "cc") {
		botBattle = true;
    	}
    	else {
        	throw std::invalid_argument("Argomento non valido");
    	}
    	log = log_or_not;
    	if (log) {
    	    log_file.open("log.txt");
    	}
}

void Naval_battle::setup() {
    if (botBattle == false) {
        std::string inizio, fine;

        bool accepted = false;
        while (!accepted) {
            try {
                std::cout << "Coordinate della corazzata 1: " << endl;
                std::cin >> inizio >> fine;
                g1_corazzata1.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << " " << fine << endl; }
		accepted=true;
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
		accepted=true;
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
		accepted=true;
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
		accepted=true;
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
		accepted=true;
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
		accepted=true;
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
		accepted=true;
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
		accepted=true;
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
    
    //una volta "create" tutte le navi stampo in output la griglia del giocatore 1
    cout<<"\n------GRIGLIA DEL GIOCATORE 1-----"<<endl;
    cout<<g1_difesa<<"\n";
}


void Naval_battle::accept_command(){
    cout << "Inserire comando (HH HH per mostrare tutti i comandi possibili) \n";
    std::string origin, target;
    cin >> origin >> target;
    //se il comadno inserito non è un'azione che deve  fare una delle varie navi
    if (origin == "HH" && target == "HH") {
        print_command();
        accept_command();
    }
    else if(origin=="AA" && target=="AA"){
        g1_attacco.remove_all("Y");
        accept_command();
    }
    else if (origin == "XX" && target == "XX") 
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
    //se il comando inserito fa fare un'azione a una delle navi disponibili
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

void Naval_battle::bot_command() {
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    string old_centro;
    //azione da parte del bot (in maniera casuale)
    if (botBattle) {
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
                    old_centro=g1_corazzata1.get_centro();
                    g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro << " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 1:
                try {
                    old_centro=g1_corazzata2.get_centro();
                    g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro<< " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 2:
                try {
                    old_centro=g1_corazzata3.get_centro();
                    g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro << " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 3:
                try {
                    old_centro=g1_supporto1.get_centro();
                    g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro << " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 4:
                try {
                    old_centro=g1_supporto2.get_centro();
                    g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro << " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 5:
                try {
                    old_centro=g1_supporto3.get_centro();
                    g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro << " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 6:
                try {
                    old_centro=g1_sottomarino1.get_centro();
                    g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro << " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 7:
                try {
                    old_centro=g1_sottomarino2.get_centro();
                    g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << old_centro<< " " << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    bool command_accepted = false;

    //azione del bot (in maniera casuale)
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
                old_centro=g2_corazzata1.get_centro();
                g2_corazzata1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 1:
            try {
                old_centro=g2_corazzata2.get_centro();
                g2_corazzata2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file <<"" <<old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 2:
            try {
                old_centro=g2_corazzata3.get_centro();
                g2_corazzata3.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 3:
            try {
                old_centro=g2_supporto1.get_centro();
                g2_supporto1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 4:
            try {
                old_centro=g2_supporto2.get_centro();
                g2_supporto2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 5:
            try {
                old_centro=g2_supporto3.get_centro();
                g2_supporto3.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 6:
            try {
                old_centro=g2_sottomarino1.get_centro();
                g2_sottomarino1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file <<old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 7:
            try {
                old_centro=g2_sottomarino2.get_centro();
                g2_sottomarino2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << old_centro << " " << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        }
    }
}

int Naval_battle::g1_corazzate() {
    int toReturn{ 0 };
    if (g1_corazzata1.isAlive()) {
        toReturn++;
    }
    if (g1_corazzata2.isAlive()) {
        toReturn++;
    }
    if (g1_corazzata3.isAlive()) {
        toReturn++;
    }
    return toReturn;
}

int  Naval_battle::g2_corazzate() {
    int toReturn{ 0 };
    if (g2_corazzata1.isAlive()) {
        toReturn++;
    }
    if (g2_corazzata2.isAlive()) {
        toReturn++;
    }
    if (g2_corazzata3.isAlive()) {
        toReturn++;
    }
    return toReturn;
}

bool Naval_battle::is_botBattle() {
    return botBattle;
}

int Naval_battle::winner() {
    if (g1_corazzate() == 0) {
        log_file.close();
        return 1;
    }
    if (g2_corazzate() == 0) {
        log_file.close();
        return 2;
    }
    return 0;
}

//Funzioni utili
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
	
	try{
        	//switch per decidere la posizione in cui il bot andrà a mettere la propria corazzata
		switch (direzione) {
	        case 0:
			if(locationX -4<0)throw invalid_argument("Numero non valido");
			fine = location_to_string(locationX -4, locationY);
			break;
     	        case 1:
			if(locationX +4>12)throw invalid_argument("Numero non valido");
			fine = location_to_string(locationX + 4, locationY);
			break;
        	case 2:
			if(locationY -4<0)throw invalid_argument("Numero non valido");
            		fine = location_to_string(locationX, locationY - 4);
            		break;
       		case 3:
			if(locationY+4>12)throw invalid_argument("Numero non valido");
            		fine = location_to_string(locationX, locationY + 4);
            		break;
        	}
        

            unita.set(inizio, fine, griglia_difesa);	//chiamo il set della corazzata per "crearla"
            if (log) { log_file << inizio << " " << fine << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {      //eccezione ancora da decidere
            isGood = false;
        }
    }
}

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
	   
	try{
        	//switch per decidere la posizione in cui il bot andrà a mettere la propria nave di supporto
		switch (direzione) {
        	case 0:
			if(locationX -2<0)throw invalid_argument("Numero non valido");
            		fine = location_to_string(locationX - 2, locationY);
            		break;
        	case 1:
			if(locationX +2>12)throw invalid_argument("Numero non valido");
            		fine = location_to_string(locationX + 2, locationY);
            		break;
        	case 2:
			if(locationY -2<0)throw invalid_argument("Numero non valido");
            		fine = location_to_string(locationX, locationY - 2);
            		break;
        	case 3:
			if(locationY+2>12)throw invalid_argument("Numero non valido");
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

//metodo ausialiaro
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
        output = output + "A"; //se il valore non é valido, invece di lanciare un eccezzione, ho deciso di impostare la colonna A di default.
    }
    output = output + to_string(Y);
    return output;
}

//metodo ausiliario
void print_command() {
    std::cout << "Lista dei comandi possibili:" << std::endl;
    std::cout << "HH HH -> mostra questa lista di comandi" << std::endl;
    std::cout << "XYOrigin XYTarget -> esegue l'azione della nave centrata in XYOrigin verso la casella XYtarget" << std::endl;
    std::cout << "YY YY -> rimuove tutti gli avvistamenti sonar dalla griglia di attacco (carattere Y)" << std::endl;
    std::cout << "XX XX -> mostra la griglia di attacco e la griglia di difesa" << std::endl;
    std::cout << "BB BB -> rimuove tutti i caratteri relativi ai colpi andati a segno dalla griglia di attacco (carattere X)" << std::endl;
    std::cout << "CC CC -> rimuove tutti i caratteri relativi ai colpi andati a vuoto dalla griglia di attacco (carattere O)" << std::endl;

}
