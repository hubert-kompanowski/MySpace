// Hubert Kompanowski 

#include <stdio.h>

void sortowanie_babelkowe();
void wyswietlanie_tablicy_A();
void wyswietlanie_tablicy_B();

int main()
{
    int tablica[10] = {3, 5, 1, 7, 2, 8 ,9 ,4, 6, 0};
    int* tablica_wskaznikow[10];

    for(int j=0; j<=9; j++)
        tablica_wskaznikow[j] = &tablica[j];

    printf("Przed sortowaniem:\n");
    wyswietlanie_tablicy_A(10, tablica);
    wyswietlanie_tablicy_B(10, tablica_wskaznikow);

    sortowanie_babelkowe(10, tablica_wskaznikow);
    
    printf("\nPo sortowaniu:\n");
    wyswietlanie_tablicy_A(10, tablica);
    wyswietlanie_tablicy_B(10, tablica_wskaznikow);
}

void sortowanie_babelkowe(int m, int* tablica[m])
{
    int* schowek;
    int zamiana;
    do
    {
        zamiana = 0;
        for(int i=0; i<m-1; i++)
        {
            if(*tablica[i]>*tablica[i+1])
            {
                zamiana = zamiana+1;
                schowek = tablica[i];
                tablica[i] = tablica[i+1];
                tablica[i+1] = schowek;
            }
        }
    }
    while(zamiana!=0);
}

void wyswietlanie_tablicy_A(int x, int tablica[x])
{
    printf("Tablica A:\n[");
    for(int j=0; j<=x-1; j++)
    {
        printf("%d, ", tablica[j]);
    }
    printf("\b\b]\n");
}

void wyswietlanie_tablicy_B(int x, int* tablica[x])
{
    printf("Tablica B (wartosci wskazywane przez wskazniki):\n[");
    for(int j=0; j<=x-1; j++)
    {
        printf("%d, ", *tablica[j]);
    }
    printf("\b\b]\n");
}
