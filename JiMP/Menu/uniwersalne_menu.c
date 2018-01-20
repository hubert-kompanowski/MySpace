#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "wyswietlanie.h"

void instrukcje_opcji_1(void);
void instrukcje_opcji_2(void);
void instrukcje_opcji_3(void);
void instrukcje_opcji_4(void);

int main(void)
{
    initscr();
    int wybor_menu;

    int rozmiar_wstepu = 5;
    char* tablica_wstepu[] = {"**** Nazwa programu ****", "poczatek!",
                      "wstep", "rozpoczecie", "start"};
    wyswietlanie_informacji(rozmiar_wstepu, tablica_wstepu);

    int rozmiar_zakonczenia = 3;

    char* tablica_opcji_2[] = {"Informacje", "wyswietlone po wybraniu", "drugiej opcji"};
    char* tablica_zakonczenia[] = {"*** KONIEC PROGRAMU ***", "dziekuje", "pozdrawiam"};

    int ilosc_opcji = 4;
    char* opcje_w_menu[] = {"Opcja 1", "Opcja 2", "Opcja 3", "Opcja 4"};
    while(TRUE)
    {
        wybor_menu = menu(ilosc_opcji, opcje_w_menu);
        
        switch(wybor_menu)
        {
            case 0:
                clear();
                wyswietlanie_informacji(rozmiar_zakonczenia, tablica_zakonczenia);
                return 0;
            case 1:
                instrukcje_opcji_1();
                break;
            case 2:
                instrukcje_opcji_2();
                break;
            case 3:
                instrukcje_opcji_3();
                break;
            case 4:
                instrukcje_opcji_4();
                break;
        }       
    }
}   

void instrukcje_opcji_1(void)
{
    clear();
    int rozmiar_opcji_1 = 4;
    char* tablica_opcji_1[] = {"Informacje", "wyswietlone po", "wybraniu", "pierwszej opcji"};
    wyswietlanie_informacji(rozmiar_opcji_1, tablica_opcji_1);

    //Tutaj należy podać co program ma robić po wybraniu tej opcji
}

void instrukcje_opcji_2(void)
{
    clear();
    int rozmiar_opcji_2 = 3;
    char* tablica_opcji_2[] = {"Informacje", "wyswietlone po wybraniu", "drugiej opcji"};
    wyswietlanie_informacji(rozmiar_opcji_2, tablica_opcji_2);

    //Tutaj należy podać co program ma robić po wybraniu tej opcji
}

void instrukcje_opcji_3(void)
{
    clear();
    int rozmiar_opcji_3 = 3;
    char* tablica_opcji_3[] = {"Informacje", "wyswietlone po wybraniu", "trzeciej opcji"};
    wyswietlanie_informacji(rozmiar_opcji_3, tablica_opcji_3);

    //Tutaj należy podać co program ma robić po wybraniu tej opcji
}

void instrukcje_opcji_4(void)
{
    clear();
    int rozmiar_opcji_4 = 3;
    char* tablica_opcji_4[] = {"Informacje", "wyswietlone po wybraniu", "czwartej opcji"};
    wyswietlanie_informacji(rozmiar_opcji_4, tablica_opcji_4);

    //Tutaj należy podać co program ma robić po wybraniu tej opcji
}
