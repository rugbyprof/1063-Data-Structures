#include <iostream>
#include <fstream>
#include <string>

#include "DBList.h"

using namespace std;



int main()
{
  srand(93487);
  DBList List1;
  string a;

  int quit = 20;

  ifstream fin("animals.txt");

  while (!fin.eof())
  {
    fin >> a;
    //List1.PriorityInsert(a);
    //List1.Print(5);
    List1.InsertRear(a);
    cout << a << endl;
    quit--;
    // if(!quit){
    //   break;
    // }
  }

  List1.Delete("wallaby");
  List1.Delete("yak");
  List1.Print();

  cout << endl;
}