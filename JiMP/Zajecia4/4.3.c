//Hubert Kompanowski - Implementacja zagadki z waga i kulkami

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void wazenie_kulek();
void losowanie_kulek();

int main (void)
{
    int kulka[9] = {0};
    losowanie_kulek(kulka);
    wazenie_kulek(kulka);
}
    
void losowanie_kulek(int kulka[9])
{
    srand(time(NULL));
    kulka[rand()%9] = 1;
}

void wazenie_kulek(int kulka[9])
{ 
    if (kulka[1]+kulka[2]+kulka[3] > kulka[4]+kulka[5]+kulka[6])
        if (kulka[1] > kulka[2]) 
            printf("kulka numer 1\n");
        else 
            if (kulka[1] < kulka[2])
                printf("kulka numer 2\n");
            else 
                printf("kulka numer 3\n");
    else 
        if (kulka[1]+kulka[2]+kulka[3] < kulka[4]+kulka[5]+kulka[6])
            if (kulka[4] > kulka[5])   
                printf("kulka numer 4\n");
            else 
                if (kulka[4] < kulka[5])
                    printf("kulka numer 6\n");
                else 
                    printf("kulka numer 5\n");
        else
            if (kulka[7] > kulka[8])
                printf("kulka numer 7\n");
            else 
                if (kulka[7] < kulka[8])
                    printf("kulka numer 8\n");
                else 
                    printf("kulka numer 9\n");
}
