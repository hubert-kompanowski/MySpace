//

#include <stdio.h>     
#include <stdarg.h>    

void scanfo_printf (int n, ...)
{
    int i;
    double val;
    char* tekst;

    va_list vl;
    va_start(vl,n);
    for (i=0;i<n;i++)
    {
        val=va_arg(vl,double);
        tekst=va_arg(vl,char*);
        printf("%s ", tekst);
        printf("%lf ",val);
    }
    va_end(vl);
    printf ("\n");
}

int main (void)
{
    double zmienna1 = 3.14159;
    double zmienna2 = 2.71828;
    double zmienna3 = 1.41421;
    scanfo_printf (3, "tekst", zmienna1, "tekst", zmienna2, "tekst", zmienna3);
}


