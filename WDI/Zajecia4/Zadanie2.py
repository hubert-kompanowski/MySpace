def fibb_rekurencyjnie(n):
    if n<=1 or n==2:
        return 1
    else:
        tmp = fibb_rekurencyjnie(n-1) + fibb_rekurencyjnie(n-2)
        return tmp

def fibb_iteracyjnie(n):
    liczba_n_1 = 1
    liczba_n_2 = 1
    
    for i in range(n-1):
        liczba_n_2 += liczba_n_1
        liczba_n_1 = liczba_n_2-liczba_n_1
        
    return liczba_n_1
            
x = int(input("Podaj n: "))

wynik = fibb_rekurencyjnie(x)
wynik2 = fibb_iteracyjnie(x)

print("rek: fibb = ",wynik)
print("iter: fibb = ",wynik2)