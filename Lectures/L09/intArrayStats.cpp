#include <iostream>
#include "intArrayStats.h"

using namespace std;


intArrayStats::intArrayStats(){
  A = new int[100];
  Size = 100;
}

intArrayStats::intArrayStats(int size){
  A = new int[size];
  Size = 100;
}

intArrayStats::intArrayStats(int *inArray ,int size){
  A = inArray;
  Size = size;
}

int intArrayStats::Mode(){
  int max=0;
  int count=0;
  int num=0;
  
  
  for(int i=0;i<Size;i++){
    count=0;
    for(int j=0;j<Size;j++){
      if(A[i]==A[j]){
        count++;
      }
    }
    if(count>max){
      max=count;
      num = A[i];
    }
    cout<<"Count:"<<count<<" Num:"<<A[i]<<endl;
  }
  
  cout<<"Max:"<<max<<" Num:"<<num<<endl;
  
  return 0;
}

double intArrayStats::Average(){
  double avg;
  //calculate avg here
  return avg;
}

int intArrayStats::Max(){
  int max;
  // do stuff
  return max;
}

int intArrayStats::Min(){
  int min;
  // do stuff
  return min;
}