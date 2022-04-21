#include "heap_delete.h"

int main(void) {

    Heap* h = HeapCreateEmpty();
    h->data = malloc(sizeof(ElemType) * 5);
    h->size = 5;

    h->data[0] = 1;
    h->data[1] = 2;
    h->data[2] = 3;
    h->data[3] = 4;
    h->data[4] = 5;

    ElemType e = 0;

    HeapDeleteNode(h, 3);
    
    HeapDelete(h);

}