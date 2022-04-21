#include <stdio.h>

static void RecamanRec(int n, int curr_n, int *ris) {

	if (curr_n > n)
	{
		return;
	}

	if (*ris % (curr_n - 1) == 0)
	{
		*ris /= (curr_n - 1);
	}
	else
	{
		*ris *= (curr_n - 1);
	}

	RecamanRec(n, curr_n + 1, ris);
}


int Recaman(int n) {

	if (n < 1)
	{
		return -1;
	}

	int ris = 1;

	RecamanRec(n, 2, &ris);

	return ris;
}