#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
    Node();
    Node(T d);
    Node(T d, Node *n);
    void print();
};

template <class U>
class Stack
{
private:
    Node<U> *top;
    int size;

public:
    Stack();
    void push(U val);
    U pop();
    void print();
};

#include "Stack.hpp"