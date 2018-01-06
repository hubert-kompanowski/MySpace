tekst = 'hubert jest super abc xyz'
alfabet ="nmpiljkohfycgtbuvrqeaswzxd"

def szyfr_cezara(tekst, przesuniecie):
    szyfr = ""    
    for i in tekst:
        if i == " ":
            szyfr += " " 
            continue
        if ord(i) + przesuniecie > 122:
            numer = przesuniecie + ord(i) - 26 
        else:
            numer = ord(i) + przesuniecie
        i = chr(numer)
        szyfr += i
    return szyfr
        

def deszyfrator_cezara(szyfr, przesuniecie):
    tekst = ""
    for i in szyfr:
        if i == " ":
            tekst += " "
            continue
        if ord(i) - przesuniecie < 97:
            numer = 26 - przesuniecie + ord(i)
        else:
            numer = ord(i) - przesuniecie
        i = chr(numer)
        tekst+=i
    return tekst

def szyfr_podstawieniowy(tekst, alfabet):    
    szyfr = ""
    for i in tekst:
        if i == " ":
            szyfr += " "
            continue
        indeks = ord(i)-97
        szyfr += alfabet[indeks]
    return szyfr
            


#szyfr = szyfr_cezara(tekst, 3)
#tekst = deszyfrator_cezara(szyfr, 3)
#print(tekst)


szyfr = szyfr_podstawieniowy(tekst, 3)
#tekst = deszyfrator_cezara(szyfr, 3)
print(szyfr)