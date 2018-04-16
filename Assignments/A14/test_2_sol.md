## Test 2 - Linked Lists  

**Name:** SOLUTION

For each of your linked lists, assume the `struct` looks like the following:
```cpp  
struct Node{  
    int data;  
    Node* next;  
};
```  
----  

**QUESTION 1** 

```cpp  
/**  
* Function: Find()  
* Returns: bool  
* Description: 
* Given a list, and a key to search for, return true if 
* the key is in the list, false otherwise.  
*/  

// Your Code Below:  



bool Find(Node* Head, int key){
	Node* Temp = Head;	// not necessary Head not passed by reference	
	
	while(Temp){
		if(Temp->data == key){
		    return true;
		}
		Temp = Temp->next;
	} 
	return false;
}



```  

**QUESTION 2** 
```cpp  
/**  
* Function: DeleteList()  
* Returns: void  
* Description: 
* Given a list delete all the nodes on the list.  
*/  

// Your Code Below:  


void DeleteList(Node *&Head){
	//Assuming list has more than one node...
	Node* Next = Head->next;
	
	while(Next){
		delete Head;
		Head = Next;
		Next = Next->next;
	}
	delete Head;
}


``` 

**QUESTION 3** 

```cpp  
/**  
* Function: Pop()  
* Returns: int  
* Description: 
* Given a list delete, the first node, and return its value. 
*/  

// Your Code Below:  

int Pop(Node *&Head){
	//Assuming a none empty list...
    Node* Prev = Head;
    int Data = Head->data;
    Head = Head->next;
    delete Prev;
    return data;
}


``` 

**Given:** 

```
// Declare a list
List theList;
theList.orderedInsert(9);
theList.orderedInsert(23);
theList.orderedInsert(11);
theList.orderedInsert(6);
theList.orderedInsert(4);
// Which results in an ordered ascending list:
```
![](https://d3vv6lp55qjaqc.cloudfront.net/items/3p0f0K0l3M040b150L2H/list1_test2.png)

**QUESTION 4**
What will the following code do the the list? 

```cpp
theList->next->next->data = theList->next->next->next->data/3;
//      (9)               =                   (11) / 3 
// 
theList->data = theList->data + 2;
// (04)      =        (04) + 2

```
![](https://d3vv6lp55qjaqc.cloudfront.net/items/1t2V2P2i3l1f2H2D1b0Z/list2_test2.png)

**QUESTION 5**

![](https://d3vv6lp55qjaqc.cloudfront.net/items/2W3e391k1f3p2l0t251v/list3_test2.png)

Use code similar to the question 4's, re-arrange the nodes into proper order (adjust the pointers). Do not try to "loop" or "traverse" the list when fixing.

```
Node* ten = theList->next->next->next;
Node* fourteen = theList->next->next;
Node* five = theList->next;

fourteen->next = ten->next;
ten->next = fourteen;
five->next = ten;

```

**QUESTION 6**

```cpp  
/**  
* Function: delete()  
* Returns: void  
* Description: 
* Given a list and a key value, delete the node that is equal to the key.
*/  

// Your Code Below:  


bool delete(Node *&List,int key){
	//assuming none empty list...
	Node* Prev = List;
	Node* Temp = List;
	
	while(Temp){
		if(Temp->data == key){
			Prev->next = Temp->next;
			delete Temp;
			return true;
		}
		Prev = Temp;
	    Temp = Temp->next;
	}
	return false;
}


``` 


**QUESTION 7**

```cpp  
/**  
* Function: swapFirstLast()  
* Returns: void  
* Description: 
* Given a list, swap the first and last values in the list.
*/  

// Your Code Below:  

void swapFirstLast(Node *&Head){
    //Assumes a list with at least two nodes...
	int temp = 0;
	Node *Last = Head;
	
	while(Last->next){
		Last = Last->next;
	}
	
	temp = Head->data;
	Head->data = Last->data;
	Last->data = temp;
	
}
``` 
