#ifndef WYSWIETLANIE_H
#define WYSWIETLANIE_H

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "wyswietlanie.c"

void wyswietlanie_w_polowie(int wiersz, const char* tekst);
int obsluga_strzalek(int znak);
void wyswietlanie_informacji(int rozmiar, char* tablica_tekstow[rozmiar]);
void wyswietlanie_mastermind(void);

#endif 

