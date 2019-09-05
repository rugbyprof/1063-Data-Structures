#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool exists(const std::string &name)
{
    ifstream f(name.c_str());
    return f.good();
}

template <typename T>
struct container
{
    T *array;
    int size;

    container()
    {
        array = NULL;
        size = 0;
    }

    void resize(int s)
    {
        array = new T[size];
        size = s;
    }

    void load(string filename)
    {

        if(!exists(filename)){
            cout<<"Error: filename: "<<filename<<" could not be opened!"<<endl;
            exit(0);
        }

        ifstream fin;       // input file type
        fin.open(filename); // connect fin to our actual file

        T dummy; 
        int count = 0;

        while (!fin.eof()) 
        {
            fin >> dummy; 
            cout<<dummy<<endl;
            count++; 
        }

        count++;

        fin.clear();  // clear the eof flag
        fin.seekg(0); // go back to beginning of file


        resize(count);

        
        for (int i = 0; i < size; i++)
        {
            fin >> array[i];
        }

    }
};


int main()
{

    container<string> A;

    A.load("data3.dat");

    // arrayInfo AH = loadArray1("data.dat");

    // //printArray(AH.A,AH.size);
    // printArray(AH);
    // cout<<endl<<endl;
    //  arrayInfo AH2 = loadArray2("data2.whocares");

    //  printArray(AH2);
}