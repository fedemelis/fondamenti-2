#include "kth_least.h"

int main(void) {

    Heap* h = HeapCreateEmpty();
    h->data = malloc(sizeof(ElemType) * 4);
    h->size = 4;

    h->data[0] = -1;
    h->data[1] = 3;
    h->data[2] = 4;
    h->data[3] = 6;
    
    KthLeast(h, 2);
    


    HeapDelete(h);

}