#include <iostream>
#include <string>
#include "DBList.h"

using namespace std;

//Public 
////////////////////////////////////////////

DBList::DBList(){
  Head = NULL;
  Tail = NULL;
  Current = NULL;
}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertFront(string Data){
  Node* Temp = new Node(Data);
  InsertFront(Temp);

}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list
 * Params:
 *     Node*& : node to be appended to front
 */
void DBList::InsertFront(Node* &Temp){
  
  if(!Head){
    Head = Temp;
    Tail = Temp;
    Tail->Next = Head;
    Current = Temp;
    Head->Prev = Tail;
    
  }else{
    Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Head = Temp;
    Current = Head;
  }
}

/**
 * PriorityInsert - 
 * 
 *     Priority = shortest word = higher priority 
 *                words of equal length = alphabatize
 *    
 */ 
void DBList::PriorityInsert(string Data){
  
  //Allocate new memory
  Node* N = new Node(Data);
  
  //Empty list -> easy
  if(!Head){
    DBList::InsertFront(N);
  
  }else{
    // check if the new word is shorter than the head
    // Check if Data (animal) shorter than Heads animal
    if(N->Data.length() <= Head->Data.length()){
      DBList::InsertFront(N);
      
    // check if the new word is longer than the tail
    // animal length is longer than the end of the list
    }else if(N->Data.length() > Tail->Data.length()){
      cout<<"rearsert"<<endl;
      DBList::InsertRear(N);
      
    // we must traverse!
    }else{
      
      // Temp pointer set to head
      Node* T = Head;
      
      // while T is not null and the length is greater than T's word
      while(T && N->Data.length() > T->Data.length()){
        T = T->Next;
      }
      
      // It T is not null and T equals the Tail
      if(T && T==Tail){
        DBList::InsertRear(N);
        
      // Check to make sure T is not null
      }else if(T){
        
        // NOW we alphabetize!
        cout<<"Length:"<<N->Data.length()<<endl;
        
        // while N > T and N's length same as T's length and T->Next exists
        while(N->Data > T->Data && N->Data.length() == T->Data.length() && T->Next){
          T = T->Next;
        }
        
        // Link the node in!
        N->Next = T;
        N->Prev = T->Prev;
        T->Prev->Next = N;
        T->Prev = N;
      }
    }
  }
}

void DBList::InsertRear(Node* &Temp){

  if(!Head){
    DBList::InsertFront(Temp);
  }else{
    Tail->Next = Temp;
    Temp->Prev = Tail;
    Tail = Temp;
  }
}

/**
 * InsertRear - 
 *     Inserts a value at the rear of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertRear(string Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = new Node(Data);
    InsertRear(Temp);
  }
}

void DBList::InsertInOrder(string Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = new Node(Data);
    //Node* Location = DBList::_Find(Data);
    
  }
}

bool DBList::Delete(string x){
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

bool DBList::Find(string x){
  return false;
}

bool DBList::Update(string x,string y){
  return false;
}

void DBList::Print(int columns){
  Node *Temp = Head;
  int count = 1;
  
  while(Temp != Tail){
    cout<<Temp->Data<<" ";
    Temp = Temp->Next;
    if(columns && count % columns == 0)
      cout<<endl;
    count++;
  }
}

void DBList::Print(){
  DBList::Print(0);
}
//Private 
////////////////////////////////////////////


Node* DBList::_Find(string key){
  Node* Temp = Head;
  
  while(Temp){
    if (Temp->Data == key){
      return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}



