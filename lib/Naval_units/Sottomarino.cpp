#include <iostream>
#include "NavalUnits.hpp"

class Sottomarino : public NavalUnits{
public:
    void azione(int YTarget, int XTarget){

        if(matrix[YTarget][XTarget]==" "){
            PosValid=true;

            //elimino la vecchia posizione del sottomarino e imposto quella nuova
            //radar

        }else{

            //Gestione posizione invalida del sottomarino

        }
    }
};