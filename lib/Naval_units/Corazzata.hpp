#include "../../include/Naval_units/Corazzata.h"
#include "../../lib/Naval_units/Naval_units.hpp"

void Corazzata::set(std::string inizio, std::string fine, Griglia& g_difesa){
       
    //converto in cordiate "matrici" la coordinata di inizio
    char cInizio=inizio.at(0);
    int xInizio=stoi(inizio.substr(1,2));
    int yInizio;
    if((cInizio<64)||(cInizio>78))  throw std::invalid_argument("Carattere non valido");
    if(cInizio<74){
        yInizio=cInizio-65;
    }else{
         yInizio=cInizio-67;
    }
        
        
    //converto in cordiate "matrici" la coordinata di fine
    char cFine=fine.at(0);
    int xFine=stoi(fine.substr(1,2));
    int yFine;
    if((cFine<64)||(cFine>78))  throw std::invalid_argument("Carattere non valido");
    if(cFine<74){
        yFine=cFine-65;
    }else{
         yFine=cFine-67;
    }
             
    //Check per vedere se posso metterla in verticale

    if(xInizio==xFine){

        for(int k=0; k<5; k++){   

            //Ad ogni ciclo cerco nella posizione Pos e mi sposto in giù
            std::string Pos(1,cInizio);
            Pos=Pos+to_string(xInizio);

            if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                cInizio=cInizio+1;
                    
            }else{
                //Se un solo spazio è occupato, lancia una eccezione
                throw std::invalid_argument("Carattere non valido");
            }
        }
            
        //Posizione overticale valida, si inserisce la lettera C nella griglia
        cInizio=cInizio-5;
           
        centro+=cInizio+2;
        centro=centro+to_string(xInizio);
            
        //for per inserire la corazzata in orizzontale nella griglia          
        for(int k=0; k<5; k++){   
                                                
            std::string Put(1,cInizio);
            Put=Put+to_string(xInizio);

            g_difesa.set("C", Put);
            cInizio=cInizio+1;

        } 

        
    }else{

        //Check per vedere se posso metterla in orizzontale

        if(yInizio==yFine){
                
            for(int k=0; k<5; k++){      
                std::string Pos(1,cInizio);
                Pos=Pos+to_string(xInizio);

                if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    xInizio=xInizio+1;                       
                }else{
                    //Se un solo spazio è occupato, lancia una eccezione
                    throw std::invalid_argument("Carattere non valido");
                }
            }

            //Posizione orizzontale valida, si inserisce la lettera C nella griglia
            xInizio=xInizio-5;
               
            centro+=cInizio;
            centro=centro+to_string(xInizio+2);
            
            //for per inserire la corazzata in orizzontale nella griglia
            for(int k=0; k<5; k++){

                std::string Put(1,cInizio);
                Put=Put+to_string(xInizio);

                g_difesa.set("C", Put);
                xInizio=xInizio+1;

            }
        }else{

            //Se non può essere messa nè in orizzontae nè in verticale, da errore
            throw std::invalid_argument("Carattere non valido");

        }
    }
       
    //Imposto le variabili della nave
    begin=inizio;
    end=fine;    
        
}
    
    void Corazzata::azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa){
        
    //Il numero vicino alla g delle griglie rappresenta il giocatore (1 quello che sta compiendo l'azione,
    //2 quello che subisce l'attacco)
  
    //if per vedere se nell'obiettivo c'è una nave non colpita
    if((g2_difesa.retrive(obiettivo)=="C")||(g2_difesa.retrive(obiettivo)=="S")||(g2_difesa.retrive(obiettivo)=="E")){         

        //nave colpita
        string l=g2_difesa.retrive(obiettivo);
        char lettera=l[0];
        lettera=lettera+32;     //mette in minuscolo
        string insert(1,lettera);
        g2_difesa.set(insert, obiettivo);

        g1_attacco.set("X", obiettivo);     //Mette un "X" nella posizione data nella griglia di attacco
            
        //Diminuire di 1 la vita della nave colpita
        //Check per vedere se la partita è finita

    }else{
            
        //mancato
            
        g1_attacco.set("O", obiettivo);     //Mette un "O" nella posizione data nella griglia di attacco

    }
        
        //Fine azione della corazzata
};
