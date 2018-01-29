## 2D Array - General Overview + dynamic array allocation

### Single Dimensional

A regular array in C++ is declared like so:

```cpp
int A[10];
```

This allocates 10 4byte memory locations with the starting address stored at a location pointed to by `A`. Each memory location is undefined. 

|<sub>0</sub>|<sub>1</sub>|<sub>2</sub>|<sub>3</sub>|<sub>4</sub>|<sub>5</sub>|<sub>6</sub>|<sub>7</sub>|<sub>8</sub>|<sub>9</sub>|
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:| 
| und  | und   | und   |  und  | und   |  und  | und   | und   |  und  | und   |

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
|<sub>0</sub>|<sub>1</sub>|<sub>2</sub>|<sub>3</sub>|<sub>4</sub>|<sub>5</sub>|<sub>6</sub>|<sub>7</sub>|<sub>8</sub>|<sub>9</sub>|
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:| 
| 0  | 0   | 0   |  0  | 0   |  0  | 0   | 0   |  0  | 0   |


We still have the issue where this array was allocated using a static integer (10 in this case). What if we're not sure what size of an array we want to allocate? We can use dynamic array allocation...

```cpp
int *B;
//or
int* B;

int array_size = 0; // variable to hold array size

// get our size from somewhere (could read it in
// from a file, etc.)
cout<<"Enter size to allocate array: ";
cin>>array_size;

// This is the actual line of code that allocates
// the memory for the array
B = new int[array_size];

// Initialize the array
for(int j=0 ; j < array_size ; j++){
    B[j] = 0;
}
```

### 2 Dimensional

```cpp
int C[5][5];
```

This allocates `5*5` 4byte memory locations with the starting address stored at a location pointed to by `C`. Each memory location is undefined. 

|            |<sub>0</sub>|<sub>1</sub>|<sub>2</sub>|<sub>3</sub>|<sub>4</sub>|
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:| 
|<sub>0</sub>| und  | und   | und   |  und  | und   |
|<sub>1</sub>| und   | und   |  und  | und   | und   |
|<sub>2</sub>| und   | und   |  und  | und   | und   |
|<sub>3</sub>| und   | und   |  und  | und   | und   |
|<sub>4</sub>| und   | und   |  und  | und   | und   |

We initialize each array location like so:

```cpp
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        C[i][j] = 0;
    }
}
```
|            |<sub>0</sub>|<sub>1</sub>|<sub>2</sub>|<sub>3</sub>|<sub>4</sub>|
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:| 
|<sub>0</sub>| 0  | 0   | 0   |  0  | 0   |
|<sub>1</sub>| 0   | 0   |  0  | 0   | 0   |
|<sub>2</sub>| 0   | 0   |  0  | 0   | 0   |
|<sub>3</sub>| 0   | 0   |  0  | 0   | 0   |
|<sub>4</sub>| 0   | 0   |  0  | 0   | 0   |

We still have the same "static" declaration problem as before, but dynamically allocating memory for a 2D array is slightly different than for a 1D array. 

To allocate memory for a 2D array dynamically we do ___NOT___ do this:

```cpp
int size = 5;
int *D = new int[size][size]
// Will discuss why more in class
```

What we need to do is this:

```cpp
int size=0;
int rows=0;
int cols=0;
int **Arr2D;

// Just for example (most likely we get sizes from another 
// resource like a database or a file etc.)
cout<<"How many rows?";
cin>>rows;
cout<<"how many cols?";
cin>>cols;

Arr2D = new int*[rows];

for(int i=0;i<cols;i++){
    Arr2D[i] = new int[cols];
}
```


Resources:
- https://brianbondy.com/blog/91/arrays-are-not-the-same-as-pointers
- https://www.tutorialcup.com/cplusplus/dynamic-memory.htm
