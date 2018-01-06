import random
import math
import time


def generowanie_tablicy(wielkosc):
    random.seed()
    tab = []
    for i in range(wielkosc):
        tab = tab + [random.randrange(-100, 100)]
    return tab


#   boubble_sort
def sortowanie_babelkowe(dane):
    for i in range(len(dane) - 1, 0, -1):
        flaga = 0
        for j in range(i):
            if dane[j] > dane[j + 1]:
                dane[j], dane[j + 1] = dane[j + 1], dane[j]
                flaga = 1
        if flaga == 0:
            break
    return dane


#   insertion_sort
def sortowanie_przez_wstawianie(dane):
    for i in range(1, len(dane)):
        klucz = dane[i]
        j = i - 1
        while j >= 0 and dane[j] > klucz:
            dane[j + 1] = dane[j]
            j = j - 1
        dane[j + 1] = klucz
    return dane


#   selection_sort
def sortowanie_przez_wybieranie(dane):
    for i in range(len(dane) - 1, 0, -1):
        maximum = 0
        for j in range(1, i):
            if dane[j] >= dane[maximum]:
                maximum = j
        dane[maximum], dane[j] = dane[j], dane[maximum]
    return dane


#   quick_sort
def sortowanie_szybkie(dane, lewy=0, prawy=None):
    if prawy is None:
        prawy = len(dane) - 1
    lew_p, praw_p = lewy, prawy
    pivot = dane[(lewy + prawy) // 2]
    while lew_p <= praw_p:
        while dane[lew_p] < pivot:
            lew_p += 1
        while dane[praw_p] > pivot:
            praw_p -= 1
        if lew_p <= praw_p:
            dane[lew_p], dane[praw_p] = dane[praw_p], dane[lew_p]
            lew_p += 1
            praw_p -= 1
    if lewy < praw_p:
        sortowanie_szybkie(dane, lewy, praw_p)
    if prawy > lew_p:
        sortowanie_szybkie(dane, lew_p, prawy)
    return dane


def operacja_scalania(lista, poczatek, srodek, koniec):
    i = poczatek
    j = srodek + 1
    lista_pomocnicza = []
    while (i <= srodek) and (j <= koniec):
        if lista[j] < lista[i]:
            lista_pomocnicza.append(lista[j])
            j = j + 1
        else:
            lista_pomocnicza.append(lista[i])
            i = i + 1
    if i <= srodek:
        while i <= srodek:
            lista_pomocnicza.append(lista[i])
            i = i + 1
        else:
            while j <= koniec:
                lista_pomocnicza.append(lista[j])
                j = j + 1
    i = 0
    while i < len(lista_pomocnicza):
        lista[poczatek + i] = lista_pomocnicza[i]
        i += 1
    return lista


#   merge_sort
def sortowanie_przez_scalanie(lista, poczatek, koniec):
    if poczatek != koniec:
        srodek = int(math.floor((poczatek + koniec) / 2))
        sortowanie_przez_scalanie(lista, poczatek, srodek)
        sortowanie_przez_scalanie(lista, srodek + 1, koniec)
        operacja_scalania(lista, poczatek, srodek, koniec)
    return lista


def element_poczatkowy_na_dol(lista, start, end):
    rodzic = start
    while True:
        dziecko = rodzic * 2 + 1
        if dziecko > end:
            break
        if dziecko + 1 <= end and lista[dziecko] < lista[dziecko + 1]:
            dziecko += 1
        if lista[rodzic] < lista[dziecko]:
            lista[rodzic], lista[dziecko] = lista[dziecko], lista[rodzic]
            rodzic = dziecko
        else:
            break


# heap_sort
def sortowanie_przez_kopcowanie(lista):
    for poczatek in range(int((len(lista) - 2) / 2), -1, -1):
        element_poczatkowy_na_dol(lista, poczatek, len(lista) - 1)
    for koniec in range(len(lista) - 1, 0, -1):
        lista[koniec], lista[0] = lista[0], lista[koniec]
        element_poczatkowy_na_dol(lista, 0, koniec - 1)
    return lista



