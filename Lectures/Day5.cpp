#include <iostream>

struct Node{
    int data;
    Node *next;
};

class List{
private:
  Node* Head;
  int size;
public:

  List(){
    Head = NULL;
    size = 0;
  }

  void Push(int val){
    if(Head == NULL){
      Head = new Node;
      Head->data = val;
      Head->next = NULL;
    }else{
      Node* Curr = Head;
      Node* Prev = Head;
      while(Curr != NULL){
        Prev = Curr;
        Curr = Curr->next;
      }
      Prev->next = new Node;
      Prev->next->data = val;
      Prev->next->next = NULL;
    }
    size++;
  }
  
  int Pop(){
    int data = Head->data;
    Node* Temp = Head;
    Head = Head->next;
    delete Temp;
    size--;
    return data;
  }
  
  void PrintList(){
    Node * current = Head;
    while(current != NULL){
      std::cout<<current->data;
      if(current->next != NULL){
        std::cout<<"->";
      }
      current = current->next;
    }
    std::cout<<std::endl;
  }
  
  int Size(){
    return size;
  }
  
};

int main() {
    std::cout << "Hello World!\n";
    int A[10] = {22,34,21,55,6,7,55,4,88,10};
    
    std::cout<<A[0]<<std::endl;  
    std::cout<<*A<<std::endl;
    std::cout<<*(A+9)<<std::endl;
    
    List L;
    for(int i=0;i<10;i++){
      L.Push(i);
    }
    L.PrintList();
    L.Pop();
    L.Pop();
    L.PrintList();
    std::cout<<L.Size()<<std::endl;

}
