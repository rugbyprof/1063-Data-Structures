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
#include <string>
#include "search.h"

using namespace std;


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
  
  Search S(4096,2048,"Ascending");
  S.PrintData();
  cout<<S.BinarySearch(3443)<<endl;
  cout<<S.LinearSearch(3443)<<endl;
  


  return 0;
}
