
/*

    Autore: Nicolas Ferraresso

*/

#include <string>

#ifndef Griglia_H_
#define Griglia_H_

// Classe che rappresenta una griglia bidimensionale di stringhe.
// Ogni posizione della griglia è rappresentata da una cella contenente una stringa.
// La classe fornisce funzionalità per posizionare, rimuovere e recuperare le stringhe nella griglia.

class Griglia{
protected:
    std::string matrix[12][12];     
public:
    Griglia();

    //funzioni utili
    void set(std::string toSet, std::string location);       
    void clear();                                             
    void remove(std::string location);                        
    void remove_all(std::string to_remove);                   
    std::string retrive(std::string location);                

    //overload operatori
    friend std::ostream& operator<<(std::ostream& os, const Griglia to_print);
};


#endif // Griglia_H_
