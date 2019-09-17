Name **********____**********

# Test 1 - Functions and Arrays - Take Home Help

## Instructions:

- Every thing will be done using digital media, then printed by a printer.
- Put your name on first page at the top.
- Keep your code neat and use proper indentation.
- Number your answers and clearly delineate them.
- Keep your answers in order.

#### Note 1:
- **_Functions DO NOT print out messages._**
    - Unless that is the purpose of the function.
    - Or the function is printing an error message.
- **_Functions calculate values to be returned to the caller._**

#### Note 2:

- Functions nearly always receive parameters.
- Those are the values they need to do thier job. 
- Typically a function does something with the parameters, then returns an answer based on what it just did. 
- If you feel the need to print something out in a function (for our class), don't.
- For the time being your functions will:
    - Receive values
    - work on said values
    - return an answer based on the work it just did

Here's a function template

```
returnType FunctionName(paramType1 param1, paramType2 param2, .... paramTypeN paramN){
    variable declarations to help with calculations

    code goes here that works on params

    return same kind of var as the returnType
}
```

#### Simple Function Example:

```cpp
/**
 * Function SumNums
 * Purpose:
 *    Sums two numbers and returns answer 
 * 
 * Params:
 *     int A : first part of sum
 *     int B : second part of sum
 * Returns:
 * 
 *     int : sum of nums
 */
int SumNums(int A, int B){  // params that contrubute to the answer
    int sum = 0;            // local variable to help with calculations

    sum = A + B;            // perform the calculations

    return sum;             // return your answer
}
```

#### Better Example:

- Write a function that receives a 1D array and returns true if some int key is in the array of integers.
- Call your function `keyExists`

>
>
>

- Ok I know my function is working on an array, so thats one parameter
- I also should remember that size always must accompany my array so I can stop looping when I need to. 
- I'm looking for a key in the array, so I need to pass that in as well.

```cpp
/**
 * Function keyExists
 * Purpose:
 *    Find a key in an array, return true if its there
 * 
 * Params:
 *     int A[] : array of integers
 *     int size: size of array
 *     int key : number I'm looking for
 * Returns:
 *     bool : true if number exists, false otherwise
 */
int keyExists(int A[], int size, int key){  // params that contrubute to the answer
    bool exists = false;                    // local variable to help with calculations

    for(int i=0;i<size;i++){                // perform the calculations
        if(A[i] == key){
            exists = true;
        }
    }
    return exists;                          // return your answer
}
```

**1)**

- Write a function that receives 3, 1D arrays.
- They are all the same size.
- It sums up the values in all arrays and returns that value.
- Call your function `sumArrays`

**2)**

- Write a function that will average integer values in a 2D array.
- Assume the 2D array has the same width and height.
- Name your function `avg2D`
- Remember averaging integers does not always result in an integer.

**3)**

Write a function that would print out the following pattern:

| Parameter of 4 | Parameter of 6                   |
| :------------- | :------------------------------- |
| x              | x                                |
| xx             | xx                               |
| xxxx           | xxxx                             |
| xxxxxxxx       | xxxxxxxx                         |
|                | xxxxxxxxxxxxxxxx                 |
|                | xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx |


**4)**

```c++
struct Stats{
   int min;
   int max;
   double avg;
   int sum;  
};
```

- Write a function that calculates all the values in the Stats struct when given an array of integers.
- Return your values in an instance of the struct.  
- Name your function `aggregateVals`


**5)**

- Write a constructor for the `Stats` struct to initialize its data members with correct values. 
- Pay attention to data types.


**6)** 

- Write a function that computes the standard deviation for a 1D array of integers.
- Call your function `calcStdDev`.
- Standard Deviation:
    1. Work out the Mean (the simple average of the numbers)
    2. Then for each number: subtract the Mean and square the result
    3. Then work out the mean of those squared differences.
    4. Take the square root of that and we are done!


**7)**

- Write a function that will dynamically allocated memory of a given size for an integer array.
- Then it will return that new array initialized with zeros.
- Call it `initIntArray`
