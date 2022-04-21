#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	if (v == NULL)
	{
		return HeapCreateEmpty();
	}

	Heap* ris = HeapCreateEmpty();

	ris->size = v_size;
	ris->data = malloc(ris->size * sizeof(ElemType));

	memcpy(ris->data, v, ris->size * sizeof(ElemType));

	for (size_t i = 0; i < ris->size; i++)
	{
		HeapMinMoveDown(ris, i);
	}

	return ris;
}