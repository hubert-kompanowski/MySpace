#include <stdio.h>
#include <stdlib.h>

int pierw (float a, float b, float c)
{
	float d;
	int e;
	d=b*b-4*a*c;

	if (d>0) e=2;
	else if (d=0) e=1;
		else e=0;
	return 0;
}
int main ()
{
		float a = rand() % 100, b = rand() % 100, c = rand() % 100;

		printf("Ilosc pierwiastkow %d",pierw(a,b,c));

		return 0;
}


