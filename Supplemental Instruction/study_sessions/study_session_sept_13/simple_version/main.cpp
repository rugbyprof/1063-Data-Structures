#include <iostream>
using namespace std;

// function only works if the input is even. We could make a version for odd
// pretty easily but it would be big. The other version of the code accounts
// for even/odd and looks nicer.
void print_diamond(int input)
{
    // r is row #, k is # of asterisks
    for (int r = 1, k = 2; r <= input - 1; r++)
    {
        int spaces = input - k;
        // print the first set of spaces for the row
        for (int i = 0; i < spaces / 2; i++)
        {
            cout << ' ';
        }
        // print the asterisks
        for (int i = 0; i < k; i++)
        {
            cout << '*';
        }
        // print the second set of spaces
        for (int i = 0; i < spaces / 2; i++)
        {
            cout << ' ';
        }
        // print a new line
        cout << '\n';
        // increase or decrease the number of asterisks for the next row
        if (r < input / 2)
        {
            k += 2;
        }
        else
        {
            k -= 2;
        }
    }
}

int main()
{
    print_diamond(6);
    print_diamond(8);

    return 0;
}