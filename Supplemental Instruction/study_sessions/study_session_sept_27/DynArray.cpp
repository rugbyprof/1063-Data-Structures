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
        if (items[index] == INT_MIN)
        {
            count++;
        }
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
    int *copy;
    int old_size = _size;
    if (count >= .8 * _size)
    {
        _size = int(_size * 1.5);
        copy = new int[_size];
        for (int i = 0; i < old_size; i++)
        {
            copy[i] = items[i];
        }
        for (int i = old_size; i < _size; i++)
        {
            copy[i] = INT_MIN;
        }
        delete[] items;
        items = copy;
    }
}

int DynArray::size()
{
    return _size;
}