#include <string>

#ifndef Griglia_H_
#define Griglia_H_


class Griglia{
protected:
    std::string matrix[12][12];      //matrice che rappresenta la griglia [y][x]
public:
    Griglia();

    //funzioni utili
    void set(std::string toSet, std::string location);        //posiziona la stringa "toSet" nalla posizione "location" 
    void clear();                                   //cancella TUTTA la griglia
    void remove(std::string location);                   //rimuove ciò che c'è nalla posizione "location"
    void remove_all(std::string to_remove);              //Elimina interamente il valore cercato dalla griglia.
    std::string retrive(std::string location);                //restituisce ció che é presente nella posizione "location"

    //overload operatori
    friend std::ostream& operator<<(std::ostream& os, const Griglia to_print);
};


#endif // Griglia_H_
