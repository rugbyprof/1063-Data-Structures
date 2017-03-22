#CS 1063 Program 3

###Infix Calculator
***Due: 10 Mar 2016***

### Overview
You are going to implement a simple calculator. 

- **Your inputs are:**

>- String infix. (defined as char[ ] or string, however you see fit)
>- Example:`(4+7)-7*(3+9)`
>- ~~The expression will be read from the command line (NOT using cin), but passed as an argument to the program (argc/argv).~~
>- You CAN use cin.
>- For example: **`eval (4+7)-7*(3+9)`** (enter) would print the answer to the expression.

***CORRECTION***

- Read in the expression with NO spaces like this: `(3+4)*9-(3+4)*8`

- **Your output is:**

>A file containing: the expression that is evaluated, the postfix conversion, and the answer. You will open the file for appending, so that every expression from the command line will be saved at the end of the file, and not overwrite the previous expression and answer. 

Example:

| infix             | postfix                   | ans |
|:------------------|:--------------------------|-----|
| `(6+2) * 5 – 8 / 4` | `6 2 + 5 * 8 4 / -`     | 38  |
| `2+3*4+5-6`	        | `234*+5+6-`	        | 13  |


### Requirements:

Your calculator is required to do the following operations (minimum): **`+, -, *, / , ^ %`**
	

#### Algorithm to convert from Infix notation to Postfix notation
- Data structures used:
    - Stack
    - Queue
- Input:
    - `string` infix expression;
    - Integers are single digits only.
- Output:
    - `Queue` postfix;

#### Algorithm:
```
    1.	Push a left parenthesis ‘(‘ onto the stack;
    2.	Append a right parenthesis ‘)’ to the end of infix.
    3.	While the stack is not empty, read infix from left to right and do the following:
        a. If the current character in infix is a white space, simply ignore it.
        b. If the current character in infix is a digit, copy it to the next element of postfix.
        c. If the current character in infix is a left parenthesis, push it onto the stack.
        d. If the current character in infix is an operator,
            • Pop operators (if there are any) at the top of the stack while they have equal or higher 
	      precedence than the current operator, and insert the popped operators in postfix.
            • Push the current character in infix onto the stack.
        e. If the current character in infix is a right parenthesis,
            • Pop operators from the top of the stack and insert them in postfix until a left parenthesis 
	      is at the top of the stack.
            • Pop (and discard) the left parenthesis from the stack.
```

The following arithmetic operations are allowed in an expression: **`+, –, *, / ^ % `**

#### Example:
| Infix string       | Postfix string      | Value |
|:-------------------|:--------------------|-------|
| `(6+2) * 5 – 8 / 4` |	`6 2 + 5 * 8 4 / -` |38  |
| `2+3*4+5-6`	      |  `234*+5+6-`	    | 13 |

Notice that parenthesis are not needed in the postfix string.

#### Algorithm to evaluate a Postfix expression

- Data structures used:
    - Stack
    - Queue
- Input:
    - Queue containing a Postfix expression;
- Output:
    - Evaluated expression.

#### Algorithm:
```
1. While the Queue is not empty, Dequeue (Pop) a character from the Queue.
    a. If the character is a digit:
            Push its integer value onto the stack (the integer value of a digit 
	    character is its ASCII value minus the ASCII value of zero).
    b. Otherwise, if the character is an operator (one of +, –, *, / ^ %),
        • Pop the two top elements off the stack into variables x and y.
        • Calculate y operator x.
        • Push the result of the calculation onto the stack.
2. When the Queue is empty, the value remaining on the Stack is the result of the 
   postfix expression.
```
### Deliverables

- Place your code in a folder called **`program_3`** in your **`assignments`** folder.
- There should be a `cpp` file called `calculator.cpp`
- I will compile your code, and run it on my machine. 
- If the folders or files are not named correctly multiply your program grade by **`.5`**.
- Have your main program read in a file called **`exp.txt`** that will have the number of expressions to be read on the top line, and then one expression per line with NO spaces within each expression:

```
7
1+2+3
(1+1+1+1+1-1-1-1)*2
2+4+2/2
(2+4+2)/2
(3*2)/(3*2)+4
((3*2)/(3*2)+4) % 3
2+2^2
```
- Your program should print out the expression along with the answers:

```
1+2+3 = 6
(1+1+1+1+1-1-1-1)*2 = 4
2+4+2/2 = 7
(2+4+2)/2 = 4
(3*2)/(3*2)+4 = 5
((3*2)/(3*2)+4) % 3 = 2
2+2^2 = 6
```
- I will evaluate your code based on the answers printed.
