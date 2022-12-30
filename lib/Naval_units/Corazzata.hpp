#include "../../include/Naval_units/Corazzata.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Corazzata : public Naval_units{
public:
    
    void set(std::string inizio, std::string fine){
        
        //converto in cordiate "matrici" la coordinata di inizio
        char cInizio=inizio.at(0);
        int xInizio=stoi(inizio.substr(1,2))-1;
        int yInizio;
        if(cInizio<76){
            yInizio=cInizio-65;
        }
        
        //converto in cordiate "matrici" la coordinata di fine
        char cFine=fine.at(0);
        int xFine=stoi(fine.substr(1,2))-1;
        int yFine;
        if(cFine<76){
            yFine=cFine-65;
        }
        

        if(xInizio==xFine){   //se hanno la stessa ascissa (la corazzata è situata in VERTICALE)
             for(int k=0; k<5; k++){
                cInizio=cInizio+1;
                std::string Pos=cInizio+""+xInizio;
                Griglia.set("C", Pos);
            } 
        }else{
            for(int k=0; k<5; k++){    //se hanno la stessa ordinata (la corazzata è situata in ORIZZONTALE)
                xInizio=xInizio+1;
                std::string Pos=cInizio+""+xInizio;
                Griglia.set("C", Pos);
            }
        }
    }
    
    void azione(std::string centro, std::string obiettivo){

        if(Griglia.retrive(obiettivo)!=" "){         

            char character=Griglia.retrive(obiettivo);
            character=character+32;                       //Metto in minuscolo il carattere colpito
            Griglia.set(character, obiettivo);
                
            //Mette un "X" nella posizione data nella griglia di attacco 
            //(Non so in che griglia di difesa metterla)
            
            //Check per vedere se la partita è finita

        }else{

            //Mette un "O" nella posizione data nella griglia di attacco
            //(Non so in che griglia di difesa metterla)

        }
    }
};
