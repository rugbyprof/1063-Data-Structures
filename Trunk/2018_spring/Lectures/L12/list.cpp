#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Struct to hold a word
// and pointer to next word
struct Node{
  string word;
  Node* next;
  Node(){
    word = "";
    next = NULL;
  }
  Node(string w){
    word = w;
    next = NULL;
  }
};

/**
* Class that represents a generic list with the following methods:
*         List()                    Constructor to initialize data members
*   bool  Empty()                   Is the list empty? (head == NULL)
*   void  Push(string word)         Pushes word to front of list
*   void  PushBack(string word)     Pushes word to end of list
*   void  Print()                   Prints entire list
*   void  PrintRear()               Prints value at rear of list
*/
class List{
private:
  Node* Top;      // Pointer to the first element in our list
  Node* Rear;     // Pointer to the last element in our list
  int listSize;   // listSize
  
public:
  /**
  * Function: List()
  * Description:
  *    Initializes necessary data members.
  * Params:
  *    None
  * Returns:
  *    None
  */
  List(){
    Top = Rear = NULL;
    listSize = 0;
  }
  
  /**
  * Function: Empty()
  * Description:
  *     Returns true if head == NULL
  * Params:
  *    None
  * Returns:
  *    bool [true,false]
  */
  bool Empty(){
    return (Top == NULL);
  }
  
  /**
  * Function: Pop()
  * Description:
  *     Removes the first item from the list (item pointed to by head)
  * Params:
  *    None
  * Returns:
  *    string word
  */
  string Pop(){
    
    // Cannot pop from empty list
    if(Empty()){
      return "error!";
    }
    
    string word;    // var to hold word from node
    
    Node* temp = Top; // Point a temp to front of list
    word = Top->word; // get word from front node
    
    Top = Top->next;  // move top pointer to next in list
    
    delete temp;      // delete the old top node
    
    return word;      // return the word
  }
  
  /**
  * Function: Push()
  * Description:
  *     Adds an item to the list (at the front closest to head).
  * Params:
  *    string word
  * Returns:
  *    void
  */
  void Push(string word){
    Node* temp = new Node(word);
    
    if(Top==NULL){
      //empty list easy fix
      Top = temp;
      Rear = Top;
    }else{
      //list is not empty so link it in
      temp->next = Top;
      Top = temp;
    }
  }
  
  /**
  * Function: PushBack()
  * Description:
  *     Adds an item to the list (at the end using our rear pointer).
  * Params:
  *    string word
  * Returns:
  *    void
  */
  void PushBack(string word){
    // Allocate new memory and initialize it
    Node* temp = new Node(word);
    
    if(Top==NULL){
      //empty list easy fix
      Top = temp;
      Rear = Top;
    }else{
      //list is not empty so link it in
      Rear->next = temp;
      Rear = temp;
    }
  }
  
  /**
  * Function: PrintRear()
  * Description:
  *     Totally worthless method to print last value in a list
  * Params:
  *    None
  * Returns:
  *    void
  */
  void PrintRear(){
    cout<<Rear->word<<endl;
  }
  
  /**
  * Function: PrintRear()
  * Description:
  *     A not so worthless method that makes us feel better when we see all of our 
  *     values being printed out correctly.
  * Params:
  *    None
  * Returns:
  *    void
  */
  void Print(){
    Node* temp = Top;
    while(Top != NULL){
      cout<<Top->word<<" ";
      Top = Top->next;
    }
  }
 
};

int main() {
  List L1;      // Create instance of class.
  List L2;      // Create another instance of same type.
  
  string word;  // var to hold word read in from file
  
  ifstream fin; // input file stream
  
  fin.open("animals.txt");  //open our animals file
  
  // While its not the end of our animals
  // file, keep looping
  while(!fin.eof()){
    fin>>word;          // read in a word
    L1.Push(word);      // add it to list 1 (front)
    L2.PushBack(word);  // add it to list 2 (back)
  }
  
  L1.Print(); // Print list (should print words in reverse order as read in)
  cout<<endl; 
  L2.Print(); // Print list (should print words in same order as read in)
    
}
