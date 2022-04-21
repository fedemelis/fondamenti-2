#include "isheap.h"

int main(void) {

    Heap* h = HeapCreateEmpty();
    h->data = malloc(sizeof(ElemType) * 5);
    h->size = 5;

    //1 3 4 6 4

    h->data[0] = 1;
    h->data[1] = 3;
    h->data[2] = 4;
    h->data[3] = 6;
    h->data[4] = 4;

    IsHeap(h);

}