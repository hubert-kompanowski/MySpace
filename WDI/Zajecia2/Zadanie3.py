x10=int(input('        Wprowadź liczbę w systemie dziesiętnym:\n'))
xx=int(input('        Wprowadź liczbę reprezentującą system liczbowy:\n'))
napis='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
liczba=''
while (x10!=0):
    y=x10%xx
    liczba=napis[y] + liczba
    x10=(x10//xx)
print('        Podana liczba w systemie',xx,"-kowym wynosi:\n=",liczba)
input('        Aby zakończy nacinij Enter...')