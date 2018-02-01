import pygame
import sys
import grafika
import czlowiek_vs_komputer
import czlowiek_vs_czlowiek
import ai_vs_czlowiek

class Game(object):
    def __init__(self):

        self.tps_max = 10.0
        pygame.init()
        self.screen = pygame.display.set_mode((422, 730))
        self.tps_clock = pygame.time.Clock()
        self.tps_delta = 0.0

        self.size = self.screen.get_size()
        self.srodek = (int(self.size[0] / 2.0), int(self.size[1] / 2.0))
        self.aktualnie_wyswietlane = 1
        self.click_vs = 0
        self.click_runda = 0
        self.aktualny_kolor = 0
        self.aktualny_vs = 0
        self.click_kolor = 0
        self.wstecz = 0
        self.wstecz_2 = 0
        self.click_miejsce = 0
        self.click = pygame.mouse.get_pressed()
        self.click_pole = 0
        self.enter = 0
        self.y_1 = 571
        self.yz = 1
        self.wiersz = 1
        self.kod_los = [0, 0, 0, 0]
        self.reset = 0
        self.stop = 0
        self.mozna_grac = 0
        self.twoj_kod = [0, 0, 0, 0]
        self.kod_los_blad = []
        self.zwracanie_krokow = [[0 for col_t in range(5)] for row_t in range(10)]
        self.uruchomienie_ai = 1
        self.graj = 0
        self.proba = []
        self.suma = 0
        self.suma_2 = 0
        self.suma_3 = 0
        self.raz_tylko = 1



        clock = pygame.time.Clock()
        FPS = 15
        # event draw i tick
        while True:

            clock.tick(FPS)

            for event in pygame.event.get():
                if self.wstecz == 1:
                    if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                        self.wstecz_2 = 1
                click = 0
                if event.type == pygame.QUIT:
                    sys.exit(0)
                elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                    self.wstecz = 1

            self.draw()
            pygame.display.flip()
            self.tps_delta -= 1 / self.tps_max

    def draw(self):
        pos = pygame.mouse.get_pos()
        click = pygame.mouse.get_pressed()
        if self.aktualnie_wyswietlane == 1:
            grafika.Grafika.menu(self)
        elif self.aktualnie_wyswietlane == 2:
            grafika.Grafika.instrukcja_2(self)
        elif self.aktualnie_wyswietlane == 3:
            grafika.Grafika.nowa_gra_2(self)

            ramka_opcje = pygame.image.load("Obrazy/ramka_opcje.png")
            ramka_opcje_mala = pygame.image.load("Obrazy/ramka_opcje_mala.png")

            # zazanczanie opcji vs
            if pos[0] in range(60, 363) and pos[1] in range(104, 165):
                if click[0]:
                    self.click_vs = 1
            if pos[0] in range(60, 363) and pos[1] in range(170, 220):
                if click[0]:
                    self.click_vs = 2
            if pos[0] in range(60, 363) and pos[1] in range(236, 286):
                if click[0]:
                    self.click_vs = 3
            if self.click_vs == 1:
                self.screen.blit(ramka_opcje, (60, 104))
            if self.click_vs == 2:
                self.screen.blit(ramka_opcje, (60, 170))
            if self.click_vs == 3:
                self.screen.blit(ramka_opcje, (60, 236))

            # zaznaczanie rundy
            if pos[0] in range(215, 261) and pos[1] in range(329, 373):
                if click[0]:
                    self.click_runda = 1
            if pos[0] in range(277, 322) and pos[1] in range(328, 372):
                if click[0]:
                    self.click_runda = 2
            if pos[0] in range(340, 384) and pos[1] in range(328, 372):
                if click[0]:
                    self.click_runda = 3
            if self.click_runda == 1:
                self.screen.blit(ramka_opcje_mala, (215, 329))
            if self.click_runda == 2:
                self.screen.blit(ramka_opcje_mala, (277, 328))
            if self.click_runda == 3:
                self.screen.blit(ramka_opcje_mala, (340, 328))

            # zaznaczanie liczby kolorow
            if pos[0] in range(216, 261) and pos[1] in range(404, 447):
                if click[0]:
                    self.click_kolor = 1
            if pos[0] in range(277, 322) and pos[1] in range(403, 447):
                if click[0]:
                    self.click_kolor = 2
            if pos[0] in range(340, 384) and pos[1] in range(403, 447):
                if click[0]:
                    self.click_kolor = 3
            if self.click_kolor == 1:
                self.screen.blit(ramka_opcje_mala, (215, 404))
            if self.click_kolor == 2:
                self.screen.blit(ramka_opcje_mala, (277, 403))
            if self.click_kolor == 3:
                self.screen.blit(ramka_opcje_mala, (340, 403))

        elif self.aktualnie_wyswietlane == 4:
            grafika.Grafika.graj_12(self)

        elif self.aktualnie_wyswietlane == 5:
            grafika.Grafika.graj_10(self)

        elif self.aktualnie_wyswietlane == 6:
            grafika.Grafika.graj_8(self)

        self.click = pygame.mouse.get_pressed()
        pos = pygame.mouse.get_pos()

        if self.aktualnie_wyswietlane == 2 or self.aktualnie_wyswietlane == 3 or self.aktualnie_wyswietlane == 7:
            if self.wstecz == 1:
                self.aktualnie_wyswietlane = 1
                self.wstecz = 0
            if pos[0] in range(21, 127) and pos[1] in range(19, 88) and self.click[0]:
                self.aktualnie_wyswietlane = 1

        if self.aktualnie_wyswietlane in [4, 5, 6]:
            if self.wstecz == 1:

                wyjscie = pygame.image.load("Obrazy/wyjsc.png")
                self.screen.blit(wyjscie, (0, 300))
                self.stop = 1

                if self.wstecz_2 == 1:
                    self.aktualnie_wyswietlane = 1
                    self.reset = 1
                    self.wstecz = 0
                    self.wstecz_2 = 0
                    self.stop = 0
                    czlowiek_vs_czlowiek.Kod.reset(self)

                przycisk = pygame.key.get_pressed()
                if przycisk[13]:
                    self.stop = 0
                    self.wstecz = 0
                    self.wstecz_2 = 0

            if self.aktualny_kolor == 8:
                grafika.Grafika.kulki_osiem(self)
            elif self.aktualny_kolor == 7:
                grafika.Grafika.kulki_siedem(self)
            elif self.aktualny_kolor == 6:
                grafika.Grafika.kulki_szesc(self)
            if self.aktualny_vs == 1:
                czlowiek_vs_komputer.Kod.main(self, self.aktualny_kolor)
                czlowiek_vs_komputer.Kod.kod_gry(self, self.aktualny_kolor)
            elif self.aktualny_vs == 2:
                if self.mozna_grac == 1:
                    ai_vs_czlowiek.Kod.main(self, self.aktualny_kolor)
                    ai_vs_czlowiek.Kod.kod_gry(self, self.aktualny_kolor)
                elif self.mozna_grac == 0:
                    czlowiek_vs_czlowiek.Ustawianie_Kodu.main(self, self.aktualny_kolor)
            elif self.aktualny_vs == 3:
                if self.mozna_grac == 1:
                    czlowiek_vs_czlowiek.Kod.main(self, self.aktualny_kolor)
                    czlowiek_vs_czlowiek.Kod.kod_gry(self, self.aktualny_kolor)
                elif self.mozna_grac == 0:
                    czlowiek_vs_czlowiek.Ustawianie_Kodu.main(self, self.aktualny_kolor)


        if self.aktualnie_wyswietlane == 1:
            if self.wstecz == 1:
                sys.exit(0)
            if pos[0] in range(95, 326) and pos[1] in range(326, 382):
                if self.click[0]:
                    self.aktualnie_wyswietlane = 7
            if pos[0] in range(95, 326) and pos[1] in range(170, 229):
                if self.click[0]:
                    self.aktualnie_wyswietlane = 3
            if pos[0] in range(95, 326) and pos[1] in range(246, 307):
                if self.click[0]:
                    self.aktualnie_wyswietlane = 2
            if pos[0] in range(95, 326) and pos[1] in range(400, 462):
                if self.click[0]:
                    sys.exit(0)

        if self.aktualnie_wyswietlane == 3:
            if pos[0] in range(126, 299) and pos[1] in range(548, 606):
                if self.click_runda and self.click_kolor and self.click_vs:
                    if self.click[0]:
                        self.graj = 1

            if self.graj == 1:
                if self.click_runda == 3:
                    self.aktualnie_wyswietlane = 4
                elif self.click_runda == 2:
                    self.aktualnie_wyswietlane = 5
                elif self.click_runda == 1:
                    self.aktualnie_wyswietlane = 6

                if self.click_kolor == 1:
                    self.aktualny_kolor = 6
                elif self.click_kolor == 2:
                    self.aktualny_kolor = 7
                elif self.click_kolor == 3:
                    self.aktualny_kolor = 8

                if self.click_vs == 1:  # czlowiek vs komputer
                    self.aktualny_vs = 1
                elif self.click_vs == 2:
                    self.aktualny_vs = 2
                elif self.click_vs == 3:
                    self.aktualny_vs = 3
                self.graj = 0

        if self.aktualnie_wyswietlane == 7:

            o_grze = pygame.image.load("Obrazy/o_grze.png")
            self.screen.blit(o_grze, (1, 1))

            strzalka = pygame.image.load("Obrazy/strzalka.png")

            pos = pygame.mouse.get_pos()
            if pos[0] in range(21, 127) and pos[1] in range(23, 88):
                self.screen.blit(strzalka, (21, 23))

if __name__ == "__main__":
    Game()
