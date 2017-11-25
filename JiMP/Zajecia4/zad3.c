//Hubert Kompanowski - Implementacja zagadki z waga i kulkami

#include <stdio.h> 
    
int main (void)
{
    int a, b, c, d, e, f, g, h, i;
    printf("Przpyisz wartości kolejnym kulkom\n");
    printf("Daj 8 jedynek a jednej kulce daj dwojke\n");
    printf("kazda wartosc zatwierdz wciskajac Enterem \n");
    scanf("%d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d",&a, &b, &c, &d, &e, &f, &g, &h, &i);
    
    if (a+b+c > d+e+f)
    {
        if (a > b) 
        {
            printf("kulka numer 1\n");
        }
        else if (a < b)
        {
            printf("kulka numer 2\n");
        }
        else printf("kulka numer 3\n");
    }
    else if (a+b+c < d+e+f)
    {
        if (d > f)
        {   
            printf("kulka numer 4\n");
        }
        else if (d < f)
        {
            printf("kulka numer 6\n");
        }
        else printf("kulka numer 5\n");
    }
    else
    {
        if (g > h)
        {
            printf("kulka numer 7\n");
        }
        else if (g < h)
        {
            printf("kulka numer 8\n");
        }
        else printf("kulka numer 9\n");
    }
        
}
