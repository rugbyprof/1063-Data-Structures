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

//Class declaration
class Color{
// Private section holds data and methods that shouldn't be accessed
// by any code outside of the class directly.
private:
  // Data member declarations 
  // (all the "data" our methods will work on)
  rgb ** imgArray;
  int width;
  int height;
  ifstream ifile;
  ofstream ofile;
  int r,g,b,gray;

  //Methods
public:
  // Constructor is a function with the same name as the class
  // it initializes an data members we need initialized.
  // This constructor has a "filename" as a parameter
  // and it will use the file to get the proper info to build
  // and load a dynamic 2D array.
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
  
  // This method writes the contents of our 2D array
  // to a file (we specify which file with the name
  // we pass in to the function (or method as class
  // functions are methods).
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
  
  // This is a PROPER comment for a function:
  /**
   * Function: grayScale
   * Description:
   *     This method loops through a 2D array of RGB values and turns each pixel into a gray
   *     scaled pixel. It does this by averaging the 3 RGB values, then writing a single value
   *     back to each R, G, B. 
   *     Example:   rgb(255,192,203) (pink) would turn into 
   *                (255+192+203)/3 = 216
   *                rgb(216,216,216) 
   * Params:
   *    none
   * Returns:
   *    none
   */
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


// Main reads much nicer with all the work
// now in the class!
int main(){
  
  Color myImage("bot.txt");
  myImage.grayScale();
  myImage.writeFile("bot2.txt");
    
  return 0;
}
