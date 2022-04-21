#include <stdlib.h>
#include <stdio.h>

static int StepsRec(int n, int somma, int *quanti, int **vec, int * nsol) {

	if (somma == n)
	{
		*nsol += 1;
		printf("[");
		for (size_t i = 0; i < *quanti; i++)
		{
			if (*quanti == i+1)
			{
				printf("%d", vec[0][i]);
			}
			else
			{
				printf("%d, ", vec[0][i]);
			}
		}
		printf("], ");
		return;
	}

	if (somma > n)
	{
		//*quanti -= 1;
		return;
	}

	*quanti += 1;
	*vec = realloc(*vec, sizeof(int) * *quanti);
	vec[0][*quanti - 1] = 1;
	StepsRec(n, somma + 1, quanti, vec, nsol);
	vec[0][*quanti - 1] = 0;
	*quanti -= 1;
	*quanti += 1;
	*vec = realloc(*vec, sizeof(int) * *quanti);
	vec[0][*quanti - 1] = 2;
	StepsRec(n, somma + 2, quanti, vec, nsol);
	vec[0][*quanti - 1] = 0;
	*quanti -= 1;
	*quanti += 1;
	*vec = realloc(*vec, sizeof(int) * *quanti);
	vec[0][*quanti - 1] = 3;
	StepsRec(n, somma + 3, quanti, vec, nsol);
	vec[0][*quanti - 1] = 0;
	*quanti -= 1;

	return nsol;

}

int Steps(int n) {

	if (n <= 0)
	{
		return 0;
	}

	int quanti = 0;
	int nsol = 0;

	int* ris = calloc(1, sizeof(int));

	StepsRec(n, 0, &quanti, &ris, &nsol);

	free(ris);

	return nsol;
}