#include "../../include/Griglia/Griglia.h"
#include <iostream>
using namespace std;


//Costruttore che crea la griglia e la inizializza tutta vuota
Griglia::Griglia(){ 
    for(int riga=0; riga<12; riga++ ){
        for(int colonna=0; colonna<12; colonna++){
            matrix[riga][colonna]=" ";
        }
    }
}


//Posiziona la stringa toSot alla posizione location
//Prima di farlo peró si assicura che la posizione location é presente nella griglia, in caso negativo lancia un eccezione invalid_argument
void Griglia::set(string toSet, string location){
    int character = location[0];
    character=character-65;
    if(character<0 || character>13){
        throw invalid_argument("Carattere della location non valido");
    }
    if (character == 9 || character == 10) {
        throw invalid_argument("Carattere della location non valido");
    }
    if (character > 10) {
        character -= 2;
    }
    int number=stoi(location.substr(1,2))-1;
    if(number<0 || number>11){
        throw invalid_argument("Numero della location non valido");
    }
    matrix[character][number] = toSet;
}


//Cancella tutti i valori presenti nella griglia
void Griglia::clear(){
    for(int riga=0; riga<12; riga++ ){
        for(int colonna=0; colonna<12; colonna++){
            matrix[riga][colonna]=" ";
        }
    }
}


//Rimuove la stringa nella posizione location
//Prima di farlo peró si assicura che la posizione location é presente nella griglia, in caso negativo lancia un eccezione invalid_argument
void Griglia::remove(string location){
    int character = location[0];
    character = character - 65;
    if (character < 0 || character>13) {
        throw invalid_argument("Carattere della location non valido");
    }
    if (character == 9 || character == 10) {
        throw invalid_argument("Carattere della location non valido");
    }
    if (character > 10) {
        character -= 2;
    }
    int number=stoi(location.substr(1,2))-1;
    if(number<0 || number>11){
        throw invalid_argument("Numero della location non valido");
    }
    matrix[character][number] = " ";
}


//Restituisce la stringa nella posizione location
//Prima di farlo peró si assicura che la posizione location é presente nella griglia, in caso negativo lancia un eccezione invalid_argument
string Griglia::retrive(string location){
    int character = location[0];
    character = character - 65;
    if (character < 0 || character>13) {
        throw invalid_argument("Carattere della location non valido");
    }
    if (character == 9 || character == 10) {
        throw invalid_argument("Carattere della location non valido");
    }
    if (character > 10) {
        character -= 2;
    }
    int number=stoi(location.substr(1,2))-1;
    if(number<0 || number>11){
        throw invalid_argument("Numero della location non valido");
    }
    return matrix[character][number];
}


//Rimuove un determinato valore interamente dalla griglia
//Scansiona tutta la griglia ed ogni volta che trova il valore cercato lo rimuove
void Griglia::remove_all(string to_remove) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (matrix[i][j] == to_remove) {
                matrix[i][j] = " ";
            }
        }
    }
}

//overload operator <<
//Stampa a schermo la griglia fornendo anche il numero nelle colonne e la lettera nella righe
ostream& operator<<(ostream& os, const Griglia to_Print){
    char rigaChar=65;

    os<<"   1   2   3   4   5   6   7   8   9   10  11  12"<<endl;
    for(int riga=0; riga<12; riga++ ){
        os<<"  --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        if(rigaChar==74) rigaChar=rigaChar+2;
        os<<rigaChar<<"|";
        rigaChar++;
        for(int colonna=0; colonna<12; colonna++){
                
            os<<" "<<to_Print.matrix[riga][colonna]<<" |";

        }
        os<<endl;
    }
    os<<"  --- --- --- --- --- --- --- --- --- --- --- ---"<<"\n";
    return os;
}
