#include <iostream>
#include "Griglia.h"

//costuttori
Griglia(){
    for(int riga=0; riga<12; riga++ ){
        for(int colonna=0; colonna<12; colonna++){
            matrix[riga][colonna]=" ";
        }
    }
}

std::ostream operator<<(std::ostream os, const Griglia to_Print){
    char rigaChar=65;

    os<<" |1|2|3|4|5|6|7|8|9|10|11|12"<<endl;
    for(int riga=0; riga<12; riga++ ){
        os<<rigaChar;
        rigaChar++;
        for(int colonna=0; colonna<12; colonna++){
            os<<"|"<<matrix[riga][colonna];
            if(colonna>=9){
                os<<" ";
            }
        os<<endl;
        }
    }
}
