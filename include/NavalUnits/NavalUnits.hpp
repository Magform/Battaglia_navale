#include <iostream>
#include <string>
#include "Griglia.hpp"

class NavalUnits{
public:
    
    virtual void azione(int YTarget, int XTarget);

    int YTarget, XTarget;
    
};
