## Test 2 - Lists, Stacks, Queues
#### Due: Thursday October 24<sup>th</sup> at 11:00 a.m.

**QUESTION 1** 
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
```
bool Find(Node* Nptr, int key);
```

---

**QUESTION 3** 

Given a list delete all the nodes on the list. 

<sub>Example function header:</sub>
```
void DeleteAll(Node* Nptr);
```

---

**QUESTION 4** 

Given a list delete, the first node, and return its value. 

<sub>Example function header:</sub>
```
int Pop(Node* Nptr);
```

---

**QUESTION 5** 

**Given:** 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test2.1.a.png">

What will the following code do the the list?

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
```
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

<center>
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.2.4.png"></center>

---
**QUESTION 10** 

- The five items: **A, B, C, D,** and **E** are pushed in a stack, one after other starting from **A**. 
- The stack is popped four items and each element is inserted in a queue. 
- The two elements are deleted from the queue and pushed back on the stack. 
- Now one item is popped from the stack. 
- The popped item is _______.

---
For questions that ask you to *use* a **Stack** and **Queue**, only use the high level functions: **Push**, **Pop**.  If I want you to implement something (like a Push function, then I'll ask you to).

---

**QUESTION 11** 

Given:
```cpp
Stack S;
Queue Q;
string word = "theworldisinyourpocket";
```

Write a code snippet to print that string out in reverse. You don't have to use both the stack and the queue, but you have to use one of them to assist you.

**MORE TO FOLLOW SOON .....**


