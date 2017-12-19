// Hubert Kompanowski - petla miesiac co 7 dni

#include <stdio.h>
#include <time.h>

void kalendarz();

int main(void)
{   
    printf("****Kalendarz****\n");
    kalendarz();
}

void kalendarz(void)
{   
    int dni;
    time_t liczba_sekund;
    struct tm struktura;
    time(&liczba_sekund);
    localtime_r(&liczba_sekund, &struktura);
    
    int msc = struktura.tm_mon+1;
    int dzien = struktura.tm_mday;

    if(msc==1 || msc==3 || msc==5 || msc==7 || msc==8 || msc==10 || msc==12) dni = 31;
    else if(msc==2) dni = 28;
    else dni = 30;

    int x = 1;
    while(x <= dni)
    {   
        if (x<=9)
        {        
            if (x==dzien) printf("[%d] ",x);
            else printf(" %d  ",x);
        }
        else
        {    
            if (x==dzien) printf("[%d]",x);
            else printf(" %d ",x);
        }
 
        if (x%7 == 0 || x==dni) printf("\n");
        x++;
    }
    
}
