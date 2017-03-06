#include <iostream>


using namespace std;

void kinda_sort(int *a,int size){
  int max  = 0;
  int index = 0;
  int temp = 0;
  
  for(int j=0;j<size;j++){
    max = a[j];
    index = j;
    for(int i =j;i<size;i++){
      if (a[i] > max) {
        max = a[i];
        index = i;
      }
    }
    temp = a[j];
    a[j] = max;
    a[index] = temp;
  }
}

bool exists(int *a, int r,int size){
  
}

void unique_items(int *a, int size){
  int r =9;
  
  for(int i=0;i<size;i++){
    a[i] = 0;
  }
  
  for(int i=0;i<size;i++){
    r = rand()%1000;
    if(!exists(a,r,size))
        a[i] = r;
  }
  
  kinda_sort(data,100);
}

int main(){
  srand(8769);
  
  int *data;
  data = new int[100];
  

  
  for(int i=0;i<100;i++){
    cout<<data[i]<<endl;
  }
  
  return 0;
}
