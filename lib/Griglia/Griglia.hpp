#include "../../include/Griglia/Griglia.h"
#include <iostream>
using namespace std;
//costuttori
Griglia::Griglia(){
    for(int riga=0; riga<12; riga++ ){
        for(int colonna=0; colonna<12; colonna++){
            matrix[riga][colonna]=" ";
        }
    }
}

void Griglia::set(string toSet, string location){
    int character = location[0];
    character=character-65;
    if(character<0 || character>13){
        throw invalid_argument("Carattere non valido");
    }
    if (character == 9 || character == 10) {
        throw invalid_argument("Carattere non valido");
    }
    if (character > 10) {
        character -= 2;
    }
    int number=stoi(location.substr(1,2))-1;
    if(number<0 || number>11){
        throw invalid_argument("Numero non valido");
    }
    matrix[character][number] = toSet;
}

void Griglia::clear(){
    for(int riga=0; riga<12; riga++ ){
        for(int colonna=0; colonna<12; colonna++){
            matrix[riga][colonna]=" ";
        }
    }
}

void Griglia::remove(string location){
    int character = location[0];
    character = character - 65;
    if (character < 0 || character>13) {
        throw invalid_argument("Carattere non valido");
    }
    if (character == 9 || character == 10) {
        throw invalid_argument("Carattere non valido");
    }
    if (character > 10) {
        character -= 2;
    }
    int number=stoi(location.substr(1,2))-1;
    if(number<0 || number>11){
        throw invalid_argument("Numero non valido");
    }
    matrix[character][number] = " ";
}

string Griglia::retrive(string location){
    int character = location[0];
    character = character - 65;
    if (character < 0 || character>13) {
        throw invalid_argument("Carattere non valido");
    }
    if (character == 9 || character == 10) {
        throw invalid_argument("Carattere non valido");
    }
    if (character > 10) {
        character -= 2;
    }
    int number=stoi(location.substr(1,2))-1;
    if(number<0 || number>11){
        throw invalid_argument("Numero non valido");
    }
    return matrix[character][number];
}

void Griglia::remove_all(string to_remove) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (matrix[i][j] == to_remove) {
                matrix[i][j] = " ";
            }
        }
    }
}

//overload operator
ostream& operator<<(ostream& os, const Griglia to_Print){
    char rigaChar=65;

    os<<"  |1|2|3|4|5|6|7|8|9|10|11|12"<<std::endl;
    for(int riga=0; riga<12; riga++ ){
        if(rigaChar==74) rigaChar=rigaChar+2;
        os<<" "<<rigaChar;
        rigaChar++;
        for(int colonna=0; colonna<12; colonna++){
            os<<"|"<<to_Print.matrix[riga][colonna];
            if(colonna>=9){
                os<<" ";
            }
        }
        os<<endl;
    }
    return os;
}
