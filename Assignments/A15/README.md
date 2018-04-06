## Fix Linked List - Fix swap function
### Due Monday April 8<sup>th</sup> by Classtime

Using the code [HERE](https://repl.it/@rugbyprof/intLinkedlist) fix the method below so that it swaps neighbors and doesn't terminate early:

```cpp
  //assumptions are list is >= length(2);
  // swaps sets of neighbors
  void swapNeighbors(){
    node* prev = Head;
    node* temp = Head->next;
    int tempvar;
    
    while(temp->next){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
      
      prev = prev->next;
      temp = temp->next->next;
    }
  }
```
