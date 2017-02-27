# Not Done
# Stacks and Queues


An array is a ___random access___ data structure, where each element can be accessed directly and in constant time. A typical illustration of random access is a book - each page of the book can be open independently of others. Random access is critical to many algorithms, for example binary search.

A linked list is a ___sequential access___ data structure, where each element can be accesed only in particular order. A typical illustration of sequential access is a roll of paper or tape - all prior material must be unrolled in order to get to data you want.

In this note we consider a subcase of sequential data structures, so-called _limited access_ data sturctures.

## Stacks
A stack is a container of objects that are inserted and removed according to the last-in first-out (LIFO) principle. In the pushdown stacks only two operations are allowed: **push** the item into the stack, and **pop** the item out of the stack. A stack is a limited access data structure - elements can be added and removed from the stack only at the top. **push** adds an item to the top of the stack, **pop** removes the item from the top. A helpful analogy is to think of a stack of books; you can remove only the top book, also you can add a new book on the top.

A stack is a **recursive** data structure. Here is a structural definition of a Stack:
- a stack is either empty or
- it consistes of a top and the rest which is a stack

![](https://d3vv6lp55qjaqc.cloudfront.net/items/2i3o2Z3I0k1s2V033v1W/stack_representation.jpg?X-CloudApp-Visitor-Id=1094421) 

### Applications

- The simplest application of a stack is to reverse a word. You push a given word to stack - letter by letter - and then pop letters from the stack.
- Another application is an "undo" mechanism in text editors; this operation is accomplished by keeping all text changes in a stack.

|                 |                  |
|:---------------:|:-----------------|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/1X1e1x2m1O0B0a290R29/Maze_simple.svg.png?X-CloudApp-Visitor-Id=1094421)  | **Backtracking**. This is a process when you need to access the most recent data element in a series of elements. Think of a labyrinth or maze - how do you find a way from an entrance to an exit?  <br> Once you reach a dead end, you must backtrack. But backtrack to where? to the previous choice point. Therefore, at each choice point you store on a stack all possible choices. Then backtracking simply means popping a next choice from the stack. |

*   Language processing:
    *   space for parameters and local variables is created internally using a stack.
    *   compiler's syntax check for matching braces is implemented by using stack.
    *   support for recursion

### Implementation

In the standard library of classes, the data type stack is an _adapter_ class, meaning that a stack is built on top of other data structures. The underlying structure for a stack could be an array, a vector, an ArrayList, a linked list, or any other collection. Regardless of the type of the underlying data structure, a Stack must implement the same functionality. This is achieved by providing a unique interface:

<pre>public interface StackInterface<AnyType>
{
   public void push(AnyType e);

   public AnyType pop();

   public AnyType peek();

   public boolean isEmpty();
}
</pre>

</dir>

The following picture demonstrates the idea of implementation _by composition_.

<center>![](pix/stack_abstraction1.bmp)</center>

Another implementation requirement (in addition to the above interface) is that all stack operations must run in **<font color="green">constant time O(1)</font>**. Constant time means that there is some constant k such that an operation takes k nanoseconds of computational time regardless of the stack size.

#### Array-based implementation

<table bordercolor="" cellpadding="2">

<tbody>

<tr align="left">

<td>  ![](pix/array_stack.bmp)  </td>

<td>In an array-based implementation we maintain the following fields: an array A of a default size (≥ 1), the variable _top_ that refers to the top element in the stack and the _capacity_ that refers to the array size. The variable _top_ changes from -1 to `capacity - 1`. We say that a stack is empty when `top = -1`, and the stack is full when `top = capacity-1`.

In a fixed-size stack abstraction, the capacity stays unchanged, therefore when _top_ reaches _capacity_, the stack object throws an exception. See [ArrayStack.java](code/ArrayStack.java) for a complete implementation of the stack class.

In a dynamic stack abstraction when _top_ reaches _capacity_, we double up the stack size.

</td>

</tr>

</tbody>

</table>

#### Linked List-based implementation

<table bordercolor="" cellpadding="2">

<tbody>

<tr align="left">

<td>Linked List-based implementation provides the best (from the efficiency point of view) dynamic stack implementation.

See [ListStack.java](code/ListStack.java) for a complete implementation of the stack class.

</td>

<td>  ![](pix/LL-stack.bmp)  </td>

</tr>

</tbody>

</table>

## Queues

<table bordercolor="" cellpadding="2">

<tbody>

<tr align="left">

<td>A queue is a container of objects (a linear collection) that are inserted and removed according to the first-in first-out (FIFO) principle. An excellent example of a queue is a line of students in the food court of the UC. New additions to a line made to the back of the queue, while removal (or serving) happens in the front. In the queue only two operations are allowed **enqueue** and **dequeue**. Enqueue means to insert an item into the back of the queue, dequeue means removing the front item. The picture demonstrates the FIFO access.

The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.

</td>

<td>  ![](pix/queue.bmp)  </td>

</tr>

</tbody>

</table>

### Implementation

In the standard library of classes, the data type queue is an _adapter_ class, meaning that a queue is built on top of other data structures. The underlying structure for a queue could be an array, a Vector, an ArrayList, a LinkedList, or any other collection. Regardless of the type of the underlying data structure, a queue must implement the same functionality. This is achieved by providing a unique interface.

<dir>

<pre>interface QueueInterface‹AnyType>
{
   public boolean isEmpty();

   public AnyType getFront();

   public AnyType dequeue();

   public void enqueue(AnyType e);

   public void clear();
}
</pre>

</dir>

Each of the above basic operations must run at constant time O(1). The following picture demonstrates the idea of implementation by composition.

<center>![](pix/queue_abstraction1.bmp)</center>

#### Circular Queue

Given an array A of a default size (≥ 1) with two references _back_ and _front_, originally set to -1 and 0 respectively. Each time we insert (enqueue) a new item, we increase the back index; when we remove (dequeue) an item - we increase the front index. Here is a picture that illustrates the model after a few steps:

<center>![](pix/array_queue_1.bmp)</center>

As you see from the picture, the queue logically moves in the array from left to right. After several moves _back_ reaches the end, leaving no space for adding new elements

<center>![](pix/array_queue_2.bmp)</center>

However, there is a free space before the front index. We shall use that space for enqueueing new items, i.e. the next entry will be stored at index 0, then 1, until _front_. Such a model is called a **<font color="green">wrap around queue</font>** or a **<font color="green">circular queue</font>**

<center>![](pix/array_queue_3.bmp)</center>

Finally, when _back_ reaches _front_, the queue is full. There are two choices to handle a full queue:a) throw an exception; b) double the array size.

The circular queue implementation is done by using the modulo operator (denoted %), which is computed by taking the remainder of division (for example, 8%5 is 3). By using the modulo operator, we can view the queue as a circular array, where the "wrapped around" can be simulated as "back % array_size". In addition to the back and front indexes, we maintain another index: _cur_ - for counting the number of elements in a queue. Having this index simplifies a logic of implementation.

See [ArrayQueue.java](code/ArrayQueue.java) for a complete implementation of a circular queue.

## Applications

The simplest two search techniques are known as Depth-First Search(DFS) and Breadth-First Search (BFS). These two searches are described by looking at how the search tree (representing all the possible paths from the start) will be traversed.

### Deapth-First Search with a Stack

In depth-first search we go down a path until we get to a dead end; then we _backtrack_ or back up (by popping a stack) to get an alternative path.

*   Create a stack
*   Create a new choice point
*   Push the choice point onto the stack
*   while (not found and stack is not empty)
    *   Pop the stack
    *   Find all possible choices after the last one tried
    *   Push these choices onto the stack
*   Return

### Breadth-First Search with a Queue

In breadth-first search we explore all the nearest possibilities by finding all possible successors and enqueue them to a queue.

*   Create a queue
*   Create a new choice point
*   Enqueue the choice point onto the queue
*   while (not found and queue is not empty)
    *   Dequeue the queue
    *   Find all possible choices after the last one tried
    *   Enqueue these choices onto the queue
*   Return

We will see more on search techniques later in the course.

### Arithmetic Expression Evaluation

An important application of stacks is in parsing. For example, a compiler must parse arithmetic expressions written using infix notation:

<dir>

<pre>1 + ((2 + 3) * 4 + 5)*6
</pre>

</dir>

We break the problem of parsing infix expressions into two stages. First, we convert from infix to a different representation called postfix. Then we parse the postfix expression, which is a somewhat easier problem than directly parsing infix.

**Converting from Infix to Postfix.** Typically, we deal with expressions in infix notation

<dir>

<pre>2 + 5
</pre>

</dir>

where the operators (e.g. +, *) are written between the operands (e.q, 2 and 5). Writing the operators after the operands gives a postfix expression 2 and 5 are called operands, and the '+' is operator. The above arithmetic expression is called infix, since the operator is in between operands. The expression

<dir>

<pre>2 5 +
</pre>

</dir>

Writing the operators before the operands gives a prefix expression

<dir>

<pre>+2 5
</pre>

</dir>

Suppose you want to compute the cost of your shopping trip. To do so, you add a list of numbers and multiply them by the local sales tax (7.25%):

<dir>

<pre>70 + 150 * 1.0725
</pre>

</dir>

Depending on the calculator, the answer would be either 235.95 or 230.875\. To avoid this confusion we shall use a postfix notation

<dir>

<pre>70  150 + 1.0725 *
</pre>

</dir>

Postfix has the nice property that parentheses are unnecessary.

Now, we describe how to convert from infix to postfix.

1.  Read in the tokens one at a time
2.  If a token is an integer, write it into the output
3.  If a token is an operator, push it to the stack, if the stack is empty. If the stack is not empty, you pop entries with higher or equal priority and only then you push that token to the stack.
4.  If a token is a left parentheses '(', push it to the stack
5.  If a token is a right parentheses ')', you pop entries until you meet '('.
6.  When you finish reading the string, you pop up all tokens which are left there.
7.  Arithmetic precedence is in increasing order: '+', '-', '*', '/';

Example. Suppose we have an infix expression:`2+(4+3*2+1)/3`. We read the string by characters.

<dir>

<pre>'2' - send to the output.
'+' - push on the stack.
'(' - push on the stack.
'4' - send to the output.
'+' - push on the stack.
'3' - send to the output.
'*' - push on the stack.
'2' - send to the output.
</pre>

</dir>

**Evaluating a Postfix Expression.** We describe how to parse and evaluate a postfix expression.

1.  We read the tokens in one at a time.
2.  If it is an integer, push it on the stack
3.  If it is a binary operator, pop the top two elements from the stack, apply the operator, and push the result back on the stack.

Consider the following postfix expression

<dir>

<pre>5 9 3 + 4 2 * * 7 + *
</pre>

</dir>

Here is a chain of operations

<dir>

<pre>Stack Operations              Output
--------------------------------------
push(5);                        5
push(9);                        5 9
push(3);                        5 9 3
push(pop() + pop())             5 12
push(4);                        5 12 4
push(2);                        5 12 4 2
push(pop() * pop())             5 12 8
push(pop() * pop())             5 96
push(7)                         5 96 7
push(pop() + pop())             5 103
push(pop() * pop())             515
</pre>

</dir>

Note, that division is not a commutative operation, so 2/3 is not the same as 3/2.

* * *

Victor S.Adamchik, CMU, 2009
https://www.cs.cmu.edu/~adamchik/15-121/lectures/Stacks%20and%20Queues/Stacks%20and%20Queues.html
