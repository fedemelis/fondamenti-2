#include "elemtype.h"
#include "list.h"
Item* ElementiPari(const Item* i) {

	if (ListIsEmpty(i))
	{
		return ListCreateEmpty();
	}

	Item* ris = ListCreateEmpty();

	int j = 0;

	for (Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp))
	{
		if (j == 0)
		{
			ris = ListInsertBack(ris, &tmp->value);
		}
		else if ((j % 2) == 0)
		{
			ris = ListInsertBack(ris, &tmp->value);
		}
		++j;
	}

	return ris;
}