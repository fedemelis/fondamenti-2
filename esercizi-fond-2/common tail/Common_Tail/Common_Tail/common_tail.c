#include "elemtype.h"
#include "list.h"
#include <stdlib.h>


const Item* CommonTail(const Item* i1, const Item* i2) {

	//Item *ris = malloc(sizeof(Item));
	Item* risBest = NULL;/* = malloc(sizeof(Item));*/
	//risBest->next = NULL;
	int quanti = 0;
	int quantiBest = 0;

	if (i1 == NULL || i2 == NULL)
	{
		return NULL;
	}

	for (Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1))
	{
		for (Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2))
		{
			if (tmp1->next == tmp2->next && tmp1->next != NULL && tmp2 != NULL)
			{
				//ris = tmp1;
				Item* t1 = tmp1;
				Item* t2 = tmp2;
				//t1 = tmp1;
				//t2 = tmp2;
				while (!ListIsEmpty(t1) && !ListIsEmpty(t2) && t1->next == t2->next)
				{
					quanti += 1;
					t1 = ListGetTail(t1);
					t2 = ListGetTail(t2);
				}
				if (quanti > quantiBest)
				{
					risBest = tmp1;
					quantiBest = quanti;
					quanti = 0;
				}
				quanti = 0;
			}
		}
	}


	if (quantiBest == 0)
	{
		return NULL;
	}
	else
	{
		return risBest;
	}

}