#include <iostream>
#include "DBList.h"

using namespace std;

int main() {
    srand(93487);
    DBList List1;
    DBList List2;
    
    for(int i=0;i<10;i++){
      List1.InsertFront(i);
    }
    
    List1.Print();
    
    cout<<endl;
    
    for(int i=0;i<10;i++){
      List2.InsertRear(i);
    }
    
    List2.Print();
    
    List2.Delete(0);
    List2.Delete(9);
    cout<<endl;
    List2.Print();
  
    List2.Delete(5);
    cout<<endl;
    List2.Print();
    
}
