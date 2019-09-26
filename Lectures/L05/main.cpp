/**
 * File: main.cpp
 * Aurhor: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: 24 Sep 24
 * Description:
 *    Main driver of an Array based implementation of a stack.
 */

#include <iostream>
#include "stack.h"
#include "stdlib.h"

using namespace std;

/**
 * Main Program
 * 
 */
int main() {
  srand(34234); // seed random number gen

  Stack S1; // Instance of our stack default constructor
  Stack S2(200);  // Instance of our stack specified size

  // Load the stack with random nums
  for (int i = 0; i < 10; i++) {
    S1.Push(rand() % 100);
  }

  // make sure it looks correct
  S1.Print();

  // Pop some items off the top  
  S1.Pop();
  S1.Pop();
  S1.Pop();
  S1.Pop();

  cout << endl;

  // Check for correct behavior again.
  S1.Print();
  return 0;
}