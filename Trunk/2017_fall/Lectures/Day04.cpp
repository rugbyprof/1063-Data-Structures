#include <iostream>

using namespace std;

class Stack{
  private:
  int *S;
  int top;
  int size;
  public:
  Stack(int s){
    size = s;
    top = -1;
    S = new int[size];
  }
  void push(int x){
    if(!full()){
      S[++top] = x;
    }else{
      cout<<"Stack Overflow!"<<endl;
    }
  }
  int pop(){
    if(!empty())
      return S[top--];
    else
      return -1;
  }
  void printStack(){
    for(int i=top;i>=0;i--){
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  bool empty(){
    return top == -1;
  }
  bool full(){
    return top == size-1;
  }
};

int main(){
  srand(546365);
  Stack s1(10);
  s1.push(3);
  s1.push(5);
  s1.push(8);
  for (int i=0;i<5;i++){
    
    s1.push(rand()%100);
  }
  s1.printStack();
  s1.pop();
  s1.pop();
  s1.pop();
  s1.printStack();
    for (int i=0;i<10;i++){
    
    s1.push(rand()%100);
  }
  s1.printStack();
  return 0;
}
