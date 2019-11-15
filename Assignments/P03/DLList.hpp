///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Assignment:       Program_03
// Date:             14 November 2019
// Description:
//       This file is an implementation of a doubly linked list of integers.
// 
//       Feel free to use and alter or destroy. Do what you like with this code.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *Next;
    Node *Prev;

    Node(int d) {
        data = d;
        Next = NULL;
        Prev = NULL;
    }
};

class DLList {
private:
    Node *Head;               // Head of list pointer
    Node *Tail;               // Tail of list pointer
    int Count;                // Count of items in list

public:
    DLList();                   // Constructor
    DLList(const DLList &);     // Copy Constructor
    ~DLList();                  // Destructor
    void InsertFront(int);      
    void InsertBack(int);       
    void Print();
    void Delete();
    void RevPrint();
};

/**
 * Public Default Constructor
 */
DLList::DLList() {
    Head = Tail = NULL;
    Count = 0;
}

/**
 * Public Copy Constructor 
 *      constructs a new list with values from another list. 
 */
DLList::DLList(const DLList &list){
    Head = Tail = NULL;
    Count = 0;

    Node* Other = list.Head;
    while(Other){
        Node* Temp = new Node(Other->data);
        _EndSert(Temp);
        Other = Other->Next;
    }
}

/**
 * Public Destructor
 */
DLList::~DLList() {
    Node *temp = Head;

    while (temp) {
        temp = temp->Next;
        delete Head;
        Head = temp;
    }
}

/**
 * Public InsertFront
 * 
 * Adds item to head of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     int data : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::InsertFront(int data) {
    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Head->Prev = Temp;
        Temp->Next = Head;
        Head = Temp;
    }
    Count++;
}

/**
 * Public InsertBack
 * 
 * Adds item to tail of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     int data : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::InsertBack(int data) {
    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Tail->Next = Temp;
        Temp->Prev = Tail;
        Tail = Temp;
    }
    Count++;
}

/**
 * Public Print
 * 
 * Prints list to stdout from head to tail
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::Print() {
    Node *Temp = Head;

    while (Temp) {
        cout << Temp->data;
        if (Temp->Next) {
            cout << "->";
        }
        Temp = Temp->Next;
    }
    cout << endl;
}


/**
 * Public RevPrint
 * 
 *  Prints list to stdout in reverse (tail to head)
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::RevPrint() {
    Node *Temp = Tail;

    while (Temp) {
        cout << Temp->data;
        if (Temp->Prev) {
            cout << "->";
        }
        Temp = Temp->Prev;
    }
    cout << endl;
}
