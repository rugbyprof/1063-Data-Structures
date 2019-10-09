#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // int nums[??];
    vector<int> nums;

    // nums[0] = 5;
    nums.push_back(5);

    // populate a vector with random numbers
    srand(42);
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(rand() % 100);
    }

    // prints vector
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }

    cout << "Size of vector " << nums.size() << endl;

    // destroy the vector and print it backwards
    while (nums.size() > 0)
    {
        nums.pop_back();
        cout << "Size of vector " << nums.size() << endl;
    }

    return 0;
}