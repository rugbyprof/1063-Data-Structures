# Not totally complete ...

## Program 1 - Image Manipulation
Due February 3<sup>rd</sup> at the beginning of class.

### Overview

This course is about data structures, but were going to start with a concept that you should have ended 
with last semester, 2D arrays. There is a starter file in this folder that will read in an image that has
been stored in a txt format. It doesn't manipulate the data at all, it simply turns around and writes the
image right back to a new file. 

Your job for this assignment will be to write two functions. One that will "flip" your image either
horizontally or vertically depending on some user input. And another function to turn your image into
gray scale. 

This won't be real fun unless we can work with real images, so I wrote a small web page that lets you convert 
images to text and back again. It lives here: http://cs.mwsu.edu/~griffin/1063_DataStructures/imgcsv/. And since 
it allows uploads, it has a username/password associated with it: ***mustang/mustang***. 

### Image Arrays

We can think of an image as a two dimensional array of RGB values. We've discussed this in class. 

| 2D Image |
|:-------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/1X0Z2W0t432k0x3w2U1u/2d_array.png?X-CloudApp-Visitor-Id=1094421) |

To flip an image across either axis is a pretty simple process. 

| Flip Vertical |
|:-------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/1K280C2Y3S2H2S3U2B07/flip%20_vertical.png?X-CloudApp-Visitor-Id=1094421) |
| To flip an image vertically, you simply copy each row as if you were folding the image in half from top to bottom or bottom to top. So `Row[i]` gets swapped with `Row[Height-1 - i]` where `0 <= i <= Height/2` |

| Flip Horizontal |
|:-------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/44052x1L2w2S010f2u1m/flip_horizontal.png?X-CloudApp-Visitor-Id=1094421) |
| To flip an image horizontally, you simply copy each column as if you were folding the image in half from left to right or vice to versa. So `Col[i]` gets swapped with `Col[Width-1 - i]` where `0 <= i <= Width/2` | |

### Requirements

- Download the starter code.

- Complete the following 3 functions:

```cpp

void flipVert(rgb** image,int width,int height){
    // your code
}

void flipHorz(rgb** image,int width,int height){
    // your code
}

void grayScale(rgb** image,int width,int height){
    // your code
}

```

Make sure you place your functions above main, and also include comment blocks for each function and your program as a whole:

Main Program Comment Block:
```cpp
/**
* @ProgramName: Program-1
* @Author: Your Name 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: DD MM YYYY
*/
```

Function Comment Block:
```cpp
/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image,int width,int height){
    // your code
}
```

You don't have to create a `class` in your solution. That's going to be the next program! If you want to get a head start, you may want to read / write your image file via functions:

```cpp

void readImage(rgb** image,int &width,int &height,ofstream &ofile){
    // Hmmm, what's up with the width and height references
}
void saveImage(rgb** image,int width,int height,ofstream &ofile){
    // your code
}

```

### Testing

When writing your programs, especially at this level, you should start small and incrementally add logic to your solution. Which means that you shouldn't jump right in and start to try flipping your image. One problem is that your working with starter code written by someone else, so you might want to familiarize yourself with the code. One way of doing this is to start with a small simple image, lets say this one:


