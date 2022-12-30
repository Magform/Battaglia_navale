#include "../../include/Naval_units/Supporto.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Supporto : public NavalUnits{
public:
    
    void set(std::string inizio, std::string fine){

        char cInizio=inizio.at(0);
        int xInizio=stoi(inizio.substr(1,2))-1;
        int yInizio;
        if(cInizio<74){
            yInizio=cInizio-65;
        }else{
            yInizio=cInizio-67;
        }

        char cFine=fine.at(0);
        int xFine=stoi(fine.substr(1,2))-1;
        int yFine;
        if(cFine<74){
            yFine=cFine-65;
        }else{
            yFine=cFine-67;
        }

        if(xInizio==xFine){
            for(int k=0; k<3; k++){
                
                yInizio=yInizio+1;
                std::string Pos=yInizio+""+xInizio;

                Griglia.set("C", Pos);
            } 
        }else{
            for(int k=0; k<3; k++){
                
                xInizio=xInizio+1;
                std::string Pos=yInizio+""+xInizio;

                Griglia.set("S", Pos);
            }
        }
    }
    
   void azione(std::string centro, std::string obiettivo){

        char c=obiettivo.at(0);
        int XTarget=stoi(obiettivo.substr(1,2))-1;
        int YTarget;
        if(c<74){
            YTarget=c-65;
        }else{
            YTarget=c-67;
        }

        if(isvalid(YTarget, XTarget)){

            //elimino la vecchia posizione della nave di supporto e imposto quella nuova
            //riparazione mettendo in maiuscolo tutte le lettere intorno

            }else{

                throw std::invalid_argument("Carattere non valido");

            }
    }

    bool isvalid(int YTarget, int XTarget)}{    //funzione per verificare se la posizione nuova è valida

        if(matrix[YTarget][XTarget]==" "){
            if((matrix[YTarget][XTarget+1]==" ")&&((matrix[YTarget][XTarget-1]==" "))){ 
               
                return true;

                //Qui guardo se, oltre alla posizione data, sono liberi anche gli spazi laterali
            
            }else{
                if((matrix[YTarget+1][XTarget]==" ")&&((matrix[YTarget-1][XTarget]==" "))){ 
                 
                    return true;

                    //Qui guardo se, oltre alla posizione data, sono liberi anche gli spazi sopra e sotto
                }
            }
        }

    return false;
    }
};
