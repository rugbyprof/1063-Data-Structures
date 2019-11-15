#include <iostream>
#include "DLList.hpp"

using namespace std; 

int main() {
    DLList D;                       // Create a list called D;
    
    
    for(int i=0;i<10;i++){          // Load D with 10 random numbers
        D.InsertBack(rand()%100);
    }
    D.Print();                      // Print D out

    DLList E(D);                    // Create a list E using D's values
    
    E.Print();                      // Print E (its same as D)
    
    return 0;
}
