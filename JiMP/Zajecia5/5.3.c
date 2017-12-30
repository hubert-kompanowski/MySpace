// Hubert Kompanowski - mnozenie macierzy

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generowanie_macierzy(int rozmiar, int tab[rozmiar][rozmiar]);
void wyswietlanie_macierzy(int rozmiar, int tab[rozmiar][rozmiar]);
void konwesja_z_2x2_na_2x2x2(int rozmiar, int tab2[rozmiar][rozmiar], int numer, int tab3[rozmiar][rozmiar][rozmiar]);
void mnozenie_macierzy(int rozmiar, int tab[rozmiar][rozmiar][rozmiar], int tab_p[rozmiar][rozmiar]);

int main (void)
{
    int rozmiar_macierzy = 2;
    int macierz_pierwsza[rozmiar_macierzy][rozmiar_macierzy];  
    int macierz_druga[rozmiar_macierzy][rozmiar_macierzy];  

    srand(time(NULL));
    generowanie_macierzy(rozmiar_macierzy, macierz_pierwsza);
    generowanie_macierzy(rozmiar_macierzy, macierz_druga);
    
    printf("Macierz pierwsza:\n");
    wyswietlanie_macierzy(rozmiar_macierzy, macierz_pierwsza);

    printf("\nMacierz druga:\n");
    wyswietlanie_macierzy(rozmiar_macierzy, macierz_druga);
  
    int macierz_2x2x2[rozmiar_macierzy][rozmiar_macierzy][rozmiar_macierzy];
    konwesja_z_2x2_na_2x2x2(rozmiar_macierzy, macierz_pierwsza, 0, macierz_2x2x2);
    konwesja_z_2x2_na_2x2x2(rozmiar_macierzy, macierz_druga, 1, macierz_2x2x2);

    int macierz_2x2_przemnozona[rozmiar_macierzy][rozmiar_macierzy];
    mnozenie_macierzy(rozmiar_macierzy, macierz_2x2x2, macierz_2x2_przemnozona);

    printf("\nMacierz przemnozona:\n");
    wyswietlanie_macierzy(2, macierz_2x2_przemnozona);
}

void generowanie_macierzy(int rozmiar, int tab[rozmiar][rozmiar])
{
    int i, j, x;

    for(i=0; i<rozmiar; i++)      
    {
        for(j=0; j<rozmiar; j++)
        {   
            x=rand()%200-100;
            tab[i][j]=x;
        }
    }
}

void wyswietlanie_macierzy(int rozmiar, int tab[rozmiar][rozmiar])
{
    int i, j;

    for(i=0; i<rozmiar; i++)   
    {
        for(j=0; j<rozmiar; j++)
        {        
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void konwesja_z_2x2_na_2x2x2(int rozmiar, int tab2[rozmiar][rozmiar], int numer, int tab3[rozmiar][rozmiar][rozmiar])
{
    int i, j;

    for(i=0; i<rozmiar; i++)      
    {
        for(j=0; j<rozmiar; j++)
        {   
            tab3[numer][i][j]=tab2[i][j];
        }
    }
}

void mnozenie_macierzy(int rozmiar, int tab[rozmiar][rozmiar][rozmiar], int tab_p[rozmiar][rozmiar])
{
        int i, j, x;

    for(i=0; i<rozmiar; i++)      
    {
        for(j=0; j<rozmiar; j++)
        {   
            if (1-i+j)
                x=0;
            else
                x=1;

            tab_p[i][j]= tab[0][j][0] * tab[1][i*j][x] + tab[0][j][1] * tab[1][1][i];       
        }
    }
}
