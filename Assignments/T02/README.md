## Test 2 - Lists, Stacks, Queues
#### Due: Thursday October 24<sup>th</sup> at 11:00 a.m.

**QUESTION 1** 

Unless specified, assume this structure for all list nodes.
```cpp  
struct Node{  
    int data;  
    Node* next;  
}
```

Write a constructor for the **struct** above.

---

**QUESTION 2** 

Given a list, and a key to search for, return true if the key is in the list, false otherwise.  

<sub>Example function header:</sub>
```cpp
bool Find(Node* Nptr, int key);
```

---

**QUESTION 3** 

Given a list delete all the nodes on the list. 

<sub>Example function header:</sub>
```cpp
void DeleteAll(Node* Nptr);
```

---

**QUESTION 4** 

Given a list: delete the first node and return its value. 

<sub>Example function header:</sub>
```cpp
int Pop(Node* Nptr);
```

---

**QUESTION 5** 

**Given:** 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test2.1.a.png">

What will the following code do to the list?

```cpp
Head->next->next->data = Head->next->next->next->data/3;
Head->data = Head->data + 2;
```

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.2.2.png">

---
**QUESTION 6** 

Use code similar to the previous question to re-arrange the nodes into proper order (adjust the pointers). Do not try to "loop" or "traverse" the list when fixing.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.2.3.png">

---

**QUESTION 7** 

Given a list delete, write a function to delete a node from the list. Your node looks like:
```cpp  
struct Node{  
    string data;  
    Node* next;  
}
```

<sub>Example function header:</sub>
```cpp
void Delete(Node* Nptr, string key);
```

---

**QUESTION 8** 

- The seven elements **A, B, C, D, E, F** and **G** are pushed onto a stack in reverse order, (*i.e., starting from **G***). 
- The stack is popped five times and each element is inserted into a queue.
- Two elements are deleted from the queue and pushed back onto the stack. 
- Now, one element is popped from the stack. 
- The popped item is ________.

---

**QUESTION 9** 

If the sequence of operations:

***push (1), push (2), pop, push (1), push (2), pop, pop, pop, push (2), pop*** 

are performed on a stack, what are the sequence of popped out values:

<center><img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.2.4.png"></center>

---
**QUESTION 10** 

- The five items: **A, B, C, D,** and **E** are pushed in a stack, one after other starting from **A**. 
- The stack is popped four items and each element is inserted in a queue. 
- The two elements are deleted from the queue and pushed back on the stack. 
- Now one item is popped from the stack. 
- The popped item is _______.

---
For questions that ask you to *use* a **Stack** and **Queue**, only use the high level functions: **Push**, **Pop**.  If I want you to implement something (like a Push function, then I'll ask you to).

**QUESTION 11** 

Given:
```cpp
Stack S;
Queue Q;
string word = "theworldisinyourpocket";
```

Write a code snippet to print that string out in reverse. You don't have to use both the stack and the queue, but you have to use one of them to assist you.


---

**QUESTION 12** 

```cpp
int [] values = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
Stack s = new Stack;
for (int 1 = 0; i < values.length; i++){
    s.push( values[ i ] );
}

int n = 25;

for (int i = 0; i < 4; i++){
    n += s.pop( );
}
for (int i = 0; i < 2; i++)
{
    n -= s.pop( );
}
cout<<n<<endl;
```

---


**QUESTION 13** 

What is the difference between array based implementations vs list based. List pros and cons of each.


---


**QUESTION 14** 

Write a code snippet that dynamically allocate an array of integers that has 500 elements. Then load it with zeros.


---


**QUESTION 15**

Trace the following code. User input is the following sequence of numbers:

***4,  5,  67,  89,  21,  3,  0,  76***

```cpp

Queue intQ;

int i;

cin >> i;

while (i != 0) {
    if (i < 35) {
        intQ.Push(i);
    }
    cin >> i;
}

while (!intQ.IsEmpty()) {
    i = intQ.Pop();
    cout << i << endl;
}

```

---

**QUESTION 16** 

Finish this `Push` method:

```cpp
void ArrayStack::Push(int x){


}
```


---


**QUESTION 17**


Finish this `Push` method:

```cpp
void ListStack::Push(string x){


}
```

---


**QUESTION 18**

Finish this `Pop` method:

```cpp
string ListQueue::Pop(){


}
```

---


**QUESTION 19**

Finish this `Pop` method:

```cpp
int ArrayQueue::Pop(){



}
```

---


**QUESTION 20**

So we've been talking about list based stacks and queues as well as array based stacks and queues. Which implementations of each (4 different total) need methods for `isEmpty()` or `isFull()` ??
