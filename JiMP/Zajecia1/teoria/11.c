#include <stdio.h>
#include <stdlib.h>

int f(int i)
{
	if (i == 1)
		return f(i-1);
	else
		return 0;
}

int main(void)
{
	//f(5)
		

	
	system("ls -l");
	double a=3.14, b=2.72, c=a/2;
	double* tab[10] = { &a, &b, &c};
	
	for(int i=0; i<sizeof(tab)/sizeof(tab[0]); i++)
	{
		//if (tab[i])
			printf("%lf", *tab[i]);
		
		//fflush(stdout);
		
	}



	/*
	int tab[5];
	for(int x=1; x<7; x++)
	{
		tab[x] = 5;
		printf("%d", tab[x]);
	}
*/
}	
