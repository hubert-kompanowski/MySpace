#include "wyswietlanie.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>


void wyswietlanie_w_polowie(int wiersz, const char* tekst)
{
    int kolumny = 0, rzedy = 0;
    getmaxyx(stdscr, rzedy, kolumny);
    mvprintw(wiersz, (kolumny / 2) - (strlen(tekst) / 2), tekst);
}

void wyswietlanie_informacji(const int rozmiar, char* const tablica_tekstow[rozmiar])
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
    const int dol = 65, gora = 66, prawa = 67, lewa = 68;
    if(znak == dol)
        return 1;
    if(znak == gora)
        return 2;
    if(znak == prawa)
        return 3;
    if(znak == lewa)
        return 4;
}
