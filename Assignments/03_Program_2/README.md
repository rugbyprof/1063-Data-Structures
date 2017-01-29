## Program 2 - Image Manipulation Part 2
Due February 15<sup>th</sup> at the beginning of class.

### Overview

Take your existing program that has a collection of image manipulation functions, and create a class definition that includes all of your functions. 


Remember the website to convert images to txt is here: http://cs.mwsu.edu/~griffin/1063_DataStructures/imgcsv/. The username/password associated with it is: ***mustang/mustang***. 



### Requirements

- Using your existing functions, complete the following class template make any necessary changes to make it work.

```cpp

class ImageManip{
private:
    rgb** image;
    int width;
    int height;
    ifstream infile;
    ofstream ofile;
    
public:
    ImageManip(){
    }
    
    void readFile(){
    }
    
    void writeFile(){
    }
    
    void grayScale(){
         // your code
    }
    
    void flipVert(){
        // your code
    }

    void flipHorz(){
        // your code
    }

    void grayScale(){
        // your code
    }
    ~ImagerManip(){
    }
}
```

- Remember to comment your code:

Main Program Comment Block:
```cpp
/**
* @ProgramName: Program-2
* @Author: Your Name 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: DD MM YYYY
*/
```

Function Comment Block:
```cpp
/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image,int width,int height){
    // your code
}
```

## Incremental Programming

- Remember to not try and solve the whole problem at once. 
- I will discuss in class some strategies for refactoring your existing code. 

## What to Turn In
- In the `assignments` folder, create a folder called `program_2` (not Program_2 or PROGRAM2 or program2 or you get it).
- Your code should be in a file called `main.cpp` within the `program_2` folder. 
- Any input files (txt or image) that you used to test your program should be in this folder as well.
- At the beginning of class on the 8<sup>th</sup>, bring in a printout of your `main.cpp` printed out using **gitprint**.
