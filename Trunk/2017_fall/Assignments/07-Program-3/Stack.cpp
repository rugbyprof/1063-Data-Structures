/**
* @ProgramName: Array Based Stack
* @Author: CS 1063 Course Members 
* @Description: 
*     This program uses an array to implement a basic stack.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2017
*/
#include <iostream>

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
  void push(char c){
    if(!full()){
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
  char pop(){
    if(!empty())
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
  void printStack(){
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
  bool empty(){
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
  bool full(){
    return top == size-1;
  }
};

/*
This main reads an infix expression from stdin, puts the tokens
in a stack, then pops each item off the stack and prints it out.
This is not meant to influence your solution to the program, it 
is simply showing basic stack use.
*/
int main(){
  srand(546365);
  string infix;
  char temp;
  
  cout<<"Expression [e.g. (3+4)*9-(3+4)*8 ]:";
  cin>>infix;
  
  Stack s1(infix.length());
  for(int i=0;i<infix.length();i++){
    s1.push(infix[i]);
  }
  
  while(!s1.empty()){
    temp = s1.pop();
    cout<<temp;
    //we could simply do cout<<s1.pop(); as well. 
  }
  cout<<endl;
  return 0;
}
