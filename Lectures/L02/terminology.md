# Object-Oriented Terminology

Object-oriented methodology is a way of viewing software components and their relationships. Object-oriented methodology relies on three characteristics that define object-oriented languages: 
1. encapsulation
2. polymorphism
3. inheritance

### Classes and Methods

A ___Class___ is the encapsulation of data together with functions that manipulate the data as well as return information about the data. The functions in a ___Class___ are called ___methods___. The example below is the ___Class Definition___:

#### Example
```cpp
class Student{
private:
    /////////////////////////////////// DATA MEMBERS ///////////////////////////////////////////////
    string fname;                   
    string lname;           
    int numGrades;
    int gradeContainer[10];

public:

    /////////////////////////////////// CONSTRUCTOR ///////////////////////////////////////////////
    Student(){              
        fname = "";
        lname = "";
        numGrades = 0;
        for(int i=0;i<10;i++){
            grades[i] = 0;
        }
    }

    /////////////////////////////////// METHODS /// ///////////////////////////////////////////////
    void setFname(string val){
        fname = val;
    }

    void setLname(string val){
        lname = val;
    }

    void addGrade(int grade){
        if(numGrades < 10){
            grades[numGrades++] = grade;
        }else{
            cout<<"Error!! Too many grades!";
        }
    }

    float avgGrades(){
        int total = 0;  

        for (int i = 0; i < numGrades; i++){
            total = total + grades[i];
        }

        return (float)total / (float)numGrades;
    }
    
};
```

When you declare an instance of a ___Class___ you get an ___Object___. The Object is resident in memory and is created using the Class definition that we wrote above. This is where the term ___OOP___ (Object Oriented Programming) comes from. ___OOP___ : a programming style that is oriented around ___Objects___!

```cpp
    S0 = Student;   // S0 is now an object.
```

### Encapsulation

___Encapsulation___ refers to mechanisms that allow each object to have its own data and methods. The idea of encapsulating data together with methods existed before object-oriented languages were developed. It is inherent in the concept of an abstract data type ___ADT___.  At a high level, this just means we are going to create our own data types so we can define what information they hold (data members) and how other constructs interact with them (methods). 

Object-oriented languages provide more powerful and flexible encapsulation mechanisms for restricting interactions between components (___Public___, ___Private___, ___Protected___). When used carefully, these mechanisms allow the software developers to restrict the interactions between components to those that are required to achieve the desired functionality. The management of component interactions is an important part of software design. It has a significant impact on the ease of understanding, testing, and maintenance of components.


### Polymorphism and Overloading

___Polymorphism___ refers to the capability of having methods with the same names and parameter types exhibit different behavior depending on the receiver. In other words, you can send the same message to two different objects and they can respond in different ways.

More generally, the capability of using names to mean different things in different contexts is called ___overloading___. This also includes allowing two methods to have the same name but different parameters types, with different behavior depending on the parameter types. Note that a language could support some kinds of overloading without supporting polymorphism. In that case, most people in the object-oriented community would not consider it to be an object-oriented language.

Polymorphism and overloading can lead to confusion if used excessively. However, the capability of using words or names to mean different things in different contexts is an important part of the power of natural languages. People begin developing the skills for using it in early childhood.


### Class Members and Instance Members

In many object-oriented languages, classes are objects in their own right (to a greater or lesser extent, depending on the language). Their primary function is as factories for objects in the category. A class can also hold data variable and constants that are shared by all of its objects and can handle methods that deal with an entire class rather than an individual object. These members are called _class members_ or, in some languages (C++ and Java, for example), _static members_. The members that are associated with objects are called _instance members_.

### Inheritance

One important characteristic of object-oriented languages is inheritance. _Inheritance_ refers to the capability of defining a new class of objects that inherits from a parent class. New data elements and methods can be added to the new class, but the data elements and methods of the parent class are available for objects in the new class without rewriting their declarations.

For example, Java uses the following syntax for inheritance:

public class B extends A {

    declarations for new members

}

___More on Class Members vs Instance Members, Inheritance, Encapsulation,  and Polymorphism later ...___