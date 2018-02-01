#ifndef WYSWIETLANIE_H
#define WYSWIETLANIE_H

#include <stdio.h>
#include <ncurses.h>
#include "wyswietlanie.c"
#include <string.h>

void wyswietlanie_w_polowie(int wiersz, const char* tekst);
int obsluga_strzalek(int znak);
void wyswietlanie_informacji(const int rozmiar, char* const tablica_tekstow[rozmiar]);
void wyswietlanie_mastermind(void);

#endif 

