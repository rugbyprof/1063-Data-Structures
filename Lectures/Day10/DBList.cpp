#include <iostream>
#include "DBList.h"

using namespace std;

//Public 
////////////////////////////////////////////

DBList::DBList(){
  Head = NULL;
  Tail = NULL;
}


bool DBList::InsertFront(int Data){
  Node* Temp = _CreateNode(Data);
  if(!Head){
    Head = Temp;
    Tail = Temp;
  }else{
    Temp->Next = Head;
    Head->Prev = Temp;
    Head = Temp;
  }
}

bool DBList::InsertRear(int Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = _CreateNode(Data);
    Tail->Next = Temp;
    Temp->Prev = Tail;
    Tail = Temp;
  }
}

bool DBList::InsertInOrder(int Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = _CreateNode(Data);
    Node* Location = DBList::Find(Data);
    
  }
}

bool DBList::Delete(int x){
  
}

Node* DBList::Find(int x){
  
}

bool DBList::Update(int x,int y){
  
}

void DBList::Print(){
  Node *Temp = Head;
  while(Temp){
    cout<<Temp->Data<<" ";
    Temp = Temp->Next;
  }
}

//Private 
////////////////////////////////////////////


Node* DBList::_CreateNode(int data){
  Node *Temp = new Node;
  Temp->Data = data;
  Temp->Prev = NULL;
  Temp->Next = NULL;
  return Temp;
}


