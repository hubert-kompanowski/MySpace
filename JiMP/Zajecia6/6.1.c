// Hubert Kompanowski - ASCII

#include <stdio.h>

void znak();
void kod();

int main(void)
{
    int n;
    printf("****Zamiana kod ASCII <==> znak****\nCo chcesz zamienić:\n1. kod\n2. znak\n");
    scanf("%d",&n); 
    switch(n)
    {
        case 1:
            znak();
            break;
        case 2:
            kod();
            break;
        default:
            printf("Nie ma takiego numeru\n");
            break;
    }
}

void znak(void)
{
    char znak, bialy;
    printf("Podaj znak: \n");
    scanf("%c%c",&bialy, &znak);
    printf("Kod ASCII: %d \n", znak); 

}

void kod(void)
{
    int kod_ascii;
    printf("Podaj kod ASCII: \n");
    scanf("%d", &kod_ascii);
    printf("Znak to: %c \n", kod_ascii);
}
