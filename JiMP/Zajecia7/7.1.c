// Hubert Kompanowski - Wskaznik na tablice

#include <stdio.h>
#include <string.h>

double liczenie_sredniej(int const *wsk1, int const*wsk2);

int main(void)
{
    const int tablica[] = {4,5,7,2,4,9,2,4,6,7};
    int const *poczatek = tablica;
    int const *koniec = &tablica[sizeof(tablica) / sizeof(tablica[0])];

    double srednia_wazona = liczenie_sredniej(poczatek, koniec); 
    printf("srednia wazona: %g\n",srednia_wazona); 
}

double liczenie_sredniej(int const *wsk1, int const*wsk2)
{
    int i = 0;
    double suma_wag = 0.0;
    double suma_wazona = 0.0;
    while(wsk1+i != wsk2)
    {   
        suma_wag += i;
        suma_wazona += *(wsk1+i) * i;    
        i++;
    }
    double srednia_wazona = suma_wazona / suma_wag;

    return srednia_wazona;
}

