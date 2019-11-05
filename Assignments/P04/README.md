## Program 4 - Caeser Cipher Class
#### Due: November 26<sup>th</sup>

### Overview

A polyalphabetic substitution simply means to replace one letter with another, in such a way that you can reverse the process to get the original message back. One of the most well known methods is the [Caeser cipher](https://en.wikipedia.org/wiki/Caesar_cipher) which simply "shifts" the alphabet by some value. For example, if we decide the "shift" value is 13, then our new alphabet would be:

```
          |00|01|02|03|04|05|06|07|08|09|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|
ORIGINAL: |A |B |C |D |E |F |G |H |I |J |K |L |M |N |O |P |Q |R |S |T |U |V |W |X |Y |Z |
SHIFTED : |N |O |P |Q |R |S |T |U |V |W |X |Y |Z |A |B |C |D |E |F |G |H |I |J |K |L |M |

```

Here is an alphabet shifted by 3:

```
          |00|01|02|03|04|05|06|07|08|09|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|
ORIGINAL: |A |B |C |D |E |F |G |H |I |J |K |L |M |N |O |P |Q |R |S |T |U |V |W |X |Y |Z |
SHIFTED : |X |Y |Z |A |B |C |D |E |F |G |H |I |J |K |L |M |N |O |P |Q |R |S |T |U |V |W |

```

If we had a message like `ATTACKATDAWN` we would use our new alphabet to "encrypt" this word by **substituting** the original letter with the **shifted letter**.

``` 
A = X
T = Q
T = Q
A = X
C = Z
K = H
A = X
T = Q
D = A
A = X
W = T
N = K
```

A C++ function to replicate this could be written like:

```cpp
// Assuming the word is UPPERCASE so ASCII A = 65
char shiftLetter(char letter, int shift){
    int intVal=0;

    intVal = (int)letter - 65;  // Turn it into an integer number between 0-25
    intVal += shift % 26;       // Shift the letter, using mod to wrap back around
    letter = intVal + 65;       // Turn integer back into an ascii upper case letter
    
    return letter;
}

You should write a better function that loops through a string and shifts each letter.

```

### Spaces & Punctuation

Typical encryption would remove all punctuation and spacing before encrypting. This makes sense, because leaving them in a string makes it much much easier (almost too easy) to crack the encryption. 

**HOWEVER!** For our assignment, we are ignoring spaces and punctuation and leaving them in the message (both plaintext and ciphertext). We want to make our messages readable! Which makes it more fun.

Pre-Processing your string is as easy as:
- Convert any character with ascii value between 97 & 122 (inclusive) to uppercase (by substracting 32).
- Ignore all other characters!


### Assignment

Write a complete C++ class called `CaeserCipher` that would include the following methods:

- Encrypt()             // encrypts a string given a specific shift value
- Decrypt()             // decrypts a string given a specific shift value
- UpperCase()           // a method that uppercases a string ( there are built in methods, but we will write our own)
- SetShift()            // sets the shift amount for your class (default should be 13)
- ReadCipherText()      // reads an encrypted file into a string
- WriteCipherText()     // writes an encrypted message to a file
- ReadPlainText()       // reads a plain text file into a string
- WritePlainText()      // writes a plain text string to a file

You will have to determine the parameters and return types for each method. 

Write a main driver function that shows the complete functionality of your `CaeserCipher` class by opening a plaintext file and encrypting it, then open an encrypted file and decrypting it. 



### Requirements

- Open the file [encrypted.txt](./encrypted.txt) and decrypt it using your own code!
- The first line tells you how many messages to read.
- Then you will read two lines for each message:
  - Shift value
  - Message to be decrypted.
- Create a file called `decrypted.txt` and write your decrypted messages to this file with a blank line between each message.
- Make sure you put the following block at the top:

```
YOUR NAME IN ALL CAPS
date
Program 4 Output
```

#### Bonus Requirement:

- Create a menu driven system that prompts the user:

```
1. Encrypt
2. Decrypt
Choice: 
```

- Either choice will accept a string, to the appropriate task, and echo message to the screen.

### Deliverables

- Create a folder called `program_4` in your `assignments` folder.
- In this folder create a file called `cipher.cpp` with c++ code that fulfills the requirements.
- Your `program_4` folder should contain:
    - `cipher.cpp` 
    - your intput file, `encrypted.txt`
    - your output file, which should be named `decrypted.txt`
- ANY file you use with your assignment should ALWAYS end up in your assignment folder. 
- Make sure you write a complete class to assist your solution.
- Make sure you implement all these methods:
  - `Encrypt()`          
  - `Decrypt()`             
  - `UpperCase()`          
  - `SetShift()`         
  - `ReadCipherText()`    
  - `WriteCipherText()`    
  - `ReadPlainText()`    
  - `WritePlainText()`     
- Comment your code as instructed in [P03](../P03/README.md).
- Print a copy of your code and output file and bring to class Thursday Nov 26<sup>th</sup> at the beginning of class.
  - Order: Code on top then output file. 
  - Stapled: Upper left corner (close to the corner).
  - Your name should be on each page ( NO HAND WRITING !!  ).
- FAILURE TO FOLLOW INSTRUCTIONS: 1 letter grade. 
