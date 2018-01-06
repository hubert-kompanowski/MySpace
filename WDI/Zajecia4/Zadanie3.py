
def trojkat_pascala(n, k):
    
    if n==k or n==0:
        return 1
    if k==1 or k==n-1:
        return k
    return trojkat_pascala(n-1, k-1) + trojkat_pascala(n-1, k)

x = int(input("Podaj wysokosc trojkata pascala: "))

for i in range (1,x+1):
    print(" "*(x+1-i), end='')
    for j in range (1,i+1):
        print(" ",trojkat_pascala(i,j), end='')
    print("")