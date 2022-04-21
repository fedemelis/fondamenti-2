#include "domino.h"

static Placing* DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, size_t currIndex, Placing *p, bool* used, Placing *best, size_t *bestLen) {

	if (currIndex > *bestLen)
	{
		memcpy(best, p, currIndex * sizeof(Placing));
		*ret_size = currIndex;
		*bestLen = currIndex;
		return;
	}

	if (currIndex == t_size)
	{
		return;
	}

	for (size_t i = 0; i < t_size; i++)
	{
		if (!used[i])
		{
			if (currIndex == 0 || 
				(t[p[currIndex - 1].indice].val1 == t[i].val1 && p[currIndex - 1].flipped) ||
				(t[p[currIndex - 1].indice].val2 == t[i].val1 && !p[currIndex - 1].flipped)) {

				p[currIndex].indice = i;
				p[currIndex].flipped = false;
				used[i] = true;
				DominoRec(t, t_size, ret_size, currIndex + 1, p, used, best, bestLen);
				used[i] = false;
			}
			if (currIndex == 0 ||
				(t[p[currIndex - 1].indice].val1 == t[i].val2 && p[currIndex - 1].flipped) ||
				(t[p[currIndex - 1].indice].val2 == t[i].val2 && !p[currIndex - 1].flipped)) {

				p[currIndex].indice = i;
				p[currIndex].flipped = true;
				used[i] = true;
				DominoRec(t, t_size, ret_size, currIndex + 1, p, used, best, bestLen);
				used[i] = false;
			}
		}
	}

	return best;
}

Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {

	if (t == NULL || t_size == 0)
	{
		*ret_size = 0;
		return NULL;
	}

	Placing* ris = calloc(t_size, sizeof(Placing));
	Placing* curr = calloc(t_size, sizeof(Placing));
	bool* used = calloc(t_size, sizeof(bool));
	size_t bestLen = 0;

	DominoRec(t, t_size, ret_size, 0, ris, used, curr, &bestLen);

	free(used);
	free(curr);
	return ris;
}
