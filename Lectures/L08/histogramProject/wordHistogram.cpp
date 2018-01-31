#include <iostream>
#include <fstream>
#include <string>

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

class wordHistogram{
  private:
    ifstream fin;   //declare file resource
    int size;
    wordNode *wordArray;
    string *words;


  public:
    wordHistogram(){
      size = 4000;
      words = new string[size];       //holds all words
      wordArray = new wordNode[size]; //holds words with counts
      wordNode L;
    }
    
    //reads words from file into array
    void readFile(string filename){
      string word;
      fin.open(filename);
      
      int i = 0;
      while(!fin.eof()){
        fin>>word;
        words[i] = word;
        i++;
      }
      fin.close();
    }
  
    // actually counts the occurences of the words
    void countWords(){
      int wordCount=0;
      bool found = false;
      
      for(int i=0;i<size;i++){
        if(wordCount == 0){
          wordArray[0].word = words[i];
          wordArray[0].count++;
          wordCount++;
          //find the word if it exists
        }else{
          found = false;
          for(int i=0;i<wordCount;i++){
            if(wordArray[i].word == words[i]){
              wordArray[i].count++;
              found = true;
            }
          }
          if(!found){
            wordArray[wordCount].word = words[i];
            wordArray[wordCount].count=1;
            wordCount++;
          }
        }
      }
    }
    
    wordNode Max(){
      int index = 0;
      int maxCount = 0;
      for(int i=0;i<size;i++){
          if(wordArray[i].count > maxCount){
            maxCount = wordArray[i].count;
            index = i;
          }
      }
      return wordArray[index];
    }

};

