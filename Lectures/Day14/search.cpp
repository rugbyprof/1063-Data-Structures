#include <iostream>
#include <string>
#include "search.h"

using namespace std;

Search::Search(int mod_val,int size=0,string direction="Ascending"){
  if(size > 0){
    Size = size;
  }else{
    Size = 1024;
  }
  Direction = direction;
  Data = new int [Size];
  Mod_val = mod_val;
  Unique_items();
  cout<<Size<<endl;
}


void Search::PrintData(){
  for(int i=0;i<Size;i++){
    cout<<Data[i]<<" ";
  }
  cout<<endl;
}
/**
* @FunctionName: BinarySearch
* @Description: 
*     Implementation of a binary search on an array of positive integers
* @Params:
*     int  key  - key to search for
* @Returns: 
*    int - positive value = index / negative value = not found
*/
int Search::BinarySearch(int key){
  int left = 0;
  int right = Size-1;
  int middle = (left + right) / 2;
  int num_comparisons = 0;
  
  bool found = false;
  
  
  while(1){
    num_comparisons++;
    if(Data[middle] == key){
      cout<<"Comparisons: "<<num_comparisons<<endl;
      return middle;
    }else if(middle == left || middle == right){
      return -1;
    }else{
      if(key < Data[middle]){
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
* @FunctionName: LinearSearch
* @Description: 
*     Implementation of a linear search on an array of positive integers
* @Params:
*     int  key  - key to search for
* @Returns: 
*    int - positive value = index / negative value = not found
*/
int Search::LinearSearch(int key){
  int num_comparisons = 0;
  for(int i=0;i<Size;i++){
    num_comparisons++;
    if(Data[i] == key){
      cout<<"Comparisons: "<<num_comparisons<<endl;
      return i;
    }
  }
  return -1;
}


/**
* @FunctionName: Sorted
* @Description: 
*     Sorts an array of integers in ascending or descending order
* @Params:
*    none
* @Returns:
*    void
*/
void Search::Sorted(){
  int val  = 0;
  int index = 0;
  int temp = 0;
  
  for(int j=0;j<Size;j++){
    val = Data[j];
    index = j;
    for(int i =j;i<Size;i++){
      if(Direction == "desc"){
        if (Data[i] > val) {
          val = Data[i];
          index = i;
        }
      }else{
        if (Data[i] < val) {
          val = Data[i];
          index = i;
        }
      }
    }
    temp = Data[j];
    Data[j] = val;
    Data[index] = temp;
  }
}


/**
* @FunctionName: Unique_items
* @Description: 
*     Generates an array of unique integers then sorts it.
* @Params:
*    none
* @Returns:
*    void
*/
void Search::Unique_items(){
  
  int r=0;
  
  for(int i=0;i<Size;i++){
    Data[i] = 0;
  }
  
  int i=0;
  while(i<Size){
    r = rand() % Mod_val;
    if(!Exists(r)){
        Data[i++] = r;
    }
  }
  
  Sorted();
  
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
bool Search::Exists(int key){
  for(int i=0;i<Size;i++){
    if(Data[i] == key){
      return true;
    }
  }
  return false;
}
