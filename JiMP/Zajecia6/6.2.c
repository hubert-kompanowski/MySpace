// Hubert Kompanowski - petla miesiac co 7 dni

#include <stdio.h>
#include <time.h>

void kalendarz();
int ile_dni_ma_dany_miesiac(int rok, int miesiac, int dni);

int main(void)
{   
    printf("   ****Kalendarz****\n");
    kalendarz();
}

void kalendarz(void)
{   
    time_t liczba_sekund;
    struct tm struktura;
    time(&liczba_sekund);
    localtime_r(&liczba_sekund, &struktura);
    
    int rok = struktura.tm_year+1900;   
    int miesiac = struktura.tm_mon+1;
    int dzien = struktura.tm_mday;

    int dni = ile_dni_ma_dany_miesiac(rok, miesiac, dni);
    int x = 1;
    while(x <= dni)
    {   
        if (x<=9)
        {        
            if (x==dzien)
                printf("[%2d]",x);
            else 
                printf(" %2d ",x);
        }
        else
        {    
            if (x==dzien) 
                printf("[%2d]",x);
            else 
                printf(" %2d ",x);
        }
 
        if (x%7 == 0 || x==dni) 
            printf("\n");
        x++;
    }    
}

int ile_dni_ma_dany_miesiac(int rok, int miesiac, int dni)
{
    if(rok%4==0 && miesiac==2)
    {
        if(rok%400==0)
        {        
            dni = 29;
            return dni;
        }
        else
        {
            if(rok%100!=0)
            {   
                dni = 29;
                return dni;
            }
        }
    }   

    if(miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8 || miesiac==10 || miesiac==12)
        dni = 31;
    else 
        if(miesiac==2) 
            dni = 28;
        else 
            dni = 30;
    return dni;
}
