#include <stdio.h>
#include <stdlib.h>
#include "biblioteka.h"


int main(int argc, char* argv[])
{

	enum WeekDay
	{
		MONDAY = 1,
		TUESDAY,
		WEDNESDAY = -50,
		THURSDAY,
		FRIDAY
	};
	
	enum WeekDay day = MONDAY;
	printInt(day);

	day = TUESDAY;
	printInt(day);

	day = WEDNESDAY;
	printInt(day);

	day = THURSDAY;
	printInt(day);

	day = FRIDAY;
	printInt(day);


	return 0;
}

















/*
int fibb(int n)
{
	
	if (n==0)
	{
		return 0;
	}	
	else if (n==1 || n==2)
	{	
		return 1;
	}
	else 
	{
		int zmienna;
		zmienna=(fibb(n-1) + fibb(n-2));
		return zmienna;
	}
}

int main()
{
	while (1)
	{	
		int n=0;	
		scanf("%d", &n);
		printf("%d\n", fibb(n));
		
	}
	return 0;
}
*/


/*
int main(int argc, char* argv[])

{
	int zm;
	while (1)
	{
		zm=0;
		scanf("%d\n", &zm);

		switch (zm)
		{
			case 0:
				return 0;
			case 1:
				puts("Kotlet schabowy");
				break;
			case 2:
				puts("Golabki");
				break;
			case 3:
				puts("Lazanki");
				break;
			default:
				puts("Nie wlasciwa opcja - brak obiadu");
				break;
		return 0;
		}
	}
}
*/






/*	for(int i=0; i<argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	return 0;
*/

