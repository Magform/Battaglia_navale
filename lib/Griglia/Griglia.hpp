#include "../../include/Griglia/Griglia.h"

//costuttori
Griglia::Griglia(){
    for(int riga=0; riga<12; riga++ ){
        for(int colonna=0; colonna<12; colonna++){
            matrix[riga][colonna]=" ";
        }
    }
}

void Griglia::set(std::string toSet, std::string location){
    int character = location[0];
    character = character-65;
    if(character<0 || character>11){
        throw std::invalid_argument("Carattere non valido");
    }
    int number =  location[1] - 49;
    if(location.length()==3){
        number = number*10+location[2] - 49;
    }
    if(number<0 || number>11){
        throw std::invalid_argument("Numero non valido");
    }
    matrix[character][number] = toSet;
}

void Griglia::remove(std::string location){
    int character = location[0];
    character = character-65;
    if(character<0 || character>11){
        throw std::invalid_argument("Carattere non valido");
    }
    int number =  location[1] - 49;
    if(location.length()==3){
        number = number*10+location[2] - 49;
    }
    if(number<0 || number>11){
        throw std::invalid_argument("Numero non valido");
    }
    matrix[character][number] = " ";
}

std::string Griglia::retrive(std::string location){
    int character = location[0];
    character = character-65;
    if(character<0 || character>11){
        throw std::invalid_argument("Carattere non valido");
    }
    int number =  location[1] - 49;
    if(location.length()==3){
        number = number*10+location[2] - 49;
    }
    if(number<0 || number>11){
        throw std::invalid_argument("Numero non valido");
    }
    return matrix[character][number];
}




//overload operator
std::ostream& operator<<(std::ostream& os, const Griglia to_Print){
    char rigaChar=65;

    os<<" |1|2|3|4|5|6|7|8|9|10|11|12"<<std::endl;
    for(int riga=0; riga<12; riga++ ){
        os<<rigaChar;
        rigaChar++;
        for(int colonna=0; colonna<12; colonna++){
            os<<"|"<<to_Print.matrix[riga][colonna];
            if(colonna>=9){
                os<<" ";
            }
        }
        os<<std::endl;
    }
    return os;
}
