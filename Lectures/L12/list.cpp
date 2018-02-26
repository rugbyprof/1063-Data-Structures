#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

class List{
private:
  Node* Top;
  Node* Rear;
  int listSize;
  
public:
  List(){
    Top = Rear = NULL;
    listSize = 0;
  }
  
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
  
  bool Empty(){
    return (Top == NULL);
  }
  
};

int main() {
  List L1;
  List L2;
  string word;
  char ch;
  string sch="";
  
  ifstream fin;
  
  fin.open("notPalindrome.txt");
  
  fin.get(ch);
  while(!fin.eof()){
    sch += ch;
    L1.Push(sch);
    sch = "";
    fin.get(ch);
  }
  
  L1.Print();
  
  // fin.open("animals.txt");
  
  // while(!fin.eof()){
  //   fin>>word;
  //   //cout<<word<<" ";
  //   L1.Push(word);
  //   L2.PushBack(word);
  // }
  
  // L1.Print();
  // cout<<endl;
  // L2.Print();
  
}
