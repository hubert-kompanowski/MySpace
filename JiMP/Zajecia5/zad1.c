//Hubert Kompanowski - Porownywanie godzin

#include <stdio.h>

int porownanie_godzin();

int main(void)
{
    int godzina1[1], godzina2[1];
    printf("Podaj pierwsza godzine w formacie HHMM   ");
    scanf("%d",&godzina1[0]);
    printf("Podaj druga godzine w formacie HHMM   ");
    scanf("%d",&godzina2[0]);

    printf("%d\n", porownanie_godzin(godzina1,godzina2));
    
}

int porownanie_godzin(int tab1[], int tab2[])
{   

    if ((tab1[0]/100 > 24) || (tab2[0]/100 > 24) || (tab1[0]%100 >= 60) || (tab2[0]%100 >=60) )
    {
        printf("Nieprawidłowa godzina\n");
        return -101;
    }

    if (tab1[0] > tab2[0])
    {
        return 1;
    }
    else if (tab1[0] < tab2[0])
    {
        return -1;
    }
    else return 0;  

     
}   
