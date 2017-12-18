
print ("           Kalkulator!\n")
x=int(input("      Podaj pierwszą liczbę:\n"))
z=input("      Podaj znak '+'  '-'  '/'  '*'  '^' :\n")
y=int(input("      Podaj drugą liczbę:\n"))

if (z=='+'):
    print("\n=",x+y)
elif (z=='-'):
    print ("\n=",x-y)
elif (z=='/'):
    print ("\n=",x/y)
elif (z=='*'):
    print ("\n=",x*y)
elif (z=='^'):
    print ("\n=",x**y)
else: print ("\nNieprawidłowe dane!")
input("\nNacinij Enter by zakończyć...")