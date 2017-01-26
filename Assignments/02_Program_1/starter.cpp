#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct rgb{
    int r;
    int g;
    int b;
};

int main(){
    ifstream ifile;
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");
    int width,height;
    
    
    rgb **img;
    
    ifile>>width>>height;
    
    img = new rgb*[height];
    
    for(int i=0;i<height;i++){
        img[i] = new rgb[width*3];
    }
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>img[i][j].r>>img[i][j].g>>img[i][j].b;            
        }
    }
    
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<img[i][j].r<<" "<<img[i][j].g<<" "<<img[i][j].b<<" ";
        }
        ofile<<endl;
    }
    
    
  return 0;
}
