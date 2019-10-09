#include <iostream>

using namespace std;

class Queue{
private:
  int *A;
  int Front;
  int Rear;
  int Size;
  int Count;
public:
  Queue();
  Queue(int);
  void Push(int);
  int Pop();
  bool Empty();
  bool Full();
  void Print();
};

