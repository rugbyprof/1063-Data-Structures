/**
* TXT Image Manipulation Starter
* 
* This code is a simple way to read in color information stored in a space
* delimited txt format. The expected file format is:
*                ---------------------------
*                | width height            |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                ---------------------------
* So a 10x10 img would have 11 total rows, 10 rows of data, with 30 values in row.
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};

class Color{
  
private:
  // Data members
  rgb ** imgArray;
  int width;
  int height;
  ifstream ifile;
  ofstream ofile;
  int r,g,b,gray;
  //Methods
  
public:
  //Constructor
  Color (string filename){
    ifile.open(filename);
    ifile>>width>>height;
    imgArray = new rgb*[height];    //This array points to every row

    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
  }
  
  void writeFile(string filename){
      //Write out our color data to a new file
    ofile.open(filename);
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
  }
  
  void grayScale(){
      for(int i=0;i<height;i++){
          for(int j=0;j<width;j++){
              r = imgArray[i][j].r;
              g = imgArray[i][j].g;
              b = imgArray[i][j].b;
              
              gray = (r+g+b)/3;
              
              imgArray[i][j].r = gray;
              imgArray[i][j].g = gray;
              imgArray[i][j].b = gray;
          }
      }
  }
};



int main(){
  
  Color myImage("bot.txt");
  myImage.grayScale();
  myImage.writeFile("bot2.txt");
    
  return 0;
}
