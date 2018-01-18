#include <stdio.h>

int main (void)
{
	char litera = 'l';
	char tekst1[] = "jmp";
	char tekst2[] = {'j','m','p','\0'};
	printf("%s, %lu, %s, %lu\n", tekst1, sizeof(tekst1), tekst2, sizeof(tekst2));

	int liczbPierw[5] = {2, 3, 5, 7, 11};
	
}
