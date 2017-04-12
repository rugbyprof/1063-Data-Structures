#include <iostream>
#include <string>

using namespace std;

class Search{
private:
  int *Data;                        //array of data to be searched
  string Direction;                 //direction to sort items 
  int Size;                         //size of my array
  int Mod_val;                      //modulo value to limit int size
  
  void Sorted();
  bool Exists(int);
  void Unique_items();
public:
  Search(int,int,string);
  int BinarySearch(int);
  int LinearSearch(int);
};
