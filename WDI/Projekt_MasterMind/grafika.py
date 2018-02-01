import pygame

class Grafika(object):

    def menu(self):
        pygame.display.set_caption('MasterMind')
        self.tlo = pygame.image.load("Obrazy/kkk.png")
        self.ramka = pygame.image.load("Obrazy/ramka_2.png")

        size = self.screen.get_size()
        self.srodek_x = int(size[0] / 2)
        self.screen.blit(self.tlo, (0, 0))

        pos = pygame.mouse.get_pos()
        if pos[0] in range(95, 326) and pos[1] in range(170, 229):
            self.screen.blit(self.ramka, (self.srodek_x - 117, 170))

        if pos[0] in range(95, 326) and pos[1] in range(246, 307):
            self.screen.blit(self.ramka, (self.srodek_x - 117, 246))

        if pos[0] in range(95, 326) and pos[1] in range(323, 384):
            self.screen.blit(self.ramka, (self.srodek_x - 117, 323))

        if pos[0] in range(95, 326) and pos[1] in range(400, 462):
            self.screen.blit(self.ramka, (self.srodek_x - 117, 400))

    def instrukcja_2(self):
        tekst_instrukcji = pygame.image.load("Obrazy/tekst_instrukcji.png")
        self.screen.blit(tekst_instrukcji, (0, 0))

        strzalka = pygame.image.load("Obrazy/strzalka.png")

        pos = pygame.mouse.get_pos()
        if pos[0] in range(21, 127) and pos[1] in range(23, 88):
            self.screen.blit(strzalka, (21, 23))

    def nowa_gra_2(self):
        nowa_gra_2 = pygame.image.load("Obrazy/opcje.png")
        self.screen.blit(nowa_gra_2, (0, 0))
        pygame.display.flip()
        strzalka = pygame.image.load("Obrazy/strzalka.png")
        ramka_opcje = pygame.image.load("Obrazy/ramka_opcje.png")
        ramka_opcje_mala = pygame.image.load("Obrazy/ramka_opcje_mala.png")
        ramka_graj = pygame.image.load("Obrazy/graj.png")

        pos = pygame.mouse.get_pos()

        # strzalka
        if pos[0] in range(21, 127) and pos[1] in range(19, 88):
            self.screen.blit(strzalka, (21, 19))

        # duza ramka
        if pos[0] in range(60, 363) and pos[1] in range(104, 165):
            self.screen.blit(ramka_opcje, (60, 104))
        if pos[0] in range(60, 363) and pos[1] in range(170, 220):
            self.screen.blit(ramka_opcje, (60, 170))
        if pos[0] in range(60, 363) and pos[1] in range(236, 286):
            self.screen.blit(ramka_opcje, (60, 236))

        # mala ramka
        if pos[0] in range(215, 261) and pos[1] in range(329, 373):
            self.screen.blit(ramka_opcje_mala, (215, 329))
        if pos[0] in range(277, 322) and pos[1] in range(328, 372):
            self.screen.blit(ramka_opcje_mala, (277, 328))
        if pos[0] in range(340, 384) and pos[1] in range(328, 372):
            self.screen.blit(ramka_opcje_mala, (340, 328))
        if pos[0] in range(216, 261) and pos[1] in range(404, 447):
            self.screen.blit(ramka_opcje_mala, (215, 404))
        if pos[0] in range(277, 322) and pos[1] in range(403, 447):
            self.screen.blit(ramka_opcje_mala, (277, 403))
        if pos[0] in range(340, 384) and pos[1] in range(403, 447):
            self.screen.blit(ramka_opcje_mala, (340, 403))

        # ramka graj
        if pos[0] in range(126, 300) and pos[1] in range(545, 607):
            self.screen.blit(ramka_graj, (126, 545))

    def kulki_szesc(self):
        k_6 = pygame.image.load("Obrazy/kulki_6.png")
        self.screen.blit(k_6, (62, 650))

    def kulki_siedem(self):
        k_7 = pygame.image.load("Obrazy/kulki_7.png")
        self.screen.blit(k_7, (40, 650))

    def kulki_osiem(self):
        k_8 = pygame.image.load("Obrazy/kulki_8.png")
        self.screen.blit(k_8, (21, 650))

    def graj_12(self):
        _12 = pygame.image.load("Obrazy/12.png")
        self.screen.blit(_12, (0, 0))

    def graj_10(self):
        _10 = pygame.image.load("Obrazy/10.png")
        self.screen.blit(_10, (0, 0))

    def graj_8(self):
        _8 = pygame.image.load("Obrazy/8.png")
        self.screen.blit(_8, (0, 0))

