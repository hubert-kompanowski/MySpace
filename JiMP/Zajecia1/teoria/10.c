#include <stdio.h>

//typedef long long Licznik;

//void wyswietl_ilosc_wyswietlen(Licznik wyswietlenia)
//{
//	printf("Wyswietlenia: %lld \n", wyswietlenia);
//}

struct Osoba
{
	char imie[32];
	int id;
	char zawod[32];
};

int main(void)
{
	struct Osoba Pudzian = {"Mariusz", 2546, "MMA"};
	printf("%s %d %s\n", Pudzian.imie, Pudzian.id, Pudzian.zawod);
	Pudzian.imie[4] = '\0';
	printf("%s %d %s\n", Pudzian.imie, Pudzian.id, Pudzian.zawod);

//	Licznik smieszne_koty = 10000;
//	Licznik gangamstyle = 10000000000;
//	wyswietl_ilosc_wyswietlen(smieszne_koty);
//	wyswietl_ilosc_wyswietlen(gangamstyle);
}

