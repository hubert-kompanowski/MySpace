// Hubert Kompanowski 

#include <stdio.h>

void sortowanie_babelkowe(int rozmiar, int* tablica[rozmiar]);
void wyswietlanie_tablicy_A(int rozmiar, int tablica[rozmiar]);
void wyswietlanie_tablicy_B(int rozmiar, int* tablica[rozmiar]);
void zamien(int *wskaznik_na_wartosc_1, int *wskaznik_na_wartosc_2);

int main()
{
    int tablica[] = {3, 5, 1, 7, 2, 8, 9, 4, 6, 0};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    int* tablica_wskaznikow[rozmiar];

    for(int j=0; j<=rozmiar-1; j++)
        tablica_wskaznikow[j] = &tablica[j];

    printf("Przed sortowaniem:\n");
    wyswietlanie_tablicy_A(rozmiar, tablica);
    wyswietlanie_tablicy_B(rozmiar, tablica_wskaznikow);

    sortowanie_babelkowe(rozmiar, tablica_wskaznikow);
    
    printf("\nPo sortowaniu:\n");
    wyswietlanie_tablicy_A(rozmiar, tablica);
    wyswietlanie_tablicy_B(rozmiar, tablica_wskaznikow);
}

void sortowanie_babelkowe(int rozmiar, int* tablica[rozmiar])
{
    int zamiana;
    do
    {
        zamiana = 0;
        for(int i=0; i<rozmiar-1; i++)
        {
            if(*tablica[i]>*tablica[i+1])
            {
                zamiana = zamiana+1;
                zamien(tablica[i], tablica[i+1]);
            }
        }
    }
    while(zamiana!=0);
}

void wyswietlanie_tablicy_A(int rozmiar, int tablica[rozmiar])
{
    printf("Tablica A:\n[");
    for(int j=0; j<=rozmiar-1; j++)
    {
        printf("%d, ", tablica[j]);
    }
    printf("\b\b]\n");
}

void wyswietlanie_tablicy_B(int rozmiar, int* tablica[rozmiar])
{
    printf("Tablica B (wartosci wskazywane przez wskazniki):\n[");
    for(int j=0; j<=rozmiar-1; j++)
    {
        printf("%d, ", *tablica[j]);
    }
    printf("\b\b]\n");
}

void zamien(int *wskaznik_na_wartosc_1, int *wskaznik_na_wartosc_2)
{
    int schowek = *wskaznik_na_wartosc_1;
    *wskaznik_na_wartosc_1 = *wskaznik_na_wartosc_2;
    *wskaznik_na_wartosc_2 = schowek;
}
