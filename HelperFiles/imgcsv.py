#!/usr/bin/env python

from PIL import Image
import sys

image_types = ['bmp','png','jpg','gif']

def print_usage():
    print("Error: Incorrect arguments")
    print("Usage: python imgcsv.py inputFileName outputFileName")

def imgtocsv(ifile,iext,ofile,oext):
    im = Image.open(ifile+'.'+iext) 
 
    width, height = im.size
 
    #load the pixel info
    pix = list(im.getdata())

    f = open(ofile + '.' + oext, 'w+')
    f.write(str(width)+" "+str(height)+"\n")
    for start in range(0,len(pix),width):
        line = pix[start:start+width]
        c = 0
        for p in line:
            if len(p) == 3:
                r,g,b = p
            else:
                r,g,b,a = p
            f.write(str(r)+' '+str(g)+' '+str(b))
            if c < width:
                f.write(' ')
            c += 1
        f.write("\n")
        
def csvtoimg(ifile,iext,ofile,oext):
    width = 0
    height = 0

    x=0
    y=0

    with open(ifile+'.'+iext) as f:
        for line in f:
            line = line.split()
            if width == 0 and height == 0:
                width = int(line[0])
                height = int(line[1])

                img = Image.new("RGB", [width,height], (255,255,255))
            else:

                for i in range(0,len(line),3):
                    r = int(line[i])
                    g = int(line[i+1])
                    b = int(line[i+2])
            
                    img.putpixel((x, y), (r,g,b))
                    x += 1
                y += 1
                x = 0
    # save the image
    img.save(ofile + "." + oext)
    # optionally look at the image you have created
    #img.show()

def main():
    if len(sys.argv) < 3:
        print_usage()
        sys.exit(0)
    ifile,iext = sys.argv[1].split('.')
    ofile,oext = sys.argv[2].split('.')
    
    if iext in image_types:
        imgtocsv(ifile,iext,ofile,oext)
    else:
        csvtoimg(ifile,iext,ofile,oext)
    
    
if __name__=='__main__':
    main()