#include <iostream>
#include <fstream>

using namespace std;

struct wordNode{
  string word;
  int count;
};



int main() {

  ifstream fin;             // create handle for input file
  string word = "";         // hold word from file
  wordNode wordArray[1000]; // array of structs to hold words and thier counts
  int wordCount = 0;        // number of words currently in the wordArray
  bool found = false;       // flag to indicate word found
  
  //initialize wordArray
  for(int i=0;i<1000;i++){
    wordArray[i].word = "";
    wordArray[i].count = 0;   
  }
  
  // open our file of words for reading
  fin.open("baby_words.txt");
  
  //loop through input file until "end of file"
  while(!fin.eof()){  
    
    // Read in a word
    fin>>word;
    
    //empty array automatically gets the word
    if(wordCount == 0){
      wordArray[0].word = word;
      wordArray[0].count++;
      wordCount++;
    }else{
      //find the word if it exists
      
      found = false;  //set flag indicate have not found word
      
      //Loop "wordCount" times (wordCount == number of words currently in array)
      for(int i=0;i<wordCount;i++){
        
        // if we find a match in the array
        // we increment the word count 
        // and we set "found" to true
        if(wordArray[i].word == word){
          wordArray[i].count++;
          found = true;
        }
      }
      
      //If we have NOT found this word in the array
      // add it to the end!
      if(!found){
        wordArray[wordCount].word = word;
        wordArray[wordCount].count = 1;
        wordCount++;
      }
    }
  }
 
  //Print out all the word counts
  for(int i=0;i<wordCount;i++){
    cout<<wordArray[i].word<<" "<<wordArray[i].count<<endl;
  }
  
}
