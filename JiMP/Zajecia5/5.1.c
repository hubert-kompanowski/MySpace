//Hubert Kompanowski - Porownywanie godzin

#include <stdio.h>

void sprawdzenie_poprawnosci(int wielkosc_tablicy, int godzina[wielkosc_tablicy]);
void tworzenie_tablicy_z_godzina(int wielkosc_tablicy, int godzina[wielkosc_tablicy]);
int porownanie_dwoch(int wielkosc_tablicy, int godzina1[wielkosc_tablicy], int godzina2[wielkosc_tablicy]);

int main(void)
{
    int godzina_1[3], godzina_2[3];
    tworzenie_tablicy_z_godzina(3, godzina_1);
    tworzenie_tablicy_z_godzina(3, godzina_2);
    int x = porownanie_dwoch(3, godzina_1, godzina_2);

    switch(x)
    {
        case(0):
            printf("Obie godziny sa sobie rowne. \n");
            break;
        case(1):
            printf ("Pierwsza godzina jest wieksza.\n");
            break;
        case(-1):
            printf ("Druga godzina jest wieksza\n");
            break;
    }
}

void sprawdzenie_poprawnosci(int wielkosc_tablicy, int godzina[wielkosc_tablicy])
{
    while(godzina[0]<0 || godzina[0]>24)
    {
        printf("Podales zla godzine, wartosc musi zawierac sie miedzy 0 i 24, wpisz jeszcze raz \n");
        scanf("%d", &godzina[0]);
    }
    while(godzina[1]<0 || godzina[1]>60)
    {
        printf("Podales zle minuty, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
        scanf("%d", &godzina[1]);
    }
    while(godzina[2]<0 || godzina[2]>60)
    {
        printf("Podales zle sekundy, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
        scanf("%d", &godzina[2]);
    }
}

void tworzenie_tablicy_z_godzina(int wielkosc_tablicy, int godzina[wielkosc_tablicy])
{
    godzina[0] = godzina[1] = godzina[2] = 0;
    printf("Wpisz po kolei godzine, minute i sekunde\n");
    printf("godziny = ");
    scanf("%d", &godzina[0]);
    sprawdzenie_poprawnosci(wielkosc_tablicy, godzina);
    printf("minuty = ");
    scanf("%d", &godzina[1]);
    sprawdzenie_poprawnosci(wielkosc_tablicy, godzina);    
    printf("sekundy = ");
    scanf("%d", &godzina[2]);
    sprawdzenie_poprawnosci(wielkosc_tablicy, godzina);
}

int porownanie_dwoch(int wielkosc_tablicy, int godzina1[wielkosc_tablicy], int godzina2[wielkosc_tablicy])
{
    for(int i=0; i<wielkosc_tablicy; i++)
    {
        if(godzina1[i] > godzina2[i])
            return 1;
        else 
            if(godzina1[i] < godzina2[i])
                return -1;
    }       
    return 0;
}

