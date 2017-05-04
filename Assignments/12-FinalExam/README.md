## Arrays
- Write functions to do the following to a an array:
    - Sum integer values 
        - Receives array, its size, and returns the sum of the values.
    - Avg integer values
        - Receives array, its size, and returns the sum of the values.
    - Max integer
        - Receives array, its size, and returns the maximum value in the array.
    - Count occurences of a specified string in an array
        - Receives an array of words, a key to search for, and returns the number of times that key occurs in the array.


## Lists

- What is the worst case search time for a singly linked list? Discuss what advantages / disadvantages a doubly linked list would have for: (1) Searching (2) Inserting (3) Deleting

-----

- Write a c++ function the will return the largest and smallest values from any given linked list.
 - Write a function to merge two linked lists of integers that are sorted into ascending order. The result should be a third linked list that is the sorted combination of the original lists. Do not destroy the original lists. Do not assume you have a class with methods to complete this problem.
 
 ![](https://d3vv6lp55qjaqc.cloudfront.net/items/2k1B1k2J0J0L221g2I2a/Image%202017-05-03%20at%202.26.48%20PM.png?X-CloudApp-Visitor-Id=1094421)
 
 ```cpp
Node * List1; //points to List1 above
Node * List2; //points to List2 above
Node * List3; //currently points to NULL;
List3 = MergeLists(List1,List2); //function call to merge the lists.

//Your function will receive two Node*’s and return a 3rd Node* that points to your new merged list.

Node* MergeLists(Node* L1, Node* L2){


```
-----

- Write a `Count()` function that counts the number of times a given int occurs in a list.

```cpp
void main() {
    List myList;
    myList.BuildOneTwoThree(); // build {1, 2, 3}
    int count = MyList.Count(2); // returns 1 since there's 1 '2' in the list
}
/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int List::Count(int searchFor) {
// Your code



```
-----

- Write a `Remove()` function that removes the front node from a linked list. Pop takes a non-empty list, deletes the head node, and returns the head node's data. Here is how it could be used:

```cpp
void main() {
    List MyList;
    MyList.BuildOneTwoThree(); // build {1, 2, 3}
    int a = MyList.Remove (); // deletes "1" node and returns 1
    int b = MyList.Remove (); // deletes "2" node and returns 2
    int c = MyList.Remove (); // deletes "3" node and returns 3
    int len = MyList.Length(); // the list is now empty, so len == 0
}
/*
Takes a non-empty list and removes (deletes) the front node, and returns the data which was in that node.
*/
int List::Remove() {
// your code...


```

## Array Based Stacks and Queues

- More to come

## List Based Stacks and Queues

- https://github.com/rugbyprof/1063-Data-Structures/blob/master/Lectures/Day19.cpp
- More to come


