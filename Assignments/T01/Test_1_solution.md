1) 

```cpp

double sum(double A[], int size){
   double total = 0.0;
   for(int i=0;i<size;i++){
      total += A[i];
      A[i] = 0;
   }
   return total;
}

```

2)

```cpp

bool findit(string **A, string key, int w, int h){

   for(int i = 0 ; i < h; i++){
      for(int j = 0 ; j < w ; j++){
         if(A[i][j] == key){
            return true;
         }
      }
   }
   return false
}
```


3)

```cpp
void print_triangle(int N){
  for(int i=1;i<=N;i++){
     for(int j=0;j<i;j++){
        cout<<'*';
     }
     cout<<endl;
  }
}
```

4)

```cpp

Stats doStats(int *A, int size){

  Stats S;
  S.min = A[0];
  S.max = A[0];
  S.avg = 0.0;
  
  
  for(int i=0;i<size;i++){
    if(A[i] < S.min){
       S.min = A[i];
    }
    if(A[i] > S.max){
      S.max = A[i];
    }
    
    S.avg += A[i];
    
  }
  
  S.avg /= size;
  
  return S;
  
}
```

5)

```
8 8 8 8 8 
8 8 8 8 8 
8 8 8 8 8 
8 8 8 8 8 
8 8 8 8 8 
```
