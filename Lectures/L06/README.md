## 2D Array - General Overview

### Overview

A regular array in C++ is declared like so:

```cpp
int A[10];
```

This allocates 10 4byte memory locations with the starting address stored at a location pointed to by `A`. Each memory location is undefined. 

| und  | und   | und   |  und  | und   |  und  | und   | und   |  und  | und   |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:| 
|<sub>0</sub>|<sub>1</sub>|<sub>2</sub>|<sub>3</sub>|<sub>4</sub>|<sub>5</sub>|<sub>6</sub>|<sub>7</sub>|<sub>8</sub>|<sub>9</sub>|

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

| 0  | 0   | 0   |  0  | 0   |  0  | 0   | 0   |  0  | 0   |
| und  | und   | und   |  und  | und   |  und  | und   | und   |  und  | und   |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:| 
|<sub>0</sub>|<sub>1</sub>|<sub>2</sub>|<sub>3</sub>|<sub>4</sub>|<sub>5</sub>|<sub>6</sub>|<sub>7</sub>|<sub>8</sub>|<sub>9</sub>|

