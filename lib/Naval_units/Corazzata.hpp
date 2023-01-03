#include "../../include/Naval_units/Corazzata.h"
#include "../../lib/Naval_units/Naval_units.hpp"

class Corazzata : public Naval_units{
public:
    
    void set(std::string inizio, std::string fine){
        
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
            bool isValid=true;
            for(int k=0; k<5; k++){      
                std::string Pos=yInizio+""+xInizio;
                if(Griglia.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                    yInizio=yInizio+1;
                }else{
                    //Se un solo spazio è occupato, lancia una eccezione
                    throw std::invalid_argument("Carattere non valido");
                }
            }

            //Posizione orizzontale valida, si inserisce la lettera C nella griglia
            yInizio=yInizio-5;
            for(int k=0; k<5; k++){   
                yInizio=yInizio+1;
                std::string Pos=yInizio+""+xInizio;
                Griglia.set("C", Pos);
            } 

        
        }else{

            //Check per vedere se posso metterla in orizzontale

            if(yInizio==yFine){
                bool isValid=true;
                for(int k=0; k<5; k++){      
                    std::string Pos=yInizio+""+xInizio;
                    if(Griglia.retrive(Pos)==" "){    //Se va fuori dalla griglia lancia l'eccezione da Griglia.hpp
                        xInizio=xInizio+1;
                    }else{
                        //Se un solo spazio è occupato, lancia una eccezione
                        throw std::invalid_argument("Carattere non valido");
                    }
                }

                //Posizione verticale valida, si inserisce la lettera C nella griglia
                xInizio=xInizio-5;
                for(int k=0; k<5; k++){
                    
                    xInizio=yInizio+1;
                    std::string Pos=xInizio+""+xInizio;

                    Griglia.set("C", Pos);
                }
            }else{

                //Se non può essere messa nè in orizzontae nè in verticale, da errore
                throw std::invalid_argument("Carattere non valido");

            }
        }
    }
        //Sono Nicolas, ho buttato un occhi e cosi ho paura che non riesca a trovarti la griglia, volendo potresti aggiungere un terzo parametro ossia la griglia cosi che possiamo sceglierla.
        //Ti chiedo inoltre se riesci a fare in modo che se si prova a creare una barca dove ve ne é gia un altro oppure fuoria dalla griglia non crea nessuna casella ma lancia un eccezzione cosi poi la vado a cattuare per fare in modo che i bot impostino le navi in modo casuale.
        //PS. sarebbe in tutte le Naval_units da fare
    }
    
    void azione(std::string obiettivo){
        
        //Controllo se la corazzata è ancora in vita
        if(!isAlive()) throw std::invalid_argument("Carattere non valido");

        if(Griglia.retrive(obiettivo)!=" "){         

            char character=Griglia.retrive(obiettivo);
            character=character+32;                       //Metto in minuscolo il carattere colpito
            Griglia.set(character, obiettivo);
                
            //Mette un "X" nella posizione data nella griglia di attacco 
            //(Non so in che griglia di difesa metterla)
            
            //Diminuire di 1 la vita della nave colpita
            
            //Check per vedere se la partita è finita

        }else{

            //Mette un "O" nella posizione data nella griglia di attacco
            //(Non so in che griglia di difesa metterla)

        }

        //Sono Nicolas, ti chiedo se riesci a fare in modo che controlli, prima di attaccare che la barca sia viva, se non é cosi lancia un eccezione che poi catturo io.
    }
};
