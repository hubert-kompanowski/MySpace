
n = int(input("Podaj maksymalna liczbe: "))


for i in range(2, n):
    liczba = i
    suma_dzielnikow = 0
    for j in range(i-1, 0, -1):
        if liczba % j == 0:
            suma_dzielnikow += j
    if liczba == suma_dzielnikow:
        print(liczba)
    
        