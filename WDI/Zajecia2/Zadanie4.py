print("Zamiana liczby z systemu1 na system2:\n")
xsys1=int(input('S1=' ))
napis='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
print ('\n         Możesz użyć znaków:\n         ',napis[0:xsys1])
x_in=input('\nL=')

x10=0
n=1
m=1
dl_x_in=len(x_in)

for i in range (dl_x_in):    
    znak=x_in[(dl_x_in-m)]
    x10=x10+napis.index(znak)*n
    n=n*xsys1
    m=m+1
  
xsys2=int(input('\nS2='))

liczba=''
while (x10!=0):
    y=x10%xsys2
    liczba=napis[y] + liczba
    x10=(x10//xsys2)
    
print('         Podana liczba w systemie',xsys2,"-kowym wynosi:\n=",liczba)
input('         Aby zakończy nacinij Enter...')
