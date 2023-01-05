#include "../../include/Naval_units/Corazzata.h"
#include "../../lib/Naval_units/Naval_units.hpp"
#include "../../lib/Griglia/Griglia.hpp"

class Corazzata : public Naval_units{
public:
    
    void set(std::string inizio, std::string fine, Griglia g_difesa){
        
        //converto in cordiate "matrici" la coordinata di inizio
        cchar cInizio=inizio.at(0);
        int xInizio=stoi(inizio.substr(1,2))-1;
        int yInizio;
        if((cInizio>64)(cInizio<74)){
            YInizio=cInizio-65;
        }else{
            throw std::invalid_argument("Carattere non valido");
        }
        
        //converto in cordiate "matrici" la coordinata di fine
        char cFine=fine.at(0);
        int xFine=stoi(fine.substr(1,2))-1;
        int yFine;
        if((cFine>64)(cFine<74)){
            YFine=cFine-65;
        }else{
            throw std::invalid_argument("Carattere non valido");
        }
        

        //Check per vedere se posso metterla in verticale

        if(xInizio==xFine){

            for(int k=0; k<5; k++){   
                
                std::string Pos=yInizio+""+xInizio;
                if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    yInizio=yInizio+1;
                    
                }else{
                    //Se un solo spazio è occupato, lancia una eccezione
                    throw std::invalid_argument("Carattere non valido");
                }
            }

            //Posizione orizzontale valida, si inserisce la lettera C nella griglia
            yInizio=yInizio-5;
            begin=inizio;
            end=fine;
            centro=(yInizio+2)+""+xInizio;            
            
            for(int k=0; k<5; k++){   
                
                yInizio=yInizio+1;
                std::string Pos=yInizio+""+xInizio;
                
                g_difesa.set("C", Pos);
                
            } 

        
        }else{

            //Check per vedere se posso metterla in orizzontale

            if(yInizio==yFine){

                for(int k=0; k<5; k++){      
                    
                    std::string Pos=yInizio+""+xInizio;
                    if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                        xInizio=xInizio+1;
                        
                    }else{
                        //Se un solo spazio è occupato, lancia una eccezione
                        throw std::invalid_argument("Carattere non valido");
                    }
                }

                //Posizione verticale valida, si inserisce la lettera C nella griglia
                xInizio=xInizio-5;
                begin=inizio;
                end=fine;
                centro=yInizio+""+(xInizio+2);
                
                for(int k=0; k<5; k++){
                    
                    xInizio=yInizio+1;
                    std::string Pos=xInizio+""+xInizio;

                    g_difesa.set("C", Pos);
                }
            }else{

                //Se non può essere messa nè in orizzontae nè in verticale, da errore
                throw std::invalid_argument("Carattere non valido");

            }
        }
    }
    
    void azione(std::string obiettivo, Griglia g1_difesa, Griglia g1_attacco, Griglia g2_difesa){
        
        //Il numero vicino alla g delle griglie rappresenta il giocatore (1 quello che sta compiendo l'azione,
        //2 quello che subisce l'attacco)
  
        //if per vedere se nell'obiettivo c'è una nave non colpita
        if((g2_difesa.retrive(obiettivo)=="C")||(g2_difesa.retrive(obiettivo)=="S")||(g2_difesa.retrive(obiettivo)=="E")){         

            //nave colpita
            char lettera=g2_difesa.retrive(obiettivo);
            lettera=lettera+32;     //mette in minuscolo
            g2_difesa.set(lettera, obiettivo);

            g1_attacco.set("X", obiettivo);     //Mette un "X" nella posizione data nella griglia di attacco
            
            //Diminuire di 1 la vita della nave colpita
            //Check per vedere se la partita è finita

        }else{
            
            //mancato
            
            g1_attacco.set("O", obiettivo);     //Mette un "O" nella posizione data nella griglia di attacco

        }
        
        //Fine azione della corazzata
    }
};
