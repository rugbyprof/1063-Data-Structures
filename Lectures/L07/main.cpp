/**
 * Lecture 07
 * 
 * List based Stack that holds an animal type
 * 
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 */
#include "ListStack.h"    // include our stack definition
#include <fstream>        
#include <iostream>

using namespace std;

int main() {
    ifstream fin("animals.txt");  // input file of animal info                   
    Animal *a;                    // animal pointer used to hold popped animals
    ListStack LS;                 // List based stack object

    // While still animals in the file
    while (!fin.eof()) {
        a = new Animal();                         // allocate memory for an animal
        fin >> a->name >> a->weight >> a->scary;  // load animal with file data
        LS.Push(a);                               // push animal onto the stack
    }


    LS.Print();             // Print the stack

    cout << endl;           // ummm

    a = LS.Pop();           // get animal off top of stack
    
    cout << a << endl;      // print animal (cout operator overloaded)

    a = LS.Pop();           // get animal off top of stack again
    
    cout << a << endl;      // print animal (cout operator overloaded)

    LS.Print();             // print the stack
}