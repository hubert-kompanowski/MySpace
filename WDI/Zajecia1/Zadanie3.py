import random
random.seed()
losowana = random.randrange(10) 
x=1
y='proby'
liczba=int(input("Podaj liczbe od 0-9:\n\n      "))
while (liczba!=losowana):
    x+=1
    if (liczba!=losowana):
        if (liczba>losowana):
            print ("\nLiczba zbyt duza!")
        else:
            print ("\nLiczba zbyt mala!")
    liczba=int(input("Sprobuj jeszcze raz:\n\n      "))
    y='prob'
print ("Gratulacje! Potrzebowales",x ,y,"by wygrac!\n")
input("Nacisnij enter aby wylaczyc...")