#ifndef Griglia_H_
#define Griglia_H_

class Griglia{
private:
    std::string matrix[12][12]; //matrice che rappresenta la griglia [y][x]
public:
    Griglia();

    //funzioni utili
    void set(std::string toSet, std::string location);

    //overload operatori
    friend std::ostream& operator<<(std::ostream& os, const Griglia to_print);
}

#endif // Griglia_H_
