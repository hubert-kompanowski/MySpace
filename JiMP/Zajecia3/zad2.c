//Hubert Kompawnowski - Przeliczenie temperatury Celciusz <--> Fahrenheit

#include <stdio.h>

void Celciusz_na_Fahrentheita();
void Fahrentheit_na_Celciusza();

int main(void)
{
    int zmienna;
    printf ("\nJaki przelicznik wybierasz?\n");
    printf ("1. Z Celciusza na Fahrentheita\n");
    printf ("2. Z Fahrentheita na Celciusza\n");
    scanf("%d",&zmienna);
    
    switch (zmienna)
    {
        case 1:
            Celciusz_na_Fahrentheita();
            break;
        case 2:
            Fahrentheit_na_Celciusza();
            break;
        default:
            printf("Nie ma takiego numeru");
            break;
    }
}   

void Celciusz_na_Fahrentheita()
{
    double temp_celciusz, temp_fahrenheit;
    printf("Podaj liczbe stopni Celciusza: ");
    scanf("%lf", &temp_celciusz);
    temp_fahrenheit = temp_celciusz * 1.8 + 32;
    printf("%g stopni Celciusza to %g stopni Fahrentheita\n", temp_celciusz, temp_fahrenheit);
}

void Fahrentheit_na_Celciusza()
{
    double temp_celciusz, temp_fahrenheit;
    printf("Podaj liczbe stopni Fahrentheita: ");
    scanf("%lf", &temp_fahrenheit);
    temp_celciusz = (temp_fahrenheit - 32) / 1.8;
    printf("%g stopni Fahrentheita to %g stopni Celciusza\n", temp_fahrenheit, temp_celciusz);
}
