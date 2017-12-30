// Hubert Kompanowski - ASCII

#include <stdio.h>

void znak(void);
void kod(void);
void czyszczenie_ekranu();

int main()
{
    while(1)
    {
        int n;
        printf("****Zamiana kod ASCII <==> znak****\nCo chcesz zamienić:\n1. znak\n2. kod\n3. wyjscie z petli\n");
        scanf("%d",&n); 
        czyszczenie_ekranu();
        switch(n)
        {
            case 1:
                znak();
                break;
            case 2:
                kod();
                break;        
            case 3:
                return 0;
            default:
                printf("Nie ma takiego numeru\n");
                break;
        }
    }
}

void znak(void)
{
    char znak, bialy;
    printf("\nPodaj znak: ");
    scanf("%c%c",&bialy, &znak);
    printf("Kod ASCII: %d \n\n", znak); 
}

void kod(void)
{
    int kod_ascii;
    printf("\nPodaj kod ASCII: \n");
    scanf("%d", &kod_ascii);
    printf("Znak to: %c \n\n", kod_ascii);
}

void czyszczenie_ekranu()
{
    printf("\033[2J");   
    printf("\033[0;0f");
}

