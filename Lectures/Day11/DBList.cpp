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
    //Node* Location = DBList::_Find(Data);
    
  }
}

bool DBList::Delete(int x){
  //One node 
  if(Head == Tail && Head->Data==x){
    delete Head;
    Head = NULL;
    Tail = NULL;
    return true;
  //Beginning of list
  }else if(Head->Data == x){
    Head = Head->Next;
    delete Head->Prev;
    Head->Prev = NULL;
    return true;
  //End of list
  }else if(Tail->Data == x){
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = NULL;
    return true;
  //Middle of list
  }else{
    Node* Location = DBList::_Find(x);
    if(Location){
      Location->Prev->Next = Location->Next;
      Location->Next->Prev = Location->Prev;
      delete Location;
      return true;
    }
  }
  return false; 
}

bool DBList::Find(int x){
  
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


Node* DBList::_Find(int key){
  Node* Temp = Head;
  
  while(Temp){
    if (Temp->Data == key){
      return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}

Node* DBList::_CreateNode(int data){
  Node *Temp = new Node;
  Temp->Data = data;
  Temp->Prev = NULL;
  Temp->Next = NULL;
  return Temp;
}


