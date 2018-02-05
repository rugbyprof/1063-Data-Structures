#include <iostream>

using namespace std;

class intArrayStats{
  private:
    int *A;
    int Size;
  public:
  intArrayStats();
  intArrayStats(int);
  intArrayStats(int*,int);
  double Average();
  int Max();
  int Min();
  int Mode();
};