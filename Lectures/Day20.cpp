#include <iostream>

//http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
//http://quiz.geeksforgeeks.org/binary-search-tree-set-2-delete/

using namespace std;

struct Node{
  int Data;
  Node* Left;
  Node* Right;
};

struct Answer{
  bool Found;
  int Comparisons;
  Answer(bool b,int c){
    Found = b;
    Comparisons = c;
  }
};

class BST{
private:
  Node* Root;
  void _Insert(Node* &Root, Node* Temp){
    if(Root == NULL){
      Root = Temp;
    }else{
      if(Root->Data < Temp->Data){
        _Insert(Root->Right,Temp);
      }else{
        _Insert(Root->Left,Temp);        
      }
    }
  }
  
  void _Inorder(Node* Root){
    if(Root == NULL){
      return;
    }else{
      cout<<Root->Data<< " "<<endl;
      _Inorder(Root->Left);
      _Inorder(Root->Right);
    }
  }
  
  int _Max(int val1,int val2){
    if(val1 > val2){
      return val1;
    }else{
      return val2;
    }
  }
  
  int _Height(Node* Temp){
    if(!Temp){
      return 0;
    }else{
      return _Max(_Height(Temp->Left) + 1,_Height(Temp->Right) + 1);
    }
  }
  
  Node* _Parent(Node* Temp, int val){
    if(Temp==NULL){
      return NULL;
    }else{
      if(Temp->Right->Data == val){
        return Temp;
      }else if(Temp->Left->Data == val){
        return Temp;
      }
      
    
      if(val < Temp->Data){
        _Parent(Temp->Left,val);
      }else{
        _Parent(Temp->Right,val);
      }
    }
  }
  
  Node* _Find(Node* Temp, int val){
    if(Temp == NULL){
      return NULL;
    }else{
      if(val == Temp->Data){
        return Temp;
      }else if(val > Temp->Data){
        return _Find(Temp->Right,val);
      }else{
        return _Find(Temp->Left,val);
      }
    }
  }
  
  Node* _Predecessor(Node* Temp){
    if(Temp->Left == NULL){
      return NULL;
    }
    Temp = Temp->Left;
    while(Temp->Right != NULL){
      Temp = Temp->Right;
    }
    return Temp;
  }
  
  int _Delete(Node* Temp){
    if(NumChildren(Temp) == 0){
      int x = Temp->Data;
      delete Temp;
      return x;
    }else if(NumChildren(Temp) == 1){
      //
    }else{
      //two cildren
    }
  }
  
  bool IsLeaf(Node* Temp){
    return (Temp->Left == NULL && Temp->Right == NULL);
  }
  
  int NumChildren(Node* Temp){
    int children = 0;
    
    if(Temp->Left){
      children++;
    }
    if(Temp->Right){
      children++;
    }
    return children;
  }
  
  
public:
  BST(){
    Root = NULL;
  }
  
  void Inorder(){
    _Inorder(Root);
  }
  
  void Insert(int val){
    Node* Temp = new Node;
    Temp->Data = val;
    Temp->Left = NULL;
    Temp->Right = NULL;
    _Insert(Root,Temp);
  }
  
  Node* Parent(int val){
    return _Parent(Root,val);
  }
  
  int Predecessor(int val){
    Node* temp = _Find(Root,val);
    temp =  _Predecessor(temp);
    return temp->Data;
  }
  
  int Height(){
    return _Height(Root);
  }

  Node* Find(int val){
    return _Find(Root,val);
  }
  
  int Delete(int key){
    Node *Temp = _Find(Root,key);
    if(Temp == NULL){
      return -1;
    }
    return _Delete(Temp);
  }
};

bool unique_number(int vals[],int num){

  for (int i=0;i<5000;i++){
    if(vals[i] == num){
      return false;
    }
  }
  return true;
}

int main(){
  srand(928347);
  BST tree;
  int nums[] = {50,17,72,12,23,54,76,9,14,19,67};
  int MaxValue = 5000;
  int r = 0;
  int *vals;
  bool use_random = false;

  
  if(use_random){
    vals = new int[MaxValue];
    
    for (int i=0;i<MaxValue;i++){
      vals[i] = 0;
    }
    tree.Insert(int(MaxValue/2));
    
    for (int i = 0;i< 128;i++){
      r = rand()%MaxValue;
      while(unique_number(vals,r)==false){
        r = rand()%MaxValue;
      }
      vals[i] = r;
      tree.Insert(r);
  
    }
  }else{  
    //https://i.stack.imgur.com/36FkR.png
    for(int i=0;i<11;i++){
      tree.Insert(nums[i]);
    }
  }
    
  //cout<<tree.Height()<<endl;
  tree.Inorder();
  //cout<<tree.Find(1979)<<endl;
  
  //cout<<tree.Predecessor(50)<<endl;
  cout<<tree.Parent(23)->Data<<endl;
  
  return 1;
}


struct Node* Delete(struct Node *root, int data) {
  if (root == NULL) {
     return NULL;
  }
  if (data > root->data) {  // data is in the left sub tree.
      root->left = Delete(root->left, data);
  } else if (data > root->data) { // data is in the right sub tree.
      root->right = Delete(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->right;
        delete temp;
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->left;
        delete temp;
     }
     // case 4: two children
     else {
        struct Node *temp = FindMin(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = Delete(root->right, temp->data); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}
