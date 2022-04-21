#include "elemtype.h"
#include "list.h"
#include <math.h>
#include <stdlib.h>

Item* CreaDaInterni(const Item* i, double r) {

	Item* ris = ListCreateEmpty();
	const Item* tmp = i;
	while (!ListIsEmpty(tmp))
	{
		double distanza = 0;
		distanza = sqrt((tmp->value.x * tmp->value.x) + (tmp->value.y * tmp->value.y));

		if (distanza <= r)
		{
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
		tmp = tmp->next;
	}
	return ris;

	//soluzione con il for

	/*Item* ris = NULL;
	for (const Item* lst = i; lst != NULL; lst = lst->next)
	{
		if ((r * r) >= (lst->value.x * lst->value.x + lst->value.y * lst->value.y))
		{
			ris = ListInsertBack(ris, ListGetHeadValue(lst));
		}
	}
	return ris;*/

}