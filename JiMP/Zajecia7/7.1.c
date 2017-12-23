// Hubert Kompanowski - Wskaznik na tablice

#include <stdio.h>

double funkcja();

int main(void)
{
    double srednia_wazona;
    int tablica[10] = {4,5,7,2,4,9,2,4,6,8};
    int *poczatek = &tablica;

    srednia_wazona = funkcja(poczatek); 
    printf("srednia wazona: %g\n",srednia_wazona); 
}



double funkcja(int *wsk1)
{
    
    double srednia_wazona;
    double suma_wazona = 0.0;
    for (int i=0; i<=9; i++)
    {
        suma_wazona += *(wsk1+i) * i;    
    }

    srednia_wazona = suma_wazona / 10.0;

    return srednia_wazona;
}
    

