//Hubert Kompanowski - menu w switchu z funkcjami

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie_tablicy_10_liczb();
void wyswietlanie_tablicy();
void liczenie_sredniej_liczb_z_tablicy();
void liczenie_medianej_liczb_z_tablicy();
void wyswietlanie_min_elemntu();
void wyswietlanie_maks_elemntu();

int main(void)
{
    int tablica[9];
    
    while (1)
    {   
        int n = 7; 
        
        srand(time(NULL));
        printf("\n               Wybierz funkcje(podaj liczbe):\n               "
                "1.losowanie tablicy\n               2.wyswietlanie tablicy\n               "
                "3.liczenie sredniej\n               4.liczenie mediany\n               "
                "5.min element\n               6.maks element\n               "
                "7.wyjscie z petli\n");
        scanf("%d",&n);
        
        printf("\033[2J");   //Czyszczenie ekranu
        printf("\033[0;0f");
    
        switch(n)
        {
            case 1:
                losowanie_tablicy_10_liczb(9, tablica);
                break;
            case 2:
                wyswietlanie_tablicy(9, tablica);
                break;
            case 3:
                liczenie_sredniej_liczb_z_tablicy(9, tablica);
                break;
            case 4:
                liczenie_medianej_liczb_z_tablicy(9, tablica);
                break;
            case 5:
                wyswietlanie_min_elemntu(9, tablica);
                break;
            case 6:
                wyswietlanie_maks_elemntu(9, tablica);
                break;
            case 7:
                return 0;
            default:
                printf("Nie ma takiego numeru\n");             
                continue;
        }
    }
}

void losowanie_tablicy_10_liczb(int m, int tab[m])
{
    for(int x=0; x<=9; x++)
    {
        tab[x] = rand()%100;
    }
    printf("Wlosowano tablice.\n");
}

void wyswietlanie_tablicy(int m, int tab[m])
{
    printf("tablica = [");
    for (int x=0; x<=9; x++)
    {
        printf("%d, ",tab[x]);
    } 
    printf("\b]\n");
}

void liczenie_sredniej_liczb_z_tablicy(int m, int tab[m])
{
    double srednia;   
    double suma = 0;
    for (int x=0; x<=9; x++)
    {
        suma += tab[x];
    } 
    srednia = suma/10;
    printf("srednia = %g\n",srednia);
}

void liczenie_medianej_liczb_z_tablicy(int m, int tab[m])
{
    int schowek, zamiana;
    double mediana;
    do
    {
        zamiana = 0;
        for (int i=0; i<9; i++)
        {
            if (tab[i] > tab[i+1])
            {
                zamiana = zamiana + 1;
                schowek = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = schowek;
            }
        }
    }
    while(zamiana!=0);
    mediana = (tab[4] + tab[5])/2;
    printf("mediana = %g\n", mediana);
}

void wyswietlanie_min_elemntu(int m, int tab[m])
{
    int min=tab[0];
    for (int x=0; x<=9; x++)
    {
        if (tab[x] < min) 
            min = tab[x];
    } 
    printf("minimalny element = %d\n",min);
}

void wyswietlanie_maks_elemntu(int m, int tab[m])
{
    int maks=tab[0];
    for (int x=0; x<=9; x++)
    {
        if (tab[x] > maks) 
            maks = tab[x];
    } 
    printf("maksymalny element = %d\n",maks);
}

