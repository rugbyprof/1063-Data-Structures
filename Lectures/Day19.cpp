#include <iostream>

using namespace std;

struct Node{
  int Data;
  Node* Next;
};

class IntListStack{
private:
  Node* Top;
public:
  IntListStack(){
    Top = NULL;
  }
  bool Empty(){
    return Top == NULL;
  }
  void Push(int val){
    Node* Temp = new Node;
    Temp->Data = val;
    Temp->Next = NULL;
    
    if(Empty()){
     Top = Temp;
    }else{
      Temp->Next = Top;
      Top = Temp;
    }
  }
  int Pop(){
    int TempData = Top->Data;
    Node* TempNodePtr = Top;
    Top = Top->Next;
    delete TempNodePtr;
    return TempData;
  }
  
  void Print(){
    Node* Temp = Top;
    while(Temp){
      cout<<Temp->Data<<"->";
      Temp = Temp->Next;
    }
    cout<<endl;
  }
};

class IntListQueue{
private:
  Node* Front;
  Node* Rear;
public:
  IntListQueue(){
    Front = Rear = NULL;
  }
  bool Empty(){
    return Front == NULL;
  }
  void Push(int val){
    Node* Temp = new Node;
    Temp->Data = val;
    Temp->Next = NULL;
    
    if(Empty()){
      Front = Rear = Temp;
    }else{
      Rear->Next = Temp;
      Rear = Temp;
    }
  }
  int Pop(){
    int TempData = Front->Data;
    Node* TempNodePtr = Front;
    Front = Front->Next;
    delete TempNodePtr;
    return TempData;
  }
  
  void Print(){
    Node* Temp = Front;
    while(Temp){
      cout<<Temp->Data<<"->";
      Temp = Temp->Next;
    }
    cout<<endl;
  }
};

int main(){
  IntListQueue Q;
  Q.Push(8);
  Q.Push(34);
  Q.Push(18);
  Q.Push(7);
  Q.Print();
  Q.Pop();
  Q.Print();
  
  IntListStack S;
  S.Push(8);
  S.Push(34);
  S.Push(18);
  S.Push(7);
  S.Print();
  S.Pop();
  S.Print();
  return 0;
}
