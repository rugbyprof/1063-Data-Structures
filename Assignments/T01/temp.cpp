#include <iostream>

using namespace std;

void print_diamond2(int N){
    string s(N,'*');

    cout<<s<<endl;
}

void print_diamond(int N)
{
    int i, j;
    int s = (N/2);
    for (i = 1; i <= N; i++){
        if (i % 2 == 1){
            continue;
        }
        for (j = 0; j < s; j++){
            cout << '.';
        }
        s--;
        for (int j = 0; j < i; j++){
            cout << '*';
        }
        cout << endl;
    }
    s = 2;
    for (i = N-2; i >= 1; i--){
        if (i % 2 == 1){
            continue;
        }
        for (j = s; j > 0; j--){
            cout << '.';
        }
        s++;
        for (int j = i; j > 0; j--){
            cout << '*';
        }
        cout << endl;
    }
}

int main()
{


    //print_diamond(4);
    //print_diamond(144);
    print_diamond2(8);

    return 0;
}