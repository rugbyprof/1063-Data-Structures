#include <iostream>

using namespace std;

struct Node{
    int Value;
    Node* Next;
    Node(int x){
        Value = x;
        Next = NULL;
    }
};

class LinkedList{
private:
    Node* Head;

public:
    LinkedList(){
        Head = NULL;
    }


    void frontSert(int x){
        Node* Temp = new Node(x);

        if(Head == NULL){
            Head = Temp;
        }else{
            Temp->Next = Head;
            Head = Temp;
        }
        
    }

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
    Node* A = new Node(8);
    Node* B = new Node(5);
    Node* C = new Node(7);
    Node* D = new Node(33);

    A->Next = B;
    B->Next = C;
    C->Next = D;

    Node* Temp = A;

    while(Temp != NULL){
        cout<<Temp->Value<<endl;
        Temp = Temp->Next;
    }

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