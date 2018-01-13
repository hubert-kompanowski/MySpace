//Hubert Kompanowski  - suma srednia mediana i dominanta
#include <stdio.h>
#include <stdlib.h>

void sprawdzenie_rozmiaru_tablicy(int rozmiar_tablicy);
void liczenie_sumy(int* wskaznik_wartosci, int rozmiar);
void liczenie_domnanty(int* wskaznik_wartosci, int rozmiar);
void liczenie_sredniej(int* wskaznik_wartosci, int rozmiar);
void liczenie_mediany(int* wskaznik_wartosci, int rozmiar);
void sortowanie_tablicy(int* wskaznik_wartosci, int rozmiar);
int porownanie_liczb(const void * liczba_1, const void* liczba_2);

int main(void)
{
    printf("Podaj ilosc liczb do wczytania: ");

    int rozmiar_tablicy;
    scanf("%d",&rozmiar_tablicy);
    sprawdzenie_rozmiaru_tablicy(rozmiar_tablicy);

    printf("Podaj elementy tablicy: ");

    int tablica_wskaznikow[rozmiar_tablicy];
    for(int i = 0;i<rozmiar_tablicy;++i)
    {
        if(scanf("%d", &tablica_wskaznikow[i])==EOF)
        {
            if(i==0)
            {
                return 0;
            }
            rozmiar_tablicy = i;
            break;
        }
    }

    sortowanie_tablicy(tablica_wskaznikow, rozmiar_tablicy);

    liczenie_sumy(tablica_wskaznikow, rozmiar_tablicy);
    liczenie_domnanty(tablica_wskaznikow, rozmiar_tablicy);
    liczenie_sredniej(tablica_wskaznikow, rozmiar_tablicy);
    liczenie_mediany(tablica_wskaznikow, rozmiar_tablicy);

    return 0;
}

void sprawdzenie_rozmiaru_tablicy(int rozmiar_tablicy)
{
    if(rozmiar_tablicy < 1 || rozmiar_tablicy > 5000)
    {
        printf("Zbyt duża lub zbyt mała ilość liczb.\n");
        exit(0);
    }
}

void liczenie_sumy(int* wskaznik_wartosci, int rozmiar)
{
    int suma = 0;
    for(int i=0; i < rozmiar; ++i)
    {
        suma+=wskaznik_wartosci[i];
    }
    printf("Suma %d %o %X\n", suma,suma,suma);
}

void liczenie_domnanty(int* wskaznik_wartosci, int rozmiar)
{
    int dominanta = 0, liczba = 0;
    int licznik = 0, maksymalny_licznik = 0;

    for(int i = 0;i < rozmiar;++i)
    {
        if(liczba != wskaznik_wartosci[i])
        {
            liczba = wskaznik_wartosci[i];
            licznik = 1;
        }
        else
        {
            licznik++;
        }

        if(licznik > maksymalny_licznik)
        {
            maksymalny_licznik = licznik;
            dominanta = wskaznik_wartosci[i];
        }
    }
    printf("Dominanta %d %o %X\n", dominanta, dominanta, dominanta);    
}

void liczenie_sredniej(int* wskaznik_wartosci, int rozmiar)
{
    double srednia;
    int suma = 0;
    for(int i=0; i < rozmiar; ++i)
        suma+=wskaznik_wartosci[i];

    srednia = (double)suma / (double)rozmiar;
    if(suma % rozmiar == 0)
        printf("Srednia %d %o %X\n", (int)srednia, (int)srednia, (int)srednia);        
    else    
        printf("Srednia %g \n", srednia);
}

void liczenie_mediany(int* wskaznik_wartosci, int rozmiar)
{
    int czy_po_przecinku = 0;
    double mediana;
    if(rozmiar%2==0)
    {
        mediana = ((double)wskaznik_wartosci[rozmiar/2] + (double)wskaznik_wartosci[rozmiar/2-1])/2;
        czy_po_przecinku = 1;
    }
    else
    {
        mediana = wskaznik_wartosci[(rozmiar-1)/2];
    }
    
    if(czy_po_przecinku == 0)
        printf("Mediana %d %o %X\n", (int)mediana, (int)mediana, (int)mediana);
    else
        printf("Mediana %g\n", mediana);

}

void sortowanie_tablicy(int* wskaznik_wartosci, int rozmiar)
{
    qsort(wskaznik_wartosci,rozmiar,sizeof(int), porownanie_liczb);
}

int porownanie_liczb(const void * liczba_1, const void* liczba_2)
{
    if(*(int*)liczba_1 < *(int*)liczba_2) 
        return -1;
    else   
        if(*(int*)liczba_1 == *(int*)liczba_2) 
            return 0;
        else 
            return 1;
}
