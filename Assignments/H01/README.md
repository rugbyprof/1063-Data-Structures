## Homework 1 - File Processing and Arrays of Structs
#### Due: Tuesday Sep 3<sup>rd</sup> at the beginning of class.

#### Given

- The code from [L02](./d1_structs.cpp) as a starting point.
- The old input file:

```
Joseph Wilson 23 34
Suzy Smart 100 100 
Bill Bob 90 66
Jon Smith 89 67
```

This only allowed us to read in the first, last, and the same amount of grades for each student. This is somewhat limiting and not a robust solution. The other data file is formatted like:

```
Joseph Wilson
2 23 34
Suzy Smart
4 100 100 50 89
Bill Bob
4 89 89 90 66
Jon Smith
1 89
```

Where:

Even lines:
>
>
>fname lname
>
Space delimited easily read using `cin>>var1>>var2;`

Odd lines: 
>
>
>N g1 g2 ... gn
>
Where `N` = the number of tests to read.
And `g1 ... gn` are space delimited grades.


### Hint

A hint not using an array of structs:

Given temp.txt:

```txt
asdf oiuf 
3 765 990 465
ljio wesd 
7 554 284 372 234 711 234 889
nfhg wasd 
1 234
```

```cpp
void printTemp(string one,string two,int count, int nums){
  cout<<one<<" "<<two<<" "<<count<<endl;
  for(int i=0;i<count;i++){
     cout<<nums[i]<<" ";
  }
  cout<<endl;
}

string one ,two;
int count;
int nums[10];
ifstream temp;
temp.open("temp.txt");

temp>>one>>two>>count;
for(int j=0;j<count;j++){
   temp>>nums[j];
}

printTemp(one,two,count,nums);  // print first chunk of data

```





### Requirements

- Write a c++ program that executes the following:

1. Read and correctly process the data file called `input_data.txt`.
2. Incorporate at least two functions:
    - `loadClassList` that opens the file and reads the data.
    - `printClassList` which will print out the results in a nicely formatted manner.
3. Create an output file with your printed students and grades.
3. Fully comment your code.

___Example Output:___

```
Students
=================================
1. Joseph Wilson:    23  24
2. Suzy Smart   :   100 100 50 89
3. Bill Bob     :    89  89 90 66
4. Jon Smith    :    89
```

#### Deliverables

Your going to think that some of what I ask you to do below is silly or anal, but if I don't give instructions
the results are chaotic. I have enough chaos in my life, I don't need yours.

- Create an `assignments` folder in your github repo. (all lower case! and one word!)
- Create a folder called `homework_1`
- In this folder create a file called `main.cpp` with c++ code that fulfills the requirements.
- Your `homework_1` folder should contain:
    - your intput file, `input_data.txt`
    - your output file, which should be named `student_output.dat`
- ANY file you use with your assignment should ALWAYS end up in your assignment folder. 
- Print a copy of your code, input file, and output file and bring to class ___Tuesday Sep 3<sup>rd</sup>___ at the beginning of class.
  - Order: Code on top, then input file, then output file. 
  - Stapled: Upper left corner (as close to the edge as possible)
  - Your name should be on each page ( NO HAND WRITING !!  ).
- FAILURE TO FOLLOW INSTRUCTIONS: 1 letter grade. Yes, seriously.
