# Program 2 Help Session
## Fixing Problems and Debugging
### Study Session 10/7/2019

This was a mostly discussion-oriented study session. There is no code to post, as we primarily worked on the students' code. (It would be cheating to upload that!)

### Notes

Make sure to update your size after enlarging or reducing! I saw a lot of code like the pseudo-code below:
```
    newSize := size * .8
    NewArray = int[newSize]
    for i = 0 to size
        // copy element from Array to NewArray
    Array = NewArray
    return
```
But its **critical** to include a line *before the end of the function* that goes something like
`size = newSize`
Otherwise the class will always act as though it is the original size, even when its bigger/smaller. Also make sure you only add the line after you are finished using the original size. (you use it in the loop, for instance)