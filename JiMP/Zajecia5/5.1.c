//Hubert Kompanowski - Porownywanie godzin

#include <stdio.h>

void sprawdzenie_poprawnosci (int godzina [3]);
int tworzenie_tablicy_z_godzina (int godzina[3]);
int porownanie_dwoch (int godzinastart[3], int godzinastop[3]);

int main (void)
{
    int godzina_1[3], godzina_2[3];
    tworzenie_tablicy_z_godzina (godzina_1);
    tworzenie_tablicy_z_godzina (godzina_2);
    int x = porownanie_dwoch(godzina_1, godzina_2);

    switch (x)
    {
        case (0):
            printf("Obie godziny sa sobie rowne. \n");
            break;
        case (1):
            printf ("Pierwsza godzina jest wieksza.\n");
            break;
        case (-1):
            printf ("Druga godzina jest wieksza\n");
            break;
    }
}

void sprawdzenie_poprawnosci (int godzina [3])
{
    while (godzina[0]<0||godzina[0]>24)
    {
        printf ("Podales zla godzine, wartosc musi zawierac sie miedzy 0 i 24, wpisz jeszcze raz \n");
        scanf ("%d", &godzina[0]);
    }
    while (godzina [1]<0||godzina[1]>60)
    {
        printf ("Podales zle minuty, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
        scanf ("%d", &godzina[1]);
    }
    while (godzina [2]<0||godzina[2]>60)
    {
        printf ("Podales zle sekundy, wartosc musi zawierac sie miedzy 0 i 60, wpisz jeszcze raz \n");
        scanf ("%d", &godzina[2]);
    }
}

int tworzenie_tablicy_z_godzina (int godzina[3])
{
    godzina[0] = 0;   godzina[1] = 0;   godzina[2] = 0;
    printf("Wpisz po kolei godzine, minute i sekunde\n");
    printf ("godziny = ");
    scanf ("%d", &godzina[0]);
    sprawdzenie_poprawnosci(godzina);
    printf ("minuty = ");
    scanf ("%d", &godzina[1]);
    sprawdzenie_poprawnosci(godzina);    
    printf ("sekundy = ");
    scanf ("%d", &godzina[2]);
    sprawdzenie_poprawnosci(godzina);
    return godzina[3];
}

int porownanie_dwoch (int godzina1[3], int godzina2[3])
{
    if (godzina1[0] > godzina2[0])
    {
        return 1;
    }
    else if (godzina1[0] < godzina2[0])
    {
        return -1;
    }
    else if (godzina1[1] > godzina2[1])
    {
        return 1;
    }
    else if (godzina1[1] < godzina2[1])
    {
        return -1;
    }
    else if (godzina1[2] > godzina2[2])
    {
        return 1;
    }
    else if (godzina1[2] < godzina2[2])
    {
        return -1;
    }   
    else return 0;
}

