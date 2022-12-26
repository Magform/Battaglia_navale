#include <iostream>
#include "NavalUnits.hpp"

#include <iostream>
#include "NavalUnits.hpp"

class Supporto : public NavalUnits{
public:
    void azione(int YTarget, int XTarget){

        if(isvalid(YTarget, XTarget)){

            //elimino la vecchia posizione della nave di supporto e imposto quella nuova
            //riparazione mettendo in maiuscolo tutte le lettere intorno

            }else{

            //Gestione posizione invalida della nave di supporto

            }
    }

    bool isvalid(int YTarget, int XTarget)}{    //funzione per verificare se la posizione nuova è valida

        if(matrix[YTarget][XTarget]==" "){
            if((matrix[YTarget][XTarget+1]==" ")&&((matrix[YTarget][XTarget-1]==" "))){ 
               
                return true;

                //guardo se, oltre alla posizione data, sono liberi anche gli spazi laterali
            
            }else{
                if((matrix[YTarget+1][XTarget]==" ")&&((matrix[YTarget-1][XTarget]==" "))){ 
                 
                    return true;

                    //guardo se, oltre alla posizione data, sono liberi anche gli spazi sopra e sotto
                }
            }
        }

    return false;
    }
};