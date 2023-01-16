#include "Supporto.h"
#include <cstring>
#include <stdexcept>
#include <string>

using namespace std;

string Supporto::get_centro(){
    return centro;
}

void Supporto::set(std::string inizio, std::string fine,Griglia& g_difesa){
       
    //converto in cordiate "matrici" la coordinata di inizio
    char cInizio=inizio.at(0);
    int xInizio=stoi(inizio.substr(1,inizio.length()-1));
    int yInizio;
    if((cInizio<65)||(cInizio>78))  throw std::invalid_argument("Carattere non valido");
   
    yInizio=cInizio-65;
    
        
    //converto in cordiate "matrici" la coordinata di fine
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
    }

    //Check per vedere se posso metterla in verticale

    if(xInizio==xFine){
        char cSearch=cInizio;
        for(int k=0; k<3; k++){   

            //Ad ogni ciclo cerco nella posizione Pos e mi sposto in giù
            if(cSearch==74||cSearch==75) cSearch=cSearch+2;
            std::string Pos(1,cSearch);
            Pos=Pos+to_string(xInizio);
            if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                cSearch=cSearch+1;
                    
            }else{
                //Se un solo spazio è occupato, lancia una eccezione
                throw std::invalid_argument("Carattere non valido");
            }
        }
            
        //Posizione verticale valida, si inserisce la lettera C nella griglia
        

        if(cInizio+1=='J'||cInizio+1=='K') {
            centro=cInizio+3;
        }else{
            centro=cInizio+1;
        }
        centro=centro+to_string(xInizio);
                    
            
        for(int k=0; k<3; k++){   
            if(cInizio==74||cInizio==75) cInizio=cInizio+2;                                   
            std::string Put(1,cInizio);
            Put=Put+to_string(xInizio);

            g_difesa.set("S", Put);
            cInizio=cInizio+1;

        } 
        
    }else{

        //Check per vedere se posso metterla in orizzontale

        if(yInizio==yFine){
            char cSearch=cInizio;  
            for(int k=0; k<3; k++){   
                if(cSearch==74||cSearch==75) cSearch=cSearch+2;   
                std::string Pos(1,cSearch);
                Pos=Pos+to_string(xInizio);

                if(g_difesa.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    xInizio=xInizio+1;                      
                }else{
                    //Se un solo spazio è occupato, lancia una eccezione

                    throw std::invalid_argument("Carattere non valido");
                }
            }

            //Posizione orizzontale valida, si inserisce la lettera C nella griglia
            xInizio=xInizio-3;
        
            if(cInizio=='J'||cInizio=='K') {
                centro=cInizio+2;
            }else{
                centro=cInizio;
            }
            centro=centro+to_string(xInizio+1);
                
            for(int k=0; k<3; k++){
                if(cInizio==74||cInizio==75) cInizio=cInizio+2;    
                std::string Put(1,cInizio);
                Put=Put+to_string(xInizio);

                g_difesa.set("S", Put);
                xInizio=xInizio+1;

            }
        }else{

            //Se non può essere messa nè in orizzontae nè in verticale, da errore
            throw std::invalid_argument("Carattere non valido");

        }
    }
    begin=inizio;
    end=fine;    
    
}

bool Supporto::isAlive(){ return vita!=0;}
    
void Supporto::azione(std::string obiettivo, Griglia& g1_difesa, Griglia& g1_attacco, Griglia& g2_difesa){

    //Controllo se la nave di supporto è ancora in vita
    if(!isAlive()) throw std::invalid_argument("Carattere non valido");
   
    //Ottengo le coordinate dell'obiettivo
    char cTarget=obiettivo.at(0);
    int XTarget=stoi(obiettivo.substr(1,obiettivo.length()-1));
    int YTarget;
    if((cTarget<65)||(cTarget>78))  throw std::invalid_argument("Carattere non valido");
    
    YTarget=cTarget-65;
    

    //Ottengo le coordinate x dell'inizio e fine della vecchia posizione, per vedere se la nave è in orizzontale o verticale
    int xInizio=stoi(begin.substr(1,begin.length()-1));
    int xFine=stoi(end.substr(1,end.length()-1));
      
    //inizio spostamento, controllando prima se la nave è in orizzontale o in verticale
    if(xInizio==xFine){
           
        //E' in verticale

        //Prendo le posizioni sopra e sotto all'obiettivo, per vedere se posso metterla in verticale
        std::string sopra, sotto;
        if(cTarget-1=='J'||cTarget-1=='K'){
            sopra=cTarget-3;
        }else{
            sopra=cTarget-1;
        }
        sopra=sopra+to_string(XTarget);

        if(cTarget+1=='J'||cTarget+1=='K'){
            sotto=cTarget+3;
        }else{
            sotto=cTarget+1;
        }
        sotto=sotto+to_string(XTarget);

        //if per vedere se le nuove posizioni sono vuote, lancia una eccezione se non lo sono o se si esce dalla griglia
        if(!((g1_difesa.retrive(obiettivo)==" ")||(g1_difesa.retrive(sopra)==" ")||(g1_difesa.retrive(sotto)==" "))){
            throw std::invalid_argument("Carattere non valido");
        }

        //Posizione valida, rimuovo la vecchia posizione
        g1_difesa.remove(begin);
        g1_difesa.remove(centro);
        g1_difesa.remove(end);

        //E metto quella nuova
        begin=sopra;
        end=sotto;
        centro=obiettivo;

        g1_difesa.set("S", begin);
        g1_difesa.set("S", centro);
        g1_difesa.set("S", end);

    }else{

        //E' in orizzontale (essendo che non è in verticale)

        //Controllo che gli spazi siano vuoti
        std::string sinistra(1,cTarget);
        sinistra=sinistra+to_string(XTarget-1);

        std::string destra(1,cTarget);
        destra=destra+to_string(XTarget+1);

        //if per vedere se le nuove posizioni sono vuote, lancia una eccezione se non lo sono o se si esce dalla griglia
        if(!((g1_difesa.retrive(obiettivo)==" ")||(g1_difesa.retrive(sinistra)==" ")||(g1_difesa.retrive(destra)==" "))){
            throw std::invalid_argument("Carattere non valido");
        }

        //Posizione valida, rimuovo la vecchia posizione
        g1_difesa.remove(begin);
        g1_difesa.remove(centro);
        g1_difesa.remove(end);

        //E metto quella nuova
        begin=sinistra;
        end=destra;
        centro=obiettivo;

        g1_difesa.set("S", begin);
        g1_difesa.set("S", centro);
        g1_difesa.set("S", end);

    }

    //Fine spostamento nave

    //Inizio riparazioni

    //Nuove coordinate x di begin e end
    char cInizio=begin.at(0);
    int XInizio=stoi(begin.substr(1,begin.length()-1));
    int YInizio;
    if((cInizio<65)||(cInizio>78))  throw std::invalid_argument("Carattere non valido");
    
    YInizio=cInizio-65;
    
    char cFine=end.at(0);
    int XFine=stoi(end.substr(1,end.length()-1));
    int YFine;
    if((cFine<65)||(cFine>78))  throw std::invalid_argument("Carattere non valido");
    
        YFine=cFine-65;
    

    if(YInizio==YFine){
     
        //Essendo in orizzontale, devo considerare solo le due righe sopra e sotto della nave

        //Riparazione riga superiore
        char cRepair;
        if(cInizio-1=='J'||cInizio-1=='K'){
            cRepair=cInizio-3;
        }else{
            cRepair=cInizio-1;
        }
        int XRepair=XInizio;
        for(int k=0; k<3; k++){
            if((cRepair>64)&&(cRepair<79)&&(XRepair+k>=0)&&(XRepair+k<12)){

                std::string Repair(1,cRepair);
                Repair=Repair+to_string(XRepair+k);
                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){

                    //Prendo la lettera e la metto maiuscola
                    string lettera=g1_difesa.retrive(Repair);
                    char l=lettera[0];
                    l=toupper(l);
                    string insert(1,l);

                    //E la inserisco
                    g1_difesa.set(insert, Repair);

                }
            }    
            //Fine controlli di riparazione nella riga superiore alla nave
        }

        //Riparazione riga inferiore
        if(cInizio+1=='J'||cInizio+1=='K'){
            cRepair=cInizio+3;
        }else{
            cRepair=cInizio+1;
        }
        XRepair=XInizio;
        for(int k=0; k<3; k++){

            if((cRepair>64)&&(cRepair<79)&&(XRepair+k>=0)&&(XRepair+k<12)){

                std::string Repair(1,cRepair);
                Repair=Repair+to_string(XRepair+k);

                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){

                    //Prendo la lettera e la metto maiuscola
                    string lettera=g1_difesa.retrive(Repair);
                    char l=lettera[0];
                    l=toupper(l);
                    string insert(1,l);

                    //E la inserisco
                    g1_difesa.set(insert, Repair);

                }
            }    
            //Fine controlli di riparazione riga inferiore alla nave
        }
            
    }else{

        //Essendo in verticale, devo considerare solo le due colonne a lato della nave           

        //Riparazione colonna a sinistra nella nave
        int XRepair=XInizio-1;
        char cRepair=cInizio;
        for(int k=0; k<3; k++){

            if((cRepair+k>64)&&(cRepair+k<79)&&(XRepair>=0)&&(XRepair<12)){

                std::string Repair;
                if(cRepair+k=='J'||cRepair=='K'){
                    Repair=cRepair+k+2;
                }else{
                    Repair=cRepair+k;
                }
                Repair=Repair+to_string(XRepair);
                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){

                    //Prendo la lettera e la metto maiuscola
                    string lettera=g1_difesa.retrive(Repair);
                    char l=lettera[0];
                    l=toupper(l);
                    string insert(1,l);

                    //E la inserisco
                    g1_difesa.set(insert, Repair);

                }
            }
            //Fine controlli di riparazione colonna a sinistra nella nave                            
        }

        //Riparazione colonna a destra nella nave
        XRepair=XInizio+1;
        cRepair=cInizio;
        for(int k=0; k<3; k++){

            if((cRepair+k>64)&&(cRepair+k<79)&&(XRepair>=0)&&(XRepair<12)){

                std::string Repair;
                if(cRepair+k=='J'||cRepair=='K'){
                    Repair=cRepair+k+2;
                }else{
                    Repair=cRepair+k;
                }
                Repair=Repair+to_string(XRepair);

                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){
              
                    //Prendo la lettera e la metto maiuscola
                    string lettera=g1_difesa.retrive(Repair);
                    char l=lettera[0];
                    l=toupper(l);
                    string insert(1,l);

                    //E la inserisco
                    g1_difesa.set(insert, Repair);

                }

            }
        }
        //Fine controlli di riparazione colonna a destra nella nave                

        //Fine riparazione
    }
    //Fine dell'azione della nave di supporto 
};

    

    
