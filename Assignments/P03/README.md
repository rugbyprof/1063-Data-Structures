## Program 3 - Arbitrary Precision Math
#### Due: November 14<sup>th</sup>

#### What is arbitrary precision math? 

Also called bignum arithmetic, multiple-precision arithmetic, or sometimes infinite-precision arithmetic, indicates that calculations are performed on numbers whose digits of precision are limited only by the available memory of the host system. This contrasts with the faster fixed-precision arithmetic found in most arithmetic logic unit (ALU) hardware, which typically offers between 8 and 64 bits of precision.

<sup>source: https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic </sup>

Yaaaaawwwn....  Did you nod off? I did. Ok, just for a second.

This is actually a pretty cool idea. Each number is ultimately stored in a register, and registers are of a fixed size. Integers are only 4 bytes (32 bits), which limits the size of the integer to 2<sup>32</sup>-1 What does this mean? Read about this on [Stack Overflow](https://stackoverflow.com/questions/94591/what-is-the-maximum-value-for-an-int32). Yes, this post went Nerd real fast, but the fact that so many individuals obsess over some power of 2 implies a lot! When I started reading the post I was reminded that I'm not the smartest person in the room, but I love the fact that this whole thread went off the rails like it did!!

The bottom line is that there are times when doing arithmetic with big numbers can be somewhat limiting. Simply 2^<sup>32</sup> or even 2^<sup>64</sup> isn't big enough! Depending on the computer architecture your working with, you may have access to 8 byte number sizes using `long` or `double`, but depending on the precision you need, this still may not be enough!! (http://floating-point-gui.de/formats/fp/). 

Honestly, for us, 2<sup>32</sup> **almost always is big enough**. But we wouldn't be computer scientists if we settled for petty `primitive data types` like `int`, `float`, and `double`. Lets make our own!

### Overview

Lets limit (for now) our problem to integers. And if we want to add: 

**`42304820394820934820394802394823094802394809 to 2318283123123893786234671923682346734`**

what data type do we use?? Int? Double? Ha! 2<sup>31</sup> = 2147483647 not nearly close enough! 2<sup>63</sup> = 9223372036854775808, still not close enough. I guess we need to solve this ourselves (note: `sign bit`, that's why `31` and not `32` and `63` and not `64`). In the example below, you can see that the far left bit (8<sup>th</sup> bit) is needed to make a number positive (0) or negative (1).

#### Sign Bit

<img src="https://cl.ly/pg9C/signbit.png" width="300">


#### Adding Numbers

Looking at the image below, we see 3 doubly linked lists with the bottom list being the result. There are different ways to approach adding linked lists together but we are going to store our numbers with the "most significant" digits toward the head and "least significant" toward the tail of our list. Since we have a doubley linked list, we can load the digits from head to tail as we read them from an input file, and them process them from tail to head as we add them together. 


|     |     |
|:-----|-----:|
| 6 + 3 = 9 (no carry) | <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.1.png" height="150"> |
| 7 + 2 + carry = 9 (no carry)  |<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.2.png" height="150"> |
| 9 + 9 + carry = 8 (carry 1) |<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.3.png" height="150"> |
| 5 + 7 + carry = 3 (carry 1) |<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.4.png" height="150"> |
| 9 + carry = 0 (carry 1) |<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.5.png" height="150"> |
| Prepend carry in new node. |<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.6.png" height="150"> |


# Requirements


- Write a program that uses a doubly linked list that will have the ability to **add**, **subtract**, and **multiply** two arbitrarily long integers positive integers. 
- The number will be stored in a file like the example below:

```
3
+
12112313121234132412312132414
13241414124124123412341324132
-
5858584774657857855674746735463
474657474657456745674567467
*
9993939393938383933883
3783783783783873783
```
- Where the first number is how many problems you will read in.
- Then there will be 3 reads for each problem:
    - The operator to tell you what operation to run. Use a switch statement to call the appropriate function.
    - A string for the first number.
    - A string for the second number.
- Read each number into a doubly linked list
- Perform the operation on the lists storing the result in a third doubly linked list.
- Write your answer out to an output file. 

**Output**

```
Your Name
Program 3
Arbitrary Precision Math

Operation 1: Addition
Answer:

982098271409179713241324 ... 1324071234

Operation 2: Multiplication
Answer:

928374928374987324928374 ... 02938402938423

ETC...
```

### Organizing Your Problem Solving

- In this folder there is a `BigNum` header file along with a working `Doubley Linked List`.
- The Doubley Linked List has almost all of the implementation you need for this assignment to help you correctly implement the `BigNum` class. 
- I know you don't think it does, but it does. 
- Actually implementing the operations (Add, Sub, and Mul) are not the biggest part of the project, getting the groundwork layed with processing the data should come first.

#### Read The Input and Start Outfile
- When solving the problem, you first need to be able to read the file and correctly grab:
  - The operation
  - The first and second number
- When you correctly obtain each value in a variable of your choice, then start writing a portion of your output file. At least the header and some of the output.
- Now you have a nice chunk of your program written and working.


#### Parsing the strings
- Now you have a main program that processes an input file, but still doesn't add numbers together. 
- But, before any operations can be performed, you need to be able to turn a string into a list of numbers. 
- This code snippet pulls each digit off of a string. It does no error checking (for bad digits), but thats ok for now.
  
```cpp
  string number = "6353736356373459658564353";
  int digit=0;

  for(int i=0;i<number.size();i++){
    digit = number[i]-48;
  }
```

- If you create an instance of your `BigNum` class and send in a string when doing so:

```cpp

    string num1;    // read from file  "6353736356373459658564353"
    string num2;    // read from file  "6300986363826263804443"
    string op;      // read from file  "+"

    fin>>op>>num1>>num2; 
    
    BigNum bum1(num1); 
    BigNum bum2(num2);

```
- Then you could construct the list using similar logic from above in your constructor. 

#### CheckPoint
- At this point, you should be able to:
  1. Read input file
  2. write part of the output file
  3. parse a string inside the class and load the list with each digit.
- Prove it to yourself by printing out both list representing each number.
- The majority of your program is done, and we havent even attempted to implement an operation!
- Nothing to this point is new, and should be familiar code. 


#### Doing The Operations

- Implementing the operations is the hard part, but if you follow this path of solving the problem you should be in a very good position to succeed.
- The descriptions up top should help you finish from here.
- Remember to draw pics and trace your code with those pics. 
- Good Luck!

### Comments

**Example Top Comment Block for every file you wrote code in ...**

```cpp
///////////////////////////////////////////////////////////////////////////////
//
// Author:           (YOUR NAME IN ALL CAPS)
// Assignment:       Program_03
// Date:             14 November 2019
// Title:            Program 3 - Graphs
// Semester:         Spring 2018
// Course:           CMPS 1063 
// 
// Files:            apm.cpp, 
//                   doubly_linked.hpp, 
//                   input_data.txt 
//                   output.num
// Description:
//       describe program here thoroughly
//
/////////////////////////////////////////////////////////////////////////////////
```

**Example Function Comment Block**

```cpp
/**
 * Add
 * 
 * Description:
 *      Adds two strings together and returs a doubly linked list.
 * 
 * Params:
 *      string val1 : A string representation of an integer number.
 *      string val2 : A string representation of an integer number.
 * 
 * Returns:
 *      Node* : a list with addition results
 */
Node* Add(string val1, string val2) {
    // put comments for most lines in your implementaion
}

//OR

/**
 * Add
 * 
 * Description:
 *      Adds an "other" doubly linked list to "this" list 
 * 
 * Params:
 *      BigNum other    : An "other" list
 * 
 * Returns:
 *      BigNum : a doubley linked list with addition results
 */
BigNum Add(BigNum other) {
    // put comments for most lines in your implementaion
}

```

### Deliverables


- Create a folder called `program_3` in your `assignments` folder.
- In this folder create a file called `apm.cpp` with c++ code that fulfills the requirements.
- Your `program_3` folder should contain:
    - `apm.cpp` 
    - your intput file, `input_data.txt`
    - your output file, which should be named `output.num`
- ANY file you use with your assignment should ALWAYS end up in your assignment folder. 
- Make sure you use a doubly linked list to implement your solution.
- At a minimum add methods to an existing doubly linked class to ADD, SUBTRACT, and MULTIPLY. 

- Print a copy of your code, input file, and output file and bring to class Thursday Nov 21<sup>st</sup> at the beginning of class.
  - Order: Code on top then output file. 
  - Stapled: Upper left corner (close to the corner).
  - Your name should be on each page ( NO HAND WRITING !!  ).
- FAILURE TO FOLLOW INSTRUCTIONS: 1 letter grade. 


### Bonus

I'm not requiring it, but for an algorithm to do division, see below:

<sub>http://justinparrtech.com/JustinParr-Tech/an-algorithm-for-arbitrary-precision-integer-division/</sub>