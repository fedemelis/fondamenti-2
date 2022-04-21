//#include "babbonatale.h"

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int* vcurr, int livello, int peso_corrente, int** bestV) {

	int quanti_pacchi_presi = 0;
	int quanti_pacchi_presi_bestV = 0;

	if (peso_corrente > p)
	{
		return;
	}

	if (livello == pacchi_size)
	{
		for (size_t i = 0; i < pacchi_size; i++)
		{
			if (vcurr[i] != 0)
			{
				quanti_pacchi_presi += 1;
			}
		}
		for (size_t i = 0; i < pacchi_size; i++)
		{
			if (bestV[0][i] != 0)
			{
				quanti_pacchi_presi_bestV += 1;
			}
		}
		if (quanti_pacchi_presi > quanti_pacchi_presi_bestV)
		{
			for (size_t i = 0; i < pacchi_size; i++)
			{
				bestV[0][i] = vcurr[i];
			}
			return;
		}
		else
		{
			return;
		}
	}

	vcurr[livello] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, livello + 1, peso_corrente, bestV);

	vcurr[livello] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, livello + 1, (peso_corrente + pacchi[livello]), bestV);
	vcurr[livello] = 0;
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	int* vcurr = calloc(pacchi_size, sizeof(int));

	int* best_v = calloc(pacchi_size, sizeof(int));

	BabboNataleRec(pacchi, pacchi_size, p, vcurr, 0, 0, &best_v);

	for (size_t i = 0; i < pacchi_size; i++)
	{
		printf("%d ", best_v[i]);
	}

	free(vcurr);
	free(best_v);

}



