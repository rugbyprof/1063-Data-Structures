#include <iostream>
#include "DynArray.h"
using namespace std;

int main()
{
  DynArray arr;
  cout << arr.size() << endl;
  srand(42);
  for (int i = 0; i < 81; i++)
  {
    arr.set(i, rand() % 100);
  }
  cout << arr.size() << endl;
  for (int i = 81; i < 9501; i++)
  {
    arr.set(i, rand() % 100);
  }
  cout << arr.size() << endl;
}