#include <stdlib.h>
#include <stdio.h>

static void BacktrackStrModRec(int n, int k, char *alfabeto, int nIndex, int kIndex, char *sol) {

	if (kIndex == k)
	{
		printf("{");
		for (size_t i = 0; i < k; i++)
		{
			printf("%c", sol[i]);
		}
		printf("}, ");
		return;
	}

	for (size_t i = 0; i < n; i++)
	{
		sol[nIndex] = alfabeto[i];
		BacktrackStrModRec(n, k, alfabeto,nIndex + 1, kIndex + 1, sol);
	}
}

void BacktrackStrMod(int n, int k) {

	if (n <= 0 || k <= 0 || n > 26 )
	{
		return NULL;
	}

	char alfabeto[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char* sol = malloc(sizeof(char) * k);

	BacktrackStrModRec(n, k, alfabeto,0, 0, sol);
	
	free(sol);
}