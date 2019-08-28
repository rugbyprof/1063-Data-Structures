/**
 * This program is a review of some 1043 (CS 1) topics.
 * 
 *  Functions
 *  Arrays
 *  For loops
 * 
 */
#include <iostream> // write to and read from stdin and stdout
#include <ctime>    // access system clock (we used for rand function)

using namespace std;

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program 
                // we capitalize constants so we know they are not variables!

/**
 * Function: countEvens
 * Description:
 *      Counts all the even elements in the array.
 * 
 * Params:
 *      int *A   : array of integers
 *      int size : size of array;
 * 
 * Returns:
 * 
 *      int - number of even integers in the array.
 */
int countEvens(int *A, int size)
{
    int evens = 0;

    for (int i = 0; i < size; i++)
    {
        if (A[i] % 2 == 0)
        {
            evens++;
        }
    }

    return evens;
}

/**
 * Function: sumArray
 * Description:
 *      Sums all the values in the array.
 * 
 * Params:
 *      int *A   : array of integers
 *      int size : size of array;
 * 
 * Returns:
 * 
 *      int - number of even integers in the array.
 */
int sumArray(int A[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total = total + A[i];
    }
    return total;
}


/**
 * Function: printArray
 * Description:
 *      Prints all the values in the array.
 * 
 * Params:
 *      int *A   : array of integers
 *      int size : size of array;
 * 
 * Returns:
 * 
 *      int - number of even integers in the array.
 */
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

/**
 * Main program driver
 */
int main(int argc, char **argv)
{

    int A[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        A[i] = rand() % 100;
    }

    cout<<"Array Contents:";
    printArray(A, SIZE);

    cout <<"Sum: "<< sumArray(A, SIZE) << endl;

    cout <<"Evens: "<<countEvens(A, SIZE) << endl;
}