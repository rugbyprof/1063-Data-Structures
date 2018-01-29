## 2D Array - General Overview

### Overview

A regular array in C++ is declared like so:

```cpp
int A[10];
```

This allocates 10 4byte memory locations with the starting address stored at a location pointed to by `A`. Each memory location is undefined. 

|   |   |   |   |   |   |   |   |   |   |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |

We could initialize each array location like so:

```cpp
for(int i=0;i<10;i++){
    A[i] = 0;
}
```

OR, we could initialize each memory location like:

```cpp
int A[10] = {0};
```

