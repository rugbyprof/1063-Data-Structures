#include <iostream>
#include <fstream>

using namespace std;

struct wordNode{
  string word;
  int count;
};


int main() {

  ifstream fin;
  string word = "";
  wordNode wordArray[1000];
  int index=0;
  int wordCount = 0;
  bool found = false;
  
  //initialize wordArray
  for(int i=0;i<1000;i++){
    wordArray[i].word = "";
    wordArray[i].count = 0;   
  }
  
  
  fin.open("baby_words.txt");
  
  //loop through input file 
  index=0;
  while(!fin.eof()){  
    fin>>word;
    //empty array auto gets the word
    if(wordCount == 0){
      wordArray[0].word = word;
      wordArray[0].count++;
      wordCount++;
      //find the word if it exists
    }else{
      found = false;
      for(int i=0;i<wordCount;i++){
        if(wordArray[i].word == word){
          wordArray[i].count++;
          found = true;
        }
      }
      if(!found){
        wordArray[wordCount].word = word;
        wordArray[wordCount].count;
        wordCount++;
      }
    }
  }
  
  
  //initialize wordArray
  for(int i=0;i<wordCount;i++){
    cout<<wordArray[i].word<<" "<<wordArray[i].count<<endl;
  }
  
  
  

  
}
