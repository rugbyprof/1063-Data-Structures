#include <iostream>

using namespace std;

char shiftLetter(char letter, int shift){
    int intVal=0;

    intVal = (int)letter - 65;  // Turn it into an integer number between 0-25
    intVal += shift % 26;       // Shift the letter, using mod to wrap back around
    letter = intVal + 65;       // Turn integer back into an ascii upper case letter
    
    return letter;
}

int main(int argc , char** argv){
    cout<<shiftLetter('A',33)<<endl;
}