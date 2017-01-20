#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct rgb {
  int r;
  int g;
  int b;
};

void printColors(rgb x[],int size){
  for(int i=0;i<size;i++){
    cout<<x[i].r<<","<<x[i].g<<","<<x[i].b<<endl;
  }
}

int main() {

  ifstream ifile;
  int r,g,b;
  
  rgb colors[150];
  
  int count = 0;
  
  
  ifile.open("data.csv");
  
  while(!ifile.eof()){
    ifile>>colors[count].r>>colors[count].g>>colors[count].b;
    count++;
  }

  colors[count-1].g = 255;

  //here we know how many colors we have
  
  printColors(colors,count);
  

}
