#include "menu.h"
#include "wyswietlanie.h"
#include <stdio.h>
#include <ncurses.h>

int menu(const int ilosc_opcji, char* tablica_opcji[ilosc_opcji + 1])
{
    initscr();
    noecho();
    tablica_opcji[ilosc_opcji] = "Wyjscie";

    int znak = 0, strzalka, ktory = 1;
    const short int min_wybor = 1;
    const short int max_wybor = ilosc_opcji+1;
    const int znak_specjalny[2] = {27, 91};
    const int enter = 10;

    do
    {  
        wyswietlanie_nazwy();

        if(znak == znak_specjalny[0])
        {
            znak = getch();            
            if(znak == znak_specjalny[1]) 
            {
                znak = getch();
                strzalka = obsluga_strzalek(znak);
            }
        }

        if(strzalka == 1 && ktory != min_wybor)
            ktory--;
        if(strzalka == 2 && ktory != max_wybor)
            ktory++;

        strzalka = 0;

        if(znak == enter)
        {
            if(ktory == ilosc_opcji+1)
                return 0;
            tablica_opcji = NULL;
            return ktory;            
        }

        for(int i=0; i<=ilosc_opcji; i++)
        {
            if(ktory == i+1)
                attron( A_REVERSE );

            wyswietlanie_w_polowie(7+2*i, tablica_opcji[i]);
            attroff( A_REVERSE );
        }

        znak = getch();
        clear();
    
    } while( ktory != ilosc_opcji+2 || znak != enter );
    
    clear();
    endwin();
    return 0;
}

