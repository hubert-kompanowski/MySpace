#include "wyswietlanie.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void wyswietlanie_w_polowie(int wiersz, const char* tekst)
{
    int kolumny = 0, rzedy = 0;
    getmaxyx(stdscr, rzedy, kolumny);
    mvprintw(wiersz, (kolumny / 2) - (strlen(tekst) / 2), tekst);
}

void wyswietlanie_informacji(int rozmiar, char* tablica_tekstow[rozmiar])
{
    initscr();

    for(int i=0; i<rozmiar; i++)
        wyswietlanie_w_polowie(i, tablica_tekstow[i]);

    getch();
    clear();
    endwin();
}

void wyswietlanie_nazwy(void)
{
    const char linijka1[] = "#   #  ##  ##### #   #  ##    ###  ###   ##   ##  ###   ##  #   # #  #";
    const char linijka2[] = "##  # #  #    #  #   # #  #   #  # #  # #  # #    #  # #  # ## ## #  #";
    const char linijka3[] = "# # # ####   #   # # # ####   ###  ###  #  # # #  ###  #### # # # #  #";
    const char linijka4[] = "#  ## #  #  #    # # # #  #   #    # #  #  # #  # # #  #  # #   # #  #";
    const char linijka5[] = "#   # #  # #####  # #  #  #   #    #  #  ##   ##  #  # #  # #   #  ## ";

    wyswietlanie_w_polowie(1, linijka1);
    wyswietlanie_w_polowie(2, linijka2);
    wyswietlanie_w_polowie(3, linijka3);
    wyswietlanie_w_polowie(4, linijka4);
    wyswietlanie_w_polowie(5, linijka5);
}   

int obsluga_strzalek(int znak)
{
    if(znak == 65)
        return 1;
    if(znak == 66)
        return 2;
    if(znak == 68)
        return 3;
    if(znak == 67)
        return 4;
}
