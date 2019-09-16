/**
 * Class lecture code
 * 
 * Written by: Terry Griffin
 * Class : CMPS 1063
 * Date: 15 Sep 19
 */

#include <iostream>

using namespace std;

/**
 * Node
 * 
 * int      Value   : the data portion of this node
 * Node*    Next    : Linked structures need a pointer (of same type) to link things together
 */
struct Node{
    int Value;
    Node* Next;

    // constructor to initialize our node
    Node(int x){
        Value = x;
        Next = NULL;
    }
};

/**
 * Class LinkeList
 * 
 * Methods:
 * 
 * LinkedList   : constructor
 * frontSert    : adds a node to front of list
 * endSert      : adds a node to rear of list
 * print        : prints the contents of the list
 */
class LinkedList{
private:
    Node* Head;

public:
    // constructor
    LinkedList(){
        Head = NULL;
    }

    /**
     * frontSert
     * 
     * Params:
     * 
     *     int x : data to hold in the node
     * 
     * Returns: 
     *     void
     */
    void frontSert(int x){
        Node* Temp = new Node(x);

        if(Head == NULL){
            Head = Temp;
        }else{
            Temp->Next = Head;
            Head = Temp;
        }
        
    }

    /**
     * endSert
     * 
     * Params:
     * 
     *     int x : data to hold in the node
     * 
     * Returns: 
     *     void
     */
    void endSert(int x){
        Node* Temp = new Node(x);

        if(Head == NULL){
            Head = Temp;
        }else{
            Node* Temp2 = Head;

            while(Temp2->Next != NULL){

                Temp2 = Temp2->Next;
            }

            Temp2->Next = Temp;
        }
    }

    /**
     * print
     * 
     * Description:
     * 
     *     prints out contents of the list
     * 
     * Params:
     * 
     *     void
     * 
     * Returns: 
     *     void
     */
    void print(){
        Node* Temp = Head;

        while(Temp != NULL){
            cout<<Temp->Value;
            if(Temp->Next){
                cout<<"->";
            }
            Temp = Temp->Next;
        }
    }
};


int main(){

    // Not the typical way of creating a list!!
    // Used as intro in class
    Node* A = new Node(8);      // create 4 new nodes all accessed with
    Node* B = new Node(5);      // var A,B,C,D
    Node* C = new Node(7);
    Node* D = new Node(33);

    A->Next = B;        // Linking the four nodes together
    B->Next = C;
    C->Next = D;

    Node* Temp = A;     // Creating a temp pointer to start at beginning of list

    // Loop through the list and print stuff out
    while(Temp != NULL){
        cout<<Temp->Value<<endl;
        Temp = Temp->Next;
    }

    // More typical way of creating a list
    LinkedList L;

    for(int i=0;i<8;i++){
        L.frontSert(i);
    }

    for(int i=0;i<8;i++){
        L.endSert(i);
    }
    L.print();


    return 0;
}