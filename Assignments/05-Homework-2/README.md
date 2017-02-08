## Recursion Homework
Due: TBD

### Requirements

- Create a folder called `Homework_2` and place it in your `assignments` folder.
- Create a markdown document called `recursion.md` and place it in your `Homework_2` folder.
- Turn a printed copy of your assignment on the day it is due. Place it in front of class at the beginning of class.
- A fully digital document is preferred, but if you need to draw by hand, simply take a clear photo of your drawing, crop it and link to it by adding your image to your `Homework_2` folder and use the following markdown syntax: `![](./photoname.extension)` (e.g. `![](./trace1.jpg)`)

1. Trace A(‘C’)    2.Trace A(‘3’)

```cpp
void A (char ch){
  if(('A'<= ch) && (ch <= 'H')){
    A(ch-1);
    cout<<ch<<endl;
  }else{
    cout<<endl;
  }
}
```

3. Trace B(4)

```cpp
int B (int n){
  if(n==0)
    return 1;
  else{
    cout<<n<<endl;
    return n * B(n-1);
  }
}
```
4. Trace C(16)

```cpp
int C (int n){
  if(n<2)
    return 0;
  else
    cout<<n<<endl;
    return (1 + C(n/2));
}
```

5. Trace D(-2365)

```cpp
int D (int n){
  if(n<0)
    return D(-n);
    if(n<10){
      cout<<n<<endl;
      return n;
    }else{
      cout<<n<<endl;
      return D(n/10);
  }
}
```

Write recursive functions to solve the following problems then trace the given value(s).

6. Write a function that will count the number of digits in a nonnegative integer. Trace for ***5679***.

```cpp
int NumDigits(int num){
    // Returns the "length" of an integer
}
```

7. Write a function `MyPow()` - Which will raise a given number to a power. Trace for ***2<sup>3</sup>***.

```cpp
int MyPow(int base, int exp)
    // Returns base^exp
    
    
)
```

8. Complete the function and trace for ***`A[2,4,5,7,8,11]`***

```cpp
int SumArray(int A[], int n)
    // Return sum of A[0] + A[1] + … + A[n-1]
    
    
)
```
