#include <iostream>

using namespace std;

class ArrQueue{
private:
  int ArraySize;
  int *Q;
  int Front;
  int Rear;
  int NumItems;
public:
  ArrQueue(int size=10){
    ArraySize = size;
    Q = new int[ArraySize];
    Front = Rear = NumItems = 0;
  }
  
  bool Push(int value){
    Q[Rear++] = value;
    NumItems++;
  }
  
  int Pop(){
    int Temp = Q[Front++];
    NumItems--;
    return Temp;
  }
  
  bool Empty(){
    return (NumItems == 0);
  }
  
  bool Full(){
    return (NumItems == ArraySize);
  }
  
  void Print(){
    for(int i=0;i<NumItems;i++){
      cout<<Q[i]<<" ";
    }
    cout<<endl;
    
    int Index = Front;
    while(Index != Rear){
      
      Index = ((Index + 1) % ArraySize)
    }
  }
  
  
};

int main() {
    ArrQueue Q;
    Q.Push(3);
    Q.Push(5);
    Q.Push(2);
    Q.Push(8);
    Q.Push(1);
    Q.Print();

}
