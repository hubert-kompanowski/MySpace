#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "menu.c"

int menu(int ilosc_opcji, char* tablica_opcji[ilosc_opcji + 1]);

#endif 
