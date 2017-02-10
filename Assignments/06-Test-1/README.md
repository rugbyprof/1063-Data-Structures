Describe the pros and cons of array based structures vs list based structures.

-----

Use the following memory snapshot to answer the questions. Write in the address, the value, or error.

| Memory Snapshot |
|:-------------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/1T1N0c0E1134312B1x1H/Screen%20Shot%202017-02-10%20at%2011.23.56%20AM.png) |

-----

Write a class definition for a class called CharManip. It doesn’t have any private members. It will have 4 member functions (just write the class definitions, not all the code for the functions):

1. ***UpperCase*** (changes all the characters in a character array from lower to uppercase.)
1. ***LowerCase*** (changes all the characters in a character array from upper to lowercase)
1. ***RetInt*** (returns the ascii (integer) value of a single character)
1. ***Reverse*** (returns the character array reversed)

-----

Write the function definition for the function ***UpperCase***. Remember it’s part of CharManip. What this function does 
is Subtract 32 from each character of the character array (as long as it’s ascii value is greater than 96) to change it to 
Uppercase. The function strlen(char array) will tell how long a string is.

-----

| Linked List Example |
|:-------------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/020M2443090H3x1O0M2K/Screen%20Shot%202017-02-10%20at%2012.01.07%20PM.png) |
| For each question involving this list, assume a fresh list. |

Given: 

```cpp
struct Node{
    int Data;
    Node* Next;
};
```

Write an update linked list after the following snippet is run:

```cpp
CurPtr = head;
while(CurPtr->Data < 39){
    CurPtr=CurPtr->Next;
}
head=CurPtr;
```
-----

Write an updated linked list after the following commands get executed:

```cpp
CurPtr = head;
while(CurPtr->next != NULL){
    if(CurPtr->data == 39){
        Node* Temp = CurPtr;
        CurPtr = CurPtr->next;
        delete Temp; 
    }
    CurPtr=CurPtr->next;
}
```
-----

Write an updated linked list after the following commands get executed:

```cpp
CurPtr = head;
CurPtr = CurPtr->Next;
CurPtr=CurPtr->Next;
NextPtr=CurPtr->Next;
CurPtr->Next = NextPtr->Next;
```

-----

Write an updated linked list after the following commands get executed:

```cpp
CurPtr = head;
CurPtr = CurPtr->Next;
CurPtr=CurPtr->Next;
head=CurPtr->Next;
```

-----

Create an entirely new linked list from the following commands:

```cpp
Node * nhead;
Node * CurrentNode;
Node * PreviousNode;
CurrentNode = new Node;
nhead = CurrentNode;
CurrentNode->Next = NULL;
CurrentNode->Data = 10;
PreviousNode = CurrentNode;
CurrentNode = new Node;
CurrentNode->Next = NULL;
CurrentNode->Data = 8;
PreviousNode->Next = CurrentNode;
CurrentNode = new Node;
CurrentNode->Next = NULL;
CurrentNode->Data = 12;
PreviousNode->Next = CurrentNode;
CurrentNode = new Node;
CurrentNode->Next = NULL;
CurrentNode->Data = nhead->data+4;
PreviousNode->Next = CurrentNode;
```
-----

Given the following function prototypes, write a class definition called MovieClass that could incorporate these as methods. You will need to create a structure called MovieData that has the following information:

```
- Title                       //example: “Gone With the Wind”
- Director                    //example: “Victor Fleming”
- Year Released               //example: 1939
- Running Time (in minutes)   //example: 226
```

**Functions:**

```cpp
void PrintMoviesByReleaseYear(int year);      //prints all movies released
                                              //in specified year
void PrintMoviesByDirector(string Director);  //prints all movies directed
                                              //by director
void AddMovie(MovieData Movie);               //Adds a movie to a linked list
                                              //of movies
```
