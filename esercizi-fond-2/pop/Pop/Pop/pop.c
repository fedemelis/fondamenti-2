#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool HeapMinPop(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h))
	{
		return false;
	}

	ElemType min = 99999999;
	int index = 0;

	for (size_t i = 0; i < h->size; i++)
	{
		if (min > h->data[i])
		{
			index = i;
			min = h->data[i];
		}
	}

	*e = min;

	h->data[index] = h->data[h->size - 1];
	ElemDelete(&h->data[h->size - 1]);
	h->data = realloc(h->data, sizeof(ElemType) * h->size - 1);
	h->size = h->size - 1;
	HeapMinMoveDown(h, index);
	return true;
}