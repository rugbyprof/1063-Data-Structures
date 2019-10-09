## Homework 03 - Overloading and Stacks
#### Due: October 15<sup>th</sup> by class time.

### Overview

Edit the [ListStack.h](../../Lectures/L07/ListStack.h) file, and add an overloaded constructor for the file so that it accepts 
the animal name, weight, and it's scary score.

Here is how we loaded the animals onto the stack in L07. Notice we created a `new` Animals THEN we put the values into the Animal before pushing onto the stack.

```cpp
while (!fin.eof()) {
    a = new Animal();                         // allocate memory for an animal
    fin >> a->name >> a->weight >> a->scary;  // load animal with file data
    LS.Push(a);                               // push animal onto the stack
}
```

I want you to create a constructor so that the following works:

```cpp
    a = new Animal(name,weight,scary);
    LS.Push(a);
```

### Deliverables

- Create a folder called `homework_03` in your `assignments` folder.
- In this folder make sure you have (same files as L07):
  - `animals.txt`
  - `ListStack.cpp`
  - `ListStack.h`
  - `main.cpp`
- Edit the ListStack and main so that the overloaded constructor is used instead of the default one.
- What to print out:
  - Print `main.cpp` 
  - Print `ListStack.cpp`
- Both of those files should be turned in at the beginning of class.
- Make sure comments are included as well!

