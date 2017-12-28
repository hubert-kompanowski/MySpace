//Hubert Kompawnowski - Zamiana stopni na radiany

#include <stdio.h>

void stopnie_na_radiany();
void radiany_na_stopnie();

int main(void)
{
    int zmienna;
    printf ("\nJaki przelicznik wybierasz?\n");
    printf ("1. Z stopni na radiany\n");
    printf ("2. Z radianow na stopnie\n");
    scanf("%d",&zmienna);
    
    switch (zmienna)
    {
        case 1:
            stopnie_na_radiany();
            break;
        case 2:
            radiany_na_stopnie();
            break;
        default:
            printf("Nie ma takiego numeru");
            break;
    }
}

void stopnie_na_radiany()
{
    double stopnie, radiany;
    const double pi = 3.14159;
    printf("Podaj liczbe stopni: ");
    scanf("%lf", &stopnie);
    radiany = stopnie / 360 * 2 * pi;
    printf("%lf stopni to %lf radianow.\n", stopnie, radiany);
}

void radiany_na_stopnie()
{
    double stopnie, radiany;
    const double pi = 3.14159;
    printf("Podaj liczbe radianow: ");
    scanf("%lf", &radiany);
    stopnie = radiany * 360 /( 2 * pi);
    printf("%lf radianow to %lf stopnie.\n", radiany, stopnie);
}
