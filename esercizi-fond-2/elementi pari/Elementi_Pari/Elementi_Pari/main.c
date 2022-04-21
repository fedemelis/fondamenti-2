#include "elementi_pari.h"

int main(void) {

    //lista 1
    ElemType e1[] = { 1, 4, 2, 0, 45, 1, 3 };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* list_a = ListCreateEmpty();
    for (size_t i = 0; i < e1_size; ++i) {
        list_a = ListInsertBack(list_a, e1 + i);
    }

    ElementiPari(list_a);

}