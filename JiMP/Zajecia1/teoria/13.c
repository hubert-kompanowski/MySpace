#include <stdio.h>

int main()
{
	const char* fileName = "plik.txt";
	
	FILE *plik = fopen(fileName, "w");
	
	if(NULL == plik)
	{
		fprintf(stderr, "blad\n");
		return 1;
	}
	
	fprintf(plik, "123123123");
	fclose(plik);
}

