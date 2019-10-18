/**
 * Topic: Doubley Linked List
 * Aurhor: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: October 2019
 * Description:
 *    Basic Doubley Linked List
 */
#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* Next;
  Node* Prev;

  Node(int d){
    data = d;
    Next = NULL;
    Prev = NULL;
  }
};

class DoubleyLinked{
private:
  Node *Head;
  Node *Middle;
  Node *Tail;
  void FrontSert(Node*&);
  void EndSert(Node*&);
  int Count;
  int MiddleLoc;
  void UpdateMiddle();
  void _RecPrint(Node*);
public:
  
  DoubleyLinked();
  void Insert(int);
  void Print();
  void Delete();
  void RevPrint();
  void RecPrint();
};


DoubleyLinked::DoubleyLinked(){
  Head = Middle = Tail = NULL;
  Count = 0;
}

void DoubleyLinked::Insert(int data){
  Node* Temp = new Node(data);

  if(!Head){
    Head = Temp;
    Middle = Temp;
    Tail = Temp;
    MiddleLoc = 1;
  }else{

    if(Temp->data <= Head->data){
      FrontSert(Temp);
    }else if(Temp->data >= Tail->data){
      EndSert(Temp);
    }else{
      Node* Trav = Head;

      while(Trav && Temp->data > Trav->data){
        Trav = Trav->Next;
      }
      cout<<Trav->data<<endl;

      Trav->Prev->Next = Temp;
      Temp->Prev = Trav->Prev;
      Temp->Next = Trav;
      Trav->Prev = Temp;
      Count++;
    }

  }

  // here!!!

  cout<<"Count: "<<Count<<endl;
}

void DoubleyLinked::UpdateMiddle(){

}

void DoubleyLinked::FrontSert(Node*& Temp){
  Head->Prev = Temp;
  Temp->Next = Head;
  Head = Temp;
  Count++;
}

void DoubleyLinked::EndSert(Node*& Temp){
  Tail->Next = Temp;
  Temp->Prev = Tail;
  Tail = Temp;
  Count++;
}

void DoubleyLinked::Print(){
    Node* Temp = Head;

    while(Temp){
      cout<<Temp->data;
      if(Temp->Next){
        cout<<"->";
      }
      Temp = Temp->Next;
    }
    cout<<endl;
}

void DoubleyLinked::RevPrint(){
    Node* Temp = Tail;

    while(Temp){
      cout<<Temp->data;
      if(Temp->Prev){
        cout<<"->";
      }
      Temp = Temp->Prev;
    }
    cout<<endl;
}

// private
void DoubleyLinked::_RecPrint(Node* ptr){
  // 1) base case
  if(!ptr){
    return;
  }
  cout<<ptr->data<<endl;
  //3) recursive call
      // 2) reduce problem space
  _RecPrint(ptr->Next);
}

// public
void DoubleyLinked::RecPrint(){
  _RecPrint(Head);
}
