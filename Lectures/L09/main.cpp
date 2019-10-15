/**
 * Topic: BubbleSort
 * Aurhor: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: October 2019
 * Description:
 *    Shows use of a bubble sort
 */

#include <iostream>

using namespace std;

void swap1(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

//swap2(&A[j],&A[j+1]);
void swap2(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int A[],int size){
  int temp=0;
  bool swapped = false;
  for(int i=0;i<size;i++){
    swapped = false;
    for(int j=0;j<size-1-i;j++){
      if(A[j] > A[j+1]){
        //cout<<"swapping"<<endl;
        swapped = true;
        swap1(A[j],A[j+1]);
      }
    }
    if(swapped == false){
      //cout<<"breaking out"<<endl;
      break;
    }
  }
}


int main() {
  //int A[] = {3,4,6,1,2,8,7,99,65,98,12,34,56,23,89};
  int A[] = {3,4,6,11,12,18,29,31,99,40,50,61,66,71,89};
  int size = 15;
  int B[10000];

  for(int i=0;i<10000;i++){
    B[i] = rand() %10000;
  }

  BubbleSort(B,10000);

  for(int i=0;i<10000;i++){
    cout<<B[i]<<" ";
  }
}