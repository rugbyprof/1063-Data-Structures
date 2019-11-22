#include <iostream>
#include <fstream>
#include "BigNum.h"

using namespace std;

///////////////////BROKEN////////////////////////

int main(){
    // BigNum B1("87962986724958672934865792348657");
    // BigNum B2("37262365187365182541234432");

    BigNum B1;
    BigNum B2;
    BigNum B3;

    B1 = "123456789123456789";
    B2 = "12345";


    cout<<B1<<endl;
    cout<<B2<<endl;
    cout<<B3<<endl;

    B3.Add(B1);
    B3.Add(B2);

    cout<<B3<<endl;
    return 0;
} 