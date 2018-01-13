// Hubert Kompanowski - sortowanie liczb z pliku > do pliku innego

#include <stdio.h>
#include <stdlib.h>

int operacje_na_pliku_wejsciowym(char* nazwa_pliku, int* liczby, int argc, char* argv[]);
void wypisywanie_liczb(int* liczby,int ilosc_liczb);
void zapisywanie_liczb_w_pliku(char* nazwa_pliku, int* liczby, int ilosc_liczb);
int porownywanie_liczb(const void * liczba_1, const void * liczba_2);

int main(int argc, char* argv[])
{
    if(argc != 2 && argc != 3)
    {
        printf("Należy podać jeden lub dwa argumenty:  ./a.out plik_z_liczbami [plik_do_zapisu] \n");
        return -1;
    }

    int* liczby = NULL;

    operacje_na_pliku_wejsciowym(argv[1], liczby, argc, argv);
}

int operacje_na_pliku_wejsciowym(char* nazwa_pliku, int* liczby, int argc, char* argv[])
{
    FILE *plik_wejsciowy = fopen(nazwa_pliku, "r");
    int liczba = 0, licznik = 0;
    
    if(plik_wejsciowy == NULL)
    {
        printf("Podano nieprawidlowy plik\n");
        exit(-1);
    }

    while(fscanf(plik_wejsciowy, "%d", &liczba) != EOF)
    {
        liczby = (int*)realloc(liczby, sizeof(int)*(licznik+1));
        *(liczby+licznik) = liczba;
        licznik++;
    }
    
    fclose(plik_wejsciowy);

    qsort(liczby, licznik, sizeof(int), porownywanie_liczb);

    if(argc == 2)
        wypisywanie_liczb(liczby, licznik);
    else
        zapisywanie_liczb_w_pliku(argv[2], liczby, licznik);     
}   

void wypisywanie_liczb(int* liczby,int ilosc_liczb)
{
    for(int x = 0; x < ilosc_liczb; x++)
        printf("%d\n",*(liczby+x));
}

void zapisywanie_liczb_w_pliku(char* nazwa_pliku, int* liczby, int ilosc_liczb)
{
    FILE *plik_do_zapisu = fopen(nazwa_pliku, "w");
    
    for(int x = 0; x < ilosc_liczb; x++)
        fprintf(plik_do_zapisu,"%d\n",liczby[x]);

    fclose(plik_do_zapisu);
}   

int porownywanie_liczb(const void * liczba_1, const void* liczba_2)
{
    if(*(int*)liczba_1 < *(int*)liczba_2) 
        return -1;
    else   
        if(*(int*)liczba_1 == *(int*)liczba_2) 
            return 0;
        else 
            return 1;
}

