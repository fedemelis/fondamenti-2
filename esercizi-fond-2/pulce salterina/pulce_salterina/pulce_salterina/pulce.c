#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static char* GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, int quantiSalti, int currPos, char *ret, int vecPos, int *bestSolDim, int saltiIndietro, char * bestSol) {

	if (currPos == h)
	{
		if (quantiSalti < *bestSolDim)
		{
			*bestSolDim = quantiSalti;
			bestSol = realloc(bestSol, (*bestSolDim * sizeof(char)));
			//bestSol = ret;
			memcpy(bestSol, ret, (*bestSolDim * sizeof(char)));
			*ret_size = quantiSalti;
			return bestSol;
		}
		else
		{
			return NULL;
		}
	}

	bool ammissibileA = true;
	bool ammissibileB = true;

	for (size_t i = 0; i < f_size; i++)
	{
		if (f[i] == (currPos + a))
		{
			ammissibileA = false;
		}
	}


	if (quantiSalti < n && ammissibileA && currPos +a >= 0)
	{
		ret = realloc(ret, sizeof(char) * (quantiSalti+1));
		ret[vecPos] = 'a';
		saltiIndietro = 0;
		//*ret_size += 1;
		GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, quantiSalti + 1, currPos + a, ret, vecPos + 1, bestSolDim, saltiIndietro, bestSol);
		//(*ret_size)--;
	}

	for (size_t i = 0; i < f_size; i++)
	{
		if (f[i] == (currPos - b))
		{
			ammissibileB = false;
		}
	}

	if (quantiSalti < n && ammissibileB && currPos - b >= 0 )
	{
		if (saltiIndietro == 1)
		{
			return NULL;
		}
		else
		{
			ret = realloc(ret, sizeof(char) * (quantiSalti+1));
			ret[vecPos] = 'b';
			//*ret_size += 1;
			GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, quantiSalti + 1, currPos - b, ret, vecPos + 1, bestSolDim, saltiIndietro + 1, bestSol);
			//*ret_size;
		}
	}
	if (*bestSolDim == 999999)
	{
		*ret_size = 0;
	}
	return bestSol;
}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {

	char* ret = malloc(1 * sizeof(char));
	char* retBest = malloc(1 * sizeof(char));
	int retBestDim = 999999;
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, 0, 0, ret, 0, &retBestDim, 0, retBest);
	free(ret);
	return retBest;
}