## Program 2 - Resizable Array Stack
#### Due: October 8<sup>th</sup> by classtime.



### Overview

Using the code in [L05](../../Lectures/L05/README.md) add the necessary code to `resize` the array of the stack gets 80% full. You should resize the array to be 1.5 times larger than it previously was. Also, you should reduce the size of your array by half (0.5) if the stack gets down to 20% full (and this should only happen if it was previously enlarged).

### Requirements

- Add a method called `checkResize` that will look at the current ratio that the stack contains and decide to enlarge or shrink.
- Add a method called `Enlarge` that will grow the array. 
- Add a method called `Reduce` that will shrink the array.

Remember a resize of the array requires allocating a brand new array, and copying the values over to the new container.

### Resizing An Array

**Allocate a new array**
```cpp
int size = 8;
int *Array = new int[size];
```

<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_1b.png" width="100">


At some point we find that our array is getting full (in this case its 75% full):

<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_2b.png" width="100">

If its over the "threshold" (whatever we decide it is 75%,80%,90%, etc.) we allocate new memory and copy our values over:

**Allocate a new BIGGER array**
```cpp
int new_size = size * 1.5;
int *Array2 = new int [new_size];

```

<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_5b.png" width="100">


**Copy data over to new array**
```cpp

for(int i=0;i<size;i++){
    Array2[i] = Array[i];
}
```

|                                                                                       |                                                                                       |
| :-----------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_3b.png" width="175"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_4b.png" width="100"> |


**Arrange pointers and Delete old array**
```cpp
int *temp = Array;

Array = Array2;

delete [] Temp;
```

|                                                                                       |                                                                                       |                                                                                      |
| :-----------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------: |:-----------------------------------------------------------------------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_6b.png" width="150"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_7b.png" width="100"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/array_resizing_8b.png" width="150"> |

### Requirements

- Initialize a stack to be of size 10.
- Open the input file and read it. It will contain push and pop commands where `push` = `+` and `pop` = `-`
- All the numbers will be `integers > 0`. 
- Pop characters are followed by a zero to make reading the input easier. 
- Example:

```
+ 10
+ 9 
+ 4
- 0
- 0
+ 2
```

- As your stack fills, enlarge it.
- If it gets down to 20%, shrink it.
- Your output will be
  - The final size of your stack. 
  - The largest size your stack was.
  - And the remaining items in the stack print from left to right.
- Example:

```
Your Name
The Date
Homework 2

Stack Size: 33
Largest Size: 109
Values: 4 5 6 7 55 6 77 67 23 45 ......
```


### Deliverables

- Create a folder called `homework_2` in your `assignments` folder.
- In this folder create a file called `main.cpp` with c++ code that fulfills the requirements.
- Your `homework_2` folder should contain:
    - `main.cpp` 
    - your intput file, `input_data.txt`
    - your output file, which should be named `stack_out.dat`
- ANY file you use with your assignment should ALWAYS end up in your assignment folder. 
- Make sure you implement the 3 methods: `checkResize`, `Enlarge`, and `Reduce`.
- Print a copy of your code, input file, and output file and bring to class ___Tuesday___ Oct 8<sup>th</sup> at the beginning of class.
  - Order: Code on top then output file. 
  - Stapled: Upper left corner (close to the corner).
  - Your name should be on each page ( NO HAND WRITING !!  ).
- FAILURE TO FOLLOW INSTRUCTIONS: 1 letter grade. 
