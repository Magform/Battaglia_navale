#include "Corazzata.h"
#include <cstring>
#include <stdexcept>

using namespace std;

string Corazzata::get_centro(){
    return centro;
}

void Corazzata::set(std::string inizio, std::string fine, Griglia& g_difesa){
       
    //converto in coordinate "matrici" la coordinata di inizio
    char cInizio=inizio.at(0);
    int xInizio=stoi(inizio.substr(1,inizio.length()-1));
    int yInizio;
    if((cInizio<65)||(cInizio>78))  throw std::invalid_argument("Carattere non valido");
 
    yInizio=cInizio-65;

    //converto in coordinate "matrici" la coordinata di fine
    char cFine=fine.at(0);
    int xFine=stoi(fine.substr(1,fine.length()-1));
    int yFine;
    if((cFine<65)||(cFine>78))  throw std::invalid_argument("Carattere non valido");
    
    yFine=cFine-65;

    //Metto in ordine le due coordinate
    if((yFine<yInizio)||(xFine<xInizio)){
        char scambioY=cFine;
        cFine=cInizio;
        cInizio=scambioY;

        int scambioX=xFine;
        xFine=xInizio;
        xInizio=scambioX;

        string scambio=inizio;
        inizio=fine;
        fine=scambio;
    }

    //Check per vedere se posso metterla in verticale

    if(xInizio==xFine){
        char cSearch=cInizio;
        for(int k=0; k<5; k++){   

            //Ad ogni ciclo cerco nella posizione Pos e mi sposto in giù
            if(cSearch==74||cSearch==75) cSearch=cSearch+2;
            std::string Pos(1,cSearch);
            Pos=Pos+to_string(xInizio);
            
            if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                cSearch=cSearch+1;
            }else{
                //Se un solo spazio è occupato, lancia una eccezione
                throw std::invalid_argument("Carattere non valido: una o piu' caselle sono gia' occupate.");
            }
        }
            
        //Posizione verticale valida, si inserisce la lettera C nella griglia
        if(cInizio+2=='J'||cInizio+2=='K') {
            centro=cInizio+4;
        }else{
            centro=cInizio+2;
        }
        centro=centro+to_string(xInizio);
        for(int k=0; k<5; k++){   
            if(cInizio==74||cInizio==75) cInizio=cInizio+2;                                    
            std::string Put(1,cInizio);
            Put=Put+to_string(xInizio);

            g_difesa.set("C", Put);
            cInizio=cInizio+1;
        }
        
    }else{
        
        //Check per vedere se posso metterla in orizzontale

        if(yInizio==yFine){
            char cSearch=cInizio;   
            for(int k=0; k<5; k++){      
                if(cSearch==74||cSearch==75) cSearch=cSearch+2;
                std::string Pos(1,cSearch);
                Pos=Pos+to_string(xInizio);

                if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    xInizio=xInizio+1;                       
                }else{
                    //Se un solo spazio è occupato, lancia una eccezione
                    throw std::invalid_argument("Carattere non valido: una o piu' caselle sono gia' occupate."); 
                }
            }

            //Posizione orizzontale valida, si inserisce la lettera C nella griglia
            xInizio=xInizio-5;

            if(cInizio+2=='J'||cInizio+2=='K') {
                centro=cInizio+2;
            }else{
                centro=cInizio;
            }
            centro=centro+to_string(xInizio+2);
                
            for(int k=0; k<5; k++){
                if(cInizio==74||cInizio==75) cInizio=cInizio+2;
                std::string Put(1,cInizio);
                Put=Put+to_string(xInizio);

                g_difesa.set("C", Put);
                xInizio=xInizio+1;
            }
            
        }else{

            //Se non può essere messa nè in orizzontae nè in verticale, da errore
            throw std::invalid_argument("La corazzata puo' essere messa solo in ORIZZONTALE o in VERTICALE! ");
        }
    }
    begin=inizio;
    end=fine;  
}

bool Corazzata::isAlive(Griglia& g_difesa){
    
    if(vita==0) return false;

    int counter=0;
    char cInizio=begin.at(0);
    char cFine=end.at(0);
    int xInizio=stoi(begin.substr(1,begin.length()-1));

    char cSearch=cInizio;
    if(cInizio==cFine){
        //se la corazzata è in orizzontale
        for(int k=0; k<5; k++){
            std::string Search(1,cInizio);
            Search=Search+to_string(xInizio+k);

            if(g_difesa.retrive(Search)=="c") counter++;
        }
    }else{
        //se la corazzata è in verticale
        for(int k=0; k<5; k++){
            if(cInizio+k==74) cSearch=cSearch+2;
            std::string Search(1,cSearch+k);
            Search=Search+to_string(xInizio);

            if(g_difesa.retrive(Search)=="c") counter++;
        }
    }
   
    vita=5-counter;
    if(vita==0){
        //La nave è stata affondata => la elimino dalla griglia di difesa
        if(cInizio==cFine){
            //se la corazzata è in orizzontale
            for(int k=0; k<5; k++){
                std::string to_remove(1,cInizio);
                to_remove=to_remove+to_string(xInizio+k);

                g_difesa.remove(to_remove);
            }
        }else{
            //se la corazzata è in verticale
            for(int k=0; k<5; k++){
                if(cInizio+k==74) cInizio=cInizio+2;
                std::string to_remove(1,cInizio+k);
                to_remove=to_remove+to_string(xInizio);

                g_difesa.remove(to_remove);
            }
        }
    }
    return true;
}

void Corazzata::azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa){
    //Il numero vicino alla g delle griglie rappresenta il giocatore (1 quello che sta compiendo l'azione, 2 quello che subisce l'attacco)
    
    //controllo che la corazzata che deve eseguiere l'azione non sia stata ancora affondata altrimenti lancio un'eccezione
    if(!isAlive(g1_difesa)) throw std::invalid_argument("Carattere non valido: la corazzata che si vuole utilizzare e' stata affondata!");

    //if per vedere se nell'obiettivo c'è una nave non colpita
    if((g2_difesa.retrive(obiettivo)=="C")||(g2_difesa.retrive(obiettivo)=="S")||(g2_difesa.retrive(obiettivo)=="E")){         

        //nave colpita
        string lettera=g2_difesa.retrive(obiettivo);
        char l=lettera[0];
        l=tolower(l);
        string insert(1,l);
        g2_difesa.set(insert, obiettivo);   //metto in minuscolo la lettera nella casella che e' stata colpita

        g1_attacco.set("X", obiettivo);     //Mette un "X" nella posizione data nella griglia di attacco
            
        //Diminuire di 1 la vita della nave colpita
        //Check per vedere se la partita è finita

    }else{
         
        //il colpo è andato a vuoto
        g1_attacco.set("O", obiettivo);     //Mette un "O" nella posizione data nella griglia di attacco
    }
    //Fine azione della corazzata
}
