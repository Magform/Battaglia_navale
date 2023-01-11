#include "../../include/Naval_battle/Naval_battle.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//funzioni utili.
std::string location_to_string(int X, int Y);
void create_corazzata(Corazzata unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);
void create_supporto(Supporto unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);
void create_sottomarino(Sottomarino unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log);
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
                std::cout << "Quali sono le coordinate per la corazzata 1: " << endl;
                std::cin >> inizio >> fine;
                g1_corazzata1.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per la corazzata 2: " << endl;
                std::cin >> inizio >> fine;
                g1_corazzata2.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per la corazzata 3: " << endl;
                std::cin >> inizio >> fine;
                g1_corazzata3.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per la nave di supporto 1: " << endl;
                std::cin >> inizio >> fine;
                g1_supporto1.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per la nave di supporto 2: " << endl;
                std::cin >> inizio >> fine;
                g1_supporto2.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per la nave di supporto 3: " << endl;
                std::cin >> inizio >> fine;
                g1_supporto3.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per il sottomarino 1: " << endl;
                std::cin >> inizio >> fine;
                g1_sottomarino1.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
            }
            catch (const invalid_argument ex) {
                cout << "Le coordinate inserite non sono valide, inserirle nuovamente" << endl;
            }
        }
        accepted = false;

        while (!accepted) {
            try {
                std::cout << "Quali sono le coordinate per il sottomarino 2: " << endl;
                std::cin >> inizio >> fine;
                g1_sottomarino2.set(inizio, fine, g1_difesa);
                if (log) { log_file << inizio << fine << endl; }
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
    else if (origin == "XX" && target == "XX") {
        cout << g1_difesa;
        cout << g1_attacco;
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
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_corazzata2.get_centro()) {
        try {
            g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_corazzata3.get_centro()) {
        try {
            g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_supporto1.get_centro()) {
        try {
            g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_supporto2.get_centro()) {
        try {
            g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_supporto3.get_centro()) {
        try {
            g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_sottomarino1.get_centro()) {
        try {
            g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else if (origin == g1_sottomarino2.get_centro()) {
        try {
            g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            if (log) { log_file << origin << target << endl; }
        }
        catch (const invalid_argument ex) {
            cout << "Azione non valida, inserire un nuovo comando" << endl;
            accept_command();
        }
    }else {
        cout << "nessuna nave ha il centro nella casella di origine dell'attacco, inserire una nuova azione" << endl;
        accept_command();
    }

}

void Naval_battle::bot_command() {
    if (botBattle) {
        bool command_accepted = false;
        while (!command_accepted) {
            srand(time(NULL));
            int attaccante = rand() % 8 + 0;
            int locationX, locationY;
            locationX = rand() % 12 + 0;
            locationY = rand() % 12 + 0;
            string target = location_to_string(locationX, locationY);
            switch (attaccante) {
            case 0:
                try {
                    g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 1:
                try {
                    g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 2:
                try {
                    g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 3:
                try {
                    g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 4:
                try {
                    g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 5:
                try {
                    g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 6:
                try {
                    g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            case 7:
                try {
                    g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
                    if (log) { log_file << origin << target << endl; }
                    command_accepted = true;
                }
                catch (const invalid_argument ex) {}
                break;
            }
        }
    }
    bool command_accepted = false;
    while (!command_accepted) {
        srand(time(NULL));
        int attaccante = rand() % 8 + 0;
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string target = location_to_string(locationX, locationY);
        switch (attaccante) {
        case 0:
            try {
                g2_corazzata1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 1:
            try {
                g2_corazzata2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 2:
            try {
                g2_corazzata3.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 3:
            try {
                g2_supporto1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 4:
            try {
                g2_supporto2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 5:
            try {
                g2_supporto3.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 6:
            try {
                g2_sottomarino1.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
                command_accepted = true;
            }
            catch (const invalid_argument ex) {}
            break;
        case 7:
            try {
                g2_sottomarino2.azione(target, g2_difesa, g2_attacco, g1_difesa);
                if (log) { log_file << origin << target << endl; }
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
        return 1;
    }
    if (g2_corazzate() == 0) {
        return 2;
    }
    return 0;
}

//Funzioni utili
void create_corazzata(Corazzata unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log){
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string inizio = location_to_string(locationX, locationY);

        int direzione = rand() % 4 + 0;
        string fine{};
        switch (direzione) {
        case 0:
            fine = location_to_string(locationX -5, locationY);
            break;
        case 1:
            fine = location_to_string(locationX + 5, locationY);
            break;
        case 2:
            fine = location_to_string(locationX, locationY - 5);
            break;
        case 3:
            fine = location_to_string(locationX, locationY + 5);
            break;
        }
        try {

            unita.set(inizio, fine, griglia_difesa);
            if (log) { log_file << inizio << fine << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {      //eccezione ancora da decidere
            isGood = false;
        }
    }
}

void create_supporto(Supporto unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log) {
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string inizio = location_to_string(locationX, locationY);

        int direzione = rand() % 4 + 0;
        string fine{};
        switch (direzione) {
        case 0:
            fine = location_to_string(locationX - 3, locationY);
            break;
        case 1:
            fine = location_to_string(locationX + 3, locationY);
            break;
        case 2:
            fine = location_to_string(locationX, locationY - 3);
            break;
        case 3:
            fine = location_to_string(locationX, locationY + 3);
            break;
        }
        try {

            unita.set(inizio, fine, griglia_difesa);
            if (log) { log_file << inizio << fine << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {
            isGood = false;
        }
    }
}

void create_sottomarino(Sottomarino unita, Griglia& griglia_difesa, std::ofstream& log_file, bool log) {
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 12 + 0;
        locationY = rand() % 12 + 0;
        string inizio = location_to_string(locationX, locationY);
        try {

            unita.set(inizio, inizio, griglia_difesa);
            if (log) { log_file << inizio << inizio << endl; }
            isGood = true;
        }
        catch (const std::invalid_argument ex) {
            isGood = false;
        }
    }
}

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
        output = output + "A"; //se il valore non é valido ho deciso di, invece di lanciare un eccezzione, impostare la colonna A.
    }
    output = output + to_string(Y);
    return output;
}




void print_command() {
    std::cout << "Lista dei comandi possibili:" << std::endl;
    std::cout << "HH HH -> mostra questa lista di comandi" << std::endl;
    std::cout << "XYOrigin XYTarget -> esegue l'azione della nave centrata in XYOrigin verso la casella XYtarget" << std::endl;
    std::cout << "YY YY -> rimuove tutti gli avvistamenti sonar dalla griglia di attacco (carattere Y)" << std::endl;
    std::cout << "XX XX -> mostra la griglia di attacco e la griglia di difesa" << std::endl;
    std::cout << "BB BB -> rimuove tutti i caratteri relativi ai colpi andati a segno dalla griglia di attacco (carattere X)" << std::endl;
    std::cout << "CC CC -> rimuove tutti i caratteri relativi ai colpi andati a vuoto dalla griglia di attacco (carattere O)" << std::endl;

}
