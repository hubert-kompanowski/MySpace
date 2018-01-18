#include <stdio.h>

void wypisz();

int main(void)
{
	const int tab[] = {1,2,3,4,5,6};
	const int rozmiar = sizeof (tab) / sizeof (tab[0]);
	
	int* a = (int*)tab;
	*a = 3;
	
	wypisz(tab, tab+rozmiar);
}


void wypisz(const int* od, const int* doo)
{
	for (int i=0; i<(doo-od); i++)
	{
		printf("%d\n",od[i]);
	}
}

