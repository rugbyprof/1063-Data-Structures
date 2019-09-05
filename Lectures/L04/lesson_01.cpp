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
    T **array;
    // data members
public:
    // constructor
    TwoDarray()
    {
        array = new T *[10];

        for (int i = 0; i < 10; i++)
        {
            array[i] = new T[10];
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                array[i][j] = rand();
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    // methods
};

int main()
{
    TwoDarray<int> A;


}