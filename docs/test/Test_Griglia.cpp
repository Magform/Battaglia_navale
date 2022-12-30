#include <string>
#include <iostream>
#include <stdexcept>

#include "../../include/Griglia/Griglia.h"

using namespace std;

int main(){
    Griglia test;
    cout<<test<<"\n";
    cout<<"Inserisco 'A' nella casella B3:"<<endl;
    test.set("A", "B3");
    cout<<test<<"\n";
    cout<<"Cerco il valore all'interno della casella B3: ";
    cout<<test.retrive("B3")<<endl;
    cout<<"\nRimuovo il valore all'interno della casella B3:"<<endl;
    test.remove("B3");
    cout<<test;
}
