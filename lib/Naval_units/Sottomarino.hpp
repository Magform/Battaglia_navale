#include "../../include/Naval_units/Sottomarino.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Sottomarino : public NavalUnits{
public:
    
    void set(std::string inizio, std::string fine){ 
        
        //Qua non ho capito se inizio e fine sono uguali, 
        //essendo il Sottomarino di lunghezza 1

        if(Griglia.retrive(inizio)==" "){
            Griglia.set("E", inizio);
        }else{
            throw std::invalid_argument("Carattere non valido");
        }

    }
    
   void azione(std::string obiettivo){

        if(Griglia.retrive(obiettivo)==" "){
  
            Griglia.remove(centro);
            Griglia.set("E", obiettivo);
            
            char c=obiettivo.at(0);
            int XTarget=stoi(obiettivo.substr(1,2))-1;
            int YTarget;
            YTarget=c-65;
            
            int YSearch=YTarget-2;
            int XSearch=XTarget-2;
            
            //inizio radar
            for(int k=0; k<5; k++){
                for(int j=0; j<5; j++){
                    if(((YSearch+k)>0)&&((YSearch+k)<12)&&((XSearch+j)>0)&&((XSearch+j)<12))){   //if per vedere se si esce dalla matrice quando si fa la ricerca radar
                        
                        //Controllo se ci sono navi nel punto matrix[YSearch][XSearch]
                        //e in caso metto una Y nella griglia di difesa
                        
                    }
                }
            }
            //fine del radar
            
          }else{

            throw std::invalid_argument("Carattere non valido");

        }
    }
};
