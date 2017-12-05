// Hubert Kompanowski - mnozenie macierzy

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generowanie_macierzy();
void wyswietlanie_macierzy();
void konwesja_z_2x2_na_2x2x2();
void mnozenie_macierzy();

int main (void)
{
    int macierz_pierwsza[2][2];  
    int macierz_druga[2][2];  
    int macierz_2x2x2[2][2][2];
    int macierz_2x2_przemnozona[2][2];

    srand(time(NULL));
    generowanie_macierzy(macierz_pierwsza);
    generowanie_macierzy(macierz_druga);
    
    printf("Macierz pierwsza:\n");
    wyswietlanie_macierzy(macierz_pierwsza);

    printf("\nMacierz druga:\n");
    wyswietlanie_macierzy(macierz_druga);

    konwesja_z_2x2_na_2x2x2(macierz_pierwsza, 0, macierz_2x2x2);
    konwesja_z_2x2_na_2x2x2(macierz_druga, 1, macierz_2x2x2);

    mnozenie_macierzy(macierz_2x2x2, macierz_2x2_przemnozona);

    printf("\nMacierz przemnozona:\n");
    wyswietlanie_macierzy(macierz_2x2_przemnozona);
}

void generowanie_macierzy(int tab[2][2])
{
    int i, j, x;

    for(i=0; i<2; i++)      
    {
        for(j=0; j<2; j++)
        {   
            x=rand()%200-100;
            tab[i][j]=x;
        }
    }
}

void wyswietlanie_macierzy (int tab[2][2])
{
    int i, j;

    for(i=0; i<2; i++)   
    {
        for(j=0; j<2; j++)
        {        
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void konwesja_z_2x2_na_2x2x2(int tab2[2][2], int numer, int tab3[2][2][2])
{
    int i, j;

    for(i=0; i<2; i++)      
    {
        for(j=0; j<2; j++)
        {   
            tab3[numer][i][j]=tab2[i][j];
        }
    }
}

void mnozenie_macierzy(int tab[2][2][2], int tab_p[2][2])
{
        int i, j, x;

    for(i=0; i<2; i++)      
    {
        for(j=0; j<2; j++)
        {   
            if (1-i+j)
            {
                x=0;
            }
            else x=1;
            tab_p[i][j]= tab[0][j][0] * tab[1][i*j][x] + tab[0][j][1] * tab[1][1][i];       
        }
    }
}
