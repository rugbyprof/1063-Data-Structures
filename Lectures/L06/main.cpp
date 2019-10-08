/**
 * Array based circular queue main driver
 * Author: Terry Griffin
 * Course: CMPS 1063
 * 
 * Description: An in class solution to a very basic circular queue. 
 */
#include <iostream>
#include "queue.h"


using namespace std;


int main() {
  Queue Q;  // Queue instance (now Q is an object)

  // Putting random values on the queue
  for(int i;i<3;i++){
    Q.Push(rand()%100);
    Q.Print();  // just for our benefit to check correctness
  }

  // Popping (de-queueing) items off the queue
  // for(int i;i<12;i++){
  //   Q.Pop();
  //   Q.Print();
  // }
  
  Q.Push(33);
  cout<<Q.Pop()<<endl;

  Q.Push(24);
  cout<<Q.Pop()<<endl;

  Q.Push(14);
  cout<<Q.Pop()<<endl;

  Q.Push(4);
  cout<<Q.Pop()<<endl;

  Q.Push(99);
  cout<<Q.Pop()<<endl;

  Q.Print();
  
}