#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <ncurses.h>
#include "menu.c"

int menu(const int ilosc_opcji, char* tablica_opcji[ilosc_opcji + 1]);

#endif 
