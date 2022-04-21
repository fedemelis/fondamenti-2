#include "move_up.h"
#include <stdlib.h>
#include <string.h>
int main(void) {

	ElemType e[] = { 2, 3, 4, 3, 1 };

	Heap* h = HeapCreateEmpty();

	h->size = 5;
	h->data = malloc(sizeof(ElemType) * h->size);

	memcpy(h->data, e, sizeof(ElemType) * h->size);

	HeapMinMoveUpRec(h, 4);

	HeapDelete(h);

}