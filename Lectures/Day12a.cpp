#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int bin_to_int(string bin){
  int total = 0;

  for(int j=0;j<bin.length();j++){
    total += (bin[j]-48) * pow(2,bin.length()-j-1);
  }
  
  return total;
  
}

int main() {
    string binary;
    
    binary = "101010110101";
    
    cout<<bin_to_int("1001");
    
}
