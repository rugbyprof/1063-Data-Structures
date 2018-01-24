## Homework 1 - Practice with arrays

#### Given

### 1)
```cpp
   int a[] = {25, -3, 6, 0, -3, 6};
   
   int n = a[1];
```

```cpp
n = 
```

### 2)
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

### 3)
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

### 4)
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

### 5)
```cpp
n = a[3]+1;
```

```cpp
n = 
```

### 6)
```cpp
n = a[3+1];
```

```cpp
n = 
```

### 7)
```cpp
n = a[3+1]+1;
```

```cpp
n = 
```


### 8)
```cpp
n = a[3+1]+a[1];
```

```cpp
n = 
```

### 9)
```cpp
What does the array look like after the following:

a[3+1] = a[3]+1;
```

```cpp
a = 
```

### 10)
```cpp
a[3] = a[3]+a[1+3]*2;
```

```cpp
a = 
```


#### Deliverables

- In your `assignments` folder on github:
   - Create a folder called `homework_1`
   - In this folder have a file called `1d_answers.md` with your solution
   