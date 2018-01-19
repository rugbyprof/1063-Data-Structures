#include <iostream>
#include <ctime>

using namespace std;


void printArray(int A[],int size){
    for(int j=0;j<size;j++){
     cout<<A[j]<<" ";
    }
    cout<<endl;
}

void printCounts(int A[],int size){
    for(int j=0;j<size;j++){
     cout<<j<<":"<<A[j]<<endl;
    }
    cout<<endl;
}

//count a certain value, and as it counts
//it, it will replace it with a -1 (sentinel value)
//
//
int countItem(int A[],int counts[],int size){
  
  for(int j=0;j<size;j++){
     counts[A[j]]++;
  }
  
  cout<<endl;
  printCounts(counts,10);
  
  return 0;
}

int main() {
  srand(923784);
  
  //Declared some variables
  int size = 100;
  int max = 10;
  int A[100] = {0};
  int counts[10] = {0};
  
  // loaded up an array with random nums
  for(int i=0;i<size;i++){
    A[i] = rand() % max;
  }
  
  //printed out the array
  for(int i=0;i<size;i++){
    cout<<A[i]<<" ";
  }
  
  countItem(A,counts,size);
  
  
}
