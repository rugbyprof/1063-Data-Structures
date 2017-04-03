#include <iostream>

using namespace std;

struct Coord{
  int row;
  int col;
  Coord(int r=0,int c=0){
    row = r;
    col = c;
  }
};

struct Node{
  Coord *loc;
  Node *Next;
};


class MoveStack{
private:
  int NumItems;
  Node *Top;
public:
  MoveStack(){
     Top = NULL;
  }
  void Push(Coord *c){
    //Allocated memory for my new node
    Node* Temp = new Node;
    Temp->loc = c;
    Temp->Next = NULL;
    
    //Figure out where it goes.
    
    if(Top == NULL){
      Top = Temp;
    }else{
      Temp->Next = Top;
      Top = Temp;
    }
  }
  
  void Pop(Coord *&c){
    if(!Empty()){
      c = Top->loc;
      Node* Temp = Top;
      Top = Top->Next;
      delete Temp;
    }
  }
  
  bool Empty(){
    return Top == NULL;
  }
  
  
  void Print(){
    Node* Temp = Top;
    while(Temp != NULL){
      cout<<"["<<Temp->loc->row<<","<<Temp->loc->col<<"]"<<endl;
      Temp = Temp->Next;
    }
  }
};

int main(){
  MoveStack M;
  Coord *c = new Coord(3,4);
  Coord *b;
  M.Push(c);
  c = new Coord(5,6);
  M.Push(c);
  c = new Coord(6,7);
  M.Push(c);
  M.Print();
  cout<<endl;
  M.Pop(b);
  cout<<b->row<<","<<b->col<<endl;
  M.Print();
  
}
