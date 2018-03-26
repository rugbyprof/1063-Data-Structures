## Homework 1 - ToUpper function
#### Due: Monday March 26<sup>th</sup> by 10:00 am

Take the function below and turn it into a `toupper` function.
```cpp
string tolower(string w){
  for(int i=0;i<w.length();i++){
    
    if((int)w[i]>=65 && (int)w[i]<=90){
      w[i] = w[i]+32;
    }
  }
  return w;
}
```

### Deliverables

- bring your printed out function to class Monday.
- Your name should be on your paper in some DIGITAL format
- NO handwriting.
