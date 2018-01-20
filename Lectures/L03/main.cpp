#include <iostream>
#include <ctime>

using namespace std;

/**
* Function: printArray
* Params:
*    int A[] : array of ints to print
*    int size: size of array so we know when to stop looping
* Returns:
*    void
*/
void printArray(int A[],int size){
    for(int j=0;j<size;j++){
     cout<<A[j]<<" ";
    }
    cout<<endl;
}

/**
* Function: printCounts
* Description:
*    Prints the counts of our counts. Pretty much the same as the other
*    print function, but we now print the index of the array as well 
*    which represents the number being counted.
* Params:
*    int A[] : array of counts to print
*    int size: size of array so we know when to stop looping
* Returns:
*    void
*/
void printCounts(int A[],int size){
    // j in this function represents the number being counted
    // and the value in the array is the count of that number
    for(int j=0;j<size;j++){
     cout<<j<<":"<<A[j]<<endl;
    }
    cout<<endl;
}

/**
* Function: printCounts
* Description:
*    Counts the number of times an integer (< size) occurs in the array.
*    In class we capped it at ints less than 10.
* Params:
*    int randomVals[] : array of values to count
*    int counts[]     : array of counts
*    int size         : size of array so we know when to stop looping
* Returns:
*    int max counted value in array.
*/
int countItem(int randomVals[],int counts[],int size){
    
  // j in this loop indexes the value in randomVals and uses
  // it as the index into counts.
  for(int j=0;j<size;j++){
     counts[randomVals[j]]++;
  }
  
  cout<<endl;
  printCounts(counts,10);
  
  return 0; // should return value that occured most, will fix next class.
}

int main() {
  srand(923784);
  
  //Declared some variables
  int size = 100;           // size of array to count
  int max = 10;             // max value to place in array
  int A[100] = {0};         // declare array of size 100 (dynamic allocation later) init to 0's
  int counts[10] = {0};     // declare array of "max" size. 
  
  // loaded up an array with random nums
  // between 0 and max-1
  for(int i=0;i<size;i++){
    A[i] = rand() % max;
  }
    
  countItem(A,counts,size);
  
}
