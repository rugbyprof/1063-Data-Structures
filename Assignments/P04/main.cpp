#include <fstream>
#include <iostream>
#include <string>

using namespace std;

char shiftLetter(char letter, int shift) {
    int intVal = 0;

    intVal = (int)letter - 65; // Turn it into an integer number between 0-25
    intVal += shift % 26;      // Shift the letter, using mod to wrap back around
    letter = intVal + 65;      // Turn integer back into an ascii upper case letter

    return letter;
}

void ProcessFile(string filename){
    ifstream fin;
    fin.open(filename);

    string str_message_count;
    int int_message_count;

    string str_shift;
    int int_shift;

    string message;

    // get message count to know how many messages
    // to read
    getline(fin, str_message_count);

    // convert a string "int" to an actual int
    int_message_count = stoi(str_message_count);

    // loop over number of messages
    for (int i = 0; i < int_message_count; i++) {
        // get shift value (as a string)
        getline(fin, str_shift);

        // get message (also as a string :) )
        getline(fin, message);

        // convert str shift to an integer
        int_shift = stoi(str_shift);

        // loop over the message and print out each letter
        for(int m=0;m<message.size();m++){
            cout<<message[m];
        }
        cout<<endl;
    }
}

int main(int argc, char **argv) {

    ProcessFile("encrypted.txt");

    cout<<"A gets shifted to: "<<shiftLetter('A',33)<<endl;
}