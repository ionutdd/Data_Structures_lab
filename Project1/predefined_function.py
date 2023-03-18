#predefined sort function in Python

import time
start_time = time.time()
f = open("date.in","r")
g = open("date.out","w")
linie = f.read().split()
arr = [int(x) for x in linie]

arr.sort()
for i in range(len(arr)):
    g.write(f"{str(arr[i])} ")

print("--- %s seconds ---" % (time.time() - start_time))
f.close()
g.close()
