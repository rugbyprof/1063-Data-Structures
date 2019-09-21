#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // size of the array
    int N;
    // read in the size
    while (cin >> N)
    {
        // whether there are any positive numbers
        bool pos = false;
        // maximum sum of a sub-rectangle
        int max = 0;
        // create a 2d array (matrix)
        int mat[N][N];
        // read in all the values
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cin >> mat[r][c];
                if (mat[r][c] >= 0)
                {
                    pos = true;
                }
            }
        }
        // if there are positive numbers
        if (pos)
        {

            // for each possible first row
            for (int fr = 0; fr < N; fr++)
            {
                // where we will store the collapsed columns
                int collapsed[N] = {0};
                // for every row
                for (int r = fr; r < N; r++)
                {
                    // current sum and sum to be tested, reset every loop
                    int sum = 0;
                    int test = 0;
                    // for every column, add to the collapsed set up to the last row
                    for (int c = 0; c < N; c++)
                    {
                        collapsed[c] += mat[r][c];
                    }
                    // for every column, test possible sums of collapsed columns
                    for (int c = 0; c < N; c++)
                    {
                        test += collapsed[c];
                        if (test > sum)
                        {
                            sum = test;
                        }
                        // handle any negative numbers that appear
                        if (test < 0)
                        {
                            test = 0;
                        }
                    }
                    // test for maximum possible sum
                    if (sum > max)
                    {
                        max = sum;
                    }
                }
            }
            // output the value
            cout << max << '\n';
        }
        else
        {
            // if all the numbers are negative, just looking for the greatest
            max = mat[0][0];
            for (int r = 0; r < N; r++)
            {
                for (int c = 0; c < N; c++)
                {
                    if (mat[r][c] > max)
                    {
                        max = mat[r][c];
                    }
                }
            }
            // output the value
            cout << max << '\n';
        }
    }
}