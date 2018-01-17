#include <iostream>

using namespace std;

class Heap{
private:
  int *H;
  int Next;
  int MaxSize;
  int CurrentSize;
  void BubbleUp(int);
  void BubbleDown(int);
  int Parent(int);
  int Left(int);
  int Right(int);
  void Swap(int,int);
  int PickChild(int i);
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

void Heap::BubbleDown(int i){
  bool loop = true;
  int left_child = 0;
  int right_child = 0;
  while(loop){
    left_child = H[left(i)]
    right_child = H[right(i)]
    
  }
}

//returns index to swap with or -1 for no Swap
int Heap::PickChild(int i){
  
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
  int temp = H[1];
  H[1] = H[--next];
  BubbleDown(1);
  return temp;
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
  int min = myHeap.Remove();
  cout<<min<<endl;
  return 0;
}

