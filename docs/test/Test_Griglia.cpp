#include <string>
#include <iostream>
#include <stdexcept>

#include "../../include/Griglia/Griglia.h"

using namespace std;

int main(){
    Griglia test;
    cout<<test<<"\n";
    cout<<"Inserisco 'A' nella casella B3:"<<endl;
    try{
    test.set("A", "B3");
    }catch(const exception& ex){
    cout<<"Errore \n";
    }
    cout << test << "\n";
    cout << "Inserisco 'A' nella casella J3:" << endl;
    try{
    test.set("A", "J3");
    }catch(const exception& ex){
    cout<<"Errore \n";
    }
    cout<<test<<"\n";
    cout << "Inserisco 'A' nella casella K3:" << endl;
    try{
    test.set("A", "K3");
    }catch(const exception& ex){
    cout<<"Errore \n";
    }
    cout << test << "\n";
    cout << "Inserisco 'A' nella casella L3:" << endl;
    try{
    test.set("A", "L3");
    }catch(const exception& ex){
    cout<<"Errore \n";
    }
    cout << test << "\n";
    cout << "Inserisco 'A' nella casella M3:" << endl;
    test.set("A", "M3");
    cout << test << "\n";
    cout<<"Cerco il valore all'interno della casella B3: ";
    cout<<test.retrive("B3")<<endl;
    cout<<"\nRimuovo il valore all'interno della casella B3:"<<endl;
    test.remove("B3");
    cout<<test;
}
