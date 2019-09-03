#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printTemp(string one,string two,int count, int nums[]){
  cout<<one<<" "<<two<<" "<<count<<endl;
  for(int i=0;i<count;i++){
     cout<<nums[i]<<" ";
  }
  cout<<endl;
}

int main(int argc, char** argv){
    string one ,two;
    int count;
    int nums[10];
    ifstream temp;

    temp.open("temp.txt");

    temp>>one>>two>>count;
    for(int j=0;j<count;j++){
        temp>>nums[j];
    }
    printTemp(one,two,count,nums);

    temp>>one>>two>>count;
    for(int j=0;j<count;j++){
        temp>>nums[j];
    }
    printTemp(one,two,count,nums);

    temp>>one>>two>>count;
    for(int j=0;j<count;j++){
        temp>>nums[j];
    }
    printTemp(one,two,count,nums);
}