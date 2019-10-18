/**
 * Topic: Recursion
 * Aurhor: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: October 2019
 * Description:
 *    Fun recursive functions ...
 */
#include <iostream>

using namespace std;

void PrintDigitsTheCoolWay(int val){
  if(val == 0){
    return;
  }

  cout<<val%10<<endl;
  PrintDigitsTheCoolWay(val/10);
  
}

// iterative solution
void PrintDigits(int val){

  while(val > 0){
    cout<<(val%10)<<endl;
    val = val / 10;
    //cout<<val<<endl;
  }

}

void SumDigits(int val,int &sum){
  if(!val){
    return;
  }

  sum += val % 10;
  SumDigits(val/10,sum);
}

int  SumDigitsV2(int val){
  if(!val){
    return 0;
  }
  return (val % 10) + SumDigitsV2(val/10);
}



int main() {
  PrintDigits(84931);
  cout<<endl<<endl;
  PrintDigitsTheCoolWay(84931);
  int sum = 0;

  SumDigits(84931,sum);
  cout<<sum<<endl;
  cout<<endl<<endl<<SumDigitsV2(84931);

  return 0;
}