//Hubert Kompanowski - wyznacznik macierzy

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generowanie_macierzy();
void wyswietlanie_macierzy();
void wyznacznik_macierzy(); 

int main(void)
{
    int macierz[3][3];
    srand(time(NULL));
    generowanie_macierzy(3, macierz);
    wyswietlanie_macierzy(3, macierz);
    wyznacznik_macierzy(3, macierz);
}

void generowanie_macierzy(int n, int tab[n][n])
{
    int i, j, x;

    for(i=0; i<3; i++)      
    {
        for(j=0; j<3; j++)
        {   
            x=rand()%10;
            tab[i][j]=x;
        }
    }
}

void wyswietlanie_macierzy(int n, int tab[n][n])
{
    int h, k;
    printf("Wylosowana macierz:\n");

    for(h=0; h<3; h++)   
    {
        for(k=0; k<3; k++)
        {        
            printf("%d ",tab[h][k]);
        }
        printf("\n");
    }
}

void wyznacznik_macierzy(int n, int tab[n][n])
{
    int w;
    printf("Wyznacznik macierzy:\n");
    w = tab[0][0]*tab[1][1]*tab[2][2] + tab[1][0]*tab[2][1]*tab[0][2] + tab[2][0]*tab[0][1]*tab[1][2] - tab[1][0]*tab[0][1]*tab[2][2] - tab[0][0]*tab[2][1]*tab[1][2] - tab[2][0]*tab[1][1]*tab[0][2];
    printf("%d\n", w);
}
