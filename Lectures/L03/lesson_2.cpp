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
        int count = 1;

        while (!fin.eof()) 
        {
            fin >> dummy; 
            //cout<<dummy<<endl;
            count++; 
        }
        
        fin.clear();  // clear the eof flag
        fin.seekg(0); // go back to beginning of file

        resize(count+5);

        cout<<count<<endl;
        int i = 0;

        cout<<"Size: "<<sizeof(array)<<endl;

        while(!fin.eof())
        {
            cout<<i<<endl;
            fin >> array[i];
            cout<<array[i]<< " ";
            i++;
        }

    }
};


int main()
{

    container<string> A;

    A.load("data3.dat");

    // container<int> B;

    // B.load("data2.dat");

}