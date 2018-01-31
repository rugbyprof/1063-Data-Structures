## Homework 2 - Write a Class

#### Overview

Using the code in [main_find_max.cpp](https://github.com/rugbyprof/1063-Data-Structures/blob/master/Lectures/L08/gpaClass/main_find_max.cpp) as a simple example of how to find the max value in an array of integers, write a class called `gpaClass` that would do the following:

- Read in 1000 Gpa's from a file into an array.
- The name of the file is `gpa.txt`
- Write class methods to do the following:
    - Find the Max Gpa (there will be multiple occurences (of 4.0), but that's ok).
    - Find the Min Gpa (not sure of the results)
    - Find the Avg Gpa 
    - Count the number of Gpa's in the following categories:
       - 0   < gpa <= 1.5
       - 1.6 < gpa <= 2.5
       - 2.5 < gpa <= 3.0
       - 3.0 < gpa <= 3.5
       - 3.5 < gpa <= 4.0        

#### Solution 

Let's start by writing a basic `Class` definition.

```cpp
class gpaClass{
// Private is a section in which we keep protected from users of our class.
private:

  // data declarations here
  // NO assigning values here, that goes in the constructor
  
// Public section allows users to access those items or methods.
public:

  // We have a function (method) that has the same name as the class
  // which servers as our constructor.
  gpaClass(){
  
    // Initialize everything here...
  }
};

```

Now lets add the basics for our class. We know enough about our problem to add a few items: 

 - Our gpa data is `double`, 
 - we're supposed to read into an array from a file. 
 
 - the file name is `gpa.txt`
 - we also know that it is a 1000 gpa's. 

So ...

```cpp
class gpaClass{
private:

  ifstream fin;    // reference to my input file
  double *data; // array of doubles to hold my gpa's (remember it has to be a pointer because
                   we can't assign anything to this variable yet).
  int numGpas;  // number of gpas to read in.
  
public:

  gpaClass(){
      numGpas = 1000;   //max size for our loops
      
      fin.open("gpa.txt");  // open our file for reading
      
      // Load array from file
      int i = 0;  // we need a looping index to access the array
      
      // While were not at the end of file
      while(!fin.eof()){
        fin>>data[i];
        i++;
      }
  }
};

```

Now to use this we could write:

```cpp

gpaClass G; //creates an instance of gpaClass called G. 
```

Creating an instance of the `gpaClass` would open the `gpa.txt` file and read in the data into our array. What if we didn't know the name of the file to open?? Lets make a small change:

```cpp
class gpaClass{
private:

  ifstream fin;    // reference to my input file
  double *data;   // array of doubles to hold my gpa's
  int numGpas;    // number of gpas to read in.
  
public:

  // remember to include string!
  gpaClass(string filename){
  
      numGpas = 1000;
      //Now we open "filename" instead of "gpa.txt"
      fin.open(filename);
      
      data = new double[numGpas];
      
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

gpaClass G("someOtherFile.txt"); //creates an instance of gpaClass called G and 
                                 // passes "someOtherFile.txt" to the constructor. 
```

We can make another simple addition, and add a `default` param to also pass the array size into the constructor:

```cpp
class gpaClass{
private:

  ifstream fin;    // reference to my input file
  double *data;   // array of doubles to hold my gpa's
  int numGpas;    // number of gpas to read in.
  
public:

  // remember to include string!
  gpaClass(string filename,int numGpas=1000){
      //Now we open "filename" instead of "gpa.txt"
      fin.open(filename);
      
      data = new double[numGpas];
      
      // Load array from file
      int i = 0;  // we need a looping index
      while(!fin.eof()){
        fin>>data[i];
        i++;
      }
  }

};

```
To create an instance of this version we could do:

```cpp

gpaClass G1("someOtherFile.txt");  // opens someOtherFile and uses the default 1000 for numGpas 

gpaClass G2("fileWith2000Gpas.txt",2000); // opens someFile and uses 2000 for numGpas 
```
