lista = [5,7,4,18,3,7,5,1,2,12,7,13]
x = int(max(lista))
tab = [1]*(x+1)

for i in range(2, x):               #  Tworzy tablice [1,1,1,1,0,1,0,1,0,0...]
    if(tab[i]==1):                  #  indeksy jedynek to liczby pierwsze
        for j in range(i+1, x+1):
            if (j%i==0):
                tab[j]=0

liczby_pierwsze = []
for k in range(2,x+1):   # Tworzy listę liczb pierwszych 
    if(tab[k]==1):
        liczby_pierwsze = liczby_pierwsze + [k]
        
uniq = list(set(lista))  #   Tworzy listę unikalnych wartosci z "listy" 
                            
for l in range(len(uniq)):                            # Pętla wszystkich liczb z uniq
    if (lista.count(uniq[l])%2!=0):                   # Jeśli liczba nie jest parzysta
        if (liczby_pierwsze.count(uniq[l])>0):        # i jeśli liczba występuje w liczby_pierwsze
            for m in range(0,lista.count(uniq[l])):   # usuwa wszystkie takie liczby z "listy" 
                lista.remove(uniq[l])                                                          
print(lista)
