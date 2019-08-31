## Practice 1 - Practice with arrays
#### Due: No Due Date

#### Given

___1)___
```cpp
   int a[] = {25, -3, 6, 0, -3, 6};
   
   int n = a[1];
```

```cpp
n = 
```

___2)___
```cpp
  int n = 0;
  for (int i=0; i<6; i++) {
    if (a[i] < 0) {
      n++;
    }
  }
```

```cpp
n = 
```

___3)___
```cpp
  int n;
  for (int i=0; i<6; i++) {
    a[i] = a[i]+1;
  }
  n = a[2];
```

```cpp
n = 
```

___4)___
```cpp
  int n = 0;
  for (int i=0; i<5; i++) {
    for (int j=i+1; j<6; j++) {
      if (a[i] == a[j]) {
         n++;
      }
    }
  }
````

```cpp
n = 
```

___5)___
```cpp
n = a[3]+1;
```

```cpp
n = 
```

___6)___
```cpp
n = a[3+1];
```

```cpp
n = 
```

___7)___
```cpp
n = a[3+1]+1;
```

```cpp
n = 
```


___8)___
```cpp
n = a[3+1]+a[1];
```

```cpp
n = 
```

___9)___
```cpp
What does the array look like after the following:

a[3+1] = a[3]+1;
```

```cpp
a = 
```

___10)___
```cpp
a[3] = a[3]+a[1+3]*2;
```

```cpp
a = ?

```

#### Deliverables

- In your `assignments` folder on github:
  - Create a folder called `homework_1`
  - In this folder create a file called `1d_answers.cpp` with your solution.
