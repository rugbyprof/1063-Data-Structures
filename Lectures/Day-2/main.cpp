#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
struct to hold a single rgb color
*/
struct rgb {
  int r;
  int g;
  int b;
};

/**
* printColors
* @params:
*    rgb x[]: array of rgb colors
*    int size: size of array
* @returns: 
*    void
*/
void printColors(rgb x[],int size){
  for(int i=0;i<size;i++){
    cout<<x[i].r<<","<<x[i].g<<","<<x[i].b<<endl;
  }
}

int main() {
  
  // file pointer
  ifstream ifile;  

  // array of rgb colors
  rgb colors[150];
  
  // counter for colors
  int count = 0;
  
  // open color data file
  ifile.open("data.csv");
  
  // read file until eof flag is set
  while(!ifile.eof()){
    ifile>>colors[count].r>>colors[count].g>>colors[count].b;
    count++;
  }
  //here we know how many colors we have
  
  // alter array for no reason except as an example on
  // how to access a single color in an array of structs
  colors[count-1].g = 255;
  
  printColors(colors,count);
 
}
