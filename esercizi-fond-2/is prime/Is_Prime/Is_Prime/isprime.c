#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isPrimeRec(int n, int max, int* currDiv) {

	if (*currDiv > max)
	{
		return true;
	}

	if ((n % (*currDiv)) == 0)
	{
		return false;
	}
	else
	{
		*currDiv += 1;
 		return isPrimeRec(n, max, currDiv);
	}

}

bool isPrime(int n) {

	int max = n / 2;
	int divisore = 2;

	if (n == 2 || n == 3)
	{
		return true;
	}

	if(n <= 0 || n == 1)
	{
		return false;
	}

	if (isPrimeRec(n, max, &divisore))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char* argv[]) {

	if (argc > 2 || argc < 2 || atoi(argv[1]) < 0)
	{
		return 1;
	}
	
	for (size_t i = 1; i < argc; i++)
	{
		if (isPrime(atoi(argv[i])))
		{
			printf("true");

		}
		else
		{
			printf("false");
		}
	}

}
