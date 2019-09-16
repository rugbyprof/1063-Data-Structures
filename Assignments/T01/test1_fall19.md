Name ________________________

## Test 1 - Functions and Arrays

#### Instructions:
- Put your name on all pieces of paper at the top right.
- Write neatly keeping your code straight and use proper indentation.
- It is not my job to decipher your answers, it is your job to clearly portray an answer.
- Use pencil only.
- Number your answers and clearly delineate them as well.
- Do not cut off an answer between pages. Plan ahead. 
- Keep your answers in order.
 
**1)**

Write a function that receives 2, 1D arrays. It sums up the values in both arrays and returns that value. Call your function `sumArrays`

**2)**

Write a function that will return a confirmation if a "key" (some value) exists in a 2D array and returns that confirmation. Write your function for an array of integers. Name your function `findKey`

**3)**

 Write a function that would print out the following pattern with a parameter of 6:
 
 ```
   **
  ****
 ******
  ****
   **
 ```

Same call with a value of 8:
 ```
    **
   ****
  ******
 ********
  ******
   ****
   **
 ```

**4)**

 ```
 struct Stats{
   int min;
   int max;
   double avg;
}; 
```

Write a function that finds the min, max, and avg of some given array, and returns the calculated values in a struct like the one above. Name your function `aggregateVals`

**5)**

Write a constructor for the `Stats` struct to initialize its data members with correct values. Pay attention to data types.

**6)**
Write a function that finds the smallest value in a 2D array of ints, and returns the smallest value. Call your function `findMin`

**7)**

Write a code snippet that would ask a user for a number and then allocate an integer array with the size of the number entered.  (snippet means not an entire program, just the code required to answer the question).

#### Given
```cpp
   int a[] = {10, -3, 6, 6, -3, 6,8,10};
```

**8)**
```cpp
  int n = 0;
  for (int i=0; i<8; i++) {
    if (a[i] < 0) {
      n++;
    }
  }
```
What is `n`?

**9)**
```cpp
  int n;
  for (int i=0; i<1; i++) {
    a[i] = a[i]+1;
  }
  n = a[2];
```
What is `n`?

**10)**

```cpp
  int n = 0;
  for (int i=0; i<8; i++) {
    for (int j=i+1; j<4; j++) {
      if (a[i] == a[j]) {
         n++;
      }
    }
  }
```
What is `n`?