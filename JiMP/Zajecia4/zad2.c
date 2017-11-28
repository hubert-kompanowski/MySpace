//Hubert Kompanowski - Zgadywanie liczby z przedziału [1,10]

#include <stdio.h>

void zgadywanie_liczby();
int zakres();

int main(void)
{
    int liczba_podana;
    int liczba;
    printf("Podaj liczbe z zakresu [1, 10]\n");
    scanf("%d", &liczba_podana);

    liczba = zakres (liczba_podana);
    zgadywanie_liczby (liczba);
}

int zakres (int liczba_podana)
{
    if (liczba_podana < 0)
    {
        liczba_podana = -liczba_podana;
    } 
    if (liczba_podana==0) liczba_podana =+ 1;

    if (liczba_podana > 10)
    {
        liczba_podana = liczba_podana % 10;
    }

    return liczba_podana;
}

void zgadywanie_liczby (int liczba)
{
    if (liczba >= 6)
    {
        if (liczba >=8)
        {
            if (liczba >=9)
            {
                if (liczba==9)
                {
                    printf("Twoja liczba to 9\n");
                }
                else printf("Twoja liczba to 10\n");
            }
            else printf("Twoja liczba to 8\n");
        }
        else if (liczba == 6)
        {
            printf("Twoja liczba to 6\n");
        }        
        else printf("Twoja liczba to 7\n");
    }
    else if (liczba >= 3)
    {
        if (liczba >= 4)
        {
            if (liczba == 4)
            {
            printf("Twoja liczba to 4\n");
            }
            else printf("Twoja liczba to 5\n");
        }
        else printf("Twoja liczba to 3\n");
    }
    else if (liczba == 1)
    {
        printf("Twoja liczba to 1\n");
    }
        else printf("Twoja liczba to 2\n");    
}
