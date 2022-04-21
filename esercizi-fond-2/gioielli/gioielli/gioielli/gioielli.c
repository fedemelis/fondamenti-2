#include "gioielli.h"

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {

	FILE* f = fopen(filename, "r+");

	if (f == NULL)
	{
		return NULL;
	}

	Gioiello* g = malloc(sizeof(Gioiello));
	int quanti = 0;
	Gioiello* gfinal = malloc(sizeof(Gioiello));
	int quale = -1;
	int presiCnt = 0;


	while (1)
	{
		if (fscanf(f, "%i %f %f", &g[quanti].codice, &g[quanti].peso, &g[quanti].prezzo) == 3) {
			++quanti;
			g = realloc(g, sizeof(Gioiello) * (quanti + 1));
		}
		else
		{
			break;
		}
	}

	fclose(f);

	int* usato = calloc(sizeof(g), sizeof(int));

	for (size_t i = 0; i < quanti; i++)
	{
		if (budget > 0)
		{
			double appet = 0;
			double best_price = 99999999;
			double best_weight = 0;
			for (size_t i = 0; i < quanti; i++)
			{
				if ((g[i].peso / g[i].prezzo) >= appet && (budget - g[i].prezzo) >= 0 && usato[i] == 0)
				{
					if (best_weight == g[i].peso && best_price < g[i].prezzo)
					{
						
					}
					else
					{
						appet = (g[i].peso / g[i].prezzo);
						quale = i;
						best_price = g[i].prezzo;
						best_weight = g[i].peso;
					}
				}
			}
			if (quale != -1)
			{
				gfinal = realloc(gfinal, sizeof(Gioiello) * (presiCnt+1));
				budget -= g[quale].prezzo;
				usato[quale] = 1;
				gfinal[presiCnt].codice = g[quale].codice;
				gfinal[presiCnt].peso = g[quale].peso;
				gfinal[presiCnt].prezzo = g[quale].prezzo;
				presiCnt++;
				quale = -1;
			}
		}
	}

	free(g);
	free(usato);
	*ret_size = presiCnt;
	return gfinal;
}