import random

# read in animals from file
data = open("animals.txt", "r") 

# turn file into a python list
animals = data.read().split("\n")

# get number of animals read in
num_animals = len(animals)

# all animals pushed onto the queue need popped off
# here is the start count
num_pops = num_animals

# sort the animals based on word length
animals.sort(key=len, reverse=True)

# swap short animals with longer ones
for i in range(int(num_animals/3)):
    r1 = random.randint(0,int(num_animals/2)-1)
    r2 = random.randint(int(num_animals/2),num_animals-1)
    temp = animals[r1]
    animals[r1] = animals[r2]
    animals[r2] = temp

# create output file 
outfile = open("input_data.txt","w")

i = 1  # loop counter 
for animal in animals:
    outfile.write("push "+animal+"\n")
    if i % 3 == 0:
        rp = random.randint(0,5)
        for j in range(rp):
            outfile.write("pop\n")
            num_pops = num_pops - 1
    i = i + 1

for j in range(num_pops):
    outfile.write("pop\n")


