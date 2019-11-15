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

class DLList{
private:
  Node *Head;
  Node *Middle;
  Node *Tail;
  void FrontSert(Node*&);
  void EndSert(Node*&);
  int Count;
  int MiddleLoc;
  void UpdateMiddle();
  void _Rprint(Node*);
public:
  
  DLList();
  ~DLList();
  void Insert(int);
  void Print();
  void Rprint();
  void Delete();
  void RevPrint();
};


DLList::DLList(){
  Head = Middle = Tail = NULL;
  Count = 0;
  cout<<"this is the constructor"<<endl;
}

DLList::~DLList(){
  Node* temp = Head;

  while(temp){
    
    temp = temp->Next;
    cout<<"deleting: "<<Head->data<<" ";
    delete Head;
    Head = temp;
  }
}

void DLList::Insert(int data){
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

  cout<<"Count: "<<Count<<endl;
}

void DLList::UpdateMiddle(){

}

void DLList::FrontSert(Node*& Temp){
  Head->Prev = Temp;
  Temp->Next = Head;
  Head = Temp;
  Count++;
}

void DLList::EndSert(Node*& Temp){
  Tail->Next = Temp;
  Temp->Prev = Tail;
  Tail = Temp;
  Count++;
}

void DLList::Print(){
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

void DLList::_Rprint(Node* ptr){
  // base case
  if(!ptr){
    return;
  }
  cout<<ptr->data<<endl;
  //recursive call
      // reduce problem space
  _Rprint(ptr->Next);
  
}

// public
void DLList::Rprint(){
  _Rprint(Head);
}

void DLList::RevPrint(){
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

int main(){
    DLList D;
    return 0;
}
