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
    void _DeleteTail();
public:
    DLList();                   // Constructor
    DLList(const DLList &);     // Copy Constructor
    ~DLList();                  // Destructor
    int Size();
    void InsertFront(int);      
    void InsertBack(int);       
    void Print();
    void RevPrint();
    void Delete();
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
    Head = Tail = NULL; // Initialize pointers like always
    Count = 0;

    // Point to "Other" lists head. Even though its private we
    // can access it beacuase we are in a class of the same type.
    Node* Other = list.Head;

    // Travers the other list
    while(Other){
        // Insert values into new nodes in this list.
        InsertBack(Other->data);
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
 * Private _DeleteTail
 * 
 * Deletes last node in list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::_DeleteTail() {
    
    if(Tail){
        Node *Temp = Tail;
        if(Tail == Head){
            Tail = Head = NULL;
            delete Temp;
        }else{
            
            Tail = Tail->Prev;
            Tail->Next = NULL;
            delete Temp;
        }
        Count--;
    }
}

/**
 * Public Delete
 * 
 * Deletes last node in list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void DLList::Delete() {
    _DeleteTail();
}

/**
 * Public Size
 * 
 * Returns size of list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     int
 */
int DLList::Size(){
    return Count;
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
