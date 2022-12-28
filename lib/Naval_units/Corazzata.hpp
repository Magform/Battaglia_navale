#include "../../include/Naval_units/Corazzata.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Corazzata : public NavalUnits{
public:
    
    void set(string inizio, :string fine){

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
            for(int k=0; k<5; k++){
                
                yInizio=yInizio+1;
                std::string Pos=yInizio+""+xInizio;
                Griglia.set("C", Pos);
            } 
        }else{
            for(int k=0; k<5; k++){
                
                xInizio=xInizio+1;
                std::string Pos=yInizio+""+xInizio;

                Griglia.set("C", Pos);
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

        if(matrix[YTarget][XTarget]!=" "){         

            //mettere in lowercase il carattere colpito nella griglia di difesa avversaria
            //Mette un "X" nella posizione data nella griglia di attacco
            //Check per vedere se la partita è finita

        }else{

            //Mette un "O" nella posizione data nella griglia di attacco

        }
    }
};
