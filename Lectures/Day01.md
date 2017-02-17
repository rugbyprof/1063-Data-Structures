```cpp
#include <iostream>
#include <ctime>
using namespace std;

/**
* fillArray - fill an integer array with numbers no larger than "mod" size
* @params:
*    int a[]: array of ints
*    int size: size of array
*    int mod: number to cap size of random value
* @returns:
*    void
*/
void fillArray(int a[],int size,int mod){
    for(int i=0;i<size;i++){
      a[i] = rand()%mod;
    }
}

/**
* printArray - print values to standard out
* @params:
*    int a[]: array of ints
*    int size: size of array
* @returns:
*    void
*/
void printArray(int a[],int size){
    for(int i=0;i<size;i++){
      cout<<a[i]<<" ";
    }
}


/**
* createArray - create an array
* @params:
*    int a[]: array of ints
*    int size: size of array
* @returns:
*    int*: reference to array
*/
int* createArray(int size,int mod){
    int *A = new int[size];
    for(int i=0;i<size;i++){
      A[i] = rand() % mod;
    }
    return A;
}

int main() {
  
    // seed random number generator with time
    srand(time(0));
  
    // create a pointer for an array
    int *A;
    
    // sizes for our arrays
    int size = 25;
    int size2 = 30;
    
    // Allocate new memory and reference it with our pointer 'A'
    A = new int[size];
    
    // call functions to fill our array and to print the array
    fillArray(A,size,1000);
    printArray(A,size);
    
    // write out couple of new lines
    cout<<endl<<endl;
    
    // we use our create array function to build our array and assign
    // the returned value to a pointer 'B'.
    int *B = createArray(size2,17);
    
    // Print out B.
    printArray(B,size2);
    
}
```
