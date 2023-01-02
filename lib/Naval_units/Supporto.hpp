#include "../../include/Naval_units/Supporto.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Supporto : public Naval_units{
public:
    
    void set(std::string inizio, std::string fine){

        char cInizio=inizio.at(0);
        int xInizio=stoi(inizio.substr(1,2))-1;
        int yInizio;
        if(cInizio<76){
            yInizio=cInizio-65;
        }

        char cFine=fine.at(0);
        int xFine=stoi(fine.substr(1,2))-1;
        int yFine;
        if(cFine<76){
            yFine=cFine-65;
        }

        if(xInizio==xFine){   //se hanno la stessa ascissa (la corazzata è situata in VERTICALE)
             for(int k=0; k<3; k++){
                cInizio=cInizio+1;
                std::string Pos=cInizio+""+xInizio;
                Griglia.set("S", Pos);
            } 
        }else{
            for(int k=0; k<3; k++){    //se hanno la stessa ordinata (la corazzata è situata in ORIZZONTALE)
                xInizio=xInizio+1;
                std::string Pos=cInizio+""+xInizio;
                Griglia.set("S", Pos);
            }
        }
    }
    
   void azione(std::string obiettivo){

        char o=obiettivo.at(0);
        int XTarget=stoi(obiettivo.substr(1,2))-1;
        int YTarget;
        if(o<74){
            YTarget=o-65;
        }

        if(isvalid(YTarget, XTarget)){

            Griglia.remove(centro);
            
            char c=centro.at(0);
            int XCentro=stoi(centro.substr(1,2))-1;
            int YCentro;
            if(c<74){
                YCentro=c-65;
            }
            
            if((matrix[YCentro][XCentro+1]=="S")||(matrix[YCentro][XCentro+1]=="s")){
                 std::string s1=YCentro+""+(XCentro+1);
                 std::string s1=YCentro+""+(XCentro-1);
                
                 Griglia.remove(s1);
                 Griglia.remove(s2);
            
            }else{
                std::string s1=(c+1)+""+XCentro;
                std::string s1=(c-1)+""+XCentro;
                
                Griglia.remove(s1);
                Griglia.remove(s2);
            }
               
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
