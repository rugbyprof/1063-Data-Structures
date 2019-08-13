//////////////////////////////////////////////////////
// This is a copy of the findMax function we wrote earlier
// this semester going over functions. Lets do the same
// thing we did with the word count (turn it into a class)
// but hopefull less confusing.
//////////////////////////////////////////////////////

#include <iostream>
#include <ctime>

using namespace std;

/**
 * Function: printArray
 * Description: prints an array
 * Params:
 *     int []   : array of integers
 *     int size : size of the array
 * Returns:
 *     void
 * */
void printArray(int A[],int size){
  for(int i=0;i<size;i++){
    cout<<A[i]<<endl;
  }
}

/**
 * Function: findMax
 * Description: finds the max int value in an array of int's
 * Params:
 *     int []   : array of integers
 *     int size : size of the array
 * Returns:
 *     int
 * */
int findMax(int A[],int size){
  int max = A[0]; //init max to first item in array
  
  for(int i=1;i<size;i++){
    if(A[i] > max){
      max = A[i];
    }
  }
  
  return max;
}

//Main program
int main() {
  int size = 100;   //creating a size variable 
    
  int A[size] = {0}; //declaring an integer array of some size

  
  srand(time(0));   //seeding random number generator
  
  //Loading up array with random integers 
  //from 0 to size.
  for(int i=0;i<size;i++){
    A[i] = rand()%size;
  }
  
  //Print out array to std out;
  printArray(A,size);
  
  cout<<endl;
  
  //Find max value and print it out 
  cout<<"Max value = "<<findMax(A,size)<<endl;
}
