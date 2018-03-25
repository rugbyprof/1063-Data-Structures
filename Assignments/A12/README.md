## Program 2 - Priority Queue
#### Due: Wednesday March 27<sup>th</sup> by 10:00 am

## Priority Queue

A priority queue is a data structure that allows certain elements to stay closer to or bubble towards the front of the queue. How far they get to the front of the structure is based on the assigned priority given to them. One real world example is a print queue, where jobs from certain individuals my have higher priority on a shared printer and print first. Or, maybe the printer assigns higher prioriy to shorter print jobs to increase throughput. A recent debate about net neutrality has posited that certain packets of data would have lower priority on the web, and therefore increase the amount of time it would take for those packets to get from A to B. 

We will not be implementing a "print queue" or some "packet" priority routing program, we will simply be implementing a basic priority queue, where WE choose the rules of what constitutes higher priority. 

## Overview

- Take code from here: [](./priority_queue.cpp)
- Your input file is here: [](./input_data.txt)
- Turn the starter code into a priority queue based on: "word length" where the shorter the word, the higher the priority.
- Ties are handled based on alphabetical order.
- The input file is a list of commands. See example below.
- Your ouput file should contain the animals popped off by the "pop" command and what remains on the queue.

### Example

```
push elephant-seal
push crow
push water-buffalo
pop
pop
push hippopotamus
push turkey
push giant-panda
push ox
pop
pop
pop
```

Base on the above input, your output should be:

```
Animals Popped off the Queue:

1 crow
2 elephant-seal
3 ox
4 turkey
5 giant-panda

Animals Remaining on the Queue (in order of priority):

1 hippopotamus
2 water-buffalo
```

## Deliverables

- Create a folder called `program_2`.
- Name your actual program `priority_queue.cpp`.
- Make sure your `priority_queue.cpp` and `input_data.txt` are both in your `program_2` folder.
- Comment your code!
- Create an output file called `priority_out.txt` that has your output as described above.
- Print out your `prirority_queue.cpp` and turn it in at the beginning of class.

- Commented code:
    - Make sure you place a program comment block at the very top of your file.
    - Comment every function and / or method. 
    - Comment any chunk of code that you feels needs explaining.
    - Rememember comments are not just for me, they are for you reading your own code weeks or months later.
    - Examples below (whether you use slashes or asterisks doesn't matter, just the content of the comment block).

#### Example Program Comment

```
///////////////////////////////////////////////////////////////////////////////
//                   YOU MUST COMPLETE AND COMMENT YOUR CODE!
// Title:            (program's title)
// Files:            (list of source files)
// Semester:         (course) Spring 2018
//
// Author:           (your name)
// Email:            (your email address)
// Description:
//       describe program here thoroughly
/////////////////////////////////////////////////////////////////////////////////
```

#### Example Function or Method Comment

```
/**
* Function Push:
*      Pushes an item onto the stack.
* 
* Params:
*      [int] val - value of item being pushed
* Returns
*      void
*/
```

