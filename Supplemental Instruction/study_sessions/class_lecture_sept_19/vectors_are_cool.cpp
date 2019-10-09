#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    // vector<string> names;
    // names.push_back("Jeremy");
    // names.push_back("Griffin");
    // names.push_back("Bob");
    // for (int i = 0; i < names.size(); i++){
    //     cout << names[i] << endl;
    // }
    // names.pop_back();
    // for (int i = 0; i < names.size(); i++){
    //     cout << names[i] << endl;
    // }

    // create an alphabet vector
    vector<char> alphabet;
    for (int i = 0; i < 26; i++)
    {
        alphabet.push_back('a' + i);
    }
    // print the alphabet
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i];
    }
    cout << endl;
    // erase 'c'
    alphabet.erase(alphabet.begin() + 2);
    // print the alphabet
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i];
    }
    cout << endl;
    // remove a bunch of letters
    alphabet.erase(alphabet.begin(), alphabet.begin() + 4);
    // print the alphabet
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i];
    }
    cout << endl;
    // insert at index 7
    alphabet.insert(alphabet.begin() + 7, '7');
    // print the alphabet
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i];
    }
    cout << endl;
}