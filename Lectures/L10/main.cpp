/**
 * Topic: Binary Search
 * Aurhor: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: October 2019
 * Description:
 *    Shows use of a binary search implementation compared to a linear search.
 */
#include <chrono>
#include <iostream>
#include <math.h>

using namespace std;


/**
 * Swap
 * 
 * Description:
 *      Swaps to values in thier original memory locations
 * 
 * Params:
 *      int *a : location 1 (the '*' accesses the location to get the value)
 *      int *b : locatoin 2
 * 
 * Returns:
 *      void
 */
void swap(int *a, int *b) {
    int temp = *a; // put first value in temp location
    *a = *b;       // overwrite location1 with value at location2
    *b = temp;     // overwrite location2 with value from temp
}

/**
 * BubbleSort
 * 
 * Description:
 *      Sorts an array of integers in ascending order.
 *      We need an ordered array to do a binary search on it.
 * 
 * Params:
 *      int A[]  : array of int's
 *      int size : size of array
 * 
 * Returns:
 *      void
 */
void BubbleSort(int A[], int size) {

    bool swapped = false; // flag to tell us if a swap was made
                          // if no swap made, we can quit

    for (int i = 0; i < size; i++) {
        swapped = false; // re-set swap variable
        for (int j = 0; j < size - 1 - i; j++) {
            if (A[j] > A[j + 1]) {

                swapped = true;         // array not in order still
                swap(&A[j], &A[j + 1]); // call the swap function with the "addresses: &" of
                                        // the two values that we are swapping
            }
        }
        // If no number was swapped, the array
        // is in order so we can break out
        if (swapped == false) {

            break;
        }
    }
}

/**
 * LinearSearch
 * 
 * Description:
 *      Performs a search on a 1D array. Worse case O(n)
 * 
 * Params:
 *      int A[]  : array of int's
 *      int size : size of array
 *      int key  : value we are looking for
 * 
 * Returns:
 *      int      : the value if found, -1 otherwise
 */
int LinearSearch(int *A, int size, int key) {

    // loop through array comparing key to each
    // location. If found "return" stops the loop
    // and sends control back to who called this
    // function
    for (int i = 0; i < size; i++) {
        if (A[i] == key) {
            return A[i];
        }
    }
    return -1;
}

/**
 * BinarySearch
 * 
 * Description:
 *      Performs a binary search on a 1D ordered array. Runs in O(lg n)
 * 
 * Params:
 *      int A[]  : array of int's
 *      int size : size of array
 *      int key  : value we are looking for
 * 
 * Returns:
 *      int      : the value if found, -1 otherwise
 */
int BinarySearch(int *A, int size, int key) {
    int comparisons = 0; // count comparisons
                         // used to compare to linear search

    int small = 0;        // variable to index to left side
                          // (smaller values) of array
    int large = size - 1; // variable to index to the right side
                          // (larger values) of array

    int middle = (small + large) / 2; // middle of array

    // If we found the key, stop looking and return
    if (A[middle] == key) {
        return key;
    }

    //   0   1   2    3    4    5    6    7    8    9   10
    // +---+---+---+----+----+----+----+----+----+----+----+
    // | 3 | 5 | 8 | 11 | 13 | 16 | 21 | 32 | 33 | 45 | 50 |
    // +---+---+---+----+----+----+----+----+----+----+----+
    //   ^                     ^                         ^
    //   |                     |                         |
    // small                middle                     large

    // While the key is not pointed to by 'middle'
    // AND the small / large indexes have not converged with middle
    while (A[middle] != key && (small != middle || large != middle)) {

        comparisons++; // keep track of comparisons to show
                       // it finds items in O(lg n) comparisons

        if (key < A[middle]) { //go left (make middle the new right or 'large')
            large = middle - 1;
        } else { //go right (make middle the new left or 'small')
            small = middle + 1;
        }
        middle = (small + large) / 2; // re-calculate middle
    }

    // How many items did we look at
    cout << "comparisons: " << comparisons << endl;

    // If we found the key, return it
    // otherwise send back a sentinel value (-1)
    if (A[middle] == key) {
        return key;
    }
    return -1;
}

/**
 * TimeFacade - A wrapper around the chrono timing library
 *              to provide a simple timing interface.
 * 
 * 
 */
struct TimeFacade{

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    std::chrono::duration<double, std::milli> duration;

    TimeFacade(){
        t1 = std::chrono::high_resolution_clock::now();
    }

    void start(){
        t1 = std::chrono::high_resolution_clock::now();
    }

    void stop(){
        t2 = std::chrono::high_resolution_clock::now();
    }

    string getDuration(){
        t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = t2 - t1;
        auto x = chrono::duration_cast<std::chrono::microseconds>(elapsed_seconds);

        string result = to_string(x.count());

        return result;
    }
};

/**
 * Main Driver
 * 
 */
int main() {

    TimeFacade T;

    int size = pow(2, 15);  // 2^15 = 32768
    int *A = new int[size]; // dyanimically allocate a 32768 sized array

    int value;

    // Fill our array with random numbers
    // including duplicates
    for (int i = 0; i < size; i++) {
        A[i] = rand();
    }

    // Sort our large array
    std::cout << "Starting sort ... " << endl;
    T.start();
    BubbleSort(A, size);
    cout << "Done sorting ... " << endl;
    cout << "It took: " << T.getDuration() << " microseconds to sort the values." << endl;

    cout << "Starting linear search ... " << endl;
    T.start();
    value = LinearSearch(A, size, A[rand()%size]);
    cout << "Done searching ... " << endl;
    cout << "It took: " << T.getDuration() << " microseconds to perform linear search." << endl;


    cout << "Starting binary search ..." << endl;
    T.start();
    value = BinarySearch(A, size, A[rand()%size]);
    cout << "Done searching ... " << endl;
    cout << "It took: " << T.getDuration() << " microseconds to perform binary search." << endl;

}

