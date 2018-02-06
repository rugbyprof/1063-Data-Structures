## Linked List - Introduction to linked lists

```cpp
#include <iostream>

using namespace std;

// Create a data type that will hold our
// data and let us point to another
// node.
struct Node{
  int data;
  Node* next;
  Node(){
    data=0;
    next=NULL;
  }
};

/**
* List: A data structure of linked components that will grow and shrink
*       dynamically.
*/
class List{
  // Private section to declare data members and functions that shouldnt be access publicly
  private:
    Node* Head; // The head of our list.

  // Publicly available methods
  public:
    //Constructor (initializes anything we need to in the class)
    List(){
      Head = NULL;
    }
  
  /**
  * Insert method allows us to add a value to the front (in this implementation)
  * of he list.
  */
  void Insert(int x){
    if(Head == NULL){
      Head = new Node;
      Head->data = x;
    }else{
      Node* Temp = new Node;
      Temp->data = x;
      Temp->next = Head;
      Head = Temp;
    }
  }

  /**
  * Print out the list so we can see our handy work.
  */
  void Print(){
    Node* Temp = Head;
    
    while(Temp != NULL){
      cout<<Temp->data<<"->";
      //do cool stuff
      Temp = Temp->next;
    }
  }
};

int main() {

  List L; // L is now an Object!
  
  // Pick any number you want and the list will grow to fit it
  // as long as there is enough memory.
  for(int i=0;i<10000;i++){
    L.Insert(rand()%100);
  }
  L.Print();
  
}
```
