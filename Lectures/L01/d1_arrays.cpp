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

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program \
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
    int evens = 0;  // var to keep track of evens

    // for loops work great when you know 
    // when to stop (size of an array for example)
    for (int i = 0; i < size; i++)
    {
        // num % 2 can only result in a `1` or a `0`
        // where `1` => odd and `0` => even
        if (A[i] % 2 == 0)
        {
            evens++;
        }
    }

    // return our even count
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
    int total = 0;  // variable to hold our total
                    // sum vars need initialized!

    // for loops great with arrays!
    for (int i = 0; i < size; i++)
    {
        // keep our running total
        total = total + A[i];
    }

    // return the total (sum)
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
    // for loops are great with _________________? 
    for (int i = 0; i < size; i++)
    {
        // write out value with a space
        cout << A[i] << " ";
    }

    // go to next line in output
    cout << endl;
}

/**
 * Main program driver
 */
int main(int argc, char **argv)
{

    int A[SIZE];    // declare integer array of SIZE (see CONSTANT at top of this file)

    // Since for loops are good with arrays, lets
    // mix it up a little bit!

    int i = 0;  // my array index

    // by boolean test: 
    //      true  => keep looping
    //      false => skip code block
    while (i < SIZE)    
    {
        A[i] = rand() % 100;

        // increment array counter every time
        // if we don't loop will go FOREVER!!
        i++;
    }

    // Printing our results to stdout
    cout << "Array Contents:";
    printArray(A, SIZE);

    cout << "Sum: " << sumArray(A, SIZE) << endl;

    cout << "Evens: " << countEvens(A, SIZE) << endl;
}