#include <stdio.h>

int main(void)
{
    int liczba;
    char znak;
    char wyraz[80];

    printf("Podaj znak:\n");
    scanf("%c", &znak);

    printf("Podaj wyraz:\n");
    scanf("%s", wyraz);

    printf("Podaj liczbe:\n");
    scanf("%d", &liczba);

    printf("znak=%c, wyraz=%s, liczba=%d\n", znak, wyraz, liczba);
}
