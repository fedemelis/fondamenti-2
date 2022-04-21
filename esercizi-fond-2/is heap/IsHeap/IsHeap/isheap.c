#include "elemtype.h"
#include "minheap.h"

bool IsHeapRec(const Heap* h, int *index, int *ris) {

	
	if ((h->data[HeapRight(*index)] < h->data[*index] || h->data[HeapLeft(*index)] < h->data[*index]) && *index <= h->size && HeapRight(*index) <= h->size && HeapLeft(*index) <= h->size)
	{
		*ris = 1;
		return false;
	}
	else if(*index <= h->size)
	{
		int prevIndex = *index;
		*index = HeapLeft(*index);
		IsHeapRec(h, index, ris);
		*index = prevIndex;
		*index = HeapRight(*index);
		IsHeapRec(h, index, ris);
	}

}

bool IsHeap(const Heap* h) {

	if (h == NULL)
	{
		return false;
	}

	if (HeapIsEmpty(h) || h->size == 1)
	{
		return true;
	}

	int index1 = 0;
	int index2 = 0;
	int ris = 0;
	
	if (h->data[HeapRight(0)] < h->data[0] || h->data[HeapLeft(0)] < h->data[0])
	{
		return false;
	}
	else
	{
		IsHeapRec(h, &index1, &ris);
		IsHeapRec(h, &index2, &ris);
	}

	if (ris == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}