/**
* @ProgramName: Array Based Queue
* @Author: CS 1063 Course Members 
* @Description: 
*     This program uses an array to implement a basic queue.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2017
*/
#include <iostream>

using namespace std;

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

/*
This main reads an infix expression from stdin, puts the tokens
in a queue, then pops each item off the queue and prints it out.
This is not meant to influence your solution to the program, it 
is simply showing basic queue use.
*/
int main(){
  srand(546365);
  string infix;
  char temp;
  
  cout<<"Expression [e.g. (3+4)*9-(3+4)*8 ]:";
  cin>>infix;
  
  Queue q1(infix.length());
  for(int i=0;i<infix.length();i++){
    q1.Push(infix[i]);
  }
  
  while(!q1.Empty()){
    temp = q1.Pop();
    cout<<temp;
    //we could simply do cout<<q1.pop(); as well. 
  }
  cout<<endl;
  return 0;
}
