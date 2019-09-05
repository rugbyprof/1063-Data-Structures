#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

template <typename T>
struct container{
  T* array;
  int size;
};

// represent a 2D array
// sum
// flip
// rotate
// zero out method
// swap

// definition
class TwoDarray{

  // data members

  // constructor 
  // methods


};

void printArray(int *x, int size){
  for(int i=0;i<size;i++){
    cout<<x[i]<<" ";
  }
  cout<<endl;
}

void printArray(arrayInfo h){
  printArray(h.A,h.size);
}

arrayInfo loadArray2(string filename){
  ifstream fin;
  fin.open(filename);
  
  arrayInfo AH;

  AH.size = 0;
  int x;
  
  while(!fin.eof()){
    fin>>x;
    AH.size++;
  }

  AH.A = new int[AH.size];

  for(int i=0;i<AH.size;i++){
    fin>>AH.A[i];
  }

  cout<<AH.size<<endl;
  return AH;
}

arrayInfo loadArray1(string filename){
  arrayInfo helper;
  helper.A = NULL;
  helper.size = 0;

  ifstream fin;
  fin.open("data.dat");

  fin>>helper.size;

  helper.A = new int[helper.size];  // I now have an array  
                      // of perfect size.
  for(int i=0;i<helper.size;i++){
    fin>>helper.A[i];
  }

  return helper;

}



int main() {
  
  arrayInfo AH = loadArray1("data.dat");

  //printArray(AH.A,AH.size);
  printArray(AH);
  cout<<endl<<endl;
   arrayInfo AH2 = loadArray2("data2.whocares");

   printArray(AH2);
}