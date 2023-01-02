#ifndef Sottomarino_H_
#define Sottomarino_H_

class Sottomarino : public Naval_units{
private:
    int vita = 5;
public:
    void set(std::string inizio, std::string fine);
    void azione(std::string obiettivo);
};

#include "../../lib/Naval_units/Sottomarino.hpp"

#endif // Sottomarino_H_

