#Radix Sort

import time
start_time = time.time()
f = open("date.in","r")
g = open("date.out","w")
linie = f.read().split()
arr = [int(x) for x in linie] 
arr2 = sorted(arr)

placement = 1
radix = 2**10    # this is where we change the base for our radix, I ran tests with base 10, base 2^10 and base 2^16. I tried 2^32, but that is too big so the execution is killed
buckets = [[] for i in range(radix)]
max_length = False
while not max_length:
    max_length = True
    for i in arr:
        tmp = i // placement
        buckets[tmp % radix].append(i)
        if max_length and tmp>0:
            max_length= False
    i = 0
    for bucket in buckets:
        for num in bucket:
            arr[i] = num
            i += 1
        bucket.clear()
    placement *= radix

if arr2 == arr:
    for i in range(len(arr)):
        g.write(f"{str(arr[i])} ")
else:
    print("Ceva gresit")

print("--- %s seconds ---" % (time.time() - start_time))
f.close()
g.close()
