#include <iostream>
#include "DLList.hpp"

using namespace std; 

int main() {
    DLList D;
    
    
    for(int i=0;i<10;i++){
        D.InsertBack(rand()%100);
    }
    D.Print();

    DLList E(D);
    E.Print();
    return 0;
}
