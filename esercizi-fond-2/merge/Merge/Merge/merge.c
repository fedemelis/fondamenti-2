#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap *ris = HeapCreateEmpty();

	for (size_t i = 0; i < h1->size; i++)
	{
		ElemType e = h1->data[i];
		HeapMinInsertNode(ris, &e);
	}

	for (size_t i = 0; i < h2->size; i++)
	{
		ElemType e = h2->data[i];
		HeapMinInsertNode(ris, &e);
	}

	return ris;

}