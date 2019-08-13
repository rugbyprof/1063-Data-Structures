#include <iostream>
#include <fstream>

using namespace std;

struct wordNode{
  string word;
  int count;
  
  //constructor
  wordNode(){
    word = "";
    count = 0;
  }
};


wordNode find_max(wordNode* wordArray,int size){
  wordNode largest;
  int max = wordArray[0].count;
  int index = 0;
  
  for(int i=1;i<size;i++){
    if(wordArray[i].count > max){
      max = wordArray[i].count;
      index = i;
    }
  }
  
  return wordArray[index];
}

void readFile(string filename,wordNode wordArray[]){
  ifstream fin;
  fin.open(filename);
  string word;
  
  int i = 0;
  while(!fin.eof()){
    fin>>word;
    wordArray[i].word = word;
    i++;
  }
  fin.close();
}

int main() {

  ifstream fin;
  string word = "";
  wordNode wordArray[1000];
  int index=0;
  int wordCount = 0;
  bool found = false;
  wordNode L;
  
  readFile("words.txt",wordArray);
  
  for(int i=0;i<1000;i++){
    cout<<wordArray[i].word<<endl;
  }
  
  exit(0);
  
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
        wordArray[wordCount].count=1;
        wordCount++;
      }
    }
  }
  
  
  //initialize wordArray
  for(int i=0;i<wordCount;i++){
    cout<<wordArray[i].word<<" "<<wordArray[i].count<<endl;
  }
  
  L = find_max(wordArray,1000);
  
  cout<<L.word<<":"<<L.count<<endl;
  

  
}