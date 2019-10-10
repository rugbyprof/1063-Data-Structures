/**
 * Lecture 08
 * 
 * List based queue 
 * 
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 */
#include <iostream>
#include <fstream>
#include "ListQueue.hpp"

using namespace std;


int main() {
  ListQueue LQ;                 // Queue instance 

  
  for(int i=0;i<10;i++){        // Load random values onto the queue
    int r = rand()%100;
    cout<<r<<" ";
    LQ.Push(r);
  }

  cout<<endl;                     // ummmm 

  LQ.Print();                     // print queue to see where values are


  for(int i=0;i<5;i++){           // remove 5 items
    if(!LQ.Empty()){
      int t = LQ.Pop();
      cout<<"Item: "<<t<<endl;    // print out items
    }else{
      cout<<"Empty queue!"<<endl;
    }

  }

  LQ.Print();                     // print again to show front removal
  LQ.PrintPointers();

  Node* f = LQ.GetFront();        // We added this in class JUST to see what front
  cout<<f->data<<endl;            // pointed to.
}