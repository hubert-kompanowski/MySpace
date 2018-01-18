#include <stdio.h>

int f();

int main(int argc, char* argv[])
{
	int suma;
	int a=5;
	int b=6;
	int* am;
	int* bm;
	am = &a;
	bm = &b;

	suma = f(am, bm);
	printf("%d\n", suma);

}

int f(int* a, int*b)
{
	*a = 2**a;
	*b = *b * *b;
	return *a + *b;	
	
}

