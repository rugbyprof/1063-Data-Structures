class DynArray
{
public:
    DynArray();
    DynArray(int);
    // this is what set does compared to a normal array
    // arr[x] = y;
    // arr.set(x, y);
    void set(int, int);
    // this is what get does compared to a normal array
    // arr[x];
    // arr.get(x);
    int get(int);
    // enlarges the array if its over 80% full
    void enlarge();
    // get the size of the array
    int size();

private:
    int _size;
    int *items;
    int count;
};