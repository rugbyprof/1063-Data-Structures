#include <iostream>
#include <fstream>
#include "wordHistogram.cpp"
#include <string>

using namespace std;


int main() {
  wordHistogram H;
  wordNode biggest;
  H.readFile("words.txt");
  H.countWords();
  biggest = H.Max();
  
  cout<<biggest.word<<":"<<biggest.count<<endl;
}
