x=int(input("Wprowadz liczbe w systemie dwojkowym:\n"))
a=1
y=0
while (x!=0):
    y=y+(x%10)*a
    a=a*2
    x=(x//10)
print ("\nliczba w systemie 10kowym wynosi",y)
input("\nNacinij Enter by zakończyć...")