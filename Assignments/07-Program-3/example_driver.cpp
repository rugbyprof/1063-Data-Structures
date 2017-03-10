#include <iostream>
#include <string>

using namespace std;

/**
* @FunctionName: Stack
* @Description: 
*     Implementation of a char stack
*/
class Stack{
  private:
  //////////////////////////////////////////////////////
  
  char *S;
  int top;
  int size;
  
  public:
  //////////////////////////////////////////////////////
  
  /**
  * @FunctionName: Stack
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial stack size
  * @Returns:
  *    void
  */
  Stack(int insize){
    size = insize;
    top = -1;
    S = new char[size];
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the stack
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c){
    if(!Full()){
      S[++top] = c;
    }else{
      cout<<"Stack Overflow!"<<endl;
    }
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop(){
    if(!Empty())
      return S[top--];
    else
      return -1;
  }
  
  /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintStack(){
    for(int i=top;i>=0;i--){
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty(){
    return top == -1;
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full(){
    return top == size-1;
  }
};



/**
* @FunctionName: Queue
* @Description: 
*     Implementation of a char queue
*/
class Queue{
  private:
  //////////////////////////////////////////////////////
  
  int ArraySize;
  char *Q;
  int Front;
  int Rear;
  int NumItems;
  
  public:
  //////////////////////////////////////////////////////
  
  /**
  * @FunctionName: Queue
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial queue size
  * @Returns:
  *    void
  */
  Queue(int insize){
    ArraySize = insize;
    Q = new char[ArraySize];
    Front = Rear = NumItems = 0;
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the queue
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c){
    if(Full()){
      cout<<"Queue Full!"<<endl;
      return;
    }
    Q[Rear] = c;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return;
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the queue
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop(){
    if(Empty()){
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }
  
  /**
  * @FunctionName: printQueue
  * @Description: 
  *     Prints queue to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintQueue(){
    for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%ArraySize){
      cout<<Q[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if queue is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty(){
    return (NumItems == 0);
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if queue is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full(){
    return (NumItems == ArraySize);
  }
};

class Calculator{
private:
  Queue *Q;
  Stack *S;
  int Size;
  string infix;
  string postfix;
  void InfixToPostfix(){
    if(infix.length() == 0){
      cout<<"Error: infix not set.";
      return;
    }
    for(int i=0;i<infix.length();i++){
      S->Push(infix[i]);
    }
    while(!S->Empty()){
      postfix += S->Pop();
    }
    cout<<postfix<<endl;
  }
  int EvaluatePostfix(){
    for(int i=0;i<postfix.length();i++){
      //
    }
    return 99;
  }
public:
  Calculator(){
    // Size = size;
    // Q = new Queue(Size);
    // S = new Stack(Size);
    infix = "";
    postfix = "";
  }
  int ProcessExpression(string exp){
    int answer = 0;
    Q = new Queue(exp.length()+2);
    S = new Stack(exp.length()+2);
    infix = exp;
    cout<<infix<<endl;
    InfixToPostfix();
    answer = EvaluatePostfix();
    delete Q;
    delete S;
    return answer;
  }
};



int main(){

  Calculator C;
  cout<<C.ProcessExpression("(3+4)/2")<<endl;
  cout<<char(49)<<endl; 
}

