#include <iostream>

using namespace std;

struct Coord{
  int row;
  int col;
  Coord(int r=0,int c=0){
    row = r;
    col = c;
  }
};

struct Node{
  Coord *loc;
  Node *Next;
};


class MoveStack{
private:
  int NumItems;
  Node *Top;
public:
  MoveStack(){
     Top = NULL;
  }
  void Push(Coord *c){
    //Allocated memory for my new node
    Node* Temp = new Node;
    Temp->loc = c;
    Temp->Next = NULL;
    
    //Figure out where it goes.
    
    if(Top == NULL){
      Top = Temp;
    }else{
      Temp->Next = Top;
      Top = Temp;
    }
  }
  
  void Pop(Coord *&c){
    if(!Empty()){
      c = Top->loc;
      Node* Temp = Top;
      Top = Top->Next;
      delete Temp;
    }
  }
  
  void Peek(Coord *&c){
    if(!Empty()){
      c = Top->loc;
    }
  }
  
  bool Empty(){
    return Top == NULL;
  }
  
  void Print(){
    Node* Temp = Top;
    while(Temp != NULL){
      cout<<"["<<Temp->loc->row<<","<<Temp->loc->col<<"]"<<endl;
      Temp = Temp->Next;
    }
  }
};

class Maze{
private:
  int **Mz;
  int Size;
  MoveStack *Ms;
public:

  Maze(int size){
    int i,j;
    Size = size;
    Ms = new MoveStack();
    Mz = new int*[size];
    for(i = 0;i < Size;i++){
      Mz[i] = new int[Size];
    }
    
    for(i=0;i<Size;i++){
      for(j=0;j<Size;j++){
        Mz[i][j] = 0;
      }
    }
  }
  
  void RandomWalk(){
    Coord *c = new Coord(3,4);
    Visit(c);
    Ms->Push(c);
    int row,col;

    while(!Ms->Empty()){
      Ms->Peek(c);
      row = c->row;
      col = c->col;
      if(inMaze(row-1,col) && open(row-1,col)){
        c = new Coord(row-1,col);
        Ms->Push(c);
        Visit(c);
      }else if(inMaze(row+1,col) && open(row+1,col)){
        c = new Coord(row+1,col);
        Ms->Push(c);
        Visit(c);
      }else if(inMaze(row,col+1) && open(row,col+1)){
        c = new Coord(row,col+1);
        Ms->Push(c);
        Visit(c);
      }else if(inMaze(row,col-1) && open(row,col-1)){
        c = new Coord(row,col-1);
        Ms->Push(c);
        Visit(c);
      }else{
        Ms->Pop(c);
      }
      Print();
    }
    
  }
  
  bool inMaze(int row,int col){
    return row >= 0 && row < Size &&
           col >= 0 && col < Size;
  }
  
  bool open(int row,int col){
    return Mz[row][col] == 0;
  }
  
  void Visit(Coord *c){
    Mz[c->row][c->col] = 1;
  }
  
  void Print(){
    int i,j;
    for(i=0;i<Size;i++){
      for(j=0;j<Size;j++){
        cout<<Mz[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
};

int main(){
  //MoveStack Ms;
  Maze Mz(5);
  // Coord *c = new Coord(3,4);
  // Coord *b;
  // Ms.Push(c);
  // c = new Coord(5,6);
  // Ms.Push(c);
  // c = new Coord(6,7);
  // Ms.Push(c);
  // Ms.Print();
  // cout<<endl;
  // Ms.Pop(b);
  // cout<<b->row<<","<<b->col<<endl;
  // Ms.Print();
  // Mz.Print();
  Mz.RandomWalk();
  
}
