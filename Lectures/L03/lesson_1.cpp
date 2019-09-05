#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * arrayContainer
 * 
 *      A data type that holds additional information along with the array.
 *      This may not be something we would really do, but it allowed us to
 *      return multiple values from a function. 
 * 
 */
struct arrayContainer
{
    int *container;
    int size;
};

/**
 * printArray
 * 
 * Description:
 *      Prints the contents of an array to stdout
 * 
 * Params:
 * 
 *      int *x   : A pointer to our array
 *      int size : The size of our array.
 * 
 * Returns:
 * 
 *      void 
 */
void printArray(int *x, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

/**
 * printArray
 * 
 * Description:
 *      Prints the contents of an array to stdout by calling another
 *      version of the printArray function
 * 
 * Params:
 * 
 *      arrayContainer  : An array type that also contains size.
 * 
 * Returns:
 * 
 *      void 
 */
void printArray(arrayContainer h)
{
    printArray(h.container, h.size);
}

/**
 * loadArrayV1
 * 
 * Description:
 * 
 *      Loads data from a file into an array.
 * 
 * Params:
 * 
 *      string filename : file to open
 * 
 * Returns:
 * 
 *      arrayContainer
 * 
 */
arrayContainer loadArrayV1(string filename)
{
    arrayContainer data;        // create instance of our container
    data.container = NULL;      // set array pointer to null
    data.size = 0;              // set array size to zero

    ifstream fin;               // input file type
    fin.open("data.dat");       // connect fin to our actual file

    fin >> data.size;           // reads first value from file 
                                // (in this case it tells how many more values to read)

    data.container = new int[data.size];    // I now have an array of perfect size since I 
                                            // dynamically created it knowing how many slots
                                            // it needed

    for (int i = 0; i < data.size; i++)     // Loop exact number of times to fill in our array
    {
        fin >> data.container[i];           // read value from file
    }

    return data;    // return our data container
                    // Its one value, but a cheater way to return 2 things!
                    // In this case an array along with its size.
}

/**
 * loadArrayV2
 * 
 * Description:
 * 
 *      Loads data from a file into an array with the assumption
 *      that the FIRST value is the COUNT of what is in the rest of the file.
 * 
 * Params:
 * 
 *      string filename : file to open
 * 
 * Returns:
 * 
 *      arrayContainer
 * 
 */
arrayContainer loadArrayV2(string filename)
{
    arrayContainer data;        // declare instance
    data.container = NULL;      // array pointer set to NULL
    data.size = 0;              // size of array set to zero

    ifstream fin;           // input file type
    fin.open(filename);     // connect fin to our actual file

    int dummy = 0;          // A dummy var to read from our file into

    while (!fin.eof())      // While we are not at the end of file
    {
        fin >> dummy;       // Remember we will NOT reach the EOF if 
                            // we do not actually READ the file :)

        data.size++;        //track how many values being read
    }

    fin.clear();            // clear the eof flag
    fin.seekg(0);           // go back to beginning of file

    // Now we know how big the file is.
    // Dynamically allocate memory to accomodate that size.
    data.container = new int[data.size];

    // We are confident in the size, so lets use a for loop to 
    // read the data into our array.
    for (int i = 0; i < data.size; i++)
    {
        fin >> data.container[i];
    }

    return data;
}


int main()
{

    arrayContainer A = loadArrayV1("data.dat");
    printArray(A);

    cout << endl
         << endl;

    arrayContainer B = loadArrayV2("data2.dat");
    printArray(B);
}