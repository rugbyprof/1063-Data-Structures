#include <iostream>

struct Node{
  int Data;
  Node *Next;
};

using namespace std;

class List{
private:
    Node *Head;
    Node *Tail;
public:
    List(){
      Head = NULL;
    }
    
    void FrontSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(Head){
        Temp->Next = Head;
      }

      Head = Temp;
      
    }
    
    //Not Done
    void OrderedSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(!Head){
        Head = Temp;
      }else{
        //X is less than head node
        if(x < Head->Data){
          Temp->Next = Head;
          Head = Temp;
        }else{
          Node *Curr = Head;
          Node *Prev = Head;
          
          while(Curr && x > Curr->Data){
            Prev = Curr;
            Curr = Curr->Next;
          }
          
          Prev->Next = Temp;
          Temp->Next = Curr;
        }
    }
    
    void PrintList(){
      if(!Head){
        cout<<"Empty"<<endl;
        return;
      }else{
        Node *Temp = Head;
        while(Temp != NULL){
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;
        }
      }
    }

};


int main() {
    srand(97097807);
    List L;
    for(int i=0;i<10;i++){
      L.FrontSert(rand()%100);
    }
    L.PrintList();
    
    
    return 0;
}
