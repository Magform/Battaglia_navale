#include "../../include/Replay/Replay.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


Replay::Replay(std::string type) {
    if (type == "v") {
        string log_in;
        cin >> log_in;
        log_input.open(log_in);
        file_output = false;
    }
    else if{type == "f"} {
        string log_in, log_out;
        cin >> log_in >> log_out;
        log_input.open(log_in);
        log_output.open(log_out);
        file_output = true;
    }
    else {
        throw invalid_argument("Tipo di replay non valido");
    }
}

void Replay::setup() {
    try {
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
        g1_sottomarino1.set(inizio, fine, g1_difesa);

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
        g2_sottomarino1.set(inizio, fine, g2_difesa);
    }
    catch (const invalid_argument ex) {
        throw invalid_argument("Il file selezionato non e' una battaglia valida ");
    }
}


void Replay::turno() {
    try {
        string origin, target;
        write("Azione giocatore 1: ");
        log_input >> origin >> target;
        write(origin + " " + target + "\n");

        if (origin == g1_corazzata1.get_centro()) {
            g1_corazzata1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_corazzata2.get_centro()) {
            g1_corazzata2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_corazzata3.get_centro()) {
            g1_corazzata3.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_supporto1.get_centro()) {
            g1_supporto1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_supporto2.get_centro()) {
            g1_supporto2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_supporto3.get_centro()) {
            g1_supporto3.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_sottomarino1.get_centro()) {
            g1_sottomarino1.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else if (origin == g1_sottomarino2.get_centro()) {
            g1_sottomarino2.azione(target, g1_difesa, g1_attacco, g2_difesa);
        }
        else {
            throw invalid_argument("Battaglia nel file non valida);
        }
        write("-----Griglie di gioco giocatore 1-----\n");
        if (!file_output) {
            cout << g1_attacco << "\n";
            cout << g1_difesa << "\n";
            delay(1000);
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
            throw invalid_argument("Battaglia nel file non valida);
        }

        write("-----Griglie di gioco giocatore 2-----\n");
        if (!file_output) {
            cout << g2_attacco << "\n";
            cout << g2_difesa << "\n";
            delay(1000);
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


int Replay::g1_corazzate() {
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

int  Replay::g2_corazzate() {
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

int Replay::winner() {
    if (g1_corazzate() == 0) {
        return 1;
    }
    if (g2_corazzate() == 0) {
        return 2;
    }
    return 0;
}

void Replay::write(string toPrint) {
    if (!file_output) { 
        cout << toPrint;
    }
    else {
        log_output << toPrint;
    }
}

void Replay::fine() {
    write("Battaglia terminata, ha vinto il giocatore " + winner());
    if (file_output) {
        log_output.close()
    }
    log_input.close();
}
