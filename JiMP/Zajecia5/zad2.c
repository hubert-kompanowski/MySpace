//Hubert Kompanowski - wyznacznik macierzy

#include <stdio.h>
#include <stdlib.h>

void Generowanie_macierzy (int tab[3][3]);
void Wyswietlanie_macierzy (int tab[3][3]);

int main(void)
{

    printf("Wylosowana macierz:\n");

    for(h=0; h<3; h++)   
    {
        for(k=0; k<3; k++)
        {        
            printf("%d ",tab[h][k]);
        }
        printf("\n");
    }
    
    printf("Wyznacznik macierzy:\n");
    w = tab[0][0]*tab[1][1]*tab[2][2] + tab[1][0]*tab[2][1]*tab[0][2] + tab[2][0]*tab[0][1]*tab[1][2] - tab[1][0]*tab[0][1]*tab[2][2] - tab[0][0]*tab[2][1]*tab[1][2] - tab[2][0]*tab[1][1]*tab[0][2];

    printf("%d\n", w);
}




void Generowanie_macierzy (int tab[3][3])
{
    int tab[3][3]; 
    int i,j,h,k,x,w;

    for(i=0; i<3; i++)      
    {
        for(j=0; j<3; j++)
        {   
            x=rand()%10;
            tab[i][j]=x;
        }
    }
}


void Wyswietlanie_macierzy (int tab[3][3])
{
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

