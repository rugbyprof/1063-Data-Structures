/**
 * This program is a review of some 1043 (CS 1) topics.
 * 
 * Functions
 * Structs
 * Arrays of Structs
 * 
 */
#include <iostream> // write to and read from stdin and stdout
#include <ctime>    // access system clock (we used for rand function)
#include <string>   //
#include <fstream>  // read a write files

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program \
                // we capitalize constants so we know they are not variables!

using namespace std; // so we don't have to put std:: in front of cin, cout.

/**
 * Structs are like creating your own data type. 
 * We can use this struct to represent a student and thier grades.
 * 
 * Remember, to declare a variable we use the following:
 *   
 *      int x;
 * 
 * To use our new struct we do the same:
 * 
 *      Student S;
 * 
 * Then we can load it with data like:
 * 
 *      S.fname = 'Susan';
 *      S.lname = 'Sarandon';
 *      S.numGrades = 1;
 *      S.grades[0] = 88;
 * 
 */
struct Student
{
    string fname;
    string lname;
    int numGrades;
    int grades[10];

    Student(string f,string l,int g,int a[]){
        fname = f;
        lname = l;
        numGrades = g;
        for(int i=0;i<g;i++)
            grades[i] = a[i]; 
    }
};

/**
 * Function: loadClassList
 * Description:
 *      Reads a file with student data, and loads it into an array of Students.
 * 
 * Params:
 *      Student *classlist  : array of Students
 *      string  filename    : name of file to process
 * 
 * Returns:
 *      int - number of students read in. 
 */
int loadClassList(Student *classList, string fileName)
{
    ifstream fin;       // get a stream variable
    fin.open(fileName); // open the stream using our fileName param
    int i = 0;          // index (counter)

    // While we have not reached the end of file
    while (!fin.eof())
    {
        // Read one line in the file into one struct at array location `i`
        fin >> classList[i].fname >> classList[i].lname >> classList[i].grades[0] >> classList[i].grades[1];

        // increment `i`
        i++;
    }

    // return sudent count
    return i;
}

/**
 * Function: printClassList
 * 
 * Description:
 *      Prints an array of students to stdout
 * 
 * Params:
 * 
 *      Student *classList : array of structs (and the structs are `Students`)
 *      int     classSize  : size of class (returned from `loadClassList` )
 * 
 * Returns:
 * 
 *      void
 */
void printClassList(Student *classList, int classSize)
{
    for (int i = 0; i < classSize; i++)
    {
        cout << classList[i].fname << " "
             << classList[i].lname << " "
             << classList[i].grades[0] << " "
             << classList[i].grades[1] << endl;
    }
}

/**
 * Function: main
 * 
 * Description:
 *      Drives this example of structs and arrays
 */
int main()
{
    //srand(time(0));   // seed with time(0) means no predictable output
    srand(2345);        // seed with integer means same randoms generated every time


    int A[SIZE];        // Array to hold students read from file
    Student s0;         // 
    Student s1;         
    Student classList[100];
    int classSize = 0;


    // Example student structs and assigning data to a struct
    // using the `.` (dot) operator.
    s0.fname = "Harriet"; 
    s0.lname = "Smith";
    s0.grades[0] = 88;
    s0.grades[1] = 91;

    
    s1.fname = "Joseph";
    s1.lname = "Wilson";
    s1.grades[0] = 20;
    s1.grades[1] = 34;

    // Call the loadClassList function to open a file and load an array
    // of `Student` structs.
    classSize = loadClassList(classList, "simple_input_data.txt");

    // Function returned how many lines (students) read in, lets print it.
    cout << "Class Size: " << classSize << endl;

    // Function to print out an array of students in a formatted way.
    printClassList(classList, classSize);


    return 0;
} 