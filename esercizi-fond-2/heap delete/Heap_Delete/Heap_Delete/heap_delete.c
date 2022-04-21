#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
void HeapDeleteNode(Heap* h, int k) {

	if (k < 0 || k >= h->size)
	{
		return;
	}

	h->data[k] = h->data[h->size - 1];
	h->data = realloc(h->data, sizeof(ElemType) * (h->size - 1));
	h->size -= 1;
	HeapMinMoveDown(h, k);

}