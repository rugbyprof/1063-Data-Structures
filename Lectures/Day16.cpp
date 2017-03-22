#include <iostream>

using namespace std;

class Heap{
private:
  int *H;
  int Next;
  int MaxSize;
  int CurrentSize;
  void BubbleUp(int);
  int Parent(int);
  int Left(int);
  int Right(int);
  void Swap(int,int);
public:
  Heap(int);
  void Insert(int);
  int Remove();
  void PrintHeap();
};

Heap::Heap(int size){
  H = new int [size];
  Next = 1;
  MaxSize = size;
  CurrentSize = 0;
}

void Heap::Insert(int x){
  H[Next] = x;
  BubbleUp(Next);
  Next++;
  CurrentSize++;
}

void Heap::BubbleUp(int i){
  int p = Parent(i);
  while(H[i] < H[p]){
    Swap(i,p);
    i = p;
    p = Parent(i);
  }
}

void Heap::Swap(int p, int i){
  int temp = H[p];
  H[p] = H[i];
  H[i] = temp;
}

int Heap::Parent(int i){
  return int(i / 2);
}

int Heap::Left(int i){
  return i * 2;
}

int Heap::Right(int i){
  return i * 2 + 1;
}

int Heap::Remove(){
  
}

void Heap::PrintHeap(){
  for(int i=1;i<Next;i++){
    cout<<H[i]<<" ";
  }
  cout<<endl;
}

int main(){
  Heap myHeap(25);
  myHeap.Insert(8);
  myHeap.Insert(4);
  myHeap.Insert(3);
  myHeap.Insert(12);
  myHeap.Insert(9);
  myHeap.Insert(11);
  myHeap.Insert(5);
  myHeap.Insert(2);
  myHeap.Insert(1);
  
  myHeap.PrintHeap();
  return 0;
}

