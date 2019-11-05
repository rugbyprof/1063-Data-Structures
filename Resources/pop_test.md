```cpp
#include <iostream>

/**
* This is the basic structure that is used for our singly linked list.
*/
struct Node{
  int Data;       // Our very simple data section
  Node* Next;     // Pointer to the next node in the list
  Node(){
    Data = -1;
    Next = NULL;
  }
  Node(int x){
    Data = x;
    Next = NULL;
  }
};

using namespace std;

/**
* The definition of our List type. Remember this was done on the fly in the classroom. 
* There are more elegant solutions, but this one works just fine.
* @Methods:
*    FrontSert   - Add an item to the front of the list
*    OrderedSert - Add an item to the list maintaining ascending order
*    DeleteNode  - Given a key, find the node and delete it from the list
*    PrintList   - Print out each item in the list
*/
struct List{

    Node *Head;   // Always need a head pointer! This gives us access to the list and is not optional.
    Node *Tail;   // Tail pointers are optional, but can help in certain circumstances 
    int size;

    /**
    * Class constructor
    */
    List(){
      Head = NULL;  // Initialize our list as empty.
      size=0;
    }

    /**
    * FrontSert
    * @params:
    *    int x : value to be placed in the list
    * @returns:
    *    void
    */
    void FrontSert(int x){
      // Memorize the three lines of new node allocation
      Node *Temp = new Node(x);
      
      // If items in list already, point our new nodes next
      // to what head points to.
      if(Head){
        Temp->Next = Head;
      }

      // Update head to point to the new node.
      Head = Temp;
      size++;
    }
    
    int Length(){
      return size;
    }
    
    
    /**
    * DeleteNode
    * @params:
    *    int key : value to be found and removed from list
    * @returns:
    *    bool : true = success + key found and false = key not found.
    */
    bool DeleteNode(int key){
      // set up a traversal to find key
      Node *Curr = Head;
      Node *Prev = Head;
      
      // assume key not found
      bool success = false;
      
      // Check to see if key is the front of the list since we have to handle it slightly
      // different. Different list configurations could clean this code up.
      if(Head->Data == key){
        success = true;
        size--;
        Head = Head->Next;
        delete Curr;
      }else{
        // Key is not at head of the list, so lets traverse to find it.
        while(Curr && key != Curr->Data){
          Prev = Curr;
          Curr = Curr->Next;
        }
        
        // If Curr is not off the end of the list AND we found the key
        if(Curr && Curr->Data == key){
          success = true;
          size--;
          Prev->Next = Curr->Next;
          delete Curr;
        }
      }
      
      return success;
    }
    
    /**
    * PrintList
    * @params:
    *    void
    * @returns:
    *    void
    */
    void PrintList(){
      if(!Head){
        cout<<"Empty"<<endl;
        return;
      }else{
        // Memorize this!! This is a basic list traversal that will be a part 
        // of many a test question
        Node *Temp = Head;
        while(Temp != NULL){
          // Here we print, but we could do other things to each list node as well (like alter the contents).
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;
        }
      }
      cout<<endl;
    }
```



```cpp
    /**
    * OrderedSert
    * @params:
    *    int x : value to be placed in the list
    * @returns:
    *    void
    */
    void OrderedSert(int x){





    }

};
```

```cpp
int main() {















    
  
    return 0;
}
```