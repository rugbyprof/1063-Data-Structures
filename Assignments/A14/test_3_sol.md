

## Test 2 - Recursion

**Name:** __________________________________________

**QUESTION 1** 
```cpp
// Given the function below:
// Use comments to label the necessary parts of a recursive function.
int arr_sum( int arr[], int size )
{ 
    
    if (size == 0) {
    // 1. Base Case
        return 0;
        
    } else{
	           // 2. recursive call
	           //  |
	           //  v
	    return arr_sum(arr,size-1) + arr[size-1];
	                   //   ^
	                   //   |
		               // 3. reduce data set / approach base case
    }
    
}

```

**QUESTION 2** 

```cpp  
/**  
* Given the following recursive function as an example, can you turn this into an 
* iterative solution (Use loops instead)?
*/  

int exponentiate_r(int x, int n){
    if (n==0) return 1;
    else return x * exponentiate_r(x, n-1);
} 
// Your function below:
```

**Answer:**

```cpp
int exponentiate(int x,int n){
	// x^0 == 1
	if(n == 0){
	   return 1;
	}
	// init product to x
    int product = x;
    
    // loop n-1 times multiplying x by itself
	for(int i=1;i<n;i++){
		product *= x;
	}
    return product;
}

```  

**QUESTION 3** 

```cpp  
/**  
* What will the following C++ program output when it is executed by the following 
* command: traceRace(16); 
*/  

int traceRace (int n){
    if(n<2){
       return 0;
    }else{
      cout<<n<<endl;
      return (1 + traceRace(n/2));
    }
 }
 ```

**Answer:**
16
8
4
2

![](https://d3vv6lp55qjaqc.cloudfront.net/items/2q3j3g0P2E3E1h0u3B2S/recursion-trace-1.png)

```cpp
// Bonus: What does it return at the very end?
```
**4**


**QUESTION 4** 
```cpp  
/**  
* The following recursive function replaces "from" letters with "to" letters.
* Example:
*     char s[] = "Linkin Park";
*     replace(s, 'P', 'B') 
*     Would print out: Linkin Bark
*/ 
void replace(char *s, char from, char to)
{
	if (*s != '\0') {
		if (*s == from) 
		   *s = to;
		   cout<<*s;
		   replace(s+1, from, to);
	}
}
```
**Answer**
```cpp
/**  
* Re-write the above function to still replace the characters, but 
* also write the string in reverse!
*/

void replace(char *s, char from, char to)
{
	if (*s != '\0') {
		if (*s == from) 
		   *s = to;
		   // move print from here
		   replace(s+1, from, to);
		   // to here!
		   cout<<*s;
	}
}

```

**QUESTION 5** 
```cpp  
/**  
*  Write a recursive function called Sum that would "sum" all the digits 
*  in an integer variable.
*  Example:
*     Sum(34376);
*     Would output: 3+4+3+7+6 or 23
*/  
//Function:
```

**Answer:**
```cpp
int Sum(int number){
   if(number == 0){
      return 0;
   }
   return number % 10 + Sum(number / 10);
}
```
Trace:
![](https://d3vv6lp55qjaqc.cloudfront.net/items/3p251s3m1J273Z3o3j1W/recursion-trace-3.png)

**QUESTION 6** 
```cpp
/**  
*  Write a recursive function: int count_digit(int n, int digit); 
*  To count the number of digits in a number n (n > 0) that are equal 
*  to a specified digit. For example, if the digit we're searching for 
*  were 2 and the number we're searching were 220, the answer would be 2.
*/
```
**Answer:**
```cpp
int count_digit(int n, int digit){
	if(n ==0){
		return 0;
	}
    if(n % 10 == digit){
        return 1 + count_digit(n / 10, digit);
    }else{
        return 0 + count_digit(n / 10, digit);
    }
}
```
Trace:

![](https://d3vv6lp55qjaqc.cloudfront.net/items/1S2y3X3Z3o381B0Q0T1O/recursion-trace-4.png)
  
**QUESTION 7** 
```cpp
/**  
*  Write a recursive function called "traverse" that will traverse a singly 
*  linked list and print out each of its values.
*  The following list would output: 
*        2 => 5 => 14 => 10 => 20 =>
*/
```
<img src="https://d3vv6lp55qjaqc.cloudfront.net/items/1j440h2X2l1I0f0C1u3c/linked_list_single.png" width=600>

```cpp
//Answer:

void traverse(Node* head){
    if(!head){
        return;
    }else{
        cout<<head->data;
        traverse(head->next);
    }
}
```





