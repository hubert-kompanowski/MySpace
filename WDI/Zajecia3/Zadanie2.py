import time
import os

szer=int(input("Podaj szerokosc(Nieparzysta):"))
wys=int(input("Podaj wysokosc(Nieparzysta):"))

sx=szer//2+1
sy=wys//2+1
x=1
y=1
z=0
a=1
n=0
m=min(sx,sy)

for k in range(100):
    for i in range(wys):
        for j in range(szer):
            if (max(abs(sx-x), abs(sy-y))==z):
                print("X ",end="")
            else:
                print("  ",end="")
            x=x+1
            
        x=1
        y=y+1
        print("")
        
    n=n+1
    z=z+a
    y=1    
    if (n%(m-1)==0):
        a=a*(-1)
    
    time.sleep(1.075) 
    os.system("clear")

    
