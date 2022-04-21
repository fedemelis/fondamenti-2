#include "merge.h"

int main(void) {

    Heap* h = HeapCreateEmpty();
    h->data = malloc(sizeof(ElemType) * 5);
    h->size = 5;

    h->data[0] = 1;
    h->data[1] = 2;
    h->data[2] = 3;
    h->data[3] = 4;
    h->data[4] = 5;

    HeapDelete(h);

    /// //////////////////////////////

    Heap* h1 = HeapCreateEmpty();
    h1->data = malloc(sizeof(ElemType) * 5);
    h1->size = 5;

    h1->data[0] = 1;
    h1->data[1] = 2;
    h1->data[2] = 3;
    h1->data[3] = 4;
    h1->data[4] = 5;

    MergeHeap(h, h1);

    HeapDelete(h1);
    HeapDelete(h);


}