#include <string>
#include <iostream>
#include <stdexcept>

#include "include/Griglia.h"

using namespace std;

int main(){
    Griglia test;
    cout<<test;
    test.set("A", "B3");
    cout<<test;
    cout<<test.retrive("B3")<<endl;
    test.remove("B3");
    cout<<test;
}
