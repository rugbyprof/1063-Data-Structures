## Program 3 - Arbitrary Precision Math
#### Due: October 29 <sup>th</sup>

#### What is arbitrary precision math? 

Also called bignum arithmetic, multiple-precision arithmetic, or sometimes infinite-precision arithmetic, indicates that calculations are performed on numbers whose digits of precision are limited only by the available memory of the host system. This contrasts with the faster fixed-precision arithmetic found in most arithmetic logic unit (ALU) hardware, which typically offers between 8 and 64 bits of precision.

<sup>source: https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic </sup>

Yaaaaawwwn....  Did you nod off? I did. Ok, just for a second.

This is actually a pretty cool idea. Each number is ultimately stored in a register, and registers are of a fixed size. Integers are only 4 bytes (32 bits), which limits the size of the integer to 2<sup>32</sup>-1 What does this mean? Read about this on [Stack Overflow](https://stackoverflow.com/questions/94591/what-is-the-maximum-value-for-an-int32). Yes, this post went Nerd real fast, but the fact that so many individuals obsess over some power of 2 implies a lot! When I started reading the post I was reminded that I'm not the smartest person in the room, but I love the fact that this whole thread went off the rails like it did!!

The bottom line is that there are times when doing arithmetic with big numbers can be somewhat limiting. Simply 2^<sup>32</sup> or even 2^<sup>64</sup> isn't big enough! Depending on the computer architecture your working with, you may have access to 8 byte number sizes using `long` or `double`, but depending on the precision you need, this still may not be enough!! (http://floating-point-gui.de/formats/fp/). 

Honestly, for us, 2<sup>32</sup> **almost always is big enough**. But we wouldn't be computer scientists if we settled for petty `primitive data types` like `int`, `float`, and `double`. Lets make our own!

### Overview

Lets limit (for now) our problem to integers. And if we want to add: 

**`42304820394820934820394802394823094802394809 to 2318283123123893786234671923682346734`**

what data type do we use?? Int? Double? Ha! 2<sup>31</sup> = 2147483647 not nearly close enough! 2<sup>63</sup> = 9223372036854775808, still not close enough. I guess we need to solve this ourselves (note: `sign bit`, that's why `31` and not `32` and `63` and not `64`). In the example below, you can see that the far left bit (8<sup>th</sup> bit) is needed to make a number positive (0) or negative (1).

#### Sign Bit

<img src="https://cl.ly/pg9C/signbit.png" width="300">


#### Adding Numbers

Looking at the image below, we see 3 doubly linked lists with the bottom list being the result. There are different ways to approach adding linked lists together but we are going to store our numbers with the "most significant" digits toward the head and "least significant" toward the tail of our list. Since we have a doubley linked list, we can load the digits from head to tail as we read them from an input file, and them process them from tail to head as we add them together. 


|     |
|-----:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.1.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.2.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.3.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.4.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.5.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/arb_math.6.png"> |

