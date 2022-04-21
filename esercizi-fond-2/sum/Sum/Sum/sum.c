#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
Item* Sum(const Item* i1, const Item* i2) {

	Item *ris = ListCreateEmpty();

	int* primo = malloc(sizeof(int));
	int quanti1 = 0;

	int* secondo = malloc(sizeof(int));
	int quanti2 = 0;

	int riporto = 0;
	int maggiore = 0;

	while (!ListIsEmpty(i1))
	{
		quanti1 += 1;
		primo = realloc(primo, quanti1 * sizeof(int));
		primo[quanti1 - 1] = i1->value;
		i1 = ListGetTail(i1);
	}

	while (!ListIsEmpty(i2))
	{
		quanti2 += 1;
		secondo = realloc(secondo, quanti2 * sizeof(int));
		secondo[quanti2 - 1] = i2->value;
		i2 = ListGetTail(i2);
	}

	if (quanti1 >= quanti2)
	{
		maggiore = quanti1;
	}
	else
	{
		maggiore = quanti2;
	}

	for (size_t i = 0; i < maggiore; i++)
	{
		if (i < quanti1 && i < quanti2)
		{
			if ((primo[i] + secondo[i]) >= 10)
			{
				ElemType e = ((primo[i] + secondo[i]) % 10) + riporto;
				riporto = (primo[i] + secondo[i]) / 10;
				ris = ListInsertBack(ris, &e);
			}
			else
			{
				ElemType e = ((primo[i] + secondo[i]) % 10) + riporto;
				riporto = 0;
				ris = ListInsertBack(ris, &e);
			}
		}
		else if (i >= quanti1)
		{
			if (secondo[i] >= 10)
			{
				ElemType e = (secondo[i] % 10) + riporto;
				riporto = (secondo[i]) / 10;
				ris = ListInsertBack(ris, &e);
			}
			else
			{
				ElemType e = (secondo[i] % 10) + riporto;
				riporto = 0;
				ris = ListInsertBack(ris, &e);
			}
		}
		else if (i >= quanti2)
		{
			if (primo[i] >= 10)
			{
				ElemType e = (primo[i] % 10) + riporto;
				riporto = primo[i] / 10;
				ris = ListInsertBack(ris, &e);
			}
			else
			{
				ElemType e = (primo[i] % 10) + riporto;
				riporto = 0;
				ris = ListInsertBack(ris, &e);
			}
		}
	}

	if (riporto != 0)
	{
		ElemType e = riporto;
		ris = ListInsertBack(ris, &e);
	}

	free(primo);
	free(secondo);
	return ris;


}