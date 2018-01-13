dane = [4,5,2,7,9,3,4,5,6,1,2,9,10,22,4,2,5]

def sortownanie_babelkowe(dane):
    for i in range(len(dane)-1, 0, -1):
        flaga=0
        for j in range(i):
            if dane[j]>dane[j+1]:
                dane[j], dane[j+1] = dane[j+1], dane[j]
                flaga = 1
        if flaga == 0:
            break
        
sortownanie_babelkowe(dane)
print(dane)
