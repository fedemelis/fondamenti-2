#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	Heap* h = HeapCreateEmpty();

	h->size = v_size;
	h->data = malloc(sizeof(int) * v_size);
	memcpy(h->data, v, v_size * sizeof(ElemType));

	for (size_t i = 0; i < v_size; i++)
	{
		HeapMinMoveDown(h, i);
	}
	 
	return h;

}