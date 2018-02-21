## Arbitrary Precision Arithmetic - Sounds freakin hard (but is it?)

#### What is arbitrary precision math? 

Also called bignum arithmetic, multiple-precision arithmetic, or sometimes infinite-precision arithmetic, indicates that calculations are performed on numbers whose digits of precision are limited only by the available memory of the host system. This contrasts with the faster fixed-precision arithmetic found in most arithmetic logic unit (ALU) hardware, which typically offers between 8 and 64 bits of precision.

<sup>source: https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic </sup>

Yaaaaawwwn....  Did you nod off? I did. Ok, just for a second. 

This is actually a pretty cool idea. In class we have mentioned that integers are only 4 bytes. Hmmmmm. What does this mean? Read about this on [Stack Overflow](https://stackoverflow.com/questions/94591/what-is-the-maximum-value-for-an-int32). Yes, this post went Nerd real fast, but the fact that so many individuals obsess over some power of 2 implies so much! When I started reading the post I was reminded that I'm not the smartest person in the room, but I love the fact that this whole thread went off the rails like it did!! Mnemonics to memorize 2<sup>32</sup> ... what!?!?! 

I digress....

The bottom line is that there are times when doing arithmetic with big numbers can be somewhat limiting. Simply 2^<sup>32</sup> isn't big enough! Depending on the computer architecture your working with, you may have access to 8 byte number sizes using `long` or `double`, but depending on the precision you need, this still may not be enough!! (http://floating-point-gui.de/formats/fp/). 

Honestly, for us, <sup>32</sup> **almost always is enough**. But we wouldn't be computer scientists if we settled for ... arghh: `primitive data types` like `int`, `float`, and `double`. I think we should make our own! And now the assignment.









