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
*         List()                    // constructor to initialize 
*   bool  Empty()                   // Is the list empty? (head == NULL)
*   void  Push(string word)         // Pushes word to front of list
*   void  PushBack(string word)     // Pushes word to end of list
*   void  Print()                   // Prints entire list
*   void  PrintRear()               // Prints value at rear of list
*/
class List{
private:
  Node* Top;
  Node* Rear;
  int listSize;
  
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
    if(Empty()){
      return "error!";
    }
    string word;
    
    Node* temp = Top;
    word = Top->word;
    
    Top = Top->next;
    
    delete temp;
    
    return word;
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
  
  void PrintRear(){
    cout<<Rear->word<<endl;
  }
  
  void Print(){
    Node* temp = Top;
    while(Top != NULL){
      cout<<Top->word<<" ";
      Top = Top->next;
    }
  }
 
};

int main() {
  List L1;
  List L2;
  string word;
  char ch;
  string sch="";
  
  ifstream fin;
 
  fin.open("animals.txt");
  
  while(!fin.eof()){
    fin>>word;
    L1.Push(word);
    L2.PushBack(word);
  }
  
  L1.Print();
  cout<<endl;
  L2.Print();
  
}
