//Hubert Kompanowski - Pierwiastki rowniania kwadratowego 
//Załaczona biblioteka math.h do obliczenia pierwiastka

#include <stdio.h>
#include <math.h>

int main (void)
{
    double a, b, c, delta, x_0, x_1, x_2;
    printf("Podaj a, b i c z rownania ax^2 + bx + c = 0 \n");
    scanf("%lf \n%lf \n%lf", &a, &b, &c);
    delta = b*b - 4*a*c;

    if(delta > 0)
    {
        x_1 = (-b + sqrt(delta)) / (2*a);
        x_2 = (-b - sqrt(delta)) / (2*a);
        printf("Pierwiastkami rownania sa %g oraz %g\n", x_1, x_2);
    }
    else if(!delta)
    {
        x_0 = -b / (2*a);
        printf("Pierwiastkiem rownania jest %g", x_0);
    }
    else 
    {
        printf("Brak pierwiastkow rownania");
    }
    
}

