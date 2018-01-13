// Hubert Kompaowski - wyswietlanie na srodku zadanej dlugosci

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wyswietlanie_na_srodku(void* dana, char* rodzaj_wejscia, int zadana_dlugosc);
void wyswietlanie_znaku(void* dana, char* rodzaj_wejscia, int zadana_dlugosc);
void wyswietlanie_napisu(void* dana, char* rodzaj_wejscia, int zadana_dlugosc);
void wyswietlanie_liczby(void* dana, char* rodzaj_wejscia, int zadana_dlugosc);
void wyswietlanie_liczby_zmiennoprzecinkowej(void* dana, char* rodzaj_wejscia, int zadana_dlugosc);

int main(void)
{
    int zadana_dlugosc = 30;
    char* napis = "jakis tam napis";
    char* napis_2 = "choinka";
    char* napis_3 = "1234567654321";
    char* napis_4 = "ZXZ";
    int liczba_2 = 888888888;
    int liczba = 333;
    double liczba_zmeinnoprzecinkowa = 31.1315;
    char znak = 'X';
    char znak_2 = 'O';

    wyswietlanie_na_srodku(NULL, "napis", zadana_dlugosc);
    wyswietlanie_na_srodku(&znak, "znak", zadana_dlugosc);
    wyswietlanie_na_srodku(&liczba,"liczba", zadana_dlugosc);
    wyswietlanie_na_srodku(&liczba_zmeinnoprzecinkowa,"liczba_zmiennoprzecinkowa", zadana_dlugosc);
    wyswietlanie_na_srodku(&napis_2, "napis", zadana_dlugosc);
    wyswietlanie_na_srodku(&liczba_2,"liczba", zadana_dlugosc);
    wyswietlanie_na_srodku(&napis_3, "napis", zadana_dlugosc);
    wyswietlanie_na_srodku(&napis, "napis", zadana_dlugosc);
    wyswietlanie_na_srodku(&znak_2, "znak", zadana_dlugosc);
    wyswietlanie_na_srodku(&napis_4, "napis", zadana_dlugosc);
    wyswietlanie_na_srodku(NULL, "znak", zadana_dlugosc);
}

int wyswietlanie_na_srodku(void* dana, char* rodzaj_wejscia, int zadana_dlugosc )
{
    if(dana==0)
    {
        printf("\n");
        return 0;
    }
    int dlugosc_danej = 0;

    if(rodzaj_wejscia == "znak")
        wyswietlanie_znaku(dana, rodzaj_wejscia, zadana_dlugosc);
    else
        if(rodzaj_wejscia == "napis")
            wyswietlanie_napisu(dana, rodzaj_wejscia, zadana_dlugosc);
        else 
            if(rodzaj_wejscia == "liczba")        
                wyswietlanie_liczby(dana, rodzaj_wejscia, zadana_dlugosc);            
            else 
                if(rodzaj_wejscia == "liczba_zmiennoprzecinkowa")                
                    wyswietlanie_liczby_zmiennoprzecinkowej(dana, rodzaj_wejscia, zadana_dlugosc);                
    return 0;
}

void wyswietlanie_znaku(void* dana, char* rodzaj_wejscia, int zadana_dlugosc)
{
    int dlugosc_danej = 0;
    char wyswietlana_dana = *(char*)dana;

    if(isprint(wyswietlana_dana) == 0)
        printf("\n");
    else
        if(zadana_dlugosc % 2 == 1)
            printf("%*c%c\n",(zadana_dlugosc-1)/2,' ',wyswietlana_dana);
        else
            printf("%*c%c\n",(zadana_dlugosc/2-1),' ', wyswietlana_dana);
}

void wyswietlanie_napisu(void* dana, char* rodzaj_wejscia, int zadana_dlugosc)
{
    int dlugosc_danej = 0;
    char* wyswietlana_dana = *(char**)dana;
    dlugosc_danej = strlen(wyswietlana_dana);

    if(dlugosc_danej >= zadana_dlugosc)
        printf("%s\n",wyswietlana_dana);
    else
        if((zadana_dlugosc-dlugosc_danej)%2 == 1)
            printf("%*c%s\n",(zadana_dlugosc-dlugosc_danej-1)/2,' ',wyswietlana_dana);
        else
            printf("%*c%s\n",((zadana_dlugosc-dlugosc_danej)/2),' ', wyswietlana_dana);
}

void wyswietlanie_liczby(void* dana, char* rodzaj_wejscia, int zadana_dlugosc)
{
    int dlugosc_danej = 0;
    int wyswietlana_dana = *(int*)dana;
    char wyswietlana_dana_2[128];
    snprintf(wyswietlana_dana_2,128,"%d",wyswietlana_dana);
    dlugosc_danej = strlen(wyswietlana_dana_2);

    if(dlugosc_danej>=zadana_dlugosc)
        printf("%s\n",wyswietlana_dana_2);
    else 
        if((zadana_dlugosc-dlugosc_danej)%2 == 1)
            printf("%*c%s\n",(zadana_dlugosc-dlugosc_danej-1)/2,' ',wyswietlana_dana_2);
        else
            printf("%*c%s\n",((zadana_dlugosc-dlugosc_danej)/2),' ', wyswietlana_dana_2);            

}

void wyswietlanie_liczby_zmiennoprzecinkowej(void* dana, char* rodzaj_wejscia, int zadana_dlugosc)
{
    int dlugosc_danej = 0;
    double wyswietlana_dana = *(double*)dana;

    char wyswietlana_dana_2[128];
    snprintf(wyswietlana_dana_2,128,"%f",wyswietlana_dana);
    dlugosc_danej = strlen(wyswietlana_dana_2);
    int po_przecinku = 2;


    for(int cyfra = 1; cyfra <= dlugosc_danej; ++cyfra)
        if(wyswietlana_dana_2[cyfra] == '.')
        {
            dlugosc_danej = cyfra+3;
            if(wyswietlana_dana_2[cyfra+1] == '0')
                if(wyswietlana_dana_2[cyfra+2] == '0')
                {
                    po_przecinku = 0;
                    dlugosc_danej = cyfra+1;
                }
            else 
            {
                if(wyswietlana_dana_2[cyfra+2] == '0')
                {
                    po_przecinku = 1;
                    dlugosc_danej = cyfra+2;
                }
                break;
            }
        }
    if(dlugosc_danej>=zadana_dlugosc)
        printf("%.*f\n",po_przecinku,wyswietlana_dana);
    else 
        if((zadana_dlugosc-dlugosc_danej)%2 == 1)
            printf("%*c%.*f\n",(zadana_dlugosc-dlugosc_danej-1)/2,
                   ' ',po_przecinku,wyswietlana_dana);
        else
            printf("%*c%.*f\n",((zadana_dlugosc-dlugosc_danej)/2),
                   ' ',po_przecinku,wyswietlana_dana);
}

