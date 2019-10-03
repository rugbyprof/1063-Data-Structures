#include <iostream>

using namespace std;



struct Animal{
  string name;
  double weight;
  double scary;

  Animal(){
    name = "";
    weight = 0.0;
    scary = 99.0;
  }
};

ostream& operator<<(ostream& , const Animal* );

struct Node{
  Animal *A;
  Node * Next;

  Node(Animal *a){
    A = a;
    Next = NULL;
  }

};

class ListStack{
private:
  Node *Top;
public:
  ListStack();
  void Push(Animal*);
  Animal* Pop();
  void Print();
  int Size();
};

