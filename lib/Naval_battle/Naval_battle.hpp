#include "../../include/Naval_battle/Naval_battle.h"

using namespace std;
//funzioni utili
//std::string location_to_string(int X, int Y);
void create_corazzata(Corazzata unita, int lunghezza, Griglia& griglia_difesa, std::ofstream log_file, bool log);
void create_supporto(Supporto unita, int lunghezza, Griglia& griglia_difesa, std::ofstream log_file, bool log);
void create_sottomarino(Sottomarino unita, int lunghezza, Griglia& griglia_difesa, std::ofstream log_file, bool log);
void print_command();

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
}

void Naval_battle::setup() {
    //se abbiamo i log accesi allora vado ad utilizzare il file log.txt per scrivere il log.
    std::ofstream log_file;
    if (log) {
        log_file.open("log.txt");
    }

    if (botBattle = false) {
        std::string inizio, fine;
        std::cout << "Quali sono le coordinate per la corazzata 1: "<<endl;
        std::cin >> inizio >> fine;
        if(log){ log_file << inizio << fine<< endl; }
        g1_corazzata1.set(inizio, fine, g1_difesa);
        std::cout << "Quali sono le coordinate per la corazzata 2: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_corazzata2.set(inizio, fine, g1_difesa);
        std::cout << "Quali sono le coordinate per la corazzata 3: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_corazzata3.set(inizio, fine, g1_difesa);

        std::cout << "Quali sono le coordinate per la nave di supporto 1: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_supporto1.set(inizio, fine, g1_difesa);
        std::cout << "Quali sono le coordinate per la nave di supporto 2: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_supporto2.set(inizio, fine, g1_difesa);
        std::cout << "Quali sono le coordinate per la nave di supporto 3: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_supporto3.set(inizio, fine, g1_difesa);

        std::cout << "Quali sono le coordinate per il sottomarino 1: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_sottomarino1.set(inizio, fine, g1_difesa);
        std::cout << "Quali sono le coordinate per il sottomarino 2: "<<endl;
        std::cin >> inizio >> fine;
        if (log) { log_file << inizio << fine << endl; }
        g1_sottomarino2.set(inizio, fine, g1_difesa);
    }
    else {
        create_corazzata(g1_corazzata1, 5, g1_difesa, log_file, log);
        create_corazzata(g1_corazzata2, 5, g1_difesa, log_file, log);
        create_corazzata(g1_corazzata3, 5, g1_difesa, log_file, log);
        create_supporto(g1_supporto1, 3, g1_difesa, log_file, log);
        create_supporto(g1_supporto2, 3, g1_difesa, log_file, log);
        create_supporto(g1_supporto3, 3, g1_difesa, log_file, log);
        create_sottomarino(g1_sottomarino1, 0, g1_difesa, log_file, log);
        create_sottomarino(g1_sottomarino2, 0, g1_difesa, log_file, log);
    }
    create_corazzata(g2_corazzata1, 5, g2_difesa, log_file, log);
    create_corazzata(g2_corazzata2, 5, g2_difesa, log_file, log);
    create_corazzata(g2_corazzata3, 5, g2_difesa, log_file, log);
    create_supporto(g2_supporto1, 3, g2_difesa, log_file, log);
    create_supporto(g2_supporto2, 3, g2_difesa, log_file, log);
    create_supporto(g2_supporto3, 3, g2_difesa, log_file, log);
    create_sottomarino(g2_sottomarino1, 0, g2_difesa, log_file, log);
    create_sottomarino(g2_sottomarino2, 0, g2_difesa, log_file, log);
}


void Naval_battle::accept_command(){
    cout << "Inserire comando (HH HH per mostrare tutti i comandi possibili) \n";
    std::string origin, target;
    cin >> origin >> target;
    if (origin == "HH" && target == "HH") {
        print_command();
        accept_command();
    }
    if(origin=="AA" && target=="AA"){
        g1_attacco.remove_all("Y");
        accept_command();
    }
    if (origin == "XX" && target == "XX") {
        cout << g1_difesa;
        cout << g1_attacco;
        accept_command();
    }
    if (origin == "BB" && target == "BB") {
        g1_attacco.remove_all("X");
        accept_command();
    }
    if (origin == "CC" && target == "CC") {
        g1_attacco.remove_all("O");
        accept_command();
    }
    if (origin == g1_corazzata1.get_centro()) {
        g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_corazzata2.get_centro()) {
        g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_corazzata3.get_centro()) {
        g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_supporto1.get_centro()) {
        g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_supporto2.get_centro()) {
        g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_supporto3.get_centro()) {
        g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_sottomarino1.get_centro()) {
        g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else if (origin == g1_sottomarino2.get_centro()) {
        g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
    }else {
        throw std::invalid_argument("Nessuna nave ha il centro nel punto selezionato");
    }
}

void Naval_battle::bot_command() {
    if (botBattle) {
        srand(time(NULL));
        int attaccante = rand() % 7 + 0;
        int locationX, locationY;
        locationX = rand() % 11 + 0;
        locationY = rand() % 11 + 0;
        string target = location_to_string(locationX, locationY);
        switch (attaccante) {
        case 0:
            g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 1:
            g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 2:
            g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 3:
            g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 4:
            g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 5:
            g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 6:
            g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        case 7:
            g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
            break;
        }
    }
    srand(time(NULL));
    int attaccante = rand() % 7 + 0;
    int locationX, locationY;
    locationX = rand() % 11 + 0;
    locationY = rand() % 11 + 0;
    string target = location_to_string(locationX, locationY);
    switch (attaccante) {
    case 0:
        g2_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 1:
        g2_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 2:
        g2_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 3:
        g2_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 4:
        g2_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 5:
        g2_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 6:
        g2_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    case 7:
        g2_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        break;
    }
}

//Funzioni utili
void create_corazzata(Corazzata unita, int lunghezza, Griglia& griglia_difesa, std::ofstream log_file, bool log){
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
            fine = location_to_string(locationX - lunghezza, locationY);
            break;
        case 1:
            fine = location_to_string(locationX + lunghezza, locationY);
            break;
        case 2:
            fine = location_to_string(locationX, locationY - lunghezza);
            break;
        case 3:
            fine = location_to_string(locationX, locationY + lunghezza);
            break;
        }
        try {

            unita.set(inizio, fine, griglia_difesa);
            if (log) { log_file << inizio << fine << endl; }
            isGood = true;
        }
        catch () {      //eccezione ancora da decidere
            isGood = false;
        }
    }
}

void create_supporto(Supporto unita, int lunghezza, Griglia& griglia_difesa, std::ofstream log_file, bool log) {
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 11 + 0;
        locationY = rand() % 11 + 0;
        string inizio = location_to_string(locationX, locationY);

        int direzione = rand() % 3 + 0;
        string fine{};
        switch (direzione) {
        case 0:
            fine = location_to_string(locationX - lunghezza, locationY);
            break;
        case 1:
            fine = location_to_string(locationX + lunghezza, locationY);
            break;
        case 2:
            fine = location_to_string(locationX, locationY - lunghezza);
            break;
        case 3:
            fine = location_to_string(locationX, locationY + lunghezza);
            break;
        }
        try {

            unita.set(inizio, fine, griglia_difesa);
            if (log) { log_file << inizio << fine << endl; }
            isGood = true;
        }
        catch () {      //eccezione ancora da decidere
            isGood = false;
        }
    }
}

void create_sottomarino(Sottomarino unita, int lunghezza, Griglia& griglia_difesa, std::ofstream log_file, bool log) {
    bool isGood = false;
    while (!isGood) {
        srand(time(NULL));
        int locationX, locationY;
        locationX = rand() % 11 + 0;
        locationY = rand() % 11 + 0;
        string inizio = location_to_string(locationX, locationY);

        int direzione = rand() % 3 + 0;
        string fine{};
        switch (direzione) {
        case 0:
            fine = location_to_string(locationX - lunghezza, locationY);
            break;
        case 1:
            fine = location_to_string(locationX + lunghezza, locationY);
            break;
        case 2:
            fine = location_to_string(locationX, locationY - lunghezza);
            break;
        case 3:
            fine = location_to_string(locationX, locationY + lunghezza);
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

bool Naval_battle::is_botBattle(){
    return botBattle;
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
