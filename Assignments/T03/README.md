## Test 3 - Assessment

## Recursion

- Be able to recall the 3 components of recursion.
- Be able to trace a recursive function.
- Be able to write a recursive function. 

#### Example

```cpp

// Label the 3 components
void PrintReverse(int num){
    if(num == 0){
        return;
    }
    cout<<num%10;
    PrintReverse(num/10);
}
```


## Class Components and Concepts

- What are the components that make up a class?
- What is the difference between a class and a struct?
- What is implementation hiding?
- What is the difference between public and private?
- What is the difference between a method and a function?
- What is a constructor and destructor and what are they used for?

### Apply Your Class Skills

- Given a small requirements list, be able to write a class with its appropriate methods and data members.
- Example: I need a class to represent a **`point`**, where `point` is a 2D location on a plane. I need to be able to move my point from one location to another (not in an animated sense), and I need to be able to calculate the distance between two points. I would like to also print out a points current values like : `(x,y)` (where x,y would be replaced with current values).


- Questions to ask yourself: 
  - What variables do I need to represent a point?
  - What methods will I need to fulfill the requirements?

- Some Answers:
  - Data Members:
    - The variables to represent your point are the data members in your class, in this case a simple `int x` and `int y` will work. They could also be `float` but thats not a big deal right now. 
    - Do I need any other variables? Not really.
  - Methods (I will implement below, we are simply getting organized):
    - I need to move a point so I need a move method that gets a new location: 
      - `void Move(int newx, int newy)`
    - I need to calculate distance between two points, so my `distance` method should probably receive another point;
      - `float Distance(Point other)`
    - I need to print my point out:
      - `void Print()`

- Ok, we should be ready to "write" our class. But there might be some issues with our distance function, especially if we store our `x` and `y` values as `private` data members of our class! Next point fixes this issue.
- I have discussed this in class, but I dont really do it all the time because its time consuming, but if you have Dr. Stringfellow for a class you had better write `setters` and `getters` for all of the data members in your class (with some exceptions). So, to solve the `private` data member problem, we can use a getter method to access them (there are other better OOP ways, but not for now).
- Also, I don't write destructors in class either, but on a test, you should include an empty destructor to show you know there should be one.

### Our Class

```cpp

#include <iostream>
#include <math.h>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    // You should always have a "default" constructor that simply
    // initializes your data members.
    Point(){
        x=0;
        y=0;
    }

    // You should always have at least one overloaded constructor
    // to allow user to initialize data members.
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }

    // Setters
    void SetX(int _x){
        x = _x;
    }

    void SetY(int _y){
        y = _y;
    }

    // Getters
    int GetX(){
        return x;
    }

    int GetY(){
        return y;
    }

    void Move(int _x,int _y){
        x = _x;
        y = _y;
    }

    void Print(){
        cout<<"("<<x<<","<<y<<")";
    }

    float Distance(Point p){
        // get the x and y from our incoming point
        int x2 = p.GetX();
        int y2 = p.GetY();

        // Formula wants the square root of the differences squared
        // so we will get and store difference first
        float dx = x - x2;
        float dy = y - y2;

        // Now we sqaure the differences and return the square root
        return sqrt(dx*dx + dy*dy);
    }

    // For fun, could write the above function in a single line? 
    float Distance2(Point p){
        return .....
    }

    ~Point(){} // destructor

}



