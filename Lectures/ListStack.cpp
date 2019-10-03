#include <iostream>
#include "ListStack.h"

using namespace std;

ostream& operator<<(ostream& os, const Animal* a)
{
    os << a->name << ':' << a->weight << ':' << a->scary;
    return os;
}

ListStack::ListStack(){
  Top = NULL;
}

void ListStack::Push(Animal *A){
  // allocate new memory
  Node *anode = new Node(A);

  // check if list is empty
  if(!Top){
    Top = anode;
  }else{
    anode->Next = Top;
    Top = anode;
    
  }
}

Animal* ListStack::Pop(){
  if(!Top){
    return NULL;
  }else{
    Node* Temp = Top;

    Animal* a = Top->A;

    Top = Top->Next;

    delete Temp;

    return a;

  }
}

void ListStack::Print(){
  Node* Temp = Top;

  while(Temp != NULL){
    cout<<Temp->A<<endl;
    Temp = Temp->Next;
  }
}