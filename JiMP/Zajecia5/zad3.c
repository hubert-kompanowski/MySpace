//#### Niedokończone #####

#include <stdio.h>
#include <stdlib.h>

int losowanie_macierzy();

int main(void)
{
    int x = losowanie_macierzy();  
    printf("%d",x[1][1]);
    
}


int losowanie_macierzy(tab[2][2])
{
    int tab[2][2]; 
    int i,j,h,k,x;

    for(i=0; i<2; i++)      
    {
        for(j=0; j<2; j++)
        {   
            x=rand()%100;
            tab[i][j]=x;
        }
    }

    printf("Wylosowana macierz:\n");

    for(h=0; h<2; h++)   
    {
        for(k=0; k<2; k++)
        {        
            printf("%d ",tab[h][k]);
        }
        printf("\n");
    }
    return tab;
}
