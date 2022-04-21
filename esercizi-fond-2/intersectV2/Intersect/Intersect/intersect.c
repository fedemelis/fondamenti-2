#include "elemtype.h"
#include "list.h"
Item* Intersect(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) || ListIsEmpty(i2))
	{
		return ListCreateEmpty();
	}

	Item* ris = ListCreateEmpty();

	for (const Item * tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1))
	{
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2))
		{
			if (tmp1->value == tmp2->value)
			{
				ris = ListInsertBack(ris, &tmp1->value);
				break;
			}
		}
	}

	return ris;

}