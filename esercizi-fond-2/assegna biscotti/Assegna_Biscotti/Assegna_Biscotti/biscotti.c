#include <stdlib.h>
#include <stdbool.h>

int FindBestCombination(int bamSize, int bisSize, int*bam, int*bis, bool* bamCompleted, bool* bisUsed, int * bestBamIndex, int * bestBisIndex) {

	int tmpRis = 0;
	int bestRis = 999999;
	bool first = true;
	bool exit = true;

	while (bestRis > 0)
	{
		if (first)
		{
			first = false;
			for (size_t i = 0; i < bamSize; i++)
			{
				for (size_t j = 0; j < bisSize; j++)
				{
					if (bamCompleted[i] == false && bisUsed[j] == false)
					{
						tmpRis = bam[i] - bis[j];
						if ((tmpRis < bestRis && bestRis > 0) || (tmpRis > bestRis && bestRis < 0) || tmpRis == 0)
						{
							if (!(tmpRis > 0 && bestRis < 0))
							{
								bestRis = tmpRis;
								tmpRis = 0;
								*bestBisIndex = j;
								*bestBamIndex = i;
							}
						}
					}
				}
			}
		}
		else
		{
			bisUsed[*bestBisIndex] = true;
			for (size_t j = 0; j < bisSize; j++)
			{
				if (bestRis == false && bisUsed[j] == false)
				{	
					exit = false;
					tmpRis = bestRis - bis[j];
					if ((tmpRis < bestRis && bestRis > 0) || (tmpRis > bestRis && bestRis < 0) || tmpRis == 0)
					{
						if (!(tmpRis > 0 && bestRis < 0))
						{
							bestRis = tmpRis;
							tmpRis = 0;
							*bestBisIndex = j;
						}
					}
				}
			}
			bisUsed[*bestBisIndex] = true;
			if (exit == true)
			{
				break;
			}
			else
			{
				exit = false;
			}
		}
	}
	return bestRis;

}

static int AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, bool * bamCompleted, bool * bisUsed, int *bamIndex, int *bisIndex, int * quantiSoddisfatti, int rimanenza, bool first, int quanti) {

	if (quanti >= bis_size)
	{
		return *quantiSoddisfatti;
	}

	if (*bamIndex >= bam_size)
	{
		*bamIndex = 0;
	}

	int diff = FindBestCombination(bam_size, bis_size, bam, bis, bamCompleted, bisUsed, bamIndex, bisIndex);

	bamCompleted[*bamIndex] = true;
	bisUsed[*bisIndex] = true;


	/*if (!bisUsed[*bisIndex])
	{
		bisUsed[*bisIndex] = true;

		if ((bam[*bamIndex] - bis[*bisIndex]) <= 0 || (rimanenza - bis[*bisIndex] <= 0 && rimanenza != 0))
		{
			bamCompleted[*bamIndex] = true;
			rimanenza = 0;
			*bamIndex += 1 + intervallo;
			*quantiSoddisfatti += 1;
			first = true;
		}
		else
		{
			if (first)
			{
				first = false;
				rimanenza = bam[*bamIndex];
				rimanenza = rimanenza - (bam[*bamIndex] - bis[*bisIndex]);
			}
			else
			{
				rimanenza = rimanenza - (bam[*bamIndex] - bis[*bisIndex]);
			}
		}
	}



	*bisIndex += 1;*/
	AssegnaBiscottiRec(bam, bam_size, bis, bis_size, bamCompleted, bisUsed, bamIndex, bisIndex, quantiSoddisfatti, rimanenza, first, quanti + 1);
}

int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
	if (bam == NULL || bam_size == 0 || bis == NULL || bis_size == 0)
	{
		return 0;
	}
	bool *bamCompleted = calloc(bam_size, sizeof(bool));
	bool *bisUsed = calloc(bis_size, sizeof(bool));
	int quantiSoddisfatti = 0;
	int best = 0;
	int bamIndex = 0;
	int bisIndex = 0;
	/*for (size_t i = 0; i < bam_size; i++)
	{
		AssegnaBiscottiRec(bam, bam_size, bis, bis_size, bamCompleted, bisUsed, &bamIndex, &bisIndex, &quantiSoddisfatti, 0, true, i);
		quantiSoddisfatti = 0;
		for (size_t i = 0; i < bam_size; i++)
		{
			if (bamCompleted[i] == true)
			{
				++quantiSoddisfatti;
			}
		}
		if (quantiSoddisfatti > best)
		{
			best = quantiSoddisfatti;
			quantiSoddisfatti = 0;
		}
		for (size_t i = 0; i < bam_size; i++)
		{
			bamCompleted[i] = false;
		}
		for (size_t i = 0; i < bis_size; i++)
		{
			bisUsed[i] = false;
		}
		bamIndex = 0;
		bisIndex = 0;
	}*/

	AssegnaBiscottiRec(bam, bam_size, bis, bis_size, bamCompleted, bisUsed, &bamIndex, &bisIndex, &quantiSoddisfatti, 0, true, 0);

	for (size_t i = 0; i < bam_size; i++)
	{
		if (bamCompleted[i] == true)
		{
			++quantiSoddisfatti;
		}
	}

	free(bamCompleted);
	free(bisUsed);
	return quantiSoddisfatti;
}