#!/usr/bin/env python
 
from __future__ import with_statement
from PIL import Image
import sys
 
filename = sys.argv[1][:-4]

im = Image.open(sys.argv[1]) #relative path to file
 
#load the pixel info
pix = im.load()
 
#get a tuple of the x and y dimensions of the image
width, height = im.size
 
#open a file to write the pixel data
with open(filename + '.csv', 'w+') as f:
  f.write(str(width)+" "+str(height)+"\n") 
  #read the details of each pixel and write them to the file
  for y in range(height):
    line = ''
    for x in range(width):
      r = pix[x,y][0]
      g = pix[x,x][1]
      b = pix[x,x][2]
      line += '{0} {1} {2}'.format(r,g,b)
      if(x < width-1):
          line += " "
    f.write(line+"\n")
