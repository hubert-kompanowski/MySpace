//Hubert Kompanowski - Pierwiastki rowniania kwadratowego 
//Załaczona biblioteka math.h do obliczenia pierwiastka

#include <stdio.h>
#include <math.h>

int liczenie_pierwiastkow();

int main (void)
{
    printf("Podaj a, b i c z rownania ax^2 + bx + c = 0 \n");
    liczenie_pierwiastkow();
}

int liczenie_pierwiastkow()
{
    double a, b, c, delta, x_0, x_1, x_2;
    scanf("%lf \n%lf \n%lf", &a, &b, &c);
    delta = b*b - 4*a*c;
    
    if(a!=0)
    {
        if(delta > 0)
        {
            x_1 = (-b + sqrt(delta)) / (2*a);
            x_2 = (-b - sqrt(delta)) / (2*a);
            printf("Pierwiastkami rownania sa %g oraz %g\n", x_1, x_2);
        }
        else if(!delta)
        {
            x_0 = -b / (2*a);
            printf("Pierwiastkiem rownania jest %g\n", x_0);
        }
        else 
        {
            printf("Brak pierwiastkow rownania\n");
        }
    }
    else
    {
        printf("'a' nie moze byc rowne zero. Podaj ponownie:\n");
        return liczenie_pierwiastkow();
    }
    return 0;
}

