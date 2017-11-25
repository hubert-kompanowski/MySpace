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
        
uniq = list(set(lista))  # Tworzy listę unikalnych wartosci z "listy" 
                            
for l in range(len(uniq)):
    if (lista.count(uniq[l])%2!=0):              
        if (liczby_pierwsze.count(uniq[l])>0):       # Usuwa z "listy" wartosci ktore
            for m in range(0,lista.count(uniq[l])):  # powtarzaja się nieparzysta ilość
                lista.remove(uniq[l])                # razy i są liczbami pierwszymi
print(lista)