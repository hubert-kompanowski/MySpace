def silnia_rekurencyjnie(n):
    if n == 1:
        return 1
    else:
        tmp = n*silnia_rekurencyjnie(n-1)
        return tmp 
        
def silnia_iteracyjnie(n):
    silnia = 1
    for i in range(n, 1, -1):
        silnia *= i
        print(i)
    return silnia
        

x = int(input("Podaj n: "))

wynik = silnia_rekurencyjnie(x)
wynik2 = silnia_iteracyjnie(x)

print("rek: n! = ",wynik)
print("iter: n! = ",wynik2)