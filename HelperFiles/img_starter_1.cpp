#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream ifile;
    ofstream ofile;
    ifile.open("bubbles.txt");
    ofile.open("bubbles2.txt");
    int width,height;
    
    int **img;
    
    ifile>>width>>height;
    
    img = new int*[height];
    
    for(int i=0;i<height;i++){
        img[i] = new int[width*3];
    }
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width*3;j++){
            ifile>>img[i][j];
        }
    }
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width*3;j++){
            if(j%3==0)
                img[i][j] = 0;
        }
    }
 
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width*3;j++){
            ofile<<img[i][j]<<" ";
        }
        ofile<<endl;
    }
    
    
  return 0;
}
