#include "../../include/Griglia/Griglia.h"

void Griglia_difesa::setup(){
    std::string inizio,fine;
    std::cout<<"Quali sono le coordinate per la corazzata 1: "
    std::cin>>inizio>>fine;
    corazzata1.set(inizio, fine);
    std::cout<<"Quali sono le coordinate per la corazzata 2: "
    std::cin>>inizio>>fine;
    corazzata2.set(inizio, fine);
    std::cout<<"Quali sono le coordinate per la corazzata 3: "
    std::cin>>inizio>>fine;
    corazzata3.set(inizio, fine);

    std::cout<<"Quali sono le coordinate per la nave di supporto 1: "
    std::cin>>inizio>>fine;
    supporto1.set(inizio, fine);
    std::cout<<"Quali sono le coordinate per la nave di supporto 2: "
    std::cin>>inizio>>fine;
    supporto2.set(inizio, fine);
    std::cout<<"Quali sono le coordinate per la nave di supporto 3: "
    std::cin>>inizio>>fine;
    supporto3.set(inizio, fine);

    std::cout<<"Quali sono le coordinate per il sottomarino 1: "
    std::cin>>inizio>>fine;
    sottomarino1.set(inizio, fine);
    std::cout<<"Quali sono le coordinate per il sottomarino 2: "
    std::cin>>inizio>>fine;
    sottomarino2.set(inizio, fine);
}
