#include <iostream>
#include "DoubleyLinked.hpp"

using namespace std;

int main() {
  DoubleyLinked D;

  D.Insert(10);
  D.Insert(8);
  D.Insert(5);
  D.Insert(3);
  D.Insert(12);
  D.Insert(14);
  D.Insert(3);
  
  //D.RevPrint();
  D.Insert(4);

  for(int i=0;i<10;i++){
    D.Insert(rand() % 100);
  }
  D.Insert(93);
  D.Print();

  return 0;
}