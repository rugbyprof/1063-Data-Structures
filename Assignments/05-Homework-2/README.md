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

6. Return the number of digits in a nonnegative integer. Trace for 5679.

7. Write `MyPow()` - Which will raise a given number to a power. For example `MyPow(10,3)` will return ***10<sup>3</sup>*** 

8. Complete the function and trace for A[2,4,5,7,8,11]
	int SumArray(int A[], int n)
	// Return sum of A[0] + A[1] + … + A[n-1]
