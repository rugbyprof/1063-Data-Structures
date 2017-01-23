# create an empty image with PIL and put pixels inside
from PIL import Image
import sys

filename = sys.argv[1][:-4]

width = 0
height = 0

x=0
y=0

with open(sys.argv[1]) as f:
    for line in f:
        line = line.split()
        print(len(line))
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
img.save(filename + "_from_csv" + ".bmp")
# optionally look at the image you have created
img.show()
