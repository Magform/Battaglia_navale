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
       
        //Controllo se il sottomarino è ancora in vita
        if(!isAlive())  throw std::invalid_argument("Carattere non valido");

        //Guardo se la posizione non è già occupata
        if(Griglia.retrive(obiettivo)!=" ")     throw std::invalid_argument("Carattere non valido");
  
        //rimuovo vecchia posizione e metto quella nuova
        Griglia.remove(centro);
        Griglia.set("E", obiettivo);
            
        //Trasformo "obiettivo" in coordinate
        char o=obiettivo.at(0);
        int XTarget=stoi(obiettivo.substr(1,2))-1;
        int YTarget;
        if((o>64)(o<74)){
            YTarget=o-65;
        }else{
             throw std::invalid_argument("Carattere non valido");
        }
            
            
        //inizio radar
        YTarget=YTarget-2;
        XTarget=XTarget-2;
        int YSearch, XSearch;
            
        for(int Ycounter=0; Ycounter<5; Ycounter++){
            YSearch=YTarget+Ycounter;

            for(int Xcounter=0; Xcounter<5; Xcounter++){
                
                XSearch=YTarget+Ycounter;

                //Guardo se la posizione dove sto cercando è all'interno della griglia
                if((XSearch>0)&&(XSearch<12)&&(YSearch>0)&&(YSearch<12)){  

                    std::string Pos=YSearch+""+XSearch;
                    if(Griglia.retrive(Pos)!=" "){  //Qua bisognerebbe guardare nella griglia di difesa dell'avversario
                            
                           //Mette una Y nella posizione "Pos" della propria griglia d'attacco
                        
                    }
                }
           }
       }
       
       //fine del radar
            
    }
};
