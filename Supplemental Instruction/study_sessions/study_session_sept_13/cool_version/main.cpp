#include <iostream>
#include <string>
using namespace std;

void print_diamond(int input)
{
    if (input % 2 == 0)
    {
        // print diamonds with even inputs
        // r is row #, k is # of asterisks
        for (int r = 1, k = 2; r <= input - 1; r++)
        {
            int spaces = input - k;
            // print the first set of spaces for the row
            cout << string(spaces / 2, ' ');
            // print the asterisks
            cout << string(k, '*');
            // print the second set of spaces
            cout << string(spaces / 2, ' ');
            // print a new line
            cout << '\n';
            // increase or decrease the number of asterisks for the next row
            // if (r < input / 2)
            //     k += 2;
            // else
            //     k -= 2;
            // the line below is equivalent to the commented out code above
            k += r < input / 2 ? 2 : -2;
        }
    }
    else
    {
        // print diamonds with odd inputs
        // r is row #, k is # of asterisks
        for (int r = 1, k = 1; r <= input; r++)
        {
            int spaces = input - k;
            // print the first set of spaces for the row
            cout << string(spaces / 2, ' ');
            // print the asterisks
            cout << string(k, '*');
            // print the second set of spaces
            cout << string(spaces / 2, ' ');
            // print a new line
            cout << '\n';
            // increase or decrease the number of asterisks for the next row
            k += r < input / 2 + 1 ? 2 : -2;
        }
    }
}

int main()
{
    for(int i = 1; i <= 80; i++){
        print_diamond(i);
    }
    return 0;
}