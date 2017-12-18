import time
from math import sqrt

n = int(input("Podaj n:"))

start_time = time.time()

tab = [1]*(n+1)
x = int(sqrt(n)+1)

for i in range(2, x):
    if(tab[i]==1):
        for j in range(i+1, n+1):
            if (j%i==0):
                tab[j]=0
                
print("---%s seconds ---" %(time.time() - start_time))

for k in range(2,n+1):
    if(tab[k]==1):
        print(k, " ", end='')

