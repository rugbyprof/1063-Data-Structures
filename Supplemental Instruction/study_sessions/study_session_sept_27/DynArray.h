class DynArray
{
public:
    DynArray();
    DynArray(int);
    void set(int, int);
    int get(int);
    void enlarge();
    int size();

private:
    int _size;
    int *items;
    int count;
};