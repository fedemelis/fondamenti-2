#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h) || h->size <= 0)
	{
		return false;
	}

	ElemType min = 9999;
	int index = 0;

	for (size_t i = 0; i < h->size; i++)
	{
		if (h->data[i] < min)
		{
			min = h->data[i];
			index = i;
			*e = h->data[i];
		}
	}

	h->data[index] = h->data[h->size - 1];
	h->data = realloc(h->data, (h->size - 1) * sizeof(ElemType));
	h->size -= 1;
	HeapMinMoveDown(h, index);
	return true;


}