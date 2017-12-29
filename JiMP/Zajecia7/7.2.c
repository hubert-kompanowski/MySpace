#include <stdio.h>

int scanfo_printf();

int main()
{
    int tablica[2];
    scanfo_printf("Podaj krotszy bok prostokata: %d teraz podaj dluzszy: %d", 2, tablica);
    
    printf("\nkrotrzy bok = %d, dluzszy bok = %d\n", tablica[0], tablica[1]);
}

int scanfo_printf(char* tekst, int x, int tablica[x])
{ 
    int i = 0;
    int j = 0;
    do
    {   
        if(tekst[i] != 37)  
            printf("%c", tekst[i]); 
        else
        {
            i++;
            if(tekst[i] == 100)
            {
                scanf("%d", &tablica[j]);
                j++;
            }
        }
        i++;   
    }
    while(tekst[i]);
}
