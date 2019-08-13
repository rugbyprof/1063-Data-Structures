## Stack - Integer stack

```cpp
#include <iostream>

using namespace std;

class intStack{
private:
  int *S;
  int top;
  int size;
public:
  intStack(){
    size = 10;
    S = new int[size];
    top = -1;
  }
  
  intStack(int s){
    size = s;
    S = new int[size];
    top = -1;
  }
  
  void push(int x){
    S[++top] = x;
    
  }
  
  int peek(){
    if(empty()){
      return -1;
    }else{
      return S[top];
    }
  }
  
  int pop(){
    return S[top--];
  }
  
  bool empty(){
    return (top < 0);
  }
  
  bool full(){
    return top == (size-1);
  }
  
  void print(){
    if(top<0){
      cout<<"Stack Empty"<<endl;
      return;
    }
    for(int i=top;i>=0;i--){
      cout<<S[i]<<endl;
    }
    cout<<endl;
  }
};

int main() {
  intStack S(100);
  
  S.push(8);
  S.push(3);
  S.push(5);
  S.print();
  S.pop();
  S.print();
  
  for(int i=0;i<25;i++){
    S.push(rand()%50);
  }
  S.print();
  
  while(!S.empty()){
    S.pop();
  }
  S.print();
  
  ////////////////////////////////////
  
  int x = 34566772;
  int y = 0;
  
  cout<<x<<endl;
  
  while(x>0){
    S.push(x%10);
    cout<<x%10;
    x = x / 10;
  }
  cout<<endl;
  while(!S.empty()){
    cout<<S.pop();
  }
  
  
  
}
```
