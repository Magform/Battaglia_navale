#include "../../include/Naval_units/Supporto.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Supporto : public Naval_units{
public:
    
    void set(string inizio, :string fine, Griglia g_difesa){

        //converto in cordiate "matrici" la coordinata di inizio
        char cInizio=inizio.at(0);
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
            
             for(int k=0; k<3; k++){            
                std::string Pos=yInizio+""+xInizio;
                if(g_difesa.retrive(Pos)==" "){      //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    yInizio=yInizio+1;            
                }else{                 
                    throw std::invalid_argument("Carattere non valido");
                }
                
            }

            //Posizione verticale valida, si inserisce la lettera S nella griglia
            yInizio=yInizio-3;
            begin=inizio;
            end=fine;
            centro=(yInizio+1)+""+xInizio;
            
            for(int k=0; k<3; k++){   
                
                yInizio=yInizio+1;
                std::string Pos=yInizio+""+xInizio;
                g_difesa.set("C", Pos);
                
            } 
            
        }else{

            //Check per vedere se posso metterla in orizzontale

            if(yInizio==yFine){

                for(int k=0; k<3; k++){      
                    std::string Pos=yInizio+""+xInizio;
                    if(g_difesa.retrive(Pos)==" "){      //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                        xInizio=xInizio+1;
                    }else{
                        throw std::invalid_argument("Carattere non valido");
                    }
                    
                }

                //Posizione orizzontale valida, si inserisce la lettera S nella griglia
                xInizio=xInizio-3;
                begin=inizio;
                end=fine;
                centro=yInizio+""+(xInizio+1);
                
                for(int k=0; k<3; k++){
                    
                    xInizio=xInizio+1;
                    std::string Pos=yInizio+""+xInizio;

                    g_difesa.set("C", Pos);
                }
            }else{

                //Se non può essere messa nè in orizzontae nè in verticale, da errore
                throw std::invalid_argument("Carattere non valido");

            }
        }
    }
    
    void azione(std::string obiettivo, Griglia g1_difesa, Griglia g1_attacco, Griglia g2_difesa){
  
       //Controllo se la nave di supporto è ancora in vita
        if(!isAlive()) throw std::invalid_argument("Carattere non valido");
       
       //Ottengo le coordinate dell'obiettivo
        char cO=obiettivo.at(0);
        int XTarget=stoi(obiettivo.substr(1,2))-1;
        int YTarget;
        if((cO>64)(cO<74)){
            YTarget=cO-65;
        }else{
            throw std::invalid_argument("Carattere non valido");
        }

        //Ottengo le coordinate x dell'inizio e fine della vecchia posizione, per vedere se la nave è in orizzontale o verticale
        int XInizio=stoi(begin.substr(1,2))-1;
        int XFine=stoi(end.substr(1,2))-1;
        
        //inizio spostamento, controllando prima se la nave è in orizzontale o in verticale
        if(xInizio==xFine){
            
            //E' in verticale

            //Prendo le posizioni sopra e sotto all'obiettivo, per vedere se posso metterla in verticale
            std::string sopra=(YTarget-1)+""+XTarget;
            std::string sotto=(YTarget+1)+""+XTarget;

            //if per vedere se le nuove posizioni sono vuote, lancia una eccezione se non lo sono o se si esce dalla griglia
            if(!((g1_difesa.retrive(obiettivo==" "))&&(g1_difesa.retrive(sopra==" "))&&(g1_difesa.retrive(sotto==" ")))){
                throw std::invalid_argument("Carattere non valido");
            }

            //Posizione valida, rimuovo la vecchia posizione
            g1_difesa.remove(begin);
            g1_difesa.remove(centro);
            g1_difesa.remove(end)

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
            std::string sinistra=YTarget+""+(XTarget-1);
            std::string destra=YTarget+""+(XTarget+1);

            //if per vedere se le nuove posizioni sono vuote, lancia una eccezione se non lo sono o se si esce dalla griglia
            if(!((g1_difesa.retrive(obiettivo==" "))&&(g1_difesa.retrive(sinistra==" "))&&(g1_difesa.retrive(destra==" ")))){
                throw std::invalid_argument("Carattere non valido");
            }

            //Posizione valida, rimuovo la vecchia posizione
            g1_difesa.remove(begin);
            g1_difesa.remove(centro);
            g1_difesa.remove(end)

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
        char cI=begin.at(0);
        int XInizio=stoi(begin.substr(1,2))-1;
        int YInizio;
        if((cI>64)(cI<74)){
            YInizio=cI-65;
        }else{
            throw std::invalid_argument("Carattere non valido");
        }

        char cF=end.at(0);
        int XFine=stoi(end.substr(1,2))-1;
        int YFine;
        if((cF64)(cF<74)){
            YFine=cF-65;
        }else{
            throw std::invalid_argument("Carattere non valido");
        }

        if(XInizio==XFine){
            
            //Essendo in verticale, devo considerare solo le due colonne a lato della nave

            //Riparazione colonna a sinistra nella nave
            int YRepair=YInizio-1;
            for(int k=0; k<3; k++){
                std::string Repair=(YRepair+k)+""+(XInizio-1);

                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){
                    char c=g1_difesa.retrive(Repair);
                    c=c-32;     //Metto in maiuscolo
                    g1_difesa.set(c, Repair);
                }
                
                //Fine controlli di riparazione colonna a sinistra nella nave
            }

            //Riparazione colonna a destra nella nave
            YRepair=YInizio-1;
            for(int k=0; k<3; k++){
                std::string Repair=(YRepair+k)+""+(XInizio+1);

                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){
                    char c=g1_difesa.retrive(Repair);
                    c=c-32;     //Metto in maiuscolo
                    g1_difesa.set(c, Repair);
                }
                
                //Fine controlli di riparazione colonna a destra nella nave
            }
            
        }else{
            
            //Essendo in orizzontale, devo considerare solo le due righe sopra e sotto della nave

            //Riparazione riga superiore
            int XRepair=XInizio-1;
            for(int k=0; k<3; k++){
                std::string Repair=(YRepair-1)+""+(XInizio+k);

                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){
                    char c=g1_difesa.retrive(Repair);
                    c=c-32;     //Metto in maiuscolo
                    g1_difesa.set(c, Repair);
                }
                
                //Fine controlli di riparazione nella riga superiore alla nave
            }

            //Riparazione riga inferiore
            XRepair=XInizio-1;
            for(int k=0; k<3; k++){
                std::string Repair=(YRepair+1)+""+(XInizio+k);

                //if per vedere se nella posizione di ricerca c'è una lettera minuscola
                if((g1_difesa.retrive(Repair)=="c")||(g1_difesa.retrive(Repair)=="s")){
                    char c=g1_difesa.retrive(Repair);
                    c=c-32;     //Metto in maiuscolo
                    g1_difesa.set(c, Repair);
                }
                
                //Fine controlli di riparazione riga inferiore alla nave

                //Fine riparazione
        }
    //Fine dell'azione della nave di supporto 
    
    }
};
