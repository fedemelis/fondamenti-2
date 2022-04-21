#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {
	if (h->size <= 0){
		return false;
	}
	int min = 99999;
	int index = 0;
	for (size_t i = 0; i < h->size; i++){
		if (h->data[i] < min){
			min = h->data[i];
			index = i;
		}
	}
	h->data[index] = h->data[h->size - 1];
	h->size -= 1;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);
	HeapMinMoveDown(h, index);
	return true;
}