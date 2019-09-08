## Program 1 -  List Class
#### Due: Tuesday September 17<sup>th</sup> by classtime

### Overview

This program you will write a list class that stores employee information, one per node. You will write list methods to perform some basic tasks. You can use the starter code from [Lecture 04](../../Lectures/L04) to help you get going.

### Requirements

At a minimum, your class will contain these methods:

- push()        : adds an item to the front of the list
- pop()         : removes an item from the front of the list
- find()        : returns a boolean true/false if an item is in the list
- delete()      : removes an item from anywhere in the list
- add additional methods to meet some questions below

The data you will be loading into your list has the following fields:

| Field      | Data type |
| :--------- | :-------- |
| emp_id     | string    |
| first_name | string    |
| last_name  | string    |
| gender     | string    |
| email      | string    |
| hourly_pay | double    |

The `find` and `delete` methods should be able to search using any of the fields in the employee record. When implementing your code, just start with one field. I'll discuss ways of changing fields in class.

Create an output file with the results of a search for: 

### String Matching

If you misspell something on a google search, does it fail? I think not. 

- I search for: `visaul` 
- Google says: Showing results for `visual`
- In fact Google used to say: Did you mean `visual`? Which was way more condescending and funny. 

There is more going on here than we are going to implement, but it proves a point: If Google ignored everything you or me misspelled, our search results would suck. 

In your program, you are going to loosen the exactness on string matching and implement a partial match search. What does that mean? Here is an example:

- Keyword: Mississippi
- Search Term: ippi => found (Mississ`ippi`)
- Search Term: Miss => found (`Miss`issippi)
- Search Term: Misss => NOT found 
- Search Term: siis => NOT found 

This is called `substring` matching, and is very common in computer science. Even though we will not be able to match swapped letters like my original example (visaul vs visual), it still is very helpful. Maybe in a later program we can try to find misspelled words, its a pretty neat algorithm.

Here is a snippet of code to find strings that have partial matches:

```cpp

string s1 = "american burgers";
string s2 = "burger";

if (s1.find(s2) != std::string::npos) {
    std::cout << "Found!" << '\n';
}
```
"Found!" will be printed if s2 is a substring of s1, and both s1 and s2 are of type std::string (which they should be);

What about a function?

```cpp

bool substringMatch(string macro, string micro){
    return (macro.find(micro) != std::string::npos)
}

cout<<substringMatch("boomer sooner","soon")<<endl;
cout<<substringMatch("boomer sooner","boom")<<endl;
cout<<substringMatch("boomer sooner","bum")<<endl;
```

Will write out:
```
1
1
0
```


### Deliverables

- Make sure you have an `assignments` folder on github.
- Create another folder inside assignments called `P01`
- Write your code in a file called `list.cpp`
- Make sure your input file makes it to the repo.
- 



