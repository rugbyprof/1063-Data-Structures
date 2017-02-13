## 1063 Data Structures
***Test 1***

- Use only pencil
- Write answers on this sheet
- Write neatly
- Don't get caught up on any single question, use your time wisely.


### 1: List or Array
-----

- ***List***: Grow and shrink dynamically
- ***Array***: Give access each element directly
- ***List***: Inserting and Deleting elements is easy
- ***Array***: Doesn't have as much overhead
- ***Array***: Easier to implement


### 2: Pointers
-----

Use the following memory snapshot to answer the questions. Write in the address, the value, or error.

| Memory Snapshot |
|:-------------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/1s0J3A0J2T3i1l0p2g2b/pointer_memory.png?X-CloudApp-Visitor-Id=1094421) |

| Command           | Result |
|:-----------------:|:------:|
|  `cout<<&D`       |   4000 |
|  `cout<<&E`       | 5000 |
|  `cout<<*D`       |   42 |
|  `cout<<*F`       |   73 |
|  `cout<<F`        |   1000 |
|  `cout<<A`        |   73     |
|  `cout<<*E`       |   Error  |
| `cout<<&G`        |   7000   |
| `C = &A; cout<<*C`|   73     |
|  `*F=*D; cout<<*F`|   42     |

### 3: 2D Arrays
-----

This wasn't on the study guide, but you should know this from your program. Write a snippet of code that would generate the array below. Assume that the array is declared and filled with zero's:

```cpp
int A[5][5] = {{0}}; 
```
| 1  | 2  | 3  | 4  | 5  |
|----|----|----|----|----|
| 6  | 7  | 8  | 9  | 10 |
| 11 | 12 | 13 | 14 | 15 |
| 16 | 17 | 18 | 19 | 20 |

***Answer:***
```cpp
int i,j,k;
for (i=0,k=1;i<5;i++){
    for (j=0;j<5;j++,k++){
        A[i][j] = k;
    }
}
```


### 4: Class Syntax
-----

Write a class definition for a class called CharManip. It doesn’t have any private members. It will have 4 member functions (just write the class definitions, not all the code for the functions):

1. ***UpperCase*** (changes all the characters in a character array from lower to uppercase.)
1. ***LowerCase*** (changes all the characters in a character array from upper to lowercase)
1. ***RetInt*** (returns the ascii (integer) value of a single character)
1. ***Reverse*** (returns the character array reversed)

***Answer:***
```cpp
class CharManip{
    CharManip();
    void UpperCase(char*);
    void LowerCase(char*);
    int RetInt(char);
    char* Reverse(char*);
};
```

### 5: List Function
-----

Write a function that receives a `Head` Node pointer and returns `True` if each of the values in the list is even and `Odd` otherwise.

***Answer:***
```cpp
bool Func(Node *head){
    while(head){
        if(head->data % 2 == 1){
            return false;
        }
        head = head->next;
    }
    return true;
}
```

### 6: List Creation
-----

Create an entirely new linked list from the following commands (remember it may not turn out perfect):

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
Node* Temp = new Node;
Temp->Data = 99;
Temp->Next = nHead;
Nhead = Temp;
```

***Answer:***

![](https://d3vv6lp55qjaqc.cloudfront.net/items/0W2v052p0C3k39031u2Z/list_create.png?X-CloudApp-Visitor-Id=1094421)


```
          nHead               PreviousNode              CurrentNode           Temp
```


### 7: List Manipulation
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
while(CurPtr->Data < 32){
    CurPtr=CurPtr->Next;
}
head=CurPtr;
```
***Answer:***

![](https://d3vv6lp55qjaqc.cloudfront.net/items/3L0R0E45211h0s3j3A2a/solution7a.png?X-CloudApp-Visitor-Id=1094421)

-----

Write an updated linked list after the following commands get executed:

```cpp
CurPtr = head;
while(CurPtr->next != NULL){
    if(CurPtr->data == 42){
        Node* Temp = CurPtr;
        CurPtr = CurPtr->next;
        delete Temp; 
    }
    CurPtr=CurPtr->next;
}
```
***Answer:***

![](https://d3vv6lp55qjaqc.cloudfront.net/items/2G3Z0e2z1V2a2b1W1M36/delete_node.png?X-CloudApp-Visitor-Id=1094421)

