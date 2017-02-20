#include <iostream>
#include <string.h>

struct Node{
  int Data;
  // string fname;
  // string lname;
  // string email;
  // double balance;
  // string address;
  // string created;
  Node *Prev;
  Node *Next;
};

class DBList{
private:
    Node *Head;
    Node *Tail;
    Node* _CreateNode(int);
    Node* _Find(int);
public:
    DBList();
    bool InsertFront(int);
    bool InsertRear(int);
    bool InsertInOrder(int);
    bool Delete(int);   //Removes item from list
    bool Find(int);     //Locate and see if exists
    bool Update(int,int);   //Change existing value
    void Print();
};
