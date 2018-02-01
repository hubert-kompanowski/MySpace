from itertools import product, tee
from random import choice

class Ai(object):

    def __init__(self):
        self.colors = (('1', '2', '3', '4', '5', '6'))
        if self.aktualny_kolor == 6:
            self.colors = ('1', '2', '3', '4', '5', '6')
        if self.aktualny_kolor == 7:
            self.colors = ('1', '2', '3', '4', '5', '6', '7')
        if self.aktualny_kolor == 8:
            self.colors = ('1', '2', '3', '4', '5', '6', '7', '8')

        self.zwracanie_krokow = [[0 for col_t in range(5)] for row_t in range(10)]
        self.holes = 4

    def losowe_rozwiazanie(self):
        return tuple(choice(self.colors) for i in range(self.holes))

    def wszystkie_rozwiazania(self):
        for self.solution in product(*tee(self.colors, self.holes)):
            yield self.solution

    def sprawdzanie_czy_pasuje(self, solution_space, guess, result):
        for self.solution in solution_space:
            if Ai.punkty(self, guess, self.solution) == result:
                yield self.solution

    def punkty(self, aktualnie, sugestia):
        wynik = []
        aktualna_lista = list(aktualnie)
        lista_sugestii = list(sugestia)
        pozycja_czarnej = [numer for numer, para in enumerate(zip(aktualna_lista, lista_sugestii)) if para[0] == para[1]]
        for numer in reversed(pozycja_czarnej):
            del aktualna_lista[numer]
            del lista_sugestii[numer]
            wynik.append('czarna')
        for color in lista_sugestii:
            if color in aktualna_lista:
                aktualna_lista.remove(color)
                wynik.append('biala')
        return tuple(wynik)

    def usunac_najmniej(self, przestrzen_rozwiazan, rozwiazanie):
        licznik_wynikow = {}
        for opcje in przestrzen_rozwiazan:
            wynik = Ai.punkty(self, rozwiazanie, opcje)
            if wynik not in licznik_wynikow.keys():
                licznik_wynikow[wynik] = 1
            else:
                licznik_wynikow[wynik] += 1
        return len(przestrzen_rozwiazan) - max(licznik_wynikow.values())

    def najlepszy_ruch(self, przestrzen_rozwiazan):
        usuwanie_rozwiazan = dict((Ai.usunac_najmniej(self, przestrzen_rozwiazan, rozwiazanie), rozwiazanie) for rozwiazanie in przestrzen_rozwiazan)
        najwieksze_wyeliminowane = max(usuwanie_rozwiazan.keys())
        return usuwanie_rozwiazan[najwieksze_wyeliminowane]

    def main(self, aktualnie = None):

        self.colors = (('1', '2', '3', '4', '5', '6'))
        if self.aktualny_kolor == 6:
            self.colors = ('1', '2', '3', '4', '5', '6')
        if self.aktualny_kolor == 7:
            self.colors = ('1', '2', '3', '4', '5', '6', '7')
        if self.aktualny_kolor == 8:
            self.colors = ('1', '2', '3', '4', '5', '6', '7', '8')

        self.holes = 4

        if aktualnie == None:
            aktualnie = Ai.losowe_rozwiazanie(self)

        obecna_sugestia = self.colors[:self.holes]

        przestrzen_rozwiazan = Ai.wszystkie_rozwiazania(self)
        sugestie = 1
        x = 0
        while True:
            obecne_punkty = Ai.punkty(self, aktualnie, obecna_sugestia)
            if obecne_punkty == tuple(['czarna'] * self.holes):
                return sugestie

            przestrzen_rozwiazan = tuple(Ai.sprawdzanie_czy_pasuje(self, przestrzen_rozwiazan, obecna_sugestia, obecne_punkty))

            obecna_sugestia = Ai.najlepszy_ruch(self, przestrzen_rozwiazan)

            self.proba += obecna_sugestia

            sugestie += 1
