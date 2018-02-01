// Hubert Kompanowski - generowanie losowych liczb do pliku  SKLADNIA: ./a.out  nazwa_pliku  ilosc_liczb

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void losowanie_liczb(int ilosc, int tablica[ilosc]);
void zapisywanie_w_pliku(char* nazwa_pliku, int ilosc, int* tablica_liczb_losowych);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    const int ilosc = atoi(argv[2]);

    if(argc != 3)
    {
        printf("Należy podać 2 argumenty (nazwe pliku oraz ilosc liczb)\n");
        return -2;
    }
    
    if(ilosc > 1000000 || ilosc <=0)
    {
        printf("Nieprawidlowo podana ilosc liczb musi byc [1,1000000]\n");
        return -1;
    }

    int tablica_liczb_losowych[ilosc];
    losowanie_liczb(ilosc, tablica_liczb_losowych);

    zapisywanie_w_pliku(argv[1], ilosc, tablica_liczb_losowych);
}

void losowanie_liczb(int ilosc, int tablica[ilosc])
{
    for(int i=0; i<ilosc; i++)
        tablica[i] = rand()%1000;
}   

void zapisywanie_w_pliku(char* nazwa_pliku, int ilosc, int* tablica_liczb_losowych)
{
    FILE* plik = fopen(nazwa_pliku, "w");
    if(plik != NULL)
        for(int x=0; x<ilosc; x++)
            fprintf(plik, "%d\n", tablica_liczb_losowych[x]);
    else
        printf("Blad otwarcia pliku");
    fclose(plik);
}
