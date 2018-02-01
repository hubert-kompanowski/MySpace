// Hubert Kompanowski - tablica char znaki i ich suma
#include <stdio.h>
#include <string.h>

int wypisywanie_elementow(const void* dane, int rozmiar_danych);

int main(void)
{
    int suma_znakow;

    char* const napis = "acb xyz";
    suma_znakow = wypisywanie_elementow(napis, strlen(napis));
    printf("suma = %d\n\n", suma_znakow);

    char* const liczba = "123456";
    suma_znakow = wypisywanie_elementow(liczba, strlen(liczba));
    printf("suma = %d\n\n", suma_znakow);

    const char znak = 't';
    suma_znakow = wypisywanie_elementow(&znak, 1);
    printf("suma = %d\n\n", suma_znakow);

    const int cyfra = 7;
    suma_znakow = wypisywanie_elementow(&cyfra, 1);
    printf("suma = %d\n\n", suma_znakow);
}

int wypisywanie_elementow(const void* dane, int rozmiar_danych)
{
    char tablica_danych[100] = {0};
    memcpy(tablica_danych, dane, rozmiar_danych);

    int suma_znakow = 0;
    char znak;
    for(int indeks = 0; indeks < rozmiar_danych; ++indeks)
    {
        znak = (char)tablica_danych[indeks];
        printf("%d ",znak);
        suma_znakow += (char)tablica_danych[indeks];
    }
    printf("\n");
    return suma_znakow;
}
