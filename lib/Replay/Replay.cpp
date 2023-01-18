#include "Replay.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

Replay::Replay(){}

//Funzione che apre i file di replay, richiede l'inseriemento del tipo di log voluto ed il file di log di una partita precente
//in caso il tipo di replay é f deve essere fornito il file dove creare l'output
//in caso il tipo di replay non sia valido (f,v) o in caso sia f e non sia presente un file di output viene lanciata un eccezion
void Replay::file_opening(std::string type, std::string log_in, std::string log_out){
    if (type == "v") {
        log_input.open(log_in);
        file_output = false;
    }
    else if(type == "f" && log_out != "") {
        log_input.open(log_in);
        log_output.open(log_out);
        file_output = true;
    }
    else {
        throw invalid_argument("Tipo di replay non valido o file di output non presente");
    }
}


//funzione cha va per prima cosa a aprire i file utilizzando la funzione privata file_opening(vederla per ulteriori informazioni)
//Gestisce poi l'inserimento delle navi dei due giocatori.
void Replay::setup(std::string type, std::string log_in, std::string log_out) {
    try {
        file_opening(type, log_in, log_out);
        std::string inizio, fine;

        write("-----Inserimento navi giocatore 1-----\n");

        write("Corazzata 1: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_corazzata1.set(inizio, fine, g1_difesa);

        write("Corazzata 2: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_corazzata2.set(inizio, fine, g1_difesa);

        write("Corazzata 3: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_corazzata3.set(inizio, fine, g1_difesa);

        write("Supporto 1: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_supporto1.set(inizio, fine, g1_difesa);

        write("Supporto 2: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_supporto2.set(inizio, fine, g1_difesa);

        write("Supporto 3: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_supporto3.set(inizio, fine, g1_difesa);

        write("Sottomarino 1: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_sottomarino1.set(inizio, fine, g1_difesa);

        write("Sottomarino 2: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g1_sottomarino2.set(inizio, fine, g1_difesa);

        write("-----Inserimento navi giocatore 2-----\n");

        write("Corazzata 1: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_corazzata1.set(inizio, fine, g2_difesa);

        write("Corazzata 2: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_corazzata2.set(inizio, fine, g2_difesa);

        write("Corazzata 3: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_corazzata3.set(inizio, fine, g2_difesa);

        write("Supporto 1: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_supporto1.set(inizio, fine, g2_difesa);

        write("Supporto 2: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_supporto2.set(inizio, fine, g2_difesa);

        write("Supporto 3: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_supporto3.set(inizio, fine, g2_difesa);

        write("Sottomarino 1: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_sottomarino1.set(inizio, fine, g2_difesa);

        write("Sottomarino 2: ");
        log_input >> inizio >> fine;
        write(inizio + " " + fine + "\n");
        g2_sottomarino2.set(inizio, fine, g2_difesa);
    }
    catch (const invalid_argument ex) {
        throw invalid_argument("Il file selezionato non e' una battaglia valida ");
    }
}


//Funzione che gestisce l'esecuzione dei turni e scrive, dove richiesto, l'azione eseguita e le griglie dei due giocatori
//Lancia un eccezione invalid_argument se vi é qualche problema presente nel file di log
void Replay::turno() {
    try {
        string origin, target;
        write("Azione giocatore 1: ");
        log_input >> origin >> target;
        write(origin + " " + target + "\n");

        if (origin == g1_corazzata1.get_centro()) {
            cout << "corazzata1" << centro << endl;
            g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_corazzata2.get_centro()) {
            cout << "corazzata2" << centro << endl;
            g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_corazzata3.get_centro()) {
            cout << "corazzata3" << centro << endl;
            g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_supporto1.get_centro()) {
            cout << "supporto1" << centro << endl;
            g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_supporto2.get_centro()) {
            cout << "supporto2" << centro << endl;s
            g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_supporto3.get_centro()) {
            cout << "supporto3" << centro << endl;
            g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_sottomarino1.get_centro()) {
            cout << "sottomarino1" << centro << endl;
            g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_sottomarino2.get_centro()) {
            cout << "sottomarino2" << endl;
            g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else {
            throw invalid_argument("Battaglia nel file non valida");
        }
        write("-----Griglie di gioco giocatore 1-----\n");
        if (!file_output) {
            cout << g1_attacco << "\n";
            cout << g1_difesa << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else {
            log_output << g1_attacco << "\n";
            log_output << g1_difesa << "\n";
        }

        write("Azione giocatore 2: ");
        log_input >> origin >> target;
        write(origin + " " + target + "\n");

        if (origin == g2_corazzata1.get_centro()) {
            g2_corazzata1.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_corazzata2.get_centro()) {
            g2_corazzata2.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_corazzata3.get_centro()) {
            g2_corazzata3.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_supporto1.get_centro()) {
            g2_supporto1.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_supporto2.get_centro()) {
            g2_supporto2.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_supporto3.get_centro()) {
            g2_supporto3.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_sottomarino1.get_centro()) {
            g2_sottomarino1.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else if (origin == g2_sottomarino2.get_centro()) {
            g2_sottomarino2.azione(target, g2_difesa, g2_attacco, g1_difesa);
        }
        else {
            throw invalid_argument("Battaglia nel file non valida");
        }

        write("-----Griglie di gioco giocatore 2-----\n");
        if (!file_output) {
            cout << g2_attacco << "\n";
            cout << g2_difesa << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else {
            log_output << g2_attacco << "\n";
            log_output << g2_difesa << "\n";
        }
    }
    catch (const invalid_argument) {
        throw invalid_argument("Il file selezionato non e' una battaglia valida ");
    }

}


//Funzione che conta le navi del giocatore1
int Replay::g1_navi() {
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
int Replay::g2_navi() {
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


//se ritorna 1 vince giocatore 1, se ritorna 2 vince giocatore 2
int Replay::winner() {
    if (g1_navi() == 0) {
        return 1;
    }
    if (g2_navi() == 0) {
        return 2;
    }
    return 0;
}


//funzione da chiamare quando termina la battaglia che si occupa di scrivere in output l'eventuale vincitore e di chiudere i file di input e output
void Replay::fine() {
    if (winner() != 0) {
        write("Battaglia terminata, ha vinto il giocatore " + winner());
    }
    else {
        write("Non vi é stato alcun vincitore");
    }
    if (file_output) {
        log_output.close();
    }
    log_input.close();
}


//funzione che accetando una stringa la scrive nel file di log se richiesto oppure la stampa a schermo
void Replay::write(string toPrint) {
    if (!file_output) {
        cout << toPrint;
    }
    else {
        log_output << toPrint;
    }
}
