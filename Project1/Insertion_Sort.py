#Insertion Sort
import time
start_time = time.time()
f = open("date.in","r")
g = open("date.out","w")
linie = f.read().split()
arr = [int(x) for x in linie]
arr2 = sorted(arr)


for i in range(1,len(arr)):
    key = arr[i]
    j = i-1
    while j>=0 and key < arr[j]:
        arr[j+1] = arr[j]
        j-=1
    arr[j+1] = key



if arr2 == arr:
    for i in range(len(arr)):
        g.write(f"{str(arr[i])} ")
else:
    print("Ceva gresit")

print("--- %s seconds ---" % (time.time() - start_time))
f.close()
g.close()
