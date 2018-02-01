// Hubert Kompanowski - petla miesiac co 7 dni

#include <stdio.h>
#include <time.h>

void kalendarz(void);
int ile_dni_ma_dany_miesiac(int rok, int miesiac, int dni);
void wyswietlanie_aktualnego_misiaca_i_roku(int miesiac, int rok);
int aktualny_rok_i_miesiac_i_dzien(char* wybor);

int main(void)
{   
    const int rok = aktualny_rok_i_miesiac_i_dzien("rok");
    const int miesiac = aktualny_rok_i_miesiac_i_dzien("miesiac");

    printf("     ****Kalendarz****\n\n");
    wyswietlanie_aktualnego_misiaca_i_roku(miesiac, rok);
    kalendarz();
}

void kalendarz(void)
{   
    const int rok = aktualny_rok_i_miesiac_i_dzien("rok");
    const int miesiac = aktualny_rok_i_miesiac_i_dzien("miesiac");
    const int dzien = aktualny_rok_i_miesiac_i_dzien("dzien");

    const int dni = ile_dni_ma_dany_miesiac(rok, miesiac, dni);
    
    for(int x = 1; x<=dni; x++)
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

void wyswietlanie_aktualnego_misiaca_i_roku(int miesiac, int rok)
{
    char* const tablica_miesiecy[12] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec",
                  "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};
    printf("       %s, %d\n", tablica_miesiecy[miesiac-1], rok);

}

int aktualny_rok_i_miesiac_i_dzien(char* wybor)
{
    time_t liczba_sekund;
    struct tm struktura;
    time(&liczba_sekund);
    localtime_r(&liczba_sekund, &struktura);

    const int rok = struktura.tm_year+1900;   
    const int miesiac = struktura.tm_mon+1;
    const int dzien = struktura.tm_mday;
    
    if(wybor == "rok")
        return rok;
    if(wybor == "miesiac")
        return miesiac;
    if(wybor == "dzien")
        return dzien;
    return 0;
}

