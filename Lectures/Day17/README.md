## Maze

Both mazes below are 5x5, but as you can see it takes more than 1 character to represent a cell. 

Is this necessary? No. 

MTC.....

**Decent looking text representation:**
```
5 5
+---+---+---+---+---+
                |   |
+---+---+---+   +   +
|       |       |   |
+---+   +   +---+   +
|       |   |       |
+   +   +   +---+   +
|   |   |           |
+   +---+---+   +   +
|               |  
+---+---+---+---+---+
```

**Ugly array based version:**
```
5 5
1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 1 0 1
1 1 1 1 1 1 0 1 0 1
1 0 0 0 1 0 0 1 0 1
1 1 1 0 1 0 1 1 0 1
1 0 0 0 1 0 1 0 0 1
1 0 1 0 1 0 1 1 0 1
1 0 1 1 1 1 0 1 0 1
1 0 0 0 0 0 0 1 0 0
1 1 1 1 1 1 1 1 1 1
```
