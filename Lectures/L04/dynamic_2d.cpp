/**
 * Class lecture code
 * 
 * Written by: Terry Griffin
 * Class : CMPS 1063
 * Date: 15 Sep 19
 */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool exists(const std::string &name)
{
    ifstream f(name.c_str());
    return f.good();
}

// represent a 2D array
// sum
// flip
// rotate
// zero out method
// swap

// definition
template <typename T>
class TwoDarray
{
private:
    // data members
    T **array;
    int rows;
    int cols;
public:
    // constructor
    TwoDarray(int r,int c)
    {
        rows = r;
        cols = c; 
        
        array = new T *[rows];

        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                array[i][j] = 0;
            }
        }


    }
    // methods
    void PrintArray(){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    TwoDarray<int> A(10,30);

    A.PrintArray();

}