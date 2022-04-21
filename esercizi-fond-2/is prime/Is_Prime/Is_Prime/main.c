/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
bool isPrimeRec(int n, int max, int* currDiv) {	int c = *currDiv;	if (*currDiv > max)
	{
		return true;
	}	if ((n % c) == 0)
	{
		return false;
	}	else
	{
		*currDiv++;
		return isPrimeRec(n, max, &currDiv);
	}}
bool isPrime(int n) {	int max = n / 2;	int divisore = 2;	if (n == 1 || n == 2 || n < 0)
	{
		return true;
	}	if (n == 0)
	{
		return false;
	}	return isPrimeRec(n, max, &divisore);}int main(int argc, char* argv[]) {	int n = 0;	printf("isprime ");	scanf("%d", &n);	if (isPrime(n))
	{
		printf("true");
	}	else
	{
		printf("false");
	}}*/