## Test 3 : Recall and Apply Assessment

## Q1

What are the 3 components necessary to write a recursive function.

## Q2 

Write a recursive function to sum the digits in an integer.

## Q3 

This code is to help you complete a fraction class explained below this code block. 
```cpp
// Greatest common divisor
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
  
// Function to convert the obtained fraction into it's simplest form 
Fraction reduce(Fraction F) 
{ 
    // Finding gcd of both terms 
    int common_factor = gcd(F.numerator,F.denominator); 
  
    // Converting both terms into simpler  
    // terms by dividing them by common factor  
    F.denominator = F.denominator/common_factor; 
    F.numerator = F.denominator/common_factor; 
    return F;
} 

// Creating a fraction
Fraction F1;        // results in a fraction 1/1
Fraction F2(2/3);   // results with numerator = 2 and denominator = 3

```


- Write a **complete class definition** to represent a single `Fraction`. 
- Each fraction will have integer numerators and denominators. 
- There are two ways to declare a new fraction (see example code above).
- Fractions cannot have a denominator of 0.
- Your class will only implement **adding** and **multiplying** of two fractions.
- Printing a fraction should look like: `(2/3)` with parens around the values.
- Don't forget all the little things that are necessary for a complete class definition.

