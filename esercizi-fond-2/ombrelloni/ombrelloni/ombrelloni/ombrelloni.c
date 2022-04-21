#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void OmbrelloniRec(int k, int n, int* nsol, int quanti_amici, int* vec, int count) {

	bool ammissibile;

	if (k == quanti_amici)
	{
		ammissibile = true;
		for (size_t j = 0; j < n; j++)
		{
			if ((vec[j] == vec[j + 1]) && vec[j] == 1)
			{
				ammissibile = false;
			}
		}
		if (ammissibile)
		{
			*nsol += 1;
			printf("%d) ", *nsol);
			for (size_t i = 0; i < n; i++)
			{
				if (i == n - 1)
				{
					printf("%d", vec[i]);
				}
				else
				{
					printf("%d ", vec[i]);
				}
			}
			printf("\n");
			quanti_amici = 0;
		}
	}

	if (count == n)
	{
		return;
	}

	vec[count] = 0;
	OmbrelloniRec(k, n, nsol, quanti_amici, vec, count + 1);

	vec[count] = 1;
	OmbrelloniRec(k, n, nsol, quanti_amici + 1, vec, count + 1);
	
}

int Ombrelloni(int k, int n) {

	if (k < 0 || n < 0)
	{
		return;
	}

	int* vec = malloc(sizeof(int) * n);
	int n_soluzioni = 0;

	OmbrelloniRec(k, n, &n_soluzioni, 0, vec, 0);

	return n_soluzioni;
}
