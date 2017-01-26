#!/usr/bin/env python
 
from __future__ import with_statement
from PIL import Image
import sys


filename = sys.argv[1][:-4]

im = Image.open(sys.argv[1]) #relative path to file
 
width, height = im.size
 
#load the pixel info
pix = list(im.getdata())

print(width,height)

f = open(filename + '.csv', 'w+')
f.write(str(width)+" "+str(height)+"\n")
for start in range(0,len(pix),width):
    line = pix[start:start+width]
    c = 0
    for p in line:
        print(p)
        if len(p) == 3:
            r,g,b = p
        else:
            r,g,b,a = p
        f.write(str(r)+' '+str(g)+' '+str(b))
        if c < width:
            f.write(' ')
        c += 1
    f.write("\n")