#include <stdio.h>

void f();

int main(void)
{
	int tab[] = {1,2,3,4,5,6,7,8,9};
	f(tab);
	
	for(int j=0;j<9;j++)
	{
		printf("%d\n", tab[j]);
	}	
}

void f(int tab[9])
{
	int i;
	int* wsk = tab;
	for(i=0;i<9;i++)
	{
		wsk = tab+i;
		*wsk = *wsk + 2;
	}
}

