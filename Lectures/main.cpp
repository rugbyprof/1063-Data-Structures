#include <iostream>
#include <fstream>
#include "ListStack.h"

using namespace std;



int main() {
 ifstream fin("animals.txt");
 string n;
 double w;
 double s;
 Animal *a;
 ListStack LS;

 while(!fin.eof()){
   a = new Animal();
   fin>>a->name>>a->weight>>a->scary;
   LS.Push(a);

  //  cout<<a->name<<a->weight<<a->scary<<endl;
  //  cout<<a<<endl;
 }
  LS.Print();
  cout<<endl;
  a = LS.Pop();
  //cout<<a->name<<a->weight<<a->scary<<endl<<endl;
  cout<<a<<endl;
  a = LS.Pop();
  //cout<<a->name<<a->weight<<a->scary<<endl<<endl;
  cout<<a<<endl;
  LS.Print();
}