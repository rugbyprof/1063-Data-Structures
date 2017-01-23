#include <iostream>
#include <fstream>

using namespace std;

struct Rgb{
  int r;
	int g;
	int b;
};

class Image{
    private:
    Rgb **ImageArray;
    public:
    Image(int width,int height,char *data_file){
        int r,g,b;
        int row = 0;
        int col = 0;
        
        ImageArray = new Rgb*[height];
        for (int i=0;i<height;i++){
          ImageArray[i] = new Rgb[width];
        }
        
        ifstream ifile;
        ifile.open(data_file);
        
        
        while(!ifile.eof()){
          ifile>>ImageArray[row][col].r;
          ifile>>ImageArray[row][col].g;
          ifile>>ImageArray[row][col].b;
          col++;
          if(col == width){
            col = 0;
            row++;
          }
        }
    }
    Rgb GetColor(int x,int y){
      
    }
    void ChangeColor(int x,int y,Rgb color){
      
    }
    void GrayScale(){
    
    }
};


int main(){
  
  Image myimage(10,10,"data.csv");
  
	return 0;
}
