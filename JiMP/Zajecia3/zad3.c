//Hubert Kompawnowski - Zamiana stopni na radiany

#include <stdio.h>

int main(void)
{
    double stopnie, radiany, radiany_z_pi;
    printf("Podaj liczbe stopni: ");
    scanf("%lf", &stopnie);
    radiany = stopnie / 360 * 2 * 3.14159;
    radiany_z_pi = stopnie / 360 * 2;
    printf("%g stopni to %g (%g*pi) radianow\n", stopnie, radiany, radiany_z_pi);
}
