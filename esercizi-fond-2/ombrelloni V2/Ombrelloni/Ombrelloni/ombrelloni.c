#include <stdlib.h>
#include <stdio.h>

static int OmbrelloniRec(int k, int n, int * currentSol, int index, int quantiPosizionati, int *quanteSol) {

	int ammissibile = 0;
	int quantiPos = 0;

	if (quantiPosizionati == n)
	{
		for (size_t i = 0; i < n; i++)
		{
			if (currentSol[i] == 1)
			{
				quantiPos += 1;
				if (currentSol[i + 1] == 1)
				{
					ammissibile = 1;
					break;
				}
			}
		}
		if (ammissibile == 0 && quantiPos == k)
		{
			*quanteSol += 1;
			printf("%d) ", *quanteSol);
			for (size_t j = 0; j < n; j++)
			{
				printf("%d ", currentSol[j]);
			}
			printf("\n");
		}
		return *quanteSol;
	}

	currentSol[index] = 0;
	OmbrelloniRec(k, n, currentSol, index + 1, quantiPosizionati + 1, quanteSol);
	currentSol[index] = 1;
	OmbrelloniRec(k, n, currentSol, index + 1, quantiPosizionati + 1, quanteSol);
	currentSol[index] = 0;

	return *quanteSol;
}


int Ombrelloni(int k, int n) {

	if (k <= 0 || n <= 0 || k >= n)
	{
		return 0;
	}

	int *currentSol = calloc(n, sizeof(int));
	int quanteSol = 0;

	OmbrelloniRec(k, n, currentSol, 0, 0, &quanteSol);

	free(currentSol);
	return quanteSol;
}