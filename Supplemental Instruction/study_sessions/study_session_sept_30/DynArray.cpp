#include "DynArray.h"
#include <climits>

DynArray::DynArray()
{
    _size = 100;
    items = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        items[i] = INT_MIN;
    }
    count = 0;
}

DynArray::DynArray(int start_size)
{
    _size = start_size;
    items = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        items[i] = INT_MIN;
    }
    count = 0;
}

void DynArray::set(int index, int value)
{
    if (value != INT_MIN)
    {
        // if we're replacing a sentinel value (adding a new item)
        // we should increase the count (number of items)
        if (items[index] == INT_MIN)
        {
            count++;
        }
        // set the value in the items array at position index
        items[index] = value;
    }
    enlarge();
}

int DynArray::get(int index)
{
    return items[index];
}

void DynArray::enlarge()
{
    // the new array of a larger size
    int *copy;
    // keeps track of the old size
    int old_size = _size;
    // should we resize (if its over 80% full)
    if (count >= .8 * _size)
    {
        // change size to be bigger (and make sure its an integer)
        _size = int(_size * 1.5);
        // create the new array
        copy = new int[_size];
        // copy all the old values to the new array
        for (int i = 0; i < old_size; i++)
        {
            copy[i] = items[i];
        }
        // initialize the new array slots to be the sentinel value
        for (int i = old_size; i < _size; i++)
        {
            copy[i] = INT_MIN;
        }
        // delete the old array
        delete[] items;
        // set items to the new array
        items = copy;
    }
}

int DynArray::size()
{
    return _size;
}