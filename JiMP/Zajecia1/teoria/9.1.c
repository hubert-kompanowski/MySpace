#include <stdio.h>

void wypisz();

int main(void)
{
	int tab[] = {1,2,3,4,5,6};
	const int rozmiar = sizeof (tab) / sizeof (tab[0]);
	
//	int* a = tab;
//	void* v = a;
//	printf("%d"\n", *v);
	
//	int *b = NULL;
//	b = (int*)v;
//	printf("%d\n", *b);
//	*b = 1;
//	printf("%d\n", *b);
	wypisz(tab, tab+rozmiar);
}

void wypisz(int* od, int* doo)
{
	for (int i=0; i<(doo-od); i++)
	{
		printf("%d\n",od[i]);
	}
}

