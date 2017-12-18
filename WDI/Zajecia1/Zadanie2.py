import math
bok1=int(input("Podaj bok1:"))
bok2=int(input("Podaj bok2:"))
bok3=int(input("Podaj bok3:"))
p=(0.5*(bok1+bok2+bok3))

if (bok1+bok2<=bok3 or bok1+bok3<=bok2 or bok2+bok3<=bok1):
    print("Nie mozna utorzyc trojkata!")
else:
    pole=math.sqrt(p*(p-bok1)*(p-bok2)*(p-bok3))
    print("Pole =",pole)
input("Press Enter to continue...")