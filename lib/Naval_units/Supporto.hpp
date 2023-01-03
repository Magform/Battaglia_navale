#include "../../include/Naval_units/Supporto.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Supporto : public Naval_units{
public:
    
    void set(std::string inizio, std::string fine){

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
            bool isValid=true;
            for(int k=0; k<3; k++){      
                std::string Pos=yInizio+""+xInizio;
                if(Griglia.retrive(Pos)==" "){      //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    yInizio=yInizio+1;
                }else{
                    throw std::invalid_argument("Carattere non valido");
                }
            }

            //Posizione valida, si inserisce la lettera S nella griglia
            yInizio=yInizio-3;
            for(int k=0; k<3; k++){   
                yInizio=yInizio+1;
                std::string Pos=yInizio+""+xInizio;
                Griglia.set("C", Pos);
            } 

        
        }else{

            //Check per vedere se posso metterla in orizzontale

            if(yInizio==yFine){
                bool isValid=true;
                for(int k=0; k<3; k++){      
                    std::string Pos=yInizio+""+xInizio;
                    if(Griglia.retrive(Pos)==" "){      //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                        xInizio=xInizio+1;
                    }else{
                        throw std::invalid_argument("Carattere non valido");
                    }
                }

                //Posizione valida, si inserisce la lettera S nella griglia
                xInizio=xInizio-3;
                for(int k=0; k<3; k++){
                    
                    xInizio=xInizio+1;
                    std::string Pos=yInizio+""+xInizio;

                    Griglia.set("C", Pos);
                }
            }else{

                //Se non può essere messa nè in orizzontae nè in verticale, da errore
                throw std::invalid_argument("Carattere non valido");

            }
        }
    }
    
   void azione(std::string obiettivo){
       
       //Controllo se la nave di supporto è ancora in vita
        if(!isAlive()) throw std::invalid_argument("Carattere non valido");
       
       //Guardo se la nuova posizione è già occupata
        if(!isvalid(YTarget, XTarget))      throw std::invalid_argument("Carattere non valido");
       
       //Inizio rimozione nave nella vecchia posizione
        Griglia.remove(centro);
            
        char c=centro.at(0);
        int XCentro=stoi(centro.substr(1,2))-1;
        int YCentro;
        if((c>64)(c<74)){
            YCentro=c-65;
        }else{
            throw std::invalid_argument("Carattere non valido");
        }
            
        if((matrix[YCentro][XCentro+1]=="S")||(matrix[YCentro][XCentro+1]=="s")){
           std::string s1=YCentro+""+(XCentro+1);
           std::string s1=YCentro+""+(XCentro-1);
                
           Griglia.remove(s1);
           Griglia.remove(s2);
            
         }else{
           std::string s1=(c+1)+""+XCentro;
           std::string s1=(c-1)+""+XCentro;
                
           Griglia.remove(s1);
           Griglia.remove(s2);
         }
       //Fine rimozione
       
       //Inizio riparazione
       char o=obiettivo.at(0);
       int XTarget=stoi(obiettivo.substr(1,2))-1;
       int YTarget;
       if((o>64)(o<74)){
           YTarget=o-65;
       }else{
            throw std::invalid_argument("Carattere non valido");
       }
        
       
       
               
            
    }

    bool isvalid(int YTarget, int XTarget)}{    //funzione per verificare se la posizione nuova è valida

        if(matrix[YTarget][XTarget]==" "){
            if((matrix[YTarget][XTarget+1]==" ")&&((matrix[YTarget][XTarget-1]==" "))){ 
               
                //Qui guardo se, oltre alla posizione data, sono liberi anche gli spazi laterali
                return true;

            }else{
                
                if((matrix[YTarget+1][XTarget]==" ")&&((matrix[YTarget-1][XTarget]==" "))){ 
                    
                    //Qui guardo se, oltre alla posizione data, sono liberi anche gli spazi sopra e sotto
                    return true;

                    
                }
            }
        }
    //Se non può essere messa nè in orizzontale nè in verticale, la funzione restituisce falso
    return false;
    
    }
};
