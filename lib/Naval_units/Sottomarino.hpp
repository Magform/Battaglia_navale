#include "../../include/Naval_units/Sottomarino.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Sottomarino : public NavalUnits{
public:
    
    void set(std::string inizio, std::string fine){ 
        
        //Qua non ho capito se inizio e fine sono uguali, 
        //essendo il Sottomarino di lunghezza 1

        char c=inizio.at(0);
        int xPos=stoi(inizio.substr(1,2))-1;
        int yPos;
        if(c<74){
            yPos=c-65;
        }else{
            yPos=c-67;
        }

        if(matrix[yPos][xPos]==" "){
            Griglia.set("E", inizio);
        }else{
            throw std::invalid_argument("Carattere non valido");
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
       
        if(matrix[YTarget][XTarget]==" "){
            PosValid=true;

            Griglia.remove(centro);
            std::string Pos=Ytarget+""+XTarget;
            Griglia.set("E", Pos);

            //radar

        }else{

            throw std::invalid_argument("Carattere non valido");

        }
    }
};
