#include "../../include/Naval_units/Sottomarino.h"

void Sottomarino::set(std::string inizio, std::string fine, Griglia& g_difesa){

    if(inizio!=fine)    throw std::invalid_argument("Carattere non valido");
    
    if(g_difesa.retrive(inizio)==" "){

            g_difesa.set("E", inizio);

    }else{

        throw std::invalid_argument("Carattere non valido");
    }
    centro=inizio;
}


void azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa){
        //Il numero vicino alla g delle griglie rappresenta il giocatore (1 quello che sta compiendo l'azione)
        
       //Controllo se il sottomarino è ancora in vita
        if(!isAlive())  throw std::invalid_argument("Carattere non valido");

        //Guardo se la posizione non è già occupata
        if(g1_difesa.retrive(obiettivo)!=" ")     throw std::invalid_argument("Carattere non valido");
        
        //nuova posizione valida
        //rimuovo vecchia posizione e metto quella nuova
        g1_difesa.remove(centro);
        g1_difesa.set("E", obiettivo);
        centro=obiettivo;  
            
        //Trasformo "obiettivo" in coordinate
        char cTarget=obiettivo.at(0);
        int XTarget=stoi(obiettivo.substr(1,2));
        int YTarget;
        if((cTarget<65)||(cTarget>78))  throw std::invalid_argument("Carattere non valido");
        YTarget=cTarget-65;
       
        
        //inizio radar
        int YSearch=YTarget-3;
        int XSearch; 

        for(int Ycounter=0; Ycounter<5; Ycounter++){
            XSearch=XTarget-3;
            YSearch=YSearch+1;

            for(int Xcounter=0; Xcounter<5; Xcounter++){
                
                XSearch=XSearch+1;

                //Guardo se la posizione dove sto cercando è all'interno della griglia
                if((XSearch>=0)&&(XSearch<12)&&(YSearch>=0)&&(YSearch<12)){  

                    char cY=YSearch+65;
                    if(cY=='J'||cY=='K') cY+=2;
                    
                    std::string Pos(1,cY);
                    Pos=Pos+to_string(XSearch);

                    try{
                        
                        //if per vedere se nella posizione dove stiamo cercando cercando c'è una nave nemica
                        if(g2_difesa.retrive(Pos)!=" "){ 
                            
                            //Nave trovata, metto una Y nella griglia d'attacco
                            g1_attacco.set("Y", Pos);
                        }
                    }catch(const std::invalid_argument ex){}
                }
           }
       //fine del radar           
       }

    //Fine sottomarino        
};
