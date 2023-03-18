#shellSort
def shellSort(arr, n):
    gap=n//2
    while gap>0:
        j=gap
        while j<n:
            i=j-gap
            while i>=0:
                if arr[i+gap]>=arr[i]:
                    break
                else:
                    arr[i+gap],arr[i]=arr[i],arr[i+gap]
  
                i=i-gap 
            j+=1
        gap=gap//2


import time
start_time = time.time()
f = open("date.in","r")
g = open("date.out","w")
linie = f.read().split()
arr = [int(x) for x in linie]
arr2 = sorted(arr)
shellSort(arr,len(arr))

if arr2 == arr:
    for i in range(len(arr)):
        g.write(f"{str(arr[i])} ")
else:
    print("Ceva gresit")

print("--- %s seconds ---" % (time.time() - start_time))
f.close()
g.close()
