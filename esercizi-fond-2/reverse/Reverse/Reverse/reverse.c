#include "elemtype.h"
#include "list.h"

Item* ListLastValue(Item* i)
{
	Item* ris = NULL;
	if (i != NULL)
	{
		ris = i;
		while (ris->next != NULL)
		{
			ris = ris->next;
		}
	}
	return ris;
}

int ListSize(Item* i)
{
	int ris = 0;
	while (i != NULL)
	{
		i = i->next;
		ris++;
	}
	return ris;
}

Item* Reverse(Item* i) {

	Item* ris = NULL;

	ris = ListLastValue(i);
	int quantiElem = ListSize(i);
	for (int j = 0; j < quantiElem - 1; j++)
	{
		Item* tmp = ListLastValue(ris);
		Item* tmp2 = i;
		while (tmp2->next != tmp)
		{
			tmp2 = tmp2->next;
		}
		tmp->next = tmp2;
		tmp2->next = NULL;													
	}
	return ris;
}