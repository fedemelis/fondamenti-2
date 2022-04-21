#include "move_down.h"
#include <stdlib.h>
#include <string.h>
int main(void) {

	ElemType e[] = { 10, 3, 4, 3, 7 };

	Heap* h = HeapCreateEmpty();

	h->size = 5;
	h->data = malloc(sizeof(ElemType) * h->size);

	memcpy(h->data, e, sizeof(ElemType) * h->size);

	HeapMinMoveDownRec(h, 0);

	HeapDelete(h);

}