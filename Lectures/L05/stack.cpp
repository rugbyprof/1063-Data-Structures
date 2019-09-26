/**
 * File: stack.cpp
 * Aurhor: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: 24 Sep 24
 * Description:
 *    Class implementation file for our array based stack of ints
 */

#include <iostream>
#include "stack.h"

using namespace std;

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
Stack::Stack(){
  Size = 100;
  A = new int [Size];
  Top = -1;
}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
Stack::Stack(int s){
  Size = s;
  A = new int [Size];
  Top = -1;
}

/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
bool Stack::Push(int val){
  if(!Full()){
    Top++;
    A[Top] = val;
    return true;
  }else{
    return false;
  }
}

/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
int Stack::Pop(){
  if(!Empty()){
    int temp = 0;   
    temp = A[Top];
    Top--;
    return temp;
  }else{
    // should return a value that implies failuer, but good enough for now
    cout<<"Cannot remove item from empty stack"<<endl;
  }
  return 0;
}

/**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    void
 * Returns:
 *     void
 */
void Stack::Print(){
  for(int i = Top;i>=0 ; i--){
    cout<<A[i]<<endl;
  }
}

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
bool Stack::Empty(){
  return Top < 0;
}

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
bool Stack::Full(){
  return (Top == Size - 1);
}

