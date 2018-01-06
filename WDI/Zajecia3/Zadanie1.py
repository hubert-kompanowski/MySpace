import random
import time
import os


szer = int(input("Podaj szerokosc:"))
wys = int(input("Podaj wysokosc:"))

n = 0
 
random.seed()
los = random.randrange(1, szer)
lista = [(-1)]

napis = [los]+[lista[0]]*(szer-1)
    
for j in range(100):
    while (n < wys):
        if (napis[n]!=(-1)):
            print('  '*(napis[n]-1)+"X", "  "*(szer-napis[n]))
        else:
            print('  '*szer)  
        n = n+1
       
    random.seed()
    los = random.randrange(1, szer)
    napis = [los]+napis[0:szer-1]
    n = 0
    time.sleep(0.1)
    os.system("clear")
    
