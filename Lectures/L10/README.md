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
  * of the list. Some lists may want insert to put a value at the end of the list
  * or some may want the value to be inserted in order.
  */
  void Insert(int x){
    // if the list is empty
    if(Head == NULL){
      Head = new Node;          // allocate new memory
      Head->data = x;           // put our value into the node
                                // thats it for an empty list!
    }else{
      // We need to add the value in front of the old head

      Node* Temp = new Node;    // allocate new memory
      Temp->data = x;           // put our value into the temp node
      Temp->next = Head;        // point the temp node to the head
      Head = Temp;              // re-assign the head to point to temp
    }
  }

  /**
  * Print out the list so we can see our handy work.
  */
  void Print(){
    Node* Temp = Head;
    
    // Typical list iteration (visiting each node so we can do stuff).
    while(Temp != NULL){
      cout<<Temp->data<<"->"; // do whatever here (print in this case)
      //do cool stuff
      Temp = Temp->next;      // go to the next node
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
