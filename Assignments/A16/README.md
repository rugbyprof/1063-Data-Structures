## Program Three - Survival of the Lucky 
Due: TBD


#### Old Description

The problem is based on [Flavius Josephus](http://en.wikipedia.org/wiki/Flavius_Josephus), a Jewish historian living in the 1st century. According to Josephus' account of the siege of [Yodfat](http://en.wikipedia.org/wiki/Yodfat), he and his 40 comrade soldiers were trapped in a cave, surrounded by Romans. They chose suicide over capture and decided that they would form a circle and start killing themselves using a step of three. Josephus states that by luck, or maybe by the hand of God, he and another man remained the last and gave up to the Romans. [Wikipedia](http://en.wikipedia.org/wiki/Josephus_problem) 

So, Josephus was in the right place, at the right time (quite literally). More simply put, the problem is to find the correct location in the circle so that you will be a survivor at the end. We will identify the correct spot to be (or the person who will survive) by following the example below:


<table>
<tr>
<td><img src="http://f.cl.ly/items/273V3A2Q050E1O3E2r3Q/josephus1.png"></td>
<td><img src="http://f.cl.ly/items/0B3m163I2t3o0L0b1G21/josephus2.png"></td>
<td><img src="http://f.cl.ly/items/0J471G3w261J2I47402G/josephus3.png"></td>
</tr>
<tr>
<td><img src="http://f.cl.ly/items/1g3N060f302308321u2l/josephus4.png"></td>
<td><img src="http://f.cl.ly/items/343y3m2h19041e2g161O/josephus5.png"></td>
<td><img src="http://f.cl.ly/items/1R161L3S1D3n250v010C/josephus6.png"></td>
</tr>
</table>

#### Old Algorithm

The original algorithm jumped __X__ number of spots going in the same direction each time. There are a couple of problems with this implementation. 1) This would only require a singly linked list to solve. 2) You could calculate a safe spot to stand knowing __X__ before hand. 


#### New Algorithm

This new implementation requires an input file of names (or animals). 

01. Load a doubly linked list with all the animals from our input file.
01. Reset the file.
01. Read in a value from the input file.
01. Get the length of the value.
01. Multiply the length by some multiplier __m__ 
01. Move __m__ spaces along the doubly linked list going to the right if __m__ is even, and left otherwise.
01. The position you land on is the animal you will eliminate (dispatch for you special operators) from the list.
01. While the size of the list is greater then 1, go to step 3.

---

#### Overview of Doubly Linked List

***Old Node Structure:***

<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/022z2J3X1K0u2z3E0p3k/linked_node.png">

~~~cpp
struct Node{
    string Name;
    Node * Next;
};
~~~

***New Structure:***

Just add an extra pointer to the node structure:

<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/3l2w2O3l370n231p323a/doubly_linked_node.png">

~~~cpp
struct Node{
    string Name;
    Node *Next;
    Node *Prev;
}
~~~

- `Node *Next` is what we would normally use in a singly linked list, pointing to the "next" node in line.
- `Node *Prev` is added, so we can point to the prev value.

Below, is a doubly linked list that connects the last and the first nodes. This creates a "circle" like effect, allowing us to traverse all the around the list without ever reaching a `NULL` pointer (which would force us to stop). Great! But .... wait .... how do we stop?

<center>
<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/3j2g0S3m1H2h1h01011P/doubly_linked_ordered_josephus_no_pointers.png" style="width:400px">
</center>

Well, we still need a `Head` pointer. Now all you need to do is test for the `head` of the list, and when your pointer is equal to `Head`, STOP!

<center>
<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/2c083r2B0u2c3R0z2E31/doubly_linked_ordered_head_only_josephus.png" style="width:400px">
</center>

~~~cpp
Node* Temp = Head;

while(Temp != Head){
    //do something
    Temp = Temp->Next;
}
~~~
Wait, this traversal will never start! Because we're currently pointing at head. So, we need to change the strategy a little bit:
<br><br>

~~~cpp
Node* Temp = Head;

while(Temp->Next != Head){
    //do something
    Temp = Temp->Next;
}
~~~

This will work, and stop one shy of the `Head`, on a traversal. 

<center>
<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/2a3Y3n1A3I3Z2i1l291Y/doubly_linked_ordered_with_pointers_josephus.png" style="width:450px">
</center>


<br><br>
Now we can traverse the list in both directions. No matter where we are currently in the list. In fact, remember when traversals always consisted of:

~~~cpp
Node* Temp = Head;

while(Temp){
    //do something
    Temp = Temp->Next;
}
~~~

Now a traversal could look like this:

~~~cpp
//Current is already set

While(Current != Head){
    //do something
    Current = Current->Next;
}
~~~

<center>
<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/3w3M0J2T1W0n0X0c3K1D/doubly_linked_traverse_next.png" style="width:450px">
</center>

Or lets traverse the other direction:

~~~cpp
//Current is already set

While(Current != Head){
    //do something
    Current = Current->Prev;
}
~~~

<center>
<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/2Q2M1g300e3a032t1p09/doubly_linked_traverse_prev.png" style="width:450px">
</center>

#### Output File 

Example output file where the animals printed are (besides first and last) printed every 11 animals removed. Or when : `count % 11 == 0`.

```
/**
* ProgramName: Program-x
* Author: Your Name 
* Description: 
*     This program reads in ....
* Course: 1063 Data Structures
* Semester: Spring 2018
* Date: DD MM YYYY
*/

First: yak
- cow
- dog
- turtle
- ...
WINNER: aardvark !!
```

#### Deliverables

- Create a folder called `program_3` and place all files in this folder.
- If it is not on github, it doesn't exist.
- Create an output file called `eliminated.txt`
- Your output file will look as described above.
- So, count the animals as they are removed and print to file when: `count % 11 == 0`.
- The last animal printed in this file will be the "winner".
- Prompt the user for the "multiplier" when the program starts. This value can be anywhere from 1 to 13 (inclusive), so check to make sure it is within range.
- Print out your **commented** source code and turn it in with your output file on top, then your main, then the rest.


