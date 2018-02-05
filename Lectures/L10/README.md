## Linked List - Introduction to linked lists

```cpp
#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
  Node(){
    data=0;
    next=NULL;
  }
};

class List{
  private:
    Node* Head;
  public:
    List(){
      Head = NULL;
    }
    
  void Insert(int x){
    if(Head == NULL){
      Head = new Node;
      Head->data = x;
    }else{
      Node* Temp = new Node;
      Temp->data = x;
      Temp->next = Head;
      Head = Temp;
    }
  }
  
  void Print(){
    Node* Temp = Head;
    
    while(Temp != NULL){
      cout<<Temp->data<<"->";
      //do cool stuff
      Temp = Temp->next;
    }
  }
};

int main() {

  List L;
  
  for(int i=0;i<10000;i++){
    L.Insert(rand()%100);
  }
  L.Print();
  
}
```
