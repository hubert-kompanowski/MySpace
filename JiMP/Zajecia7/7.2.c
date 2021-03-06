#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void scanfo_printf(char* tekst, int ilosc_argumentow, int tablica[ilosc_argumentow]);
void scanfo_printf_2_0(char* tekst, ...);

int main()
{
    int ilosc_argumentow = 2;
    int tablica[ilosc_argumentow];
    scanfo_printf("Podaj krotszy bok prostokata: %d teraz podaj dluzszy: %d", ilosc_argumentow, tablica);
    printf("\nkrotszy bok = %d, dluzszy bok = %d\n\n\n  ****  Wersja z '...':  ****\n", tablica[0], tablica[1]);
     
    int bok_1;
    int bok_2;
    scanfo_printf_2_0("Podaj krotszy bok prostokata: %d teraz podaj dluzszy: %d", &bok_1, &bok_2);
    printf("\nkrotszy bok = %d, dluzszy bok = %d\n", bok_1, bok_2);
}

void scanfo_printf(char* const tekst, int ilosc_argumentow, int tablica[ilosc_argumentow])
{ 
    int j = 0;
    for(int i = 0; tekst[i]; i++)
    {   
        if(tekst[i] != '%')  
            printf("%c", tekst[i]); 
        else
        {
            i++;
            if(tekst[i] == 'd')
            {
                scanf("%d", &tablica[j]);
                j++;
            }
        }
    }
}

void scanfo_printf_2_0(char* const tekst, ...)
{
    va_list element;
    va_start(element, tekst);
    int* liczba;

    int j = 0;
    for(int i = 0; tekst[i]; i++)
    {   
        if(tekst[i] != '%')  
            printf("%c", tekst[i]); 
        else
        {
            i++;
            if(tekst[i] == 'd')
            {
                liczba = va_arg(element, int*);
                scanf("%d", liczba);
                j++;
            }
        }   
    }

    va_end (element);
}

