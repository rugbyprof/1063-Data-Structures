/**
* @ProgramName: Binary Search
* @Author: 1063 Team  
* @Description: 
*     This program:
*          generates a randomly populated array of integers and  
*          has an implementation of a binary search
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 6 Mar 17
*/

#include <iostream>

using namespace std;

/**
* @FunctionName: sorted
* @Description: 
*     Sorts an array of integers in ascending or descending order
* @Params:
*    int* a           - 1D array of integers
*    int size         - size of array
*    string direction - "asc" = ascending / "desc" = descending
* @Returns:
*    void
*/
void sorted(int *a,int size,string direction="desc"){
  int val  = 0;
  int index = 0;
  int temp = 0;
  
  for(int j=0;j<size;j++){
    val = a[j];
    index = j;
    for(int i =j;i<size;i++){
      if(direction == "desc"){
        if (a[i] > val) {
          val = a[i];
          index = i;
        }
      }else{
        if (a[i] < val) {
          val = a[i];
          index = i;
        }
      }
    }
    temp = a[j];
    a[j] = val;
    a[index] = temp;
  }
}

/**
* @FunctionName: exists
* @Description: 
*     Checks if value exists in array
* @Params:
*    int* data        - 1D array of integers
*    int size         - size of array
*    int key          - key to search for
* @Returns:
*    bool - true = key exists / false = not in array
*/
bool exists(int *data, int size,int key){
  for(int i=0;i<size;i++){
    if(data[i] == key){
      return true;
    }
  }
  return false;
}

/**
* @FunctionName: unique_items
* @Description: 
*     Generates an array of unique integers
* @Params:
*    int size          - size of data set to create
*    string direction  - "asc" = ascending / "desc" = descending
* @Returns:
*    int* - pointer to newly allocated array
*/
int* unique_items(int size,string direction){
  
  int *data;
  data = new int[size];
  
  int r=0;
  
  for(int i=0;i<size;i++){
    data[i] = 0;
  }
  
  int i=0;
  while(i<size){
    r = rand()%1000;
    if(!exists(data,size,r)){
        data[i++] = r;
    }
  }
  
  sorted(data,size,direction);
  
  return data;
}

/**
* @FunctionName: BinarySearch
* @Description: 
*     Implementation of a binary search on an array of values
* @Params:
*     int* data - data array
*     int  key  - key to search for
* @Returns: 
*    int - positive value = index / negative value = not found
*/
int BinarySearch(int* data,int key,int size){
  int left = 0;
  int right = size-1;
  int middle = (left + right) / 2;
  
  bool found = false;
  
  
  while(!found){
    if(data[middle] == key){
      return middle;
    }else if(middle == left || middle == right){
      found == false;
    }else{
      if(key < data[middle]){
        right = middle;
      }else{
        left = middle;
      }
      middle = (left + right) / 2;
    }
    
  }
  
  return -1;
}

/**
* @FunctionName: main
* @Description: 
*     Driver for program that creates an array of unique integers and 
*     then performs a binary search on that array
* @Params:
*     NULL
* @Returns:
*    int - 0 = all ok
*/
int main(){
  srand(8769);
  int size = 100;
  string direction = "asc";
  
  int *data = unique_items(size,direction);
  
  for(int i=0;i<size;i++){
    cout<<i<<"["<<data[i]<<"]"<<endl;
  }
  
  int found = BinarySearch(data,1001,size);
  cout<<"Found: "<<found<<endl;

  return 0;
}
