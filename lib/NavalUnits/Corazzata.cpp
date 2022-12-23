#include <iostream>
#include "NavalUnits.hpp"

class Corazzata : public NavalUnits{
public:
    void azione(int YTarget, int XTarget){
        if(matrix[YTarget][XTarget]!=" "){         

            //mettere in lowercase il carattere colpito nella griglia di difesa avversaria
            //Mette un "X" nella posizione data nella griglia di attacco
            //Check per vedere se la partita è finita

        }else{

            //Mette un "O" nella posizione data nella griglia di attacco

        }
    }
};