import pygame

aktualnie_wyswietlane = [[0 for col in range(14)] for row in range(5)]
aktualna_podpowiedz = [[0 for col_ in range(14)] for row_ in range(5)]

class Kod(object):
    def main(self, aktualny_kolor):

        Kod.reset(self)

        self.pos = pygame.mouse.get_pos()

        if self.stop == 0:
            if aktualnie_wyswietlane[1][self.wiersz] and aktualnie_wyswietlane[2][self.wiersz] and aktualnie_wyswietlane[3][self.wiersz] and aktualnie_wyswietlane[4][self.wiersz]:

                enter = pygame.key.get_pressed()
                if enter[13]:

                    self.enter += 1

        Kod.wyswietlanie_pytajnikow(self)
        Kod.wyswietlanie_kulek(self)

        if aktualny_kolor == 6:
            x_1, x_2 = 77, 111

        if aktualny_kolor == 7:
            x_1, x_2 = 57, 89

        if aktualny_kolor == 8:
            x_1, x_2 = 37, 70

        x_pole_1, x_pole_2 = 156, 190
        if self.click[0]:
            pozycja = pygame.mouse.get_pos()
        else:
            pozycja = (-1, -1)

        for pole in range(1, 5):
            if pozycja[0] in range(x_pole_1, x_pole_2) and pozycja[1] in range(self.y_1, self.y_1 + 35):
                self.click_pole = pole
            x_pole_1 += 58
            x_pole_2 += 58

            #        print(self.click_pole)
        for kulka in range(1, aktualny_kolor + 1):
            if pozycja[0] in range(x_1, x_2) and pozycja[1] in range(665, 700):
                aktualnie_wyswietlane[self.click_pole][self.wiersz] = kulka
            x_1 += 46
            x_2 += 46

    def kod_gry(self, aktualny_kolor):

        self.kod_los = self.twoj_kod


        dodatkowe_2 = 0
        sprawdzenie = [0, 0, 0, 0]
        for wiersz in range(0, self.click_runda * 2 + 6):
            index = 1
            tmp = [0, 0, 0, 0]
            self.podpowiedz = []


            if self.enter == wiersz:
                self.podpowiedz.append(0)

                if aktualnie_wyswietlane[1][wiersz + 1] == self.kod_los[0]:
                    self.podpowiedz.append(1)
                    index += 1
                    tmp.append(self.kod_los[0])


                if aktualnie_wyswietlane[2][wiersz + 1] == self.kod_los[1]:
                    self.podpowiedz.append(1)
                    index += 1
                    tmp.append(self.kod_los[1])

                if aktualnie_wyswietlane[3][wiersz + 1] == self.kod_los[2]:
                    self.podpowiedz.append(1)
                    index += 1
                    tmp.append(self.kod_los[2])

                if aktualnie_wyswietlane[4][wiersz + 1] == self.kod_los[3]:
                    self.podpowiedz.append(1)
                    index += 1
                    tmp.append(self.kod_los[3])

                self.kod_los_blad = self.kod_los.copy()

                for kol_2 in range(1, 5):
                    sprawdzenie[kol_2-1] = aktualnie_wyswietlane[kol_2][wiersz + 1]

                for kol in range(1, 5):

                    if sprawdzenie.count(aktualnie_wyswietlane[kol][wiersz + 1]) > tmp.count(aktualnie_wyswietlane[kol][wiersz + 1]):
                        dodatkowe_2 = self.kod_los_blad.count(aktualnie_wyswietlane[kol][wiersz + 1]) - tmp.count(aktualnie_wyswietlane[kol][wiersz + 1])
                        sprawdzenie.remove(aktualnie_wyswietlane[kol][wiersz + 1])

                    if dodatkowe_2 or (aktualnie_wyswietlane[kol][wiersz + 1] in self.kod_los_blad and not aktualnie_wyswietlane[kol][wiersz + 1] in tmp):
                        self.podpowiedz.append(2)
                        if self.kod_los_blad.count(aktualnie_wyswietlane[kol][wiersz + 1]):
                            self.kod_los_blad.remove(aktualnie_wyswietlane[kol][wiersz + 1])
                        dodatkowe_2 = 0
                #print("podp=",self.podpowiedz, "tmp=",tmp, "sprawdz=",sprawdzenie, "blad=",self.kod_los_blad)

            while index <= 5:
                self.podpowiedz.append(0)
                index += 1


            for kolumna in range(1, 5):

                if wiersz == self.enter and self.podpowiedz[kolumna] == 0:
                    aktualna_podpowiedz[kolumna][wiersz + 1] = 0

                if self.podpowiedz[kolumna] == 1:
                    aktualna_podpowiedz[kolumna][wiersz + 1] = 1

                if self.podpowiedz[kolumna] == 2:
                    aktualna_podpowiedz[kolumna][wiersz + 1] = 2

        Kod.wyswietlanie_podpowiedzi(self)
        Kod.czy_wygrana(self)

    def wyswietlanie_kulek(self):

        czerwona = pygame.image.load("Obrazy/kulki/czerwona.png")
        zielona = pygame.image.load("Obrazy/kulki/zielona.png")
        niebieska = pygame.image.load("Obrazy/kulki/niebieska.png")
        blekitna = pygame.image.load("Obrazy/kulki/blekitna.png")
        rozowa = pygame.image.load("Obrazy/kulki/rozowa.png")
        zolta = pygame.image.load("Obrazy/kulki/zolta.png")
        szara = pygame.image.load("Obrazy/kulki/szara.png")
        czarna = pygame.image.load("Obrazy/kulki/czarna.png")

        self.y = 571
        for wysokosc in range(1, 14):
            x = 156
            for xz in range(1, 5):
                if aktualnie_wyswietlane[xz][wysokosc] == 1:
                    self.screen.blit(czerwona, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 2:
                    self.screen.blit(zielona, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 3:
                    self.screen.blit(niebieska, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 4:
                    self.screen.blit(blekitna, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 5:
                    self.screen.blit(rozowa, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 6:
                    self.screen.blit(zolta, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 7:
                    self.screen.blit(szara, (x, self.y))

                elif aktualnie_wyswietlane[xz][wysokosc] == 8:
                    self.screen.blit(czarna, (x, self.y))

                x += 58
            self.y -= 50

    def wyswietlanie_pytajnikow(self):

        pytajnik = pygame.image.load("Obrazy/kulki/pytajnik2.png")

        for wiersz_2 in range(1, self.click_runda * 2 + 6):

            if self.enter == wiersz_2:
                self.y_1 = 571 - 50 * wiersz_2
                self.wiersz = wiersz_2 + 1  # self wiersz - ktora linijka po enterze

                self.screen.blit(pytajnik, (156, 571 - 50 * wiersz_2))
                self.screen.blit(pytajnik, (214, 571 - 50 * wiersz_2))
                self.screen.blit(pytajnik, (272, 571 - 50 * wiersz_2))
                self.screen.blit(pytajnik, (330, 571 - 50 * wiersz_2))
            elif self.enter == 0:
                self.screen.blit(pytajnik, (156, 571))
                self.screen.blit(pytajnik, (214, 571))
                self.screen.blit(pytajnik, (272, 571))
                self.screen.blit(pytajnik, (330, 571))

    def wyswietlanie_podpowiedzi(self):

        mala_czarna = pygame.image.load("Obrazy/kulki/mala_czarna.png")
        mala_biala = pygame.image.load("Obrazy/kulki/mala_biala.png")

        for wysokos_2 in range(1, 14):
            if self.enter + 1 == wysokos_2:
                continue
            if aktualna_podpowiedz[1][wysokos_2] == 1:
                self.screen.blit(mala_czarna, (37, 623 - 50 * wysokos_2))
            elif aktualna_podpowiedz[1][wysokos_2] == 2:
                self.screen.blit(mala_biala, (37, 623 - 50 * wysokos_2))

            if aktualna_podpowiedz[2][wysokos_2] == 1:
                self.screen.blit(mala_czarna, (61, 623 - 50 * wysokos_2))
            elif aktualna_podpowiedz[2][wysokos_2] == 2:
                self.screen.blit(mala_biala, (61, 623 - 50 * wysokos_2))

            if aktualna_podpowiedz[3][wysokos_2] == 1:
                self.screen.blit(mala_czarna, (37, 647 - 50 * wysokos_2))
            elif aktualna_podpowiedz[3][wysokos_2] == 2:
                self.screen.blit(mala_biala, (37, 647 - 50 * wysokos_2))

            if aktualna_podpowiedz[4][wysokos_2] == 1:
                self.screen.blit(mala_czarna, (61, 647 - 50 * wysokos_2))
            elif aktualna_podpowiedz[4][wysokos_2] == 2:
                self.screen.blit(mala_biala, (61, 647 - 50 * wysokos_2))

    def czy_wygrana(self):
        wygrana_w_ostatiej = 0
        for wiersz in range(1, 14):
            if aktualna_podpowiedz[1][wiersz] == 1 and aktualna_podpowiedz[2][wiersz] == 1 :
                if aktualna_podpowiedz[3][wiersz] == 1 and aktualna_podpowiedz[4][wiersz] == 1:
                    if self.enter + 1 == wiersz:
                        continue
                    wygrana_w_ostatiej = 1
                    wygrana = pygame.image.load("Obrazy/wygrana.png")

                    for q in range(1,5):
                        for p in range(0, self.click_runda * 2 + 7):
                            aktualnie_wyswietlane[q][p] = self.kod_los[q - 1]

                    self.screen.blit(wygrana, (0, 300))
                    self.stop = 1
                    if self.wstecz == 1:
                        self.stop = 0
                        self.aktualnie_wyswietlane = 1
                        self.mozna_grac = 0
                        self.twoj_kod = [0, 0, 0, 0]
                        self.reset = 1
                        Kod.reset(self)
        if self.enter == self.click_runda * 2 + 6 and wygrana_w_ostatiej == 0:
            przegrana = pygame.image.load("Obrazy/przegrana.png")
            self.screen.blit(przegrana, (0, 300))

            for q in range(1, 5):
                for p in range(0, self.click_runda * 2 + 7):
                    aktualnie_wyswietlane[q][p] = self.kod_los[q - 1]

            self.stop = 1
            if self.wstecz == 1:
                self.stop = 0
                self.aktualnie_wyswietlane = 1
                self.reset = 1
                Kod.reset(self)

    def reset(self):
        if self.reset == 1:
            for iksy in range(1, 5):
                for igreki in range(1, 14):
                    aktualnie_wyswietlane[iksy][igreki] = 0
                    aktualna_podpowiedz[iksy][igreki] = 0

            self.click_vs = 0
            self.click_runda = 0
            self.aktualny_kolor = 0
            self.aktualny_vs = 0
            self.click_kolor = 0
            self.wstecz = 0
            self.click_miejsce = 0
            self.click = pygame.mouse.get_pressed()
            self.click_pole = 0
            self.enter = 0
            self.y_1 = 571
            self.yz = 1
            self.wiersz = 1
            self.kod_los = [0, 0, 0, 0]
            self.reset = 0
            self.mozna_grac = 0
            self.twoj_kod = [0, 0, 0, 0]
            self.mozna_grac = 0


class Ustawianie_Kodu(object):

    def main(self, ilosc_kolorow):

        ustawiony_kod = pygame.image.load("Obrazy/ukladanie_kodu.png")
        self.screen.blit(ustawiony_kod, (0,0))

        if ilosc_kolorow == 6:
            Ustawianie_Kodu.kulki_szesc(self)
            x_1, x_2 = 77, 111

        elif ilosc_kolorow == 7:
            Ustawianie_Kodu.kulki_siedem(self)
            x_1, x_2 = 57, 89

        elif ilosc_kolorow == 8:
            Ustawianie_Kodu.kulki_osiem(self)
            x_1, x_2 = 37, 70

        x_pole_1, x_pole_2 = 122, 155
        if self.click[0]:
            pozycja = pygame.mouse.get_pos()
        else:
            pozycja = (-1, -1)

        # Klikanie na twoj kod
        for pole in range(0, 4):
            if pozycja[0] in range(x_pole_1, x_pole_2) and pozycja[1] in range(546, 580):
                self.click_pole = pole
            x_pole_1 += 49
            x_pole_2 += 49

        # klikanie na liste kolorow
        for kulka in range(1, ilosc_kolorow + 1):
            if pozycja[0] in range(x_1, x_2) and pozycja[1] in range(665, 700):
                self.twoj_kod[self.click_pole] = kulka
            x_1 += 46
            x_2 += 46

        czerwona = pygame.image.load("Obrazy/kulki/czerwona.png")
        zielona = pygame.image.load("Obrazy/kulki/zielona.png")
        niebieska = pygame.image.load("Obrazy/kulki/niebieska.png")
        blekitna = pygame.image.load("Obrazy/kulki/blekitna.png")
        rozowa = pygame.image.load("Obrazy/kulki/rozowa.png")
        zolta = pygame.image.load("Obrazy/kulki/zolta.png")
        szara = pygame.image.load("Obrazy/kulki/szara.png")
        czarna = pygame.image.load("Obrazy/kulki/czarna.png")

        x = 122
        for numer in range(4):
            if self.twoj_kod[numer] == 1:
                self.screen.blit(czerwona, (x, 546))
            if self.twoj_kod[numer] == 2:
                self.screen.blit(zielona, (x, 546))
            if self.twoj_kod[numer] == 3:
                self.screen.blit(niebieska, (x, 546))
            if self.twoj_kod[numer] == 4:
                self.screen.blit(blekitna, (x, 546))
            if self.twoj_kod[numer] == 5:
                self.screen.blit(rozowa, (x, 546))
            if self.twoj_kod[numer] == 6:
                self.screen.blit(zolta, (x, 546))
            if self.twoj_kod[numer] == 7:
                self.screen.blit(szara, (x, 546))
            if self.twoj_kod[numer] == 8:
                self.screen.blit(czarna, (x, 546))
            x += 49

        if self.stop == 0:
            if self.twoj_kod[0] and self.twoj_kod[1] and self.twoj_kod[2] and self.twoj_kod[3]:
                enter = pygame.key.get_pressed()
                if enter[13]:
                    self.mozna_grac = 1

        if self.wstecz == 1:
            wyjscie = pygame.image.load("Obrazy/wyjsc.png")
            self.screen.blit(wyjscie, (0, 300))
            self.stop = 1

    def kulki_szesc(self):
        k_6 = pygame.image.load("Obrazy/kulki_6.png")
        self.screen.blit(k_6, (62, 650))

    def kulki_siedem(self):
        k_7 = pygame.image.load("Obrazy/kulki_7.png")
        self.screen.blit(k_7, (40, 650))

    def kulki_osiem(self):
        k_8 = pygame.image.load("Obrazy/kulki_8.png")
        self.screen.blit(k_8, (21, 650))