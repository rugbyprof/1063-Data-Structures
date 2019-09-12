#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d, Node *n = NULL)
    {
        data = d;
        next = n;
    }
    void print(){
        Node* temp = this;
        cout << temp->data << endl;
        while(temp->next != NULL){
            temp = temp->next;
            cout << temp->data << endl;
        }
    }
    void add(int ndata){
        Node* temp = this;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node(ndata);
    }
};

int main()
{
    Node myList(42);
    myList.add(13);
    myList.add(4589763);
    myList.add(-900);
    myList.print();
}