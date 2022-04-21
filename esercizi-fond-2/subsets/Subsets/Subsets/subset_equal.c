#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void SubsetEqualRec(int n, int s, int current, int quantiElem, bool* used, int * currentSol, int currentLevel)
{

	if (current > s)
	{
		return;
	}

	if (current == s)
	{
		printf("{");
		for (int i = 0; i < quantiElem; i++)
		{
			printf(" %d", currentSol[i]);
		}
		printf(" }, ");
	}

	for (int l = currentLevel; l < n; l++)
	{
		if (used[l] == false)
		{
			used[l] = true;
			currentSol = realloc(currentSol, sizeof(int) * (quantiElem + 1));
			currentSol[quantiElem] = l + 1;
			SubsetEqualRec(n, s, current + (l + 1), quantiElem + 1, used, currentSol, l);
			used[l] = false;
			currentSol[quantiElem] = 0;
		}
	}

}

void SubsetEqual(int n, int s) {

	if (n <= 0 || s <= 0)
	{
		return;
	}

	bool* used = calloc(n, sizeof(bool));

	int* currentSol = calloc(n, sizeof(int));

	SubsetEqualRec(n, s, 0, 0, used, currentSol, 0);

}