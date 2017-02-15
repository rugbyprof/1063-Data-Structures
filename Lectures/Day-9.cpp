#include <iostream>

using namespace std;

int main() {
    int A = 73;
    int B = 31;
    int *C;
    int *D;
    int E = 11;
    int *F;
    int G = 13;
    int H = 42;

    C = &B;
    D = &H;
    F = &A;

    cout<<"Address A:"<<&A<<endl;
    cout<<"Address B:"<<&B<<endl;
    cout<<"Address C:"<<&C<<endl;
    cout<<"Address D:"<<&D<<endl;
    cout<<"Address E:"<<&E<<endl;
    cout<<"Address F:"<<&F<<endl;
    cout<<"Address G:"<<&G<<endl;
    cout<<"Address H:"<<&H<<endl;

    cout<<&D<<endl;
    cout<<&E<<endl;
    cout<<*D<<endl;
    cout<<*F<<endl;
    cout<<F<<endl;
    cout<<A<<endl;
    //cout<<*E<<endl; //error
    cout<<&G<<endl;
    C = &A;
    cout<<*C<<endl;
    *F=*D;
    cout<<*F<<endl;
    
    char *Z = new char[10];
    
    for (int i=0;i<10;i++){
      
        Z[i] = char(i+65);
    }
    
    for (int i=0;i<10;i++){
      
        cout<<Z[i]<<endl;
    }
    
    cout<<*(Z+2)<<endl;
    
    
    
}
