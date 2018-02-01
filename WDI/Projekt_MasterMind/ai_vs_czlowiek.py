import ai
import pygame

aktualnie_wyswietlane = [[0 for col in range(14)] for row in range(5)]
aktualna_podpowiedz = [[0 for col_ in range(14)] for row_ in range(5)]

class Kod(object):
    def main(self, aktualny_kolor):
        self.pos = pygame.mouse.get_pos()

        if self.stop == 0:
            if aktualnie_wyswietlane[1][self.wiersz] and aktualnie_wyswietlane[2][self.wiersz] and aktualnie_wyswietlane[3][self.wiersz] and aktualnie_wyswietlane[4][self.wiersz]:
                enter = 1
                self.suma += 0.1
                if self.suma > 1:
                    if enter:
                        self.enter += 1
                    self.suma = 0

        Kod.wyswietlanie_pytajnikow(self)
        Kod.wyswietlanie_kulek(self)

        if self.uruchomienie_ai == 1 and self.kod_los[0] and self.kod_los[1] and self.kod_los[2] and self.kod_los[3]:
            ai.Ai.main(self, (str(self.kod_los[0]), str(self.kod_los[1]), str(self.kod_los[2]), str(self.kod_los[3])))
            self.uruchomienie_ai = 0

        self.suma_2 += 0.1
        if self.suma_2 > 4:
            for i in range(1, 5):
                aktualnie_wyswietlane[i][1] = i
            for j in range(2, (len(self.proba) // 4) + 2):
                if self.wiersz == j:
                    for ii in range(1, 5):
                        clock = pygame.time.Clock()
                        aktualnie_wyswietlane[ii][j] = int(self.proba[(ii-1) + 4*(j-2)])
            self.suma_2 = 0

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
                self.wiersz = wiersz_2 + 1

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
                        for p in range((len(self.proba) // 4 +1), self.click_runda * 2 + 7):
                            aktualnie_wyswietlane[q][p] = self.kod_los[q - 1]

                    self.screen.blit(wygrana, (0, 150))

                    self.stop = 1
                    if self.wstecz == 1:
                        self.stop = 0
                        self.aktualnie_wyswietlane = 1
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
            self.twoj_kod = [0, 0, 0, 0]
            self.reset = 0
            self.uruchomienie_ai = 1
            self.mozna_grac = 0
