#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>


extern bool Pop(Heap* h, ElemType* e) {

	if (h->size <= 0)
	{
		return false;
	}

	int min = 99999;
	int index = 0;
	for (int i = 0; i < h->size; i++)
	{
		if (h->data[i] < min)
		{
			min = h->data[i];
			index = i;
		}
	}

	*e = h->data[index];
	h->data[index] = h->data[h->size - 1];
	h->size -= 1;
	h->data = realloc(h->data, h->size * sizeof(int));
	HeapMinMoveDown(h, index);
	return true;
}