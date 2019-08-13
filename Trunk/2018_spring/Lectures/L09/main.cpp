#include <iostream>
#include "intArrayStats.h"


int main() {
  
  int *nums = new int[300];
  
  for(int i=0;i<300;i++){
    nums[i] = rand()%100;
  }
  

  intArrayStats S(nums,300);
  S.Mode();
}