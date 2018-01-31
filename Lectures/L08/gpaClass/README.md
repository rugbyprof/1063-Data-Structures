## Homework 2 - Write a Class

#### Overview

Using the code in [main_find_max.cpp](https://github.com/rugbyprof/1063-Data-Structures/blob/master/Lectures/L08/gpaClass/main_find_max.cpp) as a simple example of how to find the max value in an array of integers, write a class called `gpaClass` that would do the following:

- Read in 1000 Gpa's from a file into an array.
- Write class methods to do the following:
    - Find the Max Gpa (there will be multiple occurences (of 4.0), but that's ok).
    - Find the Min Gpa (not sure of the results)
    - Find the Avg Gpa 
    - Count the number of Gpa's in the following categories:
        0   < gpa <= 1.5
        1.6 < gpa <= 2.5
        2.5 < gpa <= 3.0
        3.0 < gpa <= 3.5
        3.5 < gpa <= 4.0        

#### Solution 

Let's start by writing a `Class` definition.

```cpp
class gpaClass{
private:

  // data declarations here
  // NO assigning values here, that goes in the constructor
public:

  // We have a function (method) that has the same name as the class
  // which servers as our constructor.
  gpaClass(){
  
    // Initialize everything here...
  }
};

```

 We know the data type = `double` and we're supposed to read into an array from a file. We also know that it is a 1000 gpa's. So ...

```cpp
class gpaClass{
private:

  ifile fin;    // reference to my input file
  double *data; // array of doubles to hold my gpa's
  int numGpas;  // number of gpas to read in.
  
public:

  gpaClass(){
      numGpas = 1000;   //max size for our loops
      fin.open("gpa.txt");
      
      // Load array from file
      int i = 0;  // we need a looping index
      while(!fin.eof()){
        fin>>data[i];
        i++;
      }
  }
};

```

Now to use this we could write:

```cpp
gpaClass G;
```

Creating an instance of the `gpaClass` would open the `gpa.txt` file and read in the data into our array. What if we didn't know the name of the file to open?? Lets make a change:

```cpp
class gpaClass{
private:

  ifile fin;    // reference to my input file
  double *data; // array of doubles to hold my gpa's
  int numGpas;  // number of gpas to read in.
  
public:

  gpaClass(){
      numGpas = 1000;   //max size for our loops
      fin.open("gpa.txt");
      
      // Load array from file
      int i = 0;  // we need a looping index
      while(!fin.eof()){
        fin>>data[i];
        i++;
      }
  }
};

```
