#include <iostream>
#include <ctime>
using namespace std;


void fillArray(int a[],int size,int mod){
    for(int i=0;i<size;i++){
      a[i] = rand()%mod;
    }
}

void printArray(int a[],int size){
    for(int i=0;i<size;i++){
      cout<<a[i]<<" ";
    }
}

int* createArray(int size,int mod){
    int *A = new int[size];
    for(int i=0;i<size;i++){
      A[i] = rand() % mod;
    }
    return A;
}

int main() {
  
    srand(time(0));
  
    int *A;
    
    int size = 25;
    int size2 = 30;
    
    A = new int[size];
    
    fillArray(A,size,1000);
    printArray(A,size);
    
    cout<<endl<<endl;
    
    int *B = createArray(size2,17);
    
    printArray(B,size2);
    
}
