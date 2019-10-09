/**
 * Array based circular queue implementation
 * Author: Terry Griffin
 * Course: CMPS 1063
 * 
 * Description: Implementation of a circular queue using an array as our container
 */
#include "queue.h"
#include <iostream>

/**
 * Queue
 * Description:
 *    Default Constructor for our queue class
 * Params:
 *    void
 * Returns:
 *    void
 */
Queue::Queue(){
  Size = 10;
  A = new int [Size];
  Front = 0;
  Rear = 0;
  Count = 0;
}

/**
 * Queue
 * Description:
 *    Overloaded Constructor for our queue class
 * Params:
 *    int s : size of our container (array)
 * Returns:
 *    void
 */
Queue::Queue(int s){
  Size = s;
  A = new int [Size];
  Front = 0;
  Rear = 0;
  Count = 0;
}

/**
 * Full
 * Description:
 *    Checks if array is full
 * Params:
 *    void
 * Returns:
 *    bool : true = array full
 */
bool Queue::Full(){
  return Count == Size;
}

/**
 * Empty
 * Description:
 *    Checks if array is empty
 * Params:
 *    void
 * Returns:
 *    bool : true = array empty
 */
bool Queue::Empty(){
  return Count == 0;
}

/**
 * Push
 * Description:
 *    Adds an item to back of queue
 * Params:
 *    void
 * Returns:
 *    void (could return bool for successful add)
 */
void Queue::Push(int val){
  if(!Full()){
    A[Rear] = val;              // get front value

    Rear = (Rear + 1) % Size;   // Re-set rear using mod to 
                                // wrap around if needed
    Count++;                   
  }else{
    // Could "throw" an error or return "false" instead
    cout<<"Error: Adding to Full Queue\n";
  }
}

/**
 * Pop
 * Description:
 *    Removes an item from front of queue
 * Params:
 *    void
 * Returns:
 *    int : value from queue
 */
int Queue::Pop(){
  if(!Empty()){
    int Temp = A[Front];        // copy front item into var
    Count--;                    // reduce count

    Front = (Front + 1) % Size; // Move front back one using
                                // mod to wrap around if necessary
    return Temp;
  }else{
    // Could "throw" an error or return "false" instead
    cout<<"Error: Removing from Empty queue\n";
  }
  return -99;
}

/**
 * Print
 * Description:
 *    Print the queue for debugging purposes
 * Params:
 *    void
 * Returns:
 *    void
 */
void Queue::Print(){
  for(int i=Front;i<Rear;i++){
    std::cout<<A[i];
    if(i<Rear-1){
      std::cout<<"->";
    }
  }
  cout<<endl;
}