// Hubert Kompanowski - petla miesiac co 7 dni

#include <stdio.h>
#include <time.h>

void kalendarz();
int ile_dni_ma_dany_misiac();

int main(void)
{   
    printf("****Kalendarz****\n");
    kalendarz();
}

void kalendarz(void)
{   
    time_t liczba_sekund;
    struct tm struktura;
    time(&liczba_sekund);
    localtime_r(&liczba_sekund, &struktura);
    
    int dni;
    int rok = struktura.tm_year;    
    int msc = struktura.tm_mon+1;
    int dzien = struktura.tm_mday;

    dni = ile_dni_ma_dany_misiac(rok, msc, dni);    

    int x = 1;
    while(x <= dni)
    {   
        if (x<=9)
        {        
            if (x==dzien)
                printf("[%d] ",x);
            else 
                printf(" %d  ",x);
        }
        else
        {    
            if (x==dzien) 
                printf("[%d]",x);
            else 
                printf(" %d ",x);
        }
 
        if (x%7 == 0 || x==dni) 
            printf("\n");
        x++;
    }    
}

int ile_dni_ma_dany_misiac(int rok, int msc, int dni)
{
    if(rok%4==0 && msc==2)
    {
        dni = 29;
        return dni;
    }   

    if(msc==1 || msc==3 || msc==5 || msc==7 || msc==8 || msc==10 || msc==12)
        dni = 31;
    else 
        if(msc==2) 
            dni = 28;
        else 
            dni = 30;
    return dni;
}
