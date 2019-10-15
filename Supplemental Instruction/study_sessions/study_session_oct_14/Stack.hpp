#include "Stack.h"
#include <iostream>
using namespace std;

template <class V>
Node<V>::Node()
{
    next = NULL;
}

template <class V>
Node<V>::Node(V d)
{
    data = d;
    next = NULL;
}

template <class V>
Node<V>::Node(V d, Node *n)
{
    data = d;
    next = n;
}

template <class V>
void Node<V>::print()
{
    cout << "Data: " << data << "\nNext Address: " << next << '\n';
}

template <class W>
Stack<W>::Stack()
{
    top = NULL;
    size = 0;
}

template <class W>
void Stack<W>::push(W val)
{
    top = new Node<W>(val, top);
    size++;
}

template <class W>
W Stack<W>::pop()
{
    W result = top->data;
    Node<W> *deleter = top;
    top = top->next;
    delete deleter;
    size--;
    return result;
}

template <class W>
void Stack<W>::print()
{
    cout << "Top ->";
    Node<W> *temp = top;
    while (temp)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}