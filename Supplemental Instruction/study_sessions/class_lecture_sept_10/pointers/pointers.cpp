#include <iostream>
using namespace std;

int main()
{
    int *ptr;
    int x = 5;
    ptr = &x;
    cout << "object at address " << ptr << " is " << *ptr << endl;
    cout << "addresss of pointer is " << &ptr << endl;
    int** dbl_ptr = &ptr;
    cout << "addresss of pointer is " << dbl_ptr << endl;
    cout << "addresss of first object is " << *dbl_ptr << endl;
    cout << "value of first object is " << **dbl_ptr << endl;
}