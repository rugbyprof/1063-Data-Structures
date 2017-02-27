## Homework 3
**Due: Mar 1 2017 by classtime.**


### Overview
Given the code from class in [array_based_circ_q.cpp](./array_based_circ_q.cpp) fix the print method (as seen below) so that 
it prints out the `Queue` correctly. The current problem is that when the `Queue` is ***full*** it prints nothing because 
***Front == Rear***. Fix the [Loop Invariant](https://en.wikipedia.org/wiki/Loop_invariant) so that the `Queue` prints correctly
regardless of its contents.

```cpp
/**
* @Homework: Homework-3
* @Author: Your Name 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: DD MM YYYY
*/

/**
* @FunctionName: Print
* @Description: 
*     You describe your fix here
* @Params:
*    NONE
* @Returns:
*    NONE
*/
void Print(){
  //FIX ME!
  int Index = Front;

  while(Index != Rear){
    cout<<Q[Index]<<" ";
    Index = ((Index + 1) % (ArraySize));
  }
  cout<<endl;
}
```

### Deliverables

- Bring a printout of your method to class on wednesday. JUST the method and both comment blocks. (See Above Example).
- Describe your solution in the comment block above the method.
- Place your solution in your assignments folder in a file called **`homework-3.cpp`**
  
