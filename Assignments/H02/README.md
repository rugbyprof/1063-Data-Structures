## Homework 2 - Resizable Array Stack
#### Due : TBD

### Overview

Using the code in [L05](../Lectures/L05/README.md) add the necessary code to `resize` the array of the stack gets 80% full. You should resize the array to be 1.5 times larger than it previously was. Also, you should reduce the size of your array if the stack gets down to 20% full (and this should only happen if it was previously enlarged).

### Requirements

- Add a method called `checkResize` that will look at the current ratio that the stack contains and decide to enlarge or shrink.
- Add a method called `Enlarge` that will grow the array. 
- Add a method called `Reduce` that will shrink the array.

Remember a resize of the array requires allocating a brand new array, and copying the values over to the new container.


MORE TO COME