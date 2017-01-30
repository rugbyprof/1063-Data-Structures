#include <iostream>

struct Node{
  int Data;
  Node *next;
};

class List{
private:
  Node *Head;
public:
  List(){
    Head = NULL;
  }
  
  void FrontSert(int x){
    if(Head == NULL){
      Head = new Node;
      Head->Data = x;
      Head->next = NULL;
    }else{
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->next = Head;
      Head = Temp;
    }
  }
  
  void Print(){
    if(!Head){
      std::cout<<"Empty"<<std::endl;
      return;
    }
    Node *Curr = Head;
    while(Curr->next != NULL){
      std::cout<<Curr->Data<<" ";
      Curr = Curr->next;
    }
    std::cout<<Curr->Data<<" ";
    return;
  }
};

int main() {
  srand(8796);
  List L;
  L.FrontSert(7);
  L.FrontSert(3);
  for(int i=0;i<10000;i++){
    L.FrontSert(rand()%100);
  }
  L.Print();
  //   int *p; 
  //   //int *y;
  //   p = new int;
    
  //   *p = 45;
    
  // //y = p;
    
  //   std::cout<<*p<<std::endl;
  //   //std::cout<<*y<<std::endl;
    
  //   delete p;
    
  //   p = new int;
    
    return 0;
}
