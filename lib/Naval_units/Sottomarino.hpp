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
    
   void azione(std::string obiettivo, Griglia g1_difesa, Griglia g1_attacco, Griglia g2_difesa){
        //Il numero vicino alla g delle griglie rappresenta il giocatore (1 quello che sta compiendo l'azione)
        
       //Controllo se il sottomarino è ancora in vita
        if(!isAlive())  throw std::invalid_argument("Carattere non valido");

        //Guardo se la posizione non è già occupata
        if(g1_difesa.retrive(obiettivo)!=" ")     throw std::invalid_argument("Carattere non valido");
  
        //rimuovo vecchia posizione e metto quella nuova
        g1_difesa.remove(centro);
        g1_difesa.set("E", obiettivo);
            
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
                    if(g2_difesa.retrive(Pos)!=" "){    //guardo nella griglia di difesa dell'avversario, se trovo qualcosa...
                        g1_attacco.set("Y", Pos);	//...metto una Y nella posizione "Pos" nella mia griglia di attacco
                    }
                }
           }
       }
       
       //fine del radar
            
    }
};
