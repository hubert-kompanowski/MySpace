// Hubert Kompanowski - Wskaznik na tablice

#include <stdio.h>

double funkcja();

int main(void)
{
    double srednia_wazona;
    int tablica[10] = {4,5,7,2,4,9,2,4,6,7};
    int *poczatek = tablica;
    int *koniec = &tablica[10];

    srednia_wazona = funkcja(poczatek, koniec); 
    printf("srednia wazona: %g\n",srednia_wazona); 
}

double funkcja(int *wsk1, int *wsk2)
{
    int i = 0;
    double srednia_wazona;
    double suma_wag = 0.0;
    double suma_wazona = 0.0;
    while(wsk1+i != wsk2)
    {   
        suma_wag += i;
        suma_wazona += *(wsk1+i) * i;    
        i++;
    }
    srednia_wazona = suma_wazona / suma_wag;

    return srednia_wazona;
}

