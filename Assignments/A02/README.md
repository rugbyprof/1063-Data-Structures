## Array Homework - Practice with arrays

#### Given

### 1)
```cpp
   int a[] = {25, -3, 6, 0, -3, 6};
   
   int n = a[1];
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

### 3)
```cpp
  int n;
  for (int i=0; i<6; i++) {
    a[i] = a[i]+1;
  }
  n = a[2];
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

### 5)
```cpp
n = a[3]+1;
```

### 6)
```cpp
n = a[3+1];
```

### 7)
```cpp
n = a[3+1]+1;
```

### 8)
```cpp
n = a[3+1]+a[1];
```

### 9)
```cpp
What does the array look like after the following:

a[3+1] = a[3]+1;
```

### 10)
```cpp
a[3] = a[3]+a[1+3]*2;
```



