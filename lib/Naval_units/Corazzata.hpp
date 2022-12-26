#include "../../include/Naval_units/Corazzata.h"

void Corazzata::set(std::string inizio, std::string fine){

    int Inizio_character = inizio[0];
    Inizio_character = Inizio_character - 65;
    if (Inizio_character < 0 || Inizio_character>11) {
        throw std::invalid_argument("Carattere inizio non valido");
    }
    int Inizio_number = inizio[1] - 49;
    if (inizio.length() == 3) {
        Inizio_number = Inizio_number * 10 + inizio[2] - 49;
    }
    if (Inizio_number < 0 || Inizio_number>11) {
        throw std::invalid_argument("Numero inizio non valido");
    }
    
    int Fine_character = fine[0];
    Fine_character = Fine_character - 65;
    if (Fine_character < 0 || Fine_character>11) {
        throw std::invalid_argument("Carattere fine non valido");
    }
    int Fine_number = fine[1] - 49;
    if (fine.length() == 3) {
        Fine_number = Fine_number * 10 + fine[2] - 49;
    }
    if (Fine_number < 0 || Fine_number>11) {
        throw std::invalid_argument("Numero fine non valido");
    }

    //Ho un problema, non so come scrivere nella griglia da qua?!?!?! Non riesco a trovare un modo di passarmela volevo provarea ad avere l'Indirizzo in una variabile ma non riesco

    //Controlla che non sia presente qualocosa nelle varie posizioni della griglia con griglia.retrive
    //Scrive nella griuglia con griglia.set
}

}

void Corazzata::azione(std::string centro) {

}
