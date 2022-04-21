#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

static void CheckSumNRec(const Node* t, int **v, int *lvl) {

	if (TreeIsEmpty(t))
	{
		return;
	}

	if (TreeLeft(t))
	{
		CheckSumNRec(TreeLeft(t), v, lvl);
		*v = realloc(*v, sizeof(int) * (*lvl + 1));
		v[0][*lvl] = TreeLeft(t)->value;
		*lvl += 1;
	}
	if (TreeRight(t))
	{
		CheckSumNRec(TreeRight(t), v, lvl);
		*v = realloc(*v, sizeof(int) * (*lvl + 1));
		v[0][*lvl] = TreeRight(t)->value;
		*lvl += 1;
	}

}

bool CheckSumN(const Node* t, int n) {

	if (!TreeLeft(t) && !TreeRight(t) )
	{
		return false;
	}

	int* v = malloc(sizeof(int));
	int lvl = 1;
	bool ris = false;

	v[0] = t->value;

	CheckSumNRec(t, &v, &lvl);

	for (size_t i = 0; i < lvl-1; i++)
	{
		for (size_t j = 0; j < lvl - 1; j++)
		{
			if ((v[i] + v[j]) == n)
			{
				ris = true;
			}
		}
	}

	free(v);
	return ris;
}